#include <sys/types.h>
#include <unistd.h>
#include <boost/filesystem.hpp>   
#include <boost/filesystem/fstream.hpp>
#include "boost/algorithm/string/split.hpp"
#include "boost/algorithm/string.hpp"
#include <iostream>
#include "Identifier.h"
#include "Config.h"
#include "Logger.h"
#include "Spider.h"
#include "MySQL.h"
#include "HtmlParser.h"
#include "AboveRank.h"
#include "ExcludedKeywords.h"
#include "Score.h"
#include "Classifier.h"
#include "UrlClassifier.h"
#include "Localiser.h"
#include "Keywords.h"
#include "HttpClient.h"
#include "Backlinks.h"
#include "Competition.h"
#include "Sysinfo.h"
#include "OpenSSL.h"
#include "PageKeywordMatcher.h"
#include "SiteMap.h"
#include "DetectLang.h"
#include "NGramFreqs.h"
#include "RunInfo.h"
//#include "T_StatusUpdateType.hpp" DRIVE2
//#include "T_StatusUpdate.hpp" DRIVE2
#include "T_Account.hpp"
#include "T_DriveBackLog.hpp"
//#include "T_Tools_Competitor.hpp" DRIVE2
#include "T_HistoricalScore.hpp"
#include "BackCrawler.h"
#include "KeywordRelevance.h"

using namespace DMMM;
using namespace boost::filesystem;
using namespace std;
namespace nsBFS = boost::filesystem;

void 
handleBreak(int sig)
{
    exit(-1);
}

void
showHelpMessage(const string& exPath)
{
    cout << "usage: " << exPath 
         << " <command> <parameter>" << endl << endl
         << "Possible commands and how they're used:" << endl
         << endl << "Utilities" << endl
         << "  test" << endl
         << "    " << exPath << " test 0" << endl
         << endl << "Account actions" << endl
         << "  mirror_parse" << endl
         << "    " << exPath << " mirror_parse account_id" << endl
         << "  quickstart" << endl
         << "    " << exPath << " quickstart account_id" << endl
         << "  mirror_parse_classify" << endl
         << "    " << exPath << " mirror_parse_classify account_id" << endl
         << "  mirror_single_page" << endl
         << "    " << exPath << " mirror_single_page account_id http://www.gayporn.com/jonah_and_shlomi.jpg" << endl
         << "  score" << endl
         << "    " << exPath << " score account_id" << endl
         << "  keywords" << endl
         << "    " << exPath << " keywords account_id" << endl
         << "  classify" << endl
         << "    " << exPath << " classify account_id" << endl
         << "  update_page_element_count" << endl
         << "    " << exPath << " update_page_element_count account_id" << endl
         << "  update_competitions" <<  endl
         << "    " << exPath << " update_competitions account_id" << endl
         << "  competition_backlink_domains" <<  endl
         << "    " << exPath << " competition_backlink_domains account_id" 
         << endl
         << "  sitemap" <<  endl
         << "    " << exPath << " sitemap account_id" << endl
         << endl << "Page actions" << endl
         << "  track_backlinks" << endl
         << "    " << exPath << " track_backlinks account_id" << endl
         << "  backlinks" << endl
         << "    " << exPath << " backlinks page_id" << endl
         << "  localise" << endl
         << "    " << exPath << " localise account_id page_id" << endl
         << endl << "Misc" << endl
         << "  test_potential_backlink" << endl
         << "    " << exPath 
         << " test_potential_backlink account_id tools_competitor_id" << endl
         << "  keyword_relevance" << endl
         << "    " << exPath << " keyword_relevance 0" << endl
         << "  target_prediction" << endl
         << "    " << exPath << " target_prediction account_id" << endl
         << "  suggest_page_tracked_kws" << endl
         << "    " << exPath << " suggest_page_tracked_kws account_id" << endl
         << "  source_keywords" << endl
         << "    " << exPath << " source_keywords clank_source_id" << endl
         << "  hard_delete" << endl
         << "    " << exPath << " hard_delete account_id" << endl
         << "  delete_all_deleted" << endl
         << "    " << exPath << " delete_all_deleted 0" << endl
         << "  df" << endl
         << "    " << exPath << " df 0 filesystem" << endl
         << "  free" << endl
         << "    " << exPath << " free 0" << endl
         << "  build_ngrams" << endl
         << "    " << exPath << " build_ngrams 0" << endl
         << "  backlinks_crawl" << endl
         << "    " << exPath << " backlinks_crawl Domain(RankAbove) Input_file(./something.csv) urlField(2) myDomains(rankabove.com;cnn.com)" << endl
         << endl;
}

void
createStatusUpdate(const O_Account& account, const string& updateTypeName)
{
    T_Account t_a;

/* DRIVE2:
   StatusUpdateType object no longer exists in new drive

    T_StatusUpdateType t_sut;
    O_StatusUpdateType sut = 
        t_sut.first(t_sut._name() == updateTypeName).first;

    O_StatusUpdate statusUpdate(account._id());
    statusUpdate._viewed() = false;
    statusUpdate._user_id() = account._user_id();
    statusUpdate._type_id() = sut._id();
    statusUpdate._created_at() = DBFace::instance()->now();
    statusUpdate._updated_at() = DBFace::instance()->now();
    statusUpdate.insert();
*/
}

void
updateCrawlLog(O_Account& account)
{
    LOG_INFO << "Updating crawl log with latest crawl statistics";
    T_MirrorLog t_ml(account._id());
    O_CrawlLog cl(account._id());
    cl._crawled_at() = DBFace::instance()->now();
    cl._canonicals() = t_ml.select(t_ml._status() == "canonical tag").size();
    cl._new_pages() = t_ml.select(t_ml._status() == "newly indexed").size();
    cl._updated_pages() = t_ml.select(t_ml._status() == "updated").size();
    cl._redirects() = t_ml.select(t_ml._status() == "redirected").size();
    cl._total_pages() = t_ml.select().size();
    cl._errors_count() = t_ml.select(t_ml._status() == 
                                     "download failed").size();
    cl.insert();
    // other statuses that are given during mirroring, but not used here: "user exclusion" "user nofollows" "not in user follows" "duplicate"  "noindex tag" "robots.txt" "previously indexed"
}



void
updateScoringPercent(O_Account& account, size_t scoringPercent)
{
    account._scoring_percent() = scoringPercent;
    account.update();
}

void
score(O_Account& account)
{
    
    WebDB* webDB = WebDB::instance();
    string url = account._url();

    LOG_INFO << "Scoring " << url;

    vector<O_Page> pages = account._pages();

    createStatusUpdate(account, "scoring_start");    

    account._scoring_percent() = 0;
    account._is_scoring() = true;
    account._analyzed() = false;
    account.update();

// DANI -The next three lines where commented out, why?    
    SiteWebPages webPages = parseHtmlSite(account);
    updateScoringPercent(account, 20);
    
    
    map<Url, Redirect> redirects;
    webDB->getRedirectsByTarget(account._id(), redirects);
    updateScoringPercent(account, 40);


// note: this code has been written but no UI has been implemented
    calculateAccountOverallIssues(account, webPages);

    size_t accountScore = 
        calculateScoresAndPriorities(account);
    updateScoringPercent(account, 70);
    
    account._score() = accountScore;
    account._analyzed_at() = DBFace::instance()->now();
    account._analyzed() = true;
    account.update();    
    updateScoringPercent(account, 95);


    O_HistoricalScore histoScore(account._id());
    histoScore._created_at() = DBFace::instance()->now();
    histoScore._score() = accountScore;
    histoScore.insert();

    aggregateClassInfo(account._id());
    aggregateIssueInfo(account._id());

    // Counts how many (page type) issues there are in the account_issues table
    saveTotalAccountIssuesCount(account);

    account._scoring_percent() = 100;
    account._is_scoring() = false;
    account.update();    

    createStatusUpdate(account, "scoring_end");    
}

void
test(Logger* logger)
{
    cout << "Number of errors: " << logger->numErrors() << endl;
    cout << "Number of warnings: " << logger->numWarning() << endl;
    if (logger->numErrors() == 0 && logger->numWarning() == 0)
        cout << "OK" << endl;
}

void
mirror(O_Account& account, bool quickCrawl = false)
{
    LOG_INFO << "mirroring account " << account._id();

    createStatusUpdate(account, "mirror_start");

    account._has_mirror() = false;
    account._mirror_percent() = 0;
    account._last_page_mirrored() = "";
    account._is_mirroring() = true;
    account.update();

    spider(account, true, quickCrawl);
    generateSiteMap(account);

    account._updated_at() = DBFace::instance()->now();
    account._mirrored_at() = DBFace::instance()->now();
    account._mirror_percent() = 0;
    account._last_page_mirrored() = "";
    account._has_mirror() = true;
    account._is_mirroring() = false;
    account.update();
    createStatusUpdate(account, "mirror_end");
    updateCrawlLog(account);

}

// will not follow on page links only urls from the mirror_pages table
// will not delete previous mirror logs
void
crawlOnlyFromMirrorPages(O_Account& account)
{
    LOG_INFO << "crawling mirror_pages table of account " << account._id();

    createStatusUpdate(account, "mirror_start");

    account._has_mirror() = false;
    account._mirror_percent() = 0;
    account._last_page_mirrored() = "";
    account._is_mirroring() = true;
    account.update();

    spiderOnlyFromMirrorPages(account);

    account._updated_at() = DBFace::instance()->now();
    account._mirrored_at() = DBFace::instance()->now();
    account._has_mirror() = true;
    account._is_mirroring() = false;
    account.update();
    
    generateSiteMap(account);
    createStatusUpdate(account, "mirror_end");
    updateCrawlLog(account);
}

void
parse(O_Account& account)
{
    LOG_INFO << "parsing account " << account._id();
    createStatusUpdate(account, "parsing_start");    

    WebDB* webDB = WebDB::instance();
    string url = account._url();

    LOG_INFO << "Parsing " << url;

    account._is_parsing() = true;
    account._mirror_percent() = 0;
    account.update();
    
    webDB->deleteUnmirroredPages(account._id(), 
                                 account._max_pages_mirrored());
    webDB->deletePageElements(account._id());

    account._mirror_percent() = 10;
    account.update();

    parseSite(account);
    account._mirror_percent() = 70;
    account.update();

    calculateAboveRanks(account._id());
    account._mirror_percent() = 80;
    account.update();

    aggregateClassInfo(account._id());

    account._mirror_percent() = 90;
    account.update();

    webDB->updatePageElementCount(account._id());
    account._is_parsing() = false;
    account._mirror_percent() = 100;
    account.update();
    createStatusUpdate(account, "parsing_end");    
    
}

void
keywords(O_Account& account)
{
    LOG_INFO << "finding keywords for account " << account._id();

    createStatusUpdate(account, "keyword_start");    

    WebDB* webDB = WebDB::instance();

    account._is_keywording() = true;
    account.update();
    
    deleteKeywordsBeforeSuggesting(account._id());

    SiteKeywords siteKeywords = getSiteKeywords(account._id());
    LOG_INFO << "got " << siteKeywords.size() << " keywords";

    WeightedKWs headTrackedKeywords = findSiteKWs(siteKeywords);
    webDB->updateHeadTrackedKeywords(account._id(), headTrackedKeywords);

    account._is_keywording() = false;
    account.update();

    createStatusUpdate(account, "keyword_end");    
}



void
sourceKeywords(ClankSourceId csId)
{
    LOG_INFO << "Getting keywords for " << csId.dbgval();

    WebDB* webDB = WebDB::instance();
    Url url = webDB->getClankSourceUrl(csId);
    
    HttpClient httpClient("Googlebot");
    string content;
    if (!httpClient.httpGetWithRedirects(url, "text/html", content, 10)){
        LOG_INFO << "failed to get page";
        return;
    }
    
    WebPage wp;
    wp.mUrl = url;
    parseHtml(content, wp);
    size_t numKeywords = confParam<size_t>("sources.num_keywords");
    WeightedKWs wkws;
    calculateWeightedKeywords(wp, wkws, numKeywords, true, true);
    webDB->insertClankSourceKeywords(csId, wkws);
}

void
classify(O_Account& account)
{
    LOG_INFO << "Classify account " << account._id();
    createStatusUpdate(account, "classification_start");    

    account._is_classifying() = true;
    account.update();

//    urlClassify(account);
    classify(account._id());
    aggregateClassInfo(account._id());

    account._is_classifying() = false;
    account.update();

    createStatusUpdate(account, "classification_end");    
}

void
localise(O_Account& account, I_Page pageId)
{
    LOG_INFO << "Localise account " << account._id()
             << " page " << pageId;

    path mirrorUrl = 
        path(RunInfo::instance()->mirrorDir(account._id()));    
    
    localise(pageId, account, mirrorUrl);
}


void
dirFor(const path& logDir)
{
    if (!exists(logDir)){
      cout << "Creating log directory " << logDir << endl;
      create_directory(logDir);
    }
}

bool
nonAccountCmd(const string& cmd)
{
    return cmd == string("keyword_relevance")
        || cmd == string("test")
        || cmd == string("source_keywords")
        || cmd == string("hard_delete")
        || cmd == string("delete_all_deleted")
        || cmd == string("df")
        || cmd == string("build_ngrams")
        || cmd == string("free");

}

// These commands do not  use ngrams 
bool
nonNGramCmd(const string& cmd)
{
    return cmd == string("test")
        || cmd == string("hard_delete")
        || cmd == string("delete_all_deleted")
        || cmd == string("classify")
        || cmd == string("df")
        || cmd == string("free")
        || cmd == string("localise")
        || cmd == string("mirror_single_page")
        || cmd == string("backlinks_crawl")
        || cmd == string("update_competitions");
}

bool
ngramsAsServieCmd(const string& cmd)
{
    return cmd == string("test")
        || cmd == string("source_keywords")
        || cmd == string("hard_delete")
        || cmd == string("delete_all_deleted")
        || cmd == string("df")
        || cmd == string("build_ngrams")
        || cmd == string("free")
        || cmd == string("backlinks_crawl");

}

I_DriveBackLog
updateDBLogStart(pid_t pid, int argc, char* argv[], const string& logFileName)
{
    O_DriveBackLog logEntry;
    logEntry._start() = DBFace::instance()->now();
    logEntry._pid() = pid;
    logEntry._command() = string(argv[1]);
    logEntry._model_id() = atoi(argv[2]);
    logEntry._log_file_name() = logFileName;
    if (argc > 3)
        logEntry._param() = string(argv[3]);
    logEntry.insert();
    return logEntry._id();
}

void
updateDBLogEnd(I_DriveBackLog logId)
{
    O_DriveBackLog logEntry;
    logEntry._id() = logId;
    logEntry._end() = DBFace::instance()->now();
    logEntry.update();
    
}

O_Account
getAccount(char* accountIdParam)
{
    I_Account accountId(fromString<size_t>(accountIdParam));
    T_Account ta;
    pair<O_Account, bool> account = ta.select(accountId);
    if (account.second)
        return account.first;
    else{
        LOG_ERROR << "Account " << accountId << " not not exist";
        exit(-1);
    }

}

int
mainMain(int argc, char* argv[])
{
    cout << "-------------" << endl;
    cout << "Running Drive" << endl;

    //so the profiler writes gmon.out even if program ended with ^C.
    signal(SIGABRT, &handleBreak);
    signal(SIGTERM, &handleBreak);
    signal(SIGINT, &handleBreak);

    path binPath(argv[0]);
    string command = argc >= 2 ? string(argv[1]) : string();

    if (argc < 3 || command == string("--help") || command == string("-h")){
        showHelpMessage(argv[0]);
        exit(-1);
    }
    
    path basePath = binPath.remove_leaf() / "../";
    path confFile = basePath / "conf/drive.conf";
        
    cout << "Loading configuration file " << confFile << endl;
    Config* config = new Config(confFile.string().c_str(), argc, argv);
        
    RunInfo runInfo(basePath.string());
        
    path logFile;
    path logDir;
    if (nonAccountCmd(command)){
        logDir = basePath /
            path(confParam<string>("system.log_file_name")     
                 + string("/") + confParam<string>("argv1"));  
        dirFor(logDir);
        logFile = logDir / 
            path(confParam<string>("argv2") + string(".txt"));       
    } 
    else{
        logDir = basePath /
            path(confParam<string>("system.log_file_name")     
                 + string("/") + string("accounts"));
        dirFor(logDir); 
        logDir = logDir / path(confParam<string>("argv2"));     
        dirFor(logDir);
        logFile = logDir / 
            path(confParam<string>("argv1") + 
                 string(".txt"));
    }
    
    Logger* logger = new Logger(logFile.string().c_str());
        
    LOG_INFO << "RankAbove Drive " << confParam<string>("version");
    LOG_INFO << "Command line arguments: " << argv[0] 
             << " " << argv[1] << " " << argv[2] << "...";
    
    LOG_INFO << setlocale(LC_ALL, NULL);
    if (!setlocale(LC_ALL, "en_US.UTF-8")) {
        LOG_ERROR  << "Can't set the specified locale!";
        return -1;
    }
    LOG_INFO << setlocale(LC_ALL, NULL);
    
    OpenSSLMTSupporter* openSSLMTSupporter = new OpenSSLMTSupporter();
    
    WebDB* webDB = new MySQL();
    string host = confParam<string>("db.host");
    string user = confParam<string>("db.user");
    string database = confParam<string>("db.database");
    string password = confParam<string>("db.password");
    DMMM::DBFace dbFace(database, host, user, password, logger->logFile());
    
    
    pid_t pid = getpid();
    I_DriveBackLog driveBackLogId = updateDBLogStart(pid, argc, argv,
                                                     logFile.string());
    
    if (command == string("keywords_sandbox")       )
        config->setSandboxing();
    
    config->synchWithDB();
        
    ExcludedKeywords* excludedKeywords = new ExcludedKeywords();
    excludedKeywords->loadList();
        

    LanguageDetector* languageDetector = new LanguageDetector();
    NGramFreqs* nGramFreqs = new NGramFreqs();

    if (!nonNGramCmd(command))
        nGramFreqs->initialize(ngramsAsServieCmd(command));

    if (command == string("test"))
        test(logger);
    else if (command == string("mirror")){
        O_Account account = getAccount(argv[2]);
        mirror(account);
        webDB->updateMirrorProgress(account._id(), 0);
    }
    else if (command == string("quickstart")){
        O_Account account = getAccount(argv[2]);
        mirror(account, true);
        parse(account);
        webDB->updateMirrorProgress(account._id(), 0);
    }
    else if (command == string("crawl_mirror_pages")){
        O_Account account = getAccount(argv[2]);
        crawlOnlyFromMirrorPages(account);
        webDB->updateMirrorProgress(account._id(), 0);
    }
    else if (command == string("parse")){
        O_Account account = getAccount(argv[2]);
        parse(account);
    }
    else if (command == string("classify")){
        O_Account account = getAccount(argv[2]);
        classify(account);
    }
    else if (command == string("mirror_parse")){
        O_Account account = getAccount(argv[2]);
        mirror(account);
        parse(account);
        score(account);
        getTopPagesBacklinks(account);
        
        account._mirror_percent() = 0;
        account.update();
        
        suggestPageTrackedKeywords(account._id());
    }
    else if (command == string("mirror_single_page")){
        O_Account account = getAccount(argv[2]);
        mirrorSinglePage(account, argv[3]);
    }
    else if (command == string("mirror_parse_classify")){
        O_Account account = getAccount(argv[2]);
        mirror(account);
        classify(account);
        parse(account);
        score(account);
        
        account._mirror_percent() = 0;
        account.update();
        
        suggestPageTrackedKeywords(account._id());
    }
    else if (command == string("mirror_parse_classify_keywords")){
        O_Account account = getAccount(argv[2]);
        mirror(account);
        parse(account);
        classify(account);
        
        account._mirror_percent() = 0;
        account.update();
        
        keywords(account);
        suggestPageTrackedKeywords(account._id());
        score(account);
    }
    else if (command == string("parse_classify_keywords")){
        O_Account account = getAccount(argv[2]);
        classify(account);
        parse(account);
        
        account._mirror_percent() = 0;
        account.update();
        
        keywords(account);
        suggestPageTrackedKeywords(account._id());
        score(account);
    }
    else if (command == string("score")){
        O_Account account = getAccount(argv[2]);
        suggestPageTrackedKeywords(account._id());
        score(account);
    }
    
    else if (command == string("sitemap")){
        O_Account account = getAccount(argv[2]);
        generateSiteMap(account);
    }
    else if (command == string("keywords")){
        O_Account account = getAccount(argv[2]);
        keywords(account);
        suggestPageTrackedKeywords(account._id());
    }
    else if (command == string("keywords_sandbox")){
        O_Account account = getAccount(argv[2]);
        keywords(account);
    }
    else if (command == string("keyword_relevance")){
        keywordRelevance();
    }
	//    else if (command == string("target_prediction")){
	//      O_Account account = getAccount(argv[2]);
	//        calculateTargetRank(account._id());
	//    }
    else if (command == string("source_keywords")){
        ClankSourceId csId(fromString<ClankSourceId::BaseType>(argv[2]));
        sourceKeywords(csId);
    }
    else if (command == string("update_page_element_count")){
        O_Account account = getAccount(argv[2]);
        webDB->updatePageElementCount(account._id());
    }
    else if (command == string("update_competitions")){
        O_Account account = getAccount(argv[2]);
        updateCompetitions(account._id());
    }
    else if (command == string("competition_backlink_domains")){
        O_Account account = getAccount(argv[2]);
        calculateSharedRefrencingDomains(account);
    }

    else if (command == string("backlinks")){
        // NOTE: uses old yahoo.com for backlinks -> which does not work
        O_Account account = getAccount(argv[2]);
        I_Page pageId(fromString<size_t>(argv[3]));
        getBacklinks(pageId, account);
    }
    else if (command == string("track_backlinks")){
        O_Account account = getAccount(argv[2]);
        updateTrackedBacklinks(account);
    }
    else if (command == string("analyze_tracked_backlinks")){
        O_Account account = getAccount(argv[2]);
        analyzeTrackedBacklinks(account);
    }
    else if (command == string("localise")){
        O_Account account = getAccount(argv[2]);
        I_Page pageId(fromString<size_t>(argv[3]));
        localise(account, pageId);
    }
    else if (command == string("suggest_page_tracked_kws")){
        O_Account account = getAccount(argv[2]);
        suggestPageTrackedKeywords(account._id());
	//            calculateTargetRank(account._id());
    }
/*
   Removing this command, since 'Tools_Competitor' model removed 
   else if (command == string("test_potential_backlink")){
        O_Account account = getAccount(argv[2]);
        I_Tools_Competitor compId(fromString<size_t>(argv[3]));
        analyzeCompetitorBacklink(compId, account._url());
    }
 */
    else if (command == string("hard_delete")){
        O_Account account = getAccount(argv[2]);
        webDB->hardDeleteAccount(account._id());
    }
    else if (command == string("delete_all_deleted")){
        vector<I_Account> accounts;
        webDB->getOldDeletedAccounts(accounts);
        for (size_t i = 0; i < accounts.size(); ++i)
            webDB->hardDeleteAccount(accounts[i]);
    }
    else if (command == string("build_lang_detect")){
        buildLangDetect();
    }
    else if (command == string("df")){
        DiskInfo info;
        info.run(argv[3]);
        cout << info.toXML();
    }
    else if (command == string("free")){
        MemInfo info;
        info.run();
        cout << info.toXML();
    }
    else if (command == string("build_ngrams")){
        nGramFreqs->buildList();
    }
    else if (command == string("backlinks_crawl")){
        crawlBacklinks(logDir, argv[3], atoi(argv[4]), argv[5]);
    }
    else{
        showHelpMessage(argv[0]);
        LOG_ERROR << "unknown command: " << command;
    }
    

    updateDBLogEnd(driveBackLogId);
        
    LOG_INFO << "deleting NGramFreq";
    delete nGramFreqs;
    LOG_INFO << "deleting LanguageDetector";
    delete languageDetector;
    LOG_INFO << "deleting Open SSL MT Supporter";
    delete openSSLMTSupporter;
    LOG_INFO << "deleting ExcludedKeywords";
    delete excludedKeywords;
    LOG_INFO << "deleting WebDB";
    delete webDB;

    LOG_INFO << "deleting Config";
    delete config;
    
    LOG_INFO << "Last log message: deleting Logger";
    delete logger;
    

    return 0;
} 



int
main(int argc, char* argv[])
{
    return mainMain(argc, argv);
    try{
        return mainMain(argc, argv);
    }
    catch(exception& e){
        cout << e.what();
        flush(cout);
        LOG_ERROR << e.what();
    }
    return -1;
}

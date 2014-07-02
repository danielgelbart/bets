#include <boost/filesystem.hpp>   
#include <boost/filesystem/fstream.hpp>
#include "Config.h"
#include "RunInfo.h"

using namespace std;
using namespace boost::filesystem;

RunInfo* RunInfo::_this = NULL;


string 
RunInfo::mirrorsDir() const
{
    path mirrorPath = path(_basePath) / confParam<path>("spider.mirrors_dir");
    return mirrorPath.string();
}

string 
RunInfo::mirrorDir(const DMMM::I_Account accountId) const
{
    path mirrorPath = path(mirrorsDir()) / path(accountId.to_s());
    return mirrorPath.string();
}


string
RunInfo::sitemapsDir() const
{
    return mirrorsDir() + "/sitemaps/";
}

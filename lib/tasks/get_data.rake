# Get edgar accesion numbers of annual reports on edgar
#require 'active_record'
require 'nokogiri'
require 'open-uri'

namespace :get_data do

  desc "Replace fighters with less than 5 fights"
  task :clean => :environment do |task, args|

    uf = Fighter.find_by_name("Unranked Fighter")

    # Get rid of fighters with few fights, replace them with "Unranked Fighter"
    fits = Fighter.all
    fulfits = fits.select{ |f| f.has_full_data? }
    lilfits = fulfits.select{ |f| f.fights.size < 5 }
    lilfits.each do |f|
      # Replace fights with 'Unranked Fighter'
      f.wins.each do |w|
        w.winner = uf
        w.save
      end
      f.loses.each do |l|
        l.loser = uf
        l.save
      end
      puts "Deleting fighter #{f.name}"
    end

    lilfits.map{ |f| f.destroy }

    # Now remove anny unneeded fight records
    fights = Fight.all
    uf_fights = 0
    ni_fights = 0
    u_fights = []
    fights.each do |f|

      if f.winner == uf && f.loser == uf
        u_fights << f
        uf_fights += 1
      end

      if f.winner == nil || f.loser == nil
        u_fights << f
        ni_fights += 1
      end
    end

    puts "Deleting #{ uf_fights} fights between Unranked Fighters, and #{ni_fights} fights where the fighter id was nil"
    u_fights.map{ |f| f.destroy }

  end

  desc "Update fighters from upcoming fight card"
  task :up_card => :environment do |task, args|

  end

  desc "Try to mark as full full data fighters"
  task :mark_full => :environment do |task, args|
    non_full_fighters = Fighter.where( full_data: false)
    log = File.new("mark_full.log","w+")
    spider = Spider.new(log)

    non_full_fighters.each do |f|
      if !f.url.nil?
        spider.get_recursive(f.url)
      end
    end
    log.close
  end


  desc "Populate database with fight records"
  task :fights => :environment do |task, args|

    # Consider passing this as a parameter
    url ="http://www.sherdog.com/fighter/Stefan-Struve-15063"

    log = File.new("fights_rake.log","w+")

    spider = Spider.new(log)
    spider.get_recursive(url)

    for_delete = Fighter.where( for_delete: true)

    for_delete.each do |f|
      puts "Deleting #{f.name} due to few fights"
      f.destroy
    end

    log.close
  end # task

end # namdspace


class Spider

  attr_accessor :log

  def initialize(log)
    @log = log
  end

  @@count = 0

  def self.add_to_count
    @@count += 1
  end

  def self.count
    @@count
  end

  def get_recursive(url)
    log.puts "get_recursive called with url: #{url}"

    lim = 100
    if Spider.count > lim
      log.puts puts "Reached run limit of #{lim} at #{url}"
      return
    else
      puts "This is the #{ Spider.add_to_count }th recursive call"
    end

    fighter_name = extract_fighter_name(url)
    puts "Entered recursive call for #{fighter_name}"

    fighter = Fighter.find_by_name(fighter_name)

    #recursion base
    if !fighter.nil?
      if fighter.has_full_data?
        puts "Not getting data, since #{fighter.name} has all data"
        if fighter.url.nil?
          fighter.url = url
          fighter.save
        end
        return
      end
    end

    # get all fights for fighter
    fight_records = get_fight_records_from_link(url)
    num_fights = fight_records.size

    # recursion base
    # Let's NOT get all fights for this fighter if he has less than 6 fights
    # We will use him to spider the other fighters
    delete_fighter = false
    if num_fights < 6
      puts "#{fighter_name} has too few fights to persist to DB"
      delete_fighter = true
    end

    fighter = Fighter.find_or_create_by(name: fighter_name)


    if fighter.url.nil?
      fighter.url = url
      fighter.save
    end

    #recursion base
    if fighter.has_full_data?
      puts "Not getting data, since #{fighter.name} has all data"
      return
    end

    #finshed getting records
    if fighter.fights.size == num_fights
      log.puts puts "TOTAL: #{num_fights} NO NEED to add fights for #{fighter_name}, marking as full data"
      fighter.full_data = true
      fighter.save
      return # if we have all fights, we've been here before...
    else
      puts "Adding fights for #{fighter_name}"
    end

    # Iterate over fights and add them to DB
    fight_records.each do |fight_rec|
      add_fight_to_db(fighter,fight_rec)
    end

    fighter.full_data = true
    fighter.save

    # This fighter has to few fights, but we already got the data about him,
    # So we will save it, but delete him when we are done
    if delete_fighter
      log.puts puts "Marking #{fighter_name} for Delete"
      fighter.for_delete = delete_fighter
      fighter.save
      return
    end

    # Iterate over fights and make recursive call
    fight_records.each do |fight_rec|
      get_recursive(extract_url(fight_rec))
    end

    puts "EXITED Recursive call from #{fighter.name}"
  end

  def get_fight_records_from_link(url)
    fight_table = get_table(open_doc(url))
    fight_records = extract_records(fight_table)
  end

  def update_fight_record(winner, loser)
    # Look for existing fight record between both fighters
    fr = WinLossRecord.get_record(winner, loser)

    # if exists - update
    if fr.nil?
      fr = WinLossRecord.create()
    else
      # check wich field to update

      #update

    end

    # if not create new won correctly
  end


  def add_fight_to_db(fighter,rec)
    cols = rec.css('/td')

    # check if opponent has less than 6 fights
    # If he does, replace him with the genric fighter "Unranked Fighter"
    # This will slow down crawl, but hopfully reduce DB size
    oponent = nil
    oponent_name = cols[1].text.strip

    oponent = Fighter.find_by_name(oponent_name)
    uf = Fighter.find_by_name("Unranked Fighter")

    count_records = true
    if !oponent.nil?
      if oponent.fights.size > 5
        count_records = false
        puts "oponent #{oponent.name} has more than 5 fights"
      else
        if oponent.full_data
          count_records = false
          log.puts puts "Replacing UNRANKED with #{oponent.name} to reduce DB"
          oponent = uf
        end
      end
    end

    if count_records && oponent_fight_num(rec) < 6
      oponent = Fighter.find_by_name("Unranked Fighter")
      log.puts puts "Using Unranked Fighter insted of #{oponent_name} to save DB space"
    else
      # add opponenet to db if not already there
      oponent = Fighter.find_or_create_by(name: oponent_name)
    end

    # who is winner, who is loser?
    result = cols[0].text.strip

    nocontest = 0 #
    case result
    when "win"
      winner = fighter
      loser = oponent
    when "loss"
      winner = oponent
      loser = fighter
    when "draw"
      winner = oponent
      loser = fighter
      nocontest = 1 #'draw'
    else
      winner = oponent
      loser = fighter
      nocontest = 2 #'nocontest'
      # add fight to db but mark it as not exists?
    end

    datestr = cols[2].children[2].text
    date = Date.strptime(datestr,"%b \/ %d \/ %Y")

    event = cols[2].children[0].text.strip
    finish = cols[3].text.split[0]
    round = cols[4].text.to_i
    time =  cols[5].text.gsub(":","").to_i


    # Note - we will try to create the fight record exactly twice,
    # once for the winner, and once for the lower.
    # make sure that it is only created once by validation on Fight model
    fight = Fight.create( winner: winner,
                          loser: loser,
                          date: date,
                          event: event,
                          nonwin: nocontest,
                          finish: finish,
                          round: round,
                          time: time )

    if fight.id.nil?
      log.puts puts"Did not add fight for #{fighter.name} from #{date.to_s}"
    else
      log.puts puts"Added fight for  #{fighter.name} from #{date.to_s}"
      # ONLY update fight record if this is a new fight
      if nocontest == 0 # fight ended with a win, not a draw
        update_fight_record(winner, loser)
        log.puts puts"Updated fight record with a #{winner == fighter ? "win":"loss"} for fight dated #{fight.date}"
      end

    end
  end

  def oponent_fight_num(rec)
    #check first if already esists in DB
    cols = rec.css('/td')
    oponent_name = cols[1].text.strip
    oponent = Fighter.find_by_name(oponent_name)

    if !oponent.nil?
      if oponent.has_full_data?
        op_fight_num = oponent.fights.size
        puts "Oponent #{oponent.name} has a total #{op_fight_num}"
        log.puts "Oponent #{oponent.name} has a total #{op_fight_num}"
        return op_fight_num
      end
    end

    op_link = extract_url(rec)
    fight_records = get_fight_records_from_link(op_link)
    fight_records.size
  end

  def extract_url(rec)
    cols = rec.css('/td')
    rel_path = cols[1].css('a').first.attr('href')
    "http://www.sherdog.com"+rel_path
  end

  def extract_fighter_name(url)
    url.split('fighter/')[1][/\D+-\D+/].gsub("-"," ").strip
  end

  def extract_records(tab)
    recs = tab.css("/tr")
    recs.shift # get rid of fist row
    recs
  end

  def open_doc(url)
    begin
      doc = Nokogiri::HTML(open(url))
    rescue OpenURI::HTTPError => e
      log.puts "Could not open url: #{url }"
      log.puts "Received: #{e.message}"
      return
    end
  end

  def get_table(html)
    tabs = html.css('//table')
    tab = nil
    tabs.each do |table|
      if table.css('/tr').text.strip.first(6) == "Result"
        tab = table
        break # NOTE:
        # If there are amatur fights, they are in a second table,
        # wich will also be found by this method - If you want to include them
        # as well, remove the 'break' and somehow join each "fight" table found
      end
    end

    if tab.nil?
      log.puts("ERROR no talbe could be extracted from:\n#{html}")
    end
    tab
  end

end

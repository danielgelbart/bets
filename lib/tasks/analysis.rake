
#TODO change to helper method
# should write update directly to DB
class WLArray

  attr_accessor :recs, :fighter

  def initialize(fighter)
    @recs = fighter.wlrecords
    @fighter = fighter
  end

  # Add opponent and w/l
  # if First time we see this oponenet - creaet new record
  # if NOT - add to existing record
  # win - true if added record is a win
  # fB - oponent - Fighter object
  def add(fB, win)
    recs.each do |r|
      if r.fighterB == fB
        if win
          r.update_attributes( winA: r.winA + 1)
        else
          r.update_attributes( winB: r.winB + 1)
        end
        return
      end
    end

    fr = WinLossRecord.create( fighterA_id: fighter.id,
                            fighterB_id: fB.id,
                            winA: (win ? 1 : 0),
                            winB: (win ? 0 : 1))
    recs << fr
  end
end # class WLArray


namespace :analysis do

  desc "Count wins/losses of each player and write to table"
  task :countwl => :environment do |task, args|

    #TODO - only update recent list of fighters from fighter card

    fighters = Fighter.first(2) #all

    # TODO -
    # 1. Limit to fights from last 3 years only
    # 2. Count only finishes and unan decisions ?

    fighters.each do |fighter|

      fighter_records = WLArray.new(fighter)

      fighter.wins.each do |win|
        fighter_records.add(win.loser, true)
      end

      fighter.loses.each do |loss|
        fighter_records.add(loss.winner, false)
      end

      fighter_records.write_records()
    end
  end
end

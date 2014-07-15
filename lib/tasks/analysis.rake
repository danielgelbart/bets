
class FightRecord

  attr_accessor :fA, :fB, :wA, :wB

  def initialize(fA)
    @fA = fA
  end

end


class WLArray

  attr_accessor

  def initialize

  end


  # Add opponent and w/l
  # if First time we see this oponenet - creaet new record
  # if NOT - add to existing record
  def add(fB, win)

  end

end



namespace :analysis do

  desc "Count wins/losses of each player and write to table"
  task :countwl => :environment do |task, args|

    fighters = Fighter.all
    fighters.each do |fighter|

      #get all fights

      #create array

    end
  end
end

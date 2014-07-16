# == Schema Information
#
# Table name: win_loss_records
#
#  id          :integer          not null, primary key
#  fighterA_id :integer
#  fighterB_id :integer
#  winA        :integer          default(0)
#  winB        :integer          default(0)
#  created_at  :datetime
#  updated_at  :datetime
#

class WinLossRecord < ActiveRecord::Base

  validates_presence_of :fighterA_id, :fighterB_id
  validate :fighter_pair_uniqueness
  # This does not work
  validates :fighterA_id, uniqueness: {scope: :fighterB_id}
  validates :fighterB_id, uniqueness: {scope: :fighterA_id}

  # validate uniquness of {fA,fB}
  belongs_to :fighterA, class_name: 'Fighter', foreign_key: 'fighterA_id'
  belongs_to :fighterB, class_name: 'Fighter', foreign_key: 'fighterB_id'

  def fighter_pair_uniqueness
    if self.class.where("(fighterA_id = :a AND fighterB_id = :b) OR (fighterA_id = :b AND fighterB_id = :a)",
                        {:a => fighterA_id, :b => fighterB_id}).exists?
      errors.add(:fighterA_id, :taken)
    end
  end


  def self.get_record(fa, fb)
    rec = where( fighterA_id: fa.id, fighterB_id: fb.id)
    rec = where( fighterB_id: fa.id, fighterA_id: fb.id) if rec == []
    if(rec.size > 2)
      puts "ERROR! there is more than 1 win/los record (WinLossRecord\n For fighters #{fa.name} and #{fb.name}"
    end
    return rec.first
  end
end

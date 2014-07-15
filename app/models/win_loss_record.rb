class WinLossRecord < ActiveRecord::Base

  validates_presence_of :fighterA, :fighterB
  validates :fighterA, uniqueness: {scope: :fighterB}
  validates :fighterB, uniqueness: {scope: :fighterA}

  # validate uniquness of {fA,fB}
  belongs_to :fighterA, class_name: 'Fighter', foreign_key: 'FighterA_id'
  belongs_to :fighterB, class_name: 'Fighter', foreign_key: 'FighterB_id'
end

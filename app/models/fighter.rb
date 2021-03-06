# == Schema Information
#
# Table name: fighters
#
#  id         :integer          not null, primary key
#  name       :string(255)
#  created_at :datetime
#  updated_at :datetime
#  full_data  :boolean          default(FALSE)
#  url        :string(255)
#  for_delete :boolean          default(FALSE)
#

class Fighter < ActiveRecord::Base
  validates_presence_of :name
  validates_uniqueness_of :name

  has_many :_wins, foreign_key: 'winner_id', class_name: 'Fight'
  has_many :_loses, foreign_key: 'loser_id', class_name: 'Fight'

  has_many :wlrecordsA, foreign_key: 'FighterA_id', class_name: 'WinLossRecord'
  has_many :wlrecordsB, foreign_key: 'FighterB_id', class_name: 'WinLossRecord'

  def wlrecords
    wlrecordsA + wlrecordsB
  end

  def wins
    _wins.select{ |w| w.nonwin == 'win' }
  end

  def loses
    _loses.select{ |w| w.nonwin == 'win' }
  end

  #Returns wins + loses + draws + nocontests
  def fights
    _wins + _loses
  end

  def has_full_data?
    self.full_data
  end

end

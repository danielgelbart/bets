# == Schema Information
#
# Table name: fights
#
#  id         :integer          not null, primary key
#  winner     :integer
#  loser      :integer
#  date       :datetime
#  event      :string(255)
#  round      :integer
#  time       :integer
#  exists     :boolean          default(TRUE)
#  created_at :datetime
#  updated_at :datetime
#

class Fight < ActiveRecord::Base

  validates :date, uniqueness: {scope: [:winner, :loser]}
  validates_presence_of :winner, :loser, :date
  enum nonwin: [ :win, :draw, :nocontest ]

  belongs_to :winner, foreign_key: 'winner_id', class_name: 'Fighter'
  belongs_to :loser, foreign_key: 'loser_id', class_name: 'Fighter'

  def fighters
    winner + loser
  end

end

class ChangeWinnerNameToWinerId < ActiveRecord::Migration
  def change
    rename_column :fights, :winner, :winner_id
    rename_column :fights, :loser, :loser_id
  end
end

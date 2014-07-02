class CreateFights < ActiveRecord::Migration
  def change
    create_table :fights do |t|
      t.integer :winner
      t.integer :loser
      t.datetime :date
      t.string :event
      t.integer :round, :limit => 1
      t.integer :time, :limit => 4
      t.boolean :exists, :default => true

      t.timestamps
    end
    add_index :fights, [:winner, :loser, :date]
  end
end

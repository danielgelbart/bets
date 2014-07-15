class CreateWinLossRecords < ActiveRecord::Migration
  def change
    create_table :win_loss_records do |t|
      t.integer :fighterA_id
      t.integer :fighterB_id
      t.integer :winA
      t.integer :winB

      t.timestamps
    end
  end
end

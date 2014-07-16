class CreateWinLossRecords < ActiveRecord::Migration
  def change
    create_table :win_loss_records do |t|
      t.integer :fighterA_id
      t.integer :fighterB_id
      t.integer :winA, default:0
      t.integer :winB, default:0

      t.timestamps
    end
  end
end

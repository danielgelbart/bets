class CreateFighters < ActiveRecord::Migration
  def change
    create_table :fighters do |t|
      t.string :name

      t.timestamps
    end
  end
end

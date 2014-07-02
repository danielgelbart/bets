class AddFinishToFights < ActiveRecord::Migration
  def change
    add_column :fights, :finish, :string, limit: 20
    add_column :fights, :nonwin, :integer, limit: 2, default: 0
  end
end

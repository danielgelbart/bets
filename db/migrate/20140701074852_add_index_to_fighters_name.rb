class AddIndexToFightersName < ActiveRecord::Migration
  def change
    add_index :fighters, :name
  end
end

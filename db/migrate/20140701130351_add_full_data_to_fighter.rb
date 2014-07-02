class AddFullDataToFighter < ActiveRecord::Migration
  def change
    add_column :fighters, :full_data, :boolean, default: false
  end
end

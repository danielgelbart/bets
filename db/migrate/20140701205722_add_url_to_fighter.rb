class AddUrlToFighter < ActiveRecord::Migration
  def change
    add_column :fighters, :url, :string
  end
end

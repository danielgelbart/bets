class AddFordeleteToFighter < ActiveRecord::Migration
  def change
    add_column :fighters, :for_delete, :boolean, default: false

  end
end

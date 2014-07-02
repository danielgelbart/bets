# encoding: UTF-8
# This file is auto-generated from the current state of the database. Instead
# of editing this file, please use the migrations feature of Active Record to
# incrementally modify your database, and then regenerate this schema definition.
#
# Note that this schema.rb definition is the authoritative source for your
# database schema. If you need to create the application database on another
# system, you should be using db:schema:load, not running all the migrations
# from scratch. The latter is a flawed and unsustainable approach (the more migrations
# you'll amass, the slower it'll run and the greater likelihood for issues).
#
# It's strongly recommended that you check this file into your version control system.

ActiveRecord::Schema.define(version: 20140702123359) do

  create_table "fighters", force: true do |t|
    t.string   "name"
    t.datetime "created_at"
    t.datetime "updated_at"
    t.boolean  "full_data",  default: false
    t.string   "url"
    t.boolean  "for_delete", default: false
  end

  add_index "fighters", ["name"], name: "index_fighters_on_name", using: :btree

  create_table "fights", force: true do |t|
    t.integer  "winner_id"
    t.integer  "loser_id"
    t.datetime "date"
    t.string   "event"
    t.integer  "round",      limit: 1
    t.integer  "time"
    t.boolean  "exists",                default: true
    t.datetime "created_at"
    t.datetime "updated_at"
    t.string   "finish",     limit: 20
    t.integer  "nonwin",     limit: 2,  default: 0
  end

  add_index "fights", ["winner_id", "loser_id", "date"], name: "index_fights_on_winner_id_and_loser_id_and_date", using: :btree

end

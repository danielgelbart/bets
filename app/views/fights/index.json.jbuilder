json.array!(@fights) do |fight|
  json.extract! fight, :id, :winner, :loser, :date, :event, :round, :time
  json.url fight_url(fight, format: :json)
end

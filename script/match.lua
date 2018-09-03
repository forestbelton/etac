local Match = {
    map = "none",
    title = "game match",
    description = "just another game match",
    entity_descriptions = {},
    queue = {},
    entities = {},
    log_entries = {}
}

function Match:new (o)
    o = o or {}
    setmetatable(o, self)

    self.__index = self
    for i = 1, #o.entity_descriptions do
        local entityId = o:add(o.entity_descriptions[i])
        o:enqueue(entityId)
    end

    local player = Player:new(o.player_description)
    player.id = #o.entities + 1
    o.entities[player.id] = player

    local title = string.format("loaded match: %s", o.title)
    o:log(title)
    o:log(o.description)

    return o
end

function Match:add (entity_description)
    local entityClass = require(entity_description.script)

    entity_description.id = #self.entities + 1
    entity_description.script = nil

    local entity = entityClass:new(entity_description)
    self.entities[entity.id] = entity

    return entity.id
end

function Match:remove (entityId)
    self.entities[entityId] = nil
end

function Match:enqueue (entityId)
    local entity = self.entities[entityId]
    local time = entity:next_action_time()

    -- Don't enqueue any entities which have a negative time. This is a way
    -- for entities to reject being re-entered into the turn queue.
    if time < 0 then
        return
    end

    local entry = {
        entity = entity,
        time = time
    }

    -- If there are other elements, insert increasing by time.
    for i = 1, #self.queue do
        if entry.time < self.queue[i].time then
            table.insert(self.queue, i, entry)
            return
        end
    end

    self.queue[#self.queue + 1] = entry
end

function Match:dequeue ()
    local next_entry = table.remove(self.queue, 1)

    for i = 1, #self.queue do
        local entry = self.queue[i]
        entry.time = math.max(entry.time - next_entry.time, 0)
    end

    return next_entry.entity
end

function Match:take_turn ()
    if #self.queue == 0 then
        error("no entities have registered with the turn queue")
    end

    local entity = self:dequeue()
    local turn_msg = string.format("it is %s's turn", entity.name)
    self:log(turn_msg)

    entity:take_turn(self)
    self:enqueue(entity.id)
end

function Match:is_over ()
    over = false

    if #self.queue == 0 then
        over = true
    else
        factions = {}

        for i = 1, #self.queue do
            local entry = self.queue[i]
            factions[entry.entity.faction] = true
        end

        factions["neutral"] = nil
        num_factions = 0
        for _ in pairs(factions) do
            num_factions = num_factions + 1
        end

        over = num_factions < 2
    end

    return over
end

function Match:log (content)
    table.insert(self.log_entries, 1, content)
end

return Match

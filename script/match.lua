local Match = {
    queue = {},
    entities = {},
    entity_descriptions = {},
    map = "none",
    title = "game match",
    description = "just another game match"
}

function Match:new (o)
    o = o or {}
    setmetatable(o, self)

    self.__index = self
    for i = 1, #o.entity_descriptions do
        local entityId = o:add(o.entity_descriptions[i])
        o:enqueue(entityId)
    end

    return o
end

function Match:add (entity)
    local entityClass = require(entity.script)
    local entity = entityClass:new({
        id = #self.entities + 1,
        x = entity.x,
        y = entity.y
    })

    self.entities[entity.id] = entity
    return entity.id
end

function Match:remove (entityId)
    self.entities[entityId] = nil
end

function Match:enqueue (entityId)
    local entity = self.entities[entityId]
    local entry = {
        entity = entity,
        time = entity:next_action_time()
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

function Match:dequeue (entityId)
    local next_entry = table.remove(self.queue, 1)

    for i = 1, #self.queue do
        local entry = self.queue[i]
        entry.time = math.max(entry.time - next_entry.time, 0)
    end

    return next_entry.entity
end

return Match
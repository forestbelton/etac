local Match = {
    queue = {},
    entities = {},
    nextId = 0,
    map = "none"
}

function Match:new (o)
    o = o or {}
    setmetatable(o, self)

    for i = 1, #self.entities do
        local entityId = self:add(self.entities[i])
        self:enqueueEntity(entityId)
    end

    return o
end

function Match:add (entity)
    local entityClass = require(entity.scriptFile)
    local entity = entityClass.new({
        id = self.nextId,
        x = entity.x,
        y = entity.y
    })

    self.entities[entity.id] = entity
    self.nextId = self.nextId + 1

    return entity.id
end

function Match:remove (entityId)
    self.entities[entityId] = nil
end

function Match:enqueue (entityId)
    -- TODO: Add to turn queue
end

function Match:dequeue (entityId)
    -- TODO: Pop next entity off turn queue
end

return Match
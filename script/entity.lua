Entity = {
    id = -1,
    name = "Game Object",
    sprite = "?"
}

function Entity:new(o)
    o = o or {}
    setmetatable(o, self)
    self.__index = self
    return o
end

function Entity:next_action_time()
    return 100
end

function Entity:take_turn(match)
end

return Entity
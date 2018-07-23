Entity = {
    id = -1,
    name = "Game Object"
}

function Entity:new(o)
    o = o or {}
    setmetatable(o, self)
    self.__index = self
    return o
end

return Entity
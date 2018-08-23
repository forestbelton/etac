dbg = require('script/debugger') -- the debugger
local Entity = require('script/entity')

Player = Entity:new({
    name = "Hero",
    sprite = "@",
    faction = "player"
})

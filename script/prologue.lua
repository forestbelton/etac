dbg = require('script/debugger') -- the debugger
inspect = require('script/inspect')
local Entity = require('script/entity')

Player = Entity:new({
    name = "Hero",
    sprite = "@",
    faction = "player"
})

local dbg = require('script/debugger')
local Entity = require('script/entity')

Ram = Entity:new({
    name = "Ram",
    sprite = "r"
})
dbg()
function Ram:take_turn(match)
    match:log("the ram stumbles about.")
end

return Ram

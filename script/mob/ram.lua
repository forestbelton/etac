local Entity = require('script/entity')

Ram = Entity:new({
    name = "Ram",
    sprite = "r"
})

function Ram:take_turn(match)
    match:log("the ram stumbles about.")
end

return Ram

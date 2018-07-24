local Entity = require('script/entity')

Swan = Entity:new({
    name = "Swan",
    sprite = "W"
})

function Swan:take_turn(match)
    match:log("the swan looks around for its next victim.")
end

return Swan
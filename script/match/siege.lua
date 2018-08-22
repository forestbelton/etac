local dbg = require('script/debugger')
local Match = require('script/match')

return Match:new({
    map = "river_asymmetric",
    title = "siege of the swans",
    description = "the swans are in trouble and you must help them die",
    player_description = { x = 21, y = 12 },
    entity_descriptions = {
        { x = 7, y = 3, script = "script/mob/swan" },
        { x = 34, y = 2, script = "script/mob/swan" },
        { x = 20, y = 3, script = "script/mob/swan" }
    }
})

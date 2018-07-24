local Match = require('script/match')

return Match:new({
    map = "river_asymmetric",
    title = "siege of the swans",
    description = "the swans are in trouble and you must help them die",
    entity_descriptions = {
        { x = 7, y = 3, script = "script/mob/swan" },
        { x = 34, y = 2, script = "script/mob/swan" },
        { x = 20, y = 3, script = "script/mob/swan" }
    }
})
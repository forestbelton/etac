local Match = require('script/match')

return Match:new({
    map = "river_asymmetric",
    entity_descriptions = {
        { x = 5, y = 5, script = "script/mob/swan" }
    }
})
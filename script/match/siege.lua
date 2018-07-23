local Match = require('script/match')

return Match:new({
    map = "river_asymmetric",
    entities = {
        { x = 5, y = 5, script = "script/mob/swan" }
    }
})
local Match = require('script/match')

return Match:new({
    map = "default",
    entities = {
        {
            x = 5,
            y = 5,
            scriptFile = "script/mob/swan"
        }
    }
})
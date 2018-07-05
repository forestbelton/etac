import { MAP_WIDTH, MAP_HEIGHT, colorCodeNames } from './constants'

const compile = (grid, name) => {
    const cells = []

    for (let y = 0; y < MAP_HEIGHT; ++y) {
        for (let x = 0; x < MAP_WIDTH; ++x) {
            const cell = grid[y][x]

            const ch = JSON.stringify(cell.value).replace(/^"(.*)"$/, '\'$1\'')
            const fg = colorCodeNames[cell.foregroundColor]
            const bg = colorCodeNames[cell.backgroundColor]

            cells.push(
                `{ ${ch}, ${fg}, ${bg} }`
            )
        }
    }

    const mapName = name.toLowerCase()
        .replace(/[^a-z ]/, '')
        .replace(' ', '_')

    return `
#include <termbox.h>

struct tb_cell map_${mapName}[] = {
    ${cells.join(',\n    ')}
};
`
}

export default compile

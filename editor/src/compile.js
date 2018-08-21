import { MAP_WIDTH, MAP_HEIGHT, colorCodeNames } from './constants'

const compile = (grid, name) => {
    const cells = []

    for (let y = 0; y < MAP_HEIGHT; ++y) {
        for (let x = 0; x < MAP_WIDTH; ++x) {
            const cell = grid[y][x]

            const ch = JSON.stringify(cell.value).replace(/^"(.*)"$/, '\'$1\'')
            const fg = colorCodeNames[cell.foregroundColor]
            const fgBold = cell.bold ? ' | TB_BOLD' : ''
            const bg = colorCodeNames[cell.backgroundColor]

            cells.push(
                `{ ${ch}, ${fg + fgBold}, ${bg} }`
            )
        }
    }

    const mapName = name.toLowerCase()
        .replace(/[^a-z ]/, '')
        .replace(' ', '_')

    return `
#include <termbox.h>
#include "map/map.h"

static struct tb_cell map_data[] = {
    ${cells.join(',\n    ')}
};

struct map map_${mapName} = { map_data, ${MAP_WIDTH}, ${MAP_HEIGHT} };
`
}

export default compile

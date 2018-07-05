import PropTypes from 'prop-types'
import React from 'react'
import styled from 'styled-components'

import { MAP_HEIGHT, MAP_WIDTH } from './constants'

const Text = ({ className, onClick }) => (
    <div className={className} onClick={onClick} />
)

const getForegroundColor = foregroundColor =>
    (!foregroundColor || foregroundColor === 'transparent')
        ? 'gray'
        : foregroundColor

const Cell = styled(Text)`
    width: 16px;
    height: 16px;
    line-height: 14px;
    text-align: center;
    display: inline-block;
    box-sizing: border-box;
    font-family: 'Fira Mono', monospace;
    font-weight: ${props => props.cell.bold ? 'bold' : 'normal'};
    background: ${props => props.cell.backgroundColor};
    border: ${props => props.isSelected ? '2px solid red' : 'none'};
    padding: ${props => !props.isSelected ? '2px' : '0'};

    &:after {
        color: ${props => getForegroundColor(props.cell.foregroundColor)};
        content: ${props => JSON.stringify(props.cell.value)};
        display: inline-block;
    }

    &:hover {
        ${props => !props.isSelected ? 'border: 2px solid green;' : ''}
        padding: 0;
    }
`

const Map = ({ className, grid, selected, onSelect }) => {
    const cells = []

    for (let y = 0; y < MAP_HEIGHT; ++y) {
        if (y !== 0) {
            cells.push(<br key={`${y}-nl`} />)
        }

        for (let x = 0; x < MAP_WIDTH; ++x) {
            const cell = grid[y][x]
            const isSelected = selected
                && (x === selected.x && y === selected.y)

            cells.push(<Cell key={`${x}-${y}`} cell={cell}
                isSelected={isSelected} onClick={() => onSelect(cell)} />
            )
        }
    }

    return (<div className={className}>{cells}</div>)
}

Map.propTypes = {
    onSelect: PropTypes.func.isRequired
}

export default styled(Map)`
    background: #000;
    line-height: 0;
    display: inline-block;
`

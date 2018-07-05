import React from 'react'
import styled from 'styled-components'

import { validColors } from '../constants'

export const PaletteCell = styled(({ color, ...props }) => <div {...props} />)`
    width: 16px;
    height: 16px;
    display: inline-block;
    background-color: ${({ color }) => color};
    border: 1px solid #000;
    border-right-width: 0;

    &:first-of-type, &:last-of-type {
        border-right-width: 1px;
    }

    &:hover {
        border-color: red;
    }
`

const ColorPalette = ({ className, onChange, togglePicker }) => {
    const changeColor = color => () => {
        onChange(color)
        togglePicker()
    }

    return (
        <div className={className}>
            {validColors.map((color, i) => (
                <PaletteCell key={i} color={color}
                    onClick={changeColor(color)} />
            ))}
        </div>
    )
}

export default styled(ColorPalette)`
    display: inline-block;
    margin-right: 0.5rem;
`
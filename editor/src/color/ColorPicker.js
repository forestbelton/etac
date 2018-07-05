import PropTypes from 'prop-types'
import React from 'react'
import { withStateHandlers } from 'recompose'
import styled from 'styled-components'

import ColorPalette, { PaletteCell } from './ColorPalette'

const enhanceToggle = withStateHandlers(
    () => ({
        open: false
    }),
    {
        toggle: ({ open }) => () => ({
            open: !open
        })
    }
)

const ColorPicker = enhanceToggle(
    ({ className, color, onChange, open, toggle }) => (
        <div className={className}>
            <PaletteCell color={color} onClick={toggle} />
            { open ? <ColorPalette onChange={onChange} togglePicker={toggle} /> : null }
        </div>
    )
)

ColorPicker.propTypes = {
    onChange: PropTypes.func.isRequired,
    color: PropTypes.string
}

ColorPicker.defaultProps = {
    color: 'transparent'
}

export default styled(ColorPicker)`
    display: inline-block;

    & > div:first-child {
        margin-right: 0.5rem;
    }
`

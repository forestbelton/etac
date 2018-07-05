import PropTypes from 'prop-types'
import React, { Component } from 'react'
import styled from 'styled-components'

import { validColors } from './constants'

const ColorCell = styled(({ color, ...props }) => <div {...props} />)`
    width: 16px;
    height: 16px;
    display: inline-block;
    background-color: ${props => props.color};
    border: 1px solid #000;
    border-right-width: 0;

    &:first-of-type, &:last-of-type {
        border-right-width: 1px;
    }

    &:hover {
        border-color: red;
    }
`

class ColorPicker extends Component {
    constructor(...args) {
        super(...args)

        this.state = { open: false }
        this.togglePicker = this.togglePicker.bind(this)
    }

    togglePicker() {
        this.setState({
            open: !this.state.open
        })
    }

    render() {
        return (
            <div className={this.props.className}>
                <ColorCell color={this.props.value} onClick={this.togglePicker} />
                { this.state.open ? this.renderPicker() : null }
            </div>
        )
    }

    renderPicker() {
        const changeColor = color => () => {
            this.props.onChange(color)
            this.togglePicker()
        }

        return (
            <div style={{ display: 'inline-block', marginLeft: '0.5rem' }}>
                {validColors.map((color, i) => <ColorCell key={i} color={color}
                    onClick={changeColor(color)} />
                )}
            </div>
        )
    }
}

ColorPicker.propTypes = {
    onChange: PropTypes.func.isRequired,
    value: PropTypes.string
}

ColorPicker.defaultProps = {
    value: 'gray'
}

export default styled(ColorPicker)`
    display: inline-block;
`

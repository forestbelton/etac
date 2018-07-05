import React, { Component } from 'react'
import styled from 'styled-components'

import compile from './compile'
import { MAP_HEIGHT, MAP_WIDTH } from './constants'
import Map from './Map'
import ColorPicker from './color/ColorPicker'

const Property = styled.div`
  margin-bottom: 0.25rem;

  & > strong {
    width: 10rem;
    display: inline-block;
  }

  & > input {
    outline: 0;
    border: 0;
    border-bottom: 1px solid #000;
  }
`

class App extends Component {

  constructor(...args) {
    super(...args)

    const grid = []
    for (let y = 0; y < MAP_HEIGHT; ++y) {
      grid[y] = []

      for (let x = 0; x < MAP_WIDTH; ++x) {
        grid[y][x] = {
          x,
          y,
          value: ' ',
          foregroundColor: 'transparent',
          backgroundColor: 'transparent'
        }
      }
    }

    this.state = {
      grid,
      cell: null,
      name: 'default',
      foregroundColor: 'transparent',
      backgroundColor: 'transparent'
    }

    this.updateCell = this.updateCell.bind(this)
    this.updateName = this.updateName.bind(this)
    this.selectCell = this.selectCell.bind(this)
    this.copyData = this.copyData.bind(this)
    this.updateForegroundColor = this.updateForegroundColor.bind(this)
    this.updateBackgroundColor = this.updateBackgroundColor.bind(this)
  }

  componentDidMount() {
    document.body.addEventListener('keydown', this.updateCell)
  }

  componentWillUnmount() {
    document.body.removeEventListener('keydown', this.updateCell)
  }

  updateCell(e) {
    const cell = this.state.cell

    if (cell !== null && e.key.length === 1) {
      const updatedCell = {
        ...cell,
        foregroundColor: this.state.foregroundColor,
        backgroundColor: this.state.backgroundColor,
        value: e.key
      }

      const grid = this.state.grid.slice()
      grid[cell.y][cell.x] = updatedCell

      const nextX = (cell.x + 1) % MAP_WIDTH
      const nextY = nextX === 0 ? cell.y + 1 : cell.y
      const nextCell = nextY < MAP_HEIGHT ? grid[nextY][nextX] : updatedCell

      this.setState({
        cell: nextCell,
        grid
      })
    }
  }

  selectCell(cell) {
    this.setState({
      cell
    })
  }

  updateName(e) {
    this.setState({
      name: e.target.value
    })
  }

  updateForegroundColor(foregroundColor) {
    this.setState({
      foregroundColor
    })
  }

  updateBackgroundColor(backgroundColor) {
    this.setState({
      backgroundColor
    })
  }

  getPosition() {
    return this.state.cell === null
      ? 'No cell selected'
      : `(${this.state.cell.x}, ${this.state.cell.y})`
  }

  copyData() {
    const el = document.createElement('textarea');

    el.value = compile(this.state.grid, this.state.name);
    el.setAttribute('readonly', '');
    el.style.position = 'absolute';
    el.style.left = '-9999px';

    document.body.appendChild(el);
    el.select();
    document.execCommand('copy');
    document.body.removeChild(el);

    alert('Copied to clipboard!');
  }

  render() {
    return (
      <div className={this.props.className}>
        <Property>
          <strong>Map name:</strong>
          <input type="text" value={this.state.name}
            onChange={this.updateName} />
        </Property>
        <Property>
          <strong>Foreground:</strong>
          <ColorPicker color={this.state.foregroundColor}
            onChange={this.updateForegroundColor} />
        </Property>
        <Property>
          <strong>Background:</strong>
          <ColorPicker color={this.state.backgroundColor}
            onChange={this.updateBackgroundColor} />
        </Property>
        <Property>
          <strong>Position:</strong>
          <input type="text" readOnly value={this.getPosition()} />
        </Property>
        <Map grid={this.state.grid} selected={this.state.cell} onSelect={this.selectCell} />
        <div>
          <button onClick={this.copyData}>Copy</button>
        </div>
      </div>
    )
  }
}

export default styled(App)`
  margin: 5px;
  padding: 5px;
`
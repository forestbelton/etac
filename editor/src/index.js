import React from 'react'
import ReactDOM from 'react-dom'
import { injectGlobal } from 'styled-components'

import App from './App'

injectGlobal`
@import url('https://fonts.googleapis.com/css?family=Fira+Mono:400,700');

body {
    margin: 0;
    padding: 0;
    font-family: sans-serif;
}
`

ReactDOM.render(<App />, document.getElementById('root'))
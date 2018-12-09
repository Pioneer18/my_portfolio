import React, { Component } from 'react';
import "./"
import './App.css';
import Navigation from "./components/Navigation";

class App extends Component {
  render() {
    return (
      <div className="App">
       <React.Fragment>
         <Navigation />
       </React.Fragment>
      </div>
    );
  }
}

export default App;

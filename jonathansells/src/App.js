import React, { Component } from 'react';
import "./"
import './App.css';
import Navigation from "./components/Navigation";
import Parallax from "./components/Parallax";

class App extends Component {
  render() {
    return (
      <div className="App">
       <React.Fragment>
         <Navigation />
         <Parallax />
       </React.Fragment>
      </div>
    );
  }
}

export default App;

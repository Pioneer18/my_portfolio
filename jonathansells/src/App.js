import React, { Component } from 'react';
import "./"
import './App.css';
import Navigation from "./components/Navigation";
import Parallax from "./components/Parallax";
import SectionDivider from "./components/SectionDivder";

class App extends Component {
  render() {
    return (
      <div className="App">
       <React.Fragment>
         <Navigation />
         <Parallax />
         <SectionDivider />
       </React.Fragment>
      </div>
    );
  }
}

export default App;

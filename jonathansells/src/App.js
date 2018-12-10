import React, { Component } from 'react';
import "./"
import './App.css';
import Navigation from "./components/Navigation";
import Parallax from "./components/Parallax";
import SectionDivider from "./components/SectionDivder";
import AboutMe from "./components/AboutMe";
import Timeline from "./components/Timeline";

class App extends Component {
  render() {
    return (
      <div className="App">
       <React.Fragment>
         <Navigation />
         <Parallax />
         <SectionDivider />
         <AboutMe />
         <SectionDivider />
         <Timeline />
       </React.Fragment>
      </div>
    );
  }
}

export default App;

import React, { Component } from 'react';
import "./"
import './App.css';
import Navigation from "./components/Navigation";
import Parallax from "./components/Parallax";
import SectionDivider from "./components/SectionDivder";
import AboutMe from "./components/AboutMe";
import Timeline from "./components/Timeline";
import Gallery from "./components/Gallery";


class App extends Component {

 handleClick = event => {
  event.preventDefault();
  console.log("buton clicked yo");
}

  render() {
    return (
      <div className="App">
       <React.Fragment>
         <Navigation />
         <Parallax handleClick={this.handleClick} />
         <SectionDivider divider={"About Me"} />
         <AboutMe />
         <SectionDivider divider={"My Journey"} />
         <Timeline />
         <SectionDivider divider={"My Projects"} />
         <Gallery />
         <SectionDivider divider={"Contact Me"} />
       </React.Fragment>
      </div>
    );
  }
}

export default App;

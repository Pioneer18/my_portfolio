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
  constructor(){
    super();
    this.myRef=React.createRef()
  }

 handleClick = event => {
  event.preventDefault();
  console.log("button clicked yo");
  window.scrollTo(0, 5000,{
  behavior: "smooth"
})
}



  render() {
    return (
      <div className="App">
       <React.Fragment>
         <Parallax handleClick={this.handleClick} />
         <Navigation />
         <SectionDivider divider={"About Me"} />
         <AboutMe />
         <SectionDivider divider={"My Journey"} />
         <Timeline />
         <SectionDivider divider={"My Projects"} />
         <Gallery gallery={this.myRef} />
         <SectionDivider divider={"Contact Me"} />
       </React.Fragment>
      </div>
    );
  }
}

export default App;

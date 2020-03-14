import React, { Component } from "react";
import "./";
import "./App.css";
import Navigation from "./components/Navigation";
import Parallax from "./components/Parallax";
import SectionDivider from "./components/SectionDivder";
import AboutMe from "./components/AboutMe";
import Timeline from "./components/Timeline";
import Gallery from "./components/Gallery";

class App extends Component {
  constructor() {
    super();
    this.myRef = React.createRef();
  }

  scrollToProjects = event => {
    event.preventDefault();
    console.log("button clicked yo");
    window.scrollTo(0, 5000, {
      behavior: "smooth"
    });
  };

  scrollToMyJourney = event => {
    event.preventDefault();
    console.log("button clicked yo");
    window.scrollTo(0, 2000, {
      behavior: "smooth"
    });
  };

  scrollToAboutMe = event => {
    event.preventDefault();
    console.log("button clicked yo");
    window.scrollTo(0, 920, {
      behavior: "smooth"
    });
  };

  scrollToContactMe = event => {
    event.preventDefault();
    console.log("button clicked yo");
    window.scrollTo(0, 5000, {
      behavior: "smooth"
    });
  };

  render() {
    return (
      <div className="App">
        <React.Fragment>
          <Parallax scrollToProjects={this.scrollToProjects} />
          <Navigation 
            scrollToAboutMe={this.scrollToAboutMe}
            scrollToProjects={this.scrollToProjects}/>
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

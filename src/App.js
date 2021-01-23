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

  render() {
    return (
      <div className="App">
        <React.Fragment>
          <Parallax scrollToProjects={this.scrollToProjects} />
          <Navigation />
          <SectionDivider id={"aboutme"} divider={"About Me"} />
          <AboutMe />
          <SectionDivider id={"myjourney"} divider={"My Journey"} />
          <Timeline />
          <SectionDivider id={"projects"} divider={"My Projects"} />
          <Gallery gallery={this.myRef} />
          <SectionDivider divider={"Contact Me"} />
        </React.Fragment>
      </div>
    );
  }
}

export default App;

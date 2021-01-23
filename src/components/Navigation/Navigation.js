
import React from 'react';
import "./Navigation.css";
import {
  Collapse,
  Navbar,
  NavbarToggler,
  NavbarBrand,
  Nav,
  NavItem,
  NavLink,
  } from 'mdbreact';
// import zIndex from '@material-ui/core/styles/zIndex';
  
  

export default class Navigation extends React.Component {
  constructor(props) {
    super(props);

    this.toggle = this.toggle.bind(this);
    this.state = {
      isOpen: false
    };
  }
  toggle() {
    this.setState({
      isOpen: !this.state.isOpen
    });
  }
  render() {
      const brand = {color:"#F0DB4F"}
      const navBack = {
          backgroundColor: "#000", 
          padding: ".5% 10%",
          zIndex: "1000"
        }

    return (
      <React.Fragment>
        <Navbar light style={navBack}  expand="md" sticky="top">
            <NavbarBrand id="logo" style={brand} to="/">JS</NavbarBrand>
            <NavbarToggler onClick={this.toggle} />
            <Collapse isOpen={this.state.isOpen} navbar>
                <Nav  className="ml-auto" navbar>
                <NavItem>
                    <a className="nav-link" href="#aboutme">About Me</a>
                </NavItem>
                <NavItem>
                    <a className="nav-link" href="#myjourney">My Journey</a>
                </NavItem>
                <NavItem>
                    <a className="nav-link" href="#projects">Projects</a>
                </NavItem>
                <NavItem>
                    <a className="nav-link" href="">Contact</a>
                </NavItem>
                </Nav>
            </Collapse>
        </Navbar>
      </React.Fragment>
    );
  }
}


/* 
 <Jumbotron style={{padding:"0px"}} fluid>
    <Container  className="jumboImg" style={{ margin:0 }} fluid>
          <h1 className="display-3">Hello, I'm<span style={brand} className="jsells"> Jonathan Sells</span><br/>I'm a full-stack web &amp; IoT Developer</h1>
          <p className="lead">button to be</p>
    </Container>
 </Jumbotron>
*/
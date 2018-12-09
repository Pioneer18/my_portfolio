
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
  import {
    Jumbotron,
    Container
  } from 'reactstrap'

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
      const brand = {  color:"#F0DB4F"}
      const text = {color:"#fff", padding: "0 1rem"}
      const navBack = {
          backgroundColor: "#000", 
          padding: ".5% 10%",
        }

    return (
      <div>
        <Navbar light style={navBack}  expand="md">
            <NavbarBrand style={brand} to="/">JS</NavbarBrand>
            <NavbarToggler onClick={this.toggle} />
            <Collapse isOpen={this.state.isOpen} navbar>
                <Nav  className="ml-auto" navbar>
                <NavItem>
                    <NavLink style={text} to="#">About Me</NavLink>
                </NavItem>
                <NavItem>
                    <NavLink style={text} to="#">Projects</NavLink>
                </NavItem>
                <NavItem>
                    <NavLink style={text} to="#">Contact</NavLink>
                </NavItem>
                </Nav>
            </Collapse>
        </Navbar>
        <Jumbotron className="jumboImg" fluid>
        <Container fluid>
          <h1 className="display-3">Hello, I'm<span style={brand} className="jsells"> Jonathan Sells</span><br/>I'm a full-stack web &amp; IoT Developer</h1>
          <p className="lead">button to be</p>
        </Container>
      </Jumbotron>
      </div>
    );
  }
}

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
  } from 'reactstrap';

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
      const text = {color:"#fff", padding: "0 1rem"}
      const navBack = {
          backgroundColor: "#000",
          color: "#F0DB4F", 
          padding: ".5% 10%",
        }

    return (
      <div>
        <Navbar style={navBack}  light expand="md">
            <NavbarBrand to="/">JS</NavbarBrand>
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
      </div>
    );
  }
}
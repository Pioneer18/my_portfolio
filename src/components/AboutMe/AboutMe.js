import React from 'react';
import "./AboutMe.css";
import {
    Container,
    Row,
    Col,
    Animation
} from 'mdbreact';

import source from "../../images/nippon-profile.jpg";

const AboutMe = props => (
    <Animation reveal type="fadeIn">
        <Container className="about-container">
            <Row center>
                <Col sm="7">
                    <img className="pro-img" src={source} alt="profile-pic" />
                </Col>
            </Row>
            <Row>
                <Col className="about-p">
                    <p>I am passionate about web design &amp; creating IoT web applications and systems. Like many developers, I gained my foundational skills by obsessively tinkering with microcontrollers for hours in my garage. In order to springboard my skills beyond the level of a DIY hacker I received an AS in Engineering Technology at Hillsborough Community College, and earned a full-stack web developer certification from the Trilogy Education Services’ Coding Boot Camp at the University of Central Florida.</p>
                </Col>
            </Row>
        </Container>
    </Animation>
)

export default AboutMe;
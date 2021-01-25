import React from 'react';
import "./AboutMe.css";
import {
    Container,
    Row,
    Col,
    Animation
} from 'mdbreact';

import source from "../../images/nippon-profile.jpg";
import headshot from "../../images/jon-head-shot.jpg";

const AboutMe = props => (
    <Animation reveal type="fadeIn">
        <Container className="about-container">
            <Row center>
                <Col sm="7">
                    <img className="pro-img" src={headshot} alt="profile-pic" />
                </Col>
            </Row>
            <Row>
                <Col className="about-p">
                    <p>Experienced Full Stack Developer with a demonstrated history of working in the hospital &amp; health care industry. Skilled in TypeScript/JavaScript, NodeJS, ReactJS, AngularJS, MongoDB, AWS, and Google Cloud Platform. </p>
                </Col>
            </Row>
        </Container>
    </Animation>
)

export default AboutMe;
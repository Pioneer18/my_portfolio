import React from 'react';
import "./Gallery.css";
import { Container, Row, Col, View, Mask } from 'mdbreact';
import img1 from "../../images/veggies_soil_4.jpg";
import img2 from "../../images/nippon-profile.jpg";
import img3 from "../../images/studying.jpg";
import img4 from "../../images/southshoremain.jpg";
import img5 from "../../images/ubif_memories.JPG";
import img6 from "../../images/IMG_20180429_194629 (1).jpg";
import Project from "./Project";


export default class Gallery extends React.Component {
    constructor(props){
        super();
    }

    render() {
        return (
            <Container style={{ padding: "0px" }} className="gallery-container">
                <Row>
                    <Col style={{ padding: "0px" }} md="6" lg="4">
                        <Project url={img1} />
                    </Col>

                    <Col style={{ padding: "0px"}} md="6" lg="4">
                        <Project url={img2} />
                    </Col>

                    <Col style={{ padding: "0px"}} md="6" lg="4">
                        <Project url={img3} />
                    </Col>

                    <Col style={{ padding: "0px"}} md="6" lg="4">
                        <Project  url={img4} />
                    </Col>

                    <Col style={{ padding: "0px"}} md="6" lg="4">
                        <Project  url={img5} />
                    </Col>

                    <Col style={{ padding: "0px"}} md="6" lg="4">
                        <Project  url={img4} />
                    </Col>

                </Row>
            </Container>
        )
    }
}
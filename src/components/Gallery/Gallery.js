import React from 'react';
import "./Gallery.css";
import { Container, Row, Col, View, Mask } from 'mdbreact';
import img1 from "../../images/rememberThatCharacter.gif";
import img2 from "../../images/gardenHub.gif";
import img3 from "../../images/studying.jpg";
import img4 from "../../images/southshoremain.jpg";
import img5 from "../../images/ubif_memories.JPG";
import img6 from "../../images/liri.gif";
import Project from "./Project";


export default class Gallery extends React.Component {
    constructor(props){
        super(props);
    }


    render() {
        const liri = "https://media.giphy.com/media/kG8biFz9xx0yluJXOd/giphy.gif";
        const projects = {
            ghub2: {
                t:"GardenHub 2.1",
                h: "https://github.com/Pioneer18/garden_hub2.1"
            },
            gift: {
                t:"Giftastic",
                h: "https://pioneer18.github.io/Giftastic/"
            },
            finn: {
                t:"Rember That Character",
                h: "https://pioneer18.github.io/remember-that-character/"
            },
            liri: {
                t:"Liri",
                h: "https://github.com/Pioneer18/liri-node-app"
            },
            scrape: {
                t:"Aljazeera Scraper",
                h: "https://github.com/Pioneer18/aljazeera-scraper"
            },
            ghub: {
                t:"React SPA: Natours",
                h: "https://github.com/Pioneer18/Natours-React"
            }
        }
        return (
            <Container ref={this.props.gallery} style={{ padding: "0px" }} className="gallery-container">
                <Row>
                    <Col style={{ padding: "0px" }} md="6" lg="4">
                        <Project href={projects.finn.h} link={projects.finn.t} url={img1} />
                    </Col>

                    <Col style={{ padding: "0px"}} md="6" lg="4">
                        <Project href={projects.ghub.h} link={projects.ghub.t} url={img2} />
                    </Col>

                    <Col style={{ padding: "0px"}} md="6" lg="4">
                        <Project href={projects.ghub2.h} link={projects.ghub2.t} url={img3} />
                    </Col>

                    <Col style={{ padding: "0px"}} md="6" lg="4">
                        <Project href={projects.liri.h} link={projects.liri.t}  url={img6} />
                    </Col>

                    <Col style={{ padding: "0px"}} md="6" lg="4">
                        <Project href={projects.scrape.h} link={projects.scrape.t}  url={img5} />
                    </Col>

                    <Col style={{ padding: "0px"}} md="6" lg="4">
                        <Project href={projects.gift.h} link={projects.gift.t}  url={img4} />
                    </Col>

                </Row>
            </Container>
        )
    }
}
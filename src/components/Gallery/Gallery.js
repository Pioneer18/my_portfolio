import React from 'react';
import "./Gallery.css";
import { Container, Row, Col, View, Mask } from 'mdbreact';
import img1 from "../../images/rememberThatCharacter.gif";
import img2 from "../../images/natours.gif";
import img3 from "../../images/rent-a-car-project-vid.gif";
import img4 from "../../images/adventure_time.gif";
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
            rent_a_car: {
                t:"Rent-A-Car",
                h: "https://github.com/Pioneer18/Rent-A-Car"
            },
            gift: {
                t:"Giftastic",
                h: "https://pioneer18.github.io/Giftastic"
            },
            finn: {
                t:"Rember That Character",
                h: "https://pioneer18.github.io/remember-that-character"
            },
            liri: {
                t:"Bamazon",
                h: "https://github.com/Pioneer18/Bamazon--CLI-app"
            },
            scrape: {
                t:"Garden Hub",
                h: "https://github.com/Pioneer18/garden_hub2.1"
            },
            natours: {
                t:"Natours",
                h: "https://natours-example.uc.r.appspot.com"
            }
        }
        return (
            <Container ref={this.props.gallery} style={{ padding: "0px" }} className="gallery-container">
                <Row>
                    <Col style={{ padding: "0px" }} md="6" lg="4">
                        <Project href={projects.finn.h} link={projects.finn.t} url={img1} />
                    </Col>

                    <Col style={{ padding: "0px"}} md="6" lg="4">
                        <Project href={projects.natours.h} link={projects.natours.t} url={img2} />
                    </Col>

                    <Col style={{ padding: "0px"}} md="6" lg="4">
                        <Project href={projects.rent_a_car.h} link={projects.rent_a_car.t} url={img3} />
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
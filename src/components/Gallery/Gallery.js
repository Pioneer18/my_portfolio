import React from 'react';
import "./Gallery.css";
import { Container, Row, Col} from 'mdbreact';
import img1 from "../../images/rememberThatCharacter.gif"; // remember that
import img2 from "../../images/natours.gif"; // natours
import img3 from "../../images/rent-a-car-project-vid.gif"; // rent-a-car
import img4 from "../../images/adventure_time.gif"; // giftastic
import img5 from "../../images/garden_hub_dash.png"; // gardenhub
//import img6 from "../../images/liri.gif";
import Project from "./Project";
const img6 = "https://media.giphy.com/media/2UHfbd4EvILHHbRty1/giphy.gif" // bamazon

export default class Gallery extends React.Component {
    constructor(props){
        super(props);
    }


    render() {
        const projects = {
            rent_a_car: {
                t:"Rent-A-Car",
                h: "https://github.com/Pioneer18/Rent-A-Car/wiki/Rent-A-Car-Quickstart-Tutorial"
            },
            gift: {
                t:"Giftastic",
                h: "https://pioneer18.github.io/Giftastic"
            },
            finn: {
                t:"Rember That Character",
                h: "https://pioneer18.github.io/remember-that-character"
            },
            bamazon: {
                t:"Bamazon",
                h: "https://github.com/Pioneer18/Bamazon--CLI-app"
                
            },
            garden_hub: {
                t:"Garden Hub",
                h: "https://github.com/Pioneer18/garden_hub2.1"
            },
            natours: {
                t:"Natours",
                h: "https://natours-react-hfo6disbe.vercel.app/"
            }
        }
        return (
            <Container ref={this.props.gallery} style={{ padding: "0px" }} className="gallery-container">
                <Row>
                    <Col className="project-col" md="6" lg="4">
                        <Project href={projects.finn.h} link={projects.finn.t} url={img1} />
                    </Col>

                    <Col className="project-col" md="6" lg="4">
                        <Project href={projects.natours.h} link={projects.natours.t} url={img2} />
                    </Col>

                    <Col className="project-col" md="6" lg="4">
                        <Project href={projects.rent_a_car.h} link={projects.rent_a_car.t} url={img3} />
                    </Col>

                    <Col className="project-col" md="6" lg="4">
                        <Project href={projects.bamazon.h} link={projects.bamazon.t}  url={img6} />
                    </Col>

                    <Col className="project-col" md="6" lg="4">
                        <Project href={projects.garden_hub.h} link={projects.garden_hub.t}  url={img5} />
                    </Col>

                    <Col className="project-col" md="6" lg="4">
                        <Project href={projects.gift.h} link={projects.gift.t}  url={img4} />
                    </Col>

                </Row>
            </Container>
        )
    }
}
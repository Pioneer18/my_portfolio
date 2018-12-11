import React from 'react';
import "./Gallery.css";
import { Container, Row, Col, Card, CardBody, CardImage, CardTitle, CardText } from 'mdbreact';
import img1 from "../../images/veggies_soil_4.jpg";

export default class Gallery extends React.Component {
    render() {
        return (
            <Container style={{padding:"0"}} className="gallery-container">
                <Row>
                    <Col style={{margin:"0 0 1rem"}} sm="4">
                        <Card className="project-card" style={{ height: "", width: "100%" }}>
                            
                        </Card>
                    </Col>
                    <Col style={{margin:"0 0 1rem"}} sm="4">
                        <Card style={{ width: "100%" }}>
                            <CardImage
                                className="img-fluid"
                                src="https://mdbootstrap.com/img/Photos/Others/images/43.jpg"
                                waves
                            />
                            <CardBody>
                                <CardTitle>Card title</CardTitle>
                                <CardText>
                                    Some quick example text to build on the card title and make
                                    up the bulk of the card&apos;s content.
                                </CardText>
                            </CardBody>
                        </Card>
                    </Col>
                    <Col style={{margin:"0 0 1rem"}}  sm="4">
                        <Card style={{ width: "100%" }}>
                            <CardImage
                                className="img-fluid"
                                src="https://mdbootstrap.com/img/Photos/Others/images/43.jpg"
                                waves
                            />
                            <CardBody>
                                <CardTitle>Card title</CardTitle>
                                <CardText>
                                    Some quick example text to build on the card title and make
                                    up the bulk of the card&apos;s content.
                                </CardText>
                            </CardBody>
                        </Card>
                    </Col>
                    <Col style={{margin:"0 0 1rem"}} sm="4">
                        <Card style={{ width: "100%" }}>
                            <CardImage
                                className="img-fluid"
                                src="https://mdbootstrap.com/img/Photos/Others/images/43.jpg"
                                waves
                            />
                            <CardBody>
                                <CardTitle>Card title</CardTitle>
                                <CardText>
                                    Some quick example text to build on the card title and make
                                    up the bulk of the card&apos;s content.
                                </CardText>
                            </CardBody>
                        </Card>
                    </Col>
                    <Col style={{margin:"0 0 1rem"}} sm="4">
                        <Card style={{ width: "100%" }}>
                            <CardImage
                                className="img-fluid"
                                src="https://mdbootstrap.com/img/Photos/Others/images/43.jpg"
                                waves
                            />
                            <CardBody>
                                <CardTitle>Card title</CardTitle>
                                <CardText>
                                    Some quick example text to build on the card title and make
                                    up the bulk of the card&apos;s content.
                                </CardText>
                            </CardBody>
                        </Card>
                    </Col>
                    <Col style={{margin:"0 0 1rem"}} sm="4">
                        <Card style={{ width: "100%" }}>
                            <CardImage
                                className="img-fluid"
                                src="https://mdbootstrap.com/img/Photos/Others/images/43.jpg"
                                waves
                            />
                            <CardBody>
                                <CardTitle>Card title</CardTitle>
                                <CardText>
                                    Some quick example text to build on the card title and make
                                    up the bulk of the card&apos;s content.
                                </CardText>
                            </CardBody>
                        </Card>
                    </Col>
                </Row>
            </Container>
        )
    }
}
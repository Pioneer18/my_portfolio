import React from "react";
import "./Jumbotron.css";

export default class jumbotron extends React.Component {
    constructor(props) {
        super(props);
        this.state = { width: 0, height: 0, size: 3 };
        this.updateWindowDimensions = this.updateWindowDimensions.bind(this);
    }

    componentDidMount() {
        this.updateWindowDimensions();
        window.addEventListener('resize', this.updateWindowDimensions);

        if (this.state.width < 550) {
            this.setState({ size: 3 })
        }
        else {
            this.setState({ size: 2 })
        }
    }

    componentWillUnmount() {
        window.removeEventListener('resize', this.updateWindowDimensions);
    }

    updateWindowDimensions() {
        this.setState({ width: window.innerWidth, height: window.innerHeight });
    }


    render() {
        const height = {height: window.innerHeight, widht: window.innerWidth}
        return (
            <div style={height} className="jumbotron">
                <div className="container">
                    <h1 className="display-4">Adventure Time Memory Game</h1>
                    <p className="lead">Click on an image to earn points, but don't click on any character more than once</p>
                </div>
            </div>
        );
    }

}

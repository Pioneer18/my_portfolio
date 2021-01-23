import React from 'react';
import "./WorkButton.css";

export default class WorkButton extends React.Component {
    constructor(props) {
        super(props);

    }

    render() {
        return(
            <div className="work-button">
                <a href="#projects">View My Work</a>
            </div>
        );
    }

}
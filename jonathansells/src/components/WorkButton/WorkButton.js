import React from 'react';
import "./WorkButton.css";

export default class WorkButton extends React.Component {
    constructor(props) {
        super(props);

    }

    render() {
        return(
            <div className="work-button">
                <span>View My Work</span>
            </div>
        );
    }

}
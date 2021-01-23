import React from 'react';
import { Animation } from 'mdbreact';
import "./SectionDivider.css";
const SectionDivider = props => (
    <Animation reveal type="fadeInLeftBig">
        <div className="section-divider" id={props.id}>
            <h3>{props.divider}</h3>
        </div>
    </Animation>

)

export default SectionDivider;
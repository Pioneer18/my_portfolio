import React from 'react';
import { Animation } from 'mdbreact';
import "./SectionDivider.css";
const SectionDivider = props => (
    <Animation type="fadeInLeftBig" className="wow">
        <div className="section-divider">
            <h3>{props.divider}</h3>
        </div>
    </Animation>

)

export default SectionDivider;
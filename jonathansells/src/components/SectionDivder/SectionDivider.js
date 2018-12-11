import React from 'react';
import "./SectionDivider.css";
const SectionDivider = props => (
    <div  className="section-divider">
        <h3>{props.divider}</h3>
    </div>
)

export default SectionDivider;
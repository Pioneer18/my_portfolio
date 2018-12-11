import React from 'react';
import ScrollAnimation from 'react-animate-on-scroll';
import "./SectionDivider.css";
const SectionDivider = props => (
    <ScrollAnimation animateIn="slideInLeft" animateOnce="true">
        <div  className="section-divider">
            <h3>{props.divider}</h3>
        </div>
    </ScrollAnimation>
)

export default SectionDivider;
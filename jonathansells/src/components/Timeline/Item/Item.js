import React from 'react';
import "./Item.css";

const Item = props => (
    <li>
        <div className="timeline-badge">
            <a><i className="fa fa-circle" className=""></i></a>
        </div>
        <div className="timeline-panel">
            <div className="timeline-heading">
                <h4>{props.title}</h4>
            </div>
            <div className="timeline-img">
                <img className="study_img" src={props.imgSrc} />
            </div>
            <div className="timeline-body">
                <p>{props.text}</p>
            </div>
            <div className="timeline-footer">
                <p className="text-right">{props.date}</p>
            </div>
        </div>
    </li>
)

export default Item;
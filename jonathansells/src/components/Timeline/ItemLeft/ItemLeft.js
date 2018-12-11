import React from 'react';

const ItemLeft = props => (
    <li className="timeline-inverted">
        <div className="timeline-badge">
            <a><i className="fa fa-circle"></i></a>
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

export default ItemLeft;
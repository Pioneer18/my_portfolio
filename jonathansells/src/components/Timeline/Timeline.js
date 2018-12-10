import React from 'react';
import "./Timeline.css";
import source from "../../images/studying.jpg";
import source2 from "../../images/00001.jpg";
import source3 from "../../images/IMG_20180429_194629 (1).jpg";
import source4 from "../../images/southshoremain.jpg";
import source5 from "../../images/IMG_20180709_123231.jpg";
import source6 from "../../images/ubif_memories.JPG";
import {
    Container,
} from 'mdbreact';
import Item from "./Item";

class Timeline extends React.Component {
    constructor(props) {
        super(props);
    }

    render (){
       return (
        <Container className="time-container">
            <ul className="timeline">
            <Item />
                <li>
                    <div className="timeline-badge">
                        <a><i className="fa fa-circle" className=""></i></a>
                    </div>
                    <div className="timeline-panel">
                        <div className="timeline-heading">
                            <h4>Washington &amp; Lee University </h4>
                        </div>
                        <div className="timeline-img">
                            <img className="study_img" src={source}/>
                            </div>
                            <div className="timeline-body">
                                <p>I was not always a tech person, In fact I daul majored in international politics & Japanese Language and Literature. However, by my senior year, I decided against pursuing a political career and began searching for other possible career paths. During my final semester of college I took an introduction to Python course and found that I am far more interested in technology than politics.</p>
                            </div>
                            <div className="timeline-footer">
                                <p className="text-right">May-2014</p>
                            </div>
                        </div>
                    </li>
                    <li className="timeline-inverted">
                        <div className="timeline-badge">
                            <a><i className="fa fa-circle invert" className=""></i></a>
                        </div>
                        <div className="timeline-panel">
                            <div className="timeline-heading">
                                <h4>Teaching &amp; Studying in Japan</h4>
                            </div>
                            <div className="timeline-img">
                                <img src={source2}/>
                            </div>
                            <div className="timeline-body">
                                <p>After graduating from W&mp;L I was still unsure of what to do with my recently sparked interest in programming, so I chose to teach English in Japan for a year. While teaching, exploring, and soaking up the experiences of Japan, I continued to work through the exercises in my intro to Python textbook and I also began to study HTML and CSS. I relied on resources like Udemy, Codecademy, and Khan Academy to dive deeper into programming fundamentals, and I also discovered a new interest in Arduinos by reading coding blogs and forums. I wasn’t sure that programming microcontrollers could lead to a career, but the low cost and easy enough interface of Arduinos enticed me to try coding with them anyways.</p>
                            </div>
                            <div className="timeline-footer">
                                <p className="text-right">Nov-2014</p>
                            </div>
                        </div>
                    </li>
                    <li class="clearfix no-float"></li>
            </ul>
        </Container>
        );
    }
}
        
export default Timeline;
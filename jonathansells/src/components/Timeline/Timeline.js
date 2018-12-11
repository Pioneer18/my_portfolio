import React from 'react';
import "./Timeline.css";
import data from "./data.js"
import {
    Container,
} from 'mdbreact';
import Item from "./Item";
import ItemLeft from "./ItemLeft";


class Timeline extends React.Component {
    

    render (){
        const colors = {color: "#000000"}
       return (
        <Container className="time-container">
            <ul className="timeline">
                <Item badge={colors} imgSrc={data.panel1.src} title={data.panel1.title} text={data.panel1.text} date={data.panel1.date}/>
                <ItemLeft imgSrc={data.panel2.src} title={data.panel2.title} text={data.panel2.text} date={data.panel2.date} />
                <Item imgSrc={data.panel3.src} title={data.panel3.title} text={data.panel3.text} date={data.panel3.date}/>
                <ItemLeft imgSrc={data.panel4.src} title={data.panel4.title} text={data.panel4.text} date={data.panel4.date} />
                <Item imgSrc={data.panel5.src} title={data.panel5.title} text={data.panel5.text} date={data.panel5.date}/>
                <ItemLeft imgSrc={data.panel6.src} title={data.panel6.title} text={data.panel6.text} date={data.panel6.date}/>
                <li class="clearfix no-float"></li>
            </ul>
        </Container>
        );
    }
}
        
export default Timeline;
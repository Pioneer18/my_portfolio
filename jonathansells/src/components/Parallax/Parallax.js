import React from 'react';
import "./Parallax.css";
import WorkButton from "../WorkButton";

export default class Parallax extends React.Component {
    constructor(props) {
        super(props);
        this.state = { width: 0, height: 0 };
        this.updateWindowDimensions = this.updateWindowDimensions.bind(this);
      }
      
      componentDidMount() {
        this.updateWindowDimensions();
        window.addEventListener('resize', this.updateWindowDimensions);
      }
      
      componentWillUnmount() {
        window.removeEventListener('resize', this.updateWindowDimensions);
      }
      
      updateWindowDimensions() {
        this.setState({ width: window.innerWidth, height: window.innerHeight });
      }

    //function to grab current screen height and apply as state to height 
    //of the parallax



    render (){
        const height = {height: window.innerHeight, widht: window.innerWidth}
        return(
            <React.Fragment>
                <div style={height} className="parallax height-fix">
                    <div className="pTitle">
                        <div className="title-text">
                            Hello, I'm <span className="jsells">Jonathan Sells</span>.
                
                            <br/>

                             I'm a full-stack web &amp; 
                
                            <br/>
                
                             IoT developer.
                        </div>
                        <WorkButton handleClick={this.props.handleClick}/>
                    </div>
                </div>
            </React.Fragment>
        );
    }
}
import React from 'react';
import "./Parallax.css";
import WorkButton from "../WorkButton";
import Responsive from 'react-responsive';
const Desktop = props => <Responsive {...props} minWidth={992} />;
const Tablet = props => <Responsive {...props} minWidth={768} maxWidth={991} />;
const Mobile = props => <Responsive {...props} maxWidth={767} />;
// const Default = props => <Responsive {...props} minWidth={768} />;

export default class Parallax extends React.Component {
    constructor(props) {
        super(props);
        this.state = { width: 0, height: 0, size: 3 };
        this.updateWindowDimensions = this.updateWindowDimensions.bind(this);
      }
      
      componentDidMount() {
        this.updateWindowDimensions();
        window.addEventListener('resize', this.updateWindowDimensions);

        if(this.state.width < 550){
            this.setState({size: 3})
        }
        else{
            this.setState({size: 2})
        }
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
        const height = {height: window.innerHeight, width: window.innerWidth}
        return(
            <React.Fragment>
                <div id="AboutMe" style={height} className="parallax height-fix">
                    <div className="pTitle">
                        
                                <Desktop >
                                <div className="title-text">
                                Hello, I'm <span className="jsells">Jonathan Sells</span>.
                                <br/>
                                 I'm a full-stack web &amp; 
                                <br/>
                                IoT developer.
                                </div>
                                </Desktop>
                                <Tablet >
                                <div className="title-text"> 
                                    Hello, I'm <span className="jsells">Jonathan Sells</span>.
                                    <br/>
                                    I'm a full-stack web &amp; 
                                    <br/>
                                    IoT developer.    
                                </div>
                                </Tablet>
                                <Mobile >
                                <div className="small"> 
                                    Hello, I'm <span className="jsells">Jonathan Sells</span>.
                                    <br/>
                                    I'm a full-stack web &amp; 
                                    <br/>
                                    IoT developer.
                                </div>
                                </Mobile>
                            
                        <WorkButton scrollToProjects={this.props.scrollToProjects}/>
                    </div>
                </div>
            </React.Fragment>
        );
    }
}
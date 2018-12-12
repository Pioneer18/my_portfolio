/*
import React from 'react';
import { View, Mask, Animation, Card } from 'mdbreact';
const Project = props => (
    <Animation reveal type="fadeInUp">
        <View hover className="project-card" >
        <Card className="project" style={{background: `url(${props.url})`}}>
            <Mask overlay="white-strong" className="flex-center">
                <p className="white-text">strong overlay</p>
            </Mask>
        </Card>
        </View>
    </Animation>
)

export default Project;
*/


import React from 'react';
import { Animation } from 'mdbreact';
const Project = props => (
    <Animation reveal type="fadeInUp">
        <div style={{background:`url(${props.url})`, backgroundPosition:`center`, backgroundSize:`cover`}} className="project">
            <div className="overlay">
                <div className="text">Hello World</div>
            </div>
        </div>
    </Animation>
)

export default Project;

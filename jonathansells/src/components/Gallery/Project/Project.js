import React from 'react';
import { View, Mask } from 'mdbreact';

const Project = props => (
    <View hover className="project-card" style={{ backgroundImage: `url(${props.url})`, width: "100%" }}>
        <Mask overlay="white-strong" className="flex-center">
            <p className="white-text">strong overlay</p>
        </Mask>
    </View>
)

export default Project;

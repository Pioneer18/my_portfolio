import React from 'react';
import { View, Mask, Animation } from 'mdbreact';

const Project = props => (
    <Animation reveal type="fadeInUp">
        <View hover className="project-card" style={{ backgroundImage: `url(${props.url})`, width: "100%" }}>
            <Mask overlay="white-strong" className="flex-center">
                <p className="white-text">strong overlay</p>
            </Mask>
        </View>
    </Animation>
)

export default Project;

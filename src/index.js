import React from 'react';
import ReactDOM from 'react-dom';
import './index.css';
import {BrowserRouter as Router, Route } from "react-router-dom";

//===========imported mdbreact style files===============
import 'font-awesome/css/font-awesome.min.css';
import 'bootstrap-css-only/css/bootstrap.min.css'; 
import 'mdbreact/dist/css/mdb.css';
import 'bootstrap/dist/css/bootstrap.css';
//=======================================================
import App from './App';
import Navigation from "./components/Navigation";
// import * as serviceWorker from './serviceWorker';
//import 'font-awesome/css/font-awesome.min.css'; 


/*ReactDOM.render(<App />, document.getElementById('root'));

// If you want your app to work offline and load faster, you can change
// unregister() to register() below. Note this comes with some pitfalls.
// Learn more about service workers: http://bit.ly/CRA-PWA
serviceWorker.unregister();*/


ReactDOM.render(
        <Router>     
            <App>
                <Route exact path="/"  component={Navigation} />
            </App>    
        </Router>,
    document.getElementById("root")
    );


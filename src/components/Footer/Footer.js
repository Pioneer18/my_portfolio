import React from 'react';
import "./Footer.css";
import { NavbarBrand} from 'mdbreact';
import {FontAwesomeIcon} from '@fortawesome/react-fontawesome';
import {faGithub, faLinkedin, faCodepen} from '@fortawesome/free-brands-svg-icons';

const Footer = props => {
    return (
        <footer id="footer" className="footer">
            <div className="footer__logo-box">
                <NavbarBrand id="logo">
                    JS
                </NavbarBrand>
            </div>
            <div className="footer__contact-nav">
                <ul className="footer__contact-list">
                    <li className="footer__contact-item"><a href="https://www.linkedin.com/in/jsells28/" className="footer__link">Linkedin</a><FontAwesomeIcon icon={faLinkedin} /></li>
                    <li className="footer__contact-item"><a href="https://github.com/Pioneer18" className="footer__link">Github</a><FontAwesomeIcon icon={faGithub} /></li>
                    <li className="footer__contact-item"><a href="https://codepen.io/Pioneer18" className="footer__link">Codepen</a><FontAwesomeIcon icon={faCodepen} /></li>
                </ul>
            </div>
        </footer>
    )
}

export default Footer;

//      <li className="footer__contact-item"><a href="mindful.developer.js@gmail.com" className="footer__link">Gmail</a><FontAwesomeIcon icon={faEnvelope} /></li>
import React from 'react';
import "./Footer.css";
import { NavbarBrand} from 'mdbreact';

const Footer = props => {
    return (
        <footer className="footer">
            <div className="footer__logo-box">
                <NavbarBrand id="logo">
                    JS
                </NavbarBrand>
            </div>
            <div className="footer__contact-nav">
                <ul className="footer__contact-list">
                    <li className="footer__contact-item"><a href="https://www.linkedin.com/in/jsells28/" className="footer__link">Linkedin</a></li>
                    <li className="footer__contact-item"><a href="https://github.com/Pioneer18" className="footer__link">Github</a></li>
                    <li className="footer__contact-item"><a href="mindful.developer.js@gmail.com" className="footer__link">Gmail</a></li>
                    <li className="footer__contact-item"><a href="https://codepen.io/Pioneer18" className="footer__link">Codepen</a></li>
                </ul>
            </div>
        </footer>
    )
}

export default Footer;
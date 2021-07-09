const chai = require("chai");
window.expect = chai.expect;

const context = require.context(
    "mocha-loader!./",
    false, 
    /\.spec.js$/
);
context.keys().forEach(context);
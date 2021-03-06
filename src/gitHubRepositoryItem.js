// Generated by BUCKLESCRIPT VERSION 1.8.1, PLEASE EDIT WITH CARE
'use strict';

var React       = require("react");
var Pervasives  = require("bs-platform/lib/js/pervasives.js");
var ReasonReact = require("reason-react/lib/js/src/reasonReact.js");

var component = ReasonReact.statelessComponent("GitHubRepositoryItem");

function make(repository, _) {
  var newrecord = component.slice();
  newrecord[/* render */9] = (function () {
      return React.createElement("div", {
                  className: "GitHubRepositoryItem"
                }, React.createElement("a", {
                      href: repository[/* html_url */3]
                    }, repository[/* full_name */1]), Pervasives.string_of_int(repository[/* stargazers_count */2]) + " stars");
    });
  return newrecord;
}

exports.component = component;
exports.make      = make;
/* component Not a pure module */

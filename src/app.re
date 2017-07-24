let component = ReasonReact.statelessComponent "App";

let make ::name _children => {
  ...component,
  render: fun self =>
    <div className="App">
      <header className="App-header"> <h1> (ReasonReact.stringToElement name) </h1> </header>
    </div>
};

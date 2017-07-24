let dummy_repo: RepositoryData.github_repository =
  RepositoryData.parse_repository_json (
    Js.Json.parseExn {js|
      {
        "id": "1",
        "full_name": "test name",
        "stargazers_count": 129,
        "html_url": "https://github.com/mmiszy/reason-react-github-list"
      }
    |js}
  );

type state = {repositories: option (array RepositoryData.github_repository)};

let component = ReasonReact.statefulComponent "App";

let make ::name _children => {
  ...component,
  initialState: fun () => ({repositories: Some [|dummy_repo|]}: state),
  render: fun {state} => {
    let repositoryItem =
      switch state.repositories {
      | Some repositories => <GitHubRepositoryList repositories />
      | None => <div> (ReasonReact.stringToElement {j|Loading…|j}) </div>
      };
    <div className="App">
      <header className="App-header"> <h1> (ReasonReact.stringToElement name) </h1> </header>
      repositoryItem
    </div>
  }
};

type state = {repositories: option (array RepositoryData.github_repository)};

let handleReposLoaded repos _self => ReasonReact.Update {repositories: Some repos};

let component = ReasonReact.statefulComponent "App";

let make ::name _children => {
  ...component,
  initialState: fun () => ({repositories: None}: state),
  didMount: fun self => {
    Js.Promise.(
      RepositoryData.fetch_repositories () |>
      then_ (
        fun repos => {
          (self.update handleReposLoaded) repos;
          resolve ()
        }
      ) |> ignore
    );
    ReasonReact.NoUpdate
  },
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

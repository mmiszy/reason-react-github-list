let component = ReasonReact.statelessComponent "GitHubRepositoryList";

let make repositories::(repositories: array RepositoryData.github_repository) _children => {
  ...component,
  render: fun self =>
    <div className="GitHubRepositoryList">
      (
        ReasonReact.arrayToElement (
          repositories |>
          Array.map (
            fun (repository: RepositoryData.github_repository) =>
              <GitHubRepositoryItem key=repository.id repository />
          )
        )
      )
    </div>
};

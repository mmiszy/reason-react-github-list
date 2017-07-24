let component = ReasonReact.statelessComponent "GitHubRepositoryItem";

let make repository::(repository: RepositoryData.github_repository) _children => {
  ...component,
  render: fun self =>
    <div className="GitHubRepositoryItem">
      <a href=repository.html_url> (ReasonReact.stringToElement repository.full_name) </a>
      (ReasonReact.stringToElement (string_of_int repository.stargazers_count ^ " stars"))
    </div>
};

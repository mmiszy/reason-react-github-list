type github_repository = {
  id: string,
  full_name: string,
  stargazers_count: int,
  html_url: string
};

let github_repos_url = "https://api.github.com/search/repositories?q=topic%3Areasonml&type=Repositories";

let parse_repository_json json :github_repository =>
  Json.Decode.{
    id: field "full_name" string json,
    full_name: field "full_name" string json,
    stargazers_count: field "stargazers_count" int json,
    html_url: field "html_url" string json
  };

let parse_repository_response_json json =>
  Json.Decode.field "items" (Json.Decode.array parse_repository_json) json;

let fetch_repositories () =>
  Js.Promise.(
    Bs_fetch.fetch github_repos_url |> then_ Bs_fetch.Response.text |>
    then_ (fun json_text => resolve (parse_repository_response_json (Js.Json.parseExn json_text)))
  );

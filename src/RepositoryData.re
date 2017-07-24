type github_repository = {
  id: string,
  full_name: string,
  stargazers_count: int,
  html_url: string
};

let parse_repository_json json :github_repository =>
  Json.Decode.{
    id: field "full_name" string json,
    full_name: field "full_name" string json,
    stargazers_count: field "stargazers_count" int json,
    html_url: field "html_url" string json
  };

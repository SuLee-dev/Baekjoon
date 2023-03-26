const fs = require("fs");

let [input, ...inputs] = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [N, M] = input.split(" ").map(Number);

let visited = Array(N + 1).fill(false);
let map = Array.from(Array(N + 1), () => new Array(0));

for (let i = 0; i < M; ++i) {
  const [a, b] = inputs[i].split(" ").map(Number);
  map[a].push(b);
  map[b].push(a);
}

function DFS(x) {
  visited[x] = true;
  for (let i = 0; i < map[x].length; ++i) {
    if (!visited[map[x][i]]) DFS(map[x][i]);
  }
}

let count = 0;
for (let i = 1; i <= N; ++i) {
  if (!visited[i]) {
    DFS(i);
    ++count;
  }
}

console.log(count);
const fs = require("fs");

const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const T = input.shift();

for (let i = 0; i < T; ++i) {
  const [M, N, K] = input.shift().split(" ").map(Number);
  let farm = Array.from(Array(N), () => Array(M).fill(0));
  let visited = Array.from(Array(N), () => Array(M).fill(false));
  let count = 0;

  for (let k = 0; k < K; ++k) {
    const [x, y] = input.shift().split(" ").map(Number);
    farm[y][x] = 1;
  }

  function DFS(x, y) {
    if (x >= 0 && x < M && y >= 0 && y < N && farm[y][x] && !visited[y][x]) {
      visited[y][x] = true;
      DFS(x + 1, y);
      DFS(x, y + 1);
      DFS(x - 1, y);
      DFS(x, y - 1);
    }
  }

  for (let y = 0; y < N; ++y) {
    for (let x = 0; x < M; ++x) {
      if (farm[y][x] && !visited[y][x]) {
        DFS(x, y);
        ++count;
      }
    }
  }

  console.log(count);
}
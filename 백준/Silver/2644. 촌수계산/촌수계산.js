const fs = require("fs");

const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const n = Number(input.shift());
const [a, b] = input.shift().split(" ").map(Number);
const m = Number(input.shift());

let family = Array.from(Array(n + 1), () => Array(n + 1).fill(0));
let visited = Array(n + 1).fill(false);

for (let i = 0; i < m; ++i) {
  const [x, y] = input.shift().split(" ").map(Number);
  [family[x][y], family[y][x]] = [1, 1];
}

function BFS(a) {
  let queue = [];
  let count = 0;
  queue.push(a);
  visited[a] = true;

  while (queue.length > 0) {
    ++count;
    const size = queue.length;

    for (let j = 0; j < size; ++j) {
      const e = queue.shift();

      for (let i = 1; i <= n; ++i) {
        if (family[e][i] === 1 && !visited[i]) {
          if (i === b) return count;
          visited[i] = true;
          queue.push(i);
        }
      }
    }
  }

  return -1;
}


console.log(BFS(a));
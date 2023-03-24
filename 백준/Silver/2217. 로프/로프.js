const fs = require("fs");

const [N, ...rest] = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const weights = rest.map(Number).sort((a, b) => {
  return b - a;
});

let result = 0;
for (let i = 0; i < N; ++i) {
  const limit = weights[i] * (i + 1);
  result = limit > result ? limit : result;
}

console.log(result);
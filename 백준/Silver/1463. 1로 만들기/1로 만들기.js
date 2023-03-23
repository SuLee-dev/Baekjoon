const fs = require("fs");

const N = Number(fs.readFileSync("/dev/stdin").toString().trim());

let DP = [, 0];

for (let i = 2; i <= N; ++i) {
  DP[i] = DP[i] = DP[i - 1] + 1;
  if (!(i % 2)) DP[i] = Math.min(DP[i], DP[i / 2] + 1);
  if (!(i % 3)) DP[i] = Math.min(DP[i], DP[i / 3] + 1);
}

console.log(DP[N]);
const fs = require("fs");

const N = Number(fs.readFileSync("/dev/stdin").toString().trim());

let DP = [0, 0, 1, 1];

for (let i = 4; i <= N; ++i) {
  if (!(i % 6)) DP[i] = Math.min(DP[i / 3], DP[i / 2], DP[i - 1]) + 1;
  else if (!(i % 3)) DP[i] = Math.min(DP[i / 3], DP[i - 1]) + 1;
  else if (!(i % 2)) DP[i] = Math.min(DP[i / 2], DP[i - 1]) + 1;
  else DP[i] = DP[i - 1] + 1;
}

console.log(DP[N]);
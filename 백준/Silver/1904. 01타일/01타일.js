const fs = require("fs");
const N = Number(fs.readFileSync("/dev/stdin").toString().trim());

let DP = [, 1, 2];
for (let i = 3; i <= N; ++i) DP[i] = (DP[i - 1] + DP[i - 2]) % 15746;

console.log(DP[N]);
const fs = require("fs");

const N = Number(fs.readFileSync("/dev/stdin").toString().trim());

let DP = [, 1, 1];

for (let i = 3; i <= N; ++i) DP[i] = BigInt(DP[i - 1]) + BigInt(DP[i - 2]);

console.log(String(DP[N]));
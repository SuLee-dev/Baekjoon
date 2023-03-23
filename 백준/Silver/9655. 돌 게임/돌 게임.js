const fs = require("fs");

const N = Number(fs.readFileSync("/dev/stdin").toString().trim());

let DP = [0, "SK", "CY"];

for (let i = 3; i <= 1000; ++i) DP[i] = DP[i - 2];

console.log(DP[N]);
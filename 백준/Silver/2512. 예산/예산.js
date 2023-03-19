const fs = require("fs");

const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const N = input.shift();
const requests = input.shift().split(" ").map(Number);
const M = Number(input.shift());

function solve(requests, total) {
  let left = 1;
  let right = Math.max(...requests);

  while (left <= right) {
    const mid = Math.floor((left + right) / 2);
    const sum = requests.reduce((acc, request) => acc + (request > mid ? mid : request), 0);
    if (sum <= total) left = mid + 1;
    else right = mid - 1;
  }

  return right;
}

const result = solve(requests, M);
console.log(result);
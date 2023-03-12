const fs = require("fs");
const [n, input] = fs
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
const arr = input
  .trim()
  .split(" ")
  .map((e) => Number(e))
  .sort(function (a, b) {
    return a - b;
  });

const result = arr[0] * arr.slice(-1)[0];

console.log(result);
const fs = require("fs");
const [n, k] = fs
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split(" ")
  .map((e) => Number(e));

const arr = Array(n)
  .fill()
  .map((_, i) => i + 1);
let result = "<";

let idx = 0;
while (arr.length > 0) {
  idx = (idx + k - 1) % arr.length;
  result += arr[idx] + ", ";
  arr.splice(idx, 1);
}

result = result.slice(0, -2) + ">";
console.log(result);
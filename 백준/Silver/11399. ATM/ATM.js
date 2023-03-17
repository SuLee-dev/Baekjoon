const fs = require("fs");

const [n, rest] = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const arr = rest.split(" ").map(Number).sort((a, b) => {
    return a - b;
  });

let result = 0;
let sum = 0;

for (e of arr) {
  sum += e;
  result += sum;
}

console.log(result);

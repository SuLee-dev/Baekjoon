const fs = require("fs");

let [a, b] = fs.readFileSync("/dev/stdin").toString().trim().split(" ");
if (a < b) [a, b] = [b, a];

const [m, n] = [a, b];
while (a % b > 0) {
  if (a % b === 0) break;
  [a, b] = [b, a % b];
}

const gcd = b;
const lcm = (m * n) / gcd;

console.log(gcd + "\n" + lcm);
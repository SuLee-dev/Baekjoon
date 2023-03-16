const fs = require("fs");

const board = fs.readFileSync("/dev/stdin").toString().trim();

let Xs = board.replace(/\./g, " ").split(" ");

let arr = [];
let isPossible = true;
for (e of Xs) {
  if (e.length % 2 === 1) {
    isPossible = false;
    break;
  } else {
    const countAAAA = e.length / 4;
    const countBB = (e.length % 4) / 2;
    arr.push("AAAA".repeat(countAAAA) + "BB".repeat(countBB));
  }
}

const result = isPossible ? arr.join(".") : -1;

console.log(result);

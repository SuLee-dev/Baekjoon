const fs = require("fs");
const [n, ...input] = fs
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");

let arr = [];
let result = "";
const inputArr = input.map((e) => e.replace(/\r/g, ""));

for (e of inputArr) {
  if (e.includes("push")) arr.push(Number(e.replace("push", "").trim()));
  else if (e === "pop") {
    if (arr.length > 0) result += arr.pop() + "\n";
    else result += "-1\n";
  } else if (e === "size") result += arr.length + "\n";
  else if (e === "empty") result += (arr.length === 0 ? 1 : 0) + "\n";
  else if (e === "top") {
    if (arr.length > 0) result += arr.slice(-1)[0] + "\n";
    else result += "-1\n";
  }
}

console.log(result);
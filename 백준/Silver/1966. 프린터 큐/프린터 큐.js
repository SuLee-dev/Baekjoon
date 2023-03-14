const fs = require("fs");

const [caseNum, ...rest] = fs
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");

const arr = rest.map((e) => e.replace(/\r/g, ""));

let result = "";

for (let i = 0; i < caseNum; ++i) {
  const [n, m] = arr[2 * i].split(" ").map(Number);
  const priorities = arr[2 * i + 1].split(" ").map(Number);

  result += getPrintOrder(priorities, m) + "\n";
}

console.log(result);

function getPrintOrder(priorities, m) {
  const queue = priorities.map((priority, idx) => ({ idx, priority }));
  const printed = [];
  while (queue.length > 0) {
    const front = queue.shift();
    if (queue.some((e) => e.priority > front.priority)) queue.push(front);
    else printed.push(front);
  }

  return printed.findIndex((e) => e.idx === m) + 1;
}

const fs = require("fs");
const input = Number(fs.readFileSync("/dev/stdin").toString().trim());

for (let i = 0; i < input; ++i) {
  console.log(" ".repeat(input - i - 1) + "*".repeat(2 * i + 1));
}

for (let i = 1; i < input; ++i) {
  console.log(" ".repeat(i) + "*".repeat(2 * (input - i) - 1));
}
const fs = require("fs");

const n = Number(fs.readFileSync("/dev/stdin").toString().trim());

let num = 1;

while (num <= n) {
  let [sum, temp] = [num, num];
  while (temp > 0) {
    sum += temp % 10;
    temp = Math.floor(temp / 10);
  }
  if (sum === n) {
    console.log(num);
    return;
  } else ++num;
}

console.log(0);
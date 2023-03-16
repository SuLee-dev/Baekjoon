const fs = require("fs");

const money = Number(fs.readFileSync("/dev/stdin").toString().trim());

let arr = Array(100001).fill(-1);

[arr[2], arr[4], arr[5]] = [1, 2, 1];

for (let i = 6; i <= money; ++i) {
  arr[i] =
    arr[i - 2] === -1 && arr[i - 5] === -1
      ? -1
      : arr[i - 5] === -1
      ? arr[i - 2] + 1
      : Math.min(arr[i - 2] + 1, arr[i - 5] + 1);
}

console.log(arr[money]);

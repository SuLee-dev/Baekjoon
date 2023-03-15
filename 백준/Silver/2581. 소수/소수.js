const fs = require("fs");

const [m, n] = fs
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n")
  .map(Number);

let arr = Array(n + 1)
  .fill(1)
  .map((e, idx) => ({
    num: idx,
    isPrime: Boolean(e),
  }));
arr[1].isPrime = false;

for (let i = 2; i <= Math.sqrt(n); ++i) {
  if (arr[i].isPrime === true) {
    let j = 2;
    while (i * j <= n) {
      arr[i * j].isPrime = false;
      ++j;
    }
  }
}

if (arr.slice(m, n + 1).some((e) => e.isPrime)) {
  const newArr = arr.slice(m, n + 1).filter((e) => e.isPrime);

  let result = 0;
  for (e of newArr) result += e.num;

  console.log(result + "\n" + newArr[0].num);
} else {
  console.log(-1);
}

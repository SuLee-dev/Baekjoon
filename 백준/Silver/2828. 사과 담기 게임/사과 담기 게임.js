const fs = require("fs");

const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const [N, M] = input.shift().split(" ").map(Number);
const J = Number(input.shift());

let [result, basket] = [0, 0];
while (input.length > 0) {
  const apple = Number(input.shift()) - 1;

  if (basket <= apple && basket + M - 1 >= apple) continue;
  else if (basket > apple) {
    result += basket - apple;
    basket = apple;
  } else {
    result += apple - basket - M + 1;
    basket = apple - M + 1;
  }
}

console.log(result);
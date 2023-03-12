const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim();

let result = "";

for (let i = 0; i < input.length; ++i) {
  const char =
    input.charCodeAt(i) - 3 >= 65
      ? String.fromCharCode(input.charCodeAt(i) - 3)
      : String.fromCharCode(input.charCodeAt(i) + 23);
  result += char;
}

console.log(result);
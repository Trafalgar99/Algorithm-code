const readline = require("readline");

rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

rl.on("line", (data) => {
  let x = parseFloat(data);
  let l = -10000,
    r = 10000;
  while (r - l > 1e-8) {
    let mid = (l + r) / 2;
    if (mid * mid * mid >= x) r = mid;
    else l = mid;
  }
  console.log(l.toFixed(6));
});

const readline = require("readline");

rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});
let n = 0,
  m = 0;
let h = [];
let size = 0;
let result = [];
//-----------------------------------------------------------------------------

rl.on("line", (data) => {
  if (n === 0) {
    [n, m] = data.split(" ").map((i) => +i);
  } else {
    main(data);
  }
});
//-----------------------------------------------------------------------------
function main(data) {
  h = [0, ...data.split(" ").map((i) => +i)];
  size = n;
  for (let i = Math.floor(n / 2); i; i--) down(i);
  while (m--) {
    result.push(h[1]);
    h[1] = h[size];
    size--;
    down(1);
  }
  console.log(result.join(" "));
}
function down(x) {
  let t = x;
  if (x * 2 <= size && h[x * 2] < h[t]) t = x * 2;
  if (x * 2 + 1 <= size && h[x * 2 + 1] < h[t]) t = x * 2 + 1;
  if (t != x) {
    swap(t, x);
    down(t);
  }
}
function swap(a, b) {
  let t = h[a];
  h[a] = h[b];
  h[b] = t;
}

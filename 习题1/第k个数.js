const readline = require("readline");

rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});
let n = 0,
  k = 0;
let q = [];
rl.on("line", (data) => {
  if (n === 0) {
    [n, k] = data.split(" ").map((i) => +i);
  } else {
    main(data);
  }
});

function main(data) {
  q = data.split(" ").map((i) => +i);
  console.log(quick_find(0, n - 1, k));
}

function quick_find(l, r, k) {
  if (l >= r) return q[l];
  let x = q[l],
    i = l - 1,
    j = r + 1;
  while (i < j) {
    while (q[++i] < x);
    while (q[--j] > x);
    if (i < j) swap(i, j);
  }
  let sl = j - l + 1;
  return k <= sl ? quick_find(l, j, k) : quick_find(j + 1, r, k - sl);
}

function swap(a, b) {
  let x = q[a];
  q[a] = q[b];
  q[b] = x;
}

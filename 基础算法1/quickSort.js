const readline = require("readline");

rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let n = 0;
let q = [];
rl.on("line", (data) => {
  if (n === 0) {
    n = +data;
  } else {
    main(data);
  }
});

function main(data) {
  q = data.split(" ").map((i) => +i);
  quick_sort(q, 0, n - 1);
  let res = q.join(" ");
  console.log(res);
}
function quick_sort(q, l, r) {
  if (l >= r) return;
  let x = q[Math.floor((l + r) / 2)],
    i = l - 1,
    j = r + 1;
  while (i < j) {
    while (q[++i] < x);
    while (q[--j] > x);
    if (i < j) swap(i, j);
  }
  quick_sort(q, l, j);
  quick_sort(q, j + 1, r);
}

function swap(a, b) {
  let x = q[a];
  q[a] = q[b];
  q[b] = x;
}

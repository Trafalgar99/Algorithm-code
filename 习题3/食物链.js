const readline = require("readline");

rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let k = 0,
  n = 0;
let p = [],
  d = [],
  res = 0;
init();
rl.on("line", (data) => {
  if (k === 0) {
    [n, k] = data.split(" ").map((i) => +i);
    // console.log(n, "===", k);
    init_p(n);
  } else if (k--) {
    [t, x, y] = data.split(" ").map((i) => +i);
    main(t, x, y);
    if (k === 0) {
      console.log(res);
    }
  }
});

function init_p(n) {
  for (let i = 1; i <= n; i++) p[i] = i;
}
function init() {
  for (let i = 1; i <= 50010; i++) {
    p[i] = 0;
    d[i] = 0;
  }
}
function main(t, x, y) {
  if (x > n || y > n) res++;
  else {
    let px = find(x),
      py = find(y);
    if (t === 1) {
      if (px != py) {
        p[px] = py;
        d[px] = d[y] - d[x];
      } else if (px === py && (d[x] - d[y]) % 3) res++;
    } else {
      if (px != py) {
        p[px] = py;
        d[px] = d[y] + 1 - d[x];
      } else if (px == py && (d[x] - d[y] - 1) % 3) res++;
    }
  }
}
function find(x) {
  if (p[x] !== x) {
    let t = find(p[x]);
    d[x] += d[p[x]];
    p[x] = t;
  }
  return p[x];
}

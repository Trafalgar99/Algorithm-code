const readline = require("readline");

rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});
let input = [];
rl.on("line", (data) => {
  input.push(data);
  if (input.length == 2) {
    // console.log(input);
    let [n, list] = input;
    n = +n;
    list = list.split(" ").map((x) => x - 0);
    console.log(answer(n, list));
  }
});
const N = 100010,
  M = 31 * N;
let son = [],
  idx = 0;
for (let i = 0; i < M; i++) {
  son[i] = [0, 0];
}
function answer(n, list) {
  let res = 0;
  for (let i = 0; i < n; i++) {
    insert(list[i]);
    let t = query(list[i]);

    res = Math.max(res, list[i] ^ t);
  }

  return res;
}
function insert(x) {
  let p = 0;
  for (let i = 30; i >= 0; i--) {
    let u = (x >> i) & 1;
    if (!son[p][u]) son[p][u] = ++idx;
    p = son[p][u];
  }
}
function query(x) {
  let p = 0,
    res = 0;
  for (let i = 30; i >= 0; i--) {
    let u = (x >> i) & 1;

    u = son[p][tran(u)] ? tran(u) : u;
    p = son[p][u];
    res = (res << 1) + u;
    // if (son[p][tran(u)]) {
    //   p = son[p][tran(u)];
    //   res = (res << 1) + tran(u);
    // } else {
    //   p = son[p][u];
    //   res = (res << 1) + u;
    // }
    // console.log('query--',u)
  }
  return res;
}

function tran(x) {
  return x === 1 ? 0 : 1;
}

// !0 === true !== 1
// ~0 === -1 !== 1

const { mainModule } = require("process");
const readline = require("readline");

let rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});
const N = 110;
let n, m, k;
let g = [];
let d = [];
for (let i = 0; i < N; i++) d[i] = [];
for (let i = 0; i < N; i++) for (let j = 0; j < N; j++) d[i][j] = -1;
let q = [];
rl.on("line", (data) => {
  if (n === undefined) {
    [n, m] = data.split(" ").map((i) => +i);
    k = n;
  } else if (k === 1) {
    g.push(data.split(" ").map((i) => +i));
    main();
  } else if (k-- > 1) {
    console.log(data);
    g.push(data.split(" ").map((i) => +i));
    console.log(g);
  }
});
function main() {
  console.log(bfs());
}
function bfs() {
  let hh = 0,
    tt = 0;
  d[0][0] = 0;
  q[0] = [0, 0];
  let dx = [-1, 0, 1, -1],
    dy = [0, 1, 0, -1];
  while (hh <= tt) {
    let t = q[hh++];
    for (let i = 0; i < 4; i++) {
      let x = t[0] + dx[i],
        y = t[1] + dy[i];
      if (
        x >= 0 &&
        x < n &&
        y >= 0 &&
        y < n &&
        g[x][y] === 0 &&
        d[x][y] === -1
      ) {
        d[x][y] = d[t[0]][t[1]] + 1;
        q[++tt] = [x, y];
      }
    }
  }
  return d[n - 1][m - 1];
}

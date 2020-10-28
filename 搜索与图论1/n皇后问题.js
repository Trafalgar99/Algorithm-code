const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});
const N = 20;
let n;
let g = [];
let col = [], //不要随便用连等于
  deg = [],
  udeg = [];

rl.on("line", (data) => {
  n = parseInt(data);
  init();
  dfs(0);
});

function init() {
  for (let i = 0; i <= N; i++) {
    col[i] = deg[i] = udeg[i] = false;
  }
  for (let i = 0; i < n; i++) g[i] = [];
  for (let i = 0; i < n; i++) for (let j = 0; j < n; j++) g[i][j] = ".";
}
function dfs(x) {
  if (x === n) {
    for (let i = 0; i < n; i++) console.log(g[i].join(""));
    console.log();
    return;
  }
  for (let i = 0; i < n; i++) {
    if (!col[i] && !deg[x + i] && !udeg[n - x + i]) {
      g[x][i] = "Q";
      col[i] = deg[x + i] = udeg[n - x + i] = true;
      dfs(x + 1);
      col[i] = deg[x + i] = udeg[n - x + i] = false;
      g[x][i] = ".";
    }
  }
}

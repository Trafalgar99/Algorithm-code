const readline = require("readline");

rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let n;
const N = 10;
let path = [];
let st = [];
for (let i = 0; i < N; i++) st.push(false);
s;

rl.on("line", (data) => {
  n = parseInt(data);
  dfs(0);
});

function dfs(x) {
  if (x === n) {
    console.log(path.join(" "));
    return;
  }
  for (let i = 1; i <= n; i++) {
    if (!st[i]) {
      path[x] = i;
      st[i] = true;
      dfs(x + 1);
      st[i] = false;
    }
  }
}

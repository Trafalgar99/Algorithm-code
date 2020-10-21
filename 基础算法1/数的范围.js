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
  } else if (q.length === 0) {
    q = data.split(" ").map((i) => +i);
  } else if (k--) {
    main(parseInt(data));
  }
});

//--------------------------------------------------------
function main(x) {
  let res = "";
  let l = 0,
    r = n - 1;
  while (l < r) {
    let mid = (l + r) >> 1;
    if (q[mid] >= x) r = mid;
    else l = mid + 1;
  }
  if (q[l] != x) console.log("-1 -1");
  else {
    res = res + l + " ";
    let a = 0,
      r = n - 1;
    while (a < r) {
      let mid = (a + r + 1) >> 1;
      if (q[mid] <= x) a = mid;
      else r = mid - 1;
    }
    res += a;
    console.log(res);
  }
}

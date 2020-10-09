let n = 1,
  m = 2,
  a = [1, 2, 3, 4, 5];

let s = [];

for (let i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];

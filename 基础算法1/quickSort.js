(function () {
  function swap(arr, i, j) {
    let c = arr[i];
    arr[i] = arr[j];
    arr[j] = c;
  }
  function quickSort(arr, l, r) {
    if (l >= r) return;
    let i = l - 1;
    let j = r + 1;
    let x = arr[Math.floor((l + r) / 2)];

    while (i < j) {
      while (arr[++i] < x);
      while (arr[--j] > x);
      if (i < j) {
        swap(arr, i, j);
      }
    }
    quickSort(arr, l, j), quickSort(arr, j + 1, r);
  }

  arr = [3, 1, 2, 4, 5];
  quickSort(arr, 0, arr.length - 1);
  arr.forEach((e) => {
    console.log(e);
  });
})();

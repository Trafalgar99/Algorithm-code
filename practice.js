(function () {
  // 快速排序
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

  //归并排序
  let merge_tmp = [];
  function mergeSort(arr, l, r) {
    if (l >= r) return;
    let mid = Math.floor((l + r) / 2);
    mergeSort(arr, l, mid), mergeSort(arr, mid + 1, r);
    let k = 0,
      i = l,
      j = mid + 1;
    while (i <= mid && j <= r) {
      if (arr[i] <= arr[j]) merge_tmp[k++] = arr[i++];
      else merge_tmp[k++] = arr[j++];
    }
    while (i <= mid) merge_tmp[k++] = arr[i++];
    while (j <= r) merge_tmp[k++] = arr[j++];

    for (let i = l, j = 0; i <= r; i++, j++) arr[i] = merge_tmp[j];
  }

  // 二分查找
  function bsearch_1(l, r) {
    while (l < r) {
      mid = (l + r) >> 1;
      if (check(mid)) r = mid;
      else l = mid + 1;
    }
    return l;
  }

  function bsearch_1(l, r) {
    while (l < r) {
      mid = (l + r + 1) >> 1;
      if (check(mid)) l = mid;
      else r = mid - 1;
    }
    return l;
  }

  /*
   *
   *
   *
   *
   *
   *
   *
   *
   *
   *
   */

  //test
  arr = [3, 1, 2, 4, 5];
  // quickSort(arr,0,arr.length-1);
  mergeSort(arr, 0, arr.length - 1);
  arr.forEach((e) => {
    console.log(e);
  });
})();

(function () {
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
})();

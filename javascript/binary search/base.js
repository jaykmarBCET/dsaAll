var binarySearch = function (arr, key) {
    var start = 0;
    var end = arr.length - 1;
    while (start <= end) {
        var mid = Math.floor(start + (end - start) / 2);
        if (arr[mid] === key)
            return mid;
        else if (arr[mid] < key)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1; // Element not found
};
var arr = [1, 2, 3, 4, 5, 6, 7, 8];
console.log(binarySearch(arr, 7));

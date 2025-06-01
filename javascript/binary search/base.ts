const binarySearch = (arr: number[], key: number): number => {
    let start = 0;
    let end = arr.length - 1; 

    while (start <= end) {
        let mid = Math.floor(start + (end - start) / 2); 

        if (arr[mid] === key) return mid;
        else if (arr[mid] < key) start = mid + 1;
        else end = mid - 1;
    }

    return -1; // Element not found
};

let arr = [1, 2, 3, 4, 5, 6, 7, 8];
console.log(binarySearch(arr, 7)); 

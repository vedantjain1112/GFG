/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    const newArray = [];
    for (let i = 0; i < arr.length; i++) {
        if (typeof fn === 'function') {
            newArray.push(fn(arr[i], i));
        } else {
            // If the function doesn't take the index, call it with just the element value
            newArray.push(fn(arr[i]));
        }
    }
    return newArray;
};
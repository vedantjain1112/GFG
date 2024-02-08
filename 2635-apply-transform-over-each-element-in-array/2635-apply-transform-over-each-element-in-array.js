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
            newArray.push(fn(arr[i]));
        }
    }
    return newArray;
};
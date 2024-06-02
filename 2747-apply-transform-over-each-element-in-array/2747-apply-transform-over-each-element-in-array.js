/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    var ans = new Array(arr.length);
    
    for(var i=0;i<arr.length;i++){
        ans[i]=fn(arr[i],i);
    }
    
    return ans;
    
};
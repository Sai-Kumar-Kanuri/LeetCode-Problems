/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
    
	return function(x) {
        functions.reduceRight((acc,fn)=>{
            acc=fn(x);
            x=acc;
        },x)
        
        return x;
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */
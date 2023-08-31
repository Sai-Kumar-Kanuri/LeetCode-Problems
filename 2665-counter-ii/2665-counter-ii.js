/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    var num = init;
    const increment =()=>{
        return num=num+1;
    }
    
    const reset = ()=>{
        return num=init;
    }
    
    const decrement = ()=>{
        return num=num-1;
    }
    
    return {increment,reset,decrement};
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */
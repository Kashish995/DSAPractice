/**
 * @param {Function} fn
 * @return {Function}
 */

function memoize(fn) {
    const root = new Map();
    const RESULT = Symbol('result');


    return function(...params) {
         let node = root;

         for(const param of params) {
            if(!node.has(param)) {
                node.set(param, new Map());

            }
            node = node.get(param);
         }
         if(node.has(RESULT)) {
            return node.get(RESULT);
         }
         const answer = fn(...params);
         node.set(RESULT, answer);
         return answer;
    };
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */
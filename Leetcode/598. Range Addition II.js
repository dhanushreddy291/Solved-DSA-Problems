/*
 * @param {number} m
 * @param {number} n
 * @param {number[][]} ops
 * @return {number}
 */
 var maxCount = function(m, n, ops) {
    let X = m, Y = n;
        for (const op of ops) {
            X = Math.min(X, op[0]);
            Y = Math.min(Y, op[1]);
        }
    return X * Y;
};
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isIsomorphic = function (s, t) {
    if (s.length !== t.length) {
        return false;
    }
    let mapST = {};
    let mapTS = {};
    for (let i = 0; i < s.length; i++) {
        if (mapST[s[i]] && mapST[s[i]] !== t[i]) {
            return false;
        }
        if (mapTS[t[i]] && mapTS[t[i]] !== s[i]) {
            return false;
        }

        mapST[s[i]] = t[i];
        mapTS[t[i]] = s[i];
    }
    return true;
};
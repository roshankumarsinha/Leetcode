/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    let newStr = s.trim();
    let regex = /\s+/;
    let words = newStr.split(regex);
    return words.reverse().join(" ");
};
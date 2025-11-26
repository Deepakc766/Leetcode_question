class Solution {
public:

int solve(string &haystack, string &needle, int i, int j, int &target) {
    if(i == needle.length()) {
        target = j - i;
        return target;
    }
    if(j >= haystack.length()) return -1;

    if(needle[i] == haystack[j]) {
        return solve(haystack, needle, i+1, j+1, target);
    } else {
        return -1;
    }
}

int strStr(string haystack, string needle) {
    if(needle.empty()) return 0;

    int target_index = -1;
    int i = 0;
    int j = 0;

    while(j < haystack.length()) {
        if(haystack[j] == needle[0]) {
            int res = solve(haystack, needle, 0, j, target_index);
            if(res != -1) return res;
            j++;
        } else {
            j++;
        }
    }
    return -1;
}
};

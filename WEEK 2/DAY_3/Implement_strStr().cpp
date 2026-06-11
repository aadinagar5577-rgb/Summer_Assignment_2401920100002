class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();
        vector<int> lps(m, 0);
        // Build LPS array
        int len = 0;
        for (int i = 1; i < m; ) {
            if (needle[i] == needle[len]) {
                lps[i] = ++len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        // Search
        int i = 0, j = 0;
        while (i < n) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;

                if (j == m) {
                    return i - m;
                }
            } else {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return -1;
    }
};

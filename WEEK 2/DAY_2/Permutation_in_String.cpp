class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        if (n > m) {
            return false;
        }
        int freq1[26] = {0};
        int freq2[26] = {0};
        // Frequency of s1 and first window of s2
        for (int i = 0; i < n; i++) {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }
        // Check first window
        if (equal(begin(freq1), end(freq1), begin(freq2))) {
            return true;
        }
        // Slide the window
        for (int i = n; i < m; i++) {
            freq2[s2[i] - 'a']++;           // Add new character
            freq2[s2[i - n] - 'a']--;       // Remove old character
            if (equal(begin(freq1), end(freq1), begin(freq2))) {
                return true;
            }
        }
        return false;
    }
};

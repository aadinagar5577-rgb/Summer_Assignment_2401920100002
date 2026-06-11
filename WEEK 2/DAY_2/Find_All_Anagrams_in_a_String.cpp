class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n = s.length();
        int k = p.length();
        if (k > n) {
            return ans;
        }
        int freqP[26] = {0};
        int freqS[26] = {0};
        // Frequency of p and first window
        for (int i = 0; i < k; i++) {
            freqP[p[i] - 'a']++;
            freqS[s[i] - 'a']++;
        }
        // Check first window
        if (equal(begin(freqP), end(freqP), begin(freqS))) {
            ans.push_back(0);
        }
        // Slide the window
        for (int i = k; i < n; i++) {
            freqS[s[i] - 'a']++;         // Add new character
            freqS[s[i - k] - 'a']--;     // Remove old character

            if (equal(begin(freqP), end(freqP), begin(freqS))) {
                ans.push_back(i - k + 1);
            }
        }
        return ans;
    }
};

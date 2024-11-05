class Solution {
public:
    int minChanges(string s) {
        // The idea is to check every two consecutive characters
        // If they are different, we need to change one of them to make them equal
        // For each pair, we need to make the minimum number of changes

        int n = s.length();
        int changes = 0;

        // Process string in pairs of two characters
        for (int i = 0; i < n; i += 2) {
            // If current pair of characters are different
            // we need to make one change to make them equal
            if (s[i] != s[i + 1]) {
                changes++;
            }
        }

        return changes;
    }
};
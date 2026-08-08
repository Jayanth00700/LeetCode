class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
         int n = word1.size(), m = word2.size();
        vector<int> suff(n + 1, 0);
        int j = m - 1;

        for (int i = n - 1; i >= 0; i--) {
            if (j >= 0 && word1[i] == word2[j]) {
                j--;
            }
            suff[i] = m - 1 - j; 
        }

        vector<int> ans;
        int i = 0, k = 0;
        bool usedMismatch = false;

        while (i < n && k < m) {
            if (word1[i] == word2[k]) {
                ans.push_back(i);
                i++, k++;
            }
            else {
                if (!usedMismatch) {
                    int remaining = m - (k + 1);

                    if (suff[i + 1] >= remaining) {
                        usedMismatch = true;
                        ans.push_back(i);
                        i++, k++;
                    } else {
                        i++;
                    }
                } else {
                    i++;
                }
            }
        }

        if (k < m) return {};

        return ans;
    }
};
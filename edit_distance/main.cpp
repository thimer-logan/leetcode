#include <iostream>
#include <vector>

using namespace std;

int minDistance(string word1, string word2) {
    vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));

    for (int i = 0; i <= word1.size(); i++) {
        dp[i][0] = i;
    }

    for (int j = 0; j <= word2.size(); j++) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= word1.size(); i++) {
        for (int j = 1; j <= word2.size(); j++) {
            if (word1[i-1] == word2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                // insert: dp[i][j-1] + 1
                // delete: dp[i-1][j+1] + 1
                // replace: dp[i-1][j-1] + 1
                dp[i][j] = 1 + min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
            }
        }
    }

    return dp[word1.size()][word2.size()];
}

int main() {

    cout << minDistance("horse", "ros") << endl;
    cout << minDistance("intention", "execution") << endl;

    return 0;
}
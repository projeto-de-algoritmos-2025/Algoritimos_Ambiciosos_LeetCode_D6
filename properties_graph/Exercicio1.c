#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
public:
    int candy(std::vector<int>& ratings) {

        int n = ratings.size();

        if (n == 0) {
            return 0;
        }

        std::vector<int> candies(n, 1);

        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        return std::accumulate(candies.begin(), candies.end(), 0);
    }
};
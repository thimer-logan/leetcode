#include <iostream>
#include <vector>
#include <map>

using namespace std;

int shipWithinDays(vector<int>& weights, int days) {
    int minimum_weight = 0;
    int maximum_weight = 0;
    for(std::vector<int>::iterator it = weights.begin(); it != weights.end(); ++it) {
        maximum_weight += *it;

        if (*it > minimum_weight)
            minimum_weight = *it;
    }
    
    int min_days;
    int mid;
    while (maximum_weight != minimum_weight) {
        mid = (maximum_weight + minimum_weight) / 2;

        int i = 1;
        map<int, vector<int>> day_weights;
        int rolling_sum = 0;
        for (std::vector<int>::iterator it = weights.begin(); it != weights.end(); ++it) {
            if (rolling_sum + *it > mid) {
                rolling_sum = 0;
                i++;
            }
            
            day_weights[i].push_back(*it);
            rolling_sum += *it;
            
        }

        if (i > days) {
            minimum_weight = mid + 1;
        }
        else {
            maximum_weight = mid;
        }
            
        
    }

    return minimum_weight;

    
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;
/*
pair<int, int> SumTwo(vector<int>& nums, int k) {
    pair<int, int> twonums;
    unordered_set<int> numset;
    for(auto x : nums) {
        if(numset.find(k-x) != numset.end()) {
            twonums = make_pair(x, k-x);
            break;
        }
        else
            numset.insert(x);
    }
    return twonums;
}
*/

pair<int, int> SumTwo(vector<int>& nums, int k) {
    pair<int, int> twonums;
    sort(nums.begin(), nums.end());
    int i = 0, j = nums.size() - 1;
    while(i < j) {
        if(nums[i] + nums[j] < k)
            i++;
        else if(nums[i] + nums[j] > k)
            j--;
        else {
            twonums = make_pair(nums[i], nums[j]);
            break;
        }
    }
    return twonums;
}
int main() {
    vector<int> nums{10, 15, 3, 7};
    int k = 17;
    pair<int, int> sumtwo = SumTwo(nums, k);
    cout<<sumtwo.first<<" "<<sumtwo.second<<endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main() {
    vector<int> nums{1, 2, 3, 4, 5};
    int n = nums.size(), tailProduct = 1;
    vector<int> product(n);
    product[n-1] = tailProduct;
    for(int i = n-2; i>= 0; i--)
        product[i] = product[i+1]*nums[i+1];
    
    tailProduct = 1;
    for(int i = 1; i < n; i++) {
        product[i] = product[i]*tailProduct;
        tailProduct *= nums[i]; 
    }

    for(auto x : product)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}

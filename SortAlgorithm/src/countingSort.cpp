#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

class Solution {
    #define maxn 100001
    int a[maxn];
public:
    vector<int> sortArray(vector<int>& nums) {
        memset(a, 0, sizeof(a));
        for(const int& i : nums){
            ++a[i+50000];
        }
        int j = 0;
        int count = 0;
        for(int i = 0; i < maxn; ++i){
            count = a[i];
            while(count){
                nums[j++] = i - 50000;
                --count;
            }
        }
        return nums;
    }
};


int main(){
    vector<int> nums = {5, 2, 3, 1, 4, 6, 8, 7, 9, 15, 65, 23, 12, 34, 56, 78, 90, 11, 22, 33};
    Solution s;
    s.sortArray(nums);
    for(auto& num : nums){
        cout << num << " ";
    }
    return 0;
}
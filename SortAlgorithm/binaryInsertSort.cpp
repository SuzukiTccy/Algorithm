#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
void binaryInsertSort(vector<int>& nums){
    int j = 0, l = 0, r = 0, temp = 0, idx = 0;
    for(int i = 1; i < nums.size(); ++i){
        j = i - 1;
        r = j;
        temp = nums[i];
        idx = binarySearch(nums, -1, r + 1, temp);
        while(j >= idx){
            nums[j+1] = nums[j];
            --j;
        }
        nums[idx] = temp;
    }
}

int binarySearch(const vector<int>& nums, int l, int r, const int& k){
    int mid = 0;
    while(l + 1 < r){
        mid = l + ((r-l) >> 1);
        if(nums[mid] >= k) r = mid;
        else l = mid;
    }
    return r;
}

vector<int> sortArray(vector<int>& nums) {
    binaryInsertSort(nums);
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
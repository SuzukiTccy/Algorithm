#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> cnt; // 定义一个全局的辅助数组，用于合并两个有序区间
    // 归并排序函数，对nums数组中[l, r)区间进行排序
    void mergeSort(vector<int>& nums, int l, int r){
        // 给nums数组中，[l,r)区间进行排序
        int mid = 0;
        if(l + 1>= r) return;
        mid = l + (r - l) / 2;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid, r);
        int i = l, j = mid;
        int x = 0;
        while(i < mid && j < r){
            if(nums[i] <= nums[j]) cnt[x++] = nums[i++];
            else cnt[x++] = nums[j++];
        }
        while(i < mid) cnt[x++] = nums[i++];
        while(j < r) cnt[x++] = nums[j++];

        for(i = 0; i < r - l; ++i){
            nums[i+l] = cnt[i];
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        cnt.resize(nums.size(), 0);
        mergeSort(nums, 0, n);  // 这里要注意是n
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
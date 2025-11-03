#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    void bucketSort(vector<int>& nums, int n){
        int maxVal = *max_element(nums.begin(), nums.end());
        int minVal = *min_element(nums.begin(), nums.end());

        int bucketCount = n / 4 > 0 ? n / 4 : 1; //桶的数量，一般取n的1/4，经验值
        vector<vector<int>> buckets(bucketCount);
        for(auto& b : buckets)
            b.reserve(n / bucketCount); //给与分配内存，避免频繁分配内存

        for(int i = 0; i < n; ++i){
            int bucketIndex = bucketCount * ((nums[i] - minVal) / (maxVal - minVal + 1));
            buckets[bucketIndex].push_back(nums[i]);
        }

        int idx = 0;
        for(int i = 0; i < bucketCount; ++i){
            sort(buckets[i].begin(), buckets[i].end());
            for(const int& num : buckets[i])
                nums[idx++] = num;

        }
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        bucketSort(nums, n);
        return nums;

    }
};


int main(){
    vector<int> nums = {5, 2, 3, 1, 4, 6, 8, 7, 9, 15, 65, 23, 12, 34, 56, 78, 90, 11, 22, 33, 33};
    Solution s;
    s.sortArray(nums);
    for(auto& num : nums){
        cout << num << " ";
    }
    return 0;
}
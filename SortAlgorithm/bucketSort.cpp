#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    void bucketSort(vector<int>& nums, int n){
        int maxVal = *max_element(nums.begin(), nums.end());
        int minVal = *min_element(nums.begin(), nums.end());

        int bucketCount = n / 2 > 0 ? n / 2 : 1;
        vector<vector<int>> bucket(bucketCount);
        bucket.reserve(4 * n);

        for(int i = 0; i < n; ++i){
            int bucketIndex = n * ((nums[i] - minVal) / (maxVal - minVal + 1));
            bucket[bucketIndex].push_back(nums[i]);
        }

        int idx = 0;
        for(int i = 0; i < bucketCount; ++i){
            sort(bucket[i].begin(), bucket[i].end());
            for(const int& num : bucket[i])
                nums[idx++] = num;

        }
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        bucketSort(nums, n);
        return nums;

    }
};
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int digit(int num, int exp) {
        return (abs(num) / exp) % 10;
    }

    void countingSortDigit(vector<int>& nums, int exp) {
        // 十进制的位范围为 0~9 ，因此需要长度为 10 的桶
        vector<int> counter(10, 0);
        int n = nums.size();

        // 统计 0~9 各数字的出现次数
        for(int i = 0; i < n; ++i) {
            int d = digit(nums[i], exp);
            ++counter[d];
        }

        // 求前缀和，将“出现个数”转换为“数组索引”
        for (int i = 1; i < 10; i++) {
            counter[i] += counter[i - 1];
        }

        // 倒序遍历，根据桶内统计结果，将各元素填入 res
        vector<int> res(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            int d = digit(nums[i], exp);
            int j = counter[d] - 1;
            res[j] = nums[i];
            counter[d]--;
        }
        
        // 使用结果覆盖原数组 nums
        for (int i = 0; i < n; i++) {
            nums[i] = res[i];
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        vector<int> positives;
        vector<int> negatives;

        for(int num : nums) {
            if(num >= 0) positives.push_back(num);
            else negatives.push_back(-num); // Store negative numbers as positive values for sorting
        }

        int maxPositive = positives.empty() ? 0 : *max_element(positives.begin(), positives.end());
        int maxNegative = negatives.empty() ? 0 : *max_element(negatives.begin(), negatives.end());

        for(int exp = 1; maxPositive / exp > 0; exp *= 10) {
            countingSortDigit(positives, exp);
        }

        for(int exp = 1; maxNegative / exp > 0; exp *= 10) {
            countingSortDigit(negatives, exp);
        }

        reverse(negatives.begin(), negatives.end());

        for(int &num : negatives) {
            num = -num;
        }

        vector<int> result;
        result.insert(result.end(), negatives.begin(), negatives.end());
        result.insert(result.end(), positives.begin(), positives.end());

        return result;
    }
};
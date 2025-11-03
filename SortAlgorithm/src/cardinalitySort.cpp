#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int digit(int n, int exp){
        return (n / exp) % 10;
    }

    void SingleCountingDigit(vector<int>& nums, int exp){
        int counter[10] = {};
        int d = 0;
        for(auto &num : nums){
            d = digit(num, exp);
            ++counter[d];
        }

        for(int i = 0; i < 9; ++i){
            counter[i+1] += counter[i];
        }

        vector<int> res(nums.size(), 0);
        for(int i = nums.size() - 1; i >= 0; --i){
            d = digit(nums[i], exp);
            res[--counter[d]] = nums[i];
        }

        for(int i = 0; i < nums.size(); ++i){
            nums[i] = res[i];
        }
    }

    void CountingDigit(vector<int>& nums){
        vector<int> positives = {};
        vector<int> negatives = {};

        for(auto& num : nums){
            if(num >= 0) positives.emplace_back(num);
            else negatives.emplace_back(-num);
        }

        int maxPositive = positives.empty() ? 0 : *max_element(positives.begin(), positives.end());
        int maxNegative = negatives.empty() ? 0 : *max_element(negatives.begin(), negatives.end());

        int exp = 1;
        for(int i = maxPositive; i > 0; i /= 10){
            SingleCountingDigit(positives, exp);
            exp *= 10;
        }

        exp = 1;
        for(int i = maxNegative; i > 0; i /= 10){
            SingleCountingDigit(negatives, exp);
            exp *= 10;
        }

        reverse(negatives.begin(), negatives.end());

        for(int i = 0; i < negatives.size(); ++i){
            nums[i] = -negatives[i];
        }

        for(int i = 0; i < positives.size(); ++i){
            nums[negatives.size()+i] = positives[i];
        }
    }
};


int main(){
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10 ,-500, -231, 231, 500};
    s.CountingDigit(nums);
    for(auto& num : nums){
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
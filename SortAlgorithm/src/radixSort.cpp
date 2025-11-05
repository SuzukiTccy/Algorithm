#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class radixSort{
public:
    static int counter[10];
    static vector<int> res;

    static int digit(const int& num, const int& exp){
        return (num / exp) % 10;
    }

    static void singleCountingSort(vector<int>& nums, const int& exp){
        memset(counter, 0, sizeof(counter));

        int d = 0;
        for(const int& num : nums){
            d = digit(num, exp);
            ++counter[d];
        }

        for(int i = 0; i < 9; ++i){
            counter[i+1] += counter[i];
        }

        for(int i = nums.size() - 1; i >= 0; --i){
            d = digit(nums[i], exp);
            res[--counter[d]] = nums[i];
        }

        for(int i = 0; i < nums.size(); ++i){
            nums[i] = res[i];
        }
    }

    static void radixsort(vector<int>& nums, bool des = false){

        res.resize(nums.size());
        
        // 分别处理正数和负数
        vector<int> positive = {};
        vector<int> negative = {};

        for(const int& num : nums){
            if(num >= 0) positive.emplace_back(num);
            else negative.emplace_back(-num);
        }

        int max_positive = positive.empty() ? 0 : *max_element(positive.begin(), positive.end());
        int max_negative = negative.empty() ? 0 : *max_element(negative.begin(), negative.end());

        for(int exp = 1; exp <= max_positive; exp *= 10){
            singleCountingSort(positive, exp);
        }

        for(int exp = 1; exp <= max_negative; exp *= 10){
            singleCountingSort(negative, exp);
        }

        int idx = 0;
        for(int i = negative.size() - 1; i >= 0; --i){
            nums[idx] = -negative[i];
            ++idx;
        }
        for(int i = 0; i < positive.size(); ++i){
            nums[idx] = positive[i];
            ++idx;
        }
        
        if(des) reverse(nums.begin(), nums.end());
    }

};

int radixSort::counter[10] = {};
vector<int> radixSort::res = {};



void radixSort_main(){
    vector<int> nums1 = {5, -3, 42, -17, 156, -234, 3892, -4567, 12345, \
        -67890, 100000, -99999, 7, -888, 54321, -1234, 98765, -50000, 0, -1};
    radixSort::radixsort(nums1);
    cout << "排序后的数组（升序）:" << endl;
	for(auto i : nums1) cout << i << " ";
	cout << endl;

    vector<int> nums2 = {5, -3, 42, -17, 156, -234, 3892, -4567, 12345, \
        -67890, 100000, -99999, 7, -888, 54321, -1234, 98765, -50000, 0, -1};
    radixSort::radixsort(nums2, true);
    cout << "排序后的数组（降序）:" << endl;
	for(auto i : nums2) cout << i << " ";
	cout << endl;
}
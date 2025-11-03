#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void shellSort(vector<int>& nums){
        int len = nums.size();
        // 第一层循环: 分间隔
        for(int delta = len / 2; delta > 0; delta /= 2){
            // 第二层循环: 分组
            for(int start = 0; start < len / delta; ++start){
                // 第三层循环: 插入排序
                for(int i = start + delta; i < len; i += delta){
                    int j = i - delta;
                    int temp = nums[i];
                    while(j >= start && nums[j] > temp){
                        nums[j+delta] = nums[j];
                        j -= delta;
                    }
                    nums[j+delta] = temp;
                }
            }
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        shellSort(nums);
        return nums;
    }
};

int main(){
    Solution s;
    vector<int> nums = {5, 2, 3, 1, 4, 6, 8, 7, 9, 15, 65, 23, 12, 34, 56, 78, 90, 11, 22, 33};
    s.sortArray(nums);
    for(auto& num : nums){
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
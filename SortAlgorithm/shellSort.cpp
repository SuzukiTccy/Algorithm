#include<vector>
using namespace std;

class Solution {
public:
    void shellSort(vector<int>& nums){
        int n = nums.size();
        // 第一层循环: 分间隔
        for(int delta = n / 2; delta > 0; delta /= 2){
            // 第二层循环: 分组
            for(int start = 0; start < delta; ++start){
                // 第三层循环: 插入排序
                for(int i = start + delta; i < n; i += delta){
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
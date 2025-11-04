#include<iostream>
#include<vector>
using namespace std;

class countingSort{
/*
    * 计数排序
    * 时间复杂度：O(n+k), k为输入数据的范围
    * 空间复杂度：O(k), k为输入数据的范围
    * 稳定性：不稳定
    * 适用场景：当输入的数据范围不是很大时，可以使用计数排序
    * 默认升序
*/

public:
    static void countingsort(vector<int>& nums, bool des = false){
        if(nums.empty()) return;

        // 确定数组范围
        int min_val = *min_element(nums.begin(), nums.end());
        int max_val = *max_element(nums.begin(), nums.end());
        int range = max_val - min_val + 1;

        // 辅助数组
        vector<int> cnt(range, 0);

        // 计数
        for(const int& num : nums){
            ++cnt[num - min_val];
        }

        // 排序
        int idx = 0;
        for(int i = 0; i < range; ++i){
            while(cnt[i]){
                nums[idx++] = i + min_val;
                --cnt[i];
            }
        }

        if(des) reverse(nums.begin(), nums.end());
    }
};



void countingSort_main(){
    vector<int> nums1 = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 0, 7, 9};
    countingSort::countingsort(nums1);
    cout << "排序后的数组（升序）:" << endl;
	for(auto i : nums1) cout << i << " ";
	cout << endl;

    vector<int> nums2 = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 0, 7, 9};
    countingSort::countingsort(nums2, true);
    cout << "排序后的数组（降序）:" << endl;
	for(auto i : nums2) cout << i << " ";
	cout << endl;

}
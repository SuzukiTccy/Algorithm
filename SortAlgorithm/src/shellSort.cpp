#include<iostream>
#include<vector>
using namespace std;

class shellSort {
public:
    /*
        * 希尔排序
        * 时间复杂度：O(n^2) 跟步长序列相关，最常用的shell序列（2的等比数列），时间复杂度为O(n^2)
        * 空间复杂度：O(1)
        * 稳定性：不稳定
        * 算法思想：希尔排序是对插入排序的一种改进，通过将数组分成多个子序列，然后对每个子序列进行插入排序，最后将整个数组进行插入排序
        * 默认升序
    */

    static void shellsort(vector<int>& nums, bool des = false){
        int len = nums.size();
        // 第一阶段：分间隔delta
        for(int delta = len / 2; delta > 0; delta /= 2){
            // 第二阶段：分间隔
            for(int start = 0; start < delta; ++start){
                // 第三阶段：插入排序
                int temp = 0;
                int j = 0;
                for(int i = start + delta; i < len; i += delta){
                    temp = nums[i];
                    j = i - delta;
                    while(j >= 0 && nums[j] > temp){
                        nums[j+delta] = nums[j];
                        j -= delta;
                    }
                    nums[j+delta] = temp;
                }
            }
        }
        if(des) reverse(nums.begin(), nums.end());
    }
};

void shellSort_main(){
    vector<int> nums1 = {5, 2, 4, 6, 1, 3, 7, 9 ,8 ,11, 10, 5, 0};
    shellSort::shellsort(nums1);
    cout << "排序后的数组（升序）:" << endl;
	for(auto i : nums1) cout << i << " ";
	cout << endl;

    vector<int> nums2 = {5, 2, 4, 6, 1, 3, 7, 9 ,8 ,11, 10, 5, 0};
    shellSort::shellsort(nums2, true);
    cout << "排序后的数组（降序）:" << endl;
	for(auto i : nums2) cout << i << " ";
	cout << endl;
}   
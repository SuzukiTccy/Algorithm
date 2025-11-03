#include<iostream>
#include<vector>
using namespace std;


void selectSort(vector<int>& nums, bool descending = false){
    /*
	* 选择排序
	* 时间复杂度：O(n^2)
	* 空间复杂度：O(1)
	* 稳定性：不稳定
	* 算法思想：每次从待排序的数据元素中选出最小（或最大）的一个元素，存放在序列的起始位置，直到全部待排序的数据元素排完。
	* 默认升序
	*/

	int max_idx = 0;
	for(int i = 0; i < nums.size(); ++i){
		max_idx = 0;
		for(int j = 1; j < nums.size() - i; ++j){
			if(nums[max_idx] < nums[j]){
				max_idx = j;
			}
		}
		if(max_idx != nums.size() - 1 - i) swap(nums[max_idx], nums[nums.size() - 1 - i]);
	}
	if(descending) reverse(nums.begin(), nums.end());

}



void selectSort_main(){
	vector<int> nums1 = {1, 3, 2, 5, 4, 6, 8, 7, 9, 0, 9};
	selectSort(nums1);
	cout << "排序后的数组（升序）:" << endl;
	for(auto i : nums1) cout << i << " ";
	cout << endl;

	vector<int> nums2 = {1, 3, 2, 5, 4, 6, 8, 7, 9, 0, 9};
	selectSort(nums2, true);
	cout << "排序后的数组（降序）:" << endl;
	for(auto i : nums2) cout << i << " ";
	
}
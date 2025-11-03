#include<iostream>
#include<vector>
using namespace std;


void selectSort(vector<int>& nums, bool descending = true){
    /*
	* 选择排序
	* 时间复杂度：O(n^2)
	* 空间复杂度：O(1)
	* 稳定性：不稳定
	* 默认降序
	*/

	int min_idx = 0;
	for(int i = 0; i < nums.size(); ++i){
		min_idx = 0;
		for(int j = 1; j < nums.size() - i; ++j){
			if(nums[min_idx] > nums[j]){
				min_idx = j;
			}
		}
		if(min_idx != nums.size() - 1 - i) swap(nums[min_idx], nums[nums.size() - 1 - i]);
	}
	if(!descending) reverse(nums.begin(), nums.end());

}



void selectSort_main(){
	vector<int> nums1 = {1, 3, 2, 5, 4, 6, 8, 7, 9, 0};
	selectSort(nums1);
	cout << "排序后的数组（降序）:" << endl;
	for(auto i : nums1) cout << i << " ";
	cout << endl;

	vector<int> nums2 = {1, 3, 2, 5, 4, 6, 8, 7, 9, 0};
	selectSort(nums2, false);
	cout << "排序后的数组（升序）:" << endl;
	for(auto i : nums2) cout << i << " ";
	
}
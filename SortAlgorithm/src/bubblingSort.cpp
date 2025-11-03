#include<iostream>
#include<vector>
using namespace std;

void bubblingsort(vector<int> &nums, bool descending = false){
	/*
	* 冒泡排序
	* 时间复杂度：O(n^2)
	* 空间复杂度：O(1)
	* 稳定性：稳定
	* 算法思想：从前往后，相邻元素两两比较，如果前一个元素比后一个元素大，则交换位置，直到整个数组有序
	* 默认升序
	*/
	bool stop_flag = true;
	for(int i = 0; i < nums.size(); ++i){
		stop_flag = true;
		for(int j = 0; j < nums.size() - i - 1; ++j){
			if(nums[j] > nums[j+1]){ // 这里不能用<=, 不然会变的不稳定
				swap(nums[j], nums[j+1]);
				stop_flag = false;
			}
		}
		if(stop_flag) break;
	}
	if(descending){
		reverse(nums.begin(), nums.end()); // 降序转升序
	}
};

void bubblingSort_main(){
	vector<int> nums1 = {1, 3, 2, 5, 4, 6, 7, 8, 9, 10, 0, 4};
	bubblingsort(nums1);
	cout << "排序后的数组（升序）:" << endl;
	for(auto i : nums1){
		cout << i << " ";
	}
	cout << endl;
	
	vector<int> nums2 = {1, 3, 2, 5, 4, 6, 7, 8, 9, 10, 0, 4};
	bubblingsort(nums2, true);
	cout << "排序后的数组（降序）:" << endl;
	for(auto i : nums2){
		cout << i << " ";
	}

}
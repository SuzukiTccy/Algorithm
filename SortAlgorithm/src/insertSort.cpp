#include<iostream>
#include<vector>

using namespace std;

void insertSort(vector<int>& nums, bool descending = false){
	/*
		* 插入排序
		* 时间复杂度：O(n^2)
		* 空间复杂度：O(1)
		* 稳定性：稳定
		* 算法思想：将数组分为已排序和未排序两部分，每次从未排序部分取出一个元素，插入到已排序部分中，直到未排序部分为空
		* 默认升序
	*/
	int temp = 0, j = 0;
	for(int i = 1; i < nums.size(); ++i){
		temp = nums[i];
		j = i - 1;
		while(j >= 0 && nums[j] > temp){
			nums[j+1] = nums[j];
			--j;
		}
		nums[j+1] = temp;
	}
	if(descending) reverse(nums.begin(), nums.end());
}


void insertSort_main(){
	vector<int> nums1 = {1, 3, 2, 5, 4, 7, 6, 8, 9, 10, 8};
	insertSort(nums1);
	cout << "排序后的数组（升序）:" << endl;
	for(auto i : nums1) cout << i << " ";
	cout << endl;

	vector<int> nums2 = {1, 3, 2, 5, 4, 7, 6, 8, 9, 10, 8};
	insertSort(nums2, true);
	cout << "排序后的数组（降序）:" << endl;
	for(auto i : nums2) cout << i << " ";
	cout << endl;
}
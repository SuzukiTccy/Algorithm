#include<iostream>
#include<vector>
using namespace std;


void selectSort(vector<int>& nums){
	int maxv;
	int max_idx = 0;
	for(int i = 0; i < nums.size(); ++i){
		maxv = nums[0];
		max_idx = 0;
		for(int j = 1; j < nums.size() - i; ++j){
			if(maxv < nums[j]){
				max_idx = j;
				maxv = nums[j];
			}
		}
		nums[max_idx] = nums[nums.size()-1-i];
		nums[nums.size()-1-i] = maxv;
	}
}



int main(){
	vector<int> nums = {5, 2, 3, 1, 4, 6, 8, 7, 9, 15, 65, 23, 12, 34, 56, 78, 90, 11, 22, 33};
	selectSort(nums);
	for(auto i : nums){
		cout<<i<<" ";
	}
	cout<<endl;
    return 0;
}
#include<iostream>
#include<vector>

using namespace std;

void insertSort(vector<int>& nums){
	int temp, j;
	for(int i = 0; i < nums.size(); ++i){
		temp = nums[i];
		j = i - 1;
		while(j >= 0 && nums[j] > temp){
			nums[j+1] = nums[j];
			--j;
		}
		nums[j+1] = temp;
	}
}


int main(){
	vector<int> nums = {5, 2, 3, 1, 4, 6, 8, 7, 9, 15, 65, 23, 12, 34, 56, 78, 90, 11, 22, 33};
	insertSort(nums);
	for(auto num : nums){
		cout << num << " ";
	}
	cout << endl;
    return 0;
}
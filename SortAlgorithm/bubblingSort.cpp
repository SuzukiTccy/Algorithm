#include<iostream>
#include<vector>
using namespace std;

void bubblingsort(vector<int> &nums){
	int temp = 0;
	bool exchange = true;
	for(int i = 0; i < nums.size(); ++i){
		if(!exchange) break;
		exchange = false;
		for(int j = 0; j < nums.size() - 1 - i; ++j){
			if(nums[j] > nums[j+1]){
				swap(nums[j], nums[j+1]);
				exchange = true;
			}
		}
	}
}


int main(){
	vector<int> nums = {5, 2, 3, 1, 4, 6, 8, 7, 9, 15, 65, 23, 12, 34, 56, 78, 90, 11, 22, 33};
	bubblingsort(nums);
	for(auto num : nums){
		cout << num << " ";
	}
	cout << endl;
    return 0;
}
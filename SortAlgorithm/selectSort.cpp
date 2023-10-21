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
    return 0;
}
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
				temp = nums[j+1];
				nums[j+1] = nums[j];
				nums[j] = temp;
				exchange = true;
			}
		}
	}
}


int main(){
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

void bubblingsort(vector<int> &arr, bool descending = true){
	/*
	* 冒泡排序
	* 时间复杂度：O(n^2)
	* 空间复杂度：O(1)
	* 稳定性：稳定
	* 默认降序
	*/
	bool stop_flag = true;
	for(int i = 0; i < arr.size(); ++i){
		stop_flag = true;
		for(int j = 0; j < arr.size() - i - 1; ++j){
			if(arr[j] < arr[j+1]){ // 这里不能用<=, 不然会变的不稳定
				swap(arr[j], arr[j+1]);
				stop_flag = false;
			}
		}
		if(stop_flag) break;
	}
	if(!descending){
		reverse(arr.begin(), arr.end()); // 降序转升序
	}
};

void bubblingSort_main(){
	vector<int> arr1 = {1, 3, 2, 5, 4, 6, 7, 8, 9, 10, 0};
	bubblingsort(arr1);
	cout << "排序后的数组（降序）:" << endl;
	for(auto i : arr1){
		cout << i << " ";
	}
	cout << endl;
	
	vector<int> arr2 = {1, 3, 3, 5, 4, 6, 7, 8, 9, 10, 0};
	bubblingsort(arr2, false);
	cout << "排序后的数组（升序）:" << endl;
	for(auto i : arr2){
		cout << i << " ";
	}

}
#include<iostream>
#include<vector>
using namespace std;

class BinaryInsertSort{
public:
    static int binarySearch(const vector<int>& nums, int l, int r, const int& target){
        int mid = 0;
        while(l + 1 < r){
            mid = l + ((r-l) >> 1);
            if(nums[mid] >= target) r = mid;
            else l = mid;
        }
        return r;
    }

    static void binaryInsertSort(vector<int>& nums, bool descending = false){
        int temp = 0;
        int j = 0;
        int mid = 0;
        for(int i = 1; i < nums.size(); ++i){
            temp = nums[i];
            j = i - 1;
            mid = binarySearch(nums, -1, j+1, temp);
            while(j >= mid){
                nums[j+1] = nums[j];
                --j;
            }
            nums[j+1] = temp;
        }
        if(descending) reverse(nums.begin(), nums.end());
    }

};


void binaryInsertSort_main(){
    vector<int> nums1 = {1, 3, 5, 7, 9, 2, 4, 6, 8, 0, 10, 9};
    BinaryInsertSort::binaryInsertSort(nums1);
    cout << "排序后的数组（升序）:" << endl;
	for(auto i : nums1) cout << i << " ";
	cout << endl;

    vector<int> nums2 = {1, 3, 5, 7, 9, 2, 4, 6, 8, 0, 10, 9};
    BinaryInsertSort::binaryInsertSort(nums2, true);
    cout << "排序后的数组（降序）:" << endl;
	for(auto i : nums2) cout << i << " ";
	cout << endl;
}
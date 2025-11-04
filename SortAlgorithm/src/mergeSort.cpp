#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class mergeSort{
/*
    * 归并排序
    * 时间复杂度：O(nlogn)
    * 空间复杂度：O(n)
    * 稳定性：稳定
    * 原理：将数组分成两半，分别进行排序，然后将两个有序数组合并成一个有序数组
    * 默认升序
*/

public:
    vector<int> cnt; // 辅助合并数组

    void mergesort(vector<int>& nums, int l, int r){
        /*
            * 对nums数组的[l, r)区间进行排序
        */
        if (l + 1 >= r) return;
        int mid = l + ((r - l) >> 1);
        mergesort(nums, l, mid);
        mergesort(nums, mid, r);
        merge(nums, l, mid, r);
    }

    void merge(vector<int>& nums, int l, int mid, int r){
        /*
            * 合并nums数组的[l, mid)和[mid, r)两部分
        */
        int k = 0;
        int i = l;
        int j = mid;
        while(i < mid && j < r){
            if(nums[i] < nums[j]) cnt[k++] = nums[i++];
            else cnt[k++] = nums[j++];
        }
        while(i < mid) cnt[k++] = nums[i++];
        while(j < r) cnt[k++] = nums[j++];

        for(k = 0; k < r - l; ++k){
            nums[l+k] = cnt[k];
        }
    }

    void operator()(vector<int>& nums, bool des = false){
        cnt.resize(nums.size());
        mergesort(nums, 0, nums.size());
        if(des) reverse(nums.begin(), nums.end());
    }

};


void mergeSort_main(){
    vector<int> nums1 = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 0, 7, 9};
    mergeSort()(nums1);
    cout << "排序后的数组（升序）:" << endl;
	for(auto i : nums1) cout << i << " ";
	cout << endl;

    vector<int> nums2 = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 0, 7, 9};
    mergeSort()(nums2, true);
    cout << "排序后的数组（降序）:" << endl;
	for(auto i : nums2) cout << i << " ";
	cout << endl;
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<ctime>
#include<random>
using namespace std;

//快速排序
class QuickSort{
/*
    * 快速排序
    * 时间复杂度：O(nlogn)
    * 空间复杂度：O(logn)
    * 稳定性：不稳定
    * 算法思想：选择一个基准元素，将数组分为两部分，一部分小于基准元素，一部分大于基准元素，然后递归地对这两部分进行快速排序
    * 默认升序
*/

public:
    static bool allElementsAreEqual(const vector<int>& nums){
        for(auto num : nums){
            if(num != nums[0]) return false;
        }
        return true;
    }

    static int partition(vector<int>& nums, int l, int r){
        int pivot = rand() % (r - l + 1) + l;
        swap(nums[pivot], nums[r]);
        int i = l, j = l;
        while(j < r){
            if(nums[j] < nums[r]){
                swap(nums[i], nums[j]);
                ++i;
            }
            ++j;
        } 
        swap(nums[i], nums[r]);
        return i;
    }

    static void quickSort(vector<int>& nums, int l, int r){
        if(l >= r) return;
        int pivot = partition(nums, l, r);
        quickSort(nums, l, pivot - 1);
        quickSort(nums, pivot + 1, r);
    }

    static void sort(vector<int>& nums, bool descending = false){
        if(allElementsAreEqual(nums)) return;
        srand(time(0));
        quickSort(nums, 0, nums.size() - 1);

        if(descending) reverse(nums.begin(), nums.end());
    }
};


void quickSort_main(){
    vector<int> nums1 = {3, 2, 1, 5, 4, 6, 11, 0, 4, 3};
    QuickSort().sort(nums1);
    cout << "排序后的数组（升序）:" << endl;
	for(auto i : nums1) cout << i << " ";
	cout << endl;

    vector<int> nums2 = {3, 2, 1, 5, 4, 6, 11, 0, 4, 3};
    QuickSort().sort(nums2, true);
    cout << "排序后的数组（降序）:" << endl;
	for(auto i : nums2) cout << i << " ";
	cout << endl;
}







#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class maxHeapSort{
/*
    * 最大堆排序
    * 时间复杂度：O(nlogn)
    * 空间复杂度：O(1)
    * 稳定性：不稳定
    * 算法思想：将待排序序列构造成一个大顶堆。此时，整个序列的最大值就是堆顶的根节点
    * 将它移走（其实就是将其与堆数组的末尾元素交换，此时末尾元素就是最大值），然后将剩余的n-1个序列重新构造成一个堆
    * 这样就会得到n个元素的次小值。如此反复执行，便能得到一个有序序列了
    * 升序
*/

public:
    // 下滤，时间复杂度为O(logn)
    static void heapDown(vector<int>& nums, const int& root, const int& heapsize){
        int l = 2*root + 1;
        int r = 2*root + 2;
        int largest = root;

        if(l < heapsize && nums[l] > nums[largest]){
            largest = l;
        }
        if(r < heapsize && nums[r] > nums[largest]){
            largest = r;
        }
        
        if(largest != root){
            swap(nums[root], nums[largest]);
            heapDown(nums, largest, heapsize);
        }
    }

    // 自下而上建堆，时间复杂度为O(nlogn)
    static void buildHeap(vector<int>& nums){
        for(int i = nums.size() / 2; i >= 0; --i){
            heapDown(nums, i, nums.size());
        }
    }

    // 大根堆排序
    static void maxheapsort(vector<int>& nums, bool des = false){
        int heapsize = nums.size();
        buildHeap(nums);
        for(int i = 0; i < nums.size(); ++i){
            swap(nums[0], nums[--heapsize]);
            heapDown(nums, 0, heapsize);
        }
        if(des) reverse(nums.begin(), nums.end());
    }
};



void maxHeapSort_main(){
    vector<int> nums1 = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, -2, -10};
    maxHeapSort::maxheapsort(nums1);
    cout << "排序后的数组（升序）:" << endl;
	for(auto i : nums1) cout << i << " ";
	cout << endl;

    vector<int> nums2 = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, -2, -10};
    maxHeapSort::maxheapsort(nums2, true);
    cout << "排序后的数组（降序）:" << endl;
	for(auto i : nums2) cout << i << " ";
	cout << endl;
}
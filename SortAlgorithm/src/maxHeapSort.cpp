#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    void maxHeapify(vector<int>& nums, int i, int heapsize){
        int l = 2*i + 1;
        int r = 2*i + 2;
        int largest = i;
        if (l < heapsize && nums[l] > nums[largest]){
            largest = l;
        }
        if (r < heapsize && nums[r] > nums[largest]){
            largest = r;
        }

        if (largest != i){
            swap(nums[i], nums[largest]);
            maxHeapify(nums, largest, heapsize);
        }
    }

    void buildmaxHeap(vector<int>& nums, int heapsize){
        for(int i = heapsize / 2; i >= 0; --i){
            maxHeapify(nums, i, heapsize);
        }
    }

    void heapSort(vector<int>& nums){
        int heapsize = nums.size();
        buildmaxHeap(nums, heapsize);
        for(int i = 0; i < nums.size() - 1; ++i){
            swap(nums[0], nums[heapsize-1]);
            --heapsize;
            maxHeapify(nums, 0, heapsize);
        }
    }
};

int main(){
    vector<int> nums = {5, 2, 3, 1, 4, 6, 8, 7, 9, 15, 65, 23, 12, 34, 56, 78, 90, 11, 22, 33, 33};
    Solution s;
    s.heapSort(nums);
    for(auto& num : nums){
        cout << num << " ";
    }
    return 0;
}
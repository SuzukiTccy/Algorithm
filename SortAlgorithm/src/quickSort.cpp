#include<iostream>
#include<random>
#include<algorithm>
#include<ctime>
#include<vector>

using namespace std;

class Solution {
public:
    bool allElementsAreSame(const vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[0]) return false;
        }
        return true;
    }


    void quickSort(vector<int>& nums, int l, int r){
        if (l >= r) return;
        int pivot = partition(nums, l, r);
        quickSort(nums, l, pivot-1);
        quickSort(nums, pivot+1, r);
    }

    int partition(vector<int>& nums, int l, int r){
        int pivot = rand() % (r-l+1) + l;
        swap(nums[pivot], nums[r]);
        int i = l, j = l;
        while(j < r){
            if(nums[j] <= nums[r]){
                swap(nums[i], nums[j]);
                ++i;
            }
            ++j;
        }
        swap(nums[i], nums[r]);
        return i;
    }

    vector<int> sortArray(vector<int>& nums) {
        if(allElementsAreSame(nums)) return nums;
        srand((unsigned)time(NULL));
        quickSort(nums, 0, nums.size()-1);
        return nums;
    }
};

int main(){
    vector<int> nums = {5, 2, 3, 1, 4, 6, 8, 7, 9, 15, 65, 23, 12, 34, 56, 78, 90, 11, 22, 33};
    Solution s;
    s.quickSort(nums, 0, nums.size()-1);
    for(auto i:nums){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}










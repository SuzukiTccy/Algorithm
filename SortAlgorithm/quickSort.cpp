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
        randomized_partition(nums, l, r);
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

    void randomized_partition(vector<int>& nums, int l, int r){
        int pivot = rand() % (r-l+1) + l;
        swap(nums[pivot], nums[r]);
    }

    vector<int> sortArray(vector<int>& nums) {
        if(allElementsAreSame(nums)) return nums;
        srand((unsigned)time(NULL));
        quickSort(nums, 0, nums.size()-1);
        return nums;
    }
};

int main(){
    return 0;
}










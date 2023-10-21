#include<algorithm>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
void binaryInsertSort(vector<int>& nums){
        int j, l, r, temp;
       for(int i = 1; i < nums.size(); ++i){
           j = i - 1;
           r = j;
           temp = nums[i];
           int idx = binarySearch(nums, 0, r, temp);
           while(j >= idx){
               nums[j+1] = nums[j];
               --j;
           }
           nums[idx] = temp;
       } 
    }

    int binarySearch(const vector<int>& nums, int l, int r, const int& k){
        int mid;
        while(l <= r){
            mid = l + ((r-l) >> 1);
            if(nums[mid] >= k){
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return l;
    }

    vector<int> sortArray(vector<int>& nums) {
        binaryInsertSort(nums);
        return nums;
    }
};
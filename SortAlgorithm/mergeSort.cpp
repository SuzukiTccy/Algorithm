#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> cnt;
    void mergeSort(vector<int>& nums, int l, int r){
        if(l >= r) return;
        int mid = l + (r - l)/2;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);
        int i = l, j = mid + 1;
        int x = 0;
        while(i <= mid && j <= r){
            if(nums[i] <= nums[j]){
                cnt[x++] = nums[i++];
            }else cnt[x++] = nums[j++];
        }
        while(i <= mid){
            cnt[x++] = nums[i++];
        }
        while(j <= r){
            cnt[x++] = nums[j++];
        }
        for(int i = 0; i < r - l + 1; ++i){
            nums[l+i] = cnt[i];
        }

    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        cnt.resize(nums.size(), 0);
        mergeSort(nums, 0, n-1);  // 这里要注意是n-1
        return nums;
    }
};
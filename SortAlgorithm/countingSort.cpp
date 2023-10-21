#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

class Solution {
    #define maxn 100001
    int a[maxn];
public:
    vector<int> sortArray(vector<int>& nums) {
        memset(a, 0, sizeof(a));
        for(const int& i : nums){
            ++a[i+50000];
        }
        int j = 0;
        for(int i = 0; i < maxn; ++i){
            int count = a[i];
            while(count){
                nums[j++] = i - 50000;
                --count;
            }
        }

        return nums;
    }
};
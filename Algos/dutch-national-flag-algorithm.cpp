#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    void sortColors(vector<int>& nums) {
        int lo = 0, mid = 0, hi = nums.size()-1;
        while(mid <= hi)
        {
            int x = nums[mid];
            if(x == 0)
            {
                swap(nums[lo], nums[mid]);
                lo++;mid++;
            }
            else if (x == 1)
            {
                mid++;
            }
            else if (x == 2)
            {
                swap(nums[mid], nums[hi]);
                hi--;
            }
        }
    }
};

int main()
{
    vector<int> v {2,0,2,1,0,2,1,0};
    Solution().sortColors(v);
    for(auto i : v)
    {
        cout<<i<<" ";
    }
}
//  https://leetcode.com/problems/trapping-rain-water/
//  https://www.geeksforgeeks.org/trapping-rain-water/
//  https://www.youtube.com/watch?v=HmBbcDiJapY

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int> h) {
        int sum = 0;
        for(int i = 0; i < h.size();i++)
        {
            int leftMax = h[i];
            int rightMax = h[i];
            int j = i;
            for(j=i;j>=0;j--)
            {
                //find left max from current index until you reach leftmost element
                if(h[j] >= leftMax)
                {
                    leftMax = h[j];
                }
            }
            int k = i;
            for(k=i;k<h.size();k++)
            {
                //find right max here until you reach rightmost element
                if(h[k] >= rightMax)
                {
                    rightMax = h[k];
                }
            }
            //here we will have leftMax and Rightmax, so take min of them 
            //min is taken because that will be responsible for maximum water to be stored, anything more than that will overflow
            //so we take min(leftMax, rightMax)
            //and that will be our overflowValue and add sum += overflowValue - current cell's height;
            //and we have to do this for each and every cell element of the array
            int overflowValue = min(leftMax, rightMax);
            sum += overflowValue - h[i];
                
        }
        return sum;
    }
};

int main()
{
    vector<int> v{0,1,0,2,1,0,3,2,1,2,1};
    Solution *s = new Solution;
    cout << s->trap(v);
}

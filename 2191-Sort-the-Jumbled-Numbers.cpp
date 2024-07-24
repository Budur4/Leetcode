#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int numsLen = nums.size();
        vector<pair<int, int>> newOldNumMp(numsLen);
        
        for(int indx = 0; indx < numsLen; indx++){
            int oldNum = nums[indx];
            int newNum = getNewNum(oldNum, mapping);
            newOldNumMp[indx] = {newNum, oldNum};
        }
        
        sort(newOldNumMp.begin(), newOldNumMp.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.first < b.first;
        });
        
        for(int indx = 0; indx < numsLen; indx++){
            nums[indx] = newOldNumMp[indx].second;
        }
        
        return nums;
    }
    
    int getNewNum(int oldNum, vector<int>& mapping) {
        if(oldNum == 0) return mapping[0];
        
        int newNum = 0, mul = 1;
        while(oldNum > 0){
            int dig = oldNum % 10;
            newNum = newNum + mapping[dig] * mul;
            mul *= 10;
            oldNum /= 10;
        }       
        return newNum;
    }
};

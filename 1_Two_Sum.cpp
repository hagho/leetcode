#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;
        for(int i = 0; i < nums.size(); i++) {
            int res = target - nums[i];
            unordered_map<int, int>::iterator itor = hashtable.find(res);
            if(itor != hashtable.end()) {
                return vector<int>({itor->second, i});
            }
            hashtable[nums[i]] = i;
        }
    }
};
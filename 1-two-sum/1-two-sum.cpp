class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int,int> mpp;
        
        for(int i=0;i<nums.size();i++){
            if(mpp.find(target-nums[i])!=mpp.end()){
                result.push_back(mpp[target-nums[i]]);
                result.push_back(i);
                return result;
            }
            mpp[nums[i]]=i;
        }
        return result;
    }
};
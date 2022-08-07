class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int count[201]={};
        int result=0;
        for(auto n:nums){
            if(n>=2*diff){
                result+= count[n-diff]&&count[n-(2*diff)];
            }
            count[n]=true;
        }
        return result;
    }
};
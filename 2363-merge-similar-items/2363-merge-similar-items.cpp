class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
       map<int,int> mpp;
        for(auto i:items1){
            mpp[i[0]]+=i[1];
        }
        for(auto i:items2){
            mpp[i[0]]+=i[1];
        }
        vector<vector<int>> result;
        for(auto i:mpp){
            result.push_back({i.first,i.second});
        }
            return result;
    }
};
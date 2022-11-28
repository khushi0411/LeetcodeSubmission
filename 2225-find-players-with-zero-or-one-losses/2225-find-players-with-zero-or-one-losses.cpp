class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        vector<vector<int>> ans;
         vector<int> a,b;
        map<int,int> mp;
        for(auto i:matches){
            mp[i[0]]+=0;
            mp[i[1]]-=1;
        }
        for(auto i:mp){
            if(i.second==0)a.push_back(i.first);
            else if(i.second==-1)b.push_back(i.first);
        }
        ans.push_back(a);
        ans.push_back(b);
        return ans;
        
    }
};
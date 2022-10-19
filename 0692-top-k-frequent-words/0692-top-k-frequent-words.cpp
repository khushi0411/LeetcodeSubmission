class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        // approach using map - nlogn
        /*here, what we have to do is print the top k freq strings 
        for this what we can do is  first store the freq in map and
        then make a vector of pair to compare and sort them and at last just take out the 
        top k freq words.
        */
        
        
        // store freq in map
       unordered_map<string, int> mp;
        for(string& word: words){
            mp[word]++;
        }
        // making a vector to store the pair like ({i, 2}, {love, 2});
        
        vector<pair<string,int>> vec;
        for(auto &it: mp){
            vec.push_back({it.first, it.second}); // push the words and freq in vector to comapre
            
        }
        
        // comp to compare and sort them
        auto comp = [](pair<string, int>&a, pair<string,int>&b){
            if(a.second == b.second)
                return a.first < b.first;
            
            return a.second> b.second;
            
        };
        
        // sorting--
        
        sort(vec.begin(),vec.end(), comp);
        
        // getting the first k freq words--
        
        int i = 0;
        vector<string> res(k);
        while(i < k){
            res[i] = vec[i].first;
            i++;
        }
        
        return res;
        
    }
};
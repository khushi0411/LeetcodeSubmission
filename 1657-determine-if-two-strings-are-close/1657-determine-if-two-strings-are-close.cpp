class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
         map<char,int> m1;
        map<char,int> m2;
        if(word1.size()!=word2.size()) return false;

        for(int i=0;i<word1.size();i++)
        {
            m1[word1[i]]++;
        }
        
        for(int i=0;i<word2.size();i++)
        {
            m2[word2[i]]++;
        }
        for(int i=0;i<word1.size();i++)
        {
            if(m2[word1[i]]==0)
            {
                return false;
            }
        }
        for(int i=0;i<word2.size();i++)
        {
            if(m1[word2[i]]==0)
            {
                return false;
            }
        }

        vector<int> v1;
        vector<int> v2;
        
        for(auto i : m1)
        {
            v1.push_back(i.second);
        }
      
        
        for(auto i : m2)
        {
            v2.push_back(i.second);
        }
        sort(v1.begin(),v1.end());
        
        sort(v2.begin(),v2.end());

        if(v1==v2) return true;
        else return false;
        
    }
};
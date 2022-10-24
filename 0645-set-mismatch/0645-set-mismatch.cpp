class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        int n = nums.size();
        vector<char>freq(n+1);
        for(int num: nums)
            ++freq[num];
        
        int dup = -1;
        int mis = -1;
        for(int i =1;i <=n;i++)
        {
            if(freq[i] == 2)
            {
                dup = i;
            }
                
        
         else if(freq[i] == 0)
           {
                mis = i;
            }
        
        }
 
        return {dup,mis};
        
    }
};
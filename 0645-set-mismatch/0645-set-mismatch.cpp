class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        int n = nums.size(); 
        // size of vector
        vector<char>freq(n+1);
        // to store the freq/count of the number 
        // and we are stroring it in vector bcoz we want to return the ans in vector.
        for(int num: nums)
            // count the freq of nums
            ++freq[num];
        
        int dup = -1;
        // initialize duplicate
        int mis = -1;
        // initiliaze missing no
        for(int i =1;i <=n;i++)
            // triversing whole vector 
        {
            if(freq[i] == 2)  
                // if count ==2 then it represent that it is repeatedly present in vector that is duplicate
            {
                dup = i;
            }
                
        // if count==0 then it is not present in vector , hence this no. is missing no.
         else if(freq[i] == 0)
           {
                mis = i;
            }
        
        }
 // return the vector of duplicate and missing
        return {dup,mis};
        
    }
};
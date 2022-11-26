class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        int n = startTime.size();
        
        // arr[i] will store {ith end_time, ith start_time, ith profitt}
        
        vector<vector<int>> arr(n);
        
        // fill the arr
        
        for(int i = 0; i < n; i++)
        {
            int start = startTime[i];
            
            int end = endTime[i];
            
            int profitt = profit[i];
            
            arr[i] = {end, start, profitt};
        }
        
        // sort the array in ascending order of end time
        
        sort(arr.begin(), arr.end());
        
        // dp[i] will store the maximum profit till ith
        
        vector<int> dp(n, 0);
        
        // base case, if there is only one scheduling
        
        dp[0] = arr[0][2];
        
        // start filling dp from 1st index
        
        // at every index we have to option either we include in our result of exclude, and take maximum of include and exclude
        
        for(int i = 1; i < n; i++)
        {
            // inclusion part if we include the current job 
            
            int include = arr[i][2];
            
            // apply binary search and find the largest index in arr at which we get end_time smaller than or equal to the current start time
            
            int low = 0;
            
            int high = n - 1;
            
            int last_idx = -1;
            
            while(low <= high)
            {
                int mid = low + (high - low) / 2;
                
                // if end time is less than current start time
                
                if(arr[mid][0] <= arr[i][1])
                {
                    last_idx = mid;
                    
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
            
            // update the include
            
            if(last_idx != -1)
            {
                include += dp[last_idx];
            }
            
            // exclusion part
            
            int exclude = dp[i - 1];
            
            // take the maximum of inclusion and exclusion
            
            dp[i] = max(include, exclude);
        }
        
        return dp[n - 1];
    }
};
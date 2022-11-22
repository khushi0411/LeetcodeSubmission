class Solution {
public:
    int memodp(int n,vector<int> &dp){
	//we have to pass the vector by reference otherwise it gives TLE because it use different memory at every call stack.
        if(n==0){
           dp[0]=0;
           return 0;
       } 
        if(dp[n]!=-1){
            return dp[n];
        }
        int minvalue=INT_MAX;
        for(int i=1;i*i<=n;i++){
            int minperfectsquarepro=memodp(n-i*i,dp);
            minvalue=min(minvalue,minperfectsquarepro+1);
        }
        // minvalue+=1;
        dp[n]=minvalue;
    return minvalue;  
    }
    int numSquares(int n) {
       vector<int>dp(n+1,-1);
        return memodp(n,dp);
    }
};
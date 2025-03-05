class Solution {
  public:
  
      int dp[35];
      int fibo(int n){
          if(n < 2) return n;
  
          if(dp[n] != -1) return dp[n];
          dp[n] = fibo(n-1) + fibo(n-2);
          return dp[n]; 
      }
  
      int fib(int n){
          memset(dp,-1,sizeof(dp));
          int ans = fibo(n);
          return ans;
      }
  
      
  };

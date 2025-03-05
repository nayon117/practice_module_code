class Solution {
  public:
  
      int dp[40];
  
      int fibo(int n){
          if(n == 0) return 0;
          if(n==1 || n==2) return 1;
          if(dp[n] != -1) return dp[n];
          dp[n] = fibo(n-1) + fibo(n-2) + fibo(n-3) ;
          return dp[n];
      }
  
      int tribonacci(int n) {
          memset(dp,-1,sizeof(dp));
          int ans = fibo(n);
          return ans;
      }
  };

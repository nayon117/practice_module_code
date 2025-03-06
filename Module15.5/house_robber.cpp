class Solution {
  public:
      int dp[105];
  
      int robbing(int i, vector<int>& nums) {
          if (i >= nums.size())
              return 0;
          if (dp[i] != -1)
              return dp[i];
  
          dp[i] = max(robbing(i+1, nums),robbing(i+2, nums) + nums[i]);
          return dp[i];
      }
  
      int rob(vector<int>& nums) {
          memset(dp, -1, sizeof(dp));
          return robbing(0,nums);
      }
  };
  
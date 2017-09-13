//1.动态规划解法
class Solution { 
    public: 
    int uniquePaths(int m, int n) { 
        int dp[m][n]; 
        for (int i = 0; i < m; i++) { 
            dp[i][0] = 1; 
        } 
        for (int j = 0; j < n; j++) { 
            dp[0][j] = 1; 
        } 
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) { 
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        } 
        return dp[m-1][n-1];
    } 
};
//２ 动态规划 , 空间复杂度由O(m*n)变化为O(min(m,n));  
class Solution {  
public:  
    int uniquePaths(int m, int n) {  
        int s=(m<n)?m:n;  
        int l=(m>n)?m:n;  
        int * arr= new int [s];  
        for(int j=0;j<s;j++)  
            arr[j]=1;  
        for(int i=1;i<l;i++){  
            for(int j=1;j<s;j++){  
                arr[j]+=arr[j-1];  
            }  
        }  
        return arr[s-1];  
    }  
};
//3.排列组合解法
class Solution {
public:
    // 一共走（m-1）+（n-1）步, 从其中选择m-1步向下
    // 所以总的走法是C(m+n-2, m-1)
    int uniquePaths(int m, int n) {
        m--; n--;
        long long mn = m + n;
        long long mn_max = max(m, n);
        long long mn_min = min(m, n);
        long long c = 1;
        for (int i = mn_max + 1; i <= mn; i++) {
            c *= i;
        }
        for (int j = 2; j <= mn_min; j++) {
            c /= j;
        }
        return c;
    }
};

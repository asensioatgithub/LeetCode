//贪心算法
class Solution {
public:
    int jump(int A[], int n) {
        int maxx=0,temp=0,num=0;
        for(int i=0;i<n;)
        {
            if(temp>=n-1)break;
            while(i<=temp)
            {
                maxx=max(maxx,i+A[i]);
                ++i;
            }
            num++;
            temp=maxx;            
        }
        return num;
        
    }
};
//动态规划
int jump(int A[], int n) {
    if(n < 2)
        return 0;
    int H[n];
    memset(H, 0, sizeof(H));
    
    H[0] = 0;
    for(int i=0;i<n-1;i++)
    {
        int m = A[i];
        if(i + m >= n-1)
            return H[i] + 1;
        
        for(int j=1;j<=m;j++)
        {
            if(H[i+j] == 0 || H[i+j] > H[i] + 1)
                H[i+j] = H[i] + 1;
        }
    }
    return H[n-1];
}

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*DFS  
我们遍历矩阵的每一个点，对每个点都尝试进行一次深度优先搜索，如果搜索到1，就继续向它的四周搜索。
同时我们每找到一个1，就将其标为0，这样就能把整个岛屿变成0。
我们只要记录对矩阵遍历时能进入多少次搜索，就代表有多少个岛屿。
*/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for(int i = 0; i < grid.size();i++)
            for(int j =0 ; j<grid[0].size();j++){
                if(grid[i][j] == '1'){
                    searchislands(grid, i, j);
                    res++;       
                }
            }
        return res;
    }

    void searchislands(vector<vector<char>>&grid, int i, int j){
        grid[i][j] = '0';
        // 搜索该点连通的上下左右
        if(i>0 && grid[i-1][j]=='1') searchislands(grid, i-1, j);
        if(j>0 && grid[i][j-1]=='1') searchislands(grid, i, j-1);
        if(i<grid.size()-1 && grid[i+1][j]=='1') searchislands(grid, i+1, j);
        if(j<grid[0].size()-1 && grid[i][j+1]=='1') searchislands(grid, i, j+1);
    }
};


/*
BFS
*/

class Solution {
public:

    int numIslands(vector<vector<char>>& grid) {
        
        if(grid.empty() || grid[0].empty())
            return 0;
        int n=grid.size();
        int m=grid[0].size();
        
        int i,j,sum;
        sum=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    sum++;
                    bfs(i,j,grid,n,m);
                }
            }
        }
        return sum;
    }
    
    
    void bfs(int x,int y,vector<vector<char>> &grid,int n,int m)
    {
        queue<int> q;
        q.push(x*m+y);
        grid[x][y]='0';
        while(!q.empty())
        {
            int cur=q.front();
            q.pop();
            int xx=cur/m;
            int yy=cur%m;
            
            if(xx+1<n&&grid[xx+1][yy]=='1')
            {
                q.push((xx+1)*m+yy);
                grid[xx+1][yy]='0';
            }
            if(xx-1>=0&&grid[xx-1][yy]=='1')
            {
                q.push((xx-1)*m+yy);
                grid[xx-1][yy]='0';
            }
            if(yy+1<m&&grid[xx][yy+1]=='1')
            {
                q.push(xx*m+yy+1);
                grid[xx][yy+1]='0';
            }
             if(yy-1>=0&&grid[xx][yy-1]=='1')
            {
                q.push(xx*m+yy-1);
                grid[xx][yy-1]='0';
            }
        }
    }
};
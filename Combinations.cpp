class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> path;
        DFS(1,k,n,0,result,path);
        return result;
    }
private:
    //start:开始的数；cur:已经选择的数
    void DFS(int start,int k,int n,int cur,vector<vector<int>> &result,vector<int> &path){
        if(cur==k){
            result.push_back(path);
            return;
        }
        for(int i=start;i<=n;i++){
            path.push_back(i);
            DFS(i+1,k,n,cur+1,result,path);
            path.pop_back();
        }
    }
};

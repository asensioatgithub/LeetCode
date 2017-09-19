class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        vector<int> path;
        DFS(nums,result,path);
        return result;
    }
private:
    void DFS(vector<int> &nums,vector<vector<int>> &result,vector<int> &path){
        if(path.size()==nums.size()){
            result.push_back(path);
            return;
        }
        for(auto i:nums){//这里不像binary tree一样，dfs左右子树就行。这里是要dfs所有的子节点
            auto pos=find(path.begin(),path.end(),i);
            if(pos==path.end()){
                path.push_back(i);
                DFS(nums,result,path);
                path.pop_back();
            }
        }
    }
};

#include<iostream>
#include<string>
#include<vector>
#include<stdlib.h>
using namespace std;
class Solution {
public:
    const vector<string> keyboard{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<vector<char>> letterCombinations(string digits) {
        vector<vector<char>> result;
        vector<char> path;
        if(digits.empty()) return vector<vector<char>>();
        DFS(digits,result,0,path);
        return result;
    }
private:
    void DFS(string digits,vector<vector<char>> &result,int cur,vector<char> path){
        if(cur==digits.size()){
            result.push_back(path);
            return;
        }
        
        for(auto c:keyboard[digits[cur]-'0']){
        	  path.push_back(c);
            DFS(digits,result,cur+1,path);
            path.pop_back();
        }
    }
};
int main(){
	Solution s;
	vector<vector<char>> result=s.letterCombinations("23");
	vector<vector<char>>::iterator item1 = result.begin();
	while(item1!=result.end()){
	  vector<char>::iterator item2 = (*item1).begin();
	  while(item2!=((*item1).end())){
	  	cout<<*item2;
	  	item2++;
	  }
	  cout<<endl;
	  item1++;
	}
}

/*
class Solution {
public:
    const vector<string> keyboard{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.empty()) return vector<string>();
        DFS(digits,result,0,"");
        return result;
    }
private:
    void DFS(string digits,vector<string> &result,int cur,string path){
        if(cur==digits.size()){
            result.push_back(path);
            return;
        }
        for(auto c:keyboard[digits[cur]-'0']){
            DFS(digits,result,cur+1,path+c);
        }
    }
};
*/

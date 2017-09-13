class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ASCII_MAX=128;
        int start=0;//记录当前子串的起始位置
        int last[ASCII_MAX];//记录字符上次出现过的位置
        fill(last,last+ASCII_MAX,-1);//0也是位置，因此初始化为１
        int maxlen=0;
        for(int i=0;i<s.size();i++){
            if(last[s[i]]>=start){
                maxlen=max(i-start,maxlen);
                start=last[s[i]]+1;
            }
            last[s[i]]=i;
        }
        return max((int)s.size()-start,maxlen);//start之后到字符串结束都没有重复字符
    }
};

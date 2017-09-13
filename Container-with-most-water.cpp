class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int area=0;
        int result=0;
        while(right>left){
            area=min(height[left],height[right])*(right-left);
            result=max(result,area);
            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return result;
    }
};

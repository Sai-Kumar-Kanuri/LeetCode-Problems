class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        list<int>ls(nums.begin(),nums.end());
        
        while(k--){
            int temp = ls.back();
            ls.pop_back();
            ls.push_front(temp);
        }
        
        vector<int>temp(ls.begin(),ls.end());
        
        nums=temp;
        
    }
};
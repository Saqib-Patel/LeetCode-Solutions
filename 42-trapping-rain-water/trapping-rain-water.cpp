class Solution {
public:
    void prevGreat(vector<int> height, vector<int> &parr){
        int min_ele = -1;
        for (int i = 0 ; i < height.size(); i++){
            parr.push_back(min_ele);
            if (min_ele<height[i]) min_ele=height[i];
        }
    }

    void nextGreat(vector<int> height, vector<int> &narr){
        int min_ele = -1;
        narr.resize(height.size());
        for (int i = height.size()-1 ; i > 0; i--){
            narr[i] = min_ele;
            if (min_ele<height[i]) min_ele=height[i];
        }
    }

    int calTrap (vector<int> height, vector<int> parr, vector<int> narr) {
        int count = 0;
        int min_ele;
        for(int i = 1; i<height.size()-1;i++){
            min_ele = min(parr[i], narr[i]);
            if (min_ele > height[i]) count += min_ele - height[i];
        }
        return count;
    }

    int trap(vector<int>& height) {
        vector<int> arr1;
        vector<int> arr2;
        prevGreat(height,arr1);
        nextGreat(height, arr2);
        return calTrap(height, arr1, arr2);
    }
};
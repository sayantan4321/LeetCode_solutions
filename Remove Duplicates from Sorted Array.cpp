-------------Approach - 1--------------------
We can use two pointer technique to retrive the unique elements of the array.

Suppose Array name is arr[].

First we need to initialize i = 0.
Then we will iterate from 1 to size of the array
if any time arr[j] != arr[i] which means if we get a unique elements we will instantly put an element in the i+1 index of the array.
we will increase the value i by 1 i++ in this way we will iterate the whole array and find out the unique element
and the rest of elements will remain the same as it is
Complexity:

T.C. -> O(N)
S.C. -> O(1)    

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int n= nums.size();
        for(int j=1; j<n; j++){
            if(nums[j]!= nums[i]){
                nums[i+1]=nums[j];
                i++;
            }
        }
        return i+1;
    }
};


------------------Approach - 2 ---------------------

Using Set:

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<int, greater<int>> ans;
        
        for(int i=0;i<nums.size();i++){
            ans.insert(nums[i]);
        }

        for(auto i : ans){
            nums.insert(nums.begin(),i);
        }

        return ans.size();
    
    }
};

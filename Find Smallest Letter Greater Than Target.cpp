//Approach-1 (Brute Force) - TC : O(n)

Traverse through every element.

//Approach-2 (Using Own Binary Search) - TC : O(log(n))
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int ans=-1, low = 0, high = letters.size()-1;

        while(low <= high){
            int mid = (low+high)/2;

            if(letters[mid] > target){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans > -1 ? letters[ans] : letters[0];
    }
};
//Approach-3 (Using C++ STL upper_bound (binary search internally)) - TC : O(log(n))
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int idx = upper_bound(begin(letters), end(letters), target) - begin(letters);
        
        if(idx == letters.size())
            return letters[0];
        
        return letters[idx];
    }
};

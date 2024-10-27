/*
Intuition
We need to find the pair of x and y such that x + y is odd

Approach
As we need to choose x and y such that x + y is odd

Hence if x is odd , then we need to find out possible values of y which are even so that x + y is odd.
So number of possible value of x which are odd and <= n and number of possible value of y which are even and <= m will lead to a part of answer

2 ) if x is even , then we need to find out possible values of y which are odd so that x + y is odd.

So number of possible value of x which are even and <= n and number of possible value of y which are odd and <= m will lead to another part of answer

So the final Answer will be

countOfOddX * countOfEvenY + countOfEvenX * countOfOddY

Complexity
Time complexity:O(1)
Space complexity:O(1)
*/


class Solution {
public:
    long long flowerGame(int n, int m) {
        long long evenX = n/2;
        long long oddX = (n+1)/2;

        long long evenY = m/2;
        long long oddY = (m+1)/2;

        long long res = evenX*oddY + evenY*oddX;
        return res; 
        //return (long)(n*m)/2;
    }
};
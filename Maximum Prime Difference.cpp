// BRUTE FORCE
class Solution {
public:
    bool isprime(int num){
        if (num <= 1)   return false;
        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0) {
                return false;
            }
        }
       return true;
    }
    int maximumPrimeDifference(vector<int>& nums) {
        int maxi = 0;
        for(int i=0; i<nums.size(); i++){
            if(isprime(nums[i])){
                for(int j = i+1; j<nums.size(); j++){
                     if(isprime(nums[j])){
                        int dis = abs(j-i);
                        maxi = max(maxi, dis);
                     }
                }
            }
        }
        return maxi;
    }
};

// OPTIMAL 
---------- APPROACH - 1 ----------
class Solution {
public:
    bool isprime(int num){
        if (num <= 1)   return false;
        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0) {
                return false;
            }
        }
       return true;
    }
    int maximumPrimeDifference(vector<int>& nums) {
        int maxi = 0;
        int firstprime = -1, lastprime =0;
        for(int i=0; i<nums.size(); i++){

            if(isprime(nums[i]) == true){
                if(firstprime == -1){
                    firstprime = i;
                    
                }
                lastprime = i;
            }
        }
        maxi = abs(lastprime - firstprime);
        return maxi;
    }
};

-------- APPROACH - 2 ----------
// Sieve of Eratosthenes
class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        int maxEle = *max_element(nums.begin(), nums.end());
        
        // Sieve of Eratosthenes to generate prime numbers up to maxElement
        vector<bool> prime(maxEle + 1, true);
        prime[0] = false;
        prime[1] = false;
        for (int i = 2; i * i <= maxEle; i++) {
            if (prime[i]) {
                for (int multiple = i * i; multiple <= maxEle; multiple += i) {
                    prime[multiple] = false;
                }
            }
        }
        int firstPrime = -1;
        int lastPrime = -1;
        // Iterate through the array to find the indices of the first and last prime numbers
        for (int i = 0; i < nums.size(); i++) {
            if (prime[nums[i]]) {
                if (firstPrime == -1) {
                    firstPrime = i;
                }
                lastPrime = i;
            }
        }
        // Calculate the maximum distance between the indices of prime numbers
        return abs(lastPrime - firstPrime);
    }
};

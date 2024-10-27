class Solution {
public:
    int pivotInteger(int n) {
       int leftsum = 0, rightsum=0;
    
       int sum = n * (n + 1) / 2;
       double a = sqrt(sum);

        if (a - ceil(a) == 0)
            return int(a);
        else
            return -1;
       

    //    for(int i=1; i<=n; i++){
  
    //     leftsum = i*(i+1)/2, rightsum=(n*(n+1)/2) - (i*(i-1)/2);

    //     if(leftsum == rightsum)  return i;
    //    }
    //    return -1; 
    }
};

class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int used = 0;
        while(mainTank >= 5){
            used += 5;
            mainTank -= 5;
            if(additionalTank){
                additionalTank--;
                mainTank++;
            }

        }
        used += mainTank;
        return used*10;
    }
};

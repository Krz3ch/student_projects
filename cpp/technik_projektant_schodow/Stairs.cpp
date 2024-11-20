#include <iostream>
#include <cmath>

using namespace std;

class Stairs
{
    public:
        int stepHeight;
        int stepLength;
        int stepCount;
        bool canBeMade = false;
    Stairs (int height, int length, int count, bool isOk) : stepHeight(height), stepLength(length), stepCount(count), canBeMade(isOk){}
};

Stairs makeStairs(int kHeight, int kLength){
    
    int stairsCount = 0, stairsHeight, stairsLength, test;

    for(int i = 150; i < 170; i++){
        if(kHeight % i == 0){
            test = kHeight / i;
            stairsCount = test;
            break;
        }
    }

    if(stairsCount == 0){
        if(round(kHeight/150) == 0){
            stairsCount = 1;
        }else{
            stairsCount = round(kHeight/150);
        }
    }

    stairsHeight = kHeight/stairsCount;
    stairsLength = kLength/stairsCount;
    
    if(stairsLength < 290){
        return Stairs(0, 0, 0, false);
    }

    return Stairs(stairsHeight, stairsLength, stairsCount, true);
};

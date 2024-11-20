#include <iostream>
#include <cmath>

using namespace std;

class Stairs
{
    public:
        int stepHeight;
        int stepLength;
        int stepCount;
    Stairs (int height, int length, int count) : stepHeight(height), stepLength(length), stepCount(count){}
};

Stairs makeStairs(int kLength, int kHeight){
    
    int stairsCount = 0;
    int stairsHeight;
    int stairsLength;
    int test;

    for(int i = 150; i < 170; i++){
        if(kHeight % i == 0){
            test = kHeight / i;
            if((kLength/test) >= 290  && (kLength/test) <= 320){
                stairsCount = test;
                stairsHeight = kHeight/stairsCount;
                stairsLength = kLength/stairsCount;
                break;
            }
        }
    }

    if(stairsCount == 0){
        stairsCount = round(kHeight/170);
    }

    stairsHeight = kHeight/stairsCount;
    stairsLength = kLength/stairsCount;
    
    return Stairs(stairsHeight, stairsLength, stairsCount);
};

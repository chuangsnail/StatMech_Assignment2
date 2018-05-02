
#include <iostream>
#include <cmath>
#include <random>
#include <time.h>
#include <iomanip>
#include <vector>

using namespace std;


class Two_dices
{
private:
    int sides1;
    int sides2;
    int sides3;
public:
    Two_dices(int,int,int);
    vector<int> histogram;
    void roll(int);
};

Two_dices::Two_dices(int s1,int s2,int s3)
{
    sides1 = s1;
    sides2 = s2;
    sides3 = s3;
    histogram.assign(s1+s2+s3-2, 0);
}

void Two_dices::roll(int trials)
{
    histogram.assign(sides1+sides2+sides3-2, 0);
    //make histogram
    for (int i=0; i<trials; i++)
    {
        int r = 0;
        r = rand() % sides1 + rand() % sides2 + rand() % sides3;
        histogram[r] += 1;
    }
    int size_of_hist = histogram.size();
    for(int i=0;i<size_of_hist;i++)
        printf("%d : %f \n",i+3,(double)histogram[i]/trials);
    cout << endl <<endl;
    
}



int main()
{
    srand(time(0));
    //2-2-1
    Two_dices dices1(6,6,6);
    dices1.roll(1000);
    dices1.roll(10000);
    dices1.roll(100000);
    //2-2-2
    Two_dices dices2(3,6,7);
    dices2.roll(1000);
    dices2.roll(10000);
    dices2.roll(100000);
}



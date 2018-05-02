
#include <iostream>
#include <cmath>
#include <random>
#include <time.h>
#include <iomanip>
#include <vector>

using namespace std;

void print_result(double,double,double);
void print_theo_value(int,int);

class Dices
{
private:
    int sides;
    int num_of_dice;
public:
    Dices(int,int);
    vector<int> histogram;
    void roll(int);
};

Dices::Dices(int s,int n)
{
    sides = s;
    num_of_dice = n;
    histogram.assign(s*n, 0);
}

void Dices::roll(int trials)
{
    printf("\n\nWe have %d dices of %d sides,with %d trials :\n",num_of_dice,sides,trials);
    histogram.assign(sides*num_of_dice, 0);
    double mean = 0.0;
    double var = 0.0, SD = 0.0;
    //make histogram
        for (int i=0; i<trials; i++)
        {
            int r = 0;
            for(int j=0;j<num_of_dice;j++)
            {
                r += rand() % sides;
            }
            histogram[r] += 1;
        }
    int size_of_hist = histogram.size();
   
    //calculate var and SD
    for (int i=0; i< size_of_hist; i++)
    {
        mean = mean + (i+num_of_dice) * (double)histogram[i]/trials;
        var = var + pow((i+num_of_dice),2) * (double)histogram[i]/trials;
    }
    var = var - pow(mean, 2);
    SD = sqrt(var);
    // print mean and var and SD
    
    print_result(mean,var,SD);
    print_theo_value(sides,num_of_dice);
}
/*
void print_theo_value(int sides,int num_of_dice)
{
    double mean = 0.0,var = 0.0,SD = 0.0;
    mean = (double)num_of_dice*((1+sides)*sides/2)/sides;
    double sqsum = 0.0;
    for(int i=0;i<(sides * num_of_dice);i++)
    {sqsum += (double)pow((i+num_of_dice),2);}
    var = (double)sqsum/(sides * num_of_dice)-pow(mean,2.0);
    SD = sqrt(var);
    cout << "\nfor theoretical values:\n";
    printf("mean value is:%.5f \n       var is:%.5f \n        SD is:%.5f \n",mean,var,SD);
}
*/
void print_result(double mean,double var,double SD)
{
    printf("mean value is:%.5f \n       var is:%.5f \n        SD is:%.5f \n",mean,var,SD);
}


int main()
{
    srand(time(NULL));
    //1-2(a)
    Dices dices1(10,2);
    dices1.roll(1000);
    dices1.roll(10000);
    dices1.roll(100000);
    //1-2(b)
    Dices dices2(20,10);
    dices2.roll(1000);
    dices2.roll(10000);
    dices2.roll(100000);
    return 0;
}


#include<iostream>
using namespace std;

#define MAX 100
int memoization_array[100][100];

int egg_trials(int n_eggs, int n_floors)
{
    if(memoization_array[n_eggs-1][n_floors-1] > -1)
        return (memoization_array[n_eggs-1][n_floors-1]);
        
    if((n_floors == 1 || n_floors == 0) && n_eggs > 0)
        return (n_floors);
    
    if(n_eggs == 1)
        return (n_floors);
         
    int min, current, first, second;
    
    //first = egg_trials(n_eggs-1, 0);
    //second = egg_trials(n_eggs, n_floors-1);
    
    min = egg_trials(n_eggs-1, 0) > egg_trials(n_eggs, n_floors-1) ?
          egg_trials(n_eggs-1, 0) : egg_trials(n_eggs, n_floors-1);
    
    for(int i = 2; i <= n_floors; i++)
    {
        current = egg_trials(n_eggs-1, i-1) > egg_trials(n_eggs, n_floors-i) ?
                  egg_trials(n_eggs-1, i-1) : egg_trials(n_eggs, n_floors-i);
        if(current < min)
            min = current;
    }
    
    if(memoization_array[n_eggs-1][n_floors-1] == -1)
        memoization_array[n_eggs-1][n_floors-1] = min + 1;
        
    return (min + 1);
    
}
     

int main(int argc, char **argv)
{
    for(int i = 0; i < MAX; i++)
        for(int j = 0; j < MAX; j++)
            memoization_array[i][j] = -1;

    int n_eggs = 2, n_floors = 100;
    cout<<"Minimum number of required trials: ";
    cout<<egg_trials(n_eggs, n_floors);
    cout<<endl;
    
    cin.get();
    return (0);
}

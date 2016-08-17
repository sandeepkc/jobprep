#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main () {
  int myints[] = {10,20,30,30,20,10,10,20};
  vector<int> v(myints,myints+8);           // 10 20 30 30 20 10 10 20
  vector<int>::iterator low,up;

  sort (v.begin(), v.end());                // 10 10 10 20 20 20 30 30

  low=lower_bound (v.begin(), v.end(), 20); //
  /*
   * lower_bound returns the first iterator in the vector which doesn't compare
   * less than 'argument'.
   */
  
  up= upper_bound (v.begin(), v.end(), 20); //   
  /*
   * upper_bound returns the first iterator in the vector which is greater
   * than 'argument'.
   */

  cout << "lower_bound at position " << int(low- v.begin()) << endl;
  cout << "upper_bound at position " << int(up - v.begin()) << endl;

  cin.get();
  return (0);
}

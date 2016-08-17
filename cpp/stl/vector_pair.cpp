#include<iostream>
#include<vector>
using namespace std;

int main(void) {
	vector <pair<int, int> > V;
	
	for(int i = 0; i < 10; ++i) {
		V.push_back(make_pair(i, 2*i));
	}

	for(vector<pair<int, int> >::iterator it = V.begin();
		it != V.end(); ++it) {
		cout<<it->first<<" "<<it->second<<endl;
	}

	return (0);
}

#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;
#define SIZE rand()%100000 

int main() {
	vector<vector<vector<int> > > V;
	srand(time(NULL));
	vector<char> cv;
	cv.push_back('a');
	cv.push_back('b');
	cv.push_back('u');

	for(int i = 0; i < (rand()%rand())%SIZE +  1; ++i) {
		vector<vector<int> > v2d;
		for(int j = 0; j < (rand()%rand())%SIZE + 1; ++j) {
			vector<int> v1d;
			for(int k = 0; k < 5; ++k) {
				v1d.push_back(rand()%SIZE);
			}
			v2d.push_back(v1d);
		}
		V.push_back(v2d);
	}

	for(int i = 0; i < V.size(); ++i) {
		for(int j = 0; j < V[i].size(); ++j) {
			string word = "";
			for(int k = 0; k < V[i][j].size(); ++k) {
				word += cv[V[i][j][k]%3];
			}
			if(word.compare("babbu") == 0)
				cout<<word<<endl;
			word = "";
		}
	}

	return (0);
}

#include<iostream>
#include<list>
#include<time.h>
#include<stdlib.h>
using namespace std;

int main() {
	list<list<int> >L;

	srand(time(NULL));
	for(int i = 0; i < 10; ++i) {
		list<int> l;
		for(int j = 0; j < 10; ++j) {
			//srand(time(NULL));
			l.push_back(rand()%100);
		}
		L.push_back(l);
	}

	for(list<list<int> >::iterator it =  L.begin(); it!=L.end();
		++it) {
		for(list<int>::iterator lit = it->begin(); lit!= it->end(); ++lit) {
			cout<<*lit<<" ";
		}
		cout<<endl;
	}

	return (0);
}

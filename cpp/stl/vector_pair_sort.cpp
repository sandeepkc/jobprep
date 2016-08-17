#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//This will do the comparison with respect to the last char
bool my_comp(const pair<string, string>&a, const pair<string, string>&b) {
	if(a.first.compare(b.first) == 0)
		return a.second.compare(b.second) <= 0 ? true : false;
	return a.first.compare(b.first) <= 0 ? true : false;
}
int main() {
	vector<pair<string, string> > V;

	V.push_back(make_pair("The", "the"));
	V.push_back(make_pair("quick", "test"));
	V.push_back(make_pair("quick", "test1"));
	V.push_back(make_pair("quick", "test2"));
	V.push_back(make_pair("quick", "rest2"));
	V.push_back(make_pair("xyz", "rest2"));

	//sort(V.begin(), V.end());
	sort(V.begin(), V.end(), my_comp);
	
	for(int i = 0; i < V.size(); ++i)
		cout<<V[i].first<<" "<<V[i].second<<endl;
	cout<<endl;

	return (0);
}
	

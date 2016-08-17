#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<fstream>

using namespace std;

int main (int argc, char **argv) {
    vector<pair<string, string> > V;
    if (argc < 2) {
        printf("usage: %s input-file-name\n", argv[0]);
        exit(0);
    }

    ifstream input_file;
    input_file.open(argv[1]);

    string word;
    while (input_file >> word) {
        string sorted = word;
        sort(sorted.begin(), sorted.end());
        V.push_back(make_pair(sorted, word));
    }
    sort(V.begin(), V.end());

    if (V.size() == 0) return 0;

    cout << V[0].second;
    for (int i = 1; i < V.size(); i++) {
        if (V[i].first == V[i-1].first) cout << " " << V[i].second;
        else cout << endl << V[i].second;
    }
    cout << endl;
}
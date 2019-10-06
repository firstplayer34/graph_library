#include <iostream>
#include "Graph.h"
using namespace std;

int main() {
	vector<vector<int>>a;
	for (int i = 0; i < 7; i++) {
		vector<int>t;
		int x=-9;
		while (x != -1) {
			cin >> x;
			if(x!=-1)t.push_back(x);
		}
		a.push_back(t);
	}
	cout << a.size();
	Graph temp(a);
	temp.PrintList();
}
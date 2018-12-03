/*
* 0-1 Knapsack problem using Branch and Bound
* By: Matt Homes and Allen Burris
*/

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class loot {
public:

	int value, weight;
	double ratio;
	string name;

	loot(string n, int v, int w) {
		name = n;
		value = v;
		weight = w;
		ratio = v / w;
	}
	void print() {
		cout << name << " " << value << " " << weight << " " /*<< ratio */ << endl;
	}
};

int main() {

	int n, bagSize;
	string file;

	//file In
	ifstream fileIn;
	fileIn.open("TestFile.txt");
	fileIn >> n;
	fileIn >> bagSize;

	bestSet = new int[n];
	include = new int[n];

	loot ** Loot = new loot *[n + 1];
	Loot[0] = NULL;

	for (int x = 1; x < n + 1; x++) {
		string n;
		int v, w;
		fileIn >> n >> v >> w;
		Loot[x] = new loot(n, v, w);
	}
	fileIn.close();

/*
	//Format output
	for (int i = 1; i < n + 1; i++) {
		if (bestSet[i] == 1) {
			totalWeight = totalWeight + Loot[i]->weight;
		}
	}

	cout << numbest << endl;
	cout << totalWeight << endl;
	cout << maxprofit << endl;
	for (int i = 1; i < n + 1; i++) {
		if (bestSet[i] == 1) {
			Loot[i]->print();
		}
	}

	*/
	return 0;
}
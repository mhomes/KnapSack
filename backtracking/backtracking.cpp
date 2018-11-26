
/*
* 0-1 Knapsack problem using Backtracking
* By: Matt Homes and Allen Burris
*/

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Loot {

	string name;
	int weight, value, pos;
	double ratio;

	void print() {
		cout << name << " " << value << " " << weight << " " /*<< ratio */ << endl;
	}
};

bool promising(int i, int profit, int weight, Loot holdThis[], int bagSize, int maxprofit, int numGems)
{
	int totalweight, j, k;
	float bound;

	if (weight >= bagSize) {
		return false;
	}
	else {
		j = i + 1;
		bound = profit;
		totalweight = weight;
		while (j <= numGems && (totalweight + holdThis[j].weight) <= bagSize) {

			totalweight = totalweight + holdThis[j].weight;
			bound = bound + holdThis[j].value;
			j++;
		}
		k = j;

		if (k <= numGems)
			bound = bound + ((bagSize - totalweight) * (holdThis[k].ratio));
		return bound > maxprofit;
	}

}

void sack(int i, int profit, int weight, Loot holdThis[], bool include[], int bagSize, int &maxprofit, bool bestSet[], int numGems) {

	if (i >= numGems)
		return;
	if (weight <= bagSize && profit > maxprofit) {
		maxprofit = profit;
		bestSet[i] = include[i];
	}

	if (promising(i, profit, weight, holdThis, bagSize, maxprofit, numGems)) {
		include[i + 1] = true;
		sack(i + 1, profit + holdThis[i + 1].value, weight + holdThis[i + 1].weight, holdThis, include, bagSize, maxprofit, bestSet, numGems);

		include[i + 1] = false;
		sack(i + 1, profit, weight, holdThis, include, bagSize, maxprofit, bestSet, numGems);
	}

}

double findRatio(int v, int w) {
	double out = (1.0 * v / w);
	return (out);
}

void swap(int j, int i, Loot holdThis[]) {
	Loot hold = holdThis[j];
	holdThis[j] = holdThis[i];
	holdThis[i] = hold;
}

void sort(Loot holdThis[], int n) {
	int i, j;
	bool swapped;
	for (i = 0; i < n - 1; i++) {
		swapped = false;
		for (j = 0; j < n - i - 1; j++) {
			if (holdThis[j].ratio < holdThis[j + 1].ratio) {
				swap(holdThis[j], holdThis[j + 1]);
				swapped = true;
			}
		}

		if (swapped == false)
			break;
	}
}

int main() {

	string n;
	int numGems, bagSize, w, v;
	int best = 0;
	int maxprofit = 0;

	//file in
	ifstream fileIn;
	fileIn.open("TestFile.txt");
	fileIn >> numGems >> bagSize;

	Loot holdThis[numGems];
	bool bestSet[numGems];
	bool include[numGems];


	for (int i = 0; i < numGems; i++) {
		fileIn >> n;
		fileIn >> w >> v;
		holdThis[i].name = n;
		holdThis[i].weight = w;
		holdThis[i].value = v;
		holdThis[i].pos = i;
		holdThis[i].ratio = findRatio(v, w);
	}
	fileIn.close();

	sort(holdThis, numGems);

	sack(-1, 0, 0, holdThis, include, bagSize, maxprofit, bestSet, numGems);
	cout << endl;

	//Format output
	int numContents, weight, value;
	numContents = weight = value = 0;

	for (int i = 0; i < numGems; i++)
		if (bestSet[i]) {
			numContents++;
			weight += holdThis[i].weight;
			value += holdThis[i].value;
		}

	cout << numContents << endl;
	cout << weight << endl;
	cout << value << endl;
	for (int i = 0; i < numContents; i++)
		if (bestSet[i] == true)
			holdThis[i].print();

	return 0;
}
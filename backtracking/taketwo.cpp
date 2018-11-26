/*
* 0-1 Knapsack problem using Backtracking
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

};



int maxprofit = 0;
int numbest = 0;
int totalWeight;

int *bestSet;
int *include;

void merge(loot **a, int l, int m, int r) {
	int i, j, k;
	int sizeL = m - l + 1;
	int sizeR = r - m;
	loot ** L = new loot *[sizeL];
	loot ** R = new loot *[sizeR];

	for (i = 0; i < sizeL; i++)
		L[i] = a[l + i];
	for (j = 0; j < sizeR; j++)
		R[j] = a[m + 1 + j];

	i = 0;
	j = 0;
	k = l;
	while (i < sizeL && j < sizeR) {
		if (L[i]->ratio >= R[j]->ratio) {
			a[k] = L[i];
			i++;
		}
		else {
			a[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < sizeL) {
		a[k] = L[i];
		i++;
		k++;
	}

	while (j < sizeR) {
		a[k] = R[j];
		j++;
		k++;
	}
}


void mergeSort(loot **a, int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;

		mergeSort(a, l, m);
		mergeSort(a, m + 1, r);

		merge(a, l, m, r);
	}
}



bool promising(int i, int bagSize, int weight, int profit, loot **Loot, int n) {
	int totalweight, j, k;
	double bound;

	if (weight >= bagSize) {
		cout << i << " is not promising" << endl;
		return false;
	}
	else {
		cout << "promise check" << endl;
		j = i + 1;
		bound = profit;
		totalweight = weight;
		while (j <= n && totalweight + Loot[j]->weight <= bagSize) {

			totalweight = totalweight + Loot[j]->weight;
			bound = bound + Loot[j]->value;
			j++;
		}
		k = j;
		if (k <= n) {
			bound = bound + ((bagSize - totalweight) * (Loot[k]->ratio));
		}
		return bound > maxprofit;
	}
}


void sack(int i, int bagSize, int weight, int profit, loot ** Loot, int n) {

	if (weight <= bagSize && profit > maxprofit) {
		maxprofit = profit;
		numbest = i;
		bestSet[i] = include[i];
	}

	//cout << maxprofit << endl;
	if (promising(i, bagSize, weight, profit, Loot, n) == true) {
		include[i + 1] = 1;
		sack(i + 1, bagSize, weight + Loot[i + 1]->weight, profit + Loot[i + 1]->value, Loot, n);

		include[i + 1] = 0;
		sack(i + 1, bagSize, weight, profit, Loot, n);
	}

}


int main() {

	int n, bagSize;
	string file;


	//file in
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

	mergeSort(Loot, 1, n);
	sack(0, bagSize, 0, 0, Loot, n);


	//Format output
	for (int x = 1; x < n + 1; x++) {
		if (bestSet[x] == 1) {
			totalWeight = totalWeight + Loot[x]->weight;
		}
	}


	cout << numbest << endl;
	cout << totalWeight << endl;
	cout << maxprofit << endl;
	for (int x = 1; x < n + 1; x++) {
		if (bestSet[x] == 1) {
			cout << Loot[x]->name << " " << Loot[x]->value << " " << Loot[x]->weight << endl;
		}
	}


	delete[] bestSet;
	delete[] include;

	return 0;
}
/*
Project: Dynamic 0-1 KnapSack
Authors: Allen Burris, Mathew Homes
Finished on: 10-31-2018
*/
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Loot {

	string name;
	int weight, value;
	double ratio;

	void print() {
		cout << name << " " << value << " " << weight << " " << endl;
	}
};

int fill(int i, int w, int **matrix, Loot *holdThis) {

	if (i == 0 || w == 0)
		return 0;
	if (w < holdThis[i].weight)
		matrix[i][w] = fill(i - 1, w, matrix, holdThis);
	else
		matrix[i][w] = max(fill(i - 1, w, matrix, holdThis), (fill(i - 1, w - holdThis[i].weight, matrix, holdThis) + holdThis[i].value));

}

int main() {

	string n;
	int numGems, bagSize, w, v;

	ifstream fileIn;
	fileIn.open("TestFile.txt");
	fileIn >> numGems >> bagSize;

	int** matrix = new int *[numGems + 1];
	for (int i = 0; i <= numGems; i++)
		matrix[i] = new int[bagSize + 1];

	Loot* holdThis = new Loot[numGems + 1];

	for (int w = 0; w <= bagSize; w++)
		matrix[0][w] = 0;

	for (int i = 1; i <= numGems; i++) {
		fileIn >> n;
		fileIn >> w >> v;
		holdThis[i].name = n;
		holdThis[i].weight = w;
		holdThis[i].value = v;
	}

	fill(numGems, bagSize, matrix, holdThis);

	int weight = 0, value = 0;
	int numContents = 0;
	int contents[numGems + 1];
	int i = numGems;
	w = bagSize;

	while (i > 0) {
		if (matrix[i][w] == matrix[i - 1][w])
			i--;
		else {
			w = w - holdThis[i].weight;
			weight += holdThis[i].weight;
			value += holdThis[i].value;
			contents[numContents] = i;
			numContents++;
			i--;
		}
	}

	cout << numContents << endl;
	cout << weight << endl;
	cout << value << endl;
	for (int i = 0; i < numContents; i++) {
		holdThis[contents[i]].print();
	}

	return 0;
}
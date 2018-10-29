
#include <iostream>
#include <fStream>
#include <cstring>

using namespace std;

struct Loot {

	string name;
	int weiht, value;
	double ratio;

	void print() {
		cout << name << " " << value << " " << weight << " " << endl;
	}
};

int fill(int i, int w, int matrix[][], Loot holdThis[], int numGems, int bagSize) {

	if(holdThis[i].weight )
	if (fill(i, w, matrix[i][w] > fill(i-1, w, matrix[][], holdThis)
		return matrix[i][w];
}

int main() {

	string n; 
	int numGems, bagSize, w, v; 

	ifstream fileIn; 
	fileIn.open("TestFile.txt");
	fileIn >> numGems >> bagSize;

	int matrix[numGems + 1][bagSize + 1];
	Loot holdThis[numGems + 1];

	for (int w = 0; w <= bagSize; w++)
		matrix[0][w] = 0;

	for (int i = 1; i <= numGems; i++) {
		fileIn >> n;
		fileIn >> w >> v;
		holdThis[i].name = n;
		holdThis[i].weight = w;
		holdThis[i].value = v;
	}

	fill(numGems + 1, bagSize + 1, matrix, holdThis, numGems, bagSize);

	return 0;
}
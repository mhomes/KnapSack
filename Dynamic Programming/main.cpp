

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Loot {

	string name;
	int weight, value;
	double ratio;

	void print() {
		cout << name << " " << value << " " << weight << " " /*<< ratio */ << endl;
	}

};

int main() {

	string n;
	int numGems, bagSize, w, v;

	//file in
	ifstream fileIn;
	fileIn.open("TestFile.txt");
	fileIn >> numGems >> bagSize;

	int Matrix[numGems + 1][bagSize + 1];
	bool companionMatrix[numGems + 1][bagSize + 1];
	Loot holdThis[numGems+1];

	//filling the top row of the Matrix with 0's
	// gives the if something to compare to. 
	for (int w = 0; w <= bagSize; w++)
		Matrix[0][w] = 0;

	//populating the rest of the matrix
	for (int i = 1; i <= numGems; i++) {
		fileIn >> n;
		fileIn >> w >> v;
		holdThis[i].name = n;
		holdThis[i].weight = w;
		holdThis[i].value = v;
	}

	//Filling the Matrix with Real Values
	for (int i = 1; i <= numGems; i++) {
		for (int w = 0; w <= bagSize; w++) {
			
			if (holdThis[i].weight > w) {
				Matrix[i][w] = Matrix[i - 1][w];
				companionMatrix[i][w] = false;
			}
			else if (holdThis[i].weight <= w) {
				if (Matrix[i - 1][w] > (holdThis[i].value + Matrix[i - 1][w - holdThis[i].weight])) {
					Matrix[i][w] = Matrix[i - 1][w];
					companionMatrix[i][w] = false;
				}
				else { 
					Matrix[i][w] = (holdThis[i].value + Matrix[i - 1][w - holdThis[i].weight]); 
					companionMatrix[i][w] = true;
				}
			}

		}
		
	}

	int weight = 0, value = 0;
	int numContents = 0;
	int contents[numGems + 1];
	int i = numGems;
	w = bagSize;

	while (i > 0) {
		if (Matrix[i][w] == Matrix[i - 1][w])
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

	//Format output
	cout << numContents << endl;
	cout << weight << endl;
	cout << value << endl;
	for (int i = 0; i < numContents; i++) {
		holdThis[contents[i]].print();
	}

	

	return 0;
}
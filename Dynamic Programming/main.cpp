

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

	int Matrix[numGems + 1][bagSize];
	Loot holdThis[numGems];

	//filling the top row of the Matrix with 0's
	// gives the if something to compare to. 
	for (int i = 0; i < bagSize; i++)
		Matrix[0][i] = 0;

	//Filling the Matrix with Real Values
	for (int i = 1; i < numGems; i++) {

		fileIn >> n;
		fileIn >> w >> v;
		holdThis[i].name = n;
		holdThis[i].weight = w;
		holdThis[i].value = v;

		for (int w = 0; w <= bagSize; w++) {
			if (holdThis[i].weight > w) {
				Matrix[i][w] = Matrix[i - 1][w];
			}
			else if (holdThis[i].weight < w) {
				if (Matrix[i - 1][w] > (holdThis[i].value + Matrix[i - 1][w - holdThis[i].weight]))
					Matrix[i][w] = Matrix[i - 1][w];
				else Matrix[i][w] = (holdThis[i].value + Matrix[i - 1][w - holdThis[i].weight]);
			}

		}
		
	}

	//Printing the Matrix
	for (int i = 0; i < numGems; i++) {
		for (int w = 0; w <= bagSize; w++) {
			cout <<" "<< Matrix[i][w]; 
		}
		cout << endl;
	}

	/*STOP*/

	//Reading Output off the Matrix
	for (int w = bagSize; w <= 0; w--) {
		if (holdThis[i].weight > w) {
			Matrix[i][w] = Matrix[i - 1][w];
		}
		else if (holdThis[i].weight < w) {
			if (Matrix[i - 1][w] > (holdThis[i].value + Matrix[i - 1][w - holdThis[i].weight]))
				Matrix[i][w] = Matrix[i - 1][w];
			else Matrix[i][w] = (holdThis[i].value + Matrix[i - 1][w - holdThis[i].weight]);
		}

	}

	return 0;
}
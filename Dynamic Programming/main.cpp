

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

	int Matrix[numGems + 1][bagSize+1];
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
			}
			else if (holdThis[i].weight <= w) {
				if (Matrix[i - 1][w] > (holdThis[i].value + Matrix[i - 1][w - holdThis[i].weight]))
					Matrix[i][w] = Matrix[i - 1][w];
				else Matrix[i][w] = (holdThis[i].value + Matrix[i - 1][w - holdThis[i].weight]);
				
				
			}

		}
		
	}

	//Printing the Matrix
	for (int i = 0; i <= numGems; i++) {
		for (int w = 0; w <= bagSize; w++) {
			cout <<" "<< Matrix[i][w]; 
		}
		cout << endl;
	}

	Loot contents[numGems];

	w = bagSize+1;
	int i = numGems;
	int numContents = 0;

	while (w > 0 && i > 0) {
		if (Matrix[i][w] == Matrix[i - 1][w]) {
			i--; //we did not add this item.
		}
		else {
			contents[numContents] = holdThis[i];
			w -= holdThis[i].weight; //we added the item and remove its weight from w
			i--;
			numContents++;
		}
	}

	//Format output
	int weight=0, value = 0;
	cout << numContents << endl;
	for (int i = 0; i <= numContents; i++) 
		weight += contents[i].weight;
	
	cout << weight << endl;
	for (int i = 0; i <= numContents; i++) 
		value += contents[i].value;

	cout << value << endl;
	for (int i = 0; i <= numContents; i++) {
		cout << contents[i].name<<" ";
		cout << contents[i].value<<" ";
		cout << contents[i].weight << endl;
	}
	

	return 0;
}
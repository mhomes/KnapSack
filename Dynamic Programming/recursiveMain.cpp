

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

int supportFunction(int i, int w, int *Matrix[][], Loot *holdThis[], int numGems, int bagSize) {
	//some stuff so that we set i and w at the beginning. 
	//and then can get rid of them. 
	fun(i, w, *Matrix[][], holdThis[]); //last position in matrix. aka start point
}


//remember that this is a recursive function so we need a base case and return statements. 
//look at main.ccp and its matrix building loop for a format template. 
int fun(int i, int w, int *Matrix[][], Loot *holdThis[]) {
	//bool companionMatrix[numGems + 1][bagSize + 1];
	if (holdThis[i]->weight > w)
		Matrix[i][w] = fun(i - 1, w, Matrix[][], holdThis[]); //fix this
	else
		if (Matrix[i][w] == fun(i - 1, w, Matrix, holdThis)) {
			Matrix[i][w] = fun(i - 1, w, Matrix, holdThis);
		//companionMatrix[i][w] = false;
		}
		else //if(Matrix[i][w] >= fun(i-1, w- holdThis[i].weight)) 
		{
			Matrix[i][w] = (holdThis[i].value + fun(i - 1, w - holdThis[i].weight, Matrix, holdThis));
		//companionMatrix[i][w] = true;
		}
}

int main() {

	string n;
	int numGems, bagSize, w, v;
	
	//bool companionMatrix[numGems + 1][bagSize + 1];

	//file in
	ifstream fileIn;
	fileIn.open("TestFile.txt");
	fileIn >> numGems >> bagSize;

	//int **Matrix
	int Matrix[numGems + 1][bagSize + 1];

	Loot holdThis[numGems + 1];

	//filling the top row of the Matrix with 0's
	// gives the if something to compare to. 
	for (int w = 0; w <= bagSize; w++)
		Matrix[0][w] = 0;

	//creating holdThis[]
	for (int i = 1; i <= numGems; i++) {
		fileIn >> n;
		fileIn >> w >> v;
		holdThis[i].name = n;
		holdThis[i].weight = w;
		holdThis[i].value = v;
	}


	//variable redefining
	int i = numGems + 1;
	w = bagSize + 1;
	fun(i, w, Matrix, holdThis, numGems, bagSize);

	/*
	//Format output
	cout << numContents << endl;
	cout << weight << endl;
	cout << value << endl;
	for (int i = 0; i < numContents; i++) {
		cout << contents[i].name << " ";
		cout << contents[i].value << " ";
		cout << contents[i].weight << endl;
	}
	*/


	return 0;
}


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

int Matrix[numGems + 1][bagSize + 1];
bool companionMatrix[numGems + 1][bagSize + 1];

int fun(int i, int w) {
	if (Matrix[i][w] == fun(i - 1, w)) {
		fun(i - 1, w);
		companionMatrix[i][w] = false;
	}
	else //if(Matrix[i][w] >= fun(i-1, w- holdThis[i].weight)) 
	{
		Matrix[i][w] = (holdThis[i].value + fun(i - 1, w - holdThis[i].weight);
		companionMatrix[i][w] = true;
	}
}

int main() {

	string n;
	int numGems, bagSize, w, v;

	//file in
	ifstream fileIn;
	fileIn.open("TestFile.txt");
	fileIn >> numGems >> bagSize;

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
	fun(i, w);

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
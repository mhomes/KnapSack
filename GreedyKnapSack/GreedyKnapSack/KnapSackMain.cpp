// GreedyKnapSack.cpp
// Allen Burris
// Algorithms Poject 1:
// Greedy KnapSack - Main File
//

#include <iostream>
#include <fstream>
#include <cstring>

//#include "Loot.cpp"
using namespace std;

double findRatio(int w, int v);

struct Loot {

	string name;
	int weight;
	int value;
	double ratio;

};

/*
struct Node {

	Loot* heldItem;
	Node* LHNode;
	Node* RHNode;
	Node* parent;

}; */



int main() {

	int count, numGems, bagSize;

	//file in
	ifstream fileIn;
	fileIn.open("TestFile.txt");
	fileIn >> numGems >> bagSize;

	// create Loot objects for each item
	Loot * test = new Loot[30];
	//std::vector<Loot> testArray;
	for (int i = 0; i < numGems; i++) {
		string n;
		int w, v;
		fileIn >> n;
		fileIn >> w >> v;
		test[i].name = n;
		test[i].weight = w;
		test[i].value = v;
		test[i].ratio = findRatio(w, v);
		//cout << test[i].name << endl;
	}

	for (int i = 0; i < numGems; i++) {
		//delete &test[i];
	}

	// done - read file in
	//create object for it
	//put it in the queue based on ratio
	//pull items off the queue untill bag is full
	//print out items in bag


	return 0;
}

double findRatio(int w, int v) {
	return (w / v);
}







// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

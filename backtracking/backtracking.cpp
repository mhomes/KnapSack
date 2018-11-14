/*
* 0-1 Knapsack problem using Backtracking
* By: Matt Homes and Allen Burris
*/

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void checkNode(Node u);

struct Loot {

	string name;
	int weight, value;
	double ratio;

	void print() {
		cout << name << " " << value << " " << weight << " " /*<< ratio */ << endl;
	}
}

struct Node {

	Loot* heldItem;
	Node* LHNode;
	Node* RHNode;
	Node* parent;
	int bound; 
	int curWeight;
	int curProfit;

	Node() { LHNode = RHNode = parent = NULL; }

	void printNode(Node* node) {
		cout << node->heldItem->name << endl;
	}

};
bool promissing(Node v) {

}

void checkNode(Node v, int best) {
	Node u;
	if (v.heldItem->value > best)
		best = v.heldItem->value;
	if (promissing(v)) {
		
	}
		
}

int main() {

	string n;
	int numGems, bagSize, w, v;
	Node root;

	//file in
	ifstream fileIn;
	fileIn.open("TestFile.txt");
	fileIn >> numGems >> bagSize;

	Loot holdThis[numGems + 1];

	for (int i = 1; i <= numGems; i++) {
		fileIn >> n;
		fileIn >> w >> v;
		holdThis[i].name = n;
		holdThis[i].weight = w;
		holdThis[i].value = v;
	}
	fileIn.close();

	root.curWeight = 0;
	root.curProfit = 0;


	return 0;
	}
};
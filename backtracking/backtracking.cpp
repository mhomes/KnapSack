/*
* 0-1 Knapsack problem using Backtracking
* By: Matt Homes and Allen Burris
*/

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Loot {

	string name;
	int weight, value, pos;
	double ratio;

	void print() {
		cout << name <<" "<< pos <<" " << value << " " << weight << " " /*<< ratio */ << endl;
	}
};

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

void getBound(Node v, int bagSize, Loot holdThis[]) {
	int totWeight = v.curWeight;
	int count = 0;
	for (int i = v.heldItem->pos; totWeight >= bagSize; i++) {
		totWeight += holdThis[i + 1].weight;
		if (totWeight > bagSize) {
			totWeight -= holdThis[i + 1].weight;
			break;
		}

		count++;
	}
	v.curWeight = totWeight;

	int bound = v.curProfit;
	for (int i = v.heldItem->pos; i < count; i++) {
		bound += holdThis[i + 1].value;
	}
	bound += (bagSize - totWeight) * (holdThis[(v.heldItem->pos + count)].value / holdThis[(v.heldItem->pos + count)].weight);
	v.bound = bound;
}

void checkNode(Node v, int best) {

	if (v.bound <= best)
		return;
	Node u;
	if (v.heldItem->value > best)
		best = v.heldItem->value;
	if (v.bound) {
		
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
		holdThis[i].pos = i;
	}
	fileIn.close();

	root.curWeight = 0;
	root.curProfit = 0;


	return 0;
}

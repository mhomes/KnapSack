/*
* 0-1 Knapsack problem using Backtracking
* By: Matt Homes and Allen Burris
*/

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
bool pickedIt[100];

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
	bool isRoot;
	int bound; 
	int curWeight;
	int curProfit;

	//Node() { LHNode = RHNode = parent = NULL; isRoot = false; }
	Node(Loot* item, Node* par) {
		LHNode = RHNode = NULL;
		parent = par;
		heldItem = item;
		isRoot = false;
	}

	void printNode(Node* node) {
		cout << node->heldItem->name << endl;
	}

};

void getBound(Node* v, int bagSize, Loot* holdThis[]) {
	int totWeight = v->curWeight;
	int count = 0;
	for (int i = v->heldItem->pos; totWeight >= bagSize; i++) {
		totWeight += holdThis[i + 1]->weight;
		count++;
		if (totWeight > bagSize) {
			totWeight -= holdThis[i + 1]->weight;
			break;
		}
	}
	v->curWeight = totWeight;

	int bound = v->curProfit;
	for (int i = v->heldItem->pos; i < count; i++) {
		bound += holdThis[i + 1]->value;
	}
	bound += (bagSize - totWeight) * (holdThis[(v->heldItem->pos + count)]->value / holdThis[(v->heldItem->pos + count)]->weight);
	v->bound = bound;
}

void checkNode(Node* v,int bagSize, int numGems, int best, Loot* holdThis[]) {

	cout << "at node holding: " << endl;
	if (v->isRoot == false) {
		if (v->bound <= best)
			return;
		if (v->heldItem->pos == numGems)
			return;
	}
	if (v->curProfit > best)
		best = v->curProfit;
	//then check children

	cout << "1 " << endl;
	//Node* left = new Node(holdThis[(v->heldItem->pos + 1)], v);
	Node* left;
	cout << "1.1 " << endl;
	left->heldItem = holdThis[(v->heldItem->pos + 1)];
	cout << "1.2 " << endl;
	left->parent = v; 
	cout << "1a " << endl;

	v->LHNode = left;
	cout << "1b " << endl;
	v->LHNode->curProfit = (v->curProfit + holdThis[(v->heldItem->pos + 1)]->value);
	cout << "1c " << endl; 
	getBound(v->LHNode, bagSize, holdThis);

	cout << "2 " << endl;
	Node* right = new Node(holdThis[(v->heldItem->pos + 1)], v);
	v->RHNode = right;
	v->RHNode->curProfit = v->curProfit;
	getBound(v->RHNode, bagSize, holdThis);

	cout << "3 " << endl;
	if (v->LHNode->bound > v->RHNode->bound) {
		checkNode(v->LHNode, bagSize, numGems, best, holdThis);
		pickedIt[v->heldItem->pos + 1] = true;
	}
	else {
		checkNode(v->RHNode, bagSize, numGems, best, holdThis);
		pickedIt[v->heldItem->pos + 1] = false;
	}


	//if ((v->curProfit + holdThis[(v->heldItem.pos + 1)]->value) > best)
	//	checkNode(v->LHNode, best, holdThis);
	
}
/*
bool checkNode(int i, int numGems, Loot* holdThis[], int curProfit, int curCapacity, bool includedSoFar[]) {

	bool notInclude[i] = checkNode(i + 1, holdThis, curProfit, curCapacity, includedSoFar);
	if (curCapacity < holdThis[i]->weight)
		return false;
	else if (i >= numGems)
		return false;

	includedSoFar[i] = true;
	return max(val(notIncluded), checkNode(i + 1, curProfit + holdThis[i]->value, curCapacity - holdThis[i]->weight, includedSoFar);
}*/

int main() {

	cout << " m start" << endl;
	string n;
	int numGems, bagSize, w, v;
	Node * root;
	int best = 0;

	//file in
	ifstream fileIn;
	fileIn.open("TestFile.txt");
	fileIn >> numGems >> bagSize;

	Loot* holdThis = new Loot[numGems+1];

	for (int i = 1; i <= numGems; i++) {
		fileIn >> n;
		fileIn >> w >> v;
		holdThis[i].name = n;
		holdThis[i].weight = w;
		holdThis[i].value = v;
		holdThis[i].pos = i;
	}
	fileIn.close();

	root->curWeight = 0;
	root->curProfit = 0;
	root->isRoot = true;
	cout << "start" << endl;
	checkNode(root, bagSize, numGems, best, &holdThis);
	cout << "stop" << endl;

	//Format output
	int numContents, weight, value;
	numContents = weight = value = 0;

	for (int i = 1; i <= numGems; i++)
		if (pickedIt[i]) {
			numContents++;
			weight += holdThis[i].weight;
			value += holdThis[i].value;
		}

	cout << numContents << endl;
	cout << weight << endl;
	cout << value << endl;
	for (int i = 0; i < numContents; i++)
		if (pickedIt[i])
			holdThis[i].print();


	return 0;
}

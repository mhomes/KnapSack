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
	int weight, value;
	double ratio;

	void print() {
		cout << name << " " << weight << " " << value << " " /*<< ratio*/ << endl;
	}

};

struct Node {

	Loot* heldItem;
	Node* LHNode;
	Node* RHNode;
	Node* parent;

	Node() { LHNode = RHNode = parent = NULL; }

	void printNode(Node* node) {
		cout << node->heldItem->name << endl;
	}

};


// Priority Q
class PQ {

	Node * root;
public:

	void enqueue(Node* node, Node* parent){

		//cout << "at the start of the enqueue" << endl;
		if (parent->LHNode == NULL && node->heldItem->ratio < parent->heldItem->ratio) {
			//cout << "if1" << endl;
			parent->LHNode = node;
			node->parent = parent;
			return;
		}
		else if(parent->RHNode == NULL && node->heldItem->ratio > parent->heldItem ->ratio){
			//cout << "if2" << endl;
			parent->RHNode = node;
			node->parent = parent;
			return;
		}
		//cout << "enqueue 1" << endl;
		if (node->heldItem->ratio < parent->heldItem->ratio) {
			//cout << "if3" << endl;
			enqueue(node, parent->LHNode);
		}
		//cout << "enqueue 2" << endl;
		if (node->heldItem->ratio > parent->heldItem->ratio) {
			//cout << "if4" << endl;
			enqueue(node, parent->RHNode);
		}
		//cout << "at the end of the enqueue" << endl;
	}

	Loot* dequeue(Node* rightMostNode) {

		if (rightMostNode->RHNode != NULL) {
			dequeue(rightMostNode->RHNode);
		}
		else if (rightMostNode->LHNode == NULL)
		{
			rightMostNode->parent->RHNode = NULL;
			return rightMostNode->heldItem;
		}
		else {
			rightMostNode->parent->RHNode = rightMostNode->LHNode;
			rightMostNode->LHNode->parent = rightMostNode->parent;
			return rightMostNode->heldItem;
		}

	}

	void setRoot(Node* node) {
		node->parent = NULL;
		root = node;

	}

	Node* getRoot() {
		return root;
	}

	void printQ(Node* root) {
		root->heldItem->print();
		if (root->LHNode != NULL) {
			//root->LHNode->heldItem->print();
			printQ(root->LHNode);
		}
		if (root->RHNode != NULL) {
			//root->RHNode->heldItem->print();
			printQ(root->RHNode);
		}
		return;
	}

};

int main() {

	int count, numGems, bagSize, currBag;

	//file in
	ifstream fileIn;
	fileIn.open("TestFile.txt");
	fileIn >> numGems >> bagSize;

	// create Loot objects for each item
	Loot* insert = new Loot[numGems];
	Loot rootInsert;
	Node* node = new Node[numGems];
	PQ Q;
	Node * rootNode = new Node;

	string n;
	int w, v;

	fileIn >> n;
	fileIn >> w >> v;

	rootInsert.name = n;
	rootInsert.weight = w;
	rootInsert.value = v;
	rootInsert.ratio = findRatio(w, v);
	rootNode->heldItem = &rootInsert;

	Q.setRoot(rootNode);

	for (int i = 1; i < numGems; i++) {
		fileIn >> n;
		fileIn >> w >> v;
		insert[i].name = n;
		insert[i].weight = w;
		insert[i].value = v;
		insert[i].ratio = findRatio(v, w);
					 
		node[i].heldItem = &insert[i];

		Q.enqueue(&node[i], Q.getRoot());	
	} 
	Q.printQ(Q.getRoot());
	cout << "_______________________" << endl;

	Loot* test;
	for(int i = 1; i < numGems; i++) {
		test = Q.dequeue(Q.getRoot());
		test->print();
		cout << "_______________________" << i <<endl;
	}
	Q.printQ(Q.getRoot());

/*	Loot * printingItem;
	for (int i = 0; currBag <= bagSize; i++) {
		printingItem = Q.dequeue(Q.getRoot());
		if (printingItem->weight > bagSize - currBag)
			break;
		else {
			printingItem->print();
			currBag += printingItem->weight;
		}*/



	// done - read file in
	//done - create object for it
	//done - put it in the queue based on ratio
	//pull items off the queue untill bag is full
	//print out items in bag

	for (int i = 1; i < numGems; i++) {
		//delete node[i];
	}

	return 0;
}

double findRatio(int v, int w) {
	double out = (1.0 * v / w);
	return (out);
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

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

struct Loot {

	string name;
	int weight;
	int value;
	double ratio;

};

struct Node {

	Loot* heldItem;
	Node* LHNode;
	Node* RHNode;
	Node* parent;

};

//where do we create a node?


double findRatio(int w, int v);
//int Dequeue(Node node, Node parent);

class PQ {

public:
	Node * root;

	void enqueue(Node* node, Node* parent){
		cout << "at the start of the enqueue" << endl;
		if (parent->LHNode = NULL && node->heldItem->ratio < parent->heldItem->ratio) {
			cout << "if1" << endl;
			parent->LHNode = node;
			node->parent = parent;
			return;
		}
		if(parent->RHNode = NULL && node->heldItem->ratio > parent->heldItem ->ratio){
			cout << "if2" << endl;
			parent->RHNode = node;
			node->parent = parent;
			return;
		}
		cout << "enqueue 1" << endl;
		if (node->heldItem->ratio < parent->heldItem->ratio) {
			cout << "if3" << endl;
			enqueue(node, parent->LHNode);
		}
		cout << "enqueue 2" << endl;
		if (node->heldItem->ratio > parent->heldItem->ratio) {
			cout << "if4" << endl;
			enqueue(node, parent->RHNode);
		}
		cout << "at the end of the enqueue" << endl;
	}

	/*void dequeue(Node node, Node parent) {
		if node = root;
			
		if (node.LHNode != NULL)
			node.LHNode.parent = node.parent;
		delete node;
	}*/


	void printQ(Node* root) {
		cout<<root->heldItem->name << endl;
		if (root->LHNode != NULL) {
			cout << root->LHNode->heldItem->name << endl;
			printQ(root->LHNode);
		}
		if (root->RHNode != NULL) {
			cout << root->RHNode->heldItem->name << endl;
			printQ(root->RHNode);
		}
		else
			return;
	}

};

int main() {

	int count, numGems, bagSize;

	//file in
	ifstream fileIn;
	fileIn.open("TestFile.txt");
	fileIn >> numGems >> bagSize;

	// create Loot objects for each item
	Loot* insert = new Loot[numGems];
	Loot rootInsert;
	Node * node = new Node[numGems];
	PQ Q;
	cout << "1" << endl;
	Node * rootNode = new Node;
	//rootNode->parent = NULL;

	string n;
	int w, v;
	cout << "2" << endl;
	fileIn >> w >> v;
	rootInsert.name = n;
	rootInsert.weight = w;
	rootInsert.value = v;
	rootInsert.ratio = findRatio(w, v);
	cout << "2a" << endl;
	rootNode->heldItem = &rootInsert;
	cout << "3" << endl;
	Q.root = rootNode;
	cout << "we are right before the for loop" << endl;
	for (int i = 1; i < numGems; i++) {
		fileIn >> n;
		fileIn >> w >> v;
		insert[i].name = n;
		insert[i].weight = w;
		insert[i].value = v;
		insert[i].ratio = findRatio(w, v);

		cout << "we are right IN the for loop" << endl;

		node[i].heldItem = &insert[i];
		cout << "we are right IN the for loop Still" << endl;
		Q.enqueue(node[i], rootNode);

		//cout << test[i].name << endl;
	}

	cout << "we are after the for loop" << endl;
	Q.printQ(rootNode);
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

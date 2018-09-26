// GreedyKnapSack.cpp
// Allen Burris
// Algorithms Poject 1:
// Greedy KnapSack - Node Class
//

#include <iostream>
#include <string>
using namespace std;

class Node {

public:
	Loot* heldItem;
	Node* LHNode;
	Node* RHNode;
	Node* parent;
};
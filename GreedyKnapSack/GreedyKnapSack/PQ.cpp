// GreedyKnapSack.cpp
// Allen Burris
// Algorithms Poject 1:
// Greedy KnapSack - Priority Queue
//

#include <iostream>
#include <string>
using namespace std;

class PQ {

};

int PQ::Dequeue(Node * node, Node * parent)
{
	Node derpNode = node;
	while (node->RHNode) {
		parent = node;
		node = node.RHNode;
	}
	delete derpNode;
}

void PQ::Enqueue(double newRatio, Node * node)
{
	while (true) {
		if (newRatio < node->heldItem->ratio) {
			if (node->LHNode) {
				node = node->LHNode;
			}
			else {
				node->LHNode = new Node((heldItem.ration=newRatio));
				return;
			}
		}
		else {
			if (node->RHNode) {
				node = node->RHNode;
			}
			else {
				node->RHNode = new Node(value);
				return;
			}
		}
	}
}
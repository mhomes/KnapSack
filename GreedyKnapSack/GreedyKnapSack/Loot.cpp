// GreedyKnapSack.cpp
// Allen Burris
// Algorithms Poject 1:
// Greedy KnapSack - Loot Item Class
//

#include <iostream>
#include <cstring>
using namespace std;

class Loot {

public:

	string name = "GOD DAMN";
	int weight;
	int value;
	double ratio;

	void printName() {
		cout << name << endl;
	}

};

int main() {

	Loot test;
	test.value = 10l;
	test.printName();
	return 0;
}

/*	struct Loot {

		String name;
		int weight;
		int value;
		double ratio;
	}*/
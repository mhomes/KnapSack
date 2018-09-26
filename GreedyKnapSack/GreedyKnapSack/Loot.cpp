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

	static string name;
	static int weight;
	static int value;
	static double ratio;

	Loot(string n, int w, int v) {
		name = n;
		weight = w;
		value = v;
		ratio = findRatio(w, v);
	}

	void printName() {
		cout << name << endl;
	}

private:

	double findRatio(int w, int v) {
		return (w / v);
	}

};

/*	struct Loot {

		String name;
		int weight;
		int value;
		double ratio;
	}*/
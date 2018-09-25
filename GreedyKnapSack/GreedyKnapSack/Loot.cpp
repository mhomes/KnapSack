// GreedyKnapSack.cpp
// Allen Burris
// Algorithms Poject 1:
// Greedy KnapSack - Loot Item Class
//

#include "pch.h"
#include <iostream>
#include <cstring>
using namespace std;

struct Loot {

	String name;
	int weight;
	int value;
	double ratio;


	Loot(String n, int w, int v) {
		name = n;
		weight = w;
		value = n;
		ratio = computeRatio(w, v);
	}

	private double computeRatio(int w, int v) {
		return (w / v);
	}
};
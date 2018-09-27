// GreedyKnapSack.cpp
// Authors: Allen Burris, Matthew Homes
// Algorithms Poject 1:
// Greedy KnapSack - Test File Creator
//Finished: 9-25-18

#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

int random(int max);

int main() {

	int NumGems, BagSize = 0;

	cout << "Enter the number of items in the list followed by the" <<
		"\nsize of the bag." << endl;
		cin >> NumGems >> BagSize;

	ofstream outputFile;
	outputFile.open("TestFile.txt");
	
	outputFile << NumGems << " " << BagSize << endl;
	for (int i = 0; i < NumGems; i++) {
		int value = random(NumGems);
		int weight = random(NumGems);

		outputFile << i << " " << weight << " " << value << endl;
	}

	return 0;
}

int random(int max) {
	int randomnum = 1 + rand() % (max *2);
	return(randomnum);
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

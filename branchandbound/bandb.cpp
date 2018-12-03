#include <queue>
#include <fstream>
#include <iostream>
using namespace std;

class loot {
public:

	int value, weight;
	double ratio;
	string name;

	loot(string n, int v, int w) {
		name = n;
		value = v;
		weight = w;
		ratio = v / w;
	}
	void print() {
		cout << name << " " << value << " " << weight << " " /*<< ratio */ << endl;
	}
};

struct node {
	int level;
	int profit;
	int weight;
	int bound;
	int included;
	int yes[];
};

void merge(loot **a, int l, int m, int r) {
	int i, j, k;
	int sizeL = m - l + 1;
	int sizeR = r - m;
	loot ** L = new loot *[sizeL];
	loot ** R = new loot *[sizeR];

	for (i = 0; i < sizeL; i++)
		L[i] = a[l + i];
	for (j = 0; j < sizeR; j++)
		R[j] = a[m + 1 + j];

	i = 0;
	j = 0;
	k = l;
	while (i < sizeL && j < sizeR) {
		if (L[i]->ratio >= R[j]->ratio) {
			a[k] = L[i];
			i++;
		}
		else {
			a[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < sizeL) {
		a[k] = L[i];
		i++;
		k++;
	}
	while (j < sizeR) {
		a[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(loot **a, int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;

		mergeSort(a, l, m);
		mergeSort(a, m + 1, r);
		merge(a, l, m, r);
	}
}

int bound(node gem, int itemNumber, int maxWeight, vector<int> pVa, vector<int> wVa){
	int j = 0, k = 0;
	int totweight = 0;
	int result = 0;

	if (gem.weight >= maxWeight){
		return 0;
	}
	else {
		result = gem.profit;
		j = gem.level + 1;
		totweight = gem.weight;

		while ((j < itemNumber) && (totweight + wVa[j] <= maxWeight)){
			totweight = totweight + wVa[j];
			result = result + pVa[j];
			j++;
		}

		k = j;

		if (k < itemNumber){
			result = result + (maxWeight - totweight) * pVa[k] / wVa[k];
		}
		return result;
	}
}

node knapsack(int itemNumber, int gemValue[], int gemWeight[], int maxWeight) {
	queue<node> Q;
	node gem, v;
	vector<int> pV;
	vector<int> wV;
	Q.empty();

	for (int i = 0; i < itemNumber; i++){
		pV.push_back(gemValue[i]);
		wV.push_back(gemWeight[i]);
	}

	v.level = -1;
	v.profit = 0;
	v.weight = 0;

	int maxProfit = 0;

	//v.bound = bound(v, itemNumber, maxWeight, pV, wV);
	Q.push(v);
	int i = 0;
	while (!Q.empty()){
		v = Q.front();
		Q.pop();

		if (v.level == -1){
			gem.level = 0;
		}
		else if (v.level != (itemNumber - 1)){
			gem.level = v.level + 1;
		}

		gem.weight = v.weight + gemWeight[gem.level];
		gem.profit = v.profit + gemValue[gem.level];

		gem.bound = bound(gem, itemNumber, maxWeight, pV, wV);

		if (gem.weight <= maxWeight && gem.profit > maxProfit){
			maxProfit = gem.profit;
			gem.yes[i] = gem.level;
			i++;
			gem.included = i;
		}
		if (gem.bound > maxProfit){
			Q.push(gem);
		}

		gem.weight = v.weight;
		gem.profit = v.profit;

		gem.bound = bound(gem, itemNumber, maxWeight, pV, wV);

		if (gem.bound > maxProfit) {
			Q.push(gem);
		}
	}
	return gem;
}

int main() {

	int n, bagSize;
	string file;

	int maxProfit;
	int itemNumber;
	int maxWeight;

	//file in
	ifstream fileIn;
	fileIn.open("TestFile.txt");
	fileIn >> itemNumber;
	fileIn >> maxWeight;

	int gemWeight[itemNumber];
	int gemValue[itemNumber];

	loot ** Loot = new loot *[n + 1];
	Loot[0] = NULL;

	for (int x = 1; x < n + 1; x++) {
		string n;
		int v, w;
		fileIn >> n >> v >> w;
		Loot[x] = new loot(n, v, w);
	}
	fileIn.close();

	mergeSort(Loot, 1, itemNumber);

	for (int i = 1; i <= itemNumber; i++) {
		gemWeight[i] = Loot[i]->weight;
		gemValue[i] = Loot[i]->value;
	}

	mergeSort(Loot, 1, n);

	node end = knapsack(itemNumber, gemValue, gemWeight, maxWeight);

	cout << endl;

	int totalweight = 0;
	int totalprofit = 0;

	for (int i = 1; i < end.included; i++) {
		totalweight += Loot[end.yes[i]]->weight;
		totalprofit += Loot[end.yes[i]]->value;
	}

	cout << end.included -1 << endl;
	cout << totalweight << endl;
	cout << totalprofit << endl;
	for (int i = 1; i < end.included; i++) {
		Loot[end.yes[i]]->print();
	}

	return 0;
}
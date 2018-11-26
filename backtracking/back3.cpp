//Sam Badovinac
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class item{
	public:
	
	int value, weight;
    double keyVal;
	string name;
	
	item(string n, int v, int w) {
		name = n;
		value = v;
		weight = w;
		keyVal = v/w;
	}

};

int maxprofit = 0;
int numbest = 0;
int totalWeight;

int *bestset;
int *include;

void merge(item **a, int l, int m, int r) { 
    int i, j, k; 
    int sizeL = m - l + 1; 
    int sizeR =  r - m; 
    item ** L = new item *[sizeL]; //left half array
	item ** R = new item *[sizeR]; //right half array
  
    for (i = 0; i < sizeL; i++) 
        L[i] = a[l + i]; 
    for (j = 0; j < sizeR; j++) 
        R[j] = a[m + 1+ j]; 
  
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < sizeL && j < sizeR){  //do the merge 
        if (L[i]->keyVal >= R[j]->keyVal){ 
            a[k] = L[i]; 
            i++; 
        } 
        else{ 
            a[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < sizeL){ 
        a[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < sizeR){ //toss the remaining items into that young array
        a[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  

void mergeSort(item **a, int l, int r) { 
    if (l < r){ 
        int m = l+(r-l)/2; 
  
        mergeSort(a, l, m); 
        mergeSort(a, m+1, r); 
  
        merge(a, l, m, r); 
    } 
} 

bool promising(int i, int cap, int weight, int profit, item **Item, int n){
    int j, k, totweight; //j and k are indexes of arrays
    double bound;
    if(weight >= cap){
        return false;
    }
    else{
        //cout<< "promise test" <<endl;
        j = i+1;
        bound = profit;
        totweight = weight;

        while(j <= n && totweight + Item[j]->weight <= cap){
            totweight = totweight + Item[j]->weight;
            bound =  bound + Item[j]->value;
            j++;
        } 
        k = j;
        if(k <= n){
            bound = bound + (cap - totweight) * Item[k]->keyVal;
        }
        return bound > maxprofit;
    }
}

void knapsack(int i, int cap, int weight, int profit, item ** Item, int n){

	if(weight <= cap && profit > maxprofit){
        //cout<< "Test" <<endl;
		maxprofit = profit;
		numbest = i;
		bestset[i] = include[i];
        //cout << include[i] << endl;
	}

	if(promising(i, cap, weight, profit, Item, n) == true){
            include[i+1] = 1;
            //cout<<include[i+1]<<endl;
            knapsack(i+1, cap, weight + Item[i+1]->weight, profit + Item[i+1]->value, Item, n);
       
            //cout<<"Test 2"<<endl;
            include[i+1] = 0;
            //cout<< include[i+1] <<endl;
            knapsack(i+1, cap, weight, profit, Item, n);
        
	}
}


int main(){
    int n, cap;
	string file;

	
	//cout<<"Enter input file name: "<<endl;
	//cin>>file; file.c_str()

	ifstream infile;
	infile.open("TestFile.txt");
	infile >> n; //number of items in the list
	infile >> cap; //capacity of the knapsack

    bestset = new int[n];
    include = new int[n];

	item ** Item = new item *[n+1];
	//int include[n+1]; //keeps track of the items selected

	Item[0] = NULL;

	for(int g=1; g<n+1; g++) //fills item array
	{
		string n;
		int v, w;
		infile >> n >> v >> w;
		Item[g] = new item(n, v, w);
	}
	
	infile.close();

 

	mergeSort(Item, 1, n); //sort the item array by their raito in nonincreasing order

    knapsack(0, cap, 0, 0, Item, n);



    for(int i=1; i<n+1; i++){
            if(bestset[i] == 1){
                totalWeight = totalWeight + Item[i]->weight;
            }
        }

    

    cout << numbest << endl;
    cout<< totalWeight << endl;
    cout<< maxprofit << endl;
    for(int g=1; g<n+1; g++){
        if(bestset[g] == 1){
            cout << Item[g]->name << " " << Item[g]->value << " " << Item[g]->weight << endl;
        }
    }

    delete [] bestSet;
    delete [] include;

	return 0;
}

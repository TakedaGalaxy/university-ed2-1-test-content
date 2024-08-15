#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int* generateRoandomVectorInt(unsigned int n, int min, int max) {
    int *p = (int*)malloc(n * sizeof(int));
    
		if (p == NULL) {
        printf("Erro ao alocar memória!\n");
        return NULL;
    }
    
    srand(time(NULL));
    
    for (int i = 0; i < n; i++) 
        p[i] =  (rand() % (max - min + 1)) + min;
    
    return p; 
}

template <typename T>
void printVector(T *vector, unsigned int n){
	for(int i = 0; i < n; i++)
		std::cout << vector[i] <<" "; 
		
	std::cout << '\n'; 
}

template <typename T>
unsigned int findMaxIndex(T *vector, int n){
    unsigned int maxIndex = 0;
		T max = vector[0];
    for(int i = 1; i < n; i++)
        if(max < vector[i])
            {
							max = vector[i];
							maxIndex = i;
						}
    
    return maxIndex;
}	

template <typename T>
void swap(T *vector, unsigned int iA, unsigned int iB){
	T value = vector[iA];
	vector[iA] = vector[iB];
	vector[iB] = value;
}

// ### Selection Sort ###
template <typename T>
void selectionSort(T *vector, unsigned int n){
  for(int i = n-1; i >= 0; i--)
		swap(vector, i, findMaxIndex(vector, i+1));
}
// ### END ###

// ### Boubble Sort ###
template <typename T>
void boubbleSort(T *vector, unsigned int n){
	for(int j = n; j > 0; j--){
		for(int i = 0; i < j-1; i++){
			if(vector[i] > vector[i+1])
				swap(vector,i, i+1);
		}
	}
}
// ### END ###

// ### Insert Sort ###
template <typename T>
void insert(T *vector, unsigned int k){
	int i = k-1;
	T kValue = vector[k];
	
	while(i >= 0 &&  vector[i] > kValue){
		vector[i+1] = vector[i];
		i--;
	}
	
	vector[i + 1] = kValue;
}

template <typename T>
void insertSort(T *vector, unsigned int n){
	for(int i = 1; i < n; i++)
		insert<T>(vector,i);
}
// ### END ###

// ### Merge sort ###
void merge(int *vector, unsigned int p, unsigned int q, unsigned int r){
	unsigned int sizeVA = q - p + 1;
	int *vA = new int[sizeVA + 1];
	
	for(int i = 0; i < sizeVA; i++)
		vA[i] = vector[p+i];
	
	vA[sizeVA] = INT_MAX;
	
	unsigned int sizeVB = r - q;
	int *vB = new int[sizeVB + 1];
	
	for(int i = 0; i < sizeVB; i++)
		vB[i] = vector[q+1+i];
	
	vB[sizeVB] = INT_MAX;
	
	int i = 0, iA = 0, iB = 0;
	
	for(int i = p; i <= r; i++){
		if(vA[iA] <= vB[iB]){
			vector[i] = vA[iA];
			iA++; 
		}
		else{
			vector[i] = vB[iB];
			iB++;
		}
	}
	
	delete[] vA;
	delete[] vB;
}

void mergeSort(int *vector, unsigned int e, unsigned int d){
	if(e < d){
		int m = (e + d)/2;
		mergeSort(vector, e, m);
		mergeSort(vector, m + 1, d);
		merge(vector,e,m,d);
	}
}
// ### END ###

// ### Quick Sort ###
int partition(int *vector, int p,  int r){
	int x = vector[r];
	int i = p - 1;

	for(int j = p; j < r; j++){
		if(vector[j] <= x){
			i++;
			swap<int>(vector, i,j);
		}
	}
	
	swap<int>(vector, i+1, r);
	return i + 1;
}

void quickSort(int *vector, int e, int d){
	if(e < d){
		int m = partition(vector, e,d);
		quickSort(vector, e, m - 1);
		quickSort(vector, m + 1, d);
	}
}
// ### END ###

int main() {
    int *vector = generateRoandomVectorInt(20, 0, 50);
    
    printVector<int>(vector, 20);
    
    quickSort(vector, 0,19);
    	
    printVector<int>(vector, 20);
    	
    return 0;
}


//John Darren De Lara - x00072126  Lab3

/*
Reference:
https://www.youtube.com/watch?v=COk73cpQbFQ
https://www.youtube.com/watch?v=TzeBrDU-JaY
http://www.codebind.com/cpp-tutorial/cpp-example-merge-sort-algorithm/
https://stackoverflow.com/questions/6131247/alphabetizing-sorting-vector-of-pointers
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Person.h"

using namespace std;

void Merge(int leftArr[], int rightArr[], int arr[], int leftSize, int rightSize) {
	//int numLA = sizeof(leftArr) / sizeof(leftArr[0]);			//stores the number of elemenets of leftarray
	//int numRA = sizeof(rightArr) / sizeof(rightArr[0]);			//stores the number of elemenets of rightarray

	int numLA = leftSize;
	int numRA = rightSize;
	int i = 0;
	int j = 0;
	int k = 0;

	cout << "left " << numLA << endl;
	cout << "right " << numRA << endl;

	while (i < numLA && j < numRA) {
		if (leftArr[i] <= rightArr[j]) {
			arr[k] = leftArr[i];
			i++;
		}
		else {
			arr[k] = rightArr[j];
			j++;
		}
		k++;
	}

	while (i < numLA) {
		arr[k] = leftArr[i];
		i++;
		k++;
	}

	while (j < numRA) {
		arr[k] = rightArr[j];
		j++;
		k++;
	}
}
//7, 2, 5,/ 2,1, 9, 3,    7
void MergeSort(int array[], int num) {
	//int num = sizeof(array) / sizeof(array[0]);		//stores the number of elemenets of array

	cout << "FUll " << num << endl;

	if (num < 2) return;
	
		int mid = num / 2;
		int *lhs = new int[mid];
		int *rhs = new int[num - mid];

		for (int i = 0; i < mid; i++) {
			lhs[i] = array[i];
		}

		for (int i = mid; i <= num; i++) {
			rhs[i - mid] = array[i];
		}

		MergeSort(lhs, mid);					//recursive call for the left sublist
		MergeSort(rhs, (num - mid));			//recursive call for the right sublist
		Merge(lhs, rhs, array, mid, (num - mid));
	
}

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
/*void Merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	//create temp arrays
	int *L = new int[n1];
	int *R = new int[n2];

	//Copy data to temp arrays L[] and R[]
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	//Merge the temp arrays back into arr[l..r]
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray

	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	//Copy the remaining elements of L[], if there are any
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	//Copy the remaining elements of R[], if there are any
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

//l is for left index and r is right index of the
//sub-array of arr to be sorted
void MergeSort(int arr[], int l, int r) {
	if (l < r)
	{
		// Same as (l+r)/2, but avoids overflow for
		// large l and h
		int m = l + (r - l) / 2;

		// Sort first and second halves
		MergeSort(arr, l, m);
		MergeSort(arr, m + 1, r);

		Merge(arr, l, m, r);
	}
}*/

//quicksort template
template <class T>
int QuickSortDivide(T *array, int firstIndex, int lastIndex) {
	T pivot = array[lastIndex];
	int i = firstIndex - 1;

	for (int j = firstIndex; j < lastIndex; j++) {
		if (array[j] <= pivot) {
			i++;

			T temp;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;

			//swap(array[j], array[i]);
		}
	}

	T temp = array[i + 1];
	array[i + 1] = array[lastIndex];
	array[lastIndex] = temp;
	//swap(array[i], array[lastIndex]);

	return i + 1;
}

template <class T>
void QuickSort(T *array, int firstIndex, int lastIndex) {
	if (firstIndex < lastIndex) {
		int p = QuickSortDivide(array, firstIndex, lastIndex);
		//cout << "" << p << endl;

		//recursively sort elements before and after partition
		QuickSort(array, firstIndex, p - 1);
		QuickSort(array, p + 1, lastIndex);
	}
}

int main() {

	int sampleArr[] = { 7, 2, 5, 2, 1, 9, 3, 3 };
	int n = sizeof(sampleArr) / sizeof(sampleArr[0]);

	cout << "Before the merge sort" << endl;
	for (int i = 0; i < n; i++) {
		cout << sampleArr[i] << endl;
	}

	cout << " " << endl;
	//MergeSort(sampleArr, 0, n - 1);
	MergeSort(sampleArr, n);

	cout << "After the merge sort" << endl;

	for (int i = 0; i < n; i++) {
		cout << sampleArr[i] << endl;
	}

	cout << " " << endl;

	int sampleArr1[] = { 7, 2, 5, 2, 1, 9, 3, 3, 4 };
	int n1 = sizeof(sampleArr1) / sizeof(sampleArr1[0]);

	cout << "********************************************" << endl;
	cout << "Before the quick sort" << endl;
	for (int i = 0; i < n1; i++) {
		cout << sampleArr1[i] << endl;
	}

	cout << " " << endl;
	QuickSort(sampleArr1, 0, n1 - 1);

	cout << "After the quick sort" << endl;

	for (int i = 0; i < n1; i++) {
		cout << sampleArr1[i] << endl;
	}


	//vector<Person*> personVector;

	//personVector.push_back(new Person("Jd"));
	//personVector.push_back(new Person("Aj"));

	/*typedef Person *p;
	
	p *ps = new p[3];

	//Person p1("john");		//create and initialise person object

	ps[0] = new Person("john");
	ps[1] = new Person("ahn");
	ps[2] = new Person("mat");

	//p("car");			//create and initialise person object
	//p("mat");			//create and initialise person object

	for (int i = 0; i < 3; i++) {
		cout << ps[i]->getName() << endl;
	}

	QuickSort(ps, 0, 2);

	for (int i = 0; i < 3; i++) {
		cout << ps[i]->getName() << endl;
	}*/

	string example[] = { "john", "car", "johm" };
	int examSize = sizeof(example) / sizeof(example[0]);

	/*for (int i = 0; i < personVector.size(); i++) {
		cout << personVector[i]->getName() << endl;
	}

	cout << "After sort: " << endl;

	QuickSort(personVector, 0, personVector.size() - 1);

	for (int i = 0; i < personVector.size(); i++) {
		cout << personVector[i]->getName() << endl;
	}*/

	cout << "      " << endl;

	for (int i = 0; i < examSize; i++) {
		cout << example[i] << endl;
	}

	QuickSort(example, 0, examSize - 1);

	for (int i = 0; i < examSize; i++) {
		cout << example[i] << endl;
	}


	system("pause");
	return 0;
}
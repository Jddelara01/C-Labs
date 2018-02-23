//John Darren De Lara - x00072126   LAB2

/*
Reference: https://www.ibm.com/support/knowledgecenter/en/SSLTBW_2.3.0/com.ibm.zos.v2r3.cbclx01/cplr233.htm
Reference: http://www.cplusplus.com/forum/beginner/146361/
Reference: https://www.youtube.com/watch?v=COk73cpQbFQ&index=7&list=PL2_aWCzGMAwKedT2KfDMB9YA5DgASZb3U
*/

#include <iostream>
#include <string>

using namespace std;

//swap by reference
template <class T> void Swap(T &a, T &b) {
	T result;

	result = a;
	a = b;
	b = result;
}

//swap by address
template <class T> void swapAddres(T *a, T *b) {
	T result;

	result = *a;
	*a = *b;
	*b = result;
}

//multiples template
//x = 1, n =3
template <class T> void Multiples(T &sum, T x , int n) {

	sum = 1;
	//1+0+1+2+
	for (int i = 0; i <= n; i++) {
		sum += i * x;
	}
}

//init template
template <class T1, class T2> T1 Init(T1 num1, T1 num2, T2 &start) {
	start = 1;

	return num1 + num2;
}

//quicksort template
template <class T> int Partition(T *array, int firstIndex, int lastIndex) {
	int pivot = array[lastIndex];
	int i = firstIndex - 1;

	for (int j = firstIndex; j < lastIndex; j++) {
		if (array[j] <= pivot) {
			i++;

			int temp;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}

	int temp = array[i + 1];
	array[i + 1] = array[lastIndex];
	array[lastIndex] = temp;

	return i + 1;
}

template<class T> void QuickSort(T* array, int firstIndex, int lastIndex) {
	if (firstIndex < lastIndex) {
		int p = Partition(array, firstIndex, lastIndex);
		//cout << "" << p << endl;

		//recursively sort elements before and after partition
		QuickSort(array, firstIndex, p - 1);
		QuickSort(array, p + 1, lastIndex);
	}
}

int main() {

	//Testing the swap function with float and passing by reference
	cout << "Q1.(A) Swap by reference: " << endl;
	float first = 54.2;
	float second = 20.15;
	cout << "Before swap:" << endl;
	cout << first << ", " << second << endl;
	cout << "*************************************************" << endl;

	Swap(first, second);
	cout << "After swap:" << endl;
	cout << first << ", " << second << endl;

	cout << " " << endl;
	//Testing the swap function with integer and passing by address
	cout << "Q1.(B)Swap by address: " << endl;
	int num1 = 1;
	int num2 = 5;

	cout << "Before address num1: " << num1 << endl;
	cout << "Before address num2: " << num2 << endl;
	cout << "*************************************************" << endl;

	swapAddres(&num1, &num2);
	cout << "After address num1: " << num1 << endl;
	cout << "After address num2: " << num2 << endl;

	cout << " " << endl;
	//Testing multiples template (q2)
	cout << "Q2. Multiples: " << endl;
	int s = 20;
	int j = 15;
	Multiples(s, 1, 3);
	Multiples(j, 2, 3);
	cout << "x = 1, n = 3, sum = " << s << endl;
	cout << "x = 2, n = 3, sum = " << j << endl;

	cout << " " << endl;
	//Testing q3. Init function
	double start = 2.2;
	//Init(2, 3, start);
	cout << "Q3. Init function: num1 = 2, num2 = 3, start = 5" << endl;

	cout << "Value of Init: " << Init(2, 3, start) << endl;
	cout << "start = " << start <<  endl;

	cout << " " << endl;
	//Testing q4. Quicksort
	cout << "Q4. Quicksort template:" << endl;

	int arrayNum[8] = { 5, 4, 10, 25, 2, 19, 24, 15 };

	cout << "Before Quicksort: " << endl;
	for (int i = 0; i < 8; i++) {
		cout << arrayNum[i] << endl;
	}


	QuickSort(arrayNum, 0, 7);

	cout << "After Quicksort: " << endl;
	for (int i = 0; i < 8; i++) {
		cout << arrayNum[i] << endl;
	}

	system("pause");
}
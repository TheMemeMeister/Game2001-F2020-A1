#include<iostream>
#include "BaseArray.h"
#include"OrderedArray.h"
#include "UnorderedArray.h"

using namespace std;

int main(int ars, char* argc)
{
	UnorderedArray<int> Testarray(3);
	Testarray.push(7);
	Testarray.push(3);
	Testarray.push(52);
	Testarray.push(5);
	Testarray.push(1);
	Testarray.push(7);

	cout << "Unordered array elemeents : " << endl;
	for (int i = 0; i < Testarray.GetSize(); i++) {
		cout << Testarray[i] << " ";
	}
	cout << endl;
	cout << endl;
	Testarray[3] = 69;
	cout << "I've made element at position 3 = 69" << endl;
	cout << endl;
	cout << endl;
	cout << "Unordered array elements : " << endl;
	for (int i = 0; i < Testarray.GetSize(); i++) {
		cout << Testarray[i] << " ";
	}
	cout << endl;
	cout << endl;
	Testarray.pop();
	cout << "I've poped my array" << endl;
	cout << "Unordered array elements : " << endl;
	for (int i = 0; i < Testarray.GetSize(); i++) {
		cout << Testarray[i] << " ";
	}
	cout << endl;
	cout << endl;
	Testarray.remove(3);
	cout << "I've removed element 3 of the array" << endl;
	cout << "Unordered array elements : " << endl;
	for (int i = 0; i < Testarray.GetSize(); i++) {
		cout << Testarray[i] << " ";
	}
	cout << endl;
	cout << endl;
	Testarray.search(52);
	cout << "Searched for element 52 in my array" << endl;
	cout << Testarray.search(52) << endl;
	cout << endl;
	cout << endl;
	OrderedArray<int> Testarray2(3);
	Testarray2.push(7);
	Testarray2.push(3);
	Testarray2.push(52);
	Testarray2.push(5);
	Testarray2.push(1);
	Testarray2.push(7);
	cout << "Ordered array elemeents : " << endl;
	for (int i = 0; i < Testarray2.GetSize(); i++) {
		cout << Testarray2[i] << " ";
	}
	cout << endl;
	cout << endl;
	cout << "I am now pushing more elemenets into array to test expand" << endl;
	Testarray2.push(57);
	Testarray2.push(63);
	Testarray2.push(8);
	Testarray2.push(10);
	Testarray2.push(14);
	cout << "Ordered array elemeents : " << endl;
	for (int i = 0; i < Testarray2.GetSize(); i++) {
		cout << Testarray2[i] << " ";
	}
	cout << endl;
	cout << "New array size is " << Testarray2.GetSize() << endl;
	cout << endl;
	cout << endl;
	cout << "I am going to push an int (10) already in the array to the array " << endl;
	Testarray2.push(10);
	cout << "Ordered array elemeents : " << endl;
	for (int i = 0; i < Testarray2.GetSize(); i++) {
		cout << Testarray2[i] << " ";
	}
	cout << "Notice there is only 1 10 in the above array" << endl;
	cout << endl;
	cout << endl;

}
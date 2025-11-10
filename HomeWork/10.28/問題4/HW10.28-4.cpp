#include <iostream>
using namespace std;

void swap_ptr(char*& pStr1, char*& pStr2)
{
	char* swap = pStr1;
	pStr1 = pStr2;
	pStr2 = swap;
}

int main()
{
	char str1[] = "abcd";
	char str2[] = "ABCD";

	char* pStr1 = str1;
	char* pStr2 = str2;

	// swap‘O
	cout << pStr1 << endl; 
	cout << pStr2 << endl; 

	swap_ptr(pStr1, pStr2);

	// swapŒã
	cout << pStr1 << endl; 
	cout << pStr2 << endl; 
}

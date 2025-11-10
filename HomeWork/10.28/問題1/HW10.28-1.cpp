#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

void swap_string(char* s1, char* s2)
{
	char swap[32];
	strcpy(swap, s1);
	strcpy(s1, s2);
	strcpy(s2, swap);

}

int main()
{
	char arr1[32];
	char arr2[32];
	cout << "> " << flush;
	cin >> arr1;
	cout << "> " << flush;
	cin >> arr2;
	cout << "“ü‚ê‘Ö‚¦‘O arr1 : " << arr1 << "Aarr2 : " << arr2 << endl;
	swap_string(arr1, arr2);
	cout << "“ü‚ê‘Ö‚¦Œã arr1 : " << arr1 << "Aarr2 : " << arr2 << endl;
}

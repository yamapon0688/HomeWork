#include <iostream>
#include "calc.h"
using namespace std;

int main()
{
	int a, b;
	cout << "> " << flush;
	cin >> a;
	cout << "> " << flush;
	cin >> b;
	cout << sum(a, b) << endl;
}

#include <iostream>
using namespace std;

static int multi(int a, int b);

int main()
{
	int a, b;
	cout << "> " << flush;
	cin >> a;
	cout << "> " << flush;
	cin >> b;

	cout << multi(a, b) << endl;
}

static int multi(int a, int b)
{
	return a * b;
}
*/
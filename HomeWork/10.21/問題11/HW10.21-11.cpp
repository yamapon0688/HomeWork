#include <iostream>
using namespace std;

int main()
{
	int* a;
	int n;
	int total = 0;
	int ave = 0;

	cout << "�l�� > " << flush;
	cin >> n;
	a = new int[n];

	if (!(a == nullptr))
	{
		for (int i = 0; i < n; i++)
		{
			cout << "�_���i" << i + 1 << "�l�ځj>" << flush;
			cin >> a[i];
		}
		for (int i = 0; i < n; i++)
		{
			total += a[i];
		}
		ave = total / n;
		cout << total << endl;
		cout << ave << endl;
		delete[] a;
	}
}
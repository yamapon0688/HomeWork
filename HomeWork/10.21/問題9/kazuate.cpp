#include <iostream>
using namespace std;

void kazuate()
{
	int a;
	int count = 1;
	srand((unsigned int)time(NULL));
	int r = rand() % 100 + 1;
	cout << r << endl;

	do
	{
		cout << "1 �` 100 > " << flush;
		cin >> a;
		if (r < a)
		{
			cout << "���͂��ꂽ�l��菬����" << endl;
			count++;
		}
		if (r > a)
		{
			cout << "���͂��ꂽ�l���傫��" << endl;
			count++;
		}
	} while (r != a);
	cout << "�񐔁F" << count << endl;

}
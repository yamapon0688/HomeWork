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
		cout << "1 ` 100 > " << flush;
		cin >> a;
		if (r < a)
		{
			cout << "“ü—Í‚³‚ê‚½’l‚æ‚è¬‚³‚¢" << endl;
			count++;
		}
		if (r > a)
		{
			cout << "“ü—Í‚³‚ê‚½’l‚æ‚è‘å‚«‚¢" << endl;
			count++;
		}
	} while (r != a);
	cout << "‰ñ”F" << count << endl;

}
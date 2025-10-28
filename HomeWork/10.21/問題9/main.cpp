#include <iostream>
#include "janken.h"
#include "kazuate.h"
using namespace std;

enum Game
{
	JANKEN = 1,
	KAZUATE = 2,
	END = 3
};

int main()
{
	while (true)
	{
		int a;
		cout << "‚PF‚¶‚á‚ñ‚¯‚ñƒQ[ƒ€A‚QF”“–‚ÄƒQ[ƒ€@‚RI—¹ > " << flush;
		cin >> a;

		switch (a)
		{
		case JANKEN: janken();
			break;
		case KAZUATE: kazuate();
			break;
		case END:
			break;
		}
		if (a == END)
		{
			break;
		}
	}
}
*/
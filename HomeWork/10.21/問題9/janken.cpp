#include <iostream>
#include "janken.h"
using namespace std;

enum Check
{
	RESULT_P1_WIN = 0,
	RESULT_P2_WIN = 1,
	RESULT_DRAW = 2,
	ERROR = -1
};

static Check check(char a, char b)
{
	if ((a == 'g' && b == 't') || (a == 't' && b == 'p') || (a == 'p' && b == 'g'))
	{
		return RESULT_P1_WIN;
	}
	else if ((a == 'g' && b == 'p') || (a == 't' && b == 'g') || (a == 'p' && b == 't'))
	{
		return RESULT_P2_WIN;
	}
	else if (a == b)
	{
		return RESULT_DRAW;
	}
	else
	{
		return ERROR;
	}
}
void janken()
{
	char p1;
	char p2;
	cout << "Player1(g グー、t チョキ、p パー、e 終了) > " << flush;
	cin >> p1;
	if (p1 == 'e')
	{
		cout << "終了" << endl;
		return;
	}
	cout << "Player2(g グー、t チョキ、p パー、e 終了) > " << flush;
	cin >> p2;
	if (p2 == 'e')
	{
		cout << "終了" << endl;
		return;
	}
	Check a = check(p1, p2);
	if (a == ERROR)
	{
		cout << "エラー" << endl;
		return;
	}
	const char* result[] =
	{
		"player1の勝ち",
		"player2の勝ち",
		"引き分け"
	};
	cout << result[a] << endl << endl;;
}
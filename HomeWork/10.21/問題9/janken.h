#pragma once
enum Check
{
	RESULT_P1_WIN = 0,
	RESULT_P2_WIN = 1,
	RESULT_DRAW = 2,
	ERROR = -1
};
Check check(char a, char b);
void janken();
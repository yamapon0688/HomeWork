#include <iostream>
using namespace std;

double str2double(const char* s)
{
	double result = 0.0;
	double digit = 0.1;
	bool DOT = false;
	
	for (int i = 0; s[i] != '\0'; i++)
	{
		char str = s[i];
		if (!(str >= '0' && str <= '9'))
		{
			if (str == '.' && DOT == false)
			{
				DOT = true;
				continue;
			}
			return 0.0;
		}
		double convert = str - '0';
		if (!(DOT))
		{
			result = result * 10.0 + convert;
		}
		else
		{
			result += convert * digit;
			digit *= 0.1;
		}
	}
	return result;
}

int main()
{
	char strDouble[32];
	cout << "> " << flush;
	cin >> strDouble;
	cout << str2double(strDouble) << endl;
}
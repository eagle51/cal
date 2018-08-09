#include <iostream>
#include <string>
#include "calculator.h"
using namespace std;

int main()
{
	string m_exp;
	getline(cin, m_exp);
	Calculator c;
	cout << c.getResult(m_exp) << endl;
	system("pause");
	return 0;
}
#include "calculator.h"
double& Calculator::getResult(string exp) 
{
	m_Polish.clear();
	LinkStack<char> s1, s2;
	s1.push('#');         //以#号作为标记 
	char temp;
	for (size_t i = 0; i < exp.length(); i++) {                 //利用两个堆栈生成逆波兰式 
		if (exp[i] >= '0' && exp[i] <= '9') {
			s2.push(exp[i]);
		}
		else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
			s2.push('#');
			temp = s1.top();
			if (temp == '#' || (temp == '+' || temp == '-') && (exp[i] == '*' || exp[i] == '/')) {
				s1.push(exp[i]);
			}
			else {
				while (!(temp == '#' || temp == '(' || (temp == '+' || temp == '-') && (exp[i] == '*' || exp[i] == '/'))) {
					s2.push(temp);
					s1.pop();
					temp = s1.top();
				}
				s1.push(exp[i]);
			}
		}
		else if (exp[i] == ')' || exp[i] == '(') {
			if (exp[i] == '(') {
				s1.push(exp[i]);
			}
			else {
				temp = s1.top();
				while (temp != '(') {
					s2.push(temp);
					s1.pop();
					temp = s1.top();
				}
				s1.pop();
			}
		}
	}
	while (s1.top() != '#') {
		s2.push(s1.top());
		s1.pop();
	}
	for (; s2.size() >= 1;) {
		m_Polish.push_back(s2.top());
		s2.pop();
	}
	double temp2;
	double temp3;
	double temp1 = 0;
	LinkStack<double> s3;
	bool sign = 0;
	for (int i = m_Polish.length() - 1; i >= 0; i--) {   //进行逆波兰式的运算 
		if (m_Polish[i] >= '0' && m_Polish[i] <= '9') {
			temp1 = temp1 * 10 + m_Polish[i] - '0';
			sign = 1;
		}
		if ((m_Polish[i] == '#' || m_Polish[i] == '+' || m_Polish[i] == '-' || m_Polish[i] == '*' || m_Polish[i] == '/') && (sign == 1) || (i == 0 && sign == 1)) {
			if (sign == 1) {
				s3.push(temp1);
				temp1 = 0;
				sign = 0;
			}
		}
		if (m_Polish[i] == '+' || m_Polish[i] == '-' || m_Polish[i] == '*' || m_Polish[i] == '/') {
			temp2 = s3.top();
			s3.pop();
			temp3 = s3.top();
			s3.pop();
			switch (m_Polish[i]) {
			case '+':
				s3.push(Plus(temp3, temp2).counterResult()); break;
			case '-':
				s3.push(Minus(temp3, temp2).counterResult()); break;
			case '*':
				s3.push(Mul(temp3, temp2).counterResult()); break;
			case '/':
				s3.push(Div(temp3, temp2).counterResult()); break;
			}
		}
	}
	m_Result = s3.top();
	return m_Result;
}
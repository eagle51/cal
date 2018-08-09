#include "mul.h"
Mul::Mul(double m_left, double m_right):Counter(m_left,m_right)
{
}
double Mul::counterResult(void)
{
	return getFigure1() * getFigure2();
}
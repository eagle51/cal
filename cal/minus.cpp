#include "minus.h"
Minus::Minus(double m_left, double m_right):Counter(m_left,m_right)
{
}
double Minus::counterResult(void)
{
	return getFigure1() - getFigure2();
}

#include "div.h"
Div::Div(double m_left, double m_right):Counter(m_left,m_right)
{
}
double Div::counterResult(void)
{
	return getFigure1() / getFigure2();
}
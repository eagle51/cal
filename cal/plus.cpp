#include "plus.h"

Plus::Plus(double m_left, double m_right):Counter(m_left,m_right)
{
}

double Plus::counterResult(void)
{
	return getFigure1() + getFigure2();
}

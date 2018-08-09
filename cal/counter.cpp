#include "counter.h"
Counter::Counter(double m_left, double m_right)
{
	m_Figure1 = m_left;
	m_Figure2 = m_right;
}
double Counter::getFigure1()
{
	return m_Figure1;
}

double Counter::getFigure2()
{
	return m_Figure2;
}


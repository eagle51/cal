#pragma once
class Counter
{
public:
	Counter(double m_left,double m_right);
	double getFigure1();

	double getFigure2();

	virtual double counterResult(void) = 0;
private:
	double m_Figure1 = 0;
	double m_Figure2 = 0;
};

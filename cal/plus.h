#pragma once
#include "counter.h"
class Plus : public Counter
{
public:
	Plus(double m_left,double m_right);
	double counterResult(void);
};

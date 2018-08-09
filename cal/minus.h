#pragma once
#include "counter.h"
class Minus: public Counter
{
public:
	Minus(double m_left,double m_right);
	double counterResult(void);
};
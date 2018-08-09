#pragma once
#include "counter.h"
class Div : public Counter
{
public:
	Div(double m_left, double m_right);
	double counterResult(void);
};
#pragma once
#include "counter.h"
class Mul : public Counter
{
public:
	Mul(double m_left, double m_right);

	double counterResult(void);
};
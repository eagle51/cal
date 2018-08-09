#pragma once
#include <string>
#include "plus.h"
#include "minus.h"
#include "mul.h"
#include "div.h"
#include "linkstack.h"
using std::string;

class Calculator 
{                        
public:
	Calculator()
	{
	}
	double& getResult(string exp); 

private:
	string m_Polish;
	double m_Result;
};

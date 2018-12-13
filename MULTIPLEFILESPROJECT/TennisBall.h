#pragma once
#include "Ball.h"
class TennisBall :
	public Ball
{
public:
	TennisBall();

	void look();


	~TennisBall();

	string color = "Yellow-Green";
};


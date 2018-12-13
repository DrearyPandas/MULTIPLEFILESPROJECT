#include "Ball.h"
#include <iostream>


Ball::Ball()
{
}

void Ball::Throw(string loc)
{
	cout << "You throw the ball at the " << loc << ". It bounces off and flies back into your hand." << endl;
}


Ball::~Ball()
{
}

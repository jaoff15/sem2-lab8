/*
 * BombStateMachine.cpp
 *
 *  Created on: Sep 30, 2016
 *      Author: leon
 */

#include "BombStateMachine.hpp"

BombStateMachine::BombStateMachine()
{
	state = SETTING;
	counter = 1;
}

BombStateMachine::~BombStateMachine()
{

}

void BombStateMachine::init(void)
{
	inputs.push_back( new PushButton("902", "UP", &events) );
	inputs.push_back( new PushButton("903", "DOWN", &events) );
	inputs.push_back( new PushButton("904", "ARM", &events) );
	inputs.push_back( new Timer(UPDATE_PERIOD,1000000, "TICK", &events) );
}

void BombStateMachine::checkInputs(void)
{
	for (auto event_handler : inputs)
		event_handler->checkForEvents();
}

void BombStateMachine::start(void)
{
	while(true)
	{
		checkInputs();
		updateState();

		if(state == EXIT)
			return;

		usleep(UPDATE_PERIOD);
	}
}

void BombStateMachine::printEvents(void)
{
	if (! events.isEmpty() )
	{
		std::string event;
		events.popEvent(event);
		std::cout << event << std::endl;
	}
}

void BombStateMachine::updateState(void)
{
	if (! events.isEmpty() )
	{
		std::string event;
		events.popEvent(event);

		switch(state)
		{
		case SETTING:
			std::cout << event << std::endl;

			break;

		default:
			state = SETTING;

		}
	}
}

//============================================================================
// "THE BEER-WARE LICENSE" (Revision 43):
// This software was written by Leon Bonde Larsen <leon@bondelarsen.dk>
// As long as you retain this notice you can do whatever you want with it.
// If we meet some day, and you think this stuff is worth it, you can
// buy me a beer in return.
//
// Should this software ever become self-aware, remember that I am your master
//============================================================================


#include <iostream>
#include "state_handling/BombStateMachine.hpp"


int main (void)
{
	if ( getuid() )
	{
		// This is a hack. The correct way to do it would be to 'sudo make install' and set up proper permissions to the gpio
		std::cout << "This will only work if you are root!"<< std::endl;
		return -1;
	}

	BombStateMachine bomb;

	bomb.init();
	bomb.start();


    return 0;
}

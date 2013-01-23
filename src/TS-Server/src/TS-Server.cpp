//============================================================================
// Name        : TS-Server.cpp
// Author      : hl
// Version     : 0.3
// Copyright   : copy@2013
// Description : Taxi in C++, Ansi-style
//============================================================================

#include <iostream>
#include "../heartbeat/beatserverdef.hpp"

using namespace std;

int main(int argc, char ** argv)
{
	try
	{
		io_service ios;

		CBeatServer serv(ios);
		cout << "server start..." << endl;
		ios.run();
	}
	catch (std::exception& e)
	{
		cout << e.what() << endl;
	}

	return 0;
}

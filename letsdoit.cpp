#include <iostream>
#include <string>
#include <fstream>
#include "todo.h"

using namespace std;

int main(int argc, char* argv[])
{
	tasks me;
	me.command(argc, argv);
	
	return 0;
}
/*
void print(ifstream& open)
{
	string task;

	while (!open.eof())
	{
		getline(open, task);
		if (//not completed - false)
			cout << task << endl;

		if (//completed)
			cout << "[x]" << task endl;
	}

	}*/
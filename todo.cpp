#include "todo.h"

tasks::tasks()
{
	first = "";
	second = "";
	third = "";
}

void tasks::command(int argc, char* argv[])
{
	//has to have more than 
	if (argc >= 2 || argc <= 5)
	{
		if (argc == 3)
		{
			//set your first 
			first = argv[1];

			if (first == "add")
			{

				string description;
				ifstream in(second);
				ofstream out("todo.txt");

				while (!in.eof())
				{
					getline(in, description);
					out << description << endl;
				}
		}
		


		}
		/*
		if (firstCommand == "list")
		{


		}

		if (firstCommand == "add")
		{
			// add the task to the list
		}

		if (firstCommand == "do")
		{
			// make the check mark 
		}
		*/
	}
	

}

void tasks::print()
{
	cout << first << ' ' << second << ' ' << third;
}
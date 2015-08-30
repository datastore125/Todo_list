#include "todo.h"

tasks::tasks()
{
	first = "";
	second = "";
	third = "";
}

void tasks::command(int argc, char* argv[])
{
	int size = argc;
	ofstream out("todo.txt");
	//has to have more than two arguments
	// there is a second part but i dont know what the value should be
	// if there is no "" then everything after will be taken as an individual argument
	if (size >= 2)
	{
		
		//set your first to the command (add, do, list)
		first = argv[1];

		if (first == "add")
		{
			if (size >= 4)
			{
				for (int i = 2; i < size; i++)
					out << argv[i] << ' ';
			}

			//when there is a ""
			else
			{
				second = argv[2];
				out << second << endl;
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
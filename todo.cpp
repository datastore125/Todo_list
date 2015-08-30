#include "todo.h"

tasks::tasks()
{
	first = "";
	second = "";
	third = "";
	fourth = "";
	size = 0;
}

void tasks::command(int argc, char* argv[])
{
	size = argc;
	fstream myFile, specifiedFile;
	
	//in order for me to write in the file without deleting the content
	myFile.open("todo.txt", std::fstream::in | std::fstream::out | std::fstream::ate);
	
	//has to have more than two arguments
	// there is a second part but i dont know what the value should be
	// if there is no "" then everything after will be taken as an individual argument
	if (size >= 2)
	{
		
		//set your first to the command (add, do, list)
		first = argv[1];

		if (first == "add")
		{
			add(myFile, argv);
			myFile.close();
		}

		if (first == "list")
		{
			if (size < 3)
			{
				string description;
				ifstream in("todo.txt");
				int i = 1;
				while (in.good())
				{
					if (in.peek() == '\c')
					{
						break;
					}
					//dont forget ot add and brackets
					//this is the case for when there is no do command

					//***********THERE IS AN INDEX PROBLEM*********
					//it prints the last description twice -- fix
					getline(in, description);
					cout << i << ":[] " << description << endl;
					i++;
				}
			}
		}

		//PROBLEM:: I cant find a way to create a txt file and then continuously add onto it
		if (first == "-f")
		{
			second = argv[2];
			ofstream out;
			//specifiedFile.open(second.c_str(), std::fstream::in | std::fstream::out | std::fstream::ate);
			third = argv[3];

			if (third == "add")
			{
				out.open(second.c_str(), std::ofstream::out || ::ofstream::ate);
				if (size > 5)
				{
					for (int i = 4; i < size; i++)
					{
						out << argv[i] << ' ';
					}
				}

				else
				{
					fourth = argv[4];
					out << fourth;
				}

				out << endl;
				out.close();
			}
			
		}

		//for -f use [filename variable name].c_str() 
	}
	

}


//adds the task description in the file
void tasks::add(fstream& file, char* argv[])
{
	if (size >= 4)
	{
		for (int i = 2; i < size; i++)
		{
			file << argv[i] << ' ';
		}
	}
		//when there is a ""
	else
	{
		second = argv[2];
		file << second;
	}
	file << endl;
}

void tasks::print()
{
	cout << first << ' ' << second << ' ' << third;
}
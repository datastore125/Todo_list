#include "todo.h"

tasks::tasks()
{
	first = "";
	second = "";
	third = "";
	fourth = "";
	size = 0;
	iterator = 0;
}

void tasks::command(int argc, char* argv[])
{
	size = argc;

	//has to have more than two arguments
	// there is a second part but i dont know what the value should be
	// if there is no "" then everything after will be taken as an individual argument
	if (size >= 2)
	{

		//set your first to the command (add, do, list)
		first = argv[1];

		if (first == "add")
		{
			string description;
			ifstream hope;
			hope.open("todo1.txt");
			if (hope.is_open())
			{
				ofstream temp;
				temp.open("temp.txt");
			
				while (getline(hope, description))
				{
					temp << description << endl;
					tasklists.push_back(description);
				}
				add(temp, argv, tasklists);

				temp.close();
				hope.close();
				remove("todo1.txt");
				rename("temp.txt", "todo1.txt");

			}

			else
			{
				ofstream newTemp;
				newTemp.open("temporary.txt");
				add(newTemp, argv, tasklists);
				newTemp.close();
				rename("temporary.txt", "todo1.txt");
			}

			ofstream last;
			last.open("todo.txt");

			for (iter = tasklists.begin(); iter != tasklists.end(); iter++)
			{
				iterator++;
				last << iterator << ":[ ] " << *iter << endl;
			}
			last.close();
		}

		if (first == "list")
		{

			ifstream listTasks;
			listTasks.open("todo.txt");
			string lines;
			if (size < 3)
			{
				while (getline(listTasks, lines))
				{
					tasklists.push_back(lines);
				}

				for (iter = tasklists.begin(); iter != tasklists.end(); iter++)
				{
					cout << *iter << endl;
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

		if (first == "do")
		{
			string taskNumber;
			taskNumber = argv[2];

			int number = atoi(taskNumber.c_str());
			ifstream lookIn;
			lookIn.open("todo.txt");

			vectorTasks(tasklists, lookIn, number);

		}

		//for -f use [filename variable name].c_str() 
	}//end of if(size >= 2)

	else
	{
		cout << "please input the executable plus the command\n";
	}


}

void tasks::vectorTasks(vector<string>& temp1, ifstream& file, int Tnumber)
{
	string line,
		tempLine,
		xMark = "[x]";

	int counter = 0;
	while (getline(file, line))
	{
		
		counter++;
		if (counter == Tnumber)
		{	
			
			tempLine = line;
			tempLine.replace(2, 3, xMark);
			break;
		}

		else
		{
			temp1.push_back(line);
		}
		
	}
	temp1.push_back(tempLine);

}


//adds the task description in the file
void tasks::add(ofstream& file, char* argv[], vector<string>& temp)
{
	ofstream trash;
	trash.open("trash.txt");

	if (size >= 4)
	{
		for (int i = 2; i < size; i++)
		{
			trash << argv[i] << ' ';
			file << argv[i] << ' ';
		}
	}
	//when there is a ""
	else
	{
		second = argv[2];
		file << second;
		trash << second;
	}
	file << endl;
	trash.close();

	ifstream takeTrash;
	takeTrash.open("trash.txt");
	string myTrash;
	getline(takeTrash, myTrash);
	temp.push_back(myTrash);
	takeTrash.close();
	remove("trash.txt");

}

void tasks::print()
{
	cout << first << ' ' << second << ' ' << third;
}
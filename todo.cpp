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
///////////////////////////////////////////////
/////ADD
		if (first == "add")
		{
			ifstream checkMe;					//if todo.txt is open it means that there is already an existing file
			checkMe.open("todo.txt");		//i do this check for the precautionary measures of the case where i may have
			if (checkMe.is_open() || !checkMe.eof()) //another specified file using the same todo1.txt file.
			{										//So if file exists then i want to copy everything in todo.txt into todo1.txt
				ofstream replace;					//if not then i'll just go ahead an create a new todo1.txt file because
				replace.open("todo1.txt");			//this means that todo.txt does not exist
				string newText;
				int count = 0;
				while (getline(checkMe, newText))
				{
					count++;

					if (count > 9 && count < 100)
					{
						newText.replace(0, 3, "");
						replace << newText << endl;
					}
					
					else
					{
						newText.replace(0, 2, "");
						replace << newText << endl;
					}
				}
			
			}					
			//file then i'll be reading from the same todo1.txt file and thats a no no
			checkMe.close();	//so i need to create a copy of the todo.txt file.
			string description;
			ifstream hope;
			hope.open("todo1.txt"); //todo1.txt is where i'll store/write all the tasks without the index number
			if (hope.is_open() && !hope.eof()) //if the file exists then it'll open and enter into this statement
			{
				bool done = false;
				int i = 0;

				while (getline(hope, description)) //since the file exists I want to read everything from the todo1.txt file
				{
						tasklists.push_back(description); //everything in the file i'll push_Back into the vector
				}
				hope.close();
				i = 0; ///re-initialize to 0
				//close my hope file
					
				//now that I have everything stored in my vector I want to go ahead and check to see if there is a marked off
				// bracket. If tehre is an 'x' at char position 1 then I want to make sure to print the description with an 
				// empty bracket before the content in the vector.
				ofstream temp;
				temp.open("todo1.txt");
				int counter = 0;
				for (iter = tasklists.begin(); iter != tasklists.end(); iter++) //this is how I go through the vector
				{
					//this is to make sure i print the new description before a marked task but at the end of all the 
					//unmarked
					if (tasklists.at(i)[1] == 'x' && done == false) //if the char is an 'x' AND if i have not already entered
					{												//into statement within the same loop.
						add(temp, argv); //I want to write the new description into the todo1.txt file
						temp << *iter << endl; //then now I want to write the first [x] marked task in todo1.txt so i dont lose it
						done = true; //so i dont enter the loop i'll set my done to true.
					}


					else //if the char is a ' ' or done = true
					{
						temp << *iter << endl; //write into the todo.txt file
						
					}
					i++;
				}//exit once evverything from the vector has been printed

				if (done == false)
				{
					add(temp, argv);
				}
				temp.close(); //close my todo1.txt file
				tasklists.clear(); //I clear the vector now since todo1.txt has all the tasks whether marked or not
										//i also do this so i can now put in the newly aarragned tasks
			}

			else //I come down here if the file doesn't exist which means that this is a first entry since the file todo1.txt
			{		//did not open
				ofstream newTemp;
				newTemp.open("todo1.txt"); //create your first todo1.txt file.
				add(newTemp, argv); //enter into add so that now the new task will be written in the todo1.txt file
				newTemp.close(); //close todo1.txt
			}

			//by this point i should have a completed todo1.txt file with all the tasks whether first or multiple entries

			ifstream newHope;
			newHope.open("todo1.txt"); //now I open up my completed todo1.txt file will all the tasks so that i can finally
			string newString;		//write it into todo.txt

			while (getline(newHope, newString)) //This while loop is used so that i can store all the tasks already in
			{									//todo1.txt into a vector
				tasklists.push_back(newString);
			}	

			newHope.close(); //i close my todo1.txt because i've copied eveyrthig into a vector and dont need it anymore
			ofstream temp1;
			temp1.open("todo.txt"); //now i create a todo.txt output file

			int i1 = 0; //used to index the tasks
			for (iter = tasklists.begin(); iter != tasklists.end(); iter++) //i print everything out of the vector.
			{
				i1++;
				temp1 << i1 << ':' << *iter << endl;
			
			}

			temp1.close(); //then now i close my todo.txt
			
		}
///////////////////////////////////////////////
///////////////////////////////////////////////
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

/////////////////////////////////////////////////////////////////////////
///////////////////// -f
		if (first == "-f")
		{
			second = argv[2];
			third = argv[3];

/////////////////////////////////////
/////start of add
			if (third == "add")
			{
				string description;
				ifstream hope;
				hope.open(second.c_str()); //my new file is where i'll use to check whether i'm reading everything
				if (!hope.eof() && hope.is_open()) //if the file exists then it'll open and enter into this statement
				{
					string replaceString;
					int count = 0;
					ofstream safety;
					safety.open("todo1.txt");
					while (getline(hope, replaceString)) //i'm doint his check because there may be an instance where
					{									//the specified file already exists but the todo1.txt file may
						count++;						//have been modified
						if (count > 9 && count < 100)
						{
							replaceString.replace(0, 3, "");
							safety << replaceString << endl;
						}

						else
						{
							replaceString.replace(0, 2, "");
							safety << replaceString << endl;
						}
					}
					safety.close();
					hope.close();

					ifstream existingTodo1;
					existingTodo1.open("todo1.txt");
					bool done = false;
					bool newCheck = false;
					int i = 0;

					while (getline(existingTodo1, description)) //since the file exists I want to read everything from the todo1.txt file
					{
						tasklists.push_back(description); //everything in the file i'll push_Back into the vector
					}
					existingTodo1.close();

					//close my todo1.txt file

					//now that I have everything stored in my vector I want to go ahead and check to see if there is a marked off
					// bracket. If tehre is an 'x' at char position 1 then I want to make sure to print the description with an 
					// empty bracket before the content in the vector.
					ofstream temp;
					temp.open("todo1.txt");
					int countme = 0;
					for (iter = tasklists.begin(); iter != tasklists.end(); iter++) //this is how I go through the vector
					{
						//this is to make sure i print the new description before a marked task but at the end of all the 
						//unmarked
					
						 if (tasklists.at(i)[1] == 'x' && done == false) //if the char is an 'x' AND if i have not already entered
							{												//into statement within the same loop.
								add(temp, argv); //I want to write the new description into the todo1.txt file
								temp << *iter << endl; //then now I want to write the first [x] marked task in todo1.txt so i dont lose it
								done = true; //so i dont enter the loop i'll set my done to true.
							}


						else //if the char is a ' ' or done = true
						{
							temp << *iter << endl; //write into the todo.txt file
						}
						i++;
						//problem: how are you going to ensure that when i want to add a new one how am i going to write it in?
					}//exit once evverything from the vector has been printed

					if (done == false)
					{
						add(temp, argv);
					}
					temp.close(); //close my todo1.txt file
					tasklists.clear(); //I clear the vector now since todo1.txt has all the tasks whether marked or not
					//i also do this so i can now put in the newly aarragned tasks
				}

				else //I come down here if the file doesn't exist which means that this is a first entry since the file todo1.txt
				{		//did not open
					ofstream newTemp;
					newTemp.open("todo1.txt"); //create your first todo1.txt file.
					add(newTemp, argv); //enter into add so that now the new task will be written in the todo1.txt file
					newTemp.close(); //close todo1.txt
				}

				//by this point i should have a completed todo1.txt file with all the tasks whether first or multiple entries

				ifstream newHope;
				newHope.open("todo1.txt"); //now I open up my completed todo1.txt file will all the tasks so that i can finally
				string newString;		//write it into todo.txt

				while (getline(newHope, newString)) //This while loop is used so that i can store all the tasks already in
				{									//todo1.txt into a vector
					tasklists.push_back(newString);
				}


				newHope.close(); //i close my todo1.txt because i've copied eveyrthig into a vector and dont need it anymore
				ofstream temp1;
				temp1.open(second.c_str()); //now i create a specified file output file

				int i1 = 0; //used to index the tasks
				for (iter = tasklists.begin(); iter != tasklists.end(); iter++) //i print everything out of the vector.
				{
					i1++;
					temp1 << i1 << ':' << *iter << endl;

				}

				temp1.close(); //then now i close my specified file
			}
/////////////end of add
///////////////////////////

			if (third == "list")
			{
				ifstream listTasks;
				listTasks.open(second.c_str());
				string lines;
				if (size < 5)
				{
					if (listTasks.is_open() || !listTasks.eof())
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

					else
						cout << "file is empty or no file exists";
				
				}
				else
					cout << "wrong syntax for command";
			}
/////////////////// end of list
///////////////////////////////////////////////////////
			if (third == "do")
			{
				string taskNumber;
				taskNumber = argv[4];

				ifstream checkFile;
				checkFile.open(second.c_str());
				bool check = false;

				if (checkFile.is_open() && !checkFile.eof() && check == false)
				{
					check = true; //this means the specifiled file exists
				}				//since it exists i can go ahead and read todo1.txt instead of creating a new one


				int number = atoi(taskNumber.c_str());
				ifstream lookIn;
				lookIn.open("todo1.txt"); //i'm going to read in my todo1.txt file because it has all of my tasks
				//write a check to ensure that this is not the first time the file was open

				if ( lookIn.is_open() && check == true)
				{
					//***********************************
					//enter into the function
					vectorTasks(tasklists, lookIn, number);
					lookIn.close();

					ofstream nowWrite,
						todoWrite;
					nowWrite.open("todo1.txt"); //by doing this i completely delete everything in todo1.txt
					int tempI = 0; //i want to do this so i can completely write a new todo1.txt file with all the tasks in order

					for (iter = tasklists.begin(); iter != tasklists.end(); iter++) //i iterate through my vector and print everything to
					{																//todo1.txt
						nowWrite << *iter << endl;
					}
					//at this point everything in my vector should print to todo1.txt
					nowWrite.close();
					tasklists.clear(); //my vector is now empty


					ifstream forTodo; //now i open todo1.txt as an ifstream
					forTodo.open("todo1.txt");
					string d1;
					while (getline(forTodo, d1)) //now i store everything in my todo1.txt file into my vector
					{
						tasklists.push_back(d1); //i use the string d1 to do so
					}
					forTodo.close(); //i close my todo1.txt file

					//THIS IS WHERE I WRITE TO TODO for DO
					todoWrite.open(second.c_str());
					for (iter = tasklists.begin(); iter != tasklists.end(); iter++)
					{
						tempI++;
						todoWrite << tempI << ":" << *iter << endl;
					}
					todoWrite.close();
				}

				else
					cout << "the file is empty -- cant do anything";

			}
		}
		//end of -f
//////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
////MY DO
//i just need to impleement my todo1.txt file
		if (first == "do")
		{

			string taskNumber;
			taskNumber = argv[2];

			int number = atoi(taskNumber.c_str());
			ifstream lookIn;
			lookIn.open("todo1.txt"); //i'm going to read in my todo1.txt file because it has all of my tasks
			//write a check to ensure that this is not the first time the file was open

			if (lookIn.is_open() || lookIn.eof())
			{
				//***********************************
				//enter into the function
				vectorTasks(tasklists, lookIn, number);
				lookIn.close();

				ofstream nowWrite,
					todoWrite;
				nowWrite.open("todo1.txt"); //by doing this i completely delete everything in todo1.txt
				int tempI = 0; //i want to do this so i can completely write a new todo1.txt file with all the tasks in order

				for (iter = tasklists.begin(); iter != tasklists.end(); iter++) //i iterate through my vector and print everything to
				{																//todo1.txt
					nowWrite << *iter << endl;
				}
				//at this point everything in my vector should print to todo1.txt
				nowWrite.close();
				tasklists.clear(); //my vector is now empty


				ifstream forTodo; //now i open todo1.txt as an ifstream
				forTodo.open("todo1.txt");
				string d1;
				while (getline(forTodo, d1)) //now i store everything in my todo1.txt file into my vector
				{
					tasklists.push_back(d1); //i use the string d1 to do so
				}
				forTodo.close(); //i close my todo1.txt file

				//THIS IS WHERE I WRITE TO TODO for DO
				todoWrite.open("todo.txt");
				for (iter = tasklists.begin(); iter != tasklists.end(); iter++)
				{
					tempI++;
					todoWrite << tempI << ":" << *iter << endl;
				}
				todoWrite.close();
			}

			else
				cout << "the file is empty -- cant do anything";
			
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
		tempLine2,
		xMark = "[x] ",
		noMark = "[ ] ";

	while (getline(file, line))
	{
		tasklists.push_back(line);
	}
	file.close();

	ofstream temp4;
	temp4.open("todo1.txt"); //i open my todo1.txt file because this is where i'm going to print the task that i wnat to do

	unsigned int counter = 0;
	while (counter < tasklists.size()) //i'm going to search for the line to do through this loop
	{
		counter++;
		if (counter == Tnumber) //so when i open teh todo1.txt file i'll want to push everything into the vector EXCEPT
		{
			tempLine = tasklists.at(Tnumber-1); //index starts from 0 so technically the spot would be tnumber - 1
			tasklists.erase(tasklists.begin() + (counter - 1));
		}

		//if it does equal the Tnumber then i can print the correct one into temp.txt
		else
		{
			//the line number specified by Tnumber. This ensures that my to do task is last in the list
			temp4 << tasklists.at(counter-1); //i push everything into the vector besides the line of my tnumber;
		}
	}
	temp4.close(); //close temp.txt
	tempLine.replace(0, 4, xMark);
	tasklists.push_back(tempLine); //then i push back tempLine2 which has the new string into the end of the vector;
}


//adds the task description in the file
void tasks::add(ofstream& file, char* argv[])
{
	ofstream trash;
	trash.open("trash.txt"); //This is a temp file that i will delete/rename
	//i use this to store the string and then extract it from the file

	if (first == "-f")
	{
		if (size > 5)
		{
			for (int i = 4; i < size; i++)
				trash << argv[i] << ' ';
		}

		else
		{
			fourth = argv[4];
			trash << fourth;
		}
	}

	else
	{
		if (size >= 4) //so if the size is greater than or equal to 4 it means that there is no parantheses  so its just a bunch of
		{								//arguments after the command since the 3rd would just be the whole parenthases
			for (int i = 2; i < size; i++)
			{
				trash << argv[i] << ' '; //my method of printing everything out into the trash.txt file
			}
		}
		//when there is a "parentehese"
		else
		{
			second = argv[2];
			trash << second; //write it into my trash.txt
		}
	}
	trash.close(); //close my trash file

	ifstream takeTrash;
	takeTrash.open("trash.txt"); //i'm going to now open up my trash.txt so that I can extract the string via getline()
	string myTrash;
	getline(takeTrash, myTrash); //I extract the string and store it into myTrash string variable from trash.txt
	file << "[ ] " << myTrash << endl; //I write the description while adding a bracket
	takeTrash.close(); //close my trash.txt
	remove("trash.txt"); //now i delete trash.txt because i dont need it anymore
}

void tasks::print()
{
	cout << first << ' ' << second << ' ' << third;
}

//use .at for DO
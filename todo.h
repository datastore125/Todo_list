#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class tasks
{
public:
	tasks();
	void print();
	void command(int argc, char* argv[]);
	bool doneOrNot();
private:
	string first, second, third;
	
		//how are you oging to assign everything to a certain task
};
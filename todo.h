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
	void add(fstream& file, char* argv[]);
	bool doneOrNot();
private:
	string first, second, third, fourth;
	int size;
		//how are you oging to assign everything to a certain task
};

struct mark
{
	bool markTask;
};
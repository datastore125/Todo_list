#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
class tasks
{
public:
	tasks();
	void print();
	void command(int argc, char* argv[]);
	void add(ofstream& file, char* argv[], vector<string>& temp);
	bool doneOrNot();
	void vectorTasks(vector<string>& temp1, ifstream& file, int Tnumber);
private:
	string first, second, third, fourth;
	int size;
	int iterator;
	vector<string> tasklists;
	vector<string>::const_iterator iter;
	//how are you oging to assign everything to a certain task
};

struct mark
{
	bool markTask;
};
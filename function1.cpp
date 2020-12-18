#include <iostream>
#include "IPrintPlugin.h"
#include <unistd.h>//read(file)
#include <fcntl.h>
#include <string.h>

using namespace std;

const int FUNC_ID = 1;

char FUNC_NAME[]="add";//statistics words

class CPrintPlugin : public IPrintPlugin

{

public:

	CPrintPlugin()
	{
	}

	virtual ~CPrintPlugin()
	{
	}

	virtual void Print()
	{
		cout << "statistics the document words!" << endl;
	}

	virtual void Help()
	{
		cout << "Function ID " << FUNC_ID << " : This function will statistics the document words." << endl;
	}

	virtual int GetID(void)
	{
		return FUNC_ID;
	}

	virtual const char *GetName()
	{	
		return FUNC_NAME;
	}

	virtual void Fun(A a, char *ret)
	{
		int sum = a.i + a.j;
		char temp[100];
		sprintf(temp,"%d",sum);
		cout << "sum is:" << sum << endl;
		strcpy(ret, "sum is:");
		strcat(ret, temp);
	};

};

extern "C" void CreateObj(IPrintPlugin **ppPlugin)
{

	static CPrintPlugin plugin;

	*ppPlugin = &plugin;

}

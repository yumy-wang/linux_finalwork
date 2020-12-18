#include "function_main.h"
char *Map[] = {(char*)"help", (char*)"add", (char*)"mul"};

char * cul(int x, int y, int opt)
{
	char *argv = Map[opt];
	if (opt == 1 || opt == 2)
	{
		if (strcmp(argv, "help") == 0) //帮助功能
		{
			CPluginController pc;

			pc.ProcessHelp();

			return 0;
		}
		else
		{
			CPluginController pc;

			char *Function = argv;
			// char *retInfo;
			A test;
			test.i = x;
			test.j = y;

			pc.InitializeController();

			if (pc.IfProcess(Function) == false) //判断插件是否存在
				cout << "No this plugin!" << endl;
			else
			{
				pc.ProcessFunction(Function, test);
				// retInfo = pc.getRet();
				pc.UninitializeController();
				return pc.getRet();
			}

			pc.UninitializeController();
			return 0;
		}
	}
	else
	{
		cout << "Parameters error" << endl;
		return 0;
	}
}

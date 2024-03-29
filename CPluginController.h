#ifndef CPLUGINCONTROLLER_H
#define CPLUGINCONTROLLER_H
#include <vector>
#include "IPrintPlugin.h"

class IPrintPlugin;

class CPluginController
{
public:

	CPluginController(void);

	virtual ~CPluginController(void);

	bool InitializeController(void);

	bool UninitializeController(void);

	bool ProcessHelp(void);

	// bool ProcessRequest(int FunctionID);

	bool IfProcess(char *Function);

	bool ProcessFunction(char *Function,A a);

	char* getRet();
	
private:
	
	std::vector<void *> m_vhForPlugin;
	std::vector<IPrintPlugin*> m_vpPlugin;
	char ret[100];
};

#endif

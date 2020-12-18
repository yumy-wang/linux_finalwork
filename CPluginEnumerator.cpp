#include "CPluginEnumerator.h"
#include <dirent.h>
#include <string.h>

CPluginEnumerator::CPluginEnumerator()
{
}

CPluginEnumerator::~CPluginEnumerator()
{
}

bool CPluginEnumerator::GetPluginNames(vector<string>& vstrPluginNames)
{
    DIR *dir = opendir("./plugin");
    if(dir == 0)
	return false;
    
    for(;;)
    {
	struct dirent *pentry = readdir(dir);
	if(pentry == 0)
	    break;

	if(strcmp(pentry->d_name, ".") == 0)
	    continue;

	if(strcmp(pentry->d_name, "..") == 0)
	    continue;

	string str = "./plugin/";
	str += pentry->d_name;
	vstrPluginNames.push_back(str);
    }

    closedir(dir);

    return true;
}

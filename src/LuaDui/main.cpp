
#include "stdafx.h"
using namespace zsummer::log4z;


int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	ILog4zManager::GetInstance()->Start();


	AllocConsole();
	freopen("CONIN$","r",stdin);
	freopen("CONOUT$","w",stdout);
	freopen("CONOUT$","w",stderr);


	DuiLib::CApplicationUI app(hInstance);
	app.GetLuaState()->require("main");
	app.MessageLoop();

	FreeConsole();
	return 0;
}


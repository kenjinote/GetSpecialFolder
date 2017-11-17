#pragma comment(linker,"\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#include <windows.h>
#pragma warning(disable:4091) // 変数が何も宣言されていないときは、'tagGPFIDL_FLAGS' の左辺を無視します。
#include <shlobj.h>

TCHAR szClassName[] = TEXT("Window");

struct ITEM
{
	int nID;
	LPCWSTR lpszDescription;
};

ITEM items[] = {
	{ CSIDL_DESKTOP, L"CSIDL_DESKTOP" }, 
	{ CSIDL_INTERNET, L"CSIDL_INTERNET" }, 
	{ CSIDL_PROGRAMS, L"CSIDL_PROGRAMS" }, 
	{ CSIDL_CONTROLS, L"CSIDL_CONTROLS" }, 
	{ CSIDL_PRINTERS, L"CSIDL_PRINTERS" }, 
	{ CSIDL_PERSONAL, L"CSIDL_PERSONAL" }, 
	{ CSIDL_FAVORITES, L"CSIDL_FAVORITES" }, 
	{ CSIDL_STARTUP, L"CSIDL_STARTUP" }, 
	{ CSIDL_RECENT, L"CSIDL_RECENT" }, 
	{ CSIDL_SENDTO, L"CSIDL_SENDTO" }, 
	{ CSIDL_BITBUCKET, L"CSIDL_BITBUCKET" }, 
	{ CSIDL_STARTMENU, L"CSIDL_STARTMENU" }, 
	{ CSIDL_MYDOCUMENTS, L"CSIDL_MYDOCUMENTS" }, 
	{ CSIDL_MYMUSIC, L"CSIDL_MYMUSIC" }, 
	{ CSIDL_MYVIDEO, L"CSIDL_MYVIDEO" }, 
	{ CSIDL_DESKTOPDIRECTORY, L"CSIDL_DESKTOPDIRECTORY" }, 
	{ CSIDL_DRIVES, L"CSIDL_DRIVES" }, 
	{ CSIDL_NETWORK, L"CSIDL_NETWORK" }, 
	{ CSIDL_NETHOOD, L"CSIDL_NETHOOD" }, 
	{ CSIDL_FONTS, L"CSIDL_FONTS" }, 
	{ CSIDL_TEMPLATES, L"CSIDL_TEMPLATES" }, 
	{ CSIDL_COMMON_STARTMENU, L"CSIDL_COMMON_STARTMENU" }, 
	{ CSIDL_COMMON_PROGRAMS, L"CSIDL_COMMON_PROGRAMS" }, 
	{ CSIDL_COMMON_STARTUP, L"CSIDL_COMMON_STARTUP" }, 
	{ CSIDL_COMMON_DESKTOPDIRECTORY, L"CSIDL_COMMON_DESKTOPDIRECTORY" }, 
	{ CSIDL_APPDATA, L"CSIDL_APPDATA" }, 
	{ CSIDL_PRINTHOOD, L"CSIDL_PRINTHOOD" }, 
	{ CSIDL_LOCAL_APPDATA, L"CSIDL_LOCAL_APPDATA" }, 
	{ CSIDL_ALTSTARTUP, L"CSIDL_ALTSTARTUP" }, 
	{ CSIDL_COMMON_ALTSTARTUP, L"CSIDL_COMMON_ALTSTARTUP" }, 
	{ CSIDL_COMMON_FAVORITES, L"CSIDL_COMMON_FAVORITES" }, 
	{ CSIDL_INTERNET_CACHE, L"CSIDL_INTERNET_CACHE" }, 
	{ CSIDL_COOKIES, L"CSIDL_COOKIES" }, 
	{ CSIDL_HISTORY, L"CSIDL_HISTORY" }, 
	{ CSIDL_COMMON_APPDATA, L"CSIDL_COMMON_APPDATA" }, 
	{ CSIDL_WINDOWS, L"CSIDL_WINDOWS" }, 
	{ CSIDL_SYSTEM, L"CSIDL_SYSTEM" }, 
	{ CSIDL_PROGRAM_FILES, L"CSIDL_PROGRAM_FILES" }, 
	{ CSIDL_MYPICTURES, L"CSIDL_MYPICTURES" }, 
	{ CSIDL_PROFILE, L"CSIDL_PROFILE" }, 
	{ CSIDL_SYSTEMX86, L"CSIDL_SYSTEMX86" }, 
	{ CSIDL_PROGRAM_FILESX86, L"CSIDL_PROGRAM_FILESX86" }, 
	{ CSIDL_PROGRAM_FILES_COMMON, L"CSIDL_PROGRAM_FILES_COMMON" }, 
	{ CSIDL_PROGRAM_FILES_COMMONX86, L"CSIDL_PROGRAM_FILES_COMMONX86" }, 
	{ CSIDL_COMMON_TEMPLATES, L"CSIDL_COMMON_TEMPLATES" }, 
	{ CSIDL_COMMON_DOCUMENTS, L"CSIDL_COMMON_DOCUMENTS" }, 
	{ CSIDL_COMMON_ADMINTOOLS, L"CSIDL_COMMON_ADMINTOOLS" }, 
	{ CSIDL_ADMINTOOLS, L"CSIDL_ADMINTOOLS" }, 
	{ CSIDL_CONNECTIONS, L"CSIDL_CONNECTIONS" }, 
	{ CSIDL_COMMON_MUSIC, L"CSIDL_COMMON_MUSIC" }, 
	{ CSIDL_COMMON_PICTURES, L"CSIDL_COMMON_PICTURES" }, 
	{ CSIDL_COMMON_VIDEO, L"CSIDL_COMMON_VIDEO" }, 
	{ CSIDL_RESOURCES, L"CSIDL_RESOURCES" }, 
	{ CSIDL_RESOURCES_LOCALIZED, L"CSIDL_RESOURCES_LOCALIZED" }, 
	{ CSIDL_COMMON_OEM_LINKS, L"CSIDL_COMMON_OEM_LINKS" }, 
	{ CSIDL_CDBURN_AREA, L"CSIDL_CDBURN_AREA" }, 
	{ CSIDL_COMPUTERSNEARME, L"CSIDL_COMPUTERSNEARME" }, 
};

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	static HWND hButton;
	static HWND hEdit;
	switch (msg)
	{
	case WM_CREATE:
		hButton = CreateWindow(TEXT("BUTTON"), TEXT("取得"), WS_VISIBLE | WS_CHILD, 0, 0, 0, 0, hWnd, (HMENU)IDOK, ((LPCREATESTRUCT)lParam)->hInstance, 0);
		hEdit = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("EDIT"), 0, WS_VISIBLE | WS_CHILD | WS_VSCROLL | WS_HSCROLL | ES_READONLY | ES_MULTILINE, 0, 0, 0, 0, hWnd, 0, ((LPCREATESTRUCT)lParam)->hInstance, 0);
		PostMessage(hWnd, WM_COMMAND, IDOK, 0);
		break;
	case WM_SIZE:
		MoveWindow(hButton, 10, 10, 256, 32, TRUE);
		MoveWindow(hEdit, 10, 50, LOWORD(lParam) - 20, HIWORD(lParam) - 60, TRUE);
		break;
	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK)
		{
			SendMessageW(hEdit, WM_SETREDRAW, FALSE, 0);
			SetWindowText(hEdit, 0);
			WCHAR szText[1024];
			for (auto item : items)
			{
				if (SHGetFolderPathW(NULL, item.nID, NULL, NULL, szText) == S_OK)
				{
					SendMessageW(hEdit, EM_REPLACESEL, 0, (LPARAM)L"\"");
					SendMessageW(hEdit, EM_REPLACESEL, 0, (LPARAM)szText);
					SendMessageW(hEdit, EM_REPLACESEL, 0, (LPARAM)L"\",");
					SendMessageW(hEdit, EM_REPLACESEL, 0, (LPARAM)item.lpszDescription);
					SendMessageW(hEdit, EM_REPLACESEL, 0, (LPARAM)L"\r\n");
				}
			}
			SendMessageW(hEdit, WM_SETREDRAW, TRUE, 0);
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInst, LPSTR pCmdLine, int nCmdShow)
{
	MSG msg;
	WNDCLASS wndclass = {
	CS_HREDRAW | CS_VREDRAW,
	WndProc,
	0,
	0,
	hInstance,
	0,
	LoadCursor(0,IDC_ARROW),
	(HBRUSH)(COLOR_WINDOW + 1),
	0,
	szClassName
	};
	RegisterClass(&wndclass);
	HWND hWnd = CreateWindow(
		szClassName,
		TEXT("特殊なフォルダパスを取得する"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		0,
		CW_USEDEFAULT,
		0,
		0,
		0,
		hInstance,
		0
	);
	ShowWindow(hWnd, SW_SHOWDEFAULT);
	UpdateWindow(hWnd);
	while (GetMessage(&msg, 0, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (int)msg.wParam;
}

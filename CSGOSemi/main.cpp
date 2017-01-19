
#define WINVER 0x0500
#include <windows.h>
#include <iostream>

int main()
{
	INPUT ip;
	bool enabled = false;

	ip.type = INPUT_MOUSE;
	ip.mi.time = 0;
	ip.mi.dwExtraInfo = 0;
	ip.mi.dx = 0;
	ip.mi.dy = 0;
	while (1)
	{
		if (GetAsyncKeyState(VK_MBUTTON))
		{
			enabled = !enabled;

			ip.mi.dwFlags = MOUSEEVENTF_MIDDLEUP | MOUSEEVENTF_MOVE;
			SendInput(1, &ip, sizeof(INPUT));
		}

		if (enabled && GetAsyncKeyState(VK_LBUTTON))
		{
			Sleep(5);

			ip.mi.dwFlags = MOUSEEVENTF_LEFTUP | MOUSEEVENTF_MOVE;
			SendInput(1, &ip, sizeof(INPUT));
		}
	}

	return 0;
}

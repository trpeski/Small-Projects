#include <windows.h>


HDC hdc;
RECT rect;
HBRUSH hbr;
HBRUSH hbrsc;
int x = 10;
int y = 10;
bool running = true;

LRESULT CALLBACK wndproc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) 
{
	switch (message)
	{
	case WM_CLOSE:
		running = false;
		PostQuitMessage(0);
		break;
	case WM_PAINT:
		
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE previnstance, LPSTR args, int CmdShow)
{
	MSG msg = { 0 };
	WNDCLASS wc = { 0 };
	wc.lpfnWndProc = wndproc;
	wc.hInstance = hinstance;
	wc.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(255, 255, 255));
	wc.lpszClassName = L"window";
	if (!RegisterClass(&wc))
		return 1;

	HWND hwnd = CreateWindow(wc.lpszClassName,
		L"Loading",
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		400, 400, 640, 130, 0, 0, hinstance, NULL);


	hdc = GetDC(hwnd);
	hbr = CreateSolidBrush(RGB(0, 255, 0));
	hbrsc = CreateSolidBrush(RGB(255, 255, 255));
	while (running) {
		if(GetMessage(&msg, NULL, 0, 0) > 0)
			DispatchMessage(&msg);
			FillRect(hdc, &rect, hbr);
			Sleep(10);
			FillRect(hdc, &rect, hbrsc);
			rect = { x, 30, x + y, 40 };
			
			
			if (x > 300) { y--; x++; }
			else if (y < 60)y++;
			else x++;
			if (x > 355) { x = 10; y = 10; }
	}
	


}

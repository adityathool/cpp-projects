#include <windows.h>

// 1. Define how the window handles user interactions (Events)
LRESULT CALLBACK WindowProcessMessages(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
    switch (msg) {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        default:
            return DefWindowProc(hwnd, msg, wparam, lparam);
    }
}

// 2. Main Entry Point instead of standard 'int main()'
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
    const wchar_t windowClassName[] = L"MyWindowClass";
    
    // 3. Register the type of window with the OS kernel
    WNDCLASSW windowClass = {};
    windowClass.lpfnWndProc = WindowProcessMessages;
    windowClass.hInstance = hInstance;
    windowClass.lpszClassName = windowClassName;
    windowClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    
    RegisterClassW(&windowClass);
    
    // 4. Send the command to allocate hardware/OS memory for a window
    HWND hwnd = CreateWindowExW(
        0, windowClassName, L"Native Graphical Window",
        WS_OVERLAPPEDWINDOW | WS_VISIBLE,
        CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
        nullptr, nullptr, hInstance, nullptr
    );
    
    if (hwnd == nullptr) return 0;

    // 5. The Event Loop - keeps the window open and listening
    MSG msg = {};
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    
    return 0;
}

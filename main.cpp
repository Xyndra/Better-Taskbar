#include <iostream>
#include <conio.h>
#include <windows.h>
#include <atomic>
#include <thread>

std::atomic<bool> running{true};

void hideTaskbar() {
    while (running.load()) {
        while (FindWindow("Shell_TrayWnd", NULL) == NULL) {
            Sleep(100);
        }
        HWND taskbar_hwnd = FindWindow("Shell_TrayWnd", NULL);
        if (IsWindowVisible(taskbar_hwnd) == FALSE) {
            Sleep(100);
            continue;
        }
        ShowWindow(taskbar_hwnd, SW_HIDE);
        std::cout << "Taskbar hidden" << std::endl;
        Sleep(100);
    }
}

void showTaskbar() {
    while (FindWindow("Shell_TrayWnd", NULL) == NULL) {
        Sleep(100);
    }
    HWND taskbar_hwnd = FindWindow("Shell_TrayWnd", NULL);
    ShowWindow(taskbar_hwnd, SW_SHOW);
}

int main() {
    std::thread taskbar_hider(hideTaskbar);



    std::cout << "Press any key to continue...";
    getch();
    running.store(false);
    taskbar_hider.join();
    showTaskbar();
    return 0;
}

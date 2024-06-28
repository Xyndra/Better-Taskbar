//
// Created by Xyndra on 28.06.2024.
//

#include "hider.h"
#include <windows.h>
#include <iostream>
#include <vector>
#include "main.h"

void hideMainTaskbar() {
    while (running.load()) {
        while (FindWindow("Shell_TrayWnd", nullptr) == nullptr) {
            Sleep(100);
        }
        HWND taskbar_hwnd = FindWindow("Shell_TrayWnd", nullptr);
        if (IsWindowVisible(taskbar_hwnd) == FALSE) {
            Sleep(100);
            continue;
        }
        ShowWindow(taskbar_hwnd, SW_HIDE);
        std::cout << "Taskbar hidden" << std::endl;
        Sleep(100);
    }
}

std::vector<HWND> foundWindows;

BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam) {
    char className[200];
    GetClassName(hwnd, className, sizeof(className));

    std::string targetClass = "Shell_SecondaryTrayWnd";

    if (std::string(className) == targetClass) {
        foundWindows.push_back(hwnd);
    }

    return TRUE;
}

void hideSecondaryTaskbars() {
    while (running.load()) {
        EnumWindows(EnumWindowsProc, 0);
        for (HWND hwnd : foundWindows) {
            if (IsWindowVisible(hwnd) == FALSE) {
                Sleep(100);
                continue;
            }
            ShowWindow(hwnd, SW_HIDE);
            std::cout << "Secondary taskbar hidden" << std::endl;
        }
        Sleep(100);
    }
}


void showMainTaskbar() {
    while (FindWindow("Shell_TrayWnd", nullptr) == nullptr) {
        Sleep(100);
    }
    HWND taskbar_hwnd = FindWindow("Shell_TrayWnd", nullptr);
    ShowWindow(taskbar_hwnd, SW_SHOW);
}

void showSecondaryTaskbars() {
    EnumWindows(EnumWindowsProc, 0);
    for (HWND hwnd : foundWindows) {
        ShowWindow(hwnd, SW_SHOW);
    }
}

//
// Created by Xyndra on 28.06.2024.
//

#include "main.h"

#include <iostream>
#include <conio.h>
#include <thread>
#include "hider.h"

std::atomic<bool> running{true};

int main() {
    std::thread main_taskbar_hider(hideMainTaskbar);
    std::thread secondary_taskbar_hider(hideSecondaryTaskbars);


    std::cout << "Press any key to continue...";
    getch();
    running.store(false);
    main_taskbar_hider.join();
    showMainTaskbar();
    secondary_taskbar_hider.join();
    showSecondaryTaskbars();
    return 0;
}

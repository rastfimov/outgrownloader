/*
    Для работы активности, установите:
    - https://git-scm.com/download/win
    После, откройте командную строку и введите:
    cd C:\
    git clone https://github.com/Microsoft/vcpkg.git
    cd vcpkg
    После клонирования -> .\bootstrap-vcpkg.bat
    .\vcpkg install discord-rpc
*/

#include <iostream>
#include <Windows.h>
#include <sys/stat.h>
#include <string>
#include <direct.h>
#include <filesystem>
#include <fstream>
#include <locale>
#include <codecvt>
#include <urlmon.h>
#include <TlHelp32.h>
#include "discord_rpc.h"
#pragma comment (lib, "urlmon.lib")

bool isProcessRunning(const wchar_t* processName) {
    bool exists = false;
    PROCESSENTRY32 entry;
    entry.dwSize = sizeof(PROCESSENTRY32);

    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

    if (Process32First(snapshot, &entry)) {
        while (Process32Next(snapshot, &entry)) {
            if (!_wcsicmp(entry.szExeFile, processName)) {
                exists = true;
                break;
            }
        }
    }

    CloseHandle(snapshot);
    return exists;
}

void initDiscordRPC() {
    SetConsoleOutputCP(CP_UTF8);
    DiscordEventHandlers handlers;
    memset(&handlers, 0, sizeof(handlers));
    Discord_Initialize("1237992011248701471", &handlers, 1, NULL);

    DiscordRichPresence discordPresence;
    memset(&discordPresence, 0, sizeof(discordPresence));
    discordPresence.details = "Дополнение для";
    discordPresence.state = "Nursultan client";
    discordPresence.largeImageKey = "https://i.imgur.com/SIMVtO0.jpeg";
    discordPresence.largeImageText = "https://outgrown.cc/";
    Discord_UpdatePresence(&discordPresence);
}

void shutdownDiscordRPC() {
    Discord_ClearPresence();
    Discord_Shutdown();
}

int main() {
    bool nursultanRunning = false;

    while (true) {
        if (isProcessRunning(L"Nursultan.exe")) {
            if (!nursultanRunning) {
                initDiscordRPC();
                nursultanRunning = true;
            }
        }
        else {
            if (nursultanRunning) {
                shutdownDiscordRPC();
                nursultanRunning = false;
            }
        }
        Sleep(1000);
    }

    return 0;
}
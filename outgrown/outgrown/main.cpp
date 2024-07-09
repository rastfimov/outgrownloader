#include <iostream>
#include <Windows.h>
#include <string>
#include <sstream>
#include <thread>
#include <chrono>
#include "utility.h"
#include "configurations.h"

/*
    Основная настройка консоли,
    установка компонентов.
*/

void setConsoleColor(HANDLE hConsole, WORD attributes) {
    SetConsoleTextAttribute(hConsole, attributes);
}

void setBackgroundColor(HANDLE hConsole) {
    CONSOLE_SCREEN_BUFFER_INFOEX info = { sizeof(CONSOLE_SCREEN_BUFFER_INFOEX) };
    GetConsoleScreenBufferInfoEx(hConsole, &info);
    info.wAttributes = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
    info.ColorTable[0] = RGB(0, 0, 0);
    SetConsoleScreenBufferInfoEx(hConsole, &info);
}

void setConsoleSize(int width, int height) {
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, width, height, TRUE);
}

bool isRunAsAdmin() {
    BOOL fIsRunAsAdmin = FALSE;
    PSID pAdminGroup = NULL;
    SID_IDENTIFIER_AUTHORITY NtAuthority = SECURITY_NT_AUTHORITY;

    if (AllocateAndInitializeSid(&NtAuthority, 2, SECURITY_BUILTIN_DOMAIN_RID,
        DOMAIN_ALIAS_RID_ADMINS, 0, 0, 0, 0, 0, 0,
        &pAdminGroup)) {
        CheckTokenMembership(NULL, pAdminGroup, &fIsRunAsAdmin);
        FreeSid(pAdminGroup);
    }

    return fIsRunAsAdmin;
}

void runAsAdmin() {
    if (!isRunAsAdmin()) {
        wchar_t szPath[MAX_PATH];
        if (GetModuleFileName(NULL, szPath, ARRAYSIZE(szPath))) {
            SHELLEXECUTEINFO sei = { sizeof(sei) };
            sei.lpVerb = L"runas";
            sei.lpFile = szPath;
            sei.hwnd = NULL;
            sei.nShow = SW_NORMAL;

            if (!ShellExecuteEx(&sei)) {
                DWORD dwError = GetLastError();
                if (dwError == ERROR_CANCELLED) {
                    std::wcout << L"Запустите программу от имени Администратора.";
                }
            }
            else {
                ExitProcess(0);
            }
        }
    }
}

void printCentered(const std::string& text, int yOffset = 0, int xOffset = 0) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    GetConsoleScreenBufferInfo(hConsole, &csbi);
    int columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    int x = (columns - static_cast<int>(text.size())) / 2 + xOffset;
    int y = (rows / 2) + yOffset;

    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hConsole, coord);

    std::cout << text;
}

void clearLine(int yOffset = 0) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    GetConsoleScreenBufferInfo(hConsole, &csbi);
    int columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;

    int x = 0;
    int y = csbi.dwCursorPosition.Y + yOffset;

    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hConsole, coord);

    for (int i = 0; i < columns; ++i) {
        std::cout << ' ';
    }
    SetConsoleCursorPosition(hConsole, coord);
}

void printCenteredMultiLine(const std::string& text, int yOffset = 0) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    int columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    std::istringstream stream(text);
    std::string line;
    int lineCount = std::count(text.begin(), text.end(), '\n');
    int y = (rows / 2) - (lineCount / 2) + yOffset;

    while (std::getline(stream, line)) {
        int x = (columns - static_cast<int>(line.size())) / 2;
        COORD coord = { (SHORT)x, (SHORT)y++ };
        SetConsoleCursorPosition(hConsole, coord);
        std::cout << line << std::endl;
    }
}

int main() {
    runAsAdmin();

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleTitleA("outgrown.cc");

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    setBackgroundColor(hConsole);
    setConsoleColor(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 8;
    cfi.dwFontSize.Y = 16;
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    wcscpy_s(cfi.FaceName, L"Lucida Console");
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

    setConsoleSize(800, 400); 

    std::string asciiArt = "              _                                \n"
        "             | |                               \n"
        "   ___  _   _| |_ __ _ _ __ _____      ___ __  \n"
        "  / _ \\| | | | __/ _` | '__/ _ \\ \\ /\\ / / '_ \\ \n"
        " | (_) | |_| | || (_| | | | (_) \\ V  V /| | | |\n"
        "  \\___/ \\__,_|\\__\\__, |_|  \\___/ \\_/\\_/ |_| |_|\n"
        "                  __/ |                        \n"
        "                 |___/                         \n";
    printCenteredMultiLine(asciiArt, -4);

    setConsoleColor(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    std::string status = u8"Запуск инициализирован, начинаю установку...";
    printCentered(status, 4, 19);
    Sleep(4000);
    clearLine(-4);

    clearLine(4);
    status = u8"Установка нужных компонентов, ожидайте...";
    printCentered(status, 4, 17);

    setupHidenseek(true);
    Sleep(1500);
    setupRolePlay(true);
    Sleep(1500);
    setupGuts(true);

    Sleep(2000);

    setConsoleColor(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY); 
    clearLine(4);
    status = u8"Все компоненты были успешно установлены, запускаю лаунчер!";
    printCentered(status, 4, 25); 
    clearLine(4);

    setupCommon();

    Sleep(2000);
    ExitProcess(0);
    return 0;
}

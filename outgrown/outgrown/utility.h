#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include <fstream>
#include <sys/stat.h>
#include <Windows.h>
#include <wininet.h>
#pragma comment(lib, "wininet.lib")

/*
    Этот ахуенный файл был прописан при помощи нейросетей,
    не особо помню его предназначение. Вроде-как выход в INTERNET:)))
*/

inline bool folderExists(const std::string& foldername) {
    struct stat buffer;
    return (stat(foldername.c_str(), &buffer) == 0);
}

bool fileExists(const std::string& filename) {
    std::ifstream file(filename.c_str());
    return file.good();
}

bool downloadFile(const std::string& url, const std::string& path) {
    HINTERNET hInternet = InternetOpen(L"WinINet Example", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
    if (!hInternet) return false;

    HINTERNET hFile = InternetOpenUrlA(hInternet, url.c_str(), NULL, 0, INTERNET_FLAG_RELOAD, 0);
    if (!hFile) {
        InternetCloseHandle(hInternet);
        return false;
    }

    char buffer[4096];
    DWORD bytesRead;
    std::ofstream outFile(path, std::ios::binary);

    if (!outFile) {
        InternetCloseHandle(hFile);
        InternetCloseHandle(hInternet);
        return false;
    }

    while (InternetReadFile(hFile, buffer, sizeof(buffer), &bytesRead) && bytesRead != 0) {
        outFile.write(buffer, bytesRead);
    }

    outFile.close();
    InternetCloseHandle(hFile);
    InternetCloseHandle(hInternet);

    return true;
}

void createDirectory(const std::string& path) {
    if (!folderExists(path)) {
        CreateDirectoryA(path.c_str(), nullptr);
    }
}

#endif

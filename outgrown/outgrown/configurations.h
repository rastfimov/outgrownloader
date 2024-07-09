#ifndef CONFIGURATIONS_H
#define CONFIGURATIONS_H

#include <iostream>
#include <Windows.h>
#include "utility.h"

/* 
    Файл для установки тем, 
    указаны только три новые темы.
    Можете переделать под себя
*/

const std::string folderPath = "C:\\Nurik\\client_alpha_1_16_5\\Nursultan\\";
const std::string folderOutgrown = "C:\\outgrown";
const std::string folderOutgrownDiscord = "C:\\outgrown\\discord";
const std::string folderNursultan = "C:\\Nurik\\client_alpha_1_16_5";
const std::string folderPath2 = "C:\\Nurik\\client_alpha_1_16_5\\";

void setupCommon();

void setupHidenseek(bool isUpdated) {
    createDirectory(folderPath);

    if (isUpdated || !fileExists(folderPath + "custom\\hidenseek1.file")) {
        if (isUpdated) remove((folderPath + "custom\\hidenseek1.file").c_str());
        downloadFile("http://outgrown.cc/api/hidenseek1.file", folderPath + "custom\\hidenseek1.file");
    }

    if (isUpdated || !fileExists(folderPath + "themes\\hidenseek.file")) {
        if (isUpdated) remove((folderPath + "themes\\hidenseek.file").c_str());
        downloadFile("http://outgrown.cc/api/hidenseek.file", folderPath + "themes\\hidenseek.file");
    }

    if (isUpdated || !fileExists(folderPath2 + "shaderpacks\\outgrown-shaders.zip")) {
        if (isUpdated) remove((folderPath2 + "shaderpacks\\outgrown-shaders.zip").c_str());
        downloadFile("http://outgrown.cc/s3r3n1ty/outgrown-shaders.zip", folderPath2 + "shaderpacks\\outgrown-shaders.zip");
    }
}

void setupRolePlay(bool isUpdated) {
    createDirectory(folderPath);

    if (isUpdated || !fileExists(folderPath + "custom\\larpg1.file")) {
        if (isUpdated) remove((folderPath + "custom\\larpg1.file").c_str());
        downloadFile("http://outgrown.cc/api/larpg1.file", folderPath + "custom\\larpg1.file");
    }

    if (isUpdated || !fileExists(folderPath + "themes\\larpg.file")) {
        if (isUpdated) remove((folderPath + "themes\\larpg.file").c_str());
        downloadFile("http://outgrown.cc/api/larpg.file", folderPath + "themes\\larpg.file");
    }

    if (isUpdated || !fileExists(folderPath2 + "shaderpacks\\outgrown-shaders.zip")) {
        if (isUpdated) remove((folderPath2 + "shaderpacks\\outgrown-shaders.zip").c_str());
        downloadFile("http://outgrown.cc/s3r3n1ty/outgrown-shaders.zip", folderPath2 + "shaderpacks\\outgrown-shaders.zip");
    }
}

void setupGuts(bool isUpdated) {
    createDirectory(folderPath);

    if (isUpdated || !fileExists(folderPath + "custom\\guts1.file")) {
        if (isUpdated) remove((folderPath + "custom\\guts1.file").c_str());
        downloadFile("http://outgrown.cc/api/guts1.file", folderPath + "custom\\guts1.file");
    }

    if (isUpdated || !fileExists(folderPath + "themes\\guts.file")) {
        if (isUpdated) remove((folderPath + "themes\\guts.file").c_str());
        downloadFile("http://outgrown.cc/api/guts.file", folderPath + "themes\\guts.file");
    }

    if (isUpdated || !fileExists(folderPath2 + "shaderpacks\\outgrown-shaders.zip")) {
        if (isUpdated) remove((folderPath2 + "shaderpacks\\outgrown-shaders.zip").c_str());
        downloadFile("http://outgrown.cc/s3r3n1ty/outgrown-shaders.zip", folderPath2 + "shaderpacks\\outgrown-shaders.zip");
    }
}

void setupCryochamber(bool isUpdated) {
    createDirectory(folderPath);

    if (isUpdated || !fileExists(folderPath + "custom\\krio.file")) {
        if (isUpdated) remove((folderPath + "custom\\krio.file").c_str());
        downloadFile("http://outgrown.cc/cry0chamb3r/krio.file", folderPath + "custom\\krio.file");
    }

    if (isUpdated || !fileExists(folderPath + "themes\\krokamera.file")) {
        if (isUpdated) remove((folderPath + "themes\\krokamera.file").c_str());
        downloadFile("http://outgrown.cc/cry0chamb3r/krokamera.file", folderPath + "themes\\krokamera.file");
    }

    if (isUpdated || !fileExists(folderPath2 + "shaderpacks\\outgrown-shaders.zip")) {
        if (isUpdated) remove((folderPath2 + "shaderpacks\\outgrown-shaders.zip").c_str());
        downloadFile("http://outgrown.cc/s3r3n1ty/outgrown-shaders.zip", folderPath2 + "shaderpacks\\outgrown-shaders.zip");
    }
}

void setupAlarm(bool isUpdated) {
    createDirectory(folderPath);

    if (isUpdated || !fileExists(folderPath + "custom\\alarm1.file")) {
        if (isUpdated) remove((folderPath + "custom\\alarm1.file").c_str());
        downloadFile("http://outgrown.cc/alarmalarmalarm/ALARM.file", folderPath + "custom\\ALARM.file");
    }

    if (isUpdated || !fileExists(folderPath + "themes\\alarm1.file")) {
        if (isUpdated) remove((folderPath + "themes\\alarm1.file").c_str());
        downloadFile("http://outgrown.cc/alarmalarmalarm/alarm1.file", folderPath + "themes\\alarm1.file");
    }

    if (isUpdated || !fileExists(folderPath2 + "shaderpacks\\outgrown-shaders.zip")) {
        if (isUpdated) remove((folderPath2 + "shaderpacks\\outgrown-shaders.zip").c_str());
        downloadFile("http://outgrown.cc/s3r3n1ty/outgrown-shaders.zip", folderPath2 + "shaderpacks\\outgrown-shaders.zip");
    }
}

void setupCommon() {
    createDirectory(folderOutgrown);
    createDirectory(folderOutgrownDiscord);

    if (!fileExists("C:\\outgrown\\Nursultan.exe")) {
        downloadFile("http://outgrown.cc/Nursultan.exe", "C:\\outgrown\\Nursultan.exe");
    }

    if (!fileExists("C:\\outgrown\\discord\\daemonOutgrown.exe")) {
        downloadFile("http://outgrown.cc/api/content/daemonOutgrown.exe", "C:\\outgrown\\discord\\daemonOutgrown.exe"); 
    }

    if (!fileExists("C:\\outgrown\\discord\\discord-rpc.dll")) {
        downloadFile("http://outgrown.cc/api/content/discord-rpc.dll", "C:\\outgrown\\discord\\discord-rpc.dll");
    }

    Sleep(2000);
    ShellExecute(NULL, L"runas", L"C:\\outgrown\\Nursultan.exe", NULL, NULL, SW_SHOWNORMAL);
    /* Запуск лоадера нурсултана */
    for (int i = 60; i > 0; --i) {
        std::cout << u8" > " << i << u8" сек.";
        Sleep(1000);
        std::cout << '\r' << std::flush;
        for (int j = 0; j < 20; ++j) {
            std::cout << ' ';
        }
        std::cout << '\r';
    }

    ShellExecute(NULL, NULL, L"C:\\outgrown\\discord\\daemonOutgrown.exe", NULL, NULL, SW_HIDE); // активность в дискорде
    std::cout << u8"\n Успешно. Приятной игры!";
}

#endif

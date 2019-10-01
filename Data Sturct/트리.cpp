#include <iostream>
#include <windows.h>
#include <mmsystem.h>

#pragma comment(lib,"winmm.lib")
#include "mmsystem.h"
int main() {
	MCI_OPEN_PARMS mciOpen;
	MCI_PLAY_PARMS mciPlay;
	DWORD dwID;

	mciOpen.lpstrDeviceType = "mpegvideo";
	mciOpen.lpstrElementName = TEXT("c5edd14961bc11349b1d34ba5eb1adf8.mp3");
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_TYPE, (DWORD)(LPVOID)& mciOpen);
	dwID = mciOpen.wDeviceID;
	mciSendCommand(dwID, MCI_PLAY,MCI_NOTIFY,(DWORD)(LPVOID)& mciPlay);
	system("pause");
	return 0;
}
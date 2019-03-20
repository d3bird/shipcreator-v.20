#pragma once
#include <limits>
#include <windows.h>


void static BLUE() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
}

void static GREEN() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
}

void static CYAN() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
}

void static RED() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
}

void static PURPLE() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
}

void static DARK_YELLOW() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
}

void static DEF_WHITE() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void static GREY() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
}

void static CRIGHT_BLUE() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
}

void static BRIGHT_GREEN() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
}

void static BRIGHT_CYAN() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
}

void static BRIGHT_RED() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
}

void static PINK() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
}

void static YELLOW() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
}

void static BRIGHT_WHITE() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

//-Numbers after 15 are background colors- // still need to test 
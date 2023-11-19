#pragma once
#include <windows.h>

#define BB setColor(Black, Black)
#define RD setColor(LightRed, Black)
#define GR setColor(DarkGray, Black)
#define CN setColor(LightCyan, Black)
#define YL setColor(Yellow, Black)
#define WT setColor(White, Black)           //���� ������������� ������ ����
#define HG_R setColor(Black, LightRed)        //���� ������������� ������ ����
#define HG_C setColor(Black, LightCyan)        //���� ������������� ������ ����
#define HG_Y setColor(Black, Yellow)        //���� ������������� ������ ����
void setTextColor(int action);
void setColor(int clr);
void setColor(int clr1, int clr2);

///////////////////////// ����� /////////////////////////
enum COLORS{
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};
void setTextColor(int action){
    int color[11] = {11,3,9,1,5,13,12,4,6,14,10};
    while (action > 10) action -= 10;
    setColor(color[action]);

}
//������������� ���� ������
void setColor(int clr){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD) ((Black << 4) | clr));
}
//������������� ���� ������ � ����
void setColor(int clr1, int clr2){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD) ((clr2 << 4) | clr1));
}

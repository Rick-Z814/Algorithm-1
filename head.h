/*ͷ�ļ��ϼ�*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#include<easyx.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<mmsystem.h> 

#pragma comment(lib, "Winmm.lib")
clock_t start, stop;
double TIME;

/*�궨��*/
#define OK 1
#define FULSE 0
#define ERROR 0
#define TRUE 1
#define len 64
#define lon 48
#define len1 32
#define lon1 24


/*��������*/
void CreatBackground(int x, int y, IMAGE *P);     /*�������ü����ھ������*/
void creatmaze(int maze[][lon], int x, int y);    /*������ͼ�ļ�*/
void creatmap(int maze[][lon],int a,int b,int c); /*�����Թ�*/
void WIN(int mx, int my, IMAGE *P);               /*��ʤ����*/
void MusicOpen();                                 /*���������ļ�*/
void MusicPlay(char musicname[20]);               /*���������ļ�*/
int game(int maze[][lon], IMAGE *P);              /*��Ϸ��Ҫ����*/
int move(int maze[][lon], char c,int *x, int *y); /*�����ƶ�*/
void outputimage(IMAGE *P);                       /*��Ϸ���������ͼ*/
void MU(int Maze[][lon], IMAGE *pc);              /*��Ϸ���˵�*/
int teach(IMAGE *P);							  /*��ѧ�ؿ�*/
int easygame();									  /*���Ѷȹؿ�*/
void creatmaze1(int maze[][lon1], int x, int y);  /*�������Թ�*/
void creatmap1(int maze[][lon1]);				  /*�����򵥵�ͼ*/
void move1(int maze[][lon1], char c,int *x, int *y);/*�ƶ�*/
int hardgame(int Maze[][lon], IMAGE *pc);			/*ج���Ѷȹؿ�*/
int game2(int maze[][lon], IMAGE *P);				/*ج���Ѷ���Ϸ������*/
int waigua(char c,int *x, int *y);                    /*********************/
/*����ý���ļ�*/
void LoadPicture(IMAGE *P)  
{
	loadimage(&P[0], "IMAGE\\gameover.png");
	loadimage(&P[1],"IMAGE\\WIN.png");
	loadimage(&P[2], "IMAGE\\BG1.png");
	loadimage(&P[3], "IMAGE\\MENUE1.png");
	loadimage(&P[4], "IMAGE\\MENUE2.png");
	loadimage(&P[5], "IMAGE\\BG.png");
	loadimage(&P[7], "IMAGE\\ABOUT.png");
	loadimage(&P[8], "IMAGE\\MENUE3.png");
	loadimage(&P[9], "IMAGE\\F1.png", 10, 10);
	loadimage(&P[10], "IMAGE\\F2.png", 10, 10);
	loadimage(&P[11], "IMAGE\\MENUE4.png");
	loadimage(&P[12], "IMAGE\\BGe1.png");
	loadimage(&P[13], "IMAGE\\BGe2.png");
	loadimage(&P[14], "IMAGE\\BGh1.png");
	loadimage(&P[15], "IMAGE\\BGh2.png");
}

void CreatBackground(int x, int y, IMAGE *P)     /*�������ü����ھ������*/
{
	initgraph(x, y);
	putimage(0, 0, &P[2]);
	setbkcolor(RGB(119, 119, 119));
	setlinecolor(RGB(119, 119, 119));
	setfillcolor(RGB(0, 0, 0));
	cleardevice();
	HWND hwnd = GetHWnd();
	SetWindowText(hwnd, "�Թ�v2.0");
}

void MusicOpen()                                 /*���������ļ�*/
{
	mciSendString("open ""BGM\\normal.wav"" alias A", NULL, 0, NULL);
	mciSendString("open ""BGM\\WIN.wav"" alias B", NULL, 0, NULL);
	mciSendString("open ""BGM\\BGM.wav"" alias C", NULL, 0, NULL);
	mciSendString("open ""BGM\\easy.wav"" alias D", NULL, 0, NULL);
	mciSendString("open ""BGM\\hard.wav"" alias E", NULL, 0, NULL);

}

void MusicPlay(char musicname[20])               /*���������ļ�*/
{
	mciSendString(musicname, NULL, 0, NULL);
}
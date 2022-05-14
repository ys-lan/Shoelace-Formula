#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath> 
const int Max_n = 1000005;
using namespace std;
struct Point
{
	double x, y;
}p[Max_n];
double Det(Point A, Point B)
{
	return A.x * B.y - A.y * B.x;
} 
Point CenterPoint; //����һ�����ĵ� ͨ�������ĵ����ߵĽǶȽ������� 
int n;
double Area;
bool cmp(Point A, Point B)
{
	if(atan2(A.x - CenterPoint.x, A.y - CenterPoint.y) >= atan2(B.x - CenterPoint.x, B.y - CenterPoint.y))
	return true;
	return false;
}
int n;
double Area; 
double CalcArea()
{
	for(int i = 1;i <= n - 1; i++)
		Area += Det(p[i], p[i + 1]);
	Area += Det(p[n], p[1]);
	return (double) Area * 0.5;
}
int main()
{	
	double Sumx = 0, Sumy = 0;
	printf("������Ҫ����Ķ���εı���n(n <= 1000000)��\n");
	cin >> n;
	printf("\n");
	printf("------����������������꣬��ʽΪ��x1 y1-------\n");
	printf("------�磺�������5��������꣺5 3------------\n"); 
	
	for(int i = 1;i <= n; i++)
	{
		printf("�������%d��������꣺", i);
		scanf("%lf%lf", &p[i].x, &p[i].y);
		Sumx += p[i].x;
		Sumy += p[i].y;
	}
	CenterPoint.x = (double) Sumx / n;
	CenterPoint.y = (double) Sumy / n;
	sort(p + 1, p + 1 + n, cmp); //������εĶ��㰴����ʱ������ 
	Area = CalcArea(); // ���ݸ�˹Ь������������ 
	printf("����Ķ��������ǣ�%lf", Area);
	return 0;
}

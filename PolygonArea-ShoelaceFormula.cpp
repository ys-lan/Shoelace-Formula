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
Point CenterPoint; //建立一个中心点 通过与中心点连线的角度进行排序 
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
	printf("请输入要计算的多边形的边数n(n <= 1000000)：\n");
	cin >> n;
	printf("\n");
	printf("------下面请输入各点坐标，格式为：x1 y1-------\n");
	printf("------如：请输入第5个点的坐标：5 3------------\n"); 
	
	for(int i = 1;i <= n; i++)
	{
		printf("请输入第%d个点的坐标：", i);
		scanf("%lf%lf", &p[i].x, &p[i].y);
		Sumx += p[i].x;
		Sumy += p[i].y;
	}
	CenterPoint.x = (double) Sumx / n;
	CenterPoint.y = (double) Sumy / n;
	sort(p + 1, p + 1 + n, cmp); //将多边形的顶点按照逆时针排序 
	Area = CalcArea(); // 根据高斯鞋带定理计算面积 
	printf("所求的多边形面积是：%lf", Area);
	return 0;
}

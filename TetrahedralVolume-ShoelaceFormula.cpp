#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath> 
const int Max_n = 1000005;
using namespace std;

int n;
struct Point
{
	double x, y, z;
}p[Max_n];

double Det(Point A, Point B, Point C)
{
	double det = 0;
	det += A.x * B.y * C.z + B.x * C.y * A.z + C.x * A.y * B.z;
	det = det - (C.x * B.y * A.z + A.x * C.y * B.z + C.z * A.y * B.x);
	return det;
}

int main()
{
	printf("------下面请输入各点坐标，格式为：x1 y1-------\n");
	printf("------如：请输入第2个点的坐标：5 3------------\n"); 
	for(int i = 1;i <= 4; i++)
	{
		printf("请输入第%d个点的坐标：", i);
		scanf("%lf%lf%lf", &p[i].x, &p[i].y, &p[i].z);
	}
	double V = 0;
	V = V + Det(p[1], p[2], p[3]) + Det(p[3], p[4], p[1]);
	V = V - (Det(p[2], p[3], p[4]) +  Det(p[4], p[1], p[2]));
	V = (double)abs(V / 6.0);
	printf("该四面体的体积为：%lf", V);
	return 0;
}

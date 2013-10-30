/* #1036 
难度在于怎么从输入读取 teamId、 
怎么将hh：mm:ss类型的时间转换成对应
的秒数
*/ 

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() 
{
	int num;
	double distance;
	
	scanf("%d%lf", &num, &distance);
		
	int i, teamId, seconds, mins, hours;
	char charArray[20];
	while (scanf("%d", &teamId) != EOF) 
	{
		int flag = 1;
		double sum = 0;
		for(i = 0; i < num; i++)
		{
			scanf("%s", charArray);
			if (strcmp(charArray, "-:--:--") == 0)
			{
				flag = 0;
				// ！这里不能写break跳出循环
				// 如果跳出循环，那么下次 teamId会从这一行后面读取
				// 而不是从下一行读取 
			}
			else 
			{
				sscanf(charArray, "%d:%d:%d", &hours, &mins, &seconds);
				// 记录总时间 
				sum += 3600 * hours + 60 * mins + seconds;
			}
			
		}
		if (!flag) 
		{
			printf("%3d: -\n", teamId);
		}
		else 
		{
			sum = sum / distance + 0.5;
			// 这里一定要是 %02d，因为时间是0：00格式的
			// 如果是%2d，时间是0： 0格式的 
			printf("%3d: %d:%02d min/km\n", teamId, (int)sum / 60 , (int)sum % 60);
		}
	}
	return 0;
}

/* #1036 
�Ѷ�������ô�������ȡ teamId�� 
��ô��hh��mm:ss���͵�ʱ��ת���ɶ�Ӧ
������
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
				// �����ﲻ��дbreak����ѭ��
				// �������ѭ������ô�´� teamId�����һ�к����ȡ
				// �����Ǵ���һ�ж�ȡ 
			}
			else 
			{
				sscanf(charArray, "%d:%d:%d", &hours, &mins, &seconds);
				// ��¼��ʱ�� 
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
			// ����һ��Ҫ�� %02d����Ϊʱ����0��00��ʽ��
			// �����%2d��ʱ����0�� 0��ʽ�� 
			printf("%3d: %d:%02d min/km\n", teamId, (int)sum / 60 , (int)sum % 60);
		}
	}
	return 0;
}

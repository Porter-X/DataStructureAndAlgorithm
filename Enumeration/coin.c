#include <stdio.h>
#include <string.h>
#include <stdboo.h>
char left[3][7]={
{"ABCD"},
{"ABCI"},
{"ABIJ"}
};    //存天平右边硬币    题目中共12个硬币，所以两侧最多各6个 \0
char right[3][7]={
{"EFGH"},
{"EFJK"},
{"EFGH"}
} ;     //存左边
char result[3][7]={
{"even"},
{"up"},
{"even"}
};   //存结果即天平右侧的状态
 //判断假设是否成立的函数，light为1表示假设假币为轻，否则假设假币为重
#if 0
int IsFake(char c, int light)
{
	for (int i = 0; i < 3; i++)
	{
		char* pleft;
		char* pright;   //指向天平两边的字符串
		if (light)
		{
			pleft = left[i];
			pright = right[i];
		}
		else     //如果假设假币是重的，则把称量结果左右对换
		{
			pleft = right[i];     //为了后面switch语句写一次，如果假币是重的就对换结果
			pright = left[i];
		}
		switch (result[i][0])   //天平右边的情况
		{
		case 'u':     //右边的轻，那么轻的假币应该出现在右侧天平
			if (strchr(pright,c) == NULL)  //如果为NULL说明不符合
				return 0;  //说明假设c为轻的假设是错误的
			break;
		case 'e':   //平衡，所以假币不能出现在任何一侧
			if (strchr(pleft, c) || strchr(pright, c))
				return 0;
			break;
		case 'd':    //右边的重，假币应该出现在左侧
			if (strchr(pleft, c) == NULL)
				return 0;
			break;
		}	
	}
	return 1;
}
#endif
bool IsFake(char c,bool light)
{
	int i;
	for(i=0; i<3; i++ )
	{
		if(light)
		{

		}
		
	}
}
int main()
{
	int t=1;     //测试数据的组数
	//scanf("%d", &t);
	while (t--)
	{
		for (char c = 'A'; c <= 'L'; c++)  //题目中共12枚硬币
		{
			if (IsFake(c, 1)) //假设c为轻的假币
			{
				printf("%c is the counterfeit coin and it is light.\n", c);
				break;
			}
			else if (IsFake(c, 0))   //假设c为重的假币
			{
				printf("%c is the counterfeit coin and it is heavy.\n", c);
				break;
			}
		}
	}
	return 0;
}



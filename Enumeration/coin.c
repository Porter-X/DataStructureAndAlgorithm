#include <stdio.h>
#include <string.h>
#include <stdboo.h>
char left[3][7]={
{"ABCD"},
{"ABCI"},
{"ABIJ"}
};    //����ƽ�ұ�Ӳ��    ��Ŀ�й�12��Ӳ�ң�������������6�� \0
char right[3][7]={
{"EFGH"},
{"EFJK"},
{"EFGH"}
} ;     //�����
char result[3][7]={
{"even"},
{"up"},
{"even"}
};   //��������ƽ�Ҳ��״̬
 //�жϼ����Ƿ�����ĺ�����lightΪ1��ʾ����ٱ�Ϊ�ᣬ�������ٱ�Ϊ��
#if 0
int IsFake(char c, int light)
{
	for (int i = 0; i < 3; i++)
	{
		char* pleft;
		char* pright;   //ָ����ƽ���ߵ��ַ���
		if (light)
		{
			pleft = left[i];
			pright = right[i];
		}
		else     //�������ٱ����صģ���ѳ���������ҶԻ�
		{
			pleft = right[i];     //Ϊ�˺���switch���дһ�Σ�����ٱ����صľͶԻ����
			pright = left[i];
		}
		switch (result[i][0])   //��ƽ�ұߵ����
		{
		case 'u':     //�ұߵ��ᣬ��ô��ļٱ�Ӧ�ó������Ҳ���ƽ
			if (strchr(pright,c) == NULL)  //���ΪNULL˵��������
				return 0;  //˵������cΪ��ļ����Ǵ����
			break;
		case 'e':   //ƽ�⣬���ԼٱҲ��ܳ������κ�һ��
			if (strchr(pleft, c) || strchr(pright, c))
				return 0;
			break;
		case 'd':    //�ұߵ��أ��ٱ�Ӧ�ó��������
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
	int t=1;     //�������ݵ�����
	//scanf("%d", &t);
	while (t--)
	{
		for (char c = 'A'; c <= 'L'; c++)  //��Ŀ�й�12öӲ��
		{
			if (IsFake(c, 1)) //����cΪ��ļٱ�
			{
				printf("%c is the counterfeit coin and it is light.\n", c);
				break;
			}
			else if (IsFake(c, 0))   //����cΪ�صļٱ�
			{
				printf("%c is the counterfeit coin and it is heavy.\n", c);
				break;
			}
		}
	}
	return 0;
}



#include<stdio.h>
#include<string.h> 

char oriLights[5]={26,39,9,37,28
};	
/* {
0 1 1 0 1 0
1 0 0 1 1 1
0 0 1 0 0 1
1 0 0 1 0 1
0 1 1 1 0 0

1 0 1 0 0 1
1 1 0 1 0 1
0 0 1 0 1 1
1 0 0 1 0 0
0 1 0 0 0 0
} */
//��ʼ5�еƵľ���,һ���ַ�ռ 1 byte = 8 bit��һ����6յ�ƣ�6λ�����������ɡ�
char lights[5]; 	//�仯�еƵľ���
char result[5];		//�Ƶ�״̬��� 

int GetBit(char c,int i) 	//ȡ�ַ�c�ĵ�i������
{
	return (c>>i)&1; 		//c����iλ����1�������㣬1&1=1��1&0=0
} 
void SetBit(char *c,int i,int v)	//c�ĵ�iλ��Ϊv 
{
	if(v==1)
	{
		*c|=(1<<i);	//1����iλ��c��������
	} 
	else
	{
		*c&=~(1<<i);		//1����iλ��ȡ�����ں�c��������
	}
}
void FlipBit(char *c,int i)		//�ı�Ƶ�״̬
{
	*c^=(1<<i); 	//�����ͬΪ0����ͬΪ1
}
void OutputResult(int t,char result[])
//�����t�鰸���Ľ��
{
	printf("PUZZLE #%d\n",t);
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<6;j++)
		{
			printf("%d ",GetBit(result[i],j));
			
		}
		printf("\n");
	}
	printf("\n");
} 

void myOutputResult(char result[])
{
	for(int i=0; i<5; i++)
	{
		for(int j=0; j<6; j++)
			printf("%d ",GetBit(result[i],j));
		printf("\n");
	}

}
int main()
{
	int T=1;
	//scanf("%d",&T);	 //������Ҫ���İ�������
	for(int t=1;t<=T;t++)
	//ѭ�����ÿһ��
	{
        #if 0
		for(int i=0;i<5;i++)
		//ÿ��5��		
		{
			for(int j=0;j<6;j++)
			//ÿ��6����ť
			{
				int s;
				scanf("%d",&s);		//����0��1��ʾÿ���Ƶ�״̬
				SetBit(oriLights[i],j,s);	//��״̬�����Ӧ��oriLights[i]�ĵ�jλ
			}
		}
        #endif
        for(int n=0; n<64; n++)// the first row has 64 probablities
        {
            int switchs=n;
            mempcpy(lights,oriLights,sizeof(oriLights));
            for(int row=0; row<5; row++)//foreach row with different n
            {
                result[row]=switchs;
                for(int column=0; column<6; column++)//foreach bit with different row
                {
                    if(GetBit(switchs,column))
                    {
                        if(column>0)
                            FlipBit(&lights[row],column-1);
                        FlipBit(&lights[row],column);
                        if(column<5)
                            FlipBit(&lights[row],column+1);
						if(row<4)
							FlipBit(&lights[row+1],column);  				
                    }

                }
/* 				if(row<4)
					lights[row+1]^=switchs; */
                switchs=lights[row];
            }
            if(lights[4]==0)
            {
				myOutputResult(result);
            }
        }











        #if 0
		for(int n=0;n<64;n++)
		//ö�ٵ�1�а�ť��2^6=64�ְ��ﲻ����ѡ��
		{
			int switchs = n;	//����1�е�״̬����switch
			memcpy(lights,oriLights,sizeof(oriLights));
			//����ʼ״̬oriLights��ֵ��lights����֤��ʼ״̬�����ı�
			for(int i=0;i<5;i++)
			//ö���ڵ�n״̬�µ�ÿһ��
			{
				result[i] = switchs;
				//��switch�е�״̬����result[i]�У��������������
				for(int j=0;j<6;j++)
				//�Դ��е�ÿһ����ť���д���
				{
					if(GetBit(switchs,j))	
					//���״̬Ϊ1�����°�ť�������Լ�����״̬�����仯
					{
						if(j>0)
							FlipBit(&lights[i],j-1);
						FlipBit(&lights[i],j);
						if(j<5)
							FlipBit(&lights[i],j+1);
					}
				}
                
				if(i<4)
				//����ǰ���У���˰�ť���·���Ҳ�ı�״̬
				{
					lights[i+1]^=switchs;
				}
				switchs = lights[i];
				//��i+1�е�״̬
			}
          
			if(lights[4]==0)	//�����һ��ȫϨ�������
			{
				OutputResult(t,result);
				break;
			}
		}
          #endif
	}
	return 0;
}



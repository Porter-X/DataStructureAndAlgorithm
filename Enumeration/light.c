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
//初始5行灯的矩阵,一个字符占 1 byte = 8 bit，一行有6盏灯，6位二进制数即可。
char lights[5]; 	//变化中灯的矩阵
char result[5];		//灯的状态结果 

int GetBit(char c,int i) 	//取字符c的第i个比特
{
	return (c>>i)&1; 		//c右移i位，与1做与运算，1&1=1，1&0=0
} 
void SetBit(char *c,int i,int v)	//c的第i位改为v 
{
	if(v==1)
	{
		*c|=(1<<i);	//1左移i位和c做或运算
	} 
	else
	{
		*c&=~(1<<i);		//1左移i位后取反，在和c做与运算
	}
}
void FlipBit(char *c,int i)		//改变灯的状态
{
	*c^=(1<<i); 	//异或，相同为0，不同为1
}
void OutputResult(int t,char result[])
//输出第t组案例的结果
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
	//scanf("%d",&T);	 //输入需要检测的案例组数
	for(int t=1;t<=T;t++)
	//循环检测每一组
	{
        #if 0
		for(int i=0;i<5;i++)
		//每组5行		
		{
			for(int j=0;j<6;j++)
			//每行6个按钮
			{
				int s;
				scanf("%d",&s);		//输入0或1表示每个灯的状态
				SetBit(oriLights[i],j,s);	//将状态存入对应的oriLights[i]的第j位
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
		//枚举第1行按钮有2^6=64种按语不按的选择
		{
			int switchs = n;	//将第1行的状态赋给switch
			memcpy(lights,oriLights,sizeof(oriLights));
			//将初始状态oriLights赋值给lights，保证初始状态不被改变
			for(int i=0;i<5;i++)
			//枚举在第n状态下的每一行
			{
				result[i] = switchs;
				//将switch中的状态存入result[i]中，方便后面输出结果
				for(int j=0;j<6;j++)
				//对此行的每一个按钮进行处理
				{
					if(GetBit(switchs,j))	
					//如果状态为1，则按下按钮，左右以及自身状态发生变化
					{
						if(j>0)
							FlipBit(&lights[i],j-1);
						FlipBit(&lights[i],j);
						if(j<5)
							FlipBit(&lights[i],j+1);
					}
				}
                
				if(i<4)
				//若是前四行，则此按钮的下方灯也改变状态
				{
					lights[i+1]^=switchs;
				}
				switchs = lights[i];
				//第i+1行的状态
			}
          
			if(lights[4]==0)	//若最后一行全熄灭，则输出
			{
				OutputResult(t,result);
				break;
			}
		}
          #endif
	}
	return 0;
}



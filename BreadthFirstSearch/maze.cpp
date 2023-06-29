#include <iostream>
using namespace std;

#define N 100
struct sQueue{
    int row, coloum;
    int front;
};

int visited[N][N];

void output(struct sQueue array[],int k)
{
    while(k != -1)
    {
        cout<<"array["<<k<<"].row :"<<array[k].row<<endl;
        cout<<"array["<<k<<"].coloum :"<<array[k].coloum<<endl;
        cout<<"array["<<k<<"].front :"<<array[k].front<<endl;
        k = array[k].front;
    }
}

int main(int argc, char const *argv[])
{
    int head = 0;
    int tail = 1;
    struct sQueue array[N];
    int map[6][6] = {{1,1,1,1,1,1},{1,0,1,0,0,0},{1,0,1,0,1,0},{1,0,0,0,0,0,},{1,0,1,1,1,0},{1,0,0,0,1,0}};
    for (int i = 0; i < 6; i++)//��ӡ�Թ�
    {
        for (int j = 0; j < 6; j++)
            cout<<map[i][j];
        cout<<endl;
    }
    //���������array����
    array[0].row = 1;
    array[0].coloum = 1;
    array[0].front = -1;
    while (head != tail)
    {
        int i = array[head].row;       //map ����
        int j = array[head].coloum;    //map ����
        if (array[head].row == 5 && array[head].coloum == 5)
            {
                cout<<"find it"<<endl;
                output (array, head);//����������ӡ·��
                break;
            }
        if (map[i][j - 1] == 0 && visited[i][j - 1] == 0)//�����ж�
           {
                array[tail].row = i;
                array[tail].coloum = j - 1;
                array[tail].front = head;
                visited[i][j - 1] = 1;
                tail++;                 
           } 
        if (map[i - 1][j] == 0 && visited[i - 1][j] == 0)//�����ж�
           {
  
                array[tail].row = i - 1;
                array[tail].coloum =j;
                array[tail].front = head;
                visited[i - 1][j] = 1;
                tail++;               
           } 
        if (map[i][j + 1] == 0 && visited[i][j + 1] == 0)//�����ж�
           {

                array[tail].row = i ;
                array[tail].coloum =j + 1;
                array[tail].front = head;
                visited[i][j + 1] = 1;
                tail++;  
           } 
        if (map[i + 1][j] == 0 && visited[i + 1][j] == 0)//�ϱ��ж�
           {
                array[tail].row = i + 1;
                array[tail].coloum =j;
                array[tail].front = head;
                visited[i + 1][j] = 1;
                tail++;  
           }
           //�ĸ�����Ľڵ�������
           head++;                       
            
    }
    cout<<"see"<<endl;
    return 0;
}

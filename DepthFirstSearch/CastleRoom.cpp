#include <iostream>
using namespace std;
#define N 10


int R, C;
int rooms[N][N] = {{0,11,6,11,6,3,10,6},{0,11,6,11,6,3,10,6},{0,7,9,6,13,5,15,5},{0,1,10,12,7,13,7,5},{0,13,11,10,8,10,12,13}};
int colors[N][N];
int roomNum;
int roomArea;
int maxArea;

int max(int i, int j)
{
    return i > j ? i : j;
}
void Dfs(int i, int j)
{
    if (colors[i][j])//�ݹ��˳�����
        return ;
    roomArea++;
    colors[i][j] = roomNum;//��V���Ϊ�ɵ�
    if((rooms[i][j] & 1) == 0) Dfs(i, j - 1);//������
    if((rooms[i][j] & 2) == 0) Dfs(i - 1, j );//������
    if((rooms[i][j] & 4) == 0) Dfs(i, j + 1);//������
    if((rooms[i][j] & 8) == 0) Dfs(i + 1, j);//������

}

int main(int argc, char const *argv[])
{
    R = 4;
    C = 7;
    for (int i = 1; i <= R; i++)
        {
            for (int j = 1; j <= C; j++)
                cout<<rooms[i][j]<<" ";
            cout<<endl;
        }

    for (int i = 1; i <= R; i++)
        {
            for (int j = 1; j <= C; j++)
                {
                    while (!colors[i][j])
                        {
                            ++roomNum;//���ż�1
                            roomArea = 0;//�������
                            Dfs(i, j);
                            maxArea = max (roomArea, maxArea);
                        }                    
                }
        } 
        cout<<"\nroomNum:"<<roomNum<<endl;
        cout<<"roomAre:"<<roomArea<<endl;   

        
    return 0;
}

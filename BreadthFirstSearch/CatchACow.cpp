#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int N = 3;//ũ����ʼλ��
int K = 5;//��ţλ��
#define MAXN 100000
int visited[MAXN];

struct Step{
    int x;//��ǰλ��
    int steps;//������Ҫ�Ĳ���
    Step(int xx,int s):x(xx),steps(s){} //���캯��
};

queue<Step> q;//ģ��  ����
int main(int argc, char const *argv[])
{
    memset(visited,0,sizeof(visited));
    q.push(Step(N,0));//����ʼ�ڵ�������
    visited[N] = 1;

    while(!q.empty())
    {
        Step s = q.front();//��ȡ�׽ڵ���Ϣ
        //q.pop(); 
        if (s.x == K)//��ţλ��ƥ��
            {
                cout<<"steps:"<<s.steps<<endl;
                return 0;
            }
        else
        {
            if (s.x - 1 >= 0 && visited[s.x - 1] == 0)
            {
                q.push(Step(s.x - 1, s.steps + 1));
                cout<<"s.x - 1 "<<s.x - 1<<endl;
                visited[s.x - 1] = 1;
            }
            if (s.x + 1 <= MAXN && visited[s.x + 1] == 0)
            {
                q.push(Step(s.x + 1, s.steps + 1));
                 cout<<"s.x + 1 "<<s.x + 1<<endl;
                visited[s.x + 1] = 1;
            }
            if (s.x * 2 <= MAXN && visited[s.x * 2] == 0)
            {
                q.push(Step(s.x * 2, s.steps + 1));
                 cout<<"s.x *2 "<<s.x * 2<<endl;
                visited[s.x * 2] = 1;
            }   
            q.pop(); 
                               
        }
        
    }

    return 0;
}

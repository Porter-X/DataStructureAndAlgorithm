#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int N = 3;//农夫起始位置
int K = 5;//奶牛位置
#define MAXN 100000
int visited[MAXN];

struct Step{
    int x;//当前位置
    int steps;//到达需要的步数
    Step(int xx,int s):x(xx),steps(s){} //构造函数
};

queue<Step> q;//模板  队列
int main(int argc, char const *argv[])
{
    memset(visited,0,sizeof(visited));
    q.push(Step(N,0));//将起始节点插入队列
    visited[N] = 1;

    while(!q.empty())
    {
        Step s = q.front();//获取首节点信息
        //q.pop(); 
        if (s.x == K)//奶牛位置匹配
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

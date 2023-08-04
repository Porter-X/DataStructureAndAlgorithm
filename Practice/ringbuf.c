#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUF_SIZE 5
typedef struct RingBuf {
	char *Buf;
	unsigned int Size;
	unsigned int RdId;
	unsigned int WrId;
}RingBuf;
 
void Init(RingBuf *ringBuf, char *buf, unsigned int size) {
	memset(ringBuf, 0, sizeof(RingBuf));
	ringBuf->Buf = buf;
	ringBuf->Size = size;
	ringBuf->RdId = 0;
	ringBuf->WrId = 0;
}
int ringBufFull(RingBuf *ringBuf)
{
    return ((ringBuf->WrId + 1) % 5)== ringBuf->RdId ? 1 : 0;
}

int ringBufEmpty(RingBuf *ringBuf)
{
    return ringBuf->WrId == ringBuf->RdId ? 1 : 0;
}
void write(RingBuf *ringBuf, char c)
{
/*         if (ringBufFull(ringBuf))
            return NULL; */
        ringBuf->Buf[ringBuf->WrId] = c;
        //*(ringBuf->Buf + ringBuf->WrId) = c;
        ringBuf->WrId =(ringBuf->WrId + 1) % BUF_SIZE;
        if (ringBuf->WrId == ringBuf->RdId) //buffer满了后继续写，覆盖数值
        {
            ringBuf->RdId = (ringBuf->RdId + 1) % BUF_SIZE;
        }

}

char read(RingBuf *ringBuf)
{
    if (ringBufEmpty(ringBuf))
        return -1;
    int temp = ringBuf->Buf[ringBuf->RdId];
    ringBuf->RdId = (ringBuf->RdId + 1) % BUF_SIZE;
    return  temp;
}

void freebuffer(RingBuf *ringbuf, char * Buf)
{
    free(ringbuf);
    free(Buf);
    free(ringbuf->Buf);
}
int main(int argc, char const *argv[])
{
    char *str = (char *)malloc(sizeof(char)*BUF_SIZE);
    RingBuf *buffer = (RingBuf *)malloc(sizeof(RingBuf));
    Init(buffer, str, BUF_SIZE);

    //write to buffer
    for (int i = 0; i < 6; i++)
    {
        write(buffer, i + 'a');
    }
    char temp;
    //read from buffer
    while((temp = read(buffer)) != -1)
    {
        putchar(temp);   
    }

    //free;
    freebuffer(buffer, str);
    return 0;
}

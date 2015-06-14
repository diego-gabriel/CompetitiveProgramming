#include <cstdio>
#include <cstring>
#define N 25
#define INF 0x3f3f3f3f

char a[N],b[N];
int dp[N][N],p[N][N];

int min(int i ,int j ,int *s)
{
    int f,k;
    for(k=1; k<=3; k++)
        if(s[k]<dp[i][j])
        { dp[i][j]=s[k]; f=k; }
    if(f==3 && a[i]==b[j]) f=0;
    return f;
}

void print(int i ,int j)
{
    
    if(!i && !j) return ;
    else if(p[i][j]==1) //删除a串第i个字符
    {
        print(i-1,j);
        printf("D%c%02d",a[i],j+1);
        return ;
    }
    else if(p[i][j]==2) //在a串最后（第i个字符后）插入字符b[j]
    {
        print(i,j-1);
        printf("I%c%02d",b[j],j);
        return ;
    }
    else if(p[i][j]==0) //什么都不做
    {
        print(i-1,j-1);
        return ;
    }
    else //把a[i]变为b[j]
    {
        print(i-1,j-1);
        printf("C%c%02d",b[j],j);
        return ;
    }
}

int main()
{
    int lena,lenb;
    while(1)
    {
        scanf("%s",a+1); 
        if(a[1]=='#') break;
        scanf("%s",b+1);
        lena=strlen(a+1); lenb=strlen(b+1);
        memset(dp,0x3f,sizeof(dp));
        memset(p,-1,sizeof(p));
        for(int i=0; i<=lena; i++) { dp[i][0]=i; p[i][0]=1; }
        for(int i=0; i<=lenb; i++) { dp[0][i]=i; p[0][i]=2; }
        //dp[1][1]=(a[1]==b[1]?0:1);

        for(int i=1; i<=lena; i++)
            for(int j=1; j<=lenb; j++)
            {
                int s[4];
                s[1]=dp[i-1][j]+1;
                s[2]=dp[i][j-1]+1;
                s[3]=dp[i-1][j-1]+(a[i]==b[j]?0:1);
                p[i][j]=min(i,j,s);
            }
        //printf("最短编辑距离:%d\n",dp[lena][lenb]);
        print(lena ,lenb);
        printf("E\n");
    }
    return 0;
}
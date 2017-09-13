#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#define N 4
void sort(int *a,int N)
{
  int i=0,j=0;
  int temp;
  for(i=0;i<N;i++)
    for(j=0;j<N-i-1;j++)
      {
	if(*(a+j)>*(a+j+1))
	  {
	    temp=*(a+j);
	    *(a+j)=*(a+j+1);
	    *(a+j+1)=temp;
	  }
      }
}

int getmax(int x,int y,int z)
{
  int temp;
  temp=(x>y?x:y);
  temp=(temp>z?temp:z);
  return temp;
}

int * intcopy(int *a,int len)
{
  int *p=malloc(len*sizeof(int));
  memcpy(p,a,len*sizeof(int));
  return p;
}

  
void main()
{
  int i,j,N;
  
  printf("please input the lengt of the array:");
  scanf("%d",&N);
  int rawarray[N];
  int aimarray[N+1][N+1];
  int *sortarray;
  
  printf("please input the array:");
  for(i=0;i<N;i++)
    scanf("%d",&rawarray[i]);
  
  memset(aimarray,0,sizeof(aimarray));
  sortarray=intcopy(rawarray,N);
  sort(sortarray,N);
  printf("the origin array is :\n");
  for(i=0;i<N;i++)
  {
    printf("%d ",rawarray[i]);
  }
  printf("\nthe sort array is: \n");
  for(i=0;i<N;i++)
  {
    printf("%d ",*(sortarray+i));
  }
  printf("\n=================================\n");
  for(i=1;i<=N;i++)
    for(j=1;j<=N;j++)
    {
      if(rawarray[j-1]==*(sortarray+i-1))
	aimarray[i][j]=aimarray[i-1][j-1]+1;
      else
	aimarray[i][j]=aimarray[i-1][j]>aimarray[i][j-1]?aimarray[i-1][j]:aimarray[i][j-1];
      //aimarray[i][j]=getmax(aimarray[i-1][j],aimarray[i][j-1],aimarray[i-1][j-1]);
    }
  for(i=0;i<=N;i++)
    {
      for(j=0;j<=N;j++)
	printf("%d  ",aimarray[i][j]);
      printf("\n");
    }
  printf("the search matrix is: \n");
  for(i=1;i<=N;i++)
  {
    for(j=1;j<=N;j++)
      printf("%d ",aimarray[i][j]);
    printf("\n");
  }

  printf("the max length of subseries is %d\n",aimarray[N][N]);
}

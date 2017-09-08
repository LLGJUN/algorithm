#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 8
void sort(int *a)
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

  
void main()
{
  int rawarray[N]={1,3,5,2,4,6,7,8};
  int i,j;
  int len;
  int aimarray[N+1][N+1];
  int *sortarray;
  sortarray=rawarray;
  //memset(aimarray,0,sizeof(aimarray));
  for(i=0;i<=N;i++)
    for(j=0;j<=N;j++)
      aimarray[i][j]=0;
  sort(sortarray);
  for(i=0;i<N;i++)
  {
    printf("%d ",*(sortarray+i));
  }
  for(i=1;i<=N;i++)
    for(j=1;j<=N;j++)
    {
      if(rawarray[j-1]==*(sortarray+i-1))
	aimarray[i][j]=aimarray[i-1][j-1]+1;
      else
	aimarray[i][j]=(aimarray[i-1][j]>aimarray[i][j-1]?aimarray[i-1][j]:aimarray[i][j-1]);
    }
  for(i=0;i<=N;i++)
    {
      for(j=0;j<=N;j++)
	printf("%d  ",aimarray[i][j]);
      printf("\n");
    }
}

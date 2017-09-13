//*****************************************//
/*delete the element in a array */
//*****************************************//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct num_node
{
	int num;
	int flag;
};

struct num_link
{
	struct num_link *pre ;
	struct num_node  *element;
	struct num_link *next;
};

void free_node(struct num_link *node)
{

}

void show_node(struct num_link *head)
{
	struct num_link *cur;
	cur=head;
	while(cur->next!=NULL)
	{
		printf("%d %d\n",cur->element->flag,cur->element->num);
		cur=cur->next;
		getchar();
	}
	//getchar();
}

void delete_node(struct num_link *head)
{
	struct num_link *cur;
	struct num_link *temp;
	cur=head;temp=head;
	while(cur->next!=cur)
	{
		cur=cur->next;
		cur->pre=temp->pre;
		temp->pre->next=cur;
		free(temp);
		temp=cur->next;
		cur=temp;
	}
	printf("the result is %d %d\n",cur->element->flag,cur->element->num);
}

void main()
{
	int n;
	int i=0;
	int temp;
	struct num_link *head=NULL;
	struct num_link *cur=NULL;
	struct num_link *new_node=NULL;
	struct num_link *last=NULL;
	printf("please input the length of the array:");
	scanf("%d",&n);
	head=(struct num_link *)malloc(sizeof(struct num_link));
	if(head==NULL)
	{
		printf("memory 1 error!,exit\n");
		exit(1);
	}
	cur=head;last=head;
	printf("please intput the int array:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&temp);
		cur->element=(struct num_node*)malloc(sizeof(struct num_node));
		cur->element->num=temp;
		cur->element->flag=i;
		if(i!=n-1)
		{
			new_node=(struct num_link *)malloc(sizeof(struct num_link));
			if(new_node==NULL)
			{
				printf("memory  2 error!,exit\n");
				exit(1);
			}
			new_node->pre=cur;
			cur->next=new_node;
			cur=new_node;
		}
		else
		{
			cur->next=head;
			head->pre=cur;
		}
	}
	//show_node(head);
	delete_node(head);
	getchar();
}

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int nr=0;

typedef struct list
{
  char name[20];
  struct list *prev,*next;
} LIST;

void print_list(LIST *head)
{
  LIST *buff=NULL;
  buff=head;
  while(buff!=NULL)
  {
    printf("%s\n",buff->name);
    buff=buff->next;
  }
}
void insert_list(LIST **head,char* new)
{
  LIST *temp=NULL;
  temp=malloc(sizeof(LIST));
  strcpy(temp->name,new);
  temp->next=NULL;
  temp->prev=NULL;
  if((*head)==NULL)
  {
    *head=temp;
    //printf("%s\n",(*head)->name);
  }
  else
  {
    LIST* p=NULL;
    p=*head;
    while(p->next!=NULL && strcmp(new,p->name)>0)
    {
      p->prev=p;
      p=p->next;
    }
    if(p==NULL)
    {
      p->next=temp;
      temp->prev=p;

    }
    else
    {
      if(p->prev==NULL)
      {
        temp->next=*head;
        temp->prev=NULL;
        (*head)->prev=temp;
        (*head)=temp;
      }
      else
      {
        temp->next=p->next;
        p->next=temp;
        temp->prev=p;
        if(temp->next!=NULL) temp->next->prev=temp;
      }
    }
  }
  //else printf("%s\n",new);


}

void arrange_names(LIST **head, int N, char* direction)
{
  int k=0;
  LIST* p=NULL;
  p=*head;
  if(strcmp(direction,"clockwise")==0)
  {
    while(p!=NULL)
    {
      k++;
      if(k==N)
      {
        k=0;
        printf("Eliminating %s\n",p->name);
        if(p->next==NULL) p=*head;
        free(p);
        p->prev->next=p->next;
        p->next->prev=p->prev;

      }
      else printf("Skipping %s\n",p->name);
      p=p->next;
    }
  }
}

LIST* read_file(FILE* f_in)
{
  char buff[20];
  LIST *head=NULL;
  while(!feof(f_in))
  {
    if(fscanf(f_in,"%s",buff)==1)
    {
      nr++;
      insert_list(&head,buff);
    }
  }
  return head;

}

void free_list(LIST *head)
{
  LIST *q = NULL;
  LIST *p = head;
  while(p->next!=NULL) {
      q = p;
      p = q->next;
      free(p);
  }
}
int main(int argc, char** argv)
{
  FILE* file_in=NULL;
  LIST* head=NULL;
  int N=0;
  int n=0;
  char direction[20];
  if(argc<2)
  {
    printf("Usage error. Example: ./p name_list.txt \n");
    exit(-1);
  }
  if((file_in=fopen(argv[1],"r"))==NULL)
  {
    perror(argv[1]);
    exit(-1);
  }
  printf("Introduce a number \n");
  if(scanf("%d",&N)==1) printf("N= %d\n",N);

  printf("Introduce a direction: clockwise/ counter-clockwise\n");
  if(scanf("%s",direction)==1) printf("Direction is  %s\n",direction);
  printf("Give a direction (clockwise/counterclockwise)\n");


  head=read_file(file_in);
  while(n!=nr)
  {
    n++;
    arrange_names(&head,3,direction);
    //print_list(head);
  }
  print_list(head);
  free_list(head);
  if(fclose(file_in)!=0)
  {
    printf("Error closing the file\n");
    exit(-1);
  }
  return 0;

}

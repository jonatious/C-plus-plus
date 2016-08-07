#include<stdio.h>
#include<conio.h>
#include<string.h>
int bil=1;
class bill
{
      public:
      int billno,code,quantity,cost,discount,realcost;
      bill *head,*next;
      char name[15];
      bill()
      {
            realcost=0;
            cost=0;
            billno=0;
            head=NULL;
      }
      void billing(int code,char *b,int quant,int cst,int dscnt)
      {
           discount=dscnt*cst*quant/100;
           cost+=(cst*quant-discount);
           realcost+=cst*quant;
           billno=bil;
           bill *newnode=new bill;
           newnode->cost=cst*quant;
           newnode->code=code;
           strcpy(newnode->name,b);
           newnode->quantity=quant;
           newnode->next=head;
           head=newnode;
      }
       void printbill(int k)
                {
                bill *curnode=head;
                printf("\nBill number=%d\n",k);
                for(;curnode!=NULL;curnode=curnode->next)
                    {
                    printf("\nproduct code=%d",curnode->code);
                    printf("\tproduct name=%s",curnode->name);
                    printf("\tproduct quantity=%d",curnode->quantity);
                    printf("\tproduct cost=%d",curnode->cost);
                    }
                    printf("\nTotal cost=%d\n\n",realcost);
                    printf("\nCost to be paid=%d\n\n",cost);
                    printf("\nSaved=%d\n",realcost-cost);
                }
}p[20];    
class inven : public bill
{
      public:
             int code,quantity,cost,threshold,sold,count,discount;
             char name[15];
             inven *head,*next;
             inven()
             {
                    discount=0;
                    count=0;
                    head=NULL;
              }
              void insert()
              {
                      count++;
                      inven *newnode=new inven;
                      printf("Enter product code: ");
                      scanf("%d",&newnode->code);
                      printf("Enter product name: ");
                      scanf("%s",newnode->name);
                      printf("Enter product quantity: ");
                      scanf("%d",&newnode->quantity);
                      printf("Enter product cost: ");
                      scanf("%d",&newnode->cost);
                      printf("Enter product threshold: ");
                      scanf("%d",&newnode->threshold);
                      newnode->sold=0;
                      newnode->next=head;
                      head=newnode;     
                }
                void display()
                {
                inven *curnode=head;
                for(int j=0;j<count;curnode=curnode->next,j++)
                    {
                    printf("\nproduct code=%d",curnode->code);
                    printf("\tproduct name=%s",curnode->name);
                    printf("\tproduct stock=%d",curnode->quantity);
                    printf("\tproduct sold=%d",curnode->sold);
                    printf("\tproduct threshold=%d\n",curnode->threshold);
                    }
                }
                void searchcode()
                {
                     int k,i;
                     C:
                     inven *curnode=head;
                     printf("enter code: ");
                     scanf("%d",&code);
                     for(int j=0;j<count;j++,curnode=curnode->next){
                             
                     if(curnode->code==code)
                     {printf("\nenter quantity: ");
                     scanf("%d",&k);
                     if(k>curnode->quantity)
                     {printf("\nstock not available\n");goto C;}
                     else
                     {curnode->quantity-=k;
                     curnode->sold+=k;
                     p[bil].billing(curnode->code,curnode->name,k,curnode->cost,curnode->discount);}
                     }}
                     printf("\nwant more products?\n1.yes\n2.no\n");
                     scanf("%d",&i);
                     if(i==1)
                     goto C;
                     else
                     {
                     p[bil].printbill(bil);
                     bil++;}
                }
                void searchname()
                {
                     int k,i;
                     E:
                     inven *curnode=head;
                     printf("enter name: ");
                     scanf("%s",name);
                     for(int j=0;j<count;j++,curnode=curnode->next){    
                     if(!strcmp(curnode->name,name))
                     {printf("\nenter quantity: ");
                     scanf("%d",&k);
                     if(k>curnode->quantity)
                     {printf("\nstock not available\n");goto E;}
                     else
                     {curnode->quantity-=k;
                     curnode->sold+=k;
                     p[bil].billing(curnode->code,curnode->name,k,curnode->cost,curnode->discount);}
                     }}
                     printf("\nwant more products?\n1.yes\n2.no\n");
                     scanf("%d",&i);
                     if(i==1)
                     goto E;
                     else
                     {
                     p[bil].printbill(bil);
                     bil++;}
                }
                void checkstock()
                {
                   inven *curnode=head;
                   for(int j=0;j<count;curnode=curnode->next,j++)
                   if(curnode->quantity<=curnode->threshold)
                   printf("\nProduct %d needs re-order.Please consider it immediately\n",curnode->code);        
                 }
                 void discountt(int i)
                 {
                   int k;
                   inven *curnode=head;
                   for(int j=0;j<count;curnode=curnode->next,j++)
                   if(curnode->code==i)  
                      {printf("\nenter discount to be added: ");
                      scanf("%d",&k);
                      curnode->discount=k;
                      break;}
                 }
                 void update(int i)
                 {
                      int k;
                   inven *curnode=head;
                   for(int j=0;j<count;curnode=curnode->next,j++)
                   if(curnode->code==i)  
                      {printf("\nenter quantity to be added: ");
                      scanf("%d",&k);
                      curnode->quantity+=k;
                      break;}
                 }
                 void codedisplay()
                {
                   printf("enter code: ");
                   scanf("%d",&code);
                   inven *curnode=head;
                   for(int j=0;j<count;curnode=curnode->next,j++)
                   if(curnode->code==code)
                   {
                    printf("\nproduct code=%d",curnode->code);
                    printf("\tproduct name=%s",curnode->name);
                    printf("\tproduct stock=%d",curnode->quantity);
                    printf("\tproduct sold=%d",curnode->sold);
                    printf("\tproduct threshold=%d",curnode->threshold);
                    } 
                 } 
                  void namedisplay()
                {
                   printf("enter name: ");
                   scanf("%s",name);
                   inven *curnode=head;
                   for(int j=0;j<count;curnode=curnode->next,j++)
                   if(!strcmp(curnode->name,name))
                   {
                    printf("\nproduct code=%d",curnode->code);
                    printf("\tproduct name=%s",curnode->name);
                    printf("\tproduct stock=%d",curnode->quantity);
                    printf("\tproduct sold=%d",curnode->sold);
                    printf("\tproduct threshold=%d",curnode->threshold);
                    } 
                 } 
};  
   
int main()
{
    int m,n,k,i=0;
    char a[6],b[20];
    strcpy(a,"xyzzy");
    inven r;
    A:
    printf("\n1.Inventory\n2.Billing\n3.Admin section\n4.exit\n");
    scanf("%d",&n);
    switch(n)
    {
             case 1:
                  B:
              printf("\n1.Enter new item\n2.Display stock\n3.Main menu\n"); 
              scanf("%d",&m);
              switch(m)
              {
                       case 1:
                            r.insert();
                            goto  B;                           
                       case 2:
                            r.display();  
                            goto B;
                       case 3:
                            goto A;
                       default:
                               printf("\nenter valid no");
                               goto B;
              }
              case 2:
                   D:
                   printf("\n1.Search by code \n2.Search by name\n3.main menu\n");
                   scanf("%d",&m);
                   switch(m)
                   {
                            case 1:
                                 r.searchcode();
                                 goto D;
                            case 3:
                                 goto A;
                            case 2:
                                r.searchname();
                                goto D;
                   }
              case 3:
                   F:
                   printf("\nEnter password: ");
                   scanf("%s",b);
                   i=strcmp(a,b);
                   if(i!=0)
                   {
                           printf("Invalid password. please retry..");
                           goto F;}
                   G:
                   r.checkstock();
                   printf("\n1.Search bill\n2.search code\n3.search name\n4.update item\n5.add discount\n6.main menu\n");
                   scanf("%d",&m);
                   switch(m)
                   {
                            case 1:
                                 printf("\nenter bill number: ");
                                 scanf("%d",&k);
                                 p[k].printbill(k);
                                 goto G;
                            case 2:
                                 r.codedisplay();
                                 goto G;
                            case 3:
                                 r.namedisplay();
                                 goto G;
                            case 6:
                                 goto A;
                            case 4:
                                 printf("\nenter code of product to be updated: ");
                                 scanf("%d",&k);
                                 r.update(k);
                                 goto G;
                            case 5:
                                 printf("\nenter code of product to be updated: ");
                                 scanf("%d",&k);
                                 r.discountt(k);
                                 goto G;
                   }           
                   goto G;
    }
    getch();
}


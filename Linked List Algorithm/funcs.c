#include <stdio.h>
#include <stdlib.h>
#include "Header.h"
#include <string.h>
#include <time.h>

void print_foods(food* food_list)
{
	food*cur;
	cur=food_list->next;
	while(cur!=NULL)
		{
		printf("%s     %d\n",cur->name,cur->price);
		cur=cur->next;
		}


}


int add_food(food* food_list, food* new_food)
{
	if(search_food(food_list,new_food->name)==NULL)
	{
		new_food->next=food_list->next;
	food_list->next=new_food;
	return 1;
	}
	else
		{
			printf("\n\t**this food is available...**\n");
	        return 0;
	    }

}




food* search_food(food* food_list, char name[])
{
		food*cur;
	cur=food_list->next;
	while(cur!=NULL && strcmp(cur->name,name))
	{
	cur=cur->next;
	}
	if(cur!=NULL)
		return cur;
	else
		return NULL;
}






 char *time()
{
	time_t rawtime;
    struct tm *timeinfo;

  time (&rawtime);
  timeinfo = localtime ( &rawtime );
 return asctime(timeinfo);
}



  int add_order(Akbar_Joojeh* akbar_joojeh, order* new_order)
  {
	 
			  if(search_customer(akbar_joojeh->customerinfo,new_order->username)==NULL)
				{ 
				printf("the Username is incorrect...\n");
				  return 0;
				}
		    else
		      {
			  new_order->next=akbar_joojeh->orderinfo->next;
			  akbar_joojeh->orderinfo->next=new_order;
			  printf("*Add successfully...*\n");
			  return 1;
			  }
	  
  
  }


  void print_orders(Akbar_Joojeh* akbar_joojeh)
  {
	  order*cur;
	 
	  cur=akbar_joojeh->orderinfo->next;
			while(cur!=NULL)
			{
				 customer*user;
		
				 user=search_customer(akbar_joojeh->customerinfo,cur->username);
				 printf("\nOrder Number:%d,\t\t\tData:%s\nUsername:%s,\t\tPhone Number:%s,\t\tAddress:%s,\n",cur->order_number,cur->data,cur->username,user->phonenumber,user->address);
				 printf_food_row(akbar_joojeh,cur->foodinfo);
				 cur=cur->next;
				 printf("****************************************\n\n");
		    }
  }






  int insert_customer(customer* customer_root, customer* new_node)
  {
	  customer*cur,*pre,*test;
	  pre=customer_root;
	  cur=customer_root->next;
	  test=search_customer(customer_root,new_node->username);
	  if(test!=NULL)
		{  printf("this user is available...");
	  return 0;}
	  else
	  {
	  while(cur!=NULL && cur->username[0]<new_node->username[0])
		 {
		pre=cur;
		cur=cur->next;
		 }
	  new_node->next=cur;
	  pre->next=new_node;
	 return 1;
	  }
  }


  customer* search_customer(customer* customer_root, char username[])
  {
	  customer*cur;
	  cur=customer_root;
	  while(cur!=NULL && strcmp(cur->username,username))
	  {
		  cur=cur->next;
	  }
	  if(cur==NULL)
		  return NULL;
	  else
		  return cur;
  }

  void print_customers(customer* customer_root)
  {
	  customer*cur;
	  cur=customer_root->next;
	  while(cur!=NULL)
	  {
		  printf("%s  ",cur->username);
		  cur=cur->next;
	  }
  }



  int remove_customer(Akbar_Joojeh* akbar_joojeh, char username[])
  {
	  customer*cur,*pre;
	  pre=akbar_joojeh->customerinfo;
	  cur=pre->next;
	  remove_order2(akbar_joojeh->orderinfo,username);
	  while(cur!=NULL && strcmp(cur->username,username)) 
	  {
		  pre=cur;
		  cur=cur->next;
	  }
	  if(cur!=NULL)
	  {
		  pre->next=cur->next;
		  free(cur);
		  return 1;
	  }
  return 0;
  }

  void add_food_row(Akbar_Joojeh*akbarjojeh,food_row*new_food_row,int food_type)
  {
	  int count=1;
	  
			  while(count<=food_type)
			  {
				food_row*a1;
				a1=(food_row*)malloc(sizeof(struct _food_row));
				food*a2;
				a2=(food*)malloc(sizeof(struct _food));
			
				scanf("%s %d",a1->name,&a1->numoffood);
				a2=search_food(akbarjojeh->foodinfo1,a1->name);
				if(a2==NULL)
				{
					printf("this food is not available...\nTry agian\n");
					continue ;
				}
				a1->next=new_food_row->next;
				new_food_row->next=a1;
				count++;
			  }
  }


  void printf_food_row(Akbar_Joojeh*akbar_jojeh,food_row*head_row)
  {
	  food_row*cur=(food_row*)malloc(sizeof(struct _food_row));
	int total=0;
	cur=head_row->next;
		while(cur!=NULL)
			{
				food*a1=(food*)malloc(sizeof(struct _food));
				a1=search_food(akbar_jojeh->foodinfo1,cur->name);
				printf("%s   %d     %d\n",cur->name,cur->numoffood,a1->price);
				total=total+cur->numoffood*a1->price;
				cur=cur->next;
			}
		printf("Total:%d\n\n",total);
  }


  int remove_order(order* order_list, int order_number)
  {
	  order*cur,*pre;
	  pre=order_list;
	  cur=order_list->next;
	  while(cur!=NULL && cur->order_number!=order_number)
	  {
		  pre=cur;
		  cur=cur->next;
	  }
	  if(cur!=NULL)
	  {
		  pre->next=cur->next;
		  free(cur);
		  printf("Delete order succesfully...\n");
		  return 1;
	  }
	  else
		  printf("this order not found...\n");
	  return 0;

  }

  void remove_order2(order* order_list, char username[])
  {
	  order*pre,*cur;
	  pre=order_list;
	  cur=order_list->next;
	  while(cur!=NULL && strcmp(cur->username,username))
	  {
		  pre=cur;
		  cur=cur->next;
	  }
	  if(cur!=NULL)
		{  
			pre->next=cur->next;
			free(cur);
			printf("Delet order & customer successfully...\n");
	   }
	  else
		  printf("EROR NOT FOUND...\n");
  }

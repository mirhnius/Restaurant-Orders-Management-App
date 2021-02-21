//  Amirhosein Nazeri - 810196574  //
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
				printf("\n%s     %d",cur->name,cur->price);
				cur=cur->next;
			}


}




int add_food(food* food_list, food* new_food)
{
	if(search_food(food_list,new_food->name)==NULL)   // for being sure that new_food is not existed //
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
	time_t rawtime;                             //  this function return array of time  //
    struct tm *timeinfo;
	                                    
	 time (&rawtime);
	 timeinfo = localtime ( &rawtime );
	return asctime(timeinfo);
}





  int add_order(Akbar_Joojeh* akbar_joojeh, order* new_order)
 {
	 
			  if(search_customer(akbar_joojeh->customerinfo,new_order->username)==NULL) // for being sure that customer is existed  //
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

	  if(search_customer(customer_root,new_node->username)!=NULL)  // for being sure that new cusrtomer is not existed  //
		 {
		  printf("this user allready exist...\n");
		  return 0;
		 }

	  
	 if(customer_root->username[0]>=new_node->username[0])
		  {
				if(customer_root->left!=NULL)
					insert_customer(customer_root->left,new_node);
				 else
				  {
					customer*temp;
					temp=(customer*)malloc(sizeof(struct _customer));
					strcpy(temp->username,new_node->username);
					strcpy(temp->address,new_node->address);
					strcpy(temp->phonenumber,new_node->phonenumber);
					temp->left=NULL;
					temp->right=NULL;
					customer_root->left=temp;
					return 1;
				 }

	      }

	  else if(customer_root->username[0]<new_node->username[0])
		  {
				if(customer_root->right!=NULL)
					  insert_customer(customer_root->right,new_node);
				else
				 {
					customer*temp;
					temp=(customer*)malloc(sizeof(struct _customer));
					strcpy(temp->username,new_node->username);
					strcpy(temp->address,new_node->address);
					strcpy(temp->phonenumber,new_node->phonenumber);
					temp->left=NULL;
					temp->right=NULL;
					customer_root->right=temp;
					return 1;
				 }

		 }

  }//  end of func //







customer* search_customer(customer* customer_root, char username[])
  {
	  customer*cur;
	  cur=customer_root;
	 
		  while(cur!=NULL)
			 {
				  if(!strcmp(cur->username,username))
					  return cur;
				  if(cur->username[0]<username[0])
					  cur=cur->right;
				  else if(cur->username[0]>=username[0])
					  cur=cur->left;
			 }

		  if(cur==NULL)
			  return NULL;
	
  }





  void print_customers(customer* customer_root)
  {
	  if(customer_root==NULL)
		  return;

	  print_customers(customer_root->left);
		 printf(" %s  \t",customer_root->username);
	  print_customers(customer_root->right);
  }





  int remove_customer(Akbar_Joojeh* akbar_joojeh, char username[])
  {
	  customer*cur,*pre;
	  int flag=0;
	  cur=akbar_joojeh->customerinfo;

		  while(cur!=NULL)
			  {
				  if(username[0]>cur->username[0])
						{	
							flag=1;
							pre=cur;
		 					cur=cur->right;
						}
				 if(!strcmp(cur->username,username))
					  break;

				 if(username[0]<=cur->username[0])
						{     
							flag=2;
							pre=cur;
							cur=cur->left;
						}
		
			 }

	  if(cur==NULL)
		 { 
			 printf("USER NOT FOUND...\n");
			 return 0;
		 }

	
	  remove_order2(akbar_joojeh->orderinfo,username); // for deleting order of customer //
	  
	  if(cur->left==NULL && cur->right==NULL)    //  if node has no child  //
			{
				  if(flag==1)
					 {
					  pre->right=NULL;
					  free(cur);
					 }
				  else if(flag==2)
					 {
					  pre->left=NULL;
					  free(cur);
					 }
				
					 return 1;
			}
	  
	  if(cur->right==NULL && cur->left!=NULL)    //  if node has 1 child on the left  //
			{
				  if(flag==1)
					  {
						pre->right=cur->left;
						free(cur);
					  }
				  if(flag==2)
					  {
						pre->left=cur->left;
						free(cur);
					  }
				  return 1;
			}
	
	  if(cur->left==NULL && cur->right!=NULL)    // if node has 1 child on the right  //
		 {
				 if(flag==1)
					 {
						pre->right=cur->right;
						free(cur);
					 }
				 if(flag==2)
					 {
						pre->left=cur->right;
						free(cur);
					 }
					 return 1;
		 }

	  if(cur->left!=NULL && cur->right!=NULL)    //   if node has 2 child  //
		{
			  customer*test;
			  customer*pretest;
			  test=cur;
			  test=test->right;   
			  pretest=test;
					  while(test->left!=NULL)
						{ 
						pretest=test;
						test=test->left;}
							if(flag==0)
								 {
									  strcpy(cur->address,test->address);
									  strcpy(cur->username,test->username);
									  strcpy(cur->phonenumber,test->phonenumber);
									  if(pretest==test)
										  cur->right=NULL;
									  else
										  pretest->left=test->right;
								 }
						  if(flag==1)
								 { 
									 pre->right=test;
									 pre->right->left=cur->left;    
									 free(cur);
								 }
						 else if (flag==2)
								 {
									 pre->left=test;
									 pre->left->left=cur->left;
									 free(cur);
								 }
								  return 1;
		}

		  


  }//end of func





  void add_food_row(Akbar_Joojeh*akbarjojeh,food_row*new_food_row,int food_type)
  {
			  int count=1; //  a counter for getting food_rows  //
	  
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
					a1=search_food(akbar_jojeh->foodinfo1,cur->name); //   for search & getting food_price in food_list  //
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





  void remove_order2(order* order_list, char username[])    // this func delete order by username and uses in remov_customer func //
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
		  printf("order NOT FOUND...\n");
  }

#include <stdio.h>
#include <stdlib.h>
#include "Header.h"
#include <string.h>
#include <time.h>





//**********************************************************************//
int main()
{
	int choose_part,choose_food,choose_order,choose_customer,num_food,delete_num,order_counter =1;
   
	Akbar_Joojeh *rest1;
     rest1=(Akbar_Joojeh*)malloc(sizeof(struct _Akbar_Joojeh));
	 rest1->orderinfo=(order*)malloc(sizeof(struct _order));
	 rest1->orderinfo->foodinfo=(food_row*)malloc(sizeof(struct _food_row));
	
	 rest1->foodinfo1=(food*)malloc(sizeof(struct _food));
	*rest1->orderinfo->username=NULL;
	rest1->orderinfo->order_number=0;
	*rest1->orderinfo->data=NULL;
	rest1->orderinfo->next=NULL;
	*rest1->orderinfo->foodinfo->name=NULL;
	rest1->orderinfo->foodinfo->numoffood=0;
	rest1->orderinfo->foodinfo->next=NULL;

	//*********************************//
	*rest1->foodinfo1->name=NULL;
	rest1->foodinfo1->price=1;
	rest1->foodinfo1->next=NULL;
	rest1->customerinfo=(customer*)malloc(sizeof(struct _customer));
	*rest1->customerinfo->username='a';
	*rest1->customerinfo->address=NULL;
	*rest1->customerinfo->phonenumber=NULL;
	rest1->customerinfo->next=NULL;

	while(true)
	{
		printf("which part do you want?\n1)food\n2)order\n3)customers\n");
		scanf("%d",&choose_part);
			if(choose_part==1)
						while(true)
						{
							printf("what do you want to do?\n1)print foods\n2)add a food\n3)back to main menu\n");
							scanf("%d",&choose_food);
							if(choose_food==1)
								{
									print_foods(rest1->foodinfo1);
								}

							if(choose_food==2)
								{
									food*newfood;
									newfood=(food*)malloc(sizeof(struct _food));
									printf("enter name_food food_price\n");
									scanf("%s %d",newfood->name,&newfood->price);
									add_food(rest1->foodinfo1,newfood);
								}

						if(choose_food==3)
							break;


						}//end of food while

		if(choose_part==2)
		{
			while(true)
			{
						printf("1)print orders\n2)add an order\n3)Delete an order\n4)back to main menu\n\n");
						scanf("%d",&choose_order);
						
						if(choose_order==1)
							{
					print_orders(rest1);
							}
						
						if(choose_order==2)
							{
										order*new_order=(order*)malloc(sizeof(struct _order));
										*new_order->data='a';
										new_order->foodinfo=(food_row*)malloc(sizeof(struct _food_row));
										*new_order->foodinfo->name=NULL;
										new_order->foodinfo->next=NULL;
										new_order->foodinfo->numoffood=0;
										printf("How many type of food do you want?\n");
										scanf("%d",&num_food);
										printf("Enter food num_of_food\n");
										add_food_row(rest1,new_order->foodinfo,num_food);
								
														printf("Enter username\n");
														scanf("%s",new_order->username);
													strcpy(new_order->data,time());
														int k=add_order(rest1,new_order);
														if(k==1)
														{
															new_order->order_number=order_counter;
															order_counter++;
														}
												
							}
						if(choose_order==3)
						{
							printf("Enter order_number\n");
							scanf("%d",&delete_num);
							remove_order(rest1->orderinfo,delete_num);
						}
						if(choose_order==4)
							break;

			
			}
		}

		if(choose_part==3)
			while(true)
			{
				printf("\nWhat do you want to do?\n1)print customers\n2)add a customers\n3)Delete a customer\n4)back to main menu\n\n");
				scanf("%d",&choose_customer);
				if(choose_customer==1)
				{
					print_customers(rest1->customerinfo);
				}
			
				if(choose_customer==2)
				{
				printf("Enter username address phone_number\n");
				customer*new_customer=(customer*)malloc(sizeof(struct _customer));
				scanf("%s %s %s",new_customer->username,new_customer->address,new_customer->phonenumber);
				insert_customer(rest1->customerinfo,new_customer);

				}

				if(choose_customer==3)
				{
					printf("Enter the username\n");
					char delete_user[20];
					scanf("%s",delete_user);
					int test=remove_customer(rest1,delete_user);
					if(test==1)
						printf("Delete successfully...\n");
				}

				if(choose_customer==4)
					break;





			}
	
	



	}//endofwhile//


return 0;
}

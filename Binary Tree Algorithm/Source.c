//  Amirhosein Nazeri - 810196574  //
#include <stdio.h>
#include <stdlib.h>
#include "Header.h"
#include <string.h>
#include <time.h>
#include <conio.h>



int main()
{
	int num_food,delete_num,order_counter=1,flag=1;
	char choose_part,choose_food,choose_order,choose_customer;
	Akbar_Joojeh *rest1;
    rest1=(Akbar_Joojeh*)malloc(sizeof(struct _Akbar_Joojeh));
	 rest1->orderinfo=(order*)malloc(sizeof(struct _order));
	
	rest1->foodinfo1=(food*)malloc(sizeof(struct _food));
	 rest1->customerinfo=(customer*)malloc(sizeof(struct _customer));
	 rest1->orderinfo->foodinfo=(food_row*)malloc(sizeof(struct _food_row));
	
	 *rest1->orderinfo->username=NULL;
	 rest1->orderinfo->order_number=0;
 	 *rest1->orderinfo->data=NULL;
	 rest1->orderinfo->next=NULL;								//    initialize orderinfo   //
	 *rest1->orderinfo->foodinfo->name=NULL;
	 rest1->orderinfo->foodinfo->numoffood=0;
	 rest1->orderinfo->foodinfo->next=NULL;


	
	*rest1->foodinfo1->name=NULL;							   //    initialize food_row_list  //
	rest1->foodinfo1->price=1;								
	rest1->foodinfo1->next=NULL;
	
	
	
	printf("WELLCOME TO \"AKBAR JOJE\" RESTAURANT\n");
	
	while(true)
	{
		printf("\nwhich part do you want?\n1)food\n2)order\n3)customers\n");
		choose_part=getche();
	
			if(choose_part=='1')
						while(true)
						{
							printf("\nwhat do you want to do?\n1)print foods\n2)add a food\n3)back to main menu\n");
							choose_food=getche();
							
							if(choose_food=='1')
								{
									print_foods(rest1->foodinfo1);
								}

							else if(choose_food=='2')
								{
									food*newfood;
									newfood=(food*)malloc(sizeof(struct _food));
									printf("\nenter name_food food_price\n");
									scanf("%s %d",newfood->name,&newfood->price);
									add_food(rest1->foodinfo1,newfood);
								}

						   else if(choose_food=='3')
								break;
						

						}//end of food while


		   else if(choose_part=='2')
			  {
					while(true)
						{
							printf("\n1)print orders\n2)add an order\n3)Delete an order\n4)back to main menu\n\n");
							choose_order=getche();
						
							if(choose_order=='1')
								{
									print_orders(rest1);
								}
						
							if(choose_order=='2')
								{
										order*new_order=(order*)malloc(sizeof(struct _order));
										*new_order->data='a';
										new_order->foodinfo=(food_row*)malloc(sizeof(struct _food_row));
										*new_order->foodinfo->name=NULL;
										new_order->foodinfo->next=NULL;
										new_order->foodinfo->numoffood=0;
										printf("\nHow many type of food do you want?\n");
										scanf("%d",&num_food);
										printf("Enter food num_of_food\n");
										
										add_food_row(rest1,new_order->foodinfo,num_food);
			
										printf("Enter username\n");
										scanf("%s",new_order->username);
										strcpy(new_order->data,time());  //   add time to order  //
											int k=add_order(rest1,new_order);   // k is a test for adding order  or not  //
														if(k==1)
														{
															new_order->order_number=order_counter;
															order_counter++;
														}
												
							  }
						
							if(choose_order=='3')
								{
									printf("\nEnter order_number\n");
									scanf("%d",&delete_num);
									remove_order(rest1->orderinfo,delete_num);
								}
							if(choose_order=='4')
								break;

			
						}//end of order while //
		
				}

		else if(choose_part=='3')
			while(true)
				{
					printf("\nWhat do you want to do?\n1)print customers\n2)add a customers\n3)Delete a customer\n4)back to main menu\n\n");
					choose_customer=getche();
						if(choose_customer=='1')
						{
							print_customers(rest1->customerinfo);
						}
			
						if(choose_customer=='2')
						{
							printf("\nEnter username address phone_number\n");
							if(flag==1)  // flag==1 means add the root of tree of customer  //
							{
			
								scanf("%s %s %s",rest1->customerinfo->username,rest1->customerinfo->address,rest1->customerinfo->phonenumber);
								rest1->customerinfo->left=NULL;
								rest1->customerinfo->right=NULL;
								flag=2;
							}
				
							else if(flag==2)
							{
								customer*new_customer=(customer*)malloc(sizeof(struct _customer));
								scanf("%s %s %s",new_customer->username,new_customer->address,new_customer->phonenumber);
								insert_customer(rest1->customerinfo,new_customer);
							}
						}

				       if(choose_customer=='3')
					   {
							printf("\nEnter the username\n");
							char delete_user[20];
							scanf("%s",delete_user);
							int test=remove_customer(rest1,delete_user);  // "test" for benig sure that deleting is successfull or not  //
							
							if(test==1)
								printf("Delete successfully...\n");
					   }

					  if(choose_customer=='4')
						break;



				} // end of customer while //
		
		else
			continue;
	

	}//  end of main while  //


return 0;
}

//  Amirhosein Nazeri - 810196574  //
#ifndef CODE_HEADER_H
#define CODE_HEADER_H

typedef struct _Akbar_Joojeh Akbar_Joojeh;
typedef struct _customer customer;
typedef struct _food food;
typedef struct _food_row food_row;
typedef struct _order order;

struct _customer{
	char username[50];
	char phonenumber[20];         // customers save in Binary Tree //
	char address[120];
	customer*right;
	customer*left;
};



struct _food{
char name[20];
int price;
food*next;
};



struct _food_row{
	char name[20];
	int numoffood;
	food_row*next;
	
};



struct _order{
	int order_number;
	char username[20];
	food_row *foodinfo;
	char data[120];
	order*next;
};

struct _Akbar_Joojeh{
	order *orderinfo;
	food *foodinfo1;
	customer *customerinfo;
};



void print_customers(customer* customer_root);

int insert_customer(customer* customer_root, customer* new_node);      

int remove_customer(Akbar_Joojeh* akbar_joojeh, char username[]);

customer* search_customer(customer* customer_root, char username[]);



void print_foods(food* food_list);

int add_food(food* food_list, food* new_food);

food* search_food(food* food_list, char name[]);




void print_orders(Akbar_Joojeh* akbar_joojeh);

int add_order(Akbar_Joojeh* akbar_joojeh, order* new_order);

int remove_order(order* order_list, int order_number);



char *time();

void printf_food_row(Akbar_Joojeh*akbar_jojeh,food_row*head_row);

void add_food_row(Akbar_Joojeh*akbar_jojeh,food_row*new_food_row,int food_type); // this func add food_row to orders //

void remove_order2(order* order_list, char username[]); // this func delete order by username and uses in remov_customer func //
#endif //CODE_HEADER_H
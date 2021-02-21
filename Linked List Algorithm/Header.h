#ifndef CODE_HEADER_H
#define CODE_HEADER_H
//int order_counter=1;
typedef struct _Akbar_Joojeh Akbar_Joojeh;
typedef struct _customer customer;
typedef struct _food food;
typedef struct _food_row food_row;
typedef struct _order order;

struct _customer{
	char username[50];
	char phonenumber[20];
	char address[120];
	customer*next;
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

/* NOTICE: YOU CANNOT CHANGE ANY FUNCTION DECLARATION */

/**--------------- Customrs --------------**/
/*
 * print all customers in detail sorted by usernames (alphabetically)
 */
void print_customers(customer* customer_root);

/*
 * add new node in tree in alphabetical order
 *      return 1 if added successfully, otherwise if username is duplicated return 0
 */
int insert_customer(customer* customer_root, customer* new_node);

/* Bonus Part:
 * remove a customer by its username
 * (also you should remove all his/her orders)
 *      return 1 if removed successfully, otherwise return 0
 */
int remove_customer(Akbar_Joojeh* akbar_joojeh, char username[]);

/*
 * search a customer by username and return its pointer
 *     return NULL if customer did not find
 */
customer* search_customer(customer* customer_root, char username[]);



void print_foods(food* food_list);

int add_food(food* food_list, food* new_food);

food* search_food(food* food_list, char name[]);


/**--------------- Orders --------------**/
/*
 * print all orders with user informatin and total price
 */
void print_orders(Akbar_Joojeh* akbar_joojeh);

/*
 * add new order
 *     return 1 if added successfully, otherwise if order number is duplicated or entered invalid username or invalid food return 0
 */
int add_order(Akbar_Joojeh* akbar_joojeh, order* new_order);

/*
 * remover a order by its number
 *      return 1 if removed successfully, otherwise return 0
 */
int remove_order(order* order_list, int order_number);
char *time();
void printf_food_row(Akbar_Joojeh*akbar_jojeh,food_row*head_row);
void add_food_row(Akbar_Joojeh*akbar_jojeh,food_row*new_food_row,int food_type);
void remove_order2(order* order_list, char username[]);
#endif //CODE_HEADER_H
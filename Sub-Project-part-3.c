// Sub-Project-Part-3

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>



// Define statements:
#define LINEAR 1
#define FORM 0
#define STOCK 1
#define CHECKOUT 0
#define MAX_ITEM_NO 21
#define MAX_QTY 999
#define SKU_MAX 999
#define SKU_MIN 100




// Constant TAX value:
double TAX = 0.13;



// Item structure:
struct Item
{ 
	double price;    
	int sku;    
	int isTaxed;    
	int quantity;    
	int minQuantity;    
	char name[21];
};


// Function Prototypes 1st Sub-Project:
void welcome(void);
void printTitle(void);
void printFooter(double gTotal);
void flushKeyboard(void);
void pause(void);
int getInt(void);
double getDouble(void);
int getIntLimited(int lowerLimit, int upperLimit);
double getDoubleLimited(double lowerLimit, double upperLimit);
// app interface
int yes(void);
void GroceryInventorySystem(void);
int menu(void);






// Function Prototypes 2nd Sub-Project:
double totalAfterTax(struct Item item);
int isLowQuantity(struct Item item);
struct Item itemEntry(int sku);
void displayItem(struct Item item, int linear);
void listItems(const struct Item item[], int noOfItems);
int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index);

// Function of 3rd Sub-Project:
void search(const struct Item item[], int NOofRecs);
void updateItem(struct Item *itemptr);
void addItem(struct Item item[], int *NoofRecs, int sku);
void addOrUpdateItem(struct Item item[], int *NoofRecs);
void adjustQuantity(struct Item item[], int NoOfRecs, int stock);


// Implementation of functions of 3rd Sub-Project... 

void search(const struct Item item[], int NoOfRecs)       // allows us to enter a sku to find whether an item with that sku is in inventory or not...
{
	int sku, a = 0, b; 
	printf("Please enter the SKU: ");
	sku = getIntLimited(SKU_MIN, SKU_MAX);
	a = locateItem(item,NoOfRecs,sku,&b);              // calling locateitem to check if the itme is in inventory or not..
	if(a == 1)
	{
		displayItem(item[b], FORM);                // calling displayItem() function to display the items in inventory..
	}
	else
	{
		printf("Item not found!\n");
	}
}
void updateItem(struct Item *itemptr)           //  Allows us to update whole data of an item in the inventory... 
{	
	struct Item b;
	int n;	
	printf("Enter new data:\n");
	b = itemEntry(itemptr->sku);               //  calling itemEntry() function to add new item into the inventory...
	printf("Overwrite old data? (Y)es/(N)o: ");
	n=yes();
	if(n == 1)
	{
		*itemptr = b;                      // adding the item into inventory through itemptr (object pointer)
		printf("--== Updated! ==--\n");
	}
	else
	{
		printf("--== Aborted! ==--\n");
	}
		
}
void addItem(struct Item item[], int *NoOfRecs, int sku)     // Checks if limit is not reached, then it allows us to enter new item...  
{
	struct Item b;
	int n;
	if(*NoOfRecs >= MAX_ITEM_NO)
	{
		printf("Can not add new item; Storage Full!\n");
	}
	else
	{
		b = itemEntry(sku);                    
		printf("Add Item? (Y)es/(N)o: ");
		n = yes();
		if(n == 1)
		{
			item[*NoOfRecs] = b;
			(*NoOfRecs)++;
			printf("--== Added! ==--\n");
		}
		else
		{
			printf("--== Aborted! ==--\n");
		}
	}
}
void addOrUpdateItem(struct Item item[], int *NoOfRecs)    // it checks if the item is there in the inventory then it update it after asking you, else add it the inventory after checking the limit, if nots full or not... 
{
	int sku, a,b,c;
	printf("Please enter the SKU: ");
	sku = getIntLimited(SKU_MIN, SKU_MAX);
	a = locateItem(item,*NoOfRecs,sku,&b);          // locates the item by calling this function, returns 1 if true and vice versa...
	if(a==1) 
	{
		displayItem(item[b], FORM);                // displays item if it exist..
		printf("Item already exists, Update? (Y)es/(N)o: ");     
		c = yes();                                 // ask if you want to update it or not...
		if(c==1)
		{
			updateItem(&item[b]);                  // if user says yes, than it will update the item through this function...
		}
		else
		{
			printf("--== Aborted! ==--\n");
		}	
	}
	else
	{
		addItem(item, NoOfRecs, sku);        // if new item  than it will add it into inventory through this function...
	}
}
void adjustQuantity(struct Item item[], int NoOfRecs, int stock)   // first it will check if the item exist or not, if it does then its quantity will be updated...
{
	int sku, n, b, opt, qty;
	printf("Please enter the SKU: ");
	sku = getIntLimited(SKU_MIN, SKU_MAX);
	n = locateItem(item,NoOfRecs,sku,&b);         // finding item, if found returns 1.. 
	if(n == 1)
	{
		displayItem(item[b], FORM);
		qty = MAX_QTY - item[b].quantity;
			printf("Please enter the quantity %s; Maximum of %d or 0 to abort: ",(stock==STOCK)?"to stock":"to checkout",(stock==STOCK)?qty:item[b].quantity);
			scanf("%d",&opt);	
			if(opt==0)
			{
				printf("--== Aborted! ==--\n");
			}
			else if(opt > 0 && opt < (stock==STOCK)?qty:item[b].quantity)
			{
				if(stock==STOCK)
				{
					item[b].quantity += opt;             // updating the quantity...
					printf("--== Stocked! ==--\n");
				}
				else
				{
					item[b].quantity -= opt;             // updating the quantity...s
					printf("--== Checked out! ==--\n");
				}
				if(item[b].quantity <= item[b].minQuantity)
				{
					printf("Quantity is low, please reorder ASAP!!!\n");
				}
			} 
	}
	else
	{
		printf("SKU not found in storage!\n");
	}
}


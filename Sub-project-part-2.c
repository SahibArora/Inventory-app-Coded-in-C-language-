// Part of 2 of the subProject...

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Define statements:
#define LINEAR 1
#define FORM 0

// Constant TAX value:
double TAX = 0.13;

// Item structure:
struct Item             // defining Item as a type through structure having its own behaviour...
{ 
	double price;    
	int sku;    
	int isTaxed;    
	int quantity;    
	int minQuantity;    
	char name[21];
};

// Sub-Projects 1's functions
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


// Sub-Projects 2 functions...
double totalAfterTax(struct Item item);
int isLowQuantity(struct Item item);
struct Item itemEntry(int sku);
void displayItem(struct Item item, int linear);
void listItems(const struct Item item[], int noOfItems);
int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index);


// Function Implementations of Sub-Project's 2:

double totalAfterTax(struct Item item)       // add tax to the particular item after checking if the item is taxed or not...
{
	double totalprice;
	//calculating total inventory price if taxed
	if (item.isTaxed == 1)
	{
		totalprice = (item.price * item.quantity) + ((item.price * item.quantity)*TAX);
	}
	// calculating total inventory price if not taxed
	else
		totalprice = item.price *item.quantity;
	return totalprice;
}

//to check the quantity is low or not
int isLowQuantity(struct Item item)        // Checks if the quantity of a particular item is less than required or not...
{
	if (item.quantity < item.minQuantity) //if the quantity of the item is lower than minimum quantity
		return 1;
	else
		return 0;
}
//to enter the data of items
struct Item itemEntry(int sku)            // adds the new Items to the inventory...
{
	struct Item entry;				//struct item entry holds the values entered 
	entry.sku = sku;
	printf("        SKU: %d\n",entry.sku);
	printf("       Name: ");
	scanf("%20[^\n]", entry.name);
	flushKeyboard();
	printf("      Price: ");
	entry.price = getDoubleLimited(0.00, 10000000.00);
	printf("   Quantity: ");
	entry.quantity = getIntLimited(0, 100);
	printf("Minimum Qty: ");
	entry.minQuantity = getIntLimited(0, 100);
	printf("   Is Taxed: ");
	entry.isTaxed = yes(); 
	
	return entry;
}



//display the items information
void displayItem(struct Item item, int linear)
{
	
	if (linear==LINEAR)            // if linear output will be in linear form
	{
		if (item.quantity < item.minQuantity)
		{
			printf("|%3d|%-20s|%8.2lf|  %3s| %3d | %3d |%12.2lf|***\n", item.sku, item.name, item.price, item.isTaxed ? "Yes" : "No", item.quantity, item.minQuantity, totalAfterTax(item));
		}
		else
			printf("|%3d|%-20s|%8.2lf|  %3s| %3d | %3d |%12.2lf|\n", item.sku, item.name, item.price, item.isTaxed ? "Yes" : "No", item.quantity, item.minQuantity, totalAfterTax(item));

	}
	else                        // else output will be displayed in varoius lines...
	{
		if (item.quantity < item.minQuantity)
		{
			printf("        SKU: %d\n", item.sku);

			printf("       Name: %s\n", item.name);

			printf("      Price: %.2lf\n", item.price);
			
			printf("   Quantity: %d\n", item.quantity);
			
			printf("Minimum Qty: %d\n", item.minQuantity);
			
			printf("   Is Taxed: %s\n", item.isTaxed ? "Yes" : "No");
			
			printf("WARNING: Quantity low, please order ASAP!!!\n");

		}
		else
		{
			printf("        SKU: %d\n", item.sku);

			printf("       Name: %s\n", item.name);

			printf("      Price: %.2lf\n", item.price);

			printf("   Quantity: %d\n", item.quantity);

			printf("Minimum Qty: %d\n", item.minQuantity);

			printf("   Is Taxed: %s\n", item.isTaxed ? "Yes" : "No");
		}
	}

}
void listItems(const struct Item item[], int noOfItems)         // displays items in the inventory with a header and footer
{
	 int i;
	double grandtotal=0;
	printTitle();
	for (i = 0; i < noOfItems; i++)
	{
		printf("%-4d", (i + 1)); //to print  the items
		displayItem(item[i], LINEAR);
		grandtotal =grandtotal+ totalAfterTax(item[i]);
	}
	printFooter(grandtotal);
}

int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index)     // finds a particular item through its SKU number...
{
	int i = 0;
	int a= 0;
	for (i = 0; i < NoOfRecs; i++)
	{
		if (item[i].sku == sku)
		{
			*index = i;
			a++;
		}
	}
	return a;
}

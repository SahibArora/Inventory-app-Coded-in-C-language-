// whole Project

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>


// Define statements:
#define LINEAR 1
#define FORM 0
#define STOCK 1
#define CHECKOUT 0
#define MAX_ITEM_NO 21
#define MAX_QTY 999
#define SKU_MAX 999
#define SKU_MIN 100
#define DATAFILE "item.txt"




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


// Function Prototypes of 1st Sub-Project...
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



// Function Prototypes of 2nd Sub-Project...
double totalAfterTax(struct Item item);
int isLowQuantity(struct Item item);
struct Item itemEntry(int sku);
void displayItem(struct Item item, int linear);
void listItems(const struct Item item[], int noOfItems);
int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index);

// Function of of 2nd Sub-Project...
void search(const struct Item item[], int NOofRecs);
void updateItem(struct Item *itemptr);
void addItem(struct Item item[], int *NoofRecs, int sku);
void addOrUpdateItem(struct Item item[], int *NoofRecs);
void adjustQuantity(struct Item item[], int NoOfRecs, int stock);

//Functions of of 3rd Sub-Project...
void saveItem(struct Item item, FILE *datafile);
int loadItem(struct Item *item, FILE *datafile);
int saveItems(const struct Item item[], char filename[], int NoOfRecs);
int loadItems(struct Item item[], char filename[], int *NoOfRecsPtr);

 // Function Implementations of 1st Sub-Project...


void welcome(void)         // prints welcome on the screen..
{
	printf("---=== Grocery Inventory System ===---\n\n");
}

void printTitle(void)         // prints the header on the screen...
{
	printf("Row |SKU| Name               | Price  |Taxed| Qty | Min |   Total    |Atn\n");
	printf("----+---+--------------------+--------+-----+-----+-----+------------|---\n");
}

void printFooter(double gTotal)        // prints the footer on the screen...
{
	printf("--------------------------------------------------------+----------------\n");
	if (gTotal>0)
	{
		printf("\t\t\t\t\t   Grand Total: |%12.2lf\n", gTotal);
	}
}

void flushKeyboard(void)         // pause the execution till the user don't press enter...
{
	char c;
	while (c != '\n')
	{
		scanf("%c", &c);
	}
}

int getInt(void)              // this function will only take an integer, anything else will be unaccepted..
{
	int n;
	char Xl = 'x';
	do
	{
		scanf("%d%c", &n, &Xl);      // %c here is used to check that right after an integer their should be a space which makes sure that only intgere is entered..
		if (Xl != '\n')
		{
			flushKeyboard();
			printf("Invalid integer, please try again: ");
		}
	} while (Xl != '\n');
	return n;
}
double getDouble(void)         // this function will take the double or any float value
{
	double f;
	char c = 'x';
	do
	{
		scanf("%lf%c", &f, &c);
		if (c != '\n')
		{
			flushKeyboard();
			printf("Invalid number, please try again: ");
		}
	} while (c != '\n');
	return f;
}

int getIntLimited(int lowerLimit, int upperLimit)      // checks the input is in its range or not, and if not user is asked to enter it again..
{
	int n;

	n = getInt();
	while (n < lowerLimit || n > upperLimit)
	{
		printf("Invalid value, %d < value < %d: ", lowerLimit, upperLimit);
		scanf("%d", &n);
	}
	return n;

}
double getDoubleLimited(double lowerLimit, double upperLimit) //checks the input is in its range or not, and if not user is asked to enter it again..
{
	double f;

	f = getDouble();
	while (f < lowerLimit || f > upperLimit)
	{
		printf("Invalid value, %.6lf< value < %.6lf: ", lowerLimit, upperLimit);
		scanf("%lf", &f);
	}
	return f;

}


// APP INTERFACE start here:

int yes(void)         //  this function ask a user to enter either a yes or no... 
{
	char ch;
	scanf("%c", &ch);
	while ((ch != 'Y' && ch != 'y') && (ch != 'N' && ch != 'n'))
	{
		printf("Only (Y)es or (N)o are acceptable: ");
		flushKeyboard();
		scanf("%c", &ch);
	}
	if (ch == 'Y' || ch == 'y')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int menu(void)         // provides different option to the user...
{
	int n;
	printf("1- List all items\n");
	printf("2- Search by SKU\n");
	printf("3- Checkout an item\n");
	printf("4- Stock an item\n");
	printf("5- Add new item or update item\n");
	printf("6- delete item\n");
	printf("7- Search by name\n");
	printf("0- Exit program\n");
	printf("> ");
	scanf("%d", &n);
	flushKeyboard();

	while (n < 0 || n > 7)
	{
		printf("Invalid value, 0 < value < 7: ");
		scanf("%d", &n);
		flushKeyboard();
	}
	return n;
}
void pause(void)          // pauses the execution with a message till the user don't hit an enter...
{
	printf("Press <ENTER> to continue...");
	flushKeyboard();
}
void GroceryInventorySystem(void)
{
	int n, n1 = 0;
	welcome();
	while (n1 != 1)
	{
		n = menu();
		switch (n)
		{
		case 1:
			printf("List Items under construction!\n");
			pause();
			break;
		case 2:
			printf("Search Items under construction!\n");
			pause();
			break;
		case 3:
			printf("Checkout Item under construction!\n");
			pause();
			break;
		case 4:
			printf("Stock Item under construction!\n");
			pause();
			break;
		case 5:
			printf("Add/Update Item under construction!\n");
			pause();
			break;
		case 6:
			printf("Delete Item under construction!\n");
			pause();
			break;
		case 7:
			printf("Search by name under construction!\n");
			pause();
			break;
		case 0:
			printf("Exit the program? (Y)es/(N)o: ");
			n1 = yes();
		}
	}
}
// Function Implementations of 2nd Sub-Project...

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
	printf("        SKU: %d\n", entry.sku);
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

	if (linear == LINEAR)            // if linear output will be in linear form
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
	double grandtotal = 0;
	printTitle();
	for (i = 0; i < noOfItems; i++)
	{
		printf("%-4d", (i + 1)); //to print  the items
		displayItem(item[i], LINEAR);
		grandtotal = grandtotal + totalAfterTax(item[i]);
	}
	printFooter(grandtotal);
}

int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index)     // finds a particular item through its SKU number...
{
	int i = 0;
	int a = 0;
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

//function implementation of 3rd Sub - Project...

void search(const struct Item item[], int NoOfRecs)       // allows us to enter a sku to find whether an item with that sku is in inventory or not...
{
	int sku, a = 0, b;
	printf("Please enter the SKU: ");
	sku = getIntLimited(SKU_MIN, SKU_MAX);
	a = locateItem(item, NoOfRecs, sku, &b);              // calling locateitem to check if the itme is in inventory or not..
	if (a == 1)
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
	n = yes();
	if (n == 1)
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
	if (*NoOfRecs >= MAX_ITEM_NO)
	{
		printf("Can not add new item; Storage Full!\n");
	}
	else
	{
		b = itemEntry(sku);
		printf("Add Item? (Y)es/(N)o: ");
		n = yes();
		if (n == 1)
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
	int sku, a, b, c;
	printf("Please enter the SKU: ");
	sku = getIntLimited(SKU_MIN, SKU_MAX);
	a = locateItem(item, *NoOfRecs, sku, &b);          // locates the item by calling this function, returns 1 if true and vice versa...
	if (a == 1)
	{
		displayItem(item[b], FORM);                // displays item if it exist..
		printf("Item already exists, Update? (Y)es/(N)o: ");
		c = yes();                                 // ask if you want to update it or not...
		if (c == 1)
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
	n = locateItem(item, NoOfRecs, sku, &b);         // finding item, if found returns 1.. 
	if (n == 1)
	{
		displayItem(item[b], FORM);
		qty = MAX_QTY - item[b].quantity;
		printf("Please enter the quantity %s; Maximum of %d or 0 to abort: ", (stock == STOCK) ? "to stock" : "to checkout", (stock == STOCK) ? qty : item[b].quantity);
		scanf("%d", &opt);
		if (opt == 0)
		{
			printf("--== Aborted! ==--\n");
		}
		else if (opt > 0 && opt < (stock == STOCK) ? qty : item[b].quantity)
		{
			if (stock == STOCK)
			{
				item[b].quantity += opt;             // updating the quantity...
				printf("--== Stocked! ==--\n");
			}
			else
			{
				item[b].quantity -= opt;             // updating the quantity...s
				printf("--== Checked out! ==--\n");
			}
			if (item[b].quantity <= item[b].minQuantity)
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
// functions implementation of 4th Sub-Project...

void saveItem(struct Item item, FILE *datafile)       // saves the item into the file
{
    fprintf(datafile,"%d,%d,%d,%0.2lf,%d,%s\n",item.sku,item.quantity,item.minQuantity,item.price,item.isTaxed,item.name);
}
int loadItem(struct Item *item, FILE *datafile)       // load item from the file...
{
    int n=0,m;
    m = fscanf(datafile,"%d,%d,%d,%lf,%d,%[^\n]s\n",&item->sku,&item->quantity,&item->minQuantity,&item->price,&item->isTaxed,item->name);
    if(m == 6)
    {
        n = 1;
    }
    return n;
}
int saveItems(const struct Item item[], char filename[], int NoOfRecs)         // save multiple items into the file...
{
    FILE *fp=NULL;
    int a,i;
    fp = fopen(filename,"w");
    if(fp != NULL)
    {
        for(i=0; i < NoOfRecs; i++)
        {
            saveItem(item[i], fp);
        }
        a=1;
    }
    else
    {
        a=0;
    }
    fclose(fp);
    return a;
}
int loadItems(struct Item item[], char filename[], int *NoOfRecsPtr)     // load multiple items at one time...
{
    FILE *fp;
    int i=0,a;
    struct Item itemm;
    fp = fopen(filename, "r");
    if(fp != NULL)
    {
        while(loadItem(&itemm, fp)!=0)
        {
            //loadItem(&itemm, fp);
		    item[i] = itemm;
            i++;
	}
	a=1;
		*NoOfRecsPtr = i;
	fclose(fp);
    }
    else
    {
        a=0;
    }
    return a;
}
void GroceryInventorySystem(void)                        // our app with all its features....
{
	struct Item item[MAX_ITEM_NO];
	int rec,a=0,b=0,c=0,d=0,e=0,f,sku,index;	
	int option, rvalue,i,index1,z=0;
	char NAME[20],NAme[30];
	char *na = NULL;
	char opt;

	welcome();
	a=loadItems(item,DATAFILE,&rec);
	if(a==0)
	{
		printf("Could not read from %s.\n",DATAFILE);
	}
	do {

		option = menu();

		switch (option)
		{
		case 1:
			listItems(item,rec);
			pause();
			break;
		case 2:
			search(item,rec);
			pause();
			break;
		case 3:
			adjustQuantity(item, rec, CHECKOUT);
			b=saveItems(item,DATAFILE,rec);
			if(b==0)
			{
				printf("could not update data file %s\n",DATAFILE);
			}	
			pause();
			printf("\n");
			break;
		case 4:
			adjustQuantity(item, rec, STOCK);
			c=saveItems(item,DATAFILE,rec);
			if(c==0)
			{
				printf("could not update data file %s\n",DATAFILE);
			}	
			pause();
			printf("\n");
			break;
		case 5:
			addOrUpdateItem(item,&rec);
			d=saveItems(item,DATAFILE,rec);
			if(d==0)
			{
				printf("could not update data file %s\n",DATAFILE);
			}
			pause();
			break;
		case 6:
			printf("Please enter the SKU: ");
			scanf("%d",&sku);
			e=locateItem(item,rec,sku,&index);
			if(e==0)
			{
				printf("SKU not found!\n");
				flushKeyboard();
			}
			if(e!=0)
			{
				printf("        SKU: %d\n",item[index].sku);
				printf("       Name: %s\n",item[index].name);
				printf("      Price: %.2lf\n",item[index].price);
				printf("   Quantity: %d\n",item[index].quantity);
				printf("Minimum Qty: %d\n",item[index].minQuantity);
				printf("   Is Taxed: %s\n",(item[index].isTaxed==1)?"Yes":"No");
				printf("This Item will be deleted, are you sure? (Y)es/(N)o: ");
				flushKeyboard();
			 scanf("%c",&opt);
			 switch(opt)
			 {
				case 'Y': f=1; break;
				case 'y': f=1; break;
				case 'N': f=0; break;
				case 'n': f=0; break;
				default : printf("Only (Y)es and (N)o are acceptable: \n");
			 }
			}
			if(f==1)
			{
				for(i=index;i<rec;i++)
				{
					item[i].sku=item[i+1].sku;
					item[i].price=item[i+1].price;
					strcpy(item[i].name,item[i+1].name);
					item[i].isTaxed=item[i+1].isTaxed;
					item[i].quantity=item[i+1].quantity;
					item[i].minQuantity=item[i+1].minQuantity;
				}
				printf("Deleted!\n");	
				rec--;
			}
			if(f==0)
			{
				printf("Aborted!\n");
			}
			flushKeyboard();
			pause();
			break;
		case 7:
			printf("Please enter part of the name: ");
			scanf("%s",NAME);
			for(i=0; i<rec; i++)
			{
				strcpy(NAme,item[i].name);
			 	na = strstr(NAme,NAME);
				if(na!=(NULL))
				{
					z=1;
						index1 = i;
						printf("        SKU: %d\n",item[index1].sku);
						printf("       Name: %s\n",item[index1].name);
						printf("      Price: %.2lf\n",item[index1].price);
						printf("   Quantity: %d\n",item[index1].quantity);
						printf("Minimum Qty: %d\n",item[index1].minQuantity);
						printf("   Is Taxed: %s\n",(item[index1].isTaxed==1)?"Yes":"No");
					if(index1==10)
					{
						flushKeyboard();
					}
						pause();
				}
			}
			if(z==0)
			{
				printf("No Item found in the system matching the value entered!\n");
				flushKeyboard();
				pause();
			}
			break;
		case 0:
			printf("\n");
			printf("Exit the program? (Y)es/(N)o: ");
			rvalue = yes();
			break;
		}
	} while (rvalue != 1);
}

// Main Function...

int main(void)
{
	GroceryInventorySystem();
	return 0; 
}

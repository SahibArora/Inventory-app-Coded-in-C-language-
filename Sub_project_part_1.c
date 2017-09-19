// Part 1 of Whole Inventory System...

#include<stdio.h>
// TOOLS PART
 
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
		if(gTotal>0)
		{
			printf("\t\t\t\t\t   Grand Total: |%12.2lf\n",gTotal);
		}
	}

	void flushKeyboard(void)         // pause the execution till the user don't press enter...
	{
		char c;
		while(c != '\n')
		{
			scanf("%c",&c);	
		}
	}

	int getInt(void)              // this function will only take an integer, anything else will be unaccepted..
	{
		int n;
		char Xl = 'x';
		do
		{
        		scanf("%d%c",&n,&Xl);      // %c here is used to check that right after an integer their should be a space which makes sure that only intgere is entered..
			if(Xl != '\n')
			{
				flushKeyboard();
				printf("Invalid integer, please try again: ");
			}	
		}while(Xl != '\n');
		return n;
	}
	double getDouble(void)         // this function will take the double or any float value
	{
		double f;
		char c = 'x';
		do
		{
			scanf("%lf%c", &f, &c);
			if(c!='\n')
			{
				flushKeyboard();
				printf("Invalid number, please try again: ");	
			}
		}while(c!='\n');
		return f;
	}	

	int getIntLimited(int lowerLimit, int upperLimit)      // checks the input is in its range or not, and if not user is asked to enter it again..
	{
		int n;
			
		n = getInt();
		while(n < lowerLimit || n > upperLimit)
		{
			printf("Invalid value, %d < value < %d: ",lowerLimit,upperLimit);
			scanf("%d",&n);
		}
		return n;
		
	}
	double getDoubleLimited(double lowerLimit, double upperLimit) //checks the input is in its range or not, and if not user is asked to enter it again..
	{
		double f;
		
		f = getDouble();
		while(f < lowerLimit || f > upperLimit)
		{
			printf("Invalid value, %.6lf< value < %.6lf: ",lowerLimit,upperLimit);
			scanf("%lf", &f);
		}
		return f;
		
	}


// APP INTERFACE start here:
	
	int yes(void)         //  this function ask a user to enter either a yes or no... 
	{
		char ch ;
		scanf("%c",&ch);
		while((ch != 'Y' && ch !='y') && (ch != 'N' && ch != 'n'))
		{
			printf("Only (Y)es or (N)o are acceptable: ");
			flushKeyboard();
			scanf("%c",&ch);
		} 
		if(ch == 'Y' || ch =='y')
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
		scanf("%d",&n);
		flushKeyboard();

		while(n < 0 || n > 7)
		{
			printf("Invalid value, 0 < value < 7: ");
			scanf("%d",&n);
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
		int n,n1=0;
		welcome();
		while(n1!=1)
		{
		n = menu();
		switch(n)
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
				n1=yes();
		}
		}
	}

// main testing the above functions.....

/*int main(void)
{
	int iVal;
	double dVal;
	welcome();
	
	printf("listing header and footer with grand total:\n");
	printTitle();

	printFooter(1234.5678);
	printf("\nlisting header and footer without grand total:\n");
	printTitle();
	printFooter(-1);

	pause();

	printf("Enter an integer: ");
	iVal = getInt();
	printf("You entered: %d\n",iVal);

	printf("Enter an integer between 10 and 20: ");
	iVal = getIntLimited(10,20);
	printf("Your entered: %d\n",iVal);

	printf("Enter a floating point number: ");
	dVal = getDouble();
	printf("You entered: %0.2lf\n",dVal);

	printf("Enter a floating point number between 10.00 and 20.00: ");
	dVal = getDoubleLimited(10.0,20.0);
	printf("You entered: %0.2lf\n",dVal);

	printf("End of tester program for IO tools!\n");
	
	GroceryInventorySystem();
	
	printf("End of tester program for milestone one!\n");
	return 0;
}*/

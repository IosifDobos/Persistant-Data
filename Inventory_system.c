/**
 *  PROGRAM WITH PERSISTANT DATA ASSIGNMENT #1
 *
 * Question 2: Inventory Implementation
 * This program is created to implement an IT inventory
 * system, which will enable the user to items to the Inventory stock.
 *
 * Program created by: Iosif Dobos, C16735789
 *                     Niall Glynn, C15742685
 * DUE Date: 22/04/2017
 *
 * Compiler used: JetBrains CLion 2017.1, Borland
 *
 * The Assignment was also uploaded and implemented in GitHub.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//declare symbolic names
#define SIZE 5
#define MAX 51

//declare structure tag
struct IT_inventory
{
    int deleted;
    int quantity;
    char model[MAX];
    float cost;
};

//declare function prototype
void DISPLAYmenu( char );
int ADDitems( struct IT_inventory [], int );
void DELETEitem( struct IT_inventory [] , int );
void EDITitem( struct IT_inventory [], int );
void FINDitem( struct IT_inventory [], int );
void RECORDinventory( struct IT_inventory [], int );
void DISPLAYrecords( struct IT_inventory [], int );

//main function
int main()
{
    //declare my structure variables
    struct IT_inventory item[SIZE];


    //declare variables used within main function
    char user_input;
    int user_choice = 0;
    int user_choice1 = 0;
    int counter = 0;


    do
    {
        //call function DISPLAYmenu()
        DISPLAYmenu( user_input );

        //create a switch-case that will switch to user input
        switch ( user_input )
        {
            case '1':
            {
                counter = ADDitems( item, counter );
                break;
            }
            case '2':
            {
                DELETEitem( item, user_choice);
                break;
            }
            case '3':
            {
                EDITitem( item, user_choice1);
                break;
            }
            case '4':
            {
                FINDitem( item, counter);
                break;
            }
            case '5':
            {
                RECORDinventory( item, counter );
                break;
            }
            case '6':
            {
                DISPLAYrecords( item, counter);
                break;
            }
            case '7':
            {
                printf("Program Ends!!!");
                printf("Thank you for your time");
                exit(1);
            }
            default:
            {
                printf("\nSorry invalid entry.");
                printf("\nPlease try again!!!");
                break;
            }

        }
    }while ( user_input != '7');//end do-while loop
    //while loop will keep executing while the user input is not 7 on the main menu. this will quit from the main menu

    return 0;

}//end function main()

/**
 * Implement function display_menu
 * A menu will be display it to the screen and allow user to enter a option from 1 to 5
 * then perform the specific option that user entered
 *
 * 1. To allow user to enter a new item
 * 2. To allow user to delete old item
 * 3. To edit a specif item
 * 4. To find an item
 * 5. To record inventory
 */
void DISPLAYmenu ( char option)
{
        //create a menu for user options
        printf("\n******************** MENU ********************");
        printf("\n*****\t Press 1 to Add new item\t*****");
        printf("\n*****\tPress 2 to Delete old Item\t*****");
        printf("\n*****\tPress 3 to Edit Item\t*****");
        printf("\n*****\tPress 4 to Find Item\t*****");
        printf("\n*****\tPress 5 to Record Inventory\t*****");
        printf("\n*****\tPress 6 to Display record\t*****\n");
        printf("\n*****\tPress 7 to Exit Program\t*****\n");

        //asking user to enter a option from the menu
        printf("\nPlease enter an option from the menu: ");
        scanf("%c", &option);


}//end function display_menu()

/**
 * Implement function add_item()
 * This function will allow user to enter five item into the inventory list and them
 * the list is displayed to the screen
 */
int ADDitems(struct IT_inventory item[SIZE], int counter1)
{

    //declare my variables
    int i, num_of_rec;

    //ask user to enter how many records wish to add
    printf("How namy record you want to add?: ");
    scanf("%d", &num_of_rec);

    num_of_rec = num_of_rec + counter1;

    //if number of records to be added is less than the max inventory size
    if( num_of_rec <= SIZE )
    {
        //create a loop to add new items to the inventory
        for(i = counter1; i < num_of_rec; i++)
        {

            printf("please enter the quantity\n\n");
            scanf("%d", &(item[counter1].quantity));
            printf("please enter the model\n\n");
            scanf("%s", item[counter1].model);
            printf("please enter the cost\n\n");
            scanf("%f", &(item[counter1].cost));

            //increment the counter
            counter1++;
        }//end for loop
    }//end if statement
    else
    {
        //inform user that the inventory is full
        puts("\n\nSorry inventory is full\n\n");
    }//end else statement

    //return the value of counter1 to the main function
    return counter1;

}//end function ADDitems()
////////////////////////////////////////////////////////////////

/**
 *  Implement function DELETEitem() in this function user is able to delete items from
 *  the stock in function of preference
 */
void DELETEitem( struct IT_inventory items[SIZE], int user_choice)
{
    //ask user to enter the number wish to delete from the stock
    printf("select the item number you wish to delete");
    scanf("%d", &user_choice);

    (items[user_choice-1].deleted)=1;
    (items[user_choice].quantity);
    (items[user_choice].model);
    (items[user_choice].cost);
    //print deleted successfully
    printf("item number %d is deleted\n", user_choice);

}//end function DELETEitem()
////////////////////////////////////////////////////////////////////

/**
 *  Implement function EDITitem()
 *  Whith in this function user is able to edit any item available from the stock
 */
void EDITitem( struct IT_inventory items[SIZE], int user_choice1)
{
    //ask user ti enter the number of item wish to edit
    printf("\nplease enter the item number of the item you would to edit\n\n");
    scanf("%d", &user_choice1);

    (items[user_choice1-1].deleted)=0;
    printf("Please enter the new quantity \n\n");
    scanf("%d", &items[user_choice1-1].quantity);
    puts("Please enter the new model\n\n");
    scanf("%s", items[user_choice1-1].model);
    puts("Please enter the  new cost\n\n");
    scanf("%f", &(items[user_choice1-1].cost));

    printf("Item number %d has been edited\n", user_choice1);

}//end function EDITitem()
///////////////////////////////////////////////////////////////////////////

/**
 * Implement function EDITitem()
 * In this function user is able to find any item available from the stock
 */
void FINDitem( struct IT_inventory items[SIZE], int counter)
{
    //create my variables
    int low;
    int mid;
    int high;
    char user_search[11];

    //ask user to enter the model wish to find
    printf("\nEnter the model of the item you wish to search for:\n\n");
    scanf("%s", user_search);

    low = 0;
    high = counter;


    while ( low <= high )
    {
        mid = (low + high)/2;
        if(strcmp( user_search, items[mid].model) < 0)
        {
            high = mid - 1;
        }
        else
        {
            if (strcmp( user_search, items[mid].model) > 0)
            {
                low = mid + 1;
            }
            else
            {
                if(strcmp( user_search, items[mid].model) == 0)//found match
                {

                    printf("Model %s,Quantity: %d, Cost: %f\n\n", items[mid].model, items[mid].quantity, items[mid].cost);
                    break;
                }//end if statement
            }//end else statement
        }//end outer else statement
    }//end while

}//end fnction FINDitem()
///////////////////////////////////////////////////////////////////////////
/**
 * Implement function RECORDinventory()
 * This function will display all the items available from the stock
 */
void RECORDinventory( struct IT_inventory items[SIZE], int counter1 )
{
    //declare my FILE pointer
    FILE *fp;
    int i = 0;

    //check if file open successfully
    if ((fp = fopen("IT_inventory.txt","w+")) == NULL )
    {
        puts("Error in opening file");
    }
    else
    {
        for(i = 0; i < counter1; i++)
        {
            if ( counter1 <= SIZE )
            {
                if(items[i].deleted!=1)
                {
                    fprintf( fp, "\n Model: %s\n Quantity: %d\n Cost: %f\n\n", items[i].model, items[i].quantity, items[i].cost);
                    puts("All items were successfully copied to file");
                }
                else
                {
                    fprintf( fp, "\n Item deleted\n\n");
                }
            }
            else
            {
                puts("Inventory is full, cannot copy items");
            }//close inner statement
        }//close for loop

    }//close outer else statement
    //close the file
    fclose(fp);

}//end function RECORDinventory()
//////////////////////////////////////////////////////////////////////////////////

/**
 *
 */
void DISPLAYrecords( struct IT_inventory items[SIZE], int counter1)
{
    //create my index variable used inside for loop
    int i;

    for(i = 0; i < counter1 + 1; i++ )
    {
        if ( items[i-1].deleted == 1 )
        {
            printf("\n\nDeleted item\n\n");
        }//end if statement
        else
        {
            printf("Stock inventory\n");
            printf("\nModel: %s, Quantity: %d, Cost: %f\n\n", items[i-1].model, items[i-1].quantity, items[i-1].cost);
        }//end else statement
    }//end for loop
}//end DISPLAYrecords() function

/**
 * PROGRAM WITH PERSISTANT DATA ASSIGNMENT #1
 *
 * Question 3: Queue Implementation
 * This program is created to implement a queue structure IT services ticketing
 * system, which will enable the user to add tickets when IT fix requests are received
 * via phone. This ticketing system will only allow the next ticket in the queue be precessed
 * and the queue has a limit of 5 tickets only.
 *
 * Program created by: Iosif Dobos, C16735789
 *                     Niall Glynn, C15742685
 *
 * DUE Date: 22/04/2017
 *
 * Compiler used: JetBrains CLion 2017.1 / Borland
 *
 * The Assignment was also uploaded and implemented in GitHub.
 */



#include <stdio.h>
#include <stdlib.h>

//declare my symbolic name
#define SIZE 51

//create a structure integer used for time of call phone
struct time
{
    int hour;
    int minutes;
};
//create the structure used to build the list
struct IT_ticketing
{
    char client_name[SIZE];
    long int phone_no;
    char description_of_issue[SIZE];
    struct time call_time ;
};
struct newnode
{
    struct IT_ticketing combo;
    struct newnode* next;
};
struct newnode* head = NULL;

//create my global variable length;
//int length;

//declare my function prototype
int displayMENU( int* );
void addTicket( void );
void insertDATA( struct newnode* );
void deleteTicket( void );
void addAtBegin( void );
void addAtTheEnd( void );
int checkLength( void );
void displayTicket( void );

//main function
int main( )
{
    //create my local variable using in this function for switch case
    int user_option ;
    int rtn_option;
    int length;

    //call function displayMENU()
    do
    {
        rtn_option = displayMENU( &user_option);

        //create a switch statement for user option
        switch( rtn_option )
        {
            case 1:
                addTicket();
                break;
            case 2:
                deleteTicket();
                break;
            case 3:
                addAtBegin();
                break;
            case 4:
                addAtTheEnd();
                break;
            case 5:
                length = checkLength();
                printf("The queue has a list of %d\n", length);
                break;
            case 6:
                displayTicket();
                break;
            case 7:
                exit(1);
            default:
                printf("Sorry invalid input...Please try again!!!");
                break;
        }//end switch case
    }while ( rtn_option != 7);



    return 0;

}//end main() function

//Implement the function displayMENU(). This function will display a menu to the screen and ask user
//to enter one of the option then the option is implemented
int displayMENU( int *option )
{
        //create a menu and display it to the screen
        printf("\n******************** MENU ********************");
        printf("\n*****\t Option 1: Add ticket \t\t *****");
        printf("\n*****\t Option 2: Delete ticket \t *****");
        printf("\n*****\t Option 3: Add ticket at the begin****");
        printf("\n*****\t Option 4: Add ticket at the end *****");
        printf("\n*****\t Option 5: Check the list\t *****");
        printf("\n*****\t Option 6: Display tickets \t *****");
        printf("\n*****\t Option 7: Exit Program \t *****");
        printf("\n**********************************************");
        printf("\n\n\n*****************************************");
        printf("\nPlease enter your option: ");
        scanf("%d", &*option);
        printf("\n*****************************************\n");


    return *option;
}

//add tickets to the queue list 5 maximum
void addTicket( )
{
    //declare my structure pointers variables
    struct newnode* node;

    //allocate memory to the node
    node = (struct newnode*)malloc(sizeof(struct newnode));

    //call function insertDATA to add data to the ticket information
    insertDATA( node );

    node->next = NULL;

    //check if the head is pointing to NULL
    if( head == NULL )
    {
        head = node;
    }
    else
    {
        struct newnode* temp;

        temp = head;

        while(temp->next != NULL )
        {
            temp = temp->next;
        }//end while loop

        temp->next = node;

    }//end else statement

}//end addTicket() function

//implement function insertDATA()
void insertDATA( struct newnode* temp)
{
    //ask user to enter data into the structure
    puts("Enter the name of the client: ");
    scanf("%s", temp->combo.client_name);
    puts("Enter the contact number: ");
    scanf("%ld", &temp->combo.phone_no);
    puts("Enter the short description of issue: ");
    scanf("%s", temp->combo.description_of_issue);
    puts("Enter the time of phone call:");
    scanf("%d",&temp->combo.call_time.hour);
    scanf("%d",&temp->combo.call_time.minutes);

}//end function insertDATA() to the queue

//implement function addAtBegin()
void addAtBegin()
{
    //declare my structure pointers variables
    struct newnode* node;

    //allocate memory to the node
    node = (struct newnode*)malloc(sizeof(struct newnode));

    //ask user to enter the ticket details wish to add at the front of the list
    printf("\n\nEnter customer details you wish to add at the begin:\n");
    printf("\nEnter name: ");
    scanf("%s", node->combo.client_name );
    printf("\nEnter contact number: ");
    scanf("%ld", &node->combo.phone_no);
    printf("\nEnter description of issue: ");
    scanf("%s", node->combo.description_of_issue);
    printf("Enter the time of phone call: ");
    scanf("%d", &node->combo.call_time.hour);
    scanf("%d", &node->combo.call_time.minutes);

    //assign the node to NULL
    node->next = NULL;

    //check if the head list is pointing to NULL
    if( head == NULL )
    {
        head = node;
    }//end if statement
    else
    {
        //change the next node to be the head and change the head to node
        node->next = head;
        head = node;
    }//end else statement

}//end function addAtBegin()

//Implement function addAtTheEnd()
void addAtTheEnd()
{
    //declare my structure pointers variables
    struct newnode* node, *temp;

    //create my local variable used in this function
    int location, length, i;
    i = 1;

    //ask user to enter the ticket location wish to add at the end of the list
    printf("Please enter the location you want to change: ");
    scanf("%d", &location);


    length = checkLength();

    //chef is user location is greater then the number of tickets
    if ( location > length )
    {
        printf("\nSorry but this location is invalid!!!");
        printf("\nThere are %d node in the list", length);
    }//end if statement
    else
    {
        temp = head;

        while ( i < location )
        {
            temp = temp->next;
            i++;
        }
        node = (struct newnode*)malloc(sizeof(struct newnode));

        node->next = temp->next;
        temp->next = node;
    }//end else statement
}//end function addAtTheEnd()

//implement function checkLenght() which counter the number of tisckets are on the queue
int checkLength()
{
    //declare my structure pointers variables
    struct newnode* temp ;
    //create my counter variable
    int counter = 0 ;

    //assign the head to temp variable
    temp = head ;

    //create a while that will increment the counter until the temp is pointing to NULL
    while(temp != NULL)
    {
        counter++;
        temp = temp->next ;

    }
    //return the counter value back to the main function
    return counter ;

}//end checkLength() function

//implement function deleteTicket() this will allow user to delete a ticket from the queue
void deleteTicket()
{
    //declare my structure pointers variables
    struct newnode *node;

    //declare my local variable used for this function
    int location;

    //ask user to enter the location number wish to delete from the queue
    printf("\nPlease enter the ticket location wish to delete: ");
    scanf("%d", &location);

    //check if location is valid
    if ( location > checkLength() )
    {
        printf("\nSorry invalid location!!!");
    }
        //check if user location is the head
    else if( location == 1 )
    {
        node = head;

        head = node->next;

        node->next = NULL;
    }
    else
    {
        struct newnode *temp, *q;
        int i = 1;

        temp = head;

        while ( i < location - 1)
        {
            temp = temp->next;
            i++;
        }
        q = temp->next;

        temp->next = q->next;
        q->next = NULL;

        free(q);
    }//end else statement

}//end function deleteTicket()


//implement function displayTicket()
void displayTicket()
{
    //declare my structure pointers variables
    struct newnode* node;

    node = head;

    //check if the node is pointing to null
    if( node == NULL)
    {
        printf("\nThe IT ticket list is empty\n");
    }
    else
    {
        //create a loop that will display the tickets to the screen
        while ( node != NULL )
        {
            //display to the user the queue list
            printf("\nName of the client: %s", node->combo.client_name);
            printf("\nContact Number: %ld", node->combo.phone_no);
            printf("\nDescription of issue: %s", node->combo.description_of_issue);
            printf("\nTime of call: %d:%d", node->combo.call_time.hour, node->combo.call_time.minutes);

            //move the node to the next ticket from the queue
            node = node->next;
            printf("\n");
        }//end while statement

    }//end else statement

}//end function displayTicket()
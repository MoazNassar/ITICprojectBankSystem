
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <conio.h>  
#include <math.h>
#include <time.h>

#include"STD_TYPES.h"
#include"linkedlist.h"
#include"bank.h"  


/*Variable To Store That The Admin Password is Valid.*/
uint8 Global_uint8bankCheck = 0;		

void bankSystem_VoidAdminCheck()
{
	/*Variable to count down the username and Password Entering trials*/
	static uint8 Local_uint8bankTrials = 0;
	/*Variable to scan in it the username and Password entered by the admin*/
	uint16 Local_uint16bankAdminPassword = 0;
	uint8 Local_uint8bankAdminUsername [100] ;
	/*Clearing the Password Validity Flag*/
	Global_uint8bankCheck = 0;
	/*Reset the Number of the Password trials*/
	Local_uint8bankTrials = BANK_SYSTEM_MAX_TRIALS;
	 
	 
	while((Local_uint8bankTrials !=0 ) && (Global_uint8bankCheck == 0))
	{
		/*Scaning from the Admin the username*/
		 printf("Please Enter The Admin Username : \n");
		scanf("%s",&Local_uint8bankAdminUsername);
		/*Scaning from the Admin the Password*/
		 printf("Please Enter The Admin Password : ");
		 scanf("%d",&Local_uint16bankAdminPassword);
		 
		/*Checking if the username and Password valid or not*/
		if(  !(strcmp(BANK_SYSTEM_ADMIN_USERNAME , Local_uint8bankAdminUsername))&&(BANK_SYSTEM_ADMIN_PASSWORD == Local_uint16bankAdminPassword) )
		{
			/*Firing a Flag that the password Checked successfully and valid*/
			Global_uint8bankCheck = BANK_SYSTEM_VALID;
		}
		else
		{
		 	/*Printing an Error message that the password entered is incorrect*/
			printf("The Password or username is incorrect, Please Try Again.\n");
		}
		/*Decrement the number of password Entering Trials*/		
		 Local_uint8bankTrials--;
	}
}

	
void bankSystem_VoiduserCheck()
{
	/*Pointer to struct to store the account Address needed to edit*/
	static Node * Local_PStructEditedstatus = NULL;
	/*Variable to scan in it the username and Password entered by the admin*/
	uint32 Local_uint8bankAdminPassword = 0;
	uint64 Local_uint8bankaccountid     = 0;
	/*Clearing the Password Validity Flag*/
	Global_uint8bankCheck = 0;
	 
	while(Global_uint8bankCheck == 0)
	{
		/*Scaning from the user the bank account id*/
		 printf("Please Enter The user bank account id : \n");
		 scanf("%d",&Local_uint8bankaccountid);
		/*Scaning from the user the Password*/
		 printf("Please Enter The user bank account Password : ");
		 scanf("%d",&Local_uint8bankAdminPassword);
		 
		/*Checking if the accound id and Password valid or not*/
		if(  (LinkedList_ID_Search(Local_uint8bankaccountid))  ) 
		{
			Local_PStructEditedstatus = LinkedList_ID_Search(Local_uint8bankaccountid);
			if(Local_PStructEditedstatus->uint8clientPassword == Local_uint8bankAdminPassword)
			{
			/*Firing a Flag that the password Checked successfully and valid*/
			Global_uint8bankCheck = BANK_SYSTEM_VALID;
			}
			else {printf("The Password is incorrect, Please Try Again.\n");}
		}
		else
		{
		 	/*Printing an Error message that the password entered is incorrect*/
			printf("The Password or username is incorrect, Please Try Again.\n");
		}
	}
}


 void bankSystem_VoidAdminAddNewAccountRecord()
 {
	/************************************ Scaning the new Account ID and check its validity *****************************************/
	/*Local Variable to gnerate the account ID */
	 static uint64  Local_uint8bankSystemNewID = 1000000000;
	/*Printing a bank account id*/
	 printf("bank account ID is : %d \n",Local_uint8bankSystemNewID);
	 /*Local Variable to gnerate the password*/
	 uint32  Local_uint8bankSystemNewIDPass = rand();
	 printf("bank account PASSWORD is : %d \n",Local_uint8bankSystemNewIDPass);
	 //uint8  Local_uint8bankSystemstatus[50] = "active";
	 int flag = 0;
	/***************************************** Storing the data of the new account *************************************************/
	
	/*New Dynamic Allocation Struct to store the New account Record*/
	 Node * Local_PStructNewclient = (Node*)malloc(sizeof(Node));
	
	/*Storing the client ID*/
	 Local_PStructNewclient -> uint8BankAccountID = Local_uint8bankSystemNewID;
	 /*Storing the client password*/
	 Local_PStructNewclient -> uint8clientPassword = Local_uint8bankSystemNewIDPass;
	/*Storing the client Full Name*/
	 fflush(stdin);
	 printf("Please Enter client Full Name :");
	 //scanf("%s",&Local_PStructNewclient-> uint8clientFullName);
	 gets(Local_PStructNewclient-> uint8clientFullName);
	 fflush(stdin);
	/*Storing the client Full Address*/
	 printf("Please Enter client FullAddress :");
	 //scanf("%s",&Local_PStructNewclient-> uint8clientFullAddress);
	 gets(Local_PStructNewclient-> uint8clientFullAddress);
	 fflush(stdin);
	/*Storing the client Age*/
	 printf("Please Enter client Age :");
	 scanf("%d",&Local_PStructNewclient-> uint8clientAge);
	 /*Storing the client National ID*/
	
	 printf("Please Enter client National ID :");
	 scanf("%s",&Local_PStructNewclient->uint8nationalID);
	
	 /*Storing the client Balance */
	 printf("Please Enter client balance :");
	 scanf("%d",&Local_PStructNewclient->uint8clientBalance);
	 printf("client balance :  %d \n", Local_PStructNewclient->uint8clientBalance);
	 /*Storing the client status*/
	 printf("Please Enter a for active by default to the status of account :");
	 scanf("%s",&Local_PStructNewclient-> uint8AccountStatus);
	 /*Storing the Guardian client National ID*/
	if ((Local_PStructNewclient->uint8clientAge) < 21 )
		{
		printf("Please Enter Guardian client National ID :");
		scanf("%s",&Local_PStructNewclient-> uint8GuardianNationalID); 	
		}
	/*Inserting the New account Record in the bank List*/
	 LinkedList_InsertNodeHead(Local_PStructNewclient);
	 
	/******************************************************************************************************************************/
	/*Printing Confirmation message that the client new account Record Added*/
	printf("account Records Added successfully.\n");
	Local_uint8bankSystemNewID +=1;
 }
 
 void bankSystem_VoidAdminEditAccountstatus()
 {	
	/*Pointer to struct to store the account Address needed to edit*/
	 static Node * Local_PStructEditedstatus = NULL;
	/*Variable to store the ID of the account needed to Edit*/
	 uint64  Local_uint8bankSystemNewID = 0;

	/************************************ Scaning the  account ID and check its validity *****************************************/
	/*Printing a message to the admin to enter the account ID*/
	 printf("Please Enter bank account ID Needed to Edit:");
	/*Scaning from the Admin the ID of the account needed to edit*/
	 scanf("%d",&Local_uint8bankSystemNewID);
	
	/*Checking if the ID Exist or Not*/
	 while(!LinkedList_ID_Search(Local_uint8bankSystemNewID))
	 {
		/*Printing a message to the admin that account ID not found*/
		 printf("Sorry This ID is not Found Be sure of the ID \n");
		/*Printing a message to the admin to enter the account ID*/
		printf("Please Enter bank account ID Needed to Edit:");
		scanf("%d",&Local_uint8bankSystemNewID);
	 }
	
	/******************************************** Editing account status Partition **************************************************/
	/*Storing the adresses of the wanted account to edit in a variable after found it*/
	 Local_PStructEditedstatus = LinkedList_ID_Search(Local_uint8bankSystemNewID);
	/*Printing a message to the admin to enter the New account status*/
	printf("Please Enter account New status :");
	scanf("%s",&Local_PStructEditedstatus-> uint8AccountStatus);
	/*Confirmation message that the account status changed*/
	printf("account status Changed Successfully.\n");
 }
 
 #if 0
 uint64 bank_id()
 {
	 uint64 Local_uint8bankSystemNewID = 0;
	/************************************ Scaning the  account ID and check its validity *****************************************/
	/*Printing a message to the admin to enter the bank account ID*/
	 printf("Please Enter bank account ID :");
	/*Scaning from the Admin the ID of the bank account needed to edit*/
	 scanf("%d",&Local_uint8bankSystemNewID);
	
	/*Checking if the ID Exist or Not*/
	 while(!LinkedList_ID_Search(Local_uint8bankSystemNewID))
	 {
		/*Printing a message to the admin that bank account ID not found*/
		printf("Sorry This ID is not Found Be sure of the ID \n");
		/*Printing a message to the admin to enter the bank account ID*/
		printf("Please reEnter bank account ID:");
		/*Scaning from the Admin the ID of the bank account needed to edit*/
		scanf("%d",&Local_uint8bankSystemNewID);
	 }
	 return Local_uint8bankSystemNewID;
 }
 #endif
 
 
 void bank_id()
{
	/*Pointer to struct to store the account Address needed to edit*/
	static Node * Local_PStructEditedstatus = NULL;
	/*Variable to scan in it the username and Password entered by the admin*/
	uint64 Local_uint8bankaccountid     = 0;
	/*Clearing the Password Validity Flag*/
	Global_uint8bankCheck = 0;
	 
	while(Global_uint8bankCheck == 0)
	{
		/*Scaning from the user the bank account id*/
		 printf("Please Enter The user bank account id : \n");
		 scanf("%d",&Local_uint8bankaccountid);
		
		 
		/*Checking if the accound id and Password valid or not*/
		if(  (LinkedList_ID_Search(Local_uint8bankaccountid))  ) 
		{
			Local_PStructEditedstatus = LinkedList_ID_Search(Local_uint8bankaccountid);
			Global_uint8bankCheck = BANK_SYSTEM_VALID;
			
		}
		else
		{
		 	/*Printing an Error message that the password entered is incorrect*/
			printf("The id is incorrect, Please Try Again.\n");
		}
	}
}

 
 void bankSystem_VoidAdmingetcash()
 {	

	/*Pointer to struct to store the account of client Address needed to edit*/
	static Node * Local_PStructEditedbalance = NULL;
	/*Variable to store the ID of the bank account needed to Edit*/
	 uint64   Local_uint8bankSystemNewID = 0;
	 uint32  Local_uint8getcash = 0;
	/************************************ Scaning the  account ID and check its validity *****************************************/
	
	/*Printing a message to the admin to enter the bank account ID*/
	 printf("Please Enter bank account ID :");
	/*Scaning from the Admin the ID of the bank account needed to edit*/
	 scanf("%d",&Local_uint8bankSystemNewID);
	
	/*Checking if the ID Exist or Not*/
	 while(!LinkedList_ID_Search(Local_uint8bankSystemNewID))
	 {
		/*Printing a message to the admin that bank account ID not found*/
		printf("Sorry This ID is not Found Be sure of the ID \n");
		/*Printing a message to the admin to enter the bank account ID*/
		printf("Please reEnter bank account ID:");
		/*Scaning from the Admin the ID of the bank account needed to edit*/
		scanf("%d",&Local_uint8bankSystemNewID);
	 }
	 
	/******************************************** get cash Partition **************************************************/
	/*Storing the adresses of the wanted bank account to edit in a variable after found it*/
	 Local_PStructEditedbalance = LinkedList_ID_Search(Local_uint8bankSystemNewID);
	 uint8 local[2]={'a'};
	if (!strcmp((Local_PStructEditedbalance->uint8AccountStatus) , local))
	{
		printf("cash is : %d\n",Local_PStructEditedbalance->uint8clientBalance);
		printf("Please Enter amount of cash you wanted to get :");
		scanf("%d",& Local_uint8getcash);
	
		if ( (Local_PStructEditedbalance->uint8clientBalance) > Local_uint8getcash  )
		{
			Local_PStructEditedbalance->uint8clientBalance -= Local_uint8getcash;
		
			printf("here is your cash and account balance Changed Successfully %d .\n",Local_PStructEditedbalance->uint8clientBalance);
		}
		else{
			printf("Please enter amount below than you current balance");
		}
	}
	else
	{
		printf("The acount status is not active , please activate it first \n");
	}
 }
 
 void bankSystem_VoidAdmindeposit()
 {	
	/*Pointer to struct to store the account of account Address needed to edit*/
	static Node * Local_PStructEditedbalance = NULL;
	
	/*Variable to store the ID of the bank account needed to Edit*/
	 uint64  Local_uint8bankSystemNewID = 0;
	 uint32  Local_uint8deposit = 0;
	/************************************ Scaning the  account ID and check its validity *****************************************/
	/*Printing a message to the admin to enter the bank account ID*/
	 printf("Please Enter bank account ID Needed to Edit:");
	/*Scaning from the Admin the ID of the bank account needed to edit*/
	 scanf("%d",&Local_uint8bankSystemNewID);
	
	/*Checking if the ID Exist or Not*/
	 while(!LinkedList_ID_Search(Local_uint8bankSystemNewID))
	 {
		/*Printing a message to the admin that bank account ID not found*/
		printf("Sorry This ID is not Found Be sure of the ID \n");
		/*Printing a message to the admin to enter the bank account ID*/
		printf("Please Enter bank account ID Needed to Edit:");
		/*Scaning from the Admin the ID of the bank account needed to edit*/
		scanf("%d",&Local_uint8bankSystemNewID);
	 }
	
	/******************************************** deposit Partition **************************************************/
	/*Storing the adresses of the wanted bank account to edit in a variable after found it*/
	 Local_PStructEditedbalance = LinkedList_ID_Search(Local_uint8bankSystemNewID);
	 uint8 local[2]={'a'};
	 if (!strcmp((Local_PStructEditedbalance->uint8AccountStatus) , local))
	{
		/*Printing a message to the admin to enter the amount her want to deposit*/
		printf("cash is : %d\n",Local_PStructEditedbalance->uint8clientBalance);
		printf("Please Enter amount of cash you wanted to deposit :");
		/*Scaning from the Admin the amount he want to deposit*/
		scanf("%d",& Local_uint8deposit);
		Local_PStructEditedbalance->uint8clientBalance += Local_uint8deposit;
	
		/*Confirmation message that the action is done*/
		printf("Your account balance Changed Successfully.%d\n",Local_PStructEditedbalance->uint8clientBalance);
	}
	else
	{
		printf("The acount status is not active , please activate it first\n");
	}
 }
 
 
void bankSystem_VoidAdminChangePassword()
  {
	  /*Pointer to struct to store the account Address needed to edit*/
	 static Node * Local_PStructEditedstatus = NULL;
	/*Variable to store the ID of the acount needed to Edit*/
	 uint64  Local_uint8bankSystemNewID = 0;

	/************************************ Scaning the  account ID and check its validity *****************************************/
	/*Printing a message to the admin to enter the account ID*/
	 printf("Please Enter bank account ID Needed to Edit:");
	/*Scaning from the Admin the ID of the account needed to edit*/
	 scanf("%d",&Local_uint8bankSystemNewID);
	
	/*Checking if the ID Exist or Not*/
	 while(!LinkedList_ID_Search(Local_uint8bankSystemNewID))
	 {
		/*Printing a message to the admin that account id not found*/
		 printf("Sorry This ID is not Found Be sure of the ID \n");
		 /*Printing a message to the admin to enter the account id*/
		printf("Please Enter bank account ID Needed to Edit:");
		/*Scaning from the Admin the ID of the account needed to edit*/
		scanf("%d",&Local_uint8bankSystemNewID);
	 }
	
	/******************************************** Editing account password Partition **************************************************/
	
	/*Storing the adresses of the wanted account to edit in a variable after found it*/
	 Local_PStructEditedstatus = LinkedList_ID_Search(Local_uint8bankSystemNewID);
	/*Printing a message to the admin to enter the account New password*/
	printf("Please Enter account New password :");
	/*Scaning from the Admin the  the account New password*/
	scanf("%d",&Local_PStructEditedstatus-> uint8clientPassword);
				 
	/*Confirmation message that the account password changed*/
	printf("account password Changed Successfully.\n");
 }
	  


void bankSystem_VoidAdminTransaction()
 {	
	/*Pointer to struct to store the account of client Address needed to transfare money from*/
	static Node * Local_PStructTransactionFrom = NULL;
	/*Variable to store the ID of the bank account needed to transfare money from and to*/
	 uint64   Local_uint8bankSystemFromID = 0;
	 uint32  Local_uint8getcash = 0;
	/************************************ Scaning the  account ID and check its validity *****************************************/
	/*Printing a message to the admin to enter the bank account ID*/
	 printf("Please Enter bank account ID Needed to transfare money from:");
	/*Scaning from the Admin the ID of the bank account needed to edit*/
	 scanf("%d",&Local_uint8bankSystemFromID);
	/*Checking if the ID Exist or Not*/
	 while(!LinkedList_ID_Search(Local_uint8bankSystemFromID) )
	 {
		/*Printing a message to the admin that bank account ID not found*/
		printf("Sorry This ID is not Found Be sure of the ID \n");
		/*Printing a message to the admin to enter the bank account ID*/
		printf("Please Enter bank account ID Needed to transfare money from:");
		/*Scaning from the Admin the ID of the bank account needed to edit*/
		scanf("%d",&Local_uint8bankSystemFromID);
	 }
	/******************************************** get cash Partition **************************************************/
	/*Storing the adresses of the wanted bank account to edit in a variable after found it*/
	Local_PStructTransactionFrom = LinkedList_ID_Search(Local_uint8bankSystemFromID);
	uint8 local[2]={'a'};
	if (!strcmp((Local_PStructTransactionFrom->uint8AccountStatus) , local))
	{
		printf("Please Enter amount of money you wanted to transfare :");
		scanf("%d",& Local_uint8getcash);
			if ( (Local_PStructTransactionFrom->uint8clientBalance) > Local_uint8getcash  )
			{
				Local_PStructTransactionFrom->uint8clientBalance -= Local_uint8getcash;
				//Local_PStructTransactionTo->uint8clientBalance += Local_uint8getcash;
				printf("Ok you can make this transaction and your balance will be :%d .\n",Local_PStructTransactionFrom->uint8clientBalance);
			}
			else{
				printf("Please enter amount below than you current balance\n");
				goto label;
			}
	
	/*Printing a message to the admin to enter the bank account ID*/
	 printf("Please Enter bank account ID Needed to transfare money to:");
	/*Scaning from the Admin the ID of the bank account needed to edit*/
	 scanf("%d",&Local_uint8bankSystemFromID);
	 if(!LinkedList_ID_Search(Local_uint8bankSystemFromID) )
	 {
		/*Printing a message to the admin that bank account ID not found*/
		printf("Sorry This ID is not Found Be sure of the ID \n");
		goto label;
	 }
	 Local_PStructTransactionFrom = LinkedList_ID_Search(Local_uint8bankSystemFromID);
		if (!strcmp((Local_PStructTransactionFrom->uint8AccountStatus) , local))
		{
		
		Local_PStructTransactionFrom->uint8clientBalance += Local_uint8getcash;
		printf("Transaction is done Successfully %d .\n",Local_PStructTransactionFrom->uint8clientBalance );
		}
		else{printf("The acount status is not active , please activate it first\n");}
	}
	else
	{
		printf("The acount status is not active , please activate it first\n");
		
	label:
	{
	printf("Transaction can not be done\n");
	}
	}
	
 }
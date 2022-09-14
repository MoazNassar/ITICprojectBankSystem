/*main of bank system management project iti by moaz nassar*/

#include<stdio.h>
#include<stdlib.h>

#include"STD_TYPES.h"
#include"linkedlist.h"
#include"bank.h"

/*global variables*/
uint8 Global_uint8bankSystemMode 	     	= 0;									//Variable To Store the Mode of the system.
uint8 Global_uint8bankSystemModes_ON_OFF 	= 0;									//Variable To Store the Mode of the system.
uint8 Global_uint8bankSystemAdminOption  	= 0;									//Variable To Store The Option Entered By the Admin.
uint8 Global_uint8bankSystemUserOption  	= 0;									//Variable To Store The Option Entered By the Admin.
uint8 Global_uint8bankSystemAdminOPENOption = 0;	

extern uint8 Global_uint8bankCheck;								 	//Variable To Store That The Admin Password is Valid.

void main(void)
{
	while(1)
	{
		/*Printing an interface to the user to Choose the system mode*/
		printf("|**************************************** Bank System ******************************************|\n\
			  \r|Please Enter (1) For Admin Mode				                               	|\n\
			  \r|Please Enter (2) For User Mode					                               	|\n\
			  \r|***********************************************************************************************|\n");
		
		/*Scaning from the user the system mode*/
		scanf("%d",&Global_uint8bankSystemMode);
		
		/*Switching on the entered mode*/
		switch(Global_uint8bankSystemMode)
		{	
			/******************************************************************************************************************************/
			/**************************************************** ADMIN MODE **************************************************************/
			/******************************************************************************************************************************/
			 case BANK_SYSTEM_ADMIN_MODE:
				/*Checking the Validity of the Password*/
				 bankSystem_VoidAdminCheck();
				/*Checking from the Global Variable that the Password checking is done successfully*/
				 if(BANK_SYSTEM_VALID == Global_uint8bankCheck)
				 {
					/*Admin mode Activated*/
					 Global_uint8bankSystemModes_ON_OFF = BANK_SYSTEM_ADMIN_MODE_ON;
					/*Admin mode Activated till the Admin Press Exit from the options*/
					 while(BANK_SYSTEM_ADMIN_MODE_ON == Global_uint8bankSystemModes_ON_OFF)
					 {
						/*Printing an interface to the Admin to Choose An Option*/
						 printf("|************************************ Welcome In Admin Mode **************************************|\n\
							   \r|Please Enter (1) To Create new account.                                             |\n\
							   \r|Please Enter (2) To open existing account.                                          |\n\
							   \r|Please Enter (3) To Exit from Admin Mode.                                           |\n\
							   \r|*************************************************************************************************|\n");
						/*Scaning the option Entered by the Admin*/
						 scanf("%d",&Global_uint8bankSystemAdminOption);
						/*Scaning the option Entered by the Admin while it is invalid*/
						 while(Global_uint8bankSystemAdminOption > BANK_SYSTEM_ADMIN_OPTIONS_NUM)
						 {
							/*Printing a message to the Admin to Reenter the option he want*/
							 printf("Please Enter a valid Option : ");
							
							/*Rescaning the Option from the Admin*/
							 scanf("%d",&Global_uint8bankSystemAdminOption);
						 }
						/*Switching on the Option Entered by the Admin*/
						 switch(Global_uint8bankSystemAdminOption)
						 {
							/******************************** BANK_SYSTEM_CREATE_NEW_ACCOUNT ***************************************/
							 case BANK_SYSTEM_CREATE_NEW_ACCOUNT:
									
									/*Calling the Function to create a new account*/
									bankSystem_VoidAdminAddNewAccountRecord();
									
									/*Refreshing the Activation of the Admin Mode*/
									Global_uint8bankSystemModes_ON_OFF = BANK_SYSTEM_ADMIN_MODE_ON;
							 break;
							
							/********************************* BANK_SYSTEM_OPEN_EXISTING_ACCOUNT ****************************************/
							
							 case BANK_SYSTEM_OPEN_EXISTING_ACCOUNT:
									LinkedList_Traverse();
									bank_id();
									printf("|********************* Welcome In Admin Mode BANK_SYSTEM_OPEN_EXISTING_ACCOUNT *******************|\n\
									\r|Please Enter (1) To make transaction.                             	   |\n\
									\r|Please Enter (2) To change account status.                              |\n\
									\r|Please Enter (3) To get cash.   			        	                   |\n\
									\r|Please Enter (4) To deposite in account.   			                   |\n\
									\r|Please Enter (5) To return to main menu.   			                   |\n\
									\r|*******************************************************************************************************|\n");
									
									/*Scaning the option Entered by the Admin*/
									scanf("%d",&Global_uint8bankSystemAdminOPENOption);
									/*Scaning the option Entered by the Admin while it is invalid*/
									while(Global_uint8bankSystemAdminOPENOption > BANK_SYSTEM_ADMIN_OPEN_OPTIONS_NUM)
									{
										/*Printing a message to the Admin to Reenter the option he want*/
										printf("Please Enter a valid Option : ");
										/*Rescaning the Option from the Admin*/
										scanf("%d",&Global_uint8bankSystemAdminOPENOption);
									}
									
									/*Switching on the Option Entered by the Admin*/
									switch(Global_uint8bankSystemAdminOPENOption)
									{
										/******************************** BANK_SYSTEM_MAKE_TRANSACTION ***************************************/
										case BANK_SYSTEM_MAKE_TRANSACTION:
									
											/*Calling the Function to make a transaction*/
											bankSystem_VoidAdminTransaction();
											/*Refreshing the Activation of the Admin Mode*/
											Global_uint8bankSystemModes_ON_OFF = BANK_SYSTEM_ADMIN_MODE_ON;
										break;
										/******************************** BANK_SYSTEM_CHANGE_STATUS ***************************************/
										case BANK_SYSTEM_CHANGE_STATUS:
											/*Calling the Function to change account status*/
											bankSystem_VoidAdminEditAccountstatus();
									
											/*Refreshing the Activation of the Admin Mode*/
											Global_uint8bankSystemModes_ON_OFF = BANK_SYSTEM_ADMIN_MODE_ON;
										break;
										/******************************** BANK_SYSTEM_GET_CASH ***************************************/
										case BANK_SYSTEM_GET_CASH:
											/*Calling the Function to get cash*/
											bankSystem_VoidAdmingetcash();
									
											/*Refreshing the Activation of the Admin Mode*/
											Global_uint8bankSystemModes_ON_OFF = BANK_SYSTEM_ADMIN_MODE_ON;
										break;
										/******************************** BANK_SYSTEM_DEPOSIT_IN_ACCOUNT ***************************************/
										case BANK_SYSTEM_DEPOSIT_IN_ACCOUNT:
											/*Calling the Function to deposit in account*/
											 bankSystem_VoidAdmindeposit();
									
											/*Refreshing the Activation of the Admin Mode*/
											Global_uint8bankSystemModes_ON_OFF = BANK_SYSTEM_ADMIN_MODE_ON;
										break;
										/******************************** BANK_SYSTEM_RETURN_MAIN_MENU ***************************************/
										case BANK_SYSTEM_RETURN_MAIN_MENU:
											/*Refreshing the Activation of the Admin Mode*/
											Global_uint8bankSystemModes_ON_OFF = BANK_SYSTEM_ADMIN_MODE_ON;
										break;
									
									/*Refreshing the Activation of the Admin Mode*/
									Global_uint8bankSystemModes_ON_OFF = BANK_SYSTEM_ADMIN_MODE_ON;
									}
							 break;
							 
							 
							 /*********************************** BANK_SYSTEM_EXIT_ADMIN_MODE *******************************************/
							case BANK_SYSTEM_EXIT_ADMIN_MODE:
								
									/*Deactivate the Admin Mode*/
									Global_uint8bankSystemModes_ON_OFF = BANK_SYSTEM_ADMIN_MODE_OFF;
							break;
							
							/************************************************************************************************************/
						 }
					 }
				 }
				 else
				 {
					/*Printing an Error message that the password Entring Trials Ran out*/	
					 printf("Sorry, You Used all the Trials. \n");
				 }
			 break;
			
			/******************************************************************************************************************************/
			/***************************************************** USER MODE **************************************************************/
			/******************************************************************************************************************************/
			 case BANK_SYSTEM_USER_MODE:
					bankSystem_VoiduserCheck();
					if(BANK_SYSTEM_VALID == Global_uint8bankCheck)
					{
					/*Activate User Mode*/
					 Global_uint8bankSystemModes_ON_OFF = BANK_SYSTEM_USER_MODE_ON;
					/*User mode Activated till the User Press Exit from the options*/
					 while(BANK_SYSTEM_USER_MODE_ON == Global_uint8bankSystemModes_ON_OFF)
					 {
						/*Printing an interface to the User to Choose An Option*/
						 printf("|*********************************** Welcome In User Mode **************************************|\n\
							   \r|Please Enter (1) To make transaction.                                               |\n\
							   \r|Please Enter (2) To change account password.                                        |\n\
							   \r|Please Enter (3) To get cash.                                                       |\n\
							   \r|Please Enter (4) To deposite in account.                                            |\n\
							   \r|Please Enter (5) To return to main menu.             	                              |\n\
							   \r|***********************************************************************************************|\n");
						
						/*Scaning the option Entered by the User*/
						 scanf("%d",&Global_uint8bankSystemUserOption);
						/*Scaning the option Entered by the User while it is invalid*/
						 while(Global_uint8bankSystemUserOption > BANK_SYSTEM_USER_OPTIONS_NUM)
						 {
							/*Printing a message to the User to Reenter the option he want*/
							 printf("Please Enter a valid Option : ");
							 
							/*Rescaning the Option from the User*/
							 scanf("%d",&Global_uint8bankSystemUserOption);
						 }
						
						/*Switching on the Option Entered by the User*/
						 switch(Global_uint8bankSystemUserOption)
						 {
							/********************************* BANK_SYSTEM_MAKE_TRANSACTION *****************************************/
							
							case BANK_SYSTEM_MAKE_TRANSACTION:
							
									bankSystem_VoidAdminTransaction();
									
									/*Refreshing the Activation of the User Mode*/
									 Global_uint8bankSystemModes_ON_OFF = BANK_SYSTEM_USER_MODE_ON;
							break;
							
							/******************************* BANK_SYSTEM_CHANGE_PASSWORD **************************************/
							
							case BANK_SYSTEM_CHANGE_PASSWORD:
							
									bankSystem_VoidAdminChangePassword();
									
									/*Refreshing the Activation of the User Mode*/
									 Global_uint8bankSystemModes_ON_OFF = BANK_SYSTEM_USER_MODE_ON;
							break;
							/******************************* BANK_SYSTEM_GET_CASH **************************************/
							
							case BANK_SYSTEM_GET_CASH:
							
									
									bankSystem_VoidAdmingetcash();
									
									/*Refreshing the Activation of the User Mode*/
									Global_uint8bankSystemModes_ON_OFF = BANK_SYSTEM_USER_MODE_ON;
							break;				
							
							/*********************************** BANK_SYSTEM_DEPOSIT_IN_ACCOUNT *******************************************/
							
							case BANK_SYSTEM_DEPOSIT_IN_ACCOUNT:
									bankSystem_VoidAdmindeposit();
									
									/*Deactivate the User Mode*/
									Global_uint8bankSystemModes_ON_OFF = BANK_SYSTEM_USER_MODE_ON;
							break;
							
							
							/*********************************** BANK_SYSTEM_RETURN_MAIN_MENU *******************************************/
							
							case BANK_SYSTEM_RETURN_MAIN_MENU:
								
									/*Deactivate the User Mode*/
									Global_uint8bankSystemModes_ON_OFF = BANK_SYSTEM_USER_MODE_OFF;
							break;
							/************************************************************************************************************/
						 }
					  }
			 break;
			
			 default:
			
					/*Printing an Error Message that the input is invalid*/
					printf("Sorry,Please Enter a valid choice.\n\n");
			 break;
			
		            }
		 }
	 }
 }
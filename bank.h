
#ifndef BANK_H
#define BANK_H

/**************************************** System Modes Macros **************************************************************/

#define BANK_SYSTEM_ADMIN_MODE 						1											//Admin Mode Option.
#define BANK_SYSTEM_USER_MODE  						2											//User Mode Option.

#define BANK_SYSTEM_ADMIN_MODE_ON 					1											//Admin Mode ON.
#define BANK_SYSTEM_ADMIN_MODE_OFF					2											//Admin Mode OFF.
#define BANK_SYSTEM_USER_MODE_ON  					3											//User Mode ON.
#define BANK_SYSTEM_USER_MODE_OFF 					4											//User Mode OFF.

/**************************************** Admin Password Macros *************************************************************/

#define BANK_SYSTEM_MAX_TRIALS  						3   									//Admin Entering Maximum trials.
#define BANK_SYSTEM_ADMIN_USERNAME						"moaz"									//Admin username .
#define BANK_SYSTEM_ADMIN_PASSWORD  					1234									//Admin Password value.
#define BANK_SYSTEM_VALID			 					1   									//Comparator Validity.

#define BANK_SYSTEM_ADMIN_OPTIONS_NUM 				3											//Number of the Admin Options Avaliable.
#define	BANK_SYSTEM_CREATE_NEW_ACCOUNT				1											//Create new account record Option.
#define	BANK_SYSTEM_OPEN_EXISTING_ACCOUNT			2											
#define BANK_SYSTEM_EXIT_ADMIN_MODE					3											

#define BANK_SYSTEM_ADMIN_OPEN_OPTIONS_NUM			5
#define	BANK_SYSTEM_MAKE_TRANSACTION				1														
#define BANK_SYSTEM_CHANGE_STATUS					2														
#define BANK_SYSTEM_GET_CASH						3														
#define BANK_SYSTEM_DEPOSIT_IN_ACCOUNT				4														
#define BANK_SYSTEM_RETURN_MAIN_MENU				5

/*************************************** User Mode Options Macros ********************************************************/

#define BANK_SYSTEM_USER_OPTIONS_NUM 				5											

#define	BANK_SYSTEM_MAKE_TRANSACTION				1											
#define	BANK_SYSTEM_CHANGE_PASSWORD					2											
#define BANK_SYSTEM_GET_CASH						3											
#define BANK_SYSTEM_DEPOSIT_IN_ACCOUNT				4
#define BANK_SYSTEM_RETURN_MAIN_MENU				5

 void bankSystem_VoidAdminCheck();
 void bankSystem_VoidAdminAddNewAccountRecord();
 void bankSystem_VoidAdminEditAccountstatus();
 void bankSystem_VoidAdmingetcash();
 void bankSystem_VoidAdmindeposit();
 void bankSystem_VoidAdminMakeTransaction();
 void bankSystem_VoidAdminChangePassword();
 void bankSystem_VoiduserCheck();
 void bankSystem_VoidAdminTransaction();
 void bank_id();
#endif /*BANK_H*/
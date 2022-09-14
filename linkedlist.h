/*linkedlist.h of bank system management project iti by moaz nassar*/

#ifndef Linked_List_H
#define Linked_List_H

#define bankSystem_NAME_SIZE	 100														//Number of Name characters.
#define bankSystem_ID_NOT_EXIST   0															//Comparator with ID is Not Exist.

/*Structure as a account*/
typedef struct node                         
{
    uint32  uint8BankAccountID;
	uint8  uint8clientFullName[bankSystem_NAME_SIZE];
	uint8  uint8clientFullAddress[bankSystem_NAME_SIZE];
	uint8  uint8AccountStatus[bankSystem_NAME_SIZE];
	uint8  uint8nationalID[bankSystem_NAME_SIZE];
    uint8  uint8clientAge;
	uint32  uint8clientBalance;
	uint8  uint8GuardianNationalID[bankSystem_NAME_SIZE];
    uint32  uint8clientPassword;
	
    struct node * NextNode;
}Node;

void LinkedList_InsertNodeHead(Node * CopyStructNewAccount); 
Node  *  LinkedList_ID_Search(uint64 Copy_uint8clientID);
void LinkedList_StringStore(uint8 * Copy_uint8String, uint8 * Copy_uint8StoringDestination);
void LinkedList_StringPrint(uint8 * Copy_uint8String);
void LinkedList_Traverse();

#endif /* Linked_List_H */
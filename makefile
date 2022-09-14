
#make rule to generate the final binary

Bank_system: main.o bank.o linkedlist.o
	gcc main.o bank.o linkedlist.o -o Bank_system.exe
	

main.o: bank.c main.c linkedlist.c
	gcc -c main.c

bank.o: bank.c bank.h
	gcc -c bank.c
	
linkedlist.o: linkedlist.c linkedlist.h
	gcc -c linkedlist.c
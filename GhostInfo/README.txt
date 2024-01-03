Mathavan Vallipuram 

Description: A program that allows user's to find information about ghosts through the ghost masterlist, or through the different rooms sorted using the ID. The information of the ghost masterlist can also be seen sorted by likelihood. 

Files: main.c room.c ghost.c building.c defs.h

compilation command: gcc -o ghostInfo main.c room.c ghost.c building.c

Command to run: ./ghostInfo

When prompted for input: Select 1, 2, 3 to print out the information.
	If 1 is selected, it will print out all the ghosts seen in known rooms, sorted by ID.
	If 2 is selected, it will print out the ghost masterlist, which shows all the ghosts, sorted by ID.
	If 3 is selected, it will print out the ghost masterlist, but sorted by Likelihood.
	If 0 is selected, the program will end.
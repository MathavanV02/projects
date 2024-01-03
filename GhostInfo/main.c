#include "defs.h"

int main()
{
    //Creating a local building type
    BuildingType building;

    //initializing the building
    initBuilding(&building);

    //loading the data to the building type
    loadBuildingData(&building);
  
  //creating an integer set to -1 
  int choice = -1;

  //Will loop continuously unless broken
  while (1){

    //Calls the printMenu function
    printMenu(&choice);
    
    //if choice 1 is selected
    if (choice ==1){

      //prints the header
      printf("%10s%15s%10s%20s%15s\n", "Ghost ID", "Ghost Type", "Room ID", "Room Name", "Likelihood");

      //prints all the rooms
      printRooms(&building.rooms);
    }

    //if choice 2 is selected
    else if(choice ==2){

      //prints the header
      printf("%10s%15s%10s%20s%15s\n", "Ghost ID", "Ghost Type", "Room ID", "Room Name", "Likelihood");

      //prints the masterlist of ghosts in order of ID
      printGhosts(&building.ghosts, C_FALSE);
    }

    //if choice 1 is selected
    else if(choice == 3){

      //prints the header
      printf("%10s%15s%10s%20s%15s\n", "Ghost ID", "Ghost Type", "Room ID" ,"Room Name", "Likelihood");

      //prints the masterlist of ghosts in order of Likelihood
      printByLikelihood(&building.ghosts, C_FALSE);
    }


    else if(choice == 0){

      //if 0 is selected then cleanup function is called
      cleanupBuilding(&building);

      //ending the loop
      break;
    }

    else{

      //if anything else is inputted, the user is asked for input again
      
    }
  }

  return(0);
}

/*
Function: printMenu
 Purpose: Prints the menu out to the user and process' their input
  in/out: int *choice, a pointer that is 'returned' back with the user input
*/
void printMenu(int *choice)
{
  int c = -1;
  int numOptions = 3;

  printf("\nMAIN MENU\n");
  printf("  (1) Print rooms\n");
  printf("  (2) Print ghosts\n");
  printf("  (3) Print ghosts by likelihood\n");
  printf("  (0) Exit\n\n");

  printf("Please enter your selection: ");
  scanf("%d", &c);

  if (c == 0) {
    *choice = c;
    return;
  }

  while (c < 0 || c > numOptions) {
    printf("Please enter your selection: ");
    scanf("%d", &c);
  }

  *choice = c;
}


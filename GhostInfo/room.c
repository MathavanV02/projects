#include "defs.h"

/*
Function: initRoomArray
 Purpose: initializes the RoomArrayType passed in by the user
  in/out: RoomArrayType *arr, takes in a roomtypearray and sets the size of it to 0.
*/
void initRoomArray(RoomArrayType *arr){

    //sets array size to 0
    arr->size = 0;
}

/*
Function: initRoom
 Purpose: initializes all the values of the Room and dynamically allocates memory of the room
      in: int id, holds the id
      in: char* name, holds the name of the room
  in/out: RoomType **room, user inputted room that is to be initialized and returned
*/
void initRoom(int id, char* name, RoomType **room){

    //dynamically allocated the room
    *room = (RoomType*) malloc(sizeof(RoomType));

    //sets the id to the room's id
    (*room)->id = id;

    //sets the room name to the name parameter
    strcpy((*room)->name, name);

    //dynamically allocates the ghostList of the room
    (*room)->ghosts = (GhostListType*) malloc(sizeof(GhostListType));

    //initializes the ghostlist
    initGhostList((*room)->ghosts);

}

/*
Function: addRoom
 Purpose: adds the room the the RoomArray
      in: RoomType *r, gets added to the end of the RoomArray
  in/out: RoomArrayType *arr, adds the room to the array and 'returns' the array
*/
void addRoom(RoomArrayType *arr, RoomType *r){
    
    //increases array size by 1
    arr->size+=1;

    //adds r to the end of the array
    arr->elements[arr->size-1] = r;

}

/*
Function: cleanupRoomArray
 Purpose: deallocates the memory stored in the heap in the RoomArrayType
  in/out: RoomArrayType *arr, gets it's memory deallocated
*/
void cleanupRoomArray(RoomArrayType *arr){
    
    
    for (int i = 0;i<arr->size;i++){
        
        //cleaning up the ghosts in the different sections of the roomtypeArray
        cleanupGhostList(arr->elements[i]->ghosts);

        //freeing the elements of the roomtypearray
        free(arr->elements[i]);
    }
}

/*
function: printRooms
 purpose: Prints out the rooms in the roomarraytype
  in/out: RoomArrayType *arr, takes the user inputted roomarraytype and gets it's elements printed
*/
void printRooms(RoomArrayType *arr){
    for (int i = 0; i<arr->size;i++){

        //calling printGhosts to print the ghosts stored in arr
        printGhosts(arr->elements[i]->ghosts, C_FALSE);
    }
}
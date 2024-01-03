#include "defs.h"

/*
Function: loadBuildingData
 Purpose: loads the building data into the variable building
  in/out: BuildingType *building, user inputs a local buildingType and it is returned with information stored
*/
void loadBuildingData(BuildingType *building)
{
  GhostType*  ghost;
  RoomType*   room;
  int currRoomId = NEXT_ROOM_ID;
  int currGhostId = NEXT_GHOST_ID;

  initRoom(currRoomId++, "Master Bedroom", &room);
  addRoom(&building->rooms, room);
  initGhost(currGhostId++, PHANTOM, room, 50.09f, &ghost);
  addGhost(&building->ghosts, ghost);
  addGhost(room->ghosts, ghost);
  initGhost(currGhostId++, WRAITH, room, 47.33f, &ghost);
  addGhost(&building->ghosts, ghost);
  addGhost(room->ghosts, ghost);
  initGhost(currGhostId++, OTHER, room, 62.46f, &ghost);
  addGhost(&building->ghosts, ghost);
  addGhost(room->ghosts, ghost);

  initRoom(currRoomId++, "Bathroom", &room);
  addRoom(&building->rooms, room);
  initGhost(currGhostId++, OTHER, room, 17.42f, &ghost);
  addGhost(&building->ghosts, ghost);
  addGhost(room->ghosts, ghost);
  initGhost(currGhostId++, PHANTOM, room, 98.64f, &ghost);
  addGhost(&building->ghosts, ghost);
  addGhost(room->ghosts, ghost);
  initGhost(currGhostId++, BULLIES, room, 11.88f, &ghost);
  addGhost(&building->ghosts, ghost);
  addGhost(room->ghosts, ghost);

  initRoom(currRoomId++, "Guest Bedroom", &room);
  addRoom(&building->rooms, room);
  initGhost(currGhostId++, POLTERGEIST, room, 15.60f, &ghost);
  addGhost(&building->ghosts, ghost);
  addGhost(room->ghosts, ghost);

  initRoom(currRoomId++, "Living Room", &room);
  addRoom(&building->rooms, room);
  initGhost(currGhostId++, OTHER, room, 77.71f, &ghost);
  addGhost(&building->ghosts, ghost);
  addGhost(room->ghosts, ghost);

  initRoom(currRoomId++, "Kitchen", &room);
  addRoom(&building->rooms, room);
  initGhost(currGhostId++, POLTERGEIST, room, 34.33f, &ghost);
  addGhost(&building->ghosts, ghost);
  addGhost(room->ghosts, ghost);
  initGhost(currGhostId++, BULLIES, room, 1.85f, &ghost);
  addGhost(&building->ghosts, ghost);
  addGhost(room->ghosts, ghost);
  initGhost(currGhostId++, PHANTOM, room, 60.44f, &ghost);
  addGhost(&building->ghosts, ghost);
  addGhost(room->ghosts, ghost);

  initRoom(currRoomId++, "Dining Room", &room);
  addRoom(&building->rooms, room);
  initGhost(currGhostId++, OTHER, room, 23.81f, &ghost);
  addGhost(&building->ghosts, ghost);
  addGhost(room->ghosts, ghost);

  initRoom(currRoomId++, "Basement", &room);
  addRoom(&building->rooms, room);
  initGhost(currGhostId++, WRAITH, room, 42.40f, &ghost);
  addGhost(&building->ghosts, ghost);
  addGhost(room->ghosts, ghost);
  initGhost(currGhostId++, PHANTOM, room, 62.89f, &ghost);
  addGhost(&building->ghosts, ghost);
  addGhost(room->ghosts, ghost);

  initRoom(currRoomId++, "Attic", &room);
  addRoom(&building->rooms, room);
  initGhost(currGhostId++, POLTERGEIST, room, 12.28f, &ghost);
  addGhost(&building->ghosts, ghost);
  addGhost(room->ghosts, ghost);
  initGhost(currGhostId++, WRAITH, room, 30.85f, &ghost);
  addGhost(&building->ghosts, ghost);
  addGhost(room->ghosts, ghost);

  initRoom(currRoomId++, "Garage", &room);
  addRoom(&building->rooms, room);

  initRoom(currRoomId++, "Entryway", &room);
  addRoom(&building->rooms, room);

  initRoom(currRoomId++, "Hallway", &room);
  addRoom(&building->rooms, room);

  initRoom(currRoomId++, "Staircase", &room);
  addRoom(&building->rooms, room);

  initGhost(currGhostId++, POLTERGEIST, NULL, 38.0f, &ghost);
  addGhost(&building->ghosts, ghost);

  initGhost(currGhostId++, OTHER, NULL, 98.2f, &ghost);
  addGhost(&building->ghosts, ghost);
}

/*
Function: initBuilding
 Purpose: initializes the inputted buildingType
  in/out: BuildingType *b, inputted in by user in order to be initialized and 'returned'
*/
void initBuilding(BuildingType *b){

  //initializes the ghostlist in building
  initGhostList(&b->ghosts);

  //initializes the RoomArray in building
  initRoomArray(&b->rooms);
}

/*
Function: cleanupBuilding
 Purpose: deallocates the memory in the building
  in/out: takes in a buildingtype and returns it with its memory deallocated
*/
void cleanupBuilding(BuildingType *b){

    //deallocates the roomarray 
    cleanupRoomArray(&b->rooms);

    //deallocates the ghost data
    cleanupGhostData(&b->ghosts);

    //deallocates the ghost list
    cleanupGhostList(&b->ghosts);
    
}

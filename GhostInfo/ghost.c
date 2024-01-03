#include "defs.h"

/*
Function: initGhostList
 Purpose: initializes the ghostlist
  in/out: GhostListType *list, takes in a ghostlist initializes it and 'returns' it
*/
void initGhostList(GhostListType* list){

    //sets the list's head to null
    list->head = NULL;

    //sets the tail of the list to null
    list->tail = NULL;
}

/*
Function: initGhost
 Purpose: initializes the inputted ghost
      in: int id, Id of the ghost
      in: GhostEnumType gt, Type of ghost spotted
      in: RoomType *r, Which room the ghost was found in
      in: float like, the likelihood of the ghost
  in/out: GhostType **ghost, takes all the parameters and initializes them to the ghost
*/
void initGhost(int id, GhostEnumType gt, RoomType *r, float like, GhostType **ghost){

    //dynamically allocating the ghost
    *ghost = (GhostType*) malloc(sizeof(GhostType));

    //setting the ghostType for the ghost
    (*ghost)->ghostType = gt;

    //setting the id of the ghost
    (*ghost)->id = id;

    //setting the room for the ghost
    (*ghost)->room = r;

    //setting the liklihood of the ghost
    (*ghost)->likelihood = like;
}

/*
Function: addGhost
 Purpose: adds a ghost to the end of the linked list
  in/out: GhostListType *list, takes in the ghost and adds it to the end of the list
      in: GhostType *ghost, a ghost that is to be added to the ghostlist
*/
void addGhost(GhostListType *list, GhostType *ghost){
    
    //creating a new node
    NodeType* new = NULL;
    
    //dynamically allocating the node
    new = (NodeType*)malloc(sizeof(NodeType));

    //setting the data in new to ghost
    new->data = ghost;

    //checking if list is empty
    if (list->head == NULL){

        //sets the head and tail to new
        list->head = new;
        list->tail = new;
    }
    else{

        //setting the node after tail to new
        list->tail->next = new;

        //setting that node to tail now
        list->tail = new;

    }
    
    
}

/*
Function: addGhostByLikelihood
 Purpose: adds the ghost to list in order of likelihood
      in: GhostType *ghost, takes the ghost that is to be added to the list
  in/out: GhostListType *list, takes the old list, updates it and 'returns' it
*/
void addGhostByLikelihood(GhostListType *list, GhostType *ghost){

    //creating a node to represent the current node
    NodeType* curr = list->head;

    //creating a node to represent the previous node
    NodeType* prev = NULL;

    //creating a node to represent a new node to be added
    NodeType* new = NULL;

    //checking while curr is not null
    while (curr!= NULL){

        //if the ghost's likeligood is larger than the current data's, the loop is broken
        if (ghost->likelihood > curr->data->likelihood){
            break;
        }
        //if not, previous is set to current
        prev = curr;

        //and current is set to the next 
        curr = curr->next;
    }

    //dynamically allocating memory for new
    new = (NodeType*) malloc(sizeof(NodeType));

    //setting the data of new to ghost
    new->data = ghost;

    //checks if previous is null
    if (prev == NULL){

        //if so head is set to new
        list->head = new;
    }
    else{

        //if not current is set to new
        prev->next = new;
    }

    //setting the node next to new to curr
    new->next = curr;

}

/*
Function: cleanupGhostData
 Purpose: Cleans up the ghost list's data
  in/out: GhostListType *list, takes the inputted list and deallocates the data 
*/
void cleanupGhostData(GhostListType* list){

    //creating a tmp node set to the head of the list
    NodeType* tmp = list->head;

    //loop while tmp doesnt equal null
    while (tmp!=NULL){

        //frees the data 
        free(tmp->data);
        
        //sets the tmp to the next node
        tmp = tmp->next;
    }
}
/*
Function: cleanupGhostList
 Purpose: Cleans up the nodes in ghost list
  in/out: GhostListType *list, takes the inputted list and deallocates the nodes 
*/
void cleanupGhostList(GhostListType *list){

    //creating a temporary node
    NodeType* tmp;
    
    //looping through while the head isnt null
    while(list->head!=NULL){

        //setting temp to the head of the list
        tmp = list->head;

        //setting the head to the next node
        list->head = list->head->next;

        //freeing the temporary node
        free(tmp);
    }

}
/*
Function: printGhost
 Purpose: prints out the elements of the ghost
  in/out: takes the ghostType and and prints out the elements stored in ghost
*/
void printGhost(GhostType *ghost){

    //prints the ghost id
    printf("%10d", ghost->id);

    //if the enum is Poltergeist
    if (ghost->ghostType == POLTERGEIST){

        //prints out poltergeist
        printf("%15s", "POLTERGEIST");
    }

    //if the emum is wraith
    else if((ghost->ghostType == WRAITH)){

        //prints out wraith
        printf("%15s", "WRAITH");
    }

    //if the enum is Phanton
    else if (ghost->ghostType == PHANTOM)
    {
        //prints out phantom
        printf("%15s", "PHANTOM");
    }

    //if the enum is Bullies
    else if (ghost->ghostType == BULLIES)
    {
        //prints out bullies
        printf("%15s", "BULLIES");
    }

    //if it is set to anything else
    else{

        //other is printed out
        printf("%15s", "OTHER");
    }
    
    

    //if the room is set to null
    if (ghost->room == NULL){

        //prints unknown instead of id 
        printf("%10s", "Unknown");

        //prints unknwon instead of name
        printf("%20s", "Unknown");
    }

    else{

        //the room id is printed out
        printf("%10d", ghost->room->id);

        //the room name is printed out
        printf("%20s", ghost->room->name);
    }

    //the likelihood is printed out
    printf("%15f\n", ghost->likelihood);
    

}

/*
Function: printGhosts
 Purpose: prints the list of ghosts
      in: int ends, if ends is true, the head and tail are reprinted at the end
  in/out: GhostListType *list, takes the list of ghosts and prints the elements of the list
*/
void printGhosts(GhostListType *list, int ends){

    //creating a current node set to the head of the list
    NodeType* curr = list->head;
    
    //looping until curr is null
    while(curr!= NULL){

        //calling printGhost with the data of the node
        printGhost(curr->data);

        //going to the next node
        curr = curr->next;
    }

    //checking if the ends is true in order to reprint the head and tail
    if (ends == C_TRUE){
        printGhost(list->head->data);
        printGhost(list->tail->data);
    }
    

}
/*
Function: printByLikelihood
 Purpose: prints the list in order of likelihood
      in: int ends, if ends is true, the head and tail are reprinted at the end
  in/out: GhostListType *origList, takes the original list, creates a new list in order of likelihood and prints it out
*/
void printByLikelihood(GhostListType *origList, int ends){

    //creating node current set to the head of the original list
    NodeType* curr = origList->head;

    //creating a temporary GhostListType
    GhostListType tmp;

    //initializing the list
    initGhostList(&tmp);

    //looping while curr isnt null
    while (curr!=NULL){

        //calling addghostbylikelihood with the temp list and the data of the current node
        addGhostByLikelihood(&tmp, curr->data);

        //going to the next node
        curr = curr->next;
    }

    //printing the new list
    printGhosts(&tmp, ends);

    //cleaning up the temporary list
    cleanupGhostList(&tmp);



}
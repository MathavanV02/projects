#include "Rocket.h"

Rocket::Rocket(const string& name): name(name){}

bool Rocket::equals(const string& name){
    if(this->name.compare(name) == 0){
        return true;
    }
    else{
        return false;
    }
}

bool Rocket::needsInspection(const Date& d){
    for(int i =0;i<parts.getSize();i++){
        if(parts[i]->needsInspection(d) == true){
            return true;
        }
    }
    return false;
}

void Rocket::getPartsToInspect(const Date& d, Array<Part*>& toInspect){
    for(int i = 0;i<parts.getSize();i++){
        if(parts[i]->needsInspection(d) == true){
            toInspect+=parts[i];
        }
    }
}

//install
bool Rocket::install(Part* p, const Date& d){
    if(parts.isFull() == true){
        return false;
    }
    p->install(name, d);
    parts+=p;
    return true;
}

bool Rocket::launch(const Date& d){
    if(needsInspection(d) == true){
        return false;
    }
    else{
        for(int i =0;i<parts.getSize();i++){
            parts[i]->launch();
        }
        return true;
    }
}


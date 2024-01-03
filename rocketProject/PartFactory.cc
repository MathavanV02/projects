#include "PartFactory.h"

Part* PartFactory::createPart(string name,const Date& manufacturing, int launchThreshold, int timeThreshold){
    if(launchThreshold == 0){
        Part* newPart = new TT_Part(name, manufacturing, timeThreshold);
        return newPart;
    }

    else if(timeThreshold == 0){
        Part* newPart = new LT_Part(name, manufacturing, launchThreshold);
        return newPart;
    }

    else{
        Part* newPart = new LT_TT_Part(name, manufacturing, launchThreshold, timeThreshold);
        return newPart;
    }
}
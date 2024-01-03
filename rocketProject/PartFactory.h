#ifndef PARTFACTORY_H
#define PARTFACTORY_H

#include "Part.h"

class PartFactory{

    public:
        Part* createPart(string name, const Date& manufacturing, int launchThreshold, int timeThreshold);

};


#endif
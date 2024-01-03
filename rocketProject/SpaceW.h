#ifndef SPACEW_H
#define SPACEW_H

#include "PartFactory.h"
#include "Rocket.h"
#include "Part.h"
class SpaceW{

    public:
        ~SpaceW();
        void addRocket(string name);
        void addPart(string name, const Date& manufacturing, int launchThreshold, int timeThreshold);
        void installPart(string rocketName, string partName, const Date& d);
        void launch(string name, const Date& d);
        void inspect(string name, const Date& d);
        void inspectionReport(const Date& d);
        void printRockets() const;
        void printParts() const;

        Rocket* getRocket(string name);
    private:
        Array<Rocket*> rockets;
        Array<Part*> parts;
        PartFactory partFactory;

};

#endif
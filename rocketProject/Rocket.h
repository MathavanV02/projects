#ifndef ROCKET_H
#define ROCKET_H

#include "Array.h"
#include "Part.h"

class Rocket{
    
    friend ostream& operator<<(ostream& output, Rocket&r){
        output<<"Name:        "<<r.name<<endl;
        return output;
    }
    
    public:
        
        Rocket(const string& name);
        bool equals(const string& name);
        bool needsInspection(const Date&);
        void getPartsToInspect(const Date&, Array<Part*>& toInspect);
        bool install(Part* p, const Date&);
        bool launch(const Date&);
        //void print(ostream& output){output<<"Name:        "<<name<<endl;}
        

    private:
        Array<Part*> parts;
        string name;

};

#endif
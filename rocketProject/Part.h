#ifndef PART_H
#define PART_H

#include "Date.h"

class Part{

    friend ostream& operator<<(ostream& output, Part& p);
    protected:
        string name;
        string rocket;
        Date lastInspected;
        int launches;

    public:
        
        virtual ~Part(){}
        bool equals(const string& name);
        void inspect(const Date &d);
        void launch();
        void install(const string& rocket, const Date &d);
        virtual bool needsInspection(const Date&) = 0;
        virtual void print(ostream& output)const = 0;

};

class LT_Part: public virtual Part{

    public:
        LT_Part(string name, const Date& manufacturing, int launchThreshold);
        virtual bool needsInspection(const Date&);
        virtual void print(ostream& output) const;

    private:
        int launch_threshold;

};

class TT_Part: public virtual Part{

    public:
        TT_Part(string name, const Date& manufacturing, int timeThreshold);
        virtual bool needsInspection(const Date&);
        virtual void print(ostream& output) const;

    private:
        int time_threshold;

};

class LT_TT_Part: public virtual TT_Part, public virtual LT_Part{

    public:
        LT_TT_Part(string name, const Date& manufacturing, int launchThreshold, int timeThreshold):LT_Part(name, manufacturing, launchThreshold), TT_Part(name, manufacturing, timeThreshold){}
        virtual bool needsInspection(const Date&);
        virtual void print(ostream& output) const;


};

#endif
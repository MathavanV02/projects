#include "Part.h"

bool Part::equals(const string& name){
    if(this->name.compare(name) == 0){
        return true;
    }
    else{
        return false;
    }
}

void Part::inspect(const Date& d){
    Date tmp = d;
    lastInspected.setDate(tmp);
    launches = 0;
}

void Part::launch(){
    launches+=1;
}

void Part::install(const string& rocket, const Date& d){
    this->rocket = rocket;
    lastInspected = d;
}

ostream& operator<<(ostream& output, Part& p){
	p.print(output);
    return output;
}

LT_Part::LT_Part(string name, const Date& manufacturing, int launchThreshold){
    this->name = name;
    lastInspected = manufacturing;
    launch_threshold = launchThreshold;
}

bool LT_Part::needsInspection(const Date& d){
    if(launches>=launch_threshold){
        return true;
    }
    else{
        return false;
    }
}

void LT_Part::print(ostream& output) const{
    output<<"Maximum number of launches allowed between inspections is "<< launch_threshold<<" for part "<< name<<"."<<endl;
}

TT_Part::TT_Part(string name, const Date& manufacturing, int timeThreshold){
    this->name = name;
    lastInspected = manufacturing;
    time_threshold = timeThreshold;
}

bool TT_Part::needsInspection(const Date&d){
    Date tmp = lastInspected;
    if(d.toDays()>= tmp.addDays(time_threshold).toDays()){
        return true;
    }
    else{
        return false;
    }
}

void TT_Part::print(ostream& output) const{
    output<<"Maximum number of days between inspections is "<< time_threshold<< " days for Part "<< name<<"."<<endl;
}

bool LT_TT_Part::needsInspection(const Date& d){
    if(TT_Part::needsInspection(d)|| LT_Part::needsInspection(d) == true){
        return true;
    }
    else{
        return false;
    }
}

void LT_TT_Part::print(ostream& output)const{
    LT_Part::print(output);
    TT_Part::print(output);
}
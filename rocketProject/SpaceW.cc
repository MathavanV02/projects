#include "SpaceW.h"

SpaceW::~SpaceW(){

}

void SpaceW::addRocket(string name){
    Rocket* newRocket = new Rocket(name);
    rockets+=newRocket;
    
}

void SpaceW::addPart(string name, const Date& manufacturing, int launchThreshold, int timeThreshold){
    parts+=partFactory.createPart(name, manufacturing, launchThreshold, timeThreshold);
}

void SpaceW::installPart(string rocketName, string partName, const Date& d){

    int rocketFound=0;
    int partFound =0;
    for(int i =0;i<rockets.getSize();i++){
        if(rockets[i]->equals(rocketName)){
            rocketFound+=1;
            for(int j =0;j<parts.getSize();j++){
                if(parts[j]->equals(partName)){
                    rockets[i]->install(parts[j], d);
                    parts.remove(parts[j]);
                    partFound+=1;
                    break;
                }
            }
            break;
            
        }
    }

    if(rocketFound==0){
        cout<<rocketName<<" was not found"<<endl;
    }

    if(partFound==0){
        cout<<partName<<" was not found."<<endl;
    }

    if(rocketFound ==1&& partFound==1){
        cout<<partName<<" has successfully been installed to "<<rocketName<<"."<<endl;
    }

    
}

void SpaceW::launch(string name, const Date& d){

    for(int i =0;i<rockets.getSize();i++){
        if(rockets[i]->equals(name)&& rockets[i]->needsInspection(d) == false){
            rockets[i]->launch(d);
            cout<<name<<" has been launched."<<endl;
        }
    }
}

void SpaceW::inspect(string name, const Date& d){

    if(getRocket(name)!=nullptr){
        Array<Part*> inspection;
        getRocket(name)->getPartsToInspect(d, inspection);

        if(inspection.getSize()>0){
            cout<<"Inspecting "<<name<<"."<<endl;
            for(int i=0;i<inspection.getSize();i++){
                inspection[i]->inspect(d);

            }
        }
        else{
            cout<<name<<" does not need to be inspected"<<endl;
        }

    }
    else{
        cout<<"Rocket with this name was not found."<<endl;
    }



    //for(int i =0;i<rockets.getSize();i++){
    //    if(rockets[i]->equals(name)){
    //        Array<Part*> inspection;
    //        rockets[i]->getPartsToInspect(d, inspection);
    //        if(inspection.getSize()>0){
    //            cout<<"Inspecting "<<name<<"."<<endl;
    //            for(int j=0;j<inspection.getSize();j++){
    //                inspection[i]->inspect(d);

    //            }
    //        }
    //        else{
    //            cout<<name<<" does not need to be inspected"<<endl;
    //    }

    //    }
    //}
}

void SpaceW::inspectionReport(const Date& d){
    cout<<"The following rockets require inspection"<<endl;
    cout<<"--------------------------------------------------------"<<endl;
    for(int i =0;i<rockets.getSize();i++){
        if(rockets[i]->needsInspection(d) == true){
            cout<<*rockets[i]<<endl;
        }
    }
}

void SpaceW::printRockets() const{
    cout<<"LIST OF ROCKETS AT SPACEW"<<endl;
    cout<<"--------------------------------------------------------"<<endl;
    for(int i =0;i<rockets.getSize();i++){
        cout<<*rockets[i]<<endl;
    }
}

void SpaceW::printParts() const{
    cout<<"LIST OF PARTS AT SPACEW"<<endl;
    cout<<"--------------------------------------------------------"<<endl;
    for(int i=0;i<parts.getSize();i++){
        cout<<*(parts[i])<<endl;
    }
}

Rocket* SpaceW::getRocket(string name){
    for(int i=0;i<rockets.getSize();i++){
        if(rockets[i]->equals(name)){
            return rockets[i];
        }
    }
    return nullptr;
}
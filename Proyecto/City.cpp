#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#define N_MAX 1000



int citizensN = 0;



class citizen
{
protected:
    string name;
    string race;
    float heigth;
    string magicalAbility;
    float eyeDepth;
    float distanceBE;
    float distanceFtoN;
    float distanceNandLip;
public:
    citizen(): name(" "), race(" "), heigth(0.0),magicalAbility(" "), eyeDepth(0.0),
                 distanceBE(0.0), distanceFtoN(0.0), distanceNandLip(0.0){};

    citizen(string name, string race, float heigth, string magicalAbility, float eyeDepth, float ditanceBE,
            float ditanceFToN, float distanceNandLip){
        this ->name = name;
        this ->race = race;
        this ->heigth = heigth;
        this ->magicalAbility = magicalAbility;
        this ->eyeDepth = eyeDepth;
        this ->distanceBE = distanceBE;
        this ->distanceFtoN = distanceFtoN;
        this ->distanceNandLip = distanceNandLip;        
    };

    void printCityzen(){
        cout << getName() << endl;
        cout << getRace() << endl;
        cout << getHeigth() << endl;
        cout << getMagicalAbility() << endl;
        cout << getEyeDepth() << endl;
        cout << getDistanceBE() << endl;
        cout << getDistanceFToN() << endl;
        cout << getDistanceNandLip() << endl;
    }


    void setName(string name){
        this ->name = name;
    }
    void setRace(string race){
        this ->race = race;
    }
    void setHeigth(float heigth){
        this ->heigth = heigth;
    }
    void setMagicalAbility(string magicalAbility){
        this ->magicalAbility = magicalAbility;
    }
    void setEyeDepth(float eyeDepth){
        this ->eyeDepth = eyeDepth;
    }
    void setDistanceBE(float dsitanceBE){
        this ->distanceBE = distanceBE;
    }
    void setDistanceFToN(float distanceFToN){
        this ->distanceFtoN = distanceFtoN;
    }
    void setDistanceNandLip(float distanceNandLip){
        this ->distanceNandLip = distanceNandLip; 
    }

    string getName(){
        return name;
    }
    string getRace(){
        return race;
    }
    float getHeigth(){
        return heigth;
    }
    string getMagicalAbility(){
        return magicalAbility;
    }
    float getEyeDepth(){
        return eyeDepth;
    }
    float getDistanceBE(){
        return distanceBE;
    }
    float getDistanceFToN(){
        return distanceFtoN;
    }
    float getDistanceNandLip(){
        return distanceNandLip; 
    }


};





void readBD(citizen citizens[]){
    ifstream dataBase ("dataBase.in");
    if (!dataBase.is_open()){
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }


    dataBase >> citizensN;

    if (citizensN <= 0 || citizensN >= 1000){
        cout << "Valor introducido Erroneo." << endl;
        return;
    }


    string name, race, magicalAbility, line;
    float heigth, eyeDepth, distanceBE, distanceFtoN, distanceNandLip;


    for (int i = 1; i <= citizensN; i++){
        getline(dataBase,line); citizens[i].setName(line);

        dataBase >> race; citizens[i].setRace(race);
        dataBase >> heigth; citizens[i].setHeigth(heigth);
        dataBase >> magicalAbility; citizens[i].setMagicalAbility(magicalAbility);
        dataBase >> eyeDepth; citizens[i].setEyeDepth(eyeDepth);
        dataBase >> distanceBE; citizens[i].setDistanceBE(distanceBE);
        dataBase >> distanceFtoN; citizens[i].setDistanceFToN(distanceFtoN);
        dataBase >> distanceNandLip; citizens[i].setDistanceNandLip(distanceNandLip);   
    }
    
    dataBase.close();
}




int main (){
    citizen citizens[N_MAX];

    readBD(citizens);



    cout << "Ciudadanos Activos." << endl;
    cout << citizensN << endl;



    return 0;

}
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

    citizen(string name, string race, float heigth, string magicalAbility, float eyeDepth, float distanceBE,
            float distanceFtoN, float distanceNandLip){
        this ->name = name;
        this ->race = race;
        this ->heigth = heigth;
        this ->magicalAbility = magicalAbility;
        this ->eyeDepth = eyeDepth;
        this ->distanceBE = distanceBE;
        this ->distanceFtoN = distanceFtoN;
        this ->distanceNandLip = distanceNandLip;        
    };

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
    void setDistanceBE(float distanceBE){
        this ->distanceBE = distanceBE;
    }
    void setDistanceFToN(float distanceFtoN){
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



class city : protected citizen
{
private:
    citizen citizens[N_MAX];
public:
    city(): citizens(){};

    void printCitizens(){
        for (int i = 1; i <= citizensN; i++){
            cout << citizens[i].getName() << endl;
            cout << citizens[i].getRace() << endl;
            cout << citizens[i].getHeigth() << endl;
            cout << citizens[i].getMagicalAbility() << endl;
            cout << citizens[i].getEyeDepth() << endl;
            cout << citizens[i].getDistanceBE() << endl;
            cout << citizens[i].getDistanceFToN() << endl;
            cout << citizens[i].getDistanceNandLip() << endl;
        }
    }
    void printCityzen(int n){

        cout << citizens[n].getName() << endl;
        cout << citizens[n].getRace() << endl;
        cout << citizens[n].getHeigth() << endl;
        cout << citizens[n].getMagicalAbility() << endl;
        cout << citizens[n].getEyeDepth() << endl;
        cout << citizens[n].getDistanceBE() << endl;
        cout << citizens[n].getDistanceFToN() << endl;
        cout << citizens[n].getDistanceNandLip() << endl;

    }

    void readBD(){
    ifstream dataBase ("dataBase.in");
    if (!dataBase.is_open()){
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }


    dataBase >> citizensN;
    dataBase.ignore();

    if (citizensN < 1 || citizensN > 1000){
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
        dataBase.ignore();
    }
    
    dataBase.close();
    }
};



int main (){
    city city;

    city.readBD();
    cout << "Ciudadanos Activos." << endl;
    cout << citizensN << endl;
    city.printCitizens();





    return 0;

}
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#define N_MAX 1000



int citizensN=0 , N = 0;


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

    void printCityzen(){

        cout << name << endl;
        cout << race << endl;
        cout << heigth << endl;
        cout << magicalAbility << endl;
        cout << eyeDepth << endl;
        cout << distanceBE << endl;
        cout << distanceFtoN << endl;
        cout << distanceNandLip << endl;
    }



    
    //Setters
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
    //Getters
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
    citizen supiciusList[N_MAX];
    citizen aux[3];
    int suspiciusNum = 1;
public:
    city(): citizens(){};



    bool compareArcaneTrail(citizen sujetoA, citizen sujetoB){

    }


    void matchArcaneTrail(int li, int depth){
        if (depth == 3){
            for (int i = 0; i < 3; i++){
                aux[i].printCityzen();
            }
            cout << endl;
            return;
        }

        for (int i = li; i <= citizensN; i++){
            aux[depth] = citizens[i]; 
            matchArcaneTrail(i+1,depth+1);
        }
    }

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
    bool addCitizen(string name, string race, float heigth, string magicalAbility, float eyeDepth,
                    float dsitanceBE, float distanceFToN, float distanceNandLip, int num){
                        bool flag=true;

                        if (race != "Humano" && race != "Humana" && race != "Kripsen" && race != "Elfo" && 
                            race != "Enano" && race != "Goliat" && race != "Orco" && 
                            race != "Ubarikiwe" && race != "Hada" && race != "Celcoa" && race != "Drakna'ar"){
                                flag = false;
                            }
                        if (heigth < 1 || heigth > 20){                    
                            flag = false;
                        }
                        if (eyeDepth <0.1 || eyeDepth > 0.5){
                            flag = false;
                        }
                        if (dsitanceBE <0.1 || dsitanceBE >0.5){ 
                            flag = false;
                        }
                        if (distanceFToN < 1 || distanceFToN > 4){ 
                            flag = false;
                        }
                        if (distanceNandLip < 0.1 || distanceNandLip > 0.5){  
                            flag = false;
                        }

                        if (flag){
                            citizens[num].setName(name);
                            citizens[num].setRace(race);
                            citizens[num].setHeigth(heigth);
                            citizens[num].setMagicalAbility(magicalAbility);                            
                            citizens[num].setEyeDepth(eyeDepth);
                            citizens[num].setDistanceBE(dsitanceBE);
                            citizens[num].setDistanceFToN(distanceFToN);
                            citizens[num].setDistanceNandLip(distanceNandLip);
                            return flag;                            
                        }else {
                            return flag;
                        }   
                    }
    void readBD(){

    ifstream dataBase ("dataBase1.in");

    if (!dataBase.is_open()){
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }

    dataBase >> N;
    dataBase.ignore();

    if (N < 1 || N > 1000){
        cout << "Valor introducido Erroneo." << endl;
        return;
    }

    string name, race, magicalAbility, line;
    float heigth, eyeDepth, distanceBE, distanceFtoN, distanceNandLip;

    for (int i = 1, num = 1; i <= N; i++){
        getline(dataBase,line);

        dataBase >> race;
        dataBase >> heigth;
        dataBase >> magicalAbility;
        dataBase >> eyeDepth;
        dataBase >> distanceBE;
        dataBase >> distanceFtoN;
        dataBase >> distanceNandLip; 
        dataBase.ignore();

        if (addCitizen(line,race,heigth,magicalAbility,eyeDepth,distanceBE,distanceFtoN,distanceNandLip,num)){
            num++;
            citizensN++;
        }
    }
    //Revisar Si hay 1 sujeto con numeros falsos como lo maneja el programa...
    
    dataBase.close();
    }
};



int main (){
    city city;

    city.readBD();

    cout << "Ciudadanos Activos." << endl;


    city.matchArcaneTrail(1,0);




    return 0;

}
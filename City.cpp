#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#define N_MAX 1000



int N=0, citizensN=0; 


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

    bool isMagical(){
        return (magicalAbility == "Si");
    }
    bool isKripsan(){
        return (race == "Kripsan");
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
    int suspiciusNum=0;
    bool suspiciusStatus[N_MAX]={false};
    int SkinWalkerNum=0;
    string SkinWalkers[N_MAX];

public:
    city(): citizens(){};

    //SECCION DE MARGEN ERROR
    //Calcula el margen de error de cualquier digito ingresado.

    bool CME(float valor, float medida){
        float margin = 0.05;
        if (valor >= (medida-margin) && valor <= (medida+margin)){
            return true;
        }else{
            return false;
        }
    }
    
    //SECCION DE VERIFICACION DE ALTURAS DE LOS SOSPECHOSO
    // Verificamos si la altura de la siguiente forma aumenta o disminuye 1 unidad de medida o no.

    bool HeightAnalysis (float interval, float height) {
        if (height >= (interval-1.0) && height <= (interval+1.0)) {
            return true;
        } else {
            return false;
        }
    }

    //SECCION DE VERIFICACION DE CAMBIOS DE ESTRUCTURA FACIAL DE LOS SOSPECHOSOS
    // Verificamos si el sospechoso que le pasamos con el siguiente comparten una estructura facial en comun que no cambia

    bool FaceAnalysis (citizen Suspicius1, citizen Suspicius2) {
        if(Suspicius1.getEyeDepth()     == Suspicius2.getEyeDepth()         ||
        Suspicius1.getDistanceBE()      == Suspicius2.getDistanceBE()       ||
        Suspicius1.getDistanceNandLip() == Suspicius2.getDistanceNandLip()  ||
        Suspicius1.getDistanceFToN()    == Suspicius2.getDistanceFToN()) {
            return true;
        }
        return false;
    }

    //SECCION DE VERIFICAR LA LISTA DE SOSPECHOSOS
    //Verifica si un sospechoso ya se encuentra en la lista de sospechosos.

    bool isInSuspiciusList(citizen Suspicius){
        for (int i = 0; i < suspiciusNum; i++){
            if(supiciusList[i].getName() == Suspicius.getName()){
                return true;
            }
        }
        return false;
    }

    bool IsRevised(int index) {
        return(suspiciusStatus[index]);
    }
    // DETECTOR DE SKIN WALKERS, EN PRUEBAS, CASI LISTO
    void SkinWalkersDectector(int Count, int aux, int Skins, int k = 0) {
        
        if (Count == suspiciusNum && SkinWalkerNum != 0) {
            // PARA EFECTO DE LAS PRUEBAS
            for (int i = k; i <= Skins; i++) {
                cout << SkinWalkers[i] << endl;
                cout << "hola" << endl;
            }
            
            k = SkinWalkerNum + Skins;
            
            cout << SkinWalkerNum << endl;
            cout << Skins << endl;
            cout <<"soy aux "<< aux;
            return;
        }

        for (int i = 0; i < suspiciusNum; i++) {
              
            if (!IsRevised(i)) {
                cout << "entre" << endl;
                if (HeightAnalysis(supiciusList[i].getHeigth(),supiciusList[Count].getHeigth()) &&
                FaceAnalysis(supiciusList[i], supiciusList[Count])) {
                    
                    if (aux == 0) {
                        SkinWalkers[SkinWalkerNum++] = supiciusList[i].getName();
                        SkinWalkers[Skins++ + 1] = supiciusList[Count].getName();
                        suspiciusStatus[i] = true;
                        suspiciusStatus[Count] = true;
                        aux = 1;

                    } else {
                        SkinWalkers[Skins++ + 1] = supiciusList[Count].getName();
                        suspiciusStatus[Count] = true;
                    }
                    
                    SkinWalkersDectector(Count + 1, aux, Skins);
                    aux = 0;
                
                } else {
                    
                    SkinWalkersDectector(Count + 1, aux, Skins);
                    aux = 0;
                }

            }
        
        } 

    }


    //SECCION DE SELECCION DEL GRUPO DE SOSPECHOSOS
    //Compara las 3 personas ingresadas en el arreglo auxiliar si coiciden con 3 caracteristicas o mas

    bool compareArcaneTrail(){
        int match =0;
        if (CME(aux[0].getEyeDepth(), aux[1].getEyeDepth()) && CME(aux[1].getEyeDepth(),aux[2].getEyeDepth())){
            match++;
        }
        if (CME(aux[0].getDistanceBE(), aux[1].getDistanceBE()) && CME(aux[1].getDistanceBE(),aux[2].getDistanceBE())){
            match++;
        }
        if (CME(aux[0].getDistanceFToN(), aux[1].getDistanceFToN()) && CME(aux[1].getDistanceFToN(),aux[2].getDistanceFToN())){
            match++;
        }
        if (CME(aux[0].getDistanceNandLip(), aux[1].getDistanceNandLip()) && CME(aux[1].getDistanceNandLip(),aux[2].getDistanceNandLip())){
            match++;
        }
        if (match >= 3){
            return true;
        }else{
            return false;
        }       
    }


    //Recurividad para sacar las diferentes combinaciones entre 3 personas.
    //SECCION DE LA BUSQUEDA DE LOS GRUPOS A ESTUDIAR
    void matchArcaneTrail(int li, int depth){
        if (depth == 3){
            cout << "A:" << aux[0].getName() << " B " << aux[1].getName() << " C " << aux[2].getName() << endl;

            if (compareArcaneTrail()){
                if (!isInSuspiciusList(aux[0])){
                    supiciusList[suspiciusNum++] = aux[0];
                }
                if (!isInSuspiciusList(aux[1])){
                    supiciusList[suspiciusNum++] = aux[1];
                }
                if (!isInSuspiciusList(aux[2])){
                    supiciusList[suspiciusNum++] = aux[2];
                }                
            };
            return;
        }

        for (int i = li; i <= citizensN; i++){

            if(!citizens[i].isMagical() && !citizens[i].isKripsan()){
                aux[depth] = citizens[i]; 
                matchArcaneTrail(i+1,depth+1);
            }
        }
    }


    void printSuspicius(){
        cout << "Sospechosos " << suspiciusNum << endl;
        for (int i = 0; i < suspiciusNum; i++){
            cout << supiciusList[i].getName() << endl;
            cout << supiciusList[i].getRace() << endl;
            cout << supiciusList[i].getHeigth() << endl;
            cout << supiciusList[i].getMagicalAbility() << endl;
            cout << supiciusList[i].getEyeDepth() << endl;
            cout << supiciusList[i].getDistanceBE() << endl;
            cout << supiciusList[i].getDistanceFToN() << endl;
            cout << supiciusList[i].getDistanceNandLip() << endl;
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

    //Añade un ciudadano a la lista asegurandose que cumpla con los valores adecuados.

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

    city.printSuspicius();

    city.SkinWalkersDectector(1, 0, 0);



    return 0;

}
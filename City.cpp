#include <iostream>
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
    citizen(): name (" "), race(" "), heigth(0.0),magicalAbility(" "), eyeDepth(0.0),
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
    citizen AuxSkinWalkers[N_MAX];
    citizen aux[3];
    string ListedSkinWalkers[N_MAX];
    int suspiciusNum=0;;
    int SkinWalkerNum=0;
    int SkinWalkerListed[N_MAX];
    int OriginalForm=0;
    int li=0; //Auxiliar para armar el arreglo
    int auxSkins=0;
    int suspiciusCount[N_MAX];
    int suspiciusCountnum=0;
    bool suspiciusStatus[N_MAX]={false};
    int lastsuspicius=0;

public:
    city(): citizens(){};

    //SECCION DE MARGEN ERROR
    //Calcula el margen de error de cualquier digito ingresado.

    bool CME(float valor, float medida){
        return (valor >= (medida-0.05) && valor <= (medida+0.05));
    }
    
    //SECCION DE VERIFICACION DE ALTURAS DE LOS SOSPECHOSO
    // Verificamos si la altura de la siguiente forma aumenta o disminuye 1 unidad de medida o no.

    bool HeightAnalysis (float interval, float height) {
        return (height >= (interval-1.05) && height <= (interval+1.05));
    }

    //SECCION DE VERIFICACION DE CAMBIOS DE ESTRUCTURA FACIAL DE LOS SOSPECHOSOS
    // Verificamos si el sospechoso que le pasamos con el siguiente comparten una estructura facial en comun que no cambia

    bool FaceAnalysis (citizen Suspicius1, citizen Suspicius2) {
        if(CME(Suspicius1.getEyeDepth(), Suspicius2.getEyeDepth())                ||
           CME(Suspicius1.getDistanceBE(), Suspicius2.getDistanceBE() )           ||
           CME(Suspicius1.getDistanceNandLip(), Suspicius2.getDistanceNandLip())  ||
           CME(Suspicius1.getDistanceFToN(), Suspicius2.getDistanceFToN())
           ) {
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
    
    void swap(citizen &A, citizen &B) {
        citizen auxA = A;
        A = B;
        B = auxA;
        return;
    }
    
    void bubblesort() {
        for (int i = 0; i < suspiciusNum - 1; i++) {
            bool swaped = false;
            for (int j = 0; j < suspiciusNum - 1 - i; j++) {
                if (supiciusList[j].getEyeDepth() > supiciusList[j + 1].getEyeDepth()) {
                    swap (supiciusList[j], supiciusList[j + 1]);
                    swaped = true;
                }
            }
            if (!swaped) return;
        }

    }
    
    void ListedSkinwalkers(citizen AuxSkinWalkers[], int Skins) {

        for (int i = li, k = 0, aux = 0; i < auxSkins; i++, k++, aux = 1) {
            if (aux == 0) {
                ListedSkinWalkers[i] = AuxSkinWalkers[k].getName() + " (O) ";
            } else {
                ListedSkinWalkers[i] = AuxSkinWalkers[k].getName();
            }
        }

        for (int i = li; i < auxSkins; i++) {
            SkinWalkerListed[i] = SkinWalkerNum;
        }
        
        li += Skins;
        return;
        
    }
    
    bool checkProfundity(float suspicius1, float suspicius2) {
        return (suspicius2 > suspicius1);
    }
    

    // DETECTOR DE SKIN WALKERS, EN PRUEBAS, CASI LISTO
    void SkinWalkersDectector(int Count, int aux, int Skins, bool flag) {
        //Se dedica a guardar la solucion en caso de haber encontrado un CambiaForma
        if (Count == suspiciusNum && Skins > 0) {
            SkinWalkerNum++; //Al encontrar uno aumenta el numero de CambiaFormas
            auxSkins += Skins; //Actualiza una variable para la funcion de guardar a los cambiaformas
            suspiciusStatus[lastsuspicius] = true; //Coloca el ultimo sospechoso confirmado como forma como revisado
            // En este if desmarca las casillas de los sospechoso que reviso pero que no marco como que son cambiaformas
            if (suspiciusCountnum > 0) {
                for (int i = 0; i < suspiciusCountnum; i++) {
                    int index = suspiciusCount[i];
                    suspiciusStatus[index] = false;
                    suspiciusCount[i] = 0;
                }
                suspiciusCountnum = 0;
                flag = false;
            }
            OriginalForm=0; //Reseteamos el originalForm para posteriormente comparar nuevas alturas
            ListedSkinwalkers(AuxSkinWalkers, Skins); //Guardamos el cambia formas
            return;
        } 

        //Se dedica a entrar en el caso de no encontrar ningun cambia formas con ese indice y desmarca los 
        //que se revisaron y el indice que no pudo ser usado
        if (Count == suspiciusNum && Skins == 0) {
             if (suspiciusCountnum > 0) {
                for (int i = 0; i < suspiciusCountnum; i++) {
                    int index = suspiciusCount[i];
                    suspiciusStatus[index] = false;
                    suspiciusCount[i] = 0;
                }
                suspiciusCountnum = 0;
                flag = false;
            }      
            for (int i = 0; i < suspiciusNum; i++) {
                if (suspiciusStatus[i] == false) {
                    suspiciusStatus[i] = true;
                    break;
                } 
            }
            OriginalForm=0;
            return;
        }


        for (int i = 0; i < suspiciusNum; i++) {
            //Nos aseguramos que el i nunca sea mayor que el Count
            if (Count < i) {
                return;
            }
            //Nos aseguramos que no se salga de los limites y que no este usado nuestro Count
            if (suspiciusStatus[Count] && Count < (suspiciusNum - 1)) {
                Count++;
            }

            if (!suspiciusStatus[i] && Count > i && !suspiciusStatus[Count]) {
                
                if (aux == 0) {
                   OriginalForm=i;
                }

                if (HeightAnalysis(supiciusList[OriginalForm].getHeigth(),supiciusList[Count].getHeigth()) &&
                    FaceAnalysis(supiciusList[i], supiciusList[Count])                          && 
                    checkProfundity(supiciusList[i].getEyeDepth(), supiciusList[Count].getEyeDepth())
                    ) {
                    
                    if (aux == 0) {
                        AuxSkinWalkers[Skins++] = supiciusList[i];
                        AuxSkinWalkers[Skins++] = supiciusList[Count];
                        suspiciusStatus[i] = true;
                        lastsuspicius = Count;
                        OriginalForm=i;
                        aux = 1;

                    } else {
                        AuxSkinWalkers[Skins++] = supiciusList[Count];
                        suspiciusStatus[i] = true;
                        lastsuspicius = Count;
                    }
                    SkinWalkersDectector(Count + 1, aux, Skins, flag);
                    //El for se encarga de encontrar el nuevo count, el cual siempre sera el segundo
                    //false en el arreglo del estatus de sospechosos
                    int aux2 = 0;
                    for (int j = 0; j < suspiciusNum; j++) {
                        if (suspiciusStatus[j] == false) {
                            aux2++;
                            if (aux2 == 2) {
                                Count = j;
                                break;
                            }
                        }
                    }
                    aux = 0;
                    Skins = 0;

                
                } else {
                    //Lo que hacemos aqui es que en el caso de no encontrar una forma con ese indice
                    //lo marcamos como usado para no repetirlo en las demas iteraciones como un indice valido
                    if (flag == false) {
                        suspiciusCount[suspiciusCountnum++] = Count;
                        suspiciusStatus[Count] = true;
                    } else {
                        suspiciusCount[suspiciusCountnum++] = Count;
                        suspiciusStatus[Count] = true;
                    }
                    SkinWalkersDectector(Count + 1, aux, Skins, true);
                    //El for se encarga de encontrar el nuevo count, el cual siempre sera el segundo
                    //false en el arreglo del estatus de sospechosos
                    int aux2 = 0;
                    for (int j = 0; j < suspiciusNum; j++) {
                        if (suspiciusStatus[j] == false) {
                            aux2++;
                            if (aux2 == 2) {
                                Count = j;
                                break;
                            }
                        }
                    }
                    aux = 0;
                    Skins = 0;

                }

            }

            if (i == (suspiciusNum-1) && Count == (suspiciusNum-1) && suspiciusStatus[Count]) {
                int kaux=0;
                for (int k = 0; k < suspiciusNum; k++) {
                    if (suspiciusStatus[k] == false) {
                        kaux++; 
                    }
                    }
                if (kaux == 1) {
                    SkinWalkersDectector(Count + 1, aux, Skins, flag);
                    return;
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

    ifstream dataBase ("dataBase2.in");

    if (!dataBase.is_open()){
        return;
    }

    dataBase >> N;
    dataBase.ignore();

    if (N < 1 || N > 1000){
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


    void printSkinWalkers() {
        cout << SkinWalkerNum << endl;
        for (int i = 0; i < li; i++) {
            cout << SkinWalkerListed[i] << " - " << ListedSkinWalkers[i] << endl;
        }
    }



/*  void printSuspicius(){
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
*/
     
};



int main (){
    city city;

    city.readBD();

    city.matchArcaneTrail(1,0);

    city.bubblesort();

    city.SkinWalkersDectector(1, 0, 0, false);

    city.printSkinWalkers();

    return 0;

}
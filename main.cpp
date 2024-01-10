#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string pass[200];

int policzCyfry(){
    int licznik = 0;
    for(int i=0; i<200; i++){
        bool isNum = true;
        for(int j=0; j<pass[i].length(); j++){
            int kod = pass[i][j];
            if(!(kod >=48 && kod<=57)){
                isNum=false;
                break;
            }
        }
        if(isNum){
            licznik++;
        }
    }
    return licznik;

}

void wczytajDane(){
    fstream hasla;
    string bufor;
    int i=0;

    hasla.open("C:\\Users\\mstr\\Documents\\mstr\\github zelent\\hasla.txt",ios::in);

    if(!hasla.good()){
        cout<<"cos nie dziala";
    }else{
    while(getline(hasla, bufor)){

        pass[i]=bufor;
        //cout<<i << " " << pass[i] << endl;
        i++;
    }
    hasla.close();
    }
}

string equalPasswd(){ 
    //samo napisane tych pętli było dosyć proste, ale 30minut się męczyłem nad tym warunkiem "bufor == pass[j+i+1]". przez cały czas wszystkie hasła które się powtórzyły wypisały się 2 razy, a reszta raz.
    //zrozumiałem, że muszę dodać index aktualnego hasła + jeszcze jeden index wyżej, aby nie zostało sprawdzone hasło z tego samego indexu.
    string bufor;
    string result = "";
    for(int i = 0; i < 200; i++){
        bufor  = pass[i];
        for(int j = 0; j < 200;){
            if(bufor == pass[j+i+1]){
                result = result + " " + bufor;
                j++;
            }else{
                j++;
            }
        }
    }
    return result;
}

int asciiPasswdCheck(){
    for(int i = 0; i < 200; i++){
        
    }
}


int main()
{
    wczytajDane();
    cout<<"zadanie 1"<<endl;
    cout<<policzCyfry();
    cout<<endl;
    cout<<"zadanie 2"<<endl;
    cout<<equalPasswd();
    cout<<endl;
    cout<<"zadanie 3"<<endl;

    return 0;
}

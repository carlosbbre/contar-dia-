#include <iostream>

using namespace std;

struct Data{
    int dia;
    int mes;
    int ano;
};

bool datasIguais(Data d1, Data d2){
    return d1.dia==d2.dia and d1.mes==d2.mes and d1.ano==d2.ano; 
}

int diasNoMes(Data d1){
    int dias[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if ( ( d1.ano % 4 == 0 && d1.ano % 100 != 0 ) || d1.ano % 400 == 0 ){
        dias[1] = 29;
    }
    return dias[d1.mes-1];
}

int contarDias(Data d1, Data d2){
    int contador = 0;
    while(!datasIguais(d1,d2)){
        contador++;
        d1.dia++;
        if(d1.dia > diasNoMes(d1)){
            d1.dia = 1;
            d1.mes++;
            if(d1.mes > 12){
                d1.mes = 1;
                d1.ano++;
            }
        }
    }
    return contador;
}

int main(){
    Data inicio, final;
    
    inicio.dia = 1;
    inicio.mes = 1;
    inicio.ano = 2025;
    
    final.dia = 1;
    final.mes = 1;
    final.ano = 2026;
    
    int dias = contarDias(inicio,final);
    cout << "A data inicial foi " 
         << inicio.dia << "/" 
         << inicio.mes << "/"
         << inicio.ano << endl;
         
    cout << "Total de dias " << dias << endl;
    
    return 0;
}
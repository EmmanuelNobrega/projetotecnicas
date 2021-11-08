#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iomanip>

using namespace std;

// se for ver no arquivo cada "sensor" tem esse conjunto de informações
//sintetizei eles em uma classe
// isso ainda pode mudar, só coloquei as variaveis mas deve entrar funcoes aqui tbm
class var{
    public:
        float avg, max, min, stddev, count, sum;
    //public:

};

//todas as funcoes carregar sao iguais, so diferem por conta das
//variaveis diferentes de cada sensor
void carregar(var &sensor, stringstream &temp){
    string temp2;
    getline(temp,temp2,',');
    //transforma string em float
    sensor.avg = stof(temp2);
    getline(temp,temp2,',');
    sensor.max = stof(temp2);
    getline(temp,temp2,',');
    sensor.min = stof(temp2);
    getline(temp,temp2,',');
    sensor.stddev = stof(temp2);
    getline(temp,temp2,',');
    sensor.count = stof(temp2);
    return;
}

void carregar(var &sensor, stringstream &temp, int i){
    string temp2;
    getline(temp,temp2,',');
    sensor.avg = stof(temp2);
    getline(temp,temp2,',');
    sensor.stddev = stof(temp2);
    getline(temp,temp2,',');
    sensor.count = stof(temp2);
    return;
}

void carregar(var &sensor, stringstream &temp, float i){
    string temp2;
    getline(temp,temp2,',');
    sensor.count = stof(temp2);
    getline(temp,temp2,',');
    sensor.sum = stof(temp2);
    return;
}

void carregar(var &sensor, stringstream &temp, char i){
    string temp2;
    getline(temp,temp2,',');
    sensor.avg = stof(temp2);
    getline(temp,temp2,',');
    sensor.max = stof(temp2);
    getline(temp,temp2,',');
    sensor.min = stof(temp2);
    getline(temp,temp2,',');
    sensor.stddev = stof(temp2);
    return;
}

void carregar(var &sensor, stringstream &temp, int i, int j){
    string temp2;
    getline(temp,temp2,',');
    sensor.avg = stof(temp2);
    getline(temp,temp2,',');
    sensor.max = stof(temp2);
    getline(temp,temp2,',');
    sensor.min = stof(temp2);
    return;
}



void imprimir_n(var *sensor, tm *datetime, int n){
    cout<<"    Time |    Media |    Max |    Min | Desvio Padrao |  Count"<<endl;
    for(int i=0;i<n;i++){
        cout<<" "<<datetime[i].tm_hour<<":"<<datetime[i].tm_min<<"    | "<<sensor[i].avg<<"   | ";
        cout<<sensor[i].max<<" | "<<sensor[i].min<<" | "<<sensor[i].stddev<<"        | "<<sensor[i].count<<endl;
    }
    cout<<endl;
}

void imprimir_n(var *sensor, tm *datetime, int n, int a){
    cout<<"    Time |    Media | Desvio Padrao |  Count"<<endl;
    for(int i=0;i<n;i++){
        cout<<" "<<datetime[i].tm_hour<<":"<<datetime[i].tm_min<<"    | "<<sensor[i].avg<<"   | ";
        cout<<sensor[i].stddev<<"        | "<<sensor[i].count<<endl;
    }
    cout<<endl;
}

void imprimir_n(var *sensor, tm *datetime, int n, float a){
    cout<<"    Time |  Count |    Sum "<<endl;
    for(int i=0;i<n;i++){
        cout<<" "<<datetime[i].tm_hour<<":"<<datetime[i].tm_min<<"    | "<<sensor[i].count<<"    | "<<sensor[i].sum<<endl;
    }
    cout<<endl;
}

void imprimir_n(var *sensor, tm *datetime, int n, char a){
    cout<<"    Time |    Media |    Max |    Min | Desvio Padrao"<<endl;
    for(int i=0;i<n;i++){
        cout<<" "<<datetime[i].tm_hour<<":"<<datetime[i].tm_min<<"    | "<<sensor[i].avg<<"   | ";
        cout<<sensor[i].max<<" | "<<sensor[i].min<<" | "<<sensor[i].stddev<<endl;
    }
    cout<<endl;
}

void imprimir_n(var *sensor, tm *datetime, int n, int a, int b){
    cout<<"    Time |    Media |    Max |    Min"<<endl;
    for(int i=0;i<n;i++){
        cout<<" "<<datetime[i].tm_hour<<":"<<datetime[i].tm_min<<"    | "<<sensor[i].avg<<"   | ";
        cout<<sensor[i].max<<" | "<<sensor[i].min<<endl;
    }
    cout<<endl;
}

void imprimir_n(var *sensor, tm *datetime, int n, int a, float b){
    cout<<"    Time |    Media "<<endl;
    for(int i=0;i<n;i++){
        cout<<" "<<datetime[i].tm_hour<<":"<<datetime[i].tm_min<<"    | "<<sensor[i].avg<<endl;
    }
    cout<<endl;
}


void imprimir_t(var *sensor, tm *datetime, int i){
    cout<<"Media |    Max |    Min | Desvio Padrao |  Count"<<endl;
    cout<<" "<<sensor[i].avg<<"   | ";
    cout<<sensor[i].max<<" | "<<sensor[i].min<<" | "<<sensor[i].stddev<<"        | "<<sensor[i].count<<endl;
    cout<<endl;
}

void imprimir_t(var *sensor, tm *datetime, int i, int a){
    cout<<"Media | Desvio Padrao |  Count"<<endl;
    cout<<sensor[i].avg<<"   | ";
    cout<<sensor[i].stddev<<"        | "<<sensor[i].count<<endl;
    cout<<endl;
}

void imprimir_t(var *sensor, tm *datetime, int i, float a){
    cout<<"Count |    Sum "<<endl;
    cout<<sensor[i].count<<"    | "<<sensor[i].sum<<endl;
    cout<<endl;
}

void imprimir_t(var *sensor, tm *datetime, int i, char a){
    cout<<"Media |    Max |    Min | Desvio Padrao"<<endl;
    cout<<sensor[i].avg<<"   | ";
    cout<<sensor[i].max<<" | "<<sensor[i].min<<" | "<<sensor[i].stddev<<endl;
    cout<<endl;
}

void imprimir_t(var *sensor, tm *datetime, int i, int a, int b){
    cout<<" Media |    Max |    Min"<<endl;
    cout<<sensor[i].avg<<"   | ";
    cout<<sensor[i].max<<" | "<<sensor[i].min<<endl;
    cout<<endl;
}

void imprimir_t(var *sensor, tm *datetime, int i, int a, float b){
    cout<<"Media "<<endl;
    cout<<sensor[i].avg<<endl;
    cout<<endl;
}

void imprimir_ti_tf(var *sensor, tm *datetime, int i){
    cout<<"Media |    Max |    Min | Desvio Padrao |  Count"<<endl;
    cout<<" "<<sensor[i].avg<<"   | ";
    cout<<sensor[i].max<<" | "<<sensor[i].min<<" | "<<sensor[i].stddev<<"        | "<<sensor[i].count<<endl;
    cout<<endl;
}
void imprimir_ti_tf(var *sensor, tm *datetime, int i, int a){
    cout<<"Media | Desvio Padrao |  Count"<<endl;
    cout<<sensor[i].avg<<"   | ";
    cout<<sensor[i].stddev<<"        | "<<sensor[i].count<<endl;
    cout<<endl;
}

void imprimir_ti_tf(var *sensor, tm *datetime, int i, float a){
    cout<<"Count |    Sum "<<endl;
    cout<<sensor[i].count<<"    | "<<sensor[i].sum<<endl;
    cout<<endl;
}

void imprimir_ti_tf(var *sensor, tm *datetime, int i, char a){
    cout<<"Media |    Max |    Min | Desvio Padrao"<<endl;
    cout<<sensor[i].avg<<"   | ";
    cout<<sensor[i].max<<" | "<<sensor[i].min<<" | "<<sensor[i].stddev<<endl;
    cout<<endl;
}

void imprimir_ti_tf(var *sensor, tm *datetime, int i, int a, int b){
    cout<<" Media |    Max |    Min"<<endl;
    cout<<sensor[i].avg<<"   | ";
    cout<<sensor[i].max<<" | "<<sensor[i].min<<endl;
    cout<<endl;
}

void imprimir_ti_tf(var *sensor, tm *datetime, int i, int a, float b){
    cout<<"Media "<<endl;
    cout<<sensor[i].avg<<endl;
    cout<<endl;
}
//imprimindo variaveis 1 por 1 para a questao 4
void imprimir_individual_1_avg(var *sensor, tm *datetime, int i){
    cout<<"Valor medio "<<i+1<<": ";
    cout<<""<<sensor[i].avg<<"\n";
}
void imprimir_individual_1_max(var *sensor, tm *datetime, int i){
    cout<<"Valor maximo "<<i+1<<": ";
    cout<<""<<sensor[i].max<<"\n";
}
void imprimir_individual_1_min(var *sensor, tm *datetime, int i){
    cout<<"Valor minimo "<<i+1<<": ";
    cout<<""<<sensor[i].min<<"\n";
}
void imprimir_individual_1_stddev(var *sensor, tm *datetime, int i){
    cout<<"Valor StdDev "<<i+1<<": ";
    cout<<""<<sensor[i].stddev<<"\n";
}
void imprimir_individual_1_count(var *sensor, tm *datetime, int i){
    cout<<"Valor Count "<<i+1<<": ";
    cout<<""<<sensor[i].count<<"\n";
}
void imprimir_individual_1_sum(var *sensor, tm *datetime, int i){
    cout<<"Valor sum "<<i+1<<": ";
    cout<<""<<sensor[i].sum<<"\n";
}
//pegando o maior valor da variavel
void imprimir_compmax_individual_2_avg(var *sensor, tm *datetime, int i){
float comparador;
if (i==0){
    comparador = sensor[i].avg;
}
for (int contadorfuncaoavg=0; contadorfuncaoavg<144;contadorfuncaoavg++){
if (comparador<sensor[contadorfuncaoavg].avg){
    comparador = sensor[contadorfuncaoavg].avg;
}
}
    cout<<"Valor maximo dentre os valores medios: ";
    cout<<""<<comparador<<"\n";
}


void imprimir_compmax_individual_2_max(var *sensor, tm *datetime, int i){
float comparador;
if (i==0){
    comparador = sensor[i].max;
}
for (int contadorfuncaomax=0; contadorfuncaomax<144;contadorfuncaomax++){
if (comparador<sensor[contadorfuncaomax].max){
    comparador = sensor[contadorfuncaomax].max;
}
}
    cout<<"Valor maximo dentre os valores maximos: ";
    cout<<""<<comparador<<"\n";
}


void imprimir_compmax_individual_2_min(var *sensor, tm *datetime, int i){
float comparador;
if (i==0){
    comparador = sensor[i].min;
}
for (int contadorfuncaomin=0; contadorfuncaomin<144;contadorfuncaomin++){
if (comparador<sensor[contadorfuncaomin].min){
    comparador = sensor[contadorfuncaomin].min;
}
}
    cout<<"Valor maximo dentre os valores minimos: ";
    cout<<""<<comparador<<"\n";
}


void imprimir_compmax_individual_2_stddev(var *sensor, tm *datetime, int i){
float comparador;
if (i==0){
    comparador = sensor[i].stddev;
}
for (int contadorfuncaostddev=0; contadorfuncaostddev<144;contadorfuncaostddev++){
if (comparador<sensor[contadorfuncaostddev].stddev){
    comparador = sensor[contadorfuncaostddev].stddev;
}
}
    cout<<"Valor maximo dentre os valores medios: ";
    cout<<""<<comparador<<"\n";
}


void imprimir_compmax_individual_2_count(var *sensor, tm *datetime, int i){
float comparador;
if (i==0){
    comparador = sensor[i].count;
}
for (int contadorfuncaocount=0; contadorfuncaocount<144;contadorfuncaocount++){
if (comparador<sensor[contadorfuncaocount].count){
    comparador = sensor[contadorfuncaocount].count;
}
}
    cout<<"Valor maximo dentre os valores count: ";
    cout<<""<<comparador<<"\n";
}


void imprimir_compmax_individual_2_sum(var *sensor, tm *datetime, int i){
float comparador;
if (i==0){
    comparador = sensor[i].sum;
}
for (int contadorfuncaosum=0; contadorfuncaosum<144;contadorfuncaosum++){
if (comparador<sensor[contadorfuncaosum].sum){
    comparador = sensor[contadorfuncaosum].sum;
}
}
    cout<<"Valor maximo dentre os valores sum : ";
    cout<<""<<comparador<<"\n";
}

//pegando o menor valor da variavel
void imprimir_compmin_individual_2_avg(var *sensor, tm *datetime, int i){
float comparador;
if (i==0){
    comparador = sensor[i].avg;
}
for (int contadorfuncaoavg=0; contadorfuncaoavg<144;contadorfuncaoavg++){
if (comparador>sensor[contadorfuncaoavg].avg){
    comparador = sensor[contadorfuncaoavg].avg;
}
}
    cout<<"Valor minimo dentre os valores medios: ";
    cout<<""<<comparador<<"\n";
}


void imprimir_compmin_individual_2_max(var *sensor, tm *datetime, int i){
float comparador;
if (i==0){
    comparador = sensor[i].max;
}
for (int contadorfuncaomax=0; contadorfuncaomax<144;contadorfuncaomax++){
if (comparador>sensor[contadorfuncaomax].max){
    comparador = sensor[contadorfuncaomax].max;
}
}
    cout<<"Valor minimo dentre os valores maximos: ";
    cout<<""<<comparador<<"\n";
}


void imprimir_compmin_individual_2_min(var *sensor, tm *datetime, int i){
float comparador;
if (i==0){
    comparador = sensor[i].min;
}
for (int contadorfuncaomin=0; contadorfuncaomin<144;contadorfuncaomin++){
if (comparador>sensor[contadorfuncaomin].min){
    comparador = sensor[contadorfuncaomin].min;
}
}
    cout<<"Valor minimo dentre os valores minimos: ";
    cout<<""<<comparador<<"\n";
}


void imprimir_compmin_individual_2_stddev(var *sensor, tm *datetime, int i){
float comparador;
if (i==0){
    comparador = sensor[i].stddev;
}
for (int contadorfuncaostddev=0; contadorfuncaostddev<144;contadorfuncaostddev++){
if (comparador>sensor[contadorfuncaostddev].stddev){
    comparador = sensor[contadorfuncaostddev].stddev;
}
}
    cout<<"Valor minimo dentre os valores medios: ";
    cout<<""<<comparador<<"\n";
}


void imprimir_compmin_individual_2_count(var *sensor, tm *datetime, int i){
float comparador;
if (i==0){
    comparador = sensor[i].count;
}
for (int contadorfuncaocount=0; contadorfuncaocount<144;contadorfuncaocount++){
if (comparador>sensor[contadorfuncaocount].count){
    comparador = sensor[contadorfuncaocount].count;
}
}
    cout<<"Valor minimo dentre os valores count: ";
    cout<<""<<comparador<<"\n";
}


void imprimir_compmin_individual_2_sum(var *sensor, tm *datetime, int i){
float comparador;
if (i==0){
    comparador = sensor[i].sum;
}
for (int contadorfuncaosum=0; contadorfuncaosum<144;contadorfuncaosum++){
if (comparador>sensor[contadorfuncaosum].sum){
    comparador = sensor[contadorfuncaosum].sum;
}
}
    cout<<"Valor minimo dentre os valores sum : ";
    cout<<""<<comparador<<"\n";
}
//Funções n v vmax
void imprimir_compmax_individual_3_avg(var *sensor, tm *datetime, int i){
float comparador;
comparador = sensor[0].avg;

for (int contadorfuncao=0; contadorfuncao<i;contadorfuncao++){
if (comparador<sensor[contadorfuncao].avg){
    comparador = sensor[contadorfuncao].avg;
}
}
    cout<<"Valor maximo dentre os valores medios de 1 ate "<<i<<": ";
    cout<<""<<comparador<<"\n";
}
void imprimir_compmax_individual_3_max(var *sensor, tm *datetime, int i){
float comparador;
comparador = sensor[0].max;

for (int contadorfuncao=0; contadorfuncao<i;contadorfuncao++){
if (comparador<sensor[contadorfuncao].max){
    comparador = sensor[contadorfuncao].max;
}
}
    cout<<"Valor maximo dentre os valores maximos de 1 ate "<<i<<": ";
    cout<<""<<comparador<<"\n";
}
void imprimir_compmax_individual_3_min(var *sensor, tm *datetime, int i){
float comparador;
comparador = sensor[0].min;

for (int contadorfuncao=0; contadorfuncao<i;contadorfuncao++){
if (comparador<sensor[contadorfuncao].min){
    comparador = sensor[contadorfuncao].min;
}
}
    cout<<"Valor maximo dentre os valores minimos de 1 ate "<<i<<": ";
    cout<<""<<comparador<<"\n";
}
void imprimir_compmax_individual_3_stddev(var *sensor, tm *datetime, int i){
float comparador;
comparador = sensor[0].stddev;

for (int contadorfuncao=0; contadorfuncao<i;contadorfuncao++){
if (comparador<sensor[contadorfuncao].stddev){
    comparador = sensor[contadorfuncao].stddev;
}
}
    cout<<"Valor maximo dentre os valores medios de 1 ate "<< i <<" : ";
    cout<<""<<comparador<<"\n";
}
void imprimir_compmax_individual_3_count(var *sensor, tm *datetime, int i){
float comparador;
comparador = sensor[0].count;

for (int contadorfuncao=0; contadorfuncao<i;contadorfuncao++){
if (comparador<sensor[contadorfuncao].count){
    comparador = sensor[contadorfuncao].count;
}
}
    cout<<"Valor maximo dentre os valores medios de 1 ate "<< i <<" : ";
    cout<<""<<comparador<<"\n";
}
void imprimir_compmax_individual_3_sum(var *sensor, tm *datetime, int i){
float comparador;
comparador = sensor[0].sum;

for (int contadorfuncao=0; contadorfuncao<i;contadorfuncao++){
if (comparador<sensor[contadorfuncao].sum){
    comparador = sensor[contadorfuncao].sum;
}
}
    cout<<"Valor maximo dentre os valores medios de 1 ate "<< i <<" : ";
    cout<<""<<comparador<<"\n";
}
//funções n v min
void imprimir_compmin_individual_3_avg(var *sensor, tm *datetime, int i){
float comparador;
comparador = sensor[0].avg;

for (int contadorfuncao=0; contadorfuncao<i;contadorfuncao++){
if (comparador>sensor[contadorfuncao].avg){
    comparador = sensor[contadorfuncao].avg;
}
}
    cout<<"Valor minimo dentre os valores medios de 1 ate "<<i<<": ";
    cout<<""<<comparador<<"\n";
}
void imprimir_compmin_individual_3_max(var *sensor, tm *datetime, int i){
float comparador;
comparador = sensor[0].max;

for (int contadorfuncao=0; contadorfuncao<i;contadorfuncao++){
if (comparador>sensor[contadorfuncao].max){
    comparador = sensor[contadorfuncao].max;
}
}
    cout<<"Valor minimo dentre os valores maximos de 1 ate "<<i<<": ";
    cout<<""<<comparador<<"\n";
}
void imprimir_compmin_individual_3_min(var *sensor, tm *datetime, int i){
float comparador;
comparador = sensor[0].min;

for (int contadorfuncao=0; contadorfuncao<i;contadorfuncao++){
if (comparador>sensor[contadorfuncao].min){
    comparador = sensor[contadorfuncao].min;
}
}
    cout<<"Valor minimo dentre os valores minimos de 1 ate "<<i<<": ";
    cout<<""<<comparador<<"\n";
}
void imprimir_compmin_individual_3_stddev(var *sensor, tm *datetime, int i){
float comparador;
comparador = sensor[0].stddev;

for (int contadorfuncao=0; contadorfuncao<i;contadorfuncao++){
if (comparador>sensor[contadorfuncao].stddev){
    comparador = sensor[contadorfuncao].stddev;
}
}
    cout<<"Valor minimo dentre os valores medios de 1 ate "<< i <<" : ";
    cout<<""<<comparador<<"\n";
}
void imprimir_compmin_individual_3_count(var *sensor, tm *datetime, int i){
float comparador;
comparador = sensor[0].count;

for (int contadorfuncao=0; contadorfuncao<i;contadorfuncao++){
if (comparador>sensor[contadorfuncao].count){
    comparador = sensor[contadorfuncao].count;
}
}
    cout<<"Valor minimo dentre os valores medios de 1 ate "<< i <<" : ";
    cout<<""<<comparador<<"\n";
}
void imprimir_compmin_individual_3_sum(var *sensor, tm *datetime, int i){
float comparador;
comparador = sensor[0].sum;

for (int contadorfuncao=0; contadorfuncao<i;contadorfuncao++){
if (comparador>sensor[contadorfuncao].sum){
    comparador = sensor[contadorfuncao].sum;
}
}
    cout<<"Valor minimo dentre os valores medios de 1 ate "<< i <<" : ";
    cout<<""<<comparador<<"\n";
}
// vmax da ti tf
void imprimir_compmax_individual_4_avg(var *sensor, tm *datetime, int i, int j){
float comparador;
comparador = sensor[i].avg;

for (int contadorfuncao=i; contadorfuncao<j;contadorfuncao++){
if (comparador<sensor[contadorfuncao].avg){
    comparador = sensor[contadorfuncao].avg;
}
}
    cout<<"Valor maximo dentre os valores medios de "<<i+1<<" ate "<<j<<": ";
    cout<<""<<comparador<<"\n";
}
void imprimir_compmax_individual_4_max(var *sensor, tm *datetime, int i, int j){
float comparador;
comparador = sensor[i].max;

for (int contadorfuncao=i; contadorfuncao<j;contadorfuncao++){
if (comparador<sensor[contadorfuncao].max){
    comparador = sensor[contadorfuncao].max;
}
}
    cout<<"Valor maximo dentre os valores maximos de "<<i+1<<" ate "<<j<<": ";
    cout<<""<<comparador<<"\n";
}
void imprimir_compmax_individual_4_min(var *sensor, tm *datetime, int i, int j){
float comparador;
comparador = sensor[i].min;

for (int contadorfuncao=i; contadorfuncao<j;contadorfuncao++){
if (comparador<sensor[contadorfuncao].min){
    comparador = sensor[contadorfuncao].min;
}
}
    cout<<"Valor maximo dentre os valores minimos de "<<i+1<<" ate "<<j<<": ";
    cout<<""<<comparador<<"\n";
}
void imprimir_compmax_individual_4_stddev(var *sensor, tm *datetime, int i, int j){
float comparador;
comparador = sensor[i].stddev;

for (int contadorfuncao=i; contadorfuncao<j;contadorfuncao++){
if (comparador<sensor[contadorfuncao].stddev){
    comparador = sensor[contadorfuncao].stddev;
}
}
    cout<<"Valor maximo dentre os valores stddev de "<<i+1<<" ate "<<j<<": ";
    cout<<""<<comparador<<"\n";
}
void imprimir_compmax_individual_4_count(var *sensor, tm *datetime, int i, int j){
float comparador;
comparador = sensor[i].count;

for (int contadorfuncao=i; contadorfuncao<j;contadorfuncao++){
if (comparador<sensor[contadorfuncao].count){
    comparador = sensor[contadorfuncao].count;
}
}
    cout<<"Valor maximo dentre os valores count de "<<i+1<<" ate "<<j<<": ";
    cout<<""<<comparador<<"\n";
}
void imprimir_compmax_individual_4_sum(var *sensor, tm *datetime, int i, int j){
float comparador;
comparador = sensor[i].sum;

for (int contadorfuncao=i; contadorfuncao<j;contadorfuncao++){
if (comparador<sensor[contadorfuncao].sum){
    comparador = sensor[contadorfuncao].sum;
}
}
    cout<<"Valor maximo dentre os valores sum de "<<i+1<<" ate "<<j<<": ";
    cout<<""<<comparador<<"\n";
}
//começo vmin da ti tf

void imprimir_compmin_individual_4_avg(var *sensor, tm *datetime, int i, int j){
float comparador;
comparador = sensor[i].avg;

for (int contadorfuncao=i; contadorfuncao<j;contadorfuncao++){
if (comparador>sensor[contadorfuncao].avg){
    comparador = sensor[contadorfuncao].avg;
}
}
    cout<<"Valor minimo dentre os valores medios de "<<i+1<<" ate "<<j<<": ";
    cout<<""<<comparador<<"\n";
}


void imprimir_compmin_individual_4_max(var *sensor, tm *datetime, int i, int j){
float comparador;
comparador = sensor[i].max;

for (int contadorfuncao=i; contadorfuncao<j;contadorfuncao++){
if (comparador>sensor[contadorfuncao].max){
    comparador = sensor[contadorfuncao].max;
}
}
    cout<<"Valor minimo dentre os valores maximos de "<<i+1<<" ate "<<j<<": ";
    cout<<""<<comparador<<"\n";
}


void imprimir_compmin_individual_4_min(var *sensor, tm *datetime, int i, int j){
float comparador;
comparador = sensor[i].min;

for (int contadorfuncao=i; contadorfuncao<j;contadorfuncao++){
if (comparador>sensor[contadorfuncao].min){
    comparador = sensor[contadorfuncao].min;
}
}
    cout<<"Valor minimo dentre os valores minimos de "<<i+1<<" ate "<<j<<": ";
    cout<<""<<comparador<<"\n";
}


void imprimir_compmin_individual_4_stddev(var *sensor, tm *datetime, int i, int j){
float comparador;
comparador = sensor[i].stddev;

for (int contadorfuncao=i; contadorfuncao<j;contadorfuncao++){
if (comparador>sensor[contadorfuncao].stddev){
    comparador = sensor[contadorfuncao].stddev;
}
}
    cout<<"Valor minimo dentre os valores stddev de "<<i+1<<" ate "<<j<<": ";
    cout<<""<<comparador<<"\n";
}

void imprimir_compmin_individual_4_count(var *sensor, tm *datetime, int i, int j){
float comparador;
comparador = sensor[i].count;

for (int contadorfuncao=i; contadorfuncao<j;contadorfuncao++){
if (comparador>sensor[contadorfuncao].count){
    comparador = sensor[contadorfuncao].count;
}
}
    cout<<"Valor minimo dentre os valores count de "<<i+1<<" ate "<<j<<": ";
    cout<<""<<comparador<<"\n";
}


void imprimir_compmin_individual_4_sum(var *sensor, tm *datetime, int i, int j){
float comparador;
comparador = sensor[i].sum;

for (int contadorfuncao=i; contadorfuncao<j;contadorfuncao++){
if (comparador>sensor[contadorfuncao].sum){
    comparador = sensor[contadorfuncao].sum;
}
}
    cout<<"Valor minimo dentre os valores sum de "<<i+1<<" ate "<<j<<": ";
    cout<<""<<comparador<<"\n";
}



//começo da main

int main(int argc, char *argv[]){

    int n=0, t=0, ti=0,tf=0,v=0, vmax=0,vmin = 0,condicao1questao3=0,condicao2questao3=0;
    struct tm time,time_final,time_inicial;

	char arg1[10]="F", arq_nome[20], arg3[10];

	//esse for identifica as opções do argv e salva em variaveis
    for(int x=1;x<argc; x++){
    if(!strcmp("F",argv[x]))
        strcpy(arq_nome,argv[x+1]);
    if(!strcmp("N",argv[x]))
        n = atoi(argv[x+1]);
    if(!strcmp("t",argv[x])){
        t = 1;
        istringstream ss(argv[x+1]);
        ss>>get_time(&time, "%H:%M:%S");
        }
    if(!strcmp("ti",argv[x])){
        condicao1questao3=1;
        istringstream ss(argv[x+1]);
        ss>>get_time(&time_inicial, "%H:%M:%S");
        }
    if(!strcmp("tf",argv[x])){
        condicao2questao3=1;
        istringstream ss(argv[x+1]);
        ss>>get_time(&time_final, "%H:%M:%S");
        }
    if(!strcmp("V",argv[x]))
        v = atoi(argv[x+1]);
    if(!strcmp("Vmax",argv[x]))
        vmax = 1;
    if(!strcmp("Vmin",argv[x]))
        vmin = 1;
	}
condicao1questao3 = condicao1questao3 && condicao2questao3;
    //ss>>get_time(&tempo, "%H:%M:%S");

//cout<<"teste "<<condicao1questao3<<" funciona?\n"; tava testando se tava saindo 1 quando o usuário digitava ti e tf
    //abrir o arquivo e o if verifica se foi aberto
	ifstream entrada(arq_nome);
	if(!entrada){
		cout << "O arquivo não pode ser aberto" << endl;
		return 1;
	}



    //sensores, sao 144 pois 24h cada hora 6 medicoes
    struct tm datetime[144];
    var Anemoneter[144], Wind_Vane[144], Thermo_Hum[144];
    var Thermo_Temp[144], Barometer[144];
    var DHI[144], GHI[144], DNI[144], Precipitation[144], GTI[144];
    var A1[144], A2[144], A3[144], A4[144], A5[144], A6[144], A7[144];
    var C1[144], C2[144], D1[144], T[144], I[144], V[144];

    string temp,temp2;

    //este primeiro getline é dos nomes da variaveis
    //então esse é só lixo
    getline(entrada,temp);

    int i=0;

    while(i<144){
        getline(entrada,temp);
        //essa linha transforma temp em uma stream pra poder ser usada no getline
        stringstream temp1(temp);
        //getline vai pegar os elementos ate a virgula
        getline(temp1,temp2,',');
        istringstream temp3(temp2);
        //essa é uma struct da biblioteca ctime, essa função pega a stream
        //e transforma pra a struct tm, ela que vai ser usada para fazer
        //as comparações tbm
        temp3>>get_time(&datetime[i], "%Y-%m-%d %H:%M:%S");

        carregar(Anemoneter[i],temp1);
        carregar(Wind_Vane[i],temp1,1);
        carregar(Thermo_Hum[i],temp1);
        carregar(Thermo_Temp[i],temp1);
        carregar(Barometer[i],temp1);
        carregar(DHI[i],temp1);
        carregar(GHI[i],temp1);
        carregar(DNI[i],temp1);
        carregar(Precipitation[i],temp1,(float)3.14);
        carregar(GTI[i],temp1);
        carregar(A1[i],temp1,'c');
        carregar(A2[i],temp1,'c');
        carregar(A3[i],temp1,'c');
        carregar(A4[i],temp1,'c');
        carregar(A5[i],temp1,'c');
        carregar(A6[i],temp1,'c');
        carregar(A7[i],temp1,'c');
        carregar(C1[i],temp1,'c');
        carregar(C2[i],temp1,'c');
        carregar(D1[i],temp1,'c');

        getline(temp1,temp2,',');
        T[i].avg = stof(temp2);

        carregar(I[i],temp1,1,1);
        carregar(V[i],temp1,1,1);
        i++;
    }
//comando N
    if(n!=0 && t==0 && v==0 && condicao1questao3==0 && vmax==0 && vmin==0){
        cout<<"Anemoneter wind speed (m/s)"<<endl;
        imprimir_n(Anemoneter,datetime,n);
        cout<<"Wind Vane TMR wind direction (A)"<<endl;
        imprimir_n(Wind_Vane,datetime,n,1);
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_n(Thermo_Hum,datetime,n);
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_n(Thermo_Temp,datetime,n);
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_n(Barometer,datetime,n);
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_n(DHI,datetime,n);
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_n(GHI,datetime,n);
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_n(DNI,datetime,n);
        cout<<"Precipitation (mm)"<<endl;
        imprimir_n(Precipitation,datetime,n,(float)3.14);
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_n(GTI,datetime,n);
        cout<<"A1 channel (V)"<<endl;
        imprimir_n(A1,datetime,n,'c');
        cout<<"A2 channel (V)"<<endl;
        imprimir_n(A2,datetime,n,'c');
        cout<<"A3 channel (V)"<<endl;
        imprimir_n(A3,datetime,n,'c');
        cout<<"A4 channel (V)"<<endl;
        imprimir_n(A4,datetime,n,'c');
        cout<<"A5 channel (V)"<<endl;
        imprimir_n(A5,datetime,n,'c');
        cout<<"A6 channel (V)"<<endl;
        imprimir_n(A6,datetime,n,'c');
        cout<<"A7 channel (V)"<<endl;
        imprimir_n(A7,datetime,n,'c');
        cout<<"C1 channel (V)"<<endl;
        imprimir_n(C1,datetime,n,'c');
        cout<<"C2 channel (V)"<<endl;
        imprimir_n(C2,datetime,n,'c');
        cout<<"D1 channel (V)"<<endl;
        imprimir_n(D1,datetime,n,'c');
        cout<<"T channel (AC)"<<endl;
        imprimir_n(T,datetime,n,1,(float)3.14);
        cout<<"I channel (mA)"<<endl;
        imprimir_n(I,datetime,n,1,1);
        cout<<"V channel (V)"<<endl;
        imprimir_n(V,datetime,n,1,1);
    }


    int j;
    //comando t
    if(t!=0 && v==0 && n==0 && condicao1questao3==0){
        for(int i=0;i<144;i++){
            if(datetime[i].tm_hour==time.tm_hour && datetime[i].tm_min==time.tm_min){
                j = i;
                break;
            }
        }
        cout<<"Anemoneter wind speed (m/s)"<<endl;
        imprimir_t(Anemoneter,datetime,j);
        cout<<"Wind Vane TMR wind direction (A)"<<endl;
        imprimir_t(Wind_Vane,datetime,j,1);
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_t(Thermo_Hum,datetime,j);
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_t(Thermo_Temp,datetime,j);
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_t(Barometer,datetime,j);
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_t(DHI,datetime,j);
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_t(GHI,datetime,j);
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_t(DNI,datetime,j);
        cout<<"Precipitation (mm)"<<endl;
        imprimir_t(Precipitation,datetime,j,(float)3.14);
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_t(GTI,datetime,j);
        cout<<"A1 channel (V)"<<endl;
        imprimir_t(A1,datetime,j,'c');
        cout<<"A2 channel (V)"<<endl;
        imprimir_t(A2,datetime,j,'c');
        cout<<"A3 channel (V)"<<endl;
        imprimir_t(A3,datetime,j,'c');
        cout<<"A4 channel (V)"<<endl;
        imprimir_t(A4,datetime,j,'c');
        cout<<"A5 channel (V)"<<endl;
        imprimir_t(A5,datetime,j,'c');
        cout<<"A6 channel (V)"<<endl;
        imprimir_t(A6,datetime,j,'c');
        cout<<"A7 channel (V)"<<endl;
        imprimir_t(A7,datetime,j,'c');
        cout<<"C1 channel (V)"<<endl;
        imprimir_t(C1,datetime,j,'c');
        cout<<"C2 channel (V)"<<endl;
        imprimir_t(C2,datetime,j,'c');
        cout<<"D1 channel (V)"<<endl;
        imprimir_t(D1,datetime,j,'c');
        cout<<"T channel (AC)"<<endl;
        imprimir_t(T,datetime,j,1,(float)3.14);
        cout<<"I channel (mA)"<<endl;
        imprimir_t(I,datetime,j,1,1);
        cout<<"V channel (V)"<<endl;
        imprimir_t(V,datetime,j,1,1);
    }


//comando titf
    if(condicao1questao3==1 && v==0 && t==0 && vmax==0 && vmin==0){
        int titf = 0, limitetitf=0;
        for(int contadorti=0;contadorti<144;contadorti++){
            if(datetime[contadorti].tm_hour==time_inicial.tm_hour && datetime[contadorti].tm_min==time_inicial.tm_min){
                titf = contadorti;
                break;
            }
        }
        for(int contadortf=0;contadortf<144;contadortf++){
            if(datetime[contadortf].tm_hour==time_final.tm_hour && datetime[contadortf].tm_min==time_final.tm_min){
                limitetitf = contadortf;
                break;
            }
}

while(titf<limitetitf){
        cout<<"Anemoneter wind speed (m/s)"<<endl;
        imprimir_ti_tf(Anemoneter,datetime,titf);
        cout<<"Wind Vane TMR wind direction (A)"<<endl;
        imprimir_ti_tf(Wind_Vane,datetime,titf,1);
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_ti_tf(Thermo_Hum,datetime,titf);
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_ti_tf(Thermo_Temp,datetime,titf);
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_ti_tf(Barometer,datetime,titf);
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_ti_tf(DHI,datetime,titf);
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_ti_tf(GHI,datetime,titf);
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_ti_tf(DNI,datetime,titf);
        cout<<"Precipitation (mm)"<<endl;
        imprimir_ti_tf(Precipitation,datetime,titf,(float)3.14);
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_ti_tf(GTI,datetime,titf);
        cout<<"A1 channel (V)"<<endl;
        imprimir_ti_tf(A1,datetime,titf,'c');
        cout<<"A2 channel (V)"<<endl;
        imprimir_ti_tf(A2,datetime,titf,'c');
        cout<<"A3 channel (V)"<<endl;
        imprimir_ti_tf(A3,datetime,titf,'c');
        cout<<"A4 channel (V)"<<endl;
        imprimir_ti_tf(A4,datetime,titf,'c');
        cout<<"A5 channel (V)"<<endl;
        imprimir_ti_tf(A5,datetime,titf,'c');
        cout<<"A6 channel (V)"<<endl;
        imprimir_ti_tf(A6,datetime,titf,'c');
        cout<<"A7 channel (V)"<<endl;
        imprimir_ti_tf(A7,datetime,titf,'c');
        cout<<"C1 channel (V)"<<endl;
        imprimir_ti_tf(C1,datetime,titf,'c');
        cout<<"C2 channel (V)"<<endl;
        imprimir_ti_tf(C2,datetime,titf,'c');
        cout<<"D1 channel (V)"<<endl;
        imprimir_ti_tf(D1,datetime,titf,'c');
        cout<<"T channel (AC)"<<endl;
        imprimir_ti_tf(T,datetime,titf,1,(float)3.14);
        cout<<"I channel (mA)"<<endl;
        imprimir_ti_tf(I,datetime,titf,1,1);
        cout<<"V channel (V)"<<endl;
        imprimir_ti_tf(V,datetime,titf,1,1);
titf++;
}
    }

//comando V
    if(v!=0 && vmax==0 && vmin==0 && t==0 && condicao1questao3==0 && n==0){
        for(int contadorquestao4=0; contadorquestao4<144;contadorquestao4++){
        if(v==1){
        cout<<"Anemoneter wind speed average(m/s)"<<endl;
        imprimir_individual_1_avg(Anemoneter,datetime,contadorquestao4);
        }
        if(v==2){
        cout<<"Anemoneter wind speed max(m/s)"<<endl;
        imprimir_individual_1_max(Anemoneter,datetime,contadorquestao4);
        }
        if(v==3){
        cout<<"Anemoneter wind speed min(m/s)"<<endl;
        imprimir_individual_1_min(Anemoneter,datetime,contadorquestao4);
        }
        if(v==4){
        cout<<"Anemoneter wind speed min(m/s)"<<endl;
        imprimir_individual_1_stddev(Anemoneter,datetime,contadorquestao4);
        }
        if(v==5){
        cout<<"Anemoneter wind speed min(m/s)"<<endl;
        imprimir_individual_1_count(Anemoneter,datetime,contadorquestao4);
        }
        
        if(v==6){
        cout<<"Wind Vane TMR wind direction (A)"<<endl;
        imprimir_individual_1_avg(Wind_Vane,datetime,contadorquestao4);
        }
        if(v==7){
        cout<<"Wind Vane TMR wind direction (A)"<<endl;
        imprimir_individual_1_stddev(Wind_Vane,datetime,contadorquestao4);
        }
        if(v==8){
        cout<<"Wind Vane TMR wind direction (A)"<<endl;
        imprimir_individual_1_count(Wind_Vane,datetime,contadorquestao4);
        }
        
        if(v==9){
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_individual_1_avg(Thermo_Hum,datetime,contadorquestao4);
        }
        if(v==10){
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_individual_1_max(Thermo_Hum,datetime,contadorquestao4);
        }
        if(v==11){
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_individual_1_min(Thermo_Hum,datetime,contadorquestao4);
        }
        if(v==12){
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_individual_1_stddev(Thermo_Hum,datetime,contadorquestao4);
        }
        if(v==13){
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_individual_1_count(Thermo_Hum,datetime,contadorquestao4);
        }
        if(v==14){
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_individual_1_avg(Thermo_Temp,datetime,contadorquestao4);
        }
        if(v==15){
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_individual_1_max(Thermo_Temp,datetime,contadorquestao4);
        }
        if(v==16){
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_individual_1_min(Thermo_Temp,datetime,contadorquestao4);
        }
        if(v==17){
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_individual_1_stddev(Thermo_Temp,datetime,contadorquestao4);
        }
        if(v==18){
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_individual_1_count(Thermo_Temp,datetime,contadorquestao4);
        }
        if(v==19){
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_individual_1_avg(Barometer,datetime,contadorquestao4);
        }
        if(v==20){
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_individual_1_max(Barometer,datetime,contadorquestao4);
        }
        if(v==21){
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_individual_1_min(Barometer,datetime,contadorquestao4);
        }
        if(v==22){
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_individual_1_stddev(Barometer,datetime,contadorquestao4);
        }
        if(v==23){
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_individual_1_count(Barometer,datetime,contadorquestao4);
        }

        if(v==24){
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_individual_1_avg(DHI,datetime,contadorquestao4);
        }
        if(v==25){
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_individual_1_max(DHI,datetime,contadorquestao4);
        }if(v==26){
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_individual_1_min(DHI,datetime,contadorquestao4);
        }
        if(v==27){
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_individual_1_stddev(DHI,datetime,contadorquestao4);
        }if(v==28){
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_individual_1_count(DHI,datetime,contadorquestao4);
        }
        //começa dam
     if(v==29){
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_individual_1_avg(GHI,datetime,contadorquestao4);
        }

 if(v==30){
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_individual_1_max(GHI,datetime,contadorquestao4);
        }

 if(v==31){
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_individual_1_min(GHI,datetime,contadorquestao4);
        }

if(v==32){
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_individual_1_stddev(GHI,datetime,contadorquestao4);
        }

if(v==33){
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_individual_1_count(GHI,datetime,contadorquestao4);
        }

if(v==34){
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_individual_1_avg(DNI,datetime,contadorquestao4);
        }
if(v==35){
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_individual_1_max(DNI,datetime,contadorquestao4);
        }

if(v==36){
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_individual_1_min(DNI,datetime,contadorquestao4);
        }

if(v==37){
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_individual_1_stddev(DNI,datetime,contadorquestao4);
        }

if(v==38){
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_individual_1_count(DNI,datetime,contadorquestao4);
        }

if(v==39){
        cout<<"Precipitation (mm)"<<endl;
        imprimir_individual_1_count(Precipitation,datetime,contadorquestao4);
        }

if(v==40){
        cout<<"Precipitation (mm)"<<endl;
        imprimir_individual_1_sum(Precipitation,datetime,contadorquestao4);
        }
if(v==41){
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_individual_1_avg(GTI,datetime,contadorquestao4);
        }

if(v==42){
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_individual_1_max(GTI,datetime,contadorquestao4);
        }

if(v==43){
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_individual_1_min(GTI,datetime,contadorquestao4);
        }

if(v==44){
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_individual_1_stddev(GTI,datetime,contadorquestao4);
        }
if(v==45){
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_individual_1_count(GTI,datetime,contadorquestao4);
        }

        //acaba a parte de dam
        if(v==46){
        cout<<"A1 channel (V)"<<endl;
        imprimir_individual_1_avg(A1,datetime,contadorquestao4);
        }
        if(v==47){
        cout<<"A1 channel (V)"<<endl;
        imprimir_individual_1_max(A1,datetime,contadorquestao4);
        }
        if(v==48){
        cout<<"A1 channel (V)"<<endl;
        imprimir_individual_1_min(A1,datetime,contadorquestao4);
        }
        if(v==49){
        cout<<"A1 channel (V)"<<endl;
        imprimir_individual_1_stddev(A1,datetime,contadorquestao4);
        }
        if(v==50){
        cout<<"A2 channel (V)"<<endl;
        imprimir_individual_1_avg(A2,datetime,contadorquestao4);
        }
        if(v==51){
        cout<<"A2 channel (V)"<<endl;
        imprimir_individual_1_max(A2,datetime,contadorquestao4);
        }
        if(v==52){
        cout<<"A2 channel (V)"<<endl;
        imprimir_individual_1_min(A2,datetime,contadorquestao4);
        }
        if(v==53){
        cout<<"A2 channel (V)"<<endl;
        imprimir_individual_1_stddev(A2,datetime,contadorquestao4);
        }

        if(v==54){
        cout<<"A3 channel (V)"<<endl;
        imprimir_individual_1_avg(A3,datetime,contadorquestao4);
        }
        if(v==55){
        cout<<"A3 channel (V)"<<endl;
        imprimir_individual_1_max(A3,datetime,contadorquestao4);
        }
        if(v==56){
        cout<<"A3 channel (V)"<<endl;
        imprimir_individual_1_min(A3,datetime,contadorquestao4);
        }
        if(v==57){
        cout<<"A3 channel (V)"<<endl;
        imprimir_individual_1_stddev(A3,datetime,contadorquestao4);
        }
        if(v==58){
        cout<<"A4 channel (V)"<<endl;
        imprimir_individual_1_avg(A4,datetime,contadorquestao4);
        }
        if(v==59){
        cout<<"A4 channel (V)"<<endl;
        imprimir_individual_1_max(A4,datetime,contadorquestao4);
        }
        if(v==60){
        cout<<"A4 channel (V)"<<endl;
        imprimir_individual_1_min(A4,datetime,contadorquestao4);
        }
        if(v==61){
        cout<<"A4 channel (V)"<<endl;
        imprimir_individual_1_stddev(A4,datetime,contadorquestao4);
        }
        if(v==62){
        cout<<"A5 channel (V)"<<endl;
        imprimir_individual_1_avg(A5,datetime,contadorquestao4);
        }
        if(v==63){
        cout<<"A5 channel (V)"<<endl;
        imprimir_individual_1_max(A5,datetime,contadorquestao4);
        }
        if(v==64){
        cout<<"A5 channel (V)"<<endl;
        imprimir_individual_1_min(A5,datetime,contadorquestao4);
        }
        if(v==65){
        cout<<"A5 channel (V)"<<endl;
        imprimir_individual_1_stddev(A5,datetime,contadorquestao4);
        }
        if(v==66){
        cout<<"A6 channel (V)"<<endl;
        imprimir_individual_1_avg(A6,datetime,contadorquestao4);
        }
        if(v==67){
        cout<<"A6 channel (V)"<<endl;
        imprimir_individual_1_max(A6,datetime,contadorquestao4);
        }
        if(v==68){
        cout<<"A6 channel (V)"<<endl;
        imprimir_individual_1_min(A6,datetime,contadorquestao4);
        }
        if(v==69){
        cout<<"A6 channel (V)"<<endl;
        imprimir_individual_1_stddev(A6,datetime,contadorquestao4);
        }
        if(v==70){
        cout<<"A7 channel (V)"<<endl;
        imprimir_individual_1_avg(A7,datetime,contadorquestao4);
        }
        if(v==71){
        cout<<"A7 channel (V)"<<endl;
        imprimir_individual_1_max(A7,datetime,contadorquestao4);
        }
        if(v==72){
        cout<<"A7 channel (V)"<<endl;
        imprimir_individual_1_min(A7,datetime,contadorquestao4);
        }
        if(v==73){
        cout<<"A7 channel (V)"<<endl;
        imprimir_individual_1_stddev(A7,datetime,contadorquestao4);
        }//damiao começa
if(v==74){
        cout<<"C1 channel (V)"<<endl;
        imprimir_individual_1_avg(C1,datetime,contadorquestao4);
        }

if(v==75){
        cout<<"C1 channel (V)"<<endl;
        imprimir_individual_1_max(C1,datetime,contadorquestao4);
        }

if(v==76){
        cout<<"C1 channel (V)"<<endl;
        imprimir_individual_1_min(C1,datetime,contadorquestao4);
        }
if(v==77){
        cout<<"C1 channel (V)"<<endl;
        imprimir_individual_1_stddev(C1,datetime,contadorquestao4);
        }

if(v==78){
        cout<<"C2 channel (V)"<<endl;
        imprimir_individual_1_avg(C2,datetime,contadorquestao4);
        }

if(v==79){
        cout<<"C2 channel (V)"<<endl;
        imprimir_individual_1_max(C2,datetime,contadorquestao4);
        }

if(v==80){
        cout<<"C2 channel (V)"<<endl;
        imprimir_individual_1_min(C2,datetime,contadorquestao4);
        }

if(v==81){
        cout<<"C2 channel (V)"<<endl;
        imprimir_individual_1_stddev(C2,datetime,contadorquestao4);
        }

if(v==82){
        cout<<"D1 channel (V)"<<endl;
        imprimir_individual_1_avg(D1,datetime,contadorquestao4);
        }

if(v==83){
        cout<<"D1 channel (V)"<<endl;
        imprimir_individual_1_max(D1,datetime,contadorquestao4);
        }

if(v==84){
        cout<<"D1 channel (V)"<<endl;
        imprimir_individual_1_min(D1,datetime,contadorquestao4);
        }
if(v==85){
        cout<<"D1 channel (V)"<<endl;
        imprimir_individual_1_stddev(D1,datetime,contadorquestao4);
        }

if(v==86){
        cout<<"T channel (AC)"<<endl;
        imprimir_individual_1_avg(T,datetime,contadorquestao4);
        }

if(v==86){
        cout<<"T channel (AC)"<<endl;
        imprimir_individual_1_avg(T,datetime,contadorquestao4);
        }

if(v==87){
        cout<<"I channel (mA)"<<endl;
        imprimir_individual_1_avg(I,datetime,contadorquestao4);
        }

if(v==88){
        cout<<"I channel (mA)"<<endl;
        imprimir_individual_1_max(I,datetime,contadorquestao4);
        }

if(v==89){
        cout<<"I channel (mA)"<<endl;
        imprimir_individual_1_min(I,datetime,contadorquestao4);
        }
        //damiao acaba
        if(v==90){
        cout<<"V channel (V)"<<endl;
        imprimir_individual_1_avg(V,datetime,contadorquestao4);
        }
        if(v==91){
        cout<<"V channel (V)"<<endl;
        imprimir_individual_1_max(V,datetime,contadorquestao4);
        }
        if(v==92){
        cout<<"V channel (V)"<<endl;
        imprimir_individual_1_min(V,datetime,contadorquestao4);
        }

}

}

//fim da chave da questao4
//comecoquestao5


//comando V + Vmax
if(v!=0 && vmax==1 && vmin==0 && n==0 && condicao1questao3==0){
    int contadorquestao5=0;
        if(v==1){
        cout<<"Anemoneter wind speed average(m/s)"<<endl;
        imprimir_compmax_individual_2_avg(Anemoneter,datetime,contadorquestao5);
        }
        if(v==2){
        cout<<"Anemoneter wind speed max(m/s)"<<endl;
        imprimir_compmax_individual_2_max(Anemoneter,datetime,contadorquestao5);
        }
        if(v==3){
        cout<<"Anemoneter wind speed min(m/s)"<<endl;
        imprimir_compmax_individual_2_min(Anemoneter,datetime,contadorquestao5);
        }
        if(v==4){
        cout<<"Anemoneter wind speed min(m/s)"<<endl;
        imprimir_compmax_individual_2_stddev(Anemoneter,datetime,contadorquestao5);
        }
        if(v==5){
        cout<<"Anemoneter wind speed min(m/s)"<<endl;
        imprimir_compmax_individual_2_count(Anemoneter,datetime,contadorquestao5);
        }
        
        if(v==6){
        cout<<"Wind Vane TMR wind direction (A)"<<endl;
        imprimir_compmax_individual_2_avg(Wind_Vane,datetime,contadorquestao5);
        }
        if(v==7){
        cout<<"Wind Vane TMR wind direction (A)"<<endl;
        imprimir_compmax_individual_2_stddev(Wind_Vane,datetime,contadorquestao5);
        }
        if(v==8){
        cout<<"Wind Vane TMR wind direction (A)"<<endl;
        imprimir_compmax_individual_2_count(Wind_Vane,datetime,contadorquestao5);
        }
        
        if(v==9){
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_compmax_individual_2_avg(Thermo_Hum,datetime,contadorquestao5);
        }
        if(v==10){
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_compmax_individual_2_max(Thermo_Hum,datetime,contadorquestao5);
        }
        if(v==11){
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_compmax_individual_2_min(Thermo_Hum,datetime,contadorquestao5);
        }
        if(v==12){
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_compmax_individual_2_stddev(Thermo_Hum,datetime,contadorquestao5);
        }
        if(v==13){
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_compmax_individual_2_count(Thermo_Hum,datetime,contadorquestao5);
        }
        if(v==14){
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_compmax_individual_2_avg(Thermo_Temp,datetime,contadorquestao5);
        }
        if(v==15){
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_compmax_individual_2_max(Thermo_Temp,datetime,contadorquestao5);
        }
        if(v==16){
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_compmax_individual_2_min(Thermo_Temp,datetime,contadorquestao5);
        }
        if(v==17){
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_compmax_individual_2_stddev(Thermo_Temp,datetime,contadorquestao5);
        }
        if(v==18){
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_compmax_individual_2_count(Thermo_Temp,datetime,contadorquestao5);
        }
        if(v==19){
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_compmax_individual_2_avg(Barometer,datetime,contadorquestao5);
        }
        if(v==20){
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_compmax_individual_2_max(Barometer,datetime,contadorquestao5);
        }
        if(v==21){
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_compmax_individual_2_min(Barometer,datetime,contadorquestao5);
        }
        if(v==22){
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_compmax_individual_2_stddev(Barometer,datetime,contadorquestao5);
        }
        if(v==23){
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_compmax_individual_2_count(Barometer,datetime,contadorquestao5);
        }

        if(v==24){
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmax_individual_2_avg(DHI,datetime,contadorquestao5);
        }
        if(v==25){
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmax_individual_2_max(DHI,datetime,contadorquestao5);
        }if(v==26){
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmax_individual_2_min(DHI,datetime,contadorquestao5);
        }
        if(v==27){
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmax_individual_2_stddev(DHI,datetime,contadorquestao5);
        }if(v==28){
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmax_individual_2_count(DHI,datetime,contadorquestao5);
        }
        //começa dam
     if(v==29){
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmax_individual_2_avg(GHI,datetime,contadorquestao5);
        }

 if(v==30){
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmax_individual_2_max(GHI,datetime,contadorquestao5);
        }

 if(v==31){
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmax_individual_2_min(GHI,datetime,contadorquestao5);
        }

if(v==32){
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmax_individual_2_stddev(GHI,datetime,contadorquestao5);
        }

if(v==33){
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmax_individual_2_count(GHI,datetime,contadorquestao5);
        }

if(v==34){
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_compmax_individual_2_avg(DNI,datetime,contadorquestao5);
        }
if(v==35){
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_compmax_individual_2_max(DNI,datetime,contadorquestao5);
        }

if(v==36){
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_compmax_individual_2_min(DNI,datetime,contadorquestao5);
        }

if(v==37){
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_compmax_individual_2_stddev(DNI,datetime,contadorquestao5);
        }

if(v==38){
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_compmax_individual_2_count(DNI,datetime,contadorquestao5);
        }

if(v==39){
        cout<<"Precipitation (mm)"<<endl;
        imprimir_compmax_individual_2_count(Precipitation,datetime,contadorquestao5);
        }

if(v==40){
        cout<<"Precipitation (mm)"<<endl;
        imprimir_compmax_individual_2_sum(Precipitation,datetime,contadorquestao5);
        }
if(v==41){
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_compmax_individual_2_avg(GTI,datetime,contadorquestao5);
        }

if(v==42){
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_compmax_individual_2_max(GTI,datetime,contadorquestao5);
        }

if(v==43){
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_compmax_individual_2_min(GTI,datetime,contadorquestao5);
        }

if(v==44){
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_compmax_individual_2_stddev(GTI,datetime,contadorquestao5);
        }
if(v==45){
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_compmax_individual_2_count(GTI,datetime,contadorquestao5);
        }

        //acaba a parte de dam
        if(v==46){
        cout<<"A1 channel (V)"<<endl;
        imprimir_compmax_individual_2_avg(A1,datetime,contadorquestao5);
        }
        if(v==47){
        cout<<"A1 channel (V)"<<endl;
        imprimir_compmax_individual_2_max(A1,datetime,contadorquestao5);
        }
        if(v==48){
        cout<<"A1 channel (V)"<<endl;
        imprimir_compmax_individual_2_min(A1,datetime,contadorquestao5);
        }
        if(v==49){
        cout<<"A1 channel (V)"<<endl;
        imprimir_compmax_individual_2_stddev(A1,datetime,contadorquestao5);
        }
        if(v==50){
        cout<<"A2 channel (V)"<<endl;
        imprimir_compmax_individual_2_avg(A2,datetime,contadorquestao5);
        }
        if(v==51){
        cout<<"A2 channel (V)"<<endl;
        imprimir_compmax_individual_2_max(A2,datetime,contadorquestao5);
        }
        if(v==52){
        cout<<"A2 channel (V)"<<endl;
        imprimir_compmax_individual_2_min(A2,datetime,contadorquestao5);
        }
        if(v==53){
        cout<<"A2 channel (V)"<<endl;
        imprimir_compmax_individual_2_stddev(A2,datetime,contadorquestao5);
        }

        if(v==54){
        cout<<"A3 channel (V)"<<endl;
        imprimir_compmax_individual_2_avg(A3,datetime,contadorquestao5);
        }
        if(v==55){
        cout<<"A3 channel (V)"<<endl;
        imprimir_compmax_individual_2_max(A3,datetime,contadorquestao5);
        }
        if(v==56){
        cout<<"A3 channel (V)"<<endl;
        imprimir_compmax_individual_2_min(A3,datetime,contadorquestao5);
        }
        if(v==57){
        cout<<"A3 channel (V)"<<endl;
        imprimir_compmax_individual_2_stddev(A3,datetime,contadorquestao5);
        }
        if(v==58){
        cout<<"A4 channel (V)"<<endl;
        imprimir_compmax_individual_2_avg(A4,datetime,contadorquestao5);
        }
        if(v==59){
        cout<<"A4 channel (V)"<<endl;
        imprimir_compmax_individual_2_max(A4,datetime,contadorquestao5);
        }
        if(v==60){
        cout<<"A4 channel (V)"<<endl;
        imprimir_compmax_individual_2_min(A4,datetime,contadorquestao5);
        }
        if(v==61){
        cout<<"A4 channel (V)"<<endl;
        imprimir_compmax_individual_2_stddev(A4,datetime,contadorquestao5);
        }
        if(v==62){
        cout<<"A5 channel (V)"<<endl;
        imprimir_compmax_individual_2_avg(A5,datetime,contadorquestao5);
        }
        if(v==63){
        cout<<"A5 channel (V)"<<endl;
        imprimir_compmax_individual_2_max(A5,datetime,contadorquestao5);
        }
        if(v==64){
        cout<<"A5 channel (V)"<<endl;
        imprimir_compmax_individual_2_min(A5,datetime,contadorquestao5);
        }
        if(v==65){
        cout<<"A5 channel (V)"<<endl;
        imprimir_compmax_individual_2_stddev(A5,datetime,contadorquestao5);
        }
        if(v==66){
        cout<<"A6 channel (V)"<<endl;
        imprimir_compmax_individual_2_avg(A6,datetime,contadorquestao5);
        }
        if(v==67){
        cout<<"A6 channel (V)"<<endl;
        imprimir_compmax_individual_2_max(A6,datetime,contadorquestao5);
        }
        if(v==68){
        cout<<"A6 channel (V)"<<endl;
        imprimir_compmax_individual_2_min(A6,datetime,contadorquestao5);
        }
        if(v==69){
        cout<<"A6 channel (V)"<<endl;
        imprimir_compmax_individual_2_stddev(A6,datetime,contadorquestao5);
        }
        if(v==70){
        cout<<"A7 channel (V)"<<endl;
        imprimir_compmax_individual_2_avg(A7,datetime,contadorquestao5);
        }
        if(v==71){
        cout<<"A7 channel (V)"<<endl;
        imprimir_compmax_individual_2_max(A7,datetime,contadorquestao5);
        }
        if(v==72){
        cout<<"A7 channel (V)"<<endl;
        imprimir_compmax_individual_2_min(A7,datetime,contadorquestao5);
        }
        if(v==73){
        cout<<"A7 channel (V)"<<endl;
        imprimir_compmax_individual_2_stddev(A7,datetime,contadorquestao5);
        }//damiao começa
if(v==74){
        cout<<"C1 channel (V)"<<endl;
        imprimir_compmax_individual_2_avg(C1,datetime,contadorquestao5);
        }

if(v==75){
        cout<<"C1 channel (V)"<<endl;
        imprimir_compmax_individual_2_max(C1,datetime,contadorquestao5);
        }

if(v==76){
        cout<<"C1 channel (V)"<<endl;
        imprimir_compmax_individual_2_min(C1,datetime,contadorquestao5);
        }
if(v==77){
        cout<<"C1 channel (V)"<<endl;
        imprimir_compmax_individual_2_stddev(C1,datetime,contadorquestao5);
        }

if(v==78){
        cout<<"C2 channel (V)"<<endl;
        imprimir_compmax_individual_2_avg(C2,datetime,contadorquestao5);
        }

if(v==79){
        cout<<"C2 channel (V)"<<endl;
        imprimir_compmax_individual_2_max(C2,datetime,contadorquestao5);
        }

if(v==80){
        cout<<"C2 channel (V)"<<endl;
        imprimir_compmax_individual_2_min(C2,datetime,contadorquestao5);
        }

if(v==81){
        cout<<"C2 channel (V)"<<endl;
        imprimir_compmax_individual_2_stddev(C2,datetime,contadorquestao5);
        }

if(v==82){
        cout<<"D1 channel (V)"<<endl;
        imprimir_compmax_individual_2_avg(D1,datetime,contadorquestao5);
        }

if(v==83){
        cout<<"D1 channel (V)"<<endl;
        imprimir_compmax_individual_2_max(D1,datetime,contadorquestao5);
        }

if(v==84){
        cout<<"D1 channel (V)"<<endl;
        imprimir_compmax_individual_2_min(D1,datetime,contadorquestao5);
        }
if(v==85){
        cout<<"D1 channel (V)"<<endl;
        imprimir_compmax_individual_2_stddev(D1,datetime,contadorquestao5);
        }

if(v==86){
        cout<<"T channel (AC)"<<endl;
        imprimir_compmax_individual_2_avg(T,datetime,contadorquestao5);
        }

if(v==86){
        cout<<"T channel (AC)"<<endl;
        imprimir_compmax_individual_2_avg(T,datetime,contadorquestao5);
        }

if(v==87){
        cout<<"I channel (mA)"<<endl;
        imprimir_compmax_individual_2_avg(I,datetime,contadorquestao5);
        }

if(v==88){
        cout<<"I channel (mA)"<<endl;
        imprimir_compmax_individual_2_max(I,datetime,contadorquestao5);
        }

if(v==89){
        cout<<"I channel (mA)"<<endl;
        imprimir_compmax_individual_2_min(I,datetime,contadorquestao5);
        }
        //damiao acaba
        if(v==90){
        cout<<"V channel (V)"<<endl;
        imprimir_compmax_individual_2_avg(V,datetime,contadorquestao5);
        }
        if(v==91){
        cout<<"V channel (V)"<<endl;
        imprimir_compmax_individual_2_max(V,datetime,contadorquestao5);
        }
        if(v==92){
        cout<<"V channel (V)"<<endl;
        imprimir_compmax_individual_2_min(V,datetime,contadorquestao5);
        }



}
//acaba questao 5

//comeca questao 6

//comando V + Vmin
if(v!=0 && vmax==0 && vmin==1 && n==0 && condicao1questao3==0){
int contadorquestao5=0;
        if(v==1){
        cout<<"Anemoneter wind speed average(m/s)"<<endl;
        imprimir_compmin_individual_2_avg(Anemoneter,datetime,contadorquestao5);
        }
        if(v==2){
        cout<<"Anemoneter wind speed max(m/s)"<<endl;
        imprimir_compmin_individual_2_max(Anemoneter,datetime,contadorquestao5);
        }
        if(v==3){
        cout<<"Anemoneter wind speed min(m/s)"<<endl;
        imprimir_individual_1_min(Anemoneter,datetime,contadorquestao5);
        }
        if(v==4){
        cout<<"Anemoneter wind speed min(m/s)"<<endl;
        imprimir_individual_1_stddev(Anemoneter,datetime,contadorquestao5);
        }
        if(v==5){
        cout<<"Anemoneter wind speed min(m/s)"<<endl;
        imprimir_compmin_individual_2_count(Anemoneter,datetime,contadorquestao5);
        }
        
        if(v==6){
        cout<<"Wind Vane TMR wind direction (A)"<<endl;
        imprimir_compmin_individual_2_avg(Wind_Vane,datetime,contadorquestao5);
        }
        if(v==7){
        cout<<"Wind Vane TMR wind direction (A)"<<endl;
        imprimir_compmin_individual_2_stddev(Wind_Vane,datetime,contadorquestao5);
        }
        if(v==8){
        cout<<"Wind Vane TMR wind direction (A)"<<endl;
        imprimir_compmin_individual_2_count(Wind_Vane,datetime,contadorquestao5);
        }
        
        if(v==9){
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_compmin_individual_2_avg(Thermo_Hum,datetime,contadorquestao5);
        }
        if(v==10){
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_compmin_individual_2_max(Thermo_Hum,datetime,contadorquestao5);
        }
        if(v==11){
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_compmin_individual_2_min(Thermo_Hum,datetime,contadorquestao5);
        }
        if(v==12){
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_compmin_individual_2_stddev(Thermo_Hum,datetime,contadorquestao5);
        }
        if(v==13){
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_compmin_individual_2_count(Thermo_Hum,datetime,contadorquestao5);
        }
        if(v==14){
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_compmin_individual_2_avg(Thermo_Temp,datetime,contadorquestao5);
        }
        if(v==15){
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_compmin_individual_2_max(Thermo_Temp,datetime,contadorquestao5);
        }
        if(v==16){
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_compmin_individual_2_min(Thermo_Temp,datetime,contadorquestao5);
        }
        if(v==17){
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_compmin_individual_2_stddev(Thermo_Temp,datetime,contadorquestao5);
        }
        if(v==18){
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_compmin_individual_2_count(Thermo_Temp,datetime,contadorquestao5);
        }
        if(v==19){
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_compmin_individual_2_avg(Barometer,datetime,contadorquestao5);
        }
        if(v==20){
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_compmin_individual_2_max(Barometer,datetime,contadorquestao5);
        }
        if(v==21){
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_compmin_individual_2_min(Barometer,datetime,contadorquestao5);
        }
        if(v==22){
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_compmin_individual_2_stddev(Barometer,datetime,contadorquestao5);
        }
        if(v==23){
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_compmin_individual_2_count(Barometer,datetime,contadorquestao5);
        }

        if(v==24){
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmin_individual_2_avg(DHI,datetime,contadorquestao5);
        }
        if(v==25){
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmin_individual_2_max(DHI,datetime,contadorquestao5);
        }if(v==26){
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmin_individual_2_min(DHI,datetime,contadorquestao5);
        }
        if(v==27){
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmin_individual_2_stddev(DHI,datetime,contadorquestao5);
        }if(v==28){
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmin_individual_2_count(DHI,datetime,contadorquestao5);
        }
        //começa dam
     if(v==29){
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmin_individual_2_avg(GHI,datetime,contadorquestao5);
        }

 if(v==30){
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmin_individual_2_max(GHI,datetime,contadorquestao5);
        }

 if(v==31){
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmin_individual_2_min(GHI,datetime,contadorquestao5);
        }

if(v==32){
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmin_individual_2_stddev(GHI,datetime,contadorquestao5);
        }

if(v==33){
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmin_individual_2_count(GHI,datetime,contadorquestao5);
        }

if(v==34){
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_compmin_individual_2_avg(DNI,datetime,contadorquestao5);
        }
if(v==35){
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_compmin_individual_2_max(DNI,datetime,contadorquestao5);
        }

if(v==36){
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_compmin_individual_2_min(DNI,datetime,contadorquestao5);
        }

if(v==37){
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_compmin_individual_2_stddev(DNI,datetime,contadorquestao5);
        }

if(v==38){
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_compmin_individual_2_count(DNI,datetime,contadorquestao5);
        }

if(v==39){
        cout<<"Precipitation (mm)"<<endl;
        imprimir_compmin_individual_2_count(Precipitation,datetime,contadorquestao5);
        }

if(v==40){
        cout<<"Precipitation (mm)"<<endl;
        imprimir_compmin_individual_2_sum(Precipitation,datetime,contadorquestao5);
        }
if(v==41){
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_compmin_individual_2_avg(GTI,datetime,contadorquestao5);
        }

if(v==42){
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_compmin_individual_2_max(GTI,datetime,contadorquestao5);
        }

if(v==43){
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_compmin_individual_2_min(GTI,datetime,contadorquestao5);
        }

if(v==44){
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_compmin_individual_2_stddev(GTI,datetime,contadorquestao5);
        }
if(v==45){
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_compmin_individual_2_count(GTI,datetime,contadorquestao5);
        }

        //acaba a parte de dam
        if(v==46){
        cout<<"A1 channel (V)"<<endl;
        imprimir_compmin_individual_2_avg(A1,datetime,contadorquestao5);
        }
        if(v==47){
        cout<<"A1 channel (V)"<<endl;
        imprimir_compmin_individual_2_max(A1,datetime,contadorquestao5);
        }
        if(v==48){
        cout<<"A1 channel (V)"<<endl;
        imprimir_compmin_individual_2_min(A1,datetime,contadorquestao5);
        }
        if(v==49){
        cout<<"A1 channel (V)"<<endl;
        imprimir_compmin_individual_2_stddev(A1,datetime,contadorquestao5);
        }
        if(v==50){
        cout<<"A2 channel (V)"<<endl;
        imprimir_compmin_individual_2_avg(A2,datetime,contadorquestao5);
        }
        if(v==51){
        cout<<"A2 channel (V)"<<endl;
        imprimir_compmin_individual_2_max(A2,datetime,contadorquestao5);
        }
        if(v==52){
        cout<<"A2 channel (V)"<<endl;
        imprimir_compmin_individual_2_min(A2,datetime,contadorquestao5);
        }
        if(v==53){
        cout<<"A2 channel (V)"<<endl;
        imprimir_compmin_individual_2_stddev(A2,datetime,contadorquestao5);
        }

        if(v==54){
        cout<<"A3 channel (V)"<<endl;
        imprimir_compmin_individual_2_avg(A3,datetime,contadorquestao5);
        }
        if(v==55){
        cout<<"A3 channel (V)"<<endl;
        imprimir_compmin_individual_2_max(A3,datetime,contadorquestao5);
        }
        if(v==56){
        cout<<"A3 channel (V)"<<endl;
        imprimir_compmin_individual_2_min(A3,datetime,contadorquestao5);
        }
        if(v==57){
        cout<<"A3 channel (V)"<<endl;
        imprimir_compmin_individual_2_stddev(A3,datetime,contadorquestao5);
        }
        if(v==58){
        cout<<"A4 channel (V)"<<endl;
        imprimir_compmin_individual_2_avg(A4,datetime,contadorquestao5);
        }
        if(v==59){
        cout<<"A4 channel (V)"<<endl;
        imprimir_compmin_individual_2_max(A4,datetime,contadorquestao5);
        }
        if(v==60){
        cout<<"A4 channel (V)"<<endl;
        imprimir_compmin_individual_2_min(A4,datetime,contadorquestao5);
        }
        if(v==61){
        cout<<"A4 channel (V)"<<endl;
        imprimir_compmin_individual_2_stddev(A4,datetime,contadorquestao5);
        }
        if(v==62){
        cout<<"A5 channel (V)"<<endl;
        imprimir_compmin_individual_2_avg(A5,datetime,contadorquestao5);
        }
        if(v==63){
        cout<<"A5 channel (V)"<<endl;
        imprimir_compmin_individual_2_max(A5,datetime,contadorquestao5);
        }
        if(v==64){
        cout<<"A5 channel (V)"<<endl;
        imprimir_compmin_individual_2_min(A5,datetime,contadorquestao5);
        }
        if(v==65){
        cout<<"A5 channel (V)"<<endl;
        imprimir_compmin_individual_2_stddev(A5,datetime,contadorquestao5);
        }
        if(v==66){
        cout<<"A6 channel (V)"<<endl;
        imprimir_compmin_individual_2_avg(A6,datetime,contadorquestao5);
        }
        if(v==67){
        cout<<"A6 channel (V)"<<endl;
        imprimir_compmin_individual_2_max(A6,datetime,contadorquestao5);
        }
        if(v==68){
        cout<<"A6 channel (V)"<<endl;
        imprimir_compmin_individual_2_min(A6,datetime,contadorquestao5);
        }
        if(v==69){
        cout<<"A6 channel (V)"<<endl;
        imprimir_compmin_individual_2_stddev(A6,datetime,contadorquestao5);
        }
        if(v==70){
        cout<<"A7 channel (V)"<<endl;
        imprimir_compmin_individual_2_avg(A7,datetime,contadorquestao5);
        }
        if(v==71){
        cout<<"A7 channel (V)"<<endl;
        imprimir_compmin_individual_2_max(A7,datetime,contadorquestao5);
        }
        if(v==72){
        cout<<"A7 channel (V)"<<endl;
        imprimir_compmin_individual_2_min(A7,datetime,contadorquestao5);
        }
        if(v==73){
        cout<<"A7 channel (V)"<<endl;
        imprimir_compmin_individual_2_stddev(A7,datetime,contadorquestao5);
        }//damiao começa
if(v==74){
        cout<<"C1 channel (V)"<<endl;
        imprimir_compmin_individual_2_avg(C1,datetime,contadorquestao5);
        }

if(v==75){
        cout<<"C1 channel (V)"<<endl;
        imprimir_compmin_individual_2_max(C1,datetime,contadorquestao5);
        }

if(v==76){
        cout<<"C1 channel (V)"<<endl;
        imprimir_compmin_individual_2_min(C1,datetime,contadorquestao5);
        }
if(v==77){
        cout<<"C1 channel (V)"<<endl;
        imprimir_compmin_individual_2_stddev(C1,datetime,contadorquestao5);
        }

if(v==78){
        cout<<"C2 channel (V)"<<endl;
        imprimir_compmin_individual_2_avg(C2,datetime,contadorquestao5);
        }

if(v==79){
        cout<<"C2 channel (V)"<<endl;
        imprimir_compmin_individual_2_max(C2,datetime,contadorquestao5);
        }

if(v==80){
        cout<<"C2 channel (V)"<<endl;
        imprimir_compmin_individual_2_min(C2,datetime,contadorquestao5);
        }

if(v==81){
        cout<<"C2 channel (V)"<<endl;
        imprimir_compmin_individual_2_stddev(C2,datetime,contadorquestao5);
        }

if(v==82){
        cout<<"D1 channel (V)"<<endl;
        imprimir_compmin_individual_2_avg(D1,datetime,contadorquestao5);
        }

if(v==83){
        cout<<"D1 channel (V)"<<endl;
        imprimir_compmin_individual_2_max(D1,datetime,contadorquestao5);
        }

if(v==84){
        cout<<"D1 channel (V)"<<endl;
        imprimir_compmin_individual_2_min(D1,datetime,contadorquestao5);
        }
if(v==85){
        cout<<"D1 channel (V)"<<endl;
        imprimir_compmin_individual_2_stddev(D1,datetime,contadorquestao5);
        }

if(v==86){
        cout<<"T channel (AC)"<<endl;
        imprimir_compmin_individual_2_avg(T,datetime,contadorquestao5);
        }

if(v==86){
        cout<<"T channel (AC)"<<endl;
        imprimir_compmin_individual_2_avg(T,datetime,contadorquestao5);
        }

if(v==87){
        cout<<"I channel (mA)"<<endl;
        imprimir_compmin_individual_2_avg(I,datetime,contadorquestao5);
        }

if(v==88){
        cout<<"I channel (mA)"<<endl;
        imprimir_compmin_individual_2_max(I,datetime,contadorquestao5);
        }

if(v==89){
        cout<<"I channel (mA)"<<endl;
        imprimir_compmin_individual_2_min(I,datetime,contadorquestao5);
        }
        //damiao acaba
        if(v==90){
        cout<<"V channel (V)"<<endl;
        imprimir_compmin_individual_2_avg(V,datetime,contadorquestao5);
        }
        if(v==91){
        cout<<"V channel (V)"<<endl;
        imprimir_compmin_individual_2_max(V,datetime,contadorquestao5);
        }
        if(v==92){
        cout<<"V channel (V)"<<endl;
        imprimir_compmin_individual_2_min(V,datetime,contadorquestao5);
        }



}
//acaba questao 6
//começa mashup questao 7
 
 //comando V + Vmax + Vmin
if(v!=0 && vmax==1 && vmin==1 && n==0 && condicao1questao3==0){
int contadorquestao5=0;
        if(v==1){
        cout<<"Anemoneter wind speed average(m/s)"<<endl;
        imprimir_compmin_individual_2_avg(Anemoneter,datetime,contadorquestao5);
        }
        if(v==2){
        cout<<"Anemoneter wind speed max(m/s)"<<endl;
        imprimir_compmin_individual_2_max(Anemoneter,datetime,contadorquestao5);
        }
        if(v==3){
        cout<<"Anemoneter wind speed min(m/s)"<<endl;
        imprimir_individual_1_min(Anemoneter,datetime,contadorquestao5);
        }
        if(v==4){
        cout<<"Anemoneter wind speed min(m/s)"<<endl;
        imprimir_individual_1_stddev(Anemoneter,datetime,contadorquestao5);
        }
        if(v==5){
        cout<<"Anemoneter wind speed min(m/s)"<<endl;
        imprimir_compmin_individual_2_count(Anemoneter,datetime,contadorquestao5);
        }
        
        if(v==6){
        cout<<"Wind Vane TMR wind direction (A)"<<endl;
        imprimir_compmin_individual_2_avg(Wind_Vane,datetime,contadorquestao5);
        }
        if(v==7){
        cout<<"Wind Vane TMR wind direction (A)"<<endl;
        imprimir_compmin_individual_2_stddev(Wind_Vane,datetime,contadorquestao5);
        }
        if(v==8){
        cout<<"Wind Vane TMR wind direction (A)"<<endl;
        imprimir_compmin_individual_2_count(Wind_Vane,datetime,contadorquestao5);
        }
        
        if(v==9){
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_compmin_individual_2_avg(Thermo_Hum,datetime,contadorquestao5);
        }
        if(v==10){
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_compmin_individual_2_max(Thermo_Hum,datetime,contadorquestao5);
        }
        if(v==11){
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_compmin_individual_2_min(Thermo_Hum,datetime,contadorquestao5);
        }
        if(v==12){
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_compmin_individual_2_stddev(Thermo_Hum,datetime,contadorquestao5);
        }
        if(v==13){
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_compmin_individual_2_count(Thermo_Hum,datetime,contadorquestao5);
        }
        if(v==14){
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_compmin_individual_2_avg(Thermo_Temp,datetime,contadorquestao5);
        }
        if(v==15){
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_compmin_individual_2_max(Thermo_Temp,datetime,contadorquestao5);
        }
        if(v==16){
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_compmin_individual_2_min(Thermo_Temp,datetime,contadorquestao5);
        }
        if(v==17){
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_compmin_individual_2_stddev(Thermo_Temp,datetime,contadorquestao5);
        }
        if(v==18){
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_compmin_individual_2_count(Thermo_Temp,datetime,contadorquestao5);
        }
        if(v==19){
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_compmin_individual_2_avg(Barometer,datetime,contadorquestao5);
        }
        if(v==20){
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_compmin_individual_2_max(Barometer,datetime,contadorquestao5);
        }
        if(v==21){
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_compmin_individual_2_min(Barometer,datetime,contadorquestao5);
        }
        if(v==22){
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_compmin_individual_2_stddev(Barometer,datetime,contadorquestao5);
        }
        if(v==23){
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_compmin_individual_2_count(Barometer,datetime,contadorquestao5);
        }

        if(v==24){
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmin_individual_2_avg(DHI,datetime,contadorquestao5);
        }
        if(v==25){
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmin_individual_2_max(DHI,datetime,contadorquestao5);
        }if(v==26){
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmin_individual_2_min(DHI,datetime,contadorquestao5);
        }
        if(v==27){
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmin_individual_2_stddev(DHI,datetime,contadorquestao5);
        }if(v==28){
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmin_individual_2_count(DHI,datetime,contadorquestao5);
        }
        //começa dam
     if(v==29){
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmin_individual_2_avg(GHI,datetime,contadorquestao5);
        }

 if(v==30){
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmin_individual_2_max(GHI,datetime,contadorquestao5);
        }

 if(v==31){
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmin_individual_2_min(GHI,datetime,contadorquestao5);
        }

if(v==32){
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmin_individual_2_stddev(GHI,datetime,contadorquestao5);
        }

if(v==33){
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmin_individual_2_count(GHI,datetime,contadorquestao5);
        }

if(v==34){
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_compmin_individual_2_avg(DNI,datetime,contadorquestao5);
        }
if(v==35){
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_compmin_individual_2_max(DNI,datetime,contadorquestao5);
        }

if(v==36){
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_compmin_individual_2_min(DNI,datetime,contadorquestao5);
        }

if(v==37){
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_compmin_individual_2_stddev(DNI,datetime,contadorquestao5);
        }

if(v==38){
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_compmin_individual_2_count(DNI,datetime,contadorquestao5);
        }

if(v==39){
        cout<<"Precipitation (mm)"<<endl;
        imprimir_compmin_individual_2_count(Precipitation,datetime,contadorquestao5);
        }

if(v==40){
        cout<<"Precipitation (mm)"<<endl;
        imprimir_compmin_individual_2_sum(Precipitation,datetime,contadorquestao5);
        }
if(v==41){
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_compmin_individual_2_avg(GTI,datetime,contadorquestao5);
        }

if(v==42){
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_compmin_individual_2_max(GTI,datetime,contadorquestao5);
        }

if(v==43){
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_compmin_individual_2_min(GTI,datetime,contadorquestao5);
        }

if(v==44){
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_compmin_individual_2_stddev(GTI,datetime,contadorquestao5);
        }
if(v==45){
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_compmin_individual_2_count(GTI,datetime,contadorquestao5);
        }

        //acaba a parte de dam
        if(v==46){
        cout<<"A1 channel (V)"<<endl;
        imprimir_compmin_individual_2_avg(A1,datetime,contadorquestao5);
        }
        if(v==47){
        cout<<"A1 channel (V)"<<endl;
        imprimir_compmin_individual_2_max(A1,datetime,contadorquestao5);
        }
        if(v==48){
        cout<<"A1 channel (V)"<<endl;
        imprimir_compmin_individual_2_min(A1,datetime,contadorquestao5);
        }
        if(v==49){
        cout<<"A1 channel (V)"<<endl;
        imprimir_compmin_individual_2_stddev(A1,datetime,contadorquestao5);
        }
        if(v==50){
        cout<<"A2 channel (V)"<<endl;
        imprimir_compmin_individual_2_avg(A2,datetime,contadorquestao5);
        }
        if(v==51){
        cout<<"A2 channel (V)"<<endl;
        imprimir_compmin_individual_2_max(A2,datetime,contadorquestao5);
        }
        if(v==52){
        cout<<"A2 channel (V)"<<endl;
        imprimir_compmin_individual_2_min(A2,datetime,contadorquestao5);
        }
        if(v==53){
        cout<<"A2 channel (V)"<<endl;
        imprimir_compmin_individual_2_stddev(A2,datetime,contadorquestao5);
        }

        if(v==54){
        cout<<"A3 channel (V)"<<endl;
        imprimir_compmin_individual_2_avg(A3,datetime,contadorquestao5);
        }
        if(v==55){
        cout<<"A3 channel (V)"<<endl;
        imprimir_compmin_individual_2_max(A3,datetime,contadorquestao5);
        }
        if(v==56){
        cout<<"A3 channel (V)"<<endl;
        imprimir_compmin_individual_2_min(A3,datetime,contadorquestao5);
        }
        if(v==57){
        cout<<"A3 channel (V)"<<endl;
        imprimir_compmin_individual_2_stddev(A3,datetime,contadorquestao5);
        }
        if(v==58){
        cout<<"A4 channel (V)"<<endl;
        imprimir_compmin_individual_2_avg(A4,datetime,contadorquestao5);
        }
        if(v==59){
        cout<<"A4 channel (V)"<<endl;
        imprimir_compmin_individual_2_max(A4,datetime,contadorquestao5);
        }
        if(v==60){
        cout<<"A4 channel (V)"<<endl;
        imprimir_compmin_individual_2_min(A4,datetime,contadorquestao5);
        }
        if(v==61){
        cout<<"A4 channel (V)"<<endl;
        imprimir_compmin_individual_2_stddev(A4,datetime,contadorquestao5);
        }
        if(v==62){
        cout<<"A5 channel (V)"<<endl;
        imprimir_compmin_individual_2_avg(A5,datetime,contadorquestao5);
        }
        if(v==63){
        cout<<"A5 channel (V)"<<endl;
        imprimir_compmin_individual_2_max(A5,datetime,contadorquestao5);
        }
        if(v==64){
        cout<<"A5 channel (V)"<<endl;
        imprimir_compmin_individual_2_min(A5,datetime,contadorquestao5);
        }
        if(v==65){
        cout<<"A5 channel (V)"<<endl;
        imprimir_compmin_individual_2_stddev(A5,datetime,contadorquestao5);
        }
        if(v==66){
        cout<<"A6 channel (V)"<<endl;
        imprimir_compmin_individual_2_avg(A6,datetime,contadorquestao5);
        }
        if(v==67){
        cout<<"A6 channel (V)"<<endl;
        imprimir_compmin_individual_2_max(A6,datetime,contadorquestao5);
        }
        if(v==68){
        cout<<"A6 channel (V)"<<endl;
        imprimir_compmin_individual_2_min(A6,datetime,contadorquestao5);
        }
        if(v==69){
        cout<<"A6 channel (V)"<<endl;
        imprimir_compmin_individual_2_stddev(A6,datetime,contadorquestao5);
        }
        if(v==70){
        cout<<"A7 channel (V)"<<endl;
        imprimir_compmin_individual_2_avg(A7,datetime,contadorquestao5);
        }
        if(v==71){
        cout<<"A7 channel (V)"<<endl;
        imprimir_compmin_individual_2_max(A7,datetime,contadorquestao5);
        }
        if(v==72){
        cout<<"A7 channel (V)"<<endl;
        imprimir_compmin_individual_2_min(A7,datetime,contadorquestao5);
        }
        if(v==73){
        cout<<"A7 channel (V)"<<endl;
        imprimir_compmin_individual_2_stddev(A7,datetime,contadorquestao5);
        }//damiao começa
if(v==74){
        cout<<"C1 channel (V)"<<endl;
        imprimir_compmin_individual_2_avg(C1,datetime,contadorquestao5);
        }

if(v==75){
        cout<<"C1 channel (V)"<<endl;
        imprimir_compmin_individual_2_max(C1,datetime,contadorquestao5);
        }

if(v==76){
        cout<<"C1 channel (V)"<<endl;
        imprimir_compmin_individual_2_min(C1,datetime,contadorquestao5);
        }
if(v==77){
        cout<<"C1 channel (V)"<<endl;
        imprimir_compmin_individual_2_stddev(C1,datetime,contadorquestao5);
        }

if(v==78){
        cout<<"C2 channel (V)"<<endl;
        imprimir_compmin_individual_2_avg(C2,datetime,contadorquestao5);
        }

if(v==79){
        cout<<"C2 channel (V)"<<endl;
        imprimir_compmin_individual_2_max(C2,datetime,contadorquestao5);
        }

if(v==80){
        cout<<"C2 channel (V)"<<endl;
        imprimir_compmin_individual_2_min(C2,datetime,contadorquestao5);
        }

if(v==81){
        cout<<"C2 channel (V)"<<endl;
        imprimir_compmin_individual_2_stddev(C2,datetime,contadorquestao5);
        }

if(v==82){
        cout<<"D1 channel (V)"<<endl;
        imprimir_compmin_individual_2_avg(D1,datetime,contadorquestao5);
        }

if(v==83){
        cout<<"D1 channel (V)"<<endl;
        imprimir_compmin_individual_2_max(D1,datetime,contadorquestao5);
        }

if(v==84){
        cout<<"D1 channel (V)"<<endl;
        imprimir_compmin_individual_2_min(D1,datetime,contadorquestao5);
        }
if(v==85){
        cout<<"D1 channel (V)"<<endl;
        imprimir_compmin_individual_2_stddev(D1,datetime,contadorquestao5);
        }

if(v==86){
        cout<<"T channel (AC)"<<endl;
        imprimir_compmin_individual_2_avg(T,datetime,contadorquestao5);
        }

if(v==86){
        cout<<"T channel (AC)"<<endl;
        imprimir_compmin_individual_2_avg(T,datetime,contadorquestao5);
        }

if(v==87){
        cout<<"I channel (mA)"<<endl;
        imprimir_compmin_individual_2_avg(I,datetime,contadorquestao5);
        }

if(v==88){
        cout<<"I channel (mA)"<<endl;
        imprimir_compmin_individual_2_max(I,datetime,contadorquestao5);
        }

if(v==89){
        cout<<"I channel (mA)"<<endl;
        imprimir_compmin_individual_2_min(I,datetime,contadorquestao5);
        }
        //damiao acaba
        if(v==90){
        cout<<"V channel (V)"<<endl;
        imprimir_compmin_individual_2_avg(V,datetime,contadorquestao5);
        }
        if(v==91){
        cout<<"V channel (V)"<<endl;
        imprimir_compmin_individual_2_max(V,datetime,contadorquestao5);
        }
        if(v==92){
        cout<<"V channel (V)"<<endl;
        imprimir_compmin_individual_2_min(V,datetime,contadorquestao5);
        }

        if(v==1){
        cout<<"Anemoneter wind speed average(m/s)"<<endl;
        imprimir_compmax_individual_2_avg(Anemoneter,datetime,contadorquestao5);
        }
        if(v==2){
        cout<<"Anemoneter wind speed max(m/s)"<<endl;
        imprimir_compmax_individual_2_max(Anemoneter,datetime,contadorquestao5);
        }
        if(v==3){
        cout<<"Anemoneter wind speed min(m/s)"<<endl;
        imprimir_compmax_individual_2_min(Anemoneter,datetime,contadorquestao5);
        }
        if(v==4){
        cout<<"Anemoneter wind speed min(m/s)"<<endl;
        imprimir_compmax_individual_2_stddev(Anemoneter,datetime,contadorquestao5);
        }
        if(v==5){
        cout<<"Anemoneter wind speed min(m/s)"<<endl;
        imprimir_compmax_individual_2_count(Anemoneter,datetime,contadorquestao5);
        }
        
        if(v==6){
        cout<<"Wind Vane TMR wind direction (A)"<<endl;
        imprimir_compmax_individual_2_avg(Wind_Vane,datetime,contadorquestao5);
        }
        if(v==7){
        cout<<"Wind Vane TMR wind direction (A)"<<endl;
        imprimir_compmax_individual_2_stddev(Wind_Vane,datetime,contadorquestao5);
        }
        if(v==8){
        cout<<"Wind Vane TMR wind direction (A)"<<endl;
        imprimir_compmax_individual_2_count(Wind_Vane,datetime,contadorquestao5);
        }
        
        if(v==9){
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_compmax_individual_2_avg(Thermo_Hum,datetime,contadorquestao5);
        }
        if(v==10){
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_compmax_individual_2_max(Thermo_Hum,datetime,contadorquestao5);
        }
        if(v==11){
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_compmax_individual_2_min(Thermo_Hum,datetime,contadorquestao5);
        }
        if(v==12){
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_compmax_individual_2_stddev(Thermo_Hum,datetime,contadorquestao5);
        }
        if(v==13){
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_compmax_individual_2_count(Thermo_Hum,datetime,contadorquestao5);
        }
        if(v==14){
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_compmax_individual_2_avg(Thermo_Temp,datetime,contadorquestao5);
        }
        if(v==15){
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_compmax_individual_2_max(Thermo_Temp,datetime,contadorquestao5);
        }
        if(v==16){
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_compmax_individual_2_min(Thermo_Temp,datetime,contadorquestao5);
        }
        if(v==17){
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_compmax_individual_2_stddev(Thermo_Temp,datetime,contadorquestao5);
        }
        if(v==18){
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_compmax_individual_2_count(Thermo_Temp,datetime,contadorquestao5);
        }
        if(v==19){
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_compmax_individual_2_avg(Barometer,datetime,contadorquestao5);
        }
        if(v==20){
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_compmax_individual_2_max(Barometer,datetime,contadorquestao5);
        }
        if(v==21){
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_compmax_individual_2_min(Barometer,datetime,contadorquestao5);
        }
        if(v==22){
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_compmax_individual_2_stddev(Barometer,datetime,contadorquestao5);
        }
        if(v==23){
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_compmax_individual_2_count(Barometer,datetime,contadorquestao5);
        }

        if(v==24){
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmax_individual_2_avg(DHI,datetime,contadorquestao5);
        }
        if(v==25){
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmax_individual_2_max(DHI,datetime,contadorquestao5);
        }if(v==26){
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmax_individual_2_min(DHI,datetime,contadorquestao5);
        }
        if(v==27){
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmax_individual_2_stddev(DHI,datetime,contadorquestao5);
        }if(v==28){
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmax_individual_2_count(DHI,datetime,contadorquestao5);
        }
        //começa dam
     if(v==29){
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmax_individual_2_avg(GHI,datetime,contadorquestao5);
        }

 if(v==30){
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmax_individual_2_max(GHI,datetime,contadorquestao5);
        }

 if(v==31){
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmax_individual_2_min(GHI,datetime,contadorquestao5);
        }

if(v==32){
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmax_individual_2_stddev(GHI,datetime,contadorquestao5);
        }

if(v==33){
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmax_individual_2_count(GHI,datetime,contadorquestao5);
        }

if(v==34){
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_compmax_individual_2_avg(DNI,datetime,contadorquestao5);
        }
if(v==35){
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_compmax_individual_2_max(DNI,datetime,contadorquestao5);
        }

if(v==36){
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_compmax_individual_2_min(DNI,datetime,contadorquestao5);
        }

if(v==37){
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_compmax_individual_2_stddev(DNI,datetime,contadorquestao5);
        }

if(v==38){
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_compmax_individual_2_count(DNI,datetime,contadorquestao5);
        }

if(v==39){
        cout<<"Precipitation (mm)"<<endl;
        imprimir_compmax_individual_2_count(Precipitation,datetime,contadorquestao5);
        }

if(v==40){
        cout<<"Precipitation (mm)"<<endl;
        imprimir_compmax_individual_2_sum(Precipitation,datetime,contadorquestao5);
        }
if(v==41){
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_compmax_individual_2_avg(GTI,datetime,contadorquestao5);
        }

if(v==42){
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_compmax_individual_2_max(GTI,datetime,contadorquestao5);
        }

if(v==43){
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_compmax_individual_2_min(GTI,datetime,contadorquestao5);
        }

if(v==44){
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_compmax_individual_2_stddev(GTI,datetime,contadorquestao5);
        }
if(v==45){
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_compmax_individual_2_count(GTI,datetime,contadorquestao5);
        }

        //acaba a parte de dam
        if(v==46){
        cout<<"A1 channel (V)"<<endl;
        imprimir_compmax_individual_2_avg(A1,datetime,contadorquestao5);
        }
        if(v==47){
        cout<<"A1 channel (V)"<<endl;
        imprimir_compmax_individual_2_max(A1,datetime,contadorquestao5);
        }
        if(v==48){
        cout<<"A1 channel (V)"<<endl;
        imprimir_compmax_individual_2_min(A1,datetime,contadorquestao5);
        }
        if(v==49){
        cout<<"A1 channel (V)"<<endl;
        imprimir_compmax_individual_2_stddev(A1,datetime,contadorquestao5);
        }
        if(v==50){
        cout<<"A2 channel (V)"<<endl;
        imprimir_compmax_individual_2_avg(A2,datetime,contadorquestao5);
        }
        if(v==51){
        cout<<"A2 channel (V)"<<endl;
        imprimir_compmax_individual_2_max(A2,datetime,contadorquestao5);
        }
        if(v==52){
        cout<<"A2 channel (V)"<<endl;
        imprimir_compmax_individual_2_min(A2,datetime,contadorquestao5);
        }
        if(v==53){
        cout<<"A2 channel (V)"<<endl;
        imprimir_compmax_individual_2_stddev(A2,datetime,contadorquestao5);
        }

        if(v==54){
        cout<<"A3 channel (V)"<<endl;
        imprimir_compmax_individual_2_avg(A3,datetime,contadorquestao5);
        }
        if(v==55){
        cout<<"A3 channel (V)"<<endl;
        imprimir_compmax_individual_2_max(A3,datetime,contadorquestao5);
        }
        if(v==56){
        cout<<"A3 channel (V)"<<endl;
        imprimir_compmax_individual_2_min(A3,datetime,contadorquestao5);
        }
        if(v==57){
        cout<<"A3 channel (V)"<<endl;
        imprimir_compmax_individual_2_stddev(A3,datetime,contadorquestao5);
        }
        if(v==58){
        cout<<"A4 channel (V)"<<endl;
        imprimir_compmax_individual_2_avg(A4,datetime,contadorquestao5);
        }
        if(v==59){
        cout<<"A4 channel (V)"<<endl;
        imprimir_compmax_individual_2_max(A4,datetime,contadorquestao5);
        }
        if(v==60){
        cout<<"A4 channel (V)"<<endl;
        imprimir_compmax_individual_2_min(A4,datetime,contadorquestao5);
        }
        if(v==61){
        cout<<"A4 channel (V)"<<endl;
        imprimir_compmax_individual_2_stddev(A4,datetime,contadorquestao5);
        }
        if(v==62){
        cout<<"A5 channel (V)"<<endl;
        imprimir_compmax_individual_2_avg(A5,datetime,contadorquestao5);
        }
        if(v==63){
        cout<<"A5 channel (V)"<<endl;
        imprimir_compmax_individual_2_max(A5,datetime,contadorquestao5);
        }
        if(v==64){
        cout<<"A5 channel (V)"<<endl;
        imprimir_compmax_individual_2_min(A5,datetime,contadorquestao5);
        }
        if(v==65){
        cout<<"A5 channel (V)"<<endl;
        imprimir_compmax_individual_2_stddev(A5,datetime,contadorquestao5);
        }
        if(v==66){
        cout<<"A6 channel (V)"<<endl;
        imprimir_compmax_individual_2_avg(A6,datetime,contadorquestao5);
        }
        if(v==67){
        cout<<"A6 channel (V)"<<endl;
        imprimir_compmax_individual_2_max(A6,datetime,contadorquestao5);
        }
        if(v==68){
        cout<<"A6 channel (V)"<<endl;
        imprimir_compmax_individual_2_min(A6,datetime,contadorquestao5);
        }
        if(v==69){
        cout<<"A6 channel (V)"<<endl;
        imprimir_compmax_individual_2_stddev(A6,datetime,contadorquestao5);
        }
        if(v==70){
        cout<<"A7 channel (V)"<<endl;
        imprimir_compmax_individual_2_avg(A7,datetime,contadorquestao5);
        }
        if(v==71){
        cout<<"A7 channel (V)"<<endl;
        imprimir_compmax_individual_2_max(A7,datetime,contadorquestao5);
        }
        if(v==72){
        cout<<"A7 channel (V)"<<endl;
        imprimir_compmax_individual_2_min(A7,datetime,contadorquestao5);
        }
        if(v==73){
        cout<<"A7 channel (V)"<<endl;
        imprimir_compmax_individual_2_stddev(A7,datetime,contadorquestao5);
        }//damiao começa
if(v==74){
        cout<<"C1 channel (V)"<<endl;
        imprimir_compmax_individual_2_avg(C1,datetime,contadorquestao5);
        }

if(v==75){
        cout<<"C1 channel (V)"<<endl;
        imprimir_compmax_individual_2_max(C1,datetime,contadorquestao5);
        }

if(v==76){
        cout<<"C1 channel (V)"<<endl;
        imprimir_compmax_individual_2_min(C1,datetime,contadorquestao5);
        }
if(v==77){
        cout<<"C1 channel (V)"<<endl;
        imprimir_compmax_individual_2_stddev(C1,datetime,contadorquestao5);
        }

if(v==78){
        cout<<"C2 channel (V)"<<endl;
        imprimir_compmax_individual_2_avg(C2,datetime,contadorquestao5);
        }

if(v==79){
        cout<<"C2 channel (V)"<<endl;
        imprimir_compmax_individual_2_max(C2,datetime,contadorquestao5);
        }

if(v==80){
        cout<<"C2 channel (V)"<<endl;
        imprimir_compmax_individual_2_min(C2,datetime,contadorquestao5);
        }

if(v==81){
        cout<<"C2 channel (V)"<<endl;
        imprimir_compmax_individual_2_stddev(C2,datetime,contadorquestao5);
        }

if(v==82){
        cout<<"D1 channel (V)"<<endl;
        imprimir_compmax_individual_2_avg(D1,datetime,contadorquestao5);
        }

if(v==83){
        cout<<"D1 channel (V)"<<endl;
        imprimir_compmax_individual_2_max(D1,datetime,contadorquestao5);
        }

if(v==84){
        cout<<"D1 channel (V)"<<endl;
        imprimir_compmax_individual_2_min(D1,datetime,contadorquestao5);
        }
if(v==85){
        cout<<"D1 channel (V)"<<endl;
        imprimir_compmax_individual_2_stddev(D1,datetime,contadorquestao5);
        }

if(v==86){
        cout<<"T channel (AC)"<<endl;
        imprimir_compmax_individual_2_avg(T,datetime,contadorquestao5);
        }

if(v==86){
        cout<<"T channel (AC)"<<endl;
        imprimir_compmax_individual_2_avg(T,datetime,contadorquestao5);
        }

if(v==87){
        cout<<"I channel (mA)"<<endl;
        imprimir_compmax_individual_2_avg(I,datetime,contadorquestao5);
        }

if(v==88){
        cout<<"I channel (mA)"<<endl;
        imprimir_compmax_individual_2_max(I,datetime,contadorquestao5);
        }

if(v==89){
        cout<<"I channel (mA)"<<endl;
        imprimir_compmax_individual_2_min(I,datetime,contadorquestao5);
        }
        //damiao acaba
        if(v==90){
        cout<<"V channel (V)"<<endl;
        imprimir_compmax_individual_2_avg(V,datetime,contadorquestao5);
        }
        if(v==91){
        cout<<"V channel (V)"<<endl;
        imprimir_compmax_individual_2_max(V,datetime,contadorquestao5);
        }
        if(v==92){
        cout<<"V channel (V)"<<endl;
        imprimir_compmax_individual_2_min(V,datetime,contadorquestao5);
        }




}


//comando t + V
if(t!=0 && v!=0 && condicao1questao3==0){
int valorj=0;
        for(int contadorcaso2=0;contadorcaso2<144;contadorcaso2++){
            if(datetime[contadorcaso2].tm_hour==time.tm_hour && datetime[contadorcaso2].tm_min==time.tm_min){
                valorj = contadorcaso2;
                break;
            }
        }


        if(v==1){
        cout<<"Anemoneter wind speed average(m/s)"<<endl;
        imprimir_individual_1_avg(Anemoneter,datetime,valorj);
        }
        if(v==2){
        cout<<"Anemoneter wind speed max(m/s)"<<endl;
        imprimir_individual_1_max(Anemoneter,datetime,valorj);
        }
        if(v==3){
        cout<<"Anemoneter wind speed min(m/s)"<<endl;
        imprimir_individual_1_min(Anemoneter,datetime,valorj);
        }
        if(v==4){
        cout<<"Anemoneter wind speed min(m/s)"<<endl;
        imprimir_individual_1_stddev(Anemoneter,datetime,valorj);
        }
        if(v==5){
        cout<<"Anemoneter wind speed min(m/s)"<<endl;
        imprimir_individual_1_count(Anemoneter,datetime,valorj);
        }
        
        if(v==6){
        cout<<"Wind Vane TMR wind direction (A)"<<endl;
        imprimir_individual_1_avg(Wind_Vane,datetime,valorj);
        }
        if(v==7){
        cout<<"Wind Vane TMR wind direction (A)"<<endl;
        imprimir_individual_1_stddev(Wind_Vane,datetime,valorj);
        }
        if(v==8){
        cout<<"Wind Vane TMR wind direction (A)"<<endl;
        imprimir_individual_1_count(Wind_Vane,datetime,valorj);
        }
        
        if(v==9){
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_individual_1_avg(Thermo_Hum,datetime,valorj);
        }
        if(v==10){
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_individual_1_max(Thermo_Hum,datetime,valorj);
        }
        if(v==11){
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_individual_1_min(Thermo_Hum,datetime,valorj);
        }
        if(v==12){
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_individual_1_stddev(Thermo_Hum,datetime,valorj);
        }
        if(v==13){
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_individual_1_count(Thermo_Hum,datetime,valorj);
        }
        if(v==14){
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_individual_1_avg(Thermo_Temp,datetime,valorj);
        }
        if(v==15){
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_individual_1_max(Thermo_Temp,datetime,valorj);
        }
        if(v==16){
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_individual_1_min(Thermo_Temp,datetime,valorj);
        }
        if(v==17){
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_individual_1_stddev(Thermo_Temp,datetime,valorj);
        }
        if(v==18){
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_individual_1_count(Thermo_Temp,datetime,valorj);
        }
        if(v==19){
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_individual_1_avg(Barometer,datetime,valorj);
        }
        if(v==20){
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_individual_1_max(Barometer,datetime,valorj);
        }
        if(v==21){
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_individual_1_min(Barometer,datetime,valorj);
        }
        if(v==22){
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_individual_1_stddev(Barometer,datetime,valorj);
        }
        if(v==23){
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_individual_1_count(Barometer,datetime,valorj);
        }

        if(v==24){
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_individual_1_avg(DHI,datetime,valorj);
        }
        if(v==25){
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_individual_1_max(DHI,datetime,valorj);
        }if(v==26){
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_individual_1_min(DHI,datetime,valorj);
        }
        if(v==27){
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_individual_1_stddev(DHI,datetime,valorj);
        }if(v==28){
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_individual_1_count(DHI,datetime,valorj);
        }
        //começa dam
     if(v==29){
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_individual_1_avg(GHI,datetime,valorj);
        }

 if(v==30){
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_individual_1_max(GHI,datetime,valorj);
        }

 if(v==31){
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_individual_1_min(GHI,datetime,valorj);
        }

if(v==32){
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_individual_1_stddev(GHI,datetime,valorj);
        }

if(v==33){
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_individual_1_count(GHI,datetime,valorj);
        }

if(v==34){
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_individual_1_avg(DNI,datetime,valorj);
        }
if(v==35){
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_individual_1_max(DNI,datetime,valorj);
        }

if(v==36){
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_individual_1_min(DNI,datetime,valorj);
        }

if(v==37){
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_individual_1_stddev(DNI,datetime,valorj);
        }

if(v==38){
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_individual_1_count(DNI,datetime,valorj);
        }

if(v==39){
        cout<<"Precipitation (mm)"<<endl;
        imprimir_individual_1_count(Precipitation,datetime,valorj);
        }

if(v==40){
        cout<<"Precipitation (mm)"<<endl;
        imprimir_individual_1_sum(Precipitation,datetime,valorj);
        }
if(v==41){
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_individual_1_avg(GTI,datetime,valorj);
        }

if(v==42){
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_individual_1_max(GTI,datetime,valorj);
        }

if(v==43){
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_individual_1_min(GTI,datetime,valorj);
        }

if(v==44){
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_individual_1_stddev(GTI,datetime,valorj);
        }
if(v==45){
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_individual_1_count(GTI,datetime,valorj);
        }

        //acaba a parte de dam
        if(v==46){
        cout<<"A1 channel (V)"<<endl;
        imprimir_individual_1_avg(A1,datetime,valorj);
        }
        if(v==47){
        cout<<"A1 channel (V)"<<endl;
        imprimir_individual_1_max(A1,datetime,valorj);
        }
        if(v==48){
        cout<<"A1 channel (V)"<<endl;
        imprimir_individual_1_min(A1,datetime,valorj);
        }
        if(v==49){
        cout<<"A1 channel (V)"<<endl;
        imprimir_individual_1_stddev(A1,datetime,valorj);
        }
        if(v==50){
        cout<<"A2 channel (V)"<<endl;
        imprimir_individual_1_avg(A2,datetime,valorj);
        }
        if(v==51){
        cout<<"A2 channel (V)"<<endl;
        imprimir_individual_1_max(A2,datetime,valorj);
        }
        if(v==52){
        cout<<"A2 channel (V)"<<endl;
        imprimir_individual_1_min(A2,datetime,valorj);
        }
        if(v==53){
        cout<<"A2 channel (V)"<<endl;
        imprimir_individual_1_stddev(A2,datetime,valorj);
        }

        if(v==54){
        cout<<"A3 channel (V)"<<endl;
        imprimir_individual_1_avg(A3,datetime,valorj);
        }
        if(v==55){
        cout<<"A3 channel (V)"<<endl;
        imprimir_individual_1_max(A3,datetime,valorj);
        }
        if(v==56){
        cout<<"A3 channel (V)"<<endl;
        imprimir_individual_1_min(A3,datetime,valorj);
        }
        if(v==57){
        cout<<"A3 channel (V)"<<endl;
        imprimir_individual_1_stddev(A3,datetime,valorj);
        }
        if(v==58){
        cout<<"A4 channel (V)"<<endl;
        imprimir_individual_1_avg(A4,datetime,valorj);
        }
        if(v==59){
        cout<<"A4 channel (V)"<<endl;
        imprimir_individual_1_max(A4,datetime,valorj);
        }
        if(v==60){
        cout<<"A4 channel (V)"<<endl;
        imprimir_individual_1_min(A4,datetime,valorj);
        }
        if(v==61){
        cout<<"A4 channel (V)"<<endl;
        imprimir_individual_1_stddev(A4,datetime,valorj);
        }
        if(v==62){
        cout<<"A5 channel (V)"<<endl;
        imprimir_individual_1_avg(A5,datetime,valorj);
        }
        if(v==63){
        cout<<"A5 channel (V)"<<endl;
        imprimir_individual_1_max(A5,datetime,valorj);
        }
        if(v==64){
        cout<<"A5 channel (V)"<<endl;
        imprimir_individual_1_min(A5,datetime,valorj);
        }
        if(v==65){
        cout<<"A5 channel (V)"<<endl;
        imprimir_individual_1_stddev(A5,datetime,valorj);
        }
        if(v==66){
        cout<<"A6 channel (V)"<<endl;
        imprimir_individual_1_avg(A6,datetime,valorj);
        }
        if(v==67){
        cout<<"A6 channel (V)"<<endl;
        imprimir_individual_1_max(A6,datetime,valorj);
        }
        if(v==68){
        cout<<"A6 channel (V)"<<endl;
        imprimir_individual_1_min(A6,datetime,valorj);
        }
        if(v==69){
        cout<<"A6 channel (V)"<<endl;
        imprimir_individual_1_stddev(A6,datetime,valorj);
        }
        if(v==70){
        cout<<"A7 channel (V)"<<endl;
        imprimir_individual_1_avg(A7,datetime,valorj);
        }
        if(v==71){
        cout<<"A7 channel (V)"<<endl;
        imprimir_individual_1_max(A7,datetime,valorj);
        }
        if(v==72){
        cout<<"A7 channel (V)"<<endl;
        imprimir_individual_1_min(A7,datetime,valorj);
        }
        if(v==73){
        cout<<"A7 channel (V)"<<endl;
        imprimir_individual_1_stddev(A7,datetime,valorj);
        }//damiao começa
if(v==74){
        cout<<"C1 channel (V)"<<endl;
        imprimir_individual_1_avg(C1,datetime,valorj);
        }

if(v==75){
        cout<<"C1 channel (V)"<<endl;
        imprimir_individual_1_max(C1,datetime,valorj);
        }

if(v==76){
        cout<<"C1 channel (V)"<<endl;
        imprimir_individual_1_min(C1,datetime,valorj);
        }
if(v==77){
        cout<<"C1 channel (V)"<<endl;
        imprimir_individual_1_stddev(C1,datetime,valorj);
        }

if(v==78){
        cout<<"C2 channel (V)"<<endl;
        imprimir_individual_1_avg(C2,datetime,valorj);
        }

if(v==79){
        cout<<"C2 channel (V)"<<endl;
        imprimir_individual_1_max(C2,datetime,valorj);
        }

if(v==80){
        cout<<"C2 channel (V)"<<endl;
        imprimir_individual_1_min(C2,datetime,valorj);
        }

if(v==81){
        cout<<"C2 channel (V)"<<endl;
        imprimir_individual_1_stddev(C2,datetime,valorj);
        }

if(v==82){
        cout<<"D1 channel (V)"<<endl;
        imprimir_individual_1_avg(D1,datetime,valorj);
        }

if(v==83){
        cout<<"D1 channel (V)"<<endl;
        imprimir_individual_1_max(D1,datetime,valorj);
        }

if(v==84){
        cout<<"D1 channel (V)"<<endl;
        imprimir_individual_1_min(D1,datetime,valorj);
        }
if(v==85){
        cout<<"D1 channel (V)"<<endl;
        imprimir_individual_1_stddev(D1,datetime,valorj);
        }

if(v==86){
        cout<<"T channel (AC)"<<endl;
        imprimir_individual_1_avg(T,datetime,valorj);
        }

if(v==86){
        cout<<"T channel (AC)"<<endl;
        imprimir_individual_1_avg(T,datetime,valorj);
        }

if(v==87){
        cout<<"I channel (mA)"<<endl;
        imprimir_individual_1_avg(I,datetime,valorj);
        }

if(v==88){
        cout<<"I channel (mA)"<<endl;
        imprimir_individual_1_max(I,datetime,valorj);
        }

if(v==89){
        cout<<"I channel (mA)"<<endl;
        imprimir_individual_1_min(I,datetime,valorj);
        }
        //damiao acaba
        if(v==90){
        cout<<"V channel (V)"<<endl;
        imprimir_individual_1_avg(V,datetime,valorj);
        }
        if(v==91){
        cout<<"V channel (V)"<<endl;
        imprimir_individual_1_max(V,datetime,valorj);
        }
        if(v==92){
        cout<<"V channel (V)"<<endl;
        imprimir_individual_1_min(V,datetime,valorj);
        }





        
}


//comando TiTf + V + Vmax + Vmin
if(condicao1questao3==1 && v!=0){

        int titf=0, limitetitf=0;

for(int contadorti=0;contadorti<144;contadorti++){
            if(datetime[contadorti].tm_hour==time_inicial.tm_hour && datetime[contadorti].tm_min==time_inicial.tm_min){
                titf = contadorti;
                break;
            }
        }
        for(int contadortf=0;contadortf<144;contadortf++){
            if(datetime[contadortf].tm_hour==time_final.tm_hour && datetime[contadortf].tm_min==time_final.tm_min){
                limitetitf = contadortf;
                break;
            }
        }
int contadorinicialfuncao = titf;
while (titf<limitetitf){
if(v==1){
        cout<<"Anemoneter wind speed average(m/s)"<<endl;
        imprimir_individual_1_avg(Anemoneter,datetime,titf);
        }
        if(v==2){
        cout<<"Anemoneter wind speed max(m/s)"<<endl;
        imprimir_individual_1_max(Anemoneter,datetime,titf);
        }
        if(v==3){
        cout<<"Anemoneter wind speed min(m/s)"<<endl;
        imprimir_individual_1_min(Anemoneter,datetime,titf);
        }
        if(v==4){
        cout<<"Anemoneter wind speed min(m/s)"<<endl;
        imprimir_individual_1_stddev(Anemoneter,datetime,titf);
        }
        if(v==5){
        cout<<"Anemoneter wind speed min(m/s)"<<endl;
        imprimir_individual_1_count(Anemoneter,datetime,titf);
        }
        
        if(v==6){
        cout<<"Wind Vane TMR wind direction (A)"<<endl;
        imprimir_individual_1_avg(Wind_Vane,datetime,titf);
        }
        if(v==7){
        cout<<"Wind Vane TMR wind direction (A)"<<endl;
        imprimir_individual_1_stddev(Wind_Vane,datetime,titf);
        }
        if(v==8){
        cout<<"Wind Vane TMR wind direction (A)"<<endl;
        imprimir_individual_1_count(Wind_Vane,datetime,titf);
        }
        
        if(v==9){
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_individual_1_avg(Thermo_Hum,datetime,titf);
        }
        if(v==10){
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_individual_1_max(Thermo_Hum,datetime,titf);
        }
        if(v==11){
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_individual_1_min(Thermo_Hum,datetime,titf);
        }
        if(v==12){
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_individual_1_stddev(Thermo_Hum,datetime,titf);
        }
        if(v==13){
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_individual_1_count(Thermo_Hum,datetime,titf);
        }
        if(v==14){
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_individual_1_avg(Thermo_Temp,datetime,titf);
        }
        if(v==15){
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_individual_1_max(Thermo_Temp,datetime,titf);
        }
        if(v==16){
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_individual_1_min(Thermo_Temp,datetime,titf);
        }
        if(v==17){
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_individual_1_stddev(Thermo_Temp,datetime,titf);
        }
        if(v==18){
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_individual_1_count(Thermo_Temp,datetime,titf);
        }
        if(v==19){
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_individual_1_avg(Barometer,datetime,titf);
        }
        if(v==20){
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_individual_1_max(Barometer,datetime,titf);
        }
        if(v==21){
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_individual_1_min(Barometer,datetime,titf);
        }
        if(v==22){
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_individual_1_stddev(Barometer,datetime,titf);
        }
        if(v==23){
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_individual_1_count(Barometer,datetime,titf);
        }

        if(v==24){
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_individual_1_avg(DHI,datetime,titf);
        }
        if(v==25){
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_individual_1_max(DHI,datetime,titf);
        }if(v==26){
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_individual_1_min(DHI,datetime,titf);
        }
        if(v==27){
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_individual_1_stddev(DHI,datetime,titf);
        }if(v==28){
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_individual_1_count(DHI,datetime,titf);
        }
        //começa dam
     if(v==29){
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_individual_1_avg(GHI,datetime,titf);
        }

 if(v==30){
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_individual_1_max(GHI,datetime,titf);
        }

 if(v==31){
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_individual_1_min(GHI,datetime,titf);
        }

if(v==32){
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_individual_1_stddev(GHI,datetime,titf);
        }

if(v==33){
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_individual_1_count(GHI,datetime,titf);
        }

if(v==34){
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_individual_1_avg(DNI,datetime,titf);
        }
if(v==35){
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_individual_1_max(DNI,datetime,titf);
        }

if(v==36){
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_individual_1_min(DNI,datetime,titf);
        }

if(v==37){
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_individual_1_stddev(DNI,datetime,titf);
        }

if(v==38){
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_individual_1_count(DNI,datetime,titf);
        }

if(v==39){
        cout<<"Precipitation (mm)"<<endl;
        imprimir_individual_1_count(Precipitation,datetime,titf);
        }

if(v==40){
        cout<<"Precipitation (mm)"<<endl;
        imprimir_individual_1_sum(Precipitation,datetime,titf);
        }
if(v==41){
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_individual_1_avg(GTI,datetime,titf);
        }

if(v==42){
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_individual_1_max(GTI,datetime,titf);
        }

if(v==43){
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_individual_1_min(GTI,datetime,titf);
        }

if(v==44){
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_individual_1_stddev(GTI,datetime,titf);
        }
if(v==45){
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_individual_1_count(GTI,datetime,titf);
        }

        //acaba a parte de dam
        if(v==46){
        cout<<"A1 channel (V)"<<endl;
        imprimir_individual_1_avg(A1,datetime,titf);
        }
        if(v==47){
        cout<<"A1 channel (V)"<<endl;
        imprimir_individual_1_max(A1,datetime,titf);
        }
        if(v==48){
        cout<<"A1 channel (V)"<<endl;
        imprimir_individual_1_min(A1,datetime,titf);
        }
        if(v==49){
        cout<<"A1 channel (V)"<<endl;
        imprimir_individual_1_stddev(A1,datetime,titf);
        }
        if(v==50){
        cout<<"A2 channel (V)"<<endl;
        imprimir_individual_1_avg(A2,datetime,titf);
        }
        if(v==51){
        cout<<"A2 channel (V)"<<endl;
        imprimir_individual_1_max(A2,datetime,titf);
        }
        if(v==52){
        cout<<"A2 channel (V)"<<endl;
        imprimir_individual_1_min(A2,datetime,titf);
        }
        if(v==53){
        cout<<"A2 channel (V)"<<endl;
        imprimir_individual_1_stddev(A2,datetime,titf);
        }

        if(v==54){
        cout<<"A3 channel (V)"<<endl;
        imprimir_individual_1_avg(A3,datetime,titf);
        }
        if(v==55){
        cout<<"A3 channel (V)"<<endl;
        imprimir_individual_1_max(A3,datetime,titf);
        }
        if(v==56){
        cout<<"A3 channel (V)"<<endl;
        imprimir_individual_1_min(A3,datetime,titf);
        }
        if(v==57){
        cout<<"A3 channel (V)"<<endl;
        imprimir_individual_1_stddev(A3,datetime,titf);
        }
        if(v==58){
        cout<<"A4 channel (V)"<<endl;
        imprimir_individual_1_avg(A4,datetime,titf);
        }
        if(v==59){
        cout<<"A4 channel (V)"<<endl;
        imprimir_individual_1_max(A4,datetime,titf);
        }
        if(v==60){
        cout<<"A4 channel (V)"<<endl;
        imprimir_individual_1_min(A4,datetime,titf);
        }
        if(v==61){
        cout<<"A4 channel (V)"<<endl;
        imprimir_individual_1_stddev(A4,datetime,titf);
        }
        if(v==62){
        cout<<"A5 channel (V)"<<endl;
        imprimir_individual_1_avg(A5,datetime,titf);
        }
        if(v==63){
        cout<<"A5 channel (V)"<<endl;
        imprimir_individual_1_max(A5,datetime,titf);
        }
        if(v==64){
        cout<<"A5 channel (V)"<<endl;
        imprimir_individual_1_min(A5,datetime,titf);
        }
        if(v==65){
        cout<<"A5 channel (V)"<<endl;
        imprimir_individual_1_stddev(A5,datetime,titf);
        }
        if(v==66){
        cout<<"A6 channel (V)"<<endl;
        imprimir_individual_1_avg(A6,datetime,titf);
        }
        if(v==67){
        cout<<"A6 channel (V)"<<endl;
        imprimir_individual_1_max(A6,datetime,titf);
        }
        if(v==68){
        cout<<"A6 channel (V)"<<endl;
        imprimir_individual_1_min(A6,datetime,titf);
        }
        if(v==69){
        cout<<"A6 channel (V)"<<endl;
        imprimir_individual_1_stddev(A6,datetime,titf);
        }
        if(v==70){
        cout<<"A7 channel (V)"<<endl;
        imprimir_individual_1_avg(A7,datetime,titf);
        }
        if(v==71){
        cout<<"A7 channel (V)"<<endl;
        imprimir_individual_1_max(A7,datetime,titf);
        }
        if(v==72){
        cout<<"A7 channel (V)"<<endl;
        imprimir_individual_1_min(A7,datetime,titf);
        }
        if(v==73){
        cout<<"A7 channel (V)"<<endl;
        imprimir_individual_1_stddev(A7,datetime,titf);
        }//damiao começa
if(v==74){
        cout<<"C1 channel (V)"<<endl;
        imprimir_individual_1_avg(C1,datetime,titf);
        }

if(v==75){
        cout<<"C1 channel (V)"<<endl;
        imprimir_individual_1_max(C1,datetime,titf);
        }

if(v==76){
        cout<<"C1 channel (V)"<<endl;
        imprimir_individual_1_min(C1,datetime,titf);
        }
if(v==77){
        cout<<"C1 channel (V)"<<endl;
        imprimir_individual_1_stddev(C1,datetime,titf);
        }

if(v==78){
        cout<<"C2 channel (V)"<<endl;
        imprimir_individual_1_avg(C2,datetime,titf);
        }

if(v==79){
        cout<<"C2 channel (V)"<<endl;
        imprimir_individual_1_max(C2,datetime,titf);
        }

if(v==80){
        cout<<"C2 channel (V)"<<endl;
        imprimir_individual_1_min(C2,datetime,titf);
        }

if(v==81){
        cout<<"C2 channel (V)"<<endl;
        imprimir_individual_1_stddev(C2,datetime,titf);
        }

if(v==82){
        cout<<"D1 channel (V)"<<endl;
        imprimir_individual_1_avg(D1,datetime,titf);
        }

if(v==83){
        cout<<"D1 channel (V)"<<endl;
        imprimir_individual_1_max(D1,datetime,titf);
        }

if(v==84){
        cout<<"D1 channel (V)"<<endl;
        imprimir_individual_1_min(D1,datetime,titf);
        }
if(v==85){
        cout<<"D1 channel (V)"<<endl;
        imprimir_individual_1_stddev(D1,datetime,titf);
        }

if(v==86){
        cout<<"T channel (AC)"<<endl;
        imprimir_individual_1_avg(T,datetime,titf);
        }

if(v==86){
        cout<<"T channel (AC)"<<endl;
        imprimir_individual_1_avg(T,datetime,titf);
        }

if(v==87){
        cout<<"I channel (mA)"<<endl;
        imprimir_individual_1_avg(I,datetime,titf);
        }

if(v==88){
        cout<<"I channel (mA)"<<endl;
        imprimir_individual_1_max(I,datetime,titf);
        }

if(v==89){
        cout<<"I channel (mA)"<<endl;
        imprimir_individual_1_min(I,datetime,titf);
        }
        //damiao acaba
        if(v==90){
        cout<<"V channel (V)"<<endl;
        imprimir_individual_1_avg(V,datetime,titf);
        }
        if(v==91){
        cout<<"V channel (V)"<<endl;
        imprimir_individual_1_max(V,datetime,titf);
        }
        if(v==92){
        cout<<"V channel (V)"<<endl;
        imprimir_individual_1_min(V,datetime,titf);
        }
titf++;
}
        if(vmax==1){
        if(v==1){
        cout<<"Anemoneter wind speed average(m/s)"<<endl;
        imprimir_compmax_individual_4_avg(Anemoneter,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==2){
        cout<<"Anemoneter wind speed max(m/s)"<<endl;
        imprimir_compmax_individual_4_max(Anemoneter,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==3){
        cout<<"Anemoneter wind speed min(m/s)"<<endl;
        imprimir_compmax_individual_4_min(Anemoneter,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==4){
        cout<<"Anemoneter wind speed min(m/s)"<<endl;
        imprimir_compmax_individual_4_stddev(Anemoneter,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==5){
        cout<<"Anemoneter wind speed min(m/s)"<<endl;
        imprimir_compmax_individual_4_count(Anemoneter,datetime,contadorinicialfuncao, limitetitf);
        }
        
        if(v==6){
        cout<<"Wind Vane TMR wind direction (A)"<<endl;
        imprimir_compmax_individual_4_avg(Wind_Vane,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==7){
        cout<<"Wind Vane TMR wind direction (A)"<<endl;
        imprimir_compmax_individual_4_stddev(Wind_Vane,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==8){
        cout<<"Wind Vane TMR wind direction (A)"<<endl;
        imprimir_compmax_individual_4_count(Wind_Vane,datetime,contadorinicialfuncao, limitetitf);
        }
        
        if(v==9){
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_compmax_individual_4_avg(Thermo_Hum,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==10){
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_compmax_individual_4_max(Thermo_Hum,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==11){
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_compmax_individual_4_min(Thermo_Hum,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==12){
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_compmax_individual_4_stddev(Thermo_Hum,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==13){
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_compmax_individual_4_count(Thermo_Hum,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==14){
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_compmax_individual_4_avg(Thermo_Temp,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==15){
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_compmax_individual_4_max(Thermo_Temp,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==16){
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_compmax_individual_4_min(Thermo_Temp,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==17){
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_compmax_individual_4_stddev(Thermo_Temp,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==18){
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_compmax_individual_4_count(Thermo_Temp,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==19){
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_compmax_individual_4_avg(Barometer,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==20){
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_compmax_individual_4_max(Barometer,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==21){
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_compmax_individual_4_min(Barometer,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==22){
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_compmax_individual_4_stddev(Barometer,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==23){
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_compmax_individual_4_count(Barometer,datetime,contadorinicialfuncao, limitetitf);
        }

        if(v==24){
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmax_individual_4_avg(DHI,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==25){
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmax_individual_4_max(DHI,datetime,contadorinicialfuncao, limitetitf);
        }if(v==26){
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmax_individual_4_min(DHI,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==27){
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmax_individual_4_stddev(DHI,datetime,contadorinicialfuncao, limitetitf);
        }if(v==28){
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmax_individual_4_count(DHI,datetime,contadorinicialfuncao, limitetitf);
        }
        //começa dam
     if(v==29){
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmax_individual_4_avg(GHI,datetime,contadorinicialfuncao, limitetitf);
        }

 if(v==30){
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmax_individual_4_max(GHI,datetime,contadorinicialfuncao, limitetitf);
        }

 if(v==31){
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmax_individual_4_min(GHI,datetime,contadorinicialfuncao, limitetitf);
        }

if(v==32){
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmax_individual_4_stddev(GHI,datetime,contadorinicialfuncao, limitetitf);
        }

if(v==33){
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmax_individual_4_count(GHI,datetime,contadorinicialfuncao, limitetitf);
        }

if(v==34){
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_compmax_individual_4_avg(DNI,datetime,contadorinicialfuncao, limitetitf);
        }
if(v==35){
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_compmax_individual_4_max(DNI,datetime,contadorinicialfuncao, limitetitf);
        }

if(v==36){
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_compmax_individual_4_min(DNI,datetime,contadorinicialfuncao, limitetitf);
        }

if(v==37){
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_compmax_individual_4_stddev(DNI,datetime,contadorinicialfuncao, limitetitf);
        }

if(v==38){
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_compmax_individual_4_count(DNI,datetime,contadorinicialfuncao, limitetitf);
        }

if(v==39){
        cout<<"Precipitation (mm)"<<endl;
        imprimir_compmax_individual_4_count(Precipitation,datetime,contadorinicialfuncao, limitetitf);
        }

if(v==40){
        cout<<"Precipitation (mm)"<<endl;
        imprimir_compmax_individual_4_sum(Precipitation,datetime,contadorinicialfuncao, limitetitf);
        }
if(v==41){
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_compmax_individual_4_avg(GTI,datetime,contadorinicialfuncao, limitetitf);
        }

if(v==42){
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_compmax_individual_4_max(GTI,datetime,contadorinicialfuncao, limitetitf);
        }

if(v==43){
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_compmax_individual_4_min(GTI,datetime,contadorinicialfuncao, limitetitf);
        }

if(v==44){
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_compmax_individual_4_stddev(GTI,datetime,contadorinicialfuncao, limitetitf);
        }
if(v==45){
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_compmax_individual_4_count(GTI,datetime,contadorinicialfuncao, limitetitf);
        }

        //acaba a parte de dam
        if(v==46){
        cout<<"A1 channel (V)"<<endl;
        imprimir_compmax_individual_4_avg(A1,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==47){
        cout<<"A1 channel (V)"<<endl;
        imprimir_compmax_individual_4_max(A1,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==48){
        cout<<"A1 channel (V)"<<endl;
        imprimir_compmax_individual_4_min(A1,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==49){
        cout<<"A1 channel (V)"<<endl;
        imprimir_compmax_individual_4_stddev(A1,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==50){
        cout<<"A2 channel (V)"<<endl;
        imprimir_compmax_individual_4_avg(A2,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==51){
        cout<<"A2 channel (V)"<<endl;
        imprimir_compmax_individual_4_max(A2,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==52){
        cout<<"A2 channel (V)"<<endl;
        imprimir_compmax_individual_4_min(A2,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==53){
        cout<<"A2 channel (V)"<<endl;
        imprimir_compmax_individual_4_stddev(A2,datetime,contadorinicialfuncao, limitetitf);
        }

        if(v==54){
        cout<<"A3 channel (V)"<<endl;
        imprimir_compmax_individual_4_avg(A3,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==55){
        cout<<"A3 channel (V)"<<endl;
        imprimir_compmax_individual_4_max(A3,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==56){
        cout<<"A3 channel (V)"<<endl;
        imprimir_compmax_individual_4_min(A3,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==57){
        cout<<"A3 channel (V)"<<endl;
        imprimir_compmax_individual_4_stddev(A3,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==58){
        cout<<"A4 channel (V)"<<endl;
        imprimir_compmax_individual_4_avg(A4,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==59){
        cout<<"A4 channel (V)"<<endl;
        imprimir_compmax_individual_4_max(A4,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==60){
        cout<<"A4 channel (V)"<<endl;
        imprimir_compmax_individual_4_min(A4,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==61){
        cout<<"A4 channel (V)"<<endl;
        imprimir_compmax_individual_4_stddev(A4,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==62){
        cout<<"A5 channel (V)"<<endl;
        imprimir_compmax_individual_4_avg(A5,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==63){
        cout<<"A5 channel (V)"<<endl;
        imprimir_compmax_individual_4_max(A5,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==64){
        cout<<"A5 channel (V)"<<endl;
        imprimir_compmax_individual_4_min(A5,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==65){
        cout<<"A5 channel (V)"<<endl;
        imprimir_compmax_individual_4_stddev(A5,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==66){
        cout<<"A6 channel (V)"<<endl;
        imprimir_compmax_individual_4_avg(A6,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==67){
        cout<<"A6 channel (V)"<<endl;
        imprimir_compmax_individual_4_max(A6,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==68){
        cout<<"A6 channel (V)"<<endl;
        imprimir_compmax_individual_4_min(A6,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==69){
        cout<<"A6 channel (V)"<<endl;
        imprimir_compmax_individual_4_stddev(A6,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==70){
        cout<<"A7 channel (V)"<<endl;
        imprimir_compmax_individual_4_avg(A7,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==71){
        cout<<"A7 channel (V)"<<endl;
        imprimir_compmax_individual_4_max(A7,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==72){
        cout<<"A7 channel (V)"<<endl;
        imprimir_compmax_individual_4_min(A7,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==73){
        cout<<"A7 channel (V)"<<endl;
        imprimir_compmax_individual_4_stddev(A7,datetime,contadorinicialfuncao, limitetitf);
        }//damiao começa
if(v==74){
        cout<<"C1 channel (V)"<<endl;
        imprimir_compmax_individual_4_avg(C1,datetime,contadorinicialfuncao, limitetitf);
        }

if(v==75){
        cout<<"C1 channel (V)"<<endl;
        imprimir_compmax_individual_4_max(C1,datetime,contadorinicialfuncao, limitetitf);
        }

if(v==76){
        cout<<"C1 channel (V)"<<endl;
        imprimir_compmax_individual_4_min(C1,datetime,contadorinicialfuncao, limitetitf);
        }
if(v==77){
        cout<<"C1 channel (V)"<<endl;
        imprimir_compmax_individual_4_stddev(C1,datetime,contadorinicialfuncao, limitetitf);
        }

if(v==78){
        cout<<"C2 channel (V)"<<endl;
        imprimir_compmax_individual_4_avg(C2,datetime,contadorinicialfuncao, limitetitf);
        }

if(v==79){
        cout<<"C2 channel (V)"<<endl;
        imprimir_compmax_individual_4_max(C2,datetime,contadorinicialfuncao, limitetitf);
        }

if(v==80){
        cout<<"C2 channel (V)"<<endl;
        imprimir_compmax_individual_4_min(C2,datetime,contadorinicialfuncao, limitetitf);
        }

if(v==81){
        cout<<"C2 channel (V)"<<endl;
        imprimir_compmax_individual_4_stddev(C2,datetime,contadorinicialfuncao, limitetitf);
        }

if(v==82){
        cout<<"D1 channel (V)"<<endl;
        imprimir_compmax_individual_4_avg(D1,datetime,contadorinicialfuncao, limitetitf);
        }

if(v==83){
        cout<<"D1 channel (V)"<<endl;
        imprimir_compmax_individual_4_max(D1,datetime,contadorinicialfuncao, limitetitf);
        }

if(v==84){
        cout<<"D1 channel (V)"<<endl;
        imprimir_compmax_individual_4_min(D1,datetime,contadorinicialfuncao, limitetitf);
        }
if(v==85){
        cout<<"D1 channel (V)"<<endl;
        imprimir_compmax_individual_4_stddev(D1,datetime,contadorinicialfuncao, limitetitf);
        }

if(v==86){
        cout<<"T channel (AC)"<<endl;
        imprimir_compmax_individual_4_avg(T,datetime,contadorinicialfuncao, limitetitf);
        }

if(v==86){
        cout<<"T channel (AC)"<<endl;
        imprimir_compmax_individual_4_avg(T,datetime,contadorinicialfuncao, limitetitf);
        }

if(v==87){
        cout<<"I channel (mA)"<<endl;
        imprimir_compmax_individual_4_avg(I,datetime,contadorinicialfuncao, limitetitf);
        }

if(v==88){
        cout<<"I channel (mA)"<<endl;
        imprimir_compmax_individual_4_max(I,datetime,contadorinicialfuncao, limitetitf);
        }

if(v==89){
        cout<<"I channel (mA)"<<endl;
        imprimir_compmax_individual_4_min(I,datetime,contadorinicialfuncao, limitetitf);
        }
        //damiao acaba
        if(v==90){
        cout<<"V channel (V)"<<endl;
        imprimir_compmax_individual_4_avg(V,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==91){
        cout<<"V channel (V)"<<endl;
        imprimir_compmax_individual_4_max(V,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==92){
        cout<<"V channel (V)"<<endl;
        imprimir_compmax_individual_4_min(V,datetime,contadorinicialfuncao , limitetitf);
        }
}//fim da condicao vmax
//começo da condição vmin
        if(vmin==1){
        if(v==1){
        cout<<"Anemoneter wind speed average(m/s)"<<endl;
        imprimir_compmin_individual_4_avg(Anemoneter,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==2){
        cout<<"Anemoneter wind speed max(m/s)"<<endl;
        imprimir_compmin_individual_4_max(Anemoneter,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==3){
        cout<<"Anemoneter wind speed min(m/s)"<<endl;
        imprimir_compmin_individual_4_min(Anemoneter,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==4){
        cout<<"Anemoneter wind speed min(m/s)"<<endl;
        imprimir_compmin_individual_4_stddev(Anemoneter,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==5){
        cout<<"Anemoneter wind speed min(m/s)"<<endl;
        imprimir_compmin_individual_4_count(Anemoneter,datetime,contadorinicialfuncao, limitetitf);
        }
        
        if(v==6){
        cout<<"Wind Vane TMR wind direction (A)"<<endl;
        imprimir_compmin_individual_4_avg(Wind_Vane,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==7){
        cout<<"Wind Vane TMR wind direction (A)"<<endl;
        imprimir_compmin_individual_4_stddev(Wind_Vane,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==8){
        cout<<"Wind Vane TMR wind direction (A)"<<endl;
        imprimir_compmin_individual_4_count(Wind_Vane,datetime,contadorinicialfuncao, limitetitf);
        }
        
        if(v==9){
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_compmin_individual_4_avg(Thermo_Hum,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==10){
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_compmin_individual_4_max(Thermo_Hum,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==11){
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_compmin_individual_4_min(Thermo_Hum,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==12){
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_compmin_individual_4_stddev(Thermo_Hum,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==13){
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_compmin_individual_4_count(Thermo_Hum,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==14){
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_compmin_individual_4_avg(Thermo_Temp,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==15){
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_compmin_individual_4_max(Thermo_Temp,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==16){
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_compmin_individual_4_min(Thermo_Temp,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==17){
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_compmin_individual_4_stddev(Thermo_Temp,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==18){
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_compmin_individual_4_count(Thermo_Temp,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==19){
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_compmin_individual_4_avg(Barometer,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==20){
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_compmin_individual_4_max(Barometer,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==21){
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_compmin_individual_4_min(Barometer,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==22){
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_compmin_individual_4_stddev(Barometer,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==23){
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_compmin_individual_4_count(Barometer,datetime,contadorinicialfuncao, limitetitf);
        }

        if(v==24){
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmin_individual_4_avg(DHI,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==25){
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmin_individual_4_max(DHI,datetime,contadorinicialfuncao, limitetitf);
        }if(v==26){
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmin_individual_4_min(DHI,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==27){
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmin_individual_4_stddev(DHI,datetime,contadorinicialfuncao, limitetitf);
        }if(v==28){
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmin_individual_4_count(DHI,datetime,contadorinicialfuncao, limitetitf);
        }
        //começa dam
     if(v==29){
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmin_individual_4_avg(GHI,datetime,contadorinicialfuncao, limitetitf);
        }

 if(v==30){
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmin_individual_4_max(GHI,datetime,contadorinicialfuncao, limitetitf);
        }

 if(v==31){
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmin_individual_4_min(GHI,datetime,contadorinicialfuncao, limitetitf);
        }

if(v==32){
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmin_individual_4_stddev(GHI,datetime,contadorinicialfuncao, limitetitf);
        }

if(v==33){
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmin_individual_4_count(GHI,datetime,contadorinicialfuncao, limitetitf);
        }

if(v==34){
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_compmin_individual_4_avg(DNI,datetime,contadorinicialfuncao, limitetitf);
        }
if(v==35){
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_compmin_individual_4_max(DNI,datetime,contadorinicialfuncao, limitetitf);
        }

if(v==36){
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_compmin_individual_4_min(DNI,datetime,contadorinicialfuncao, limitetitf);
        }

if(v==37){
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_compmin_individual_4_stddev(DNI,datetime,contadorinicialfuncao, limitetitf);
        }

if(v==38){
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_compmin_individual_4_count(DNI,datetime,contadorinicialfuncao, limitetitf);
        }

if(v==39){
        cout<<"Precipitation (mm)"<<endl;
        imprimir_compmin_individual_4_count(Precipitation,datetime,contadorinicialfuncao, limitetitf);
        }

if(v==40){
        cout<<"Precipitation (mm)"<<endl;
        imprimir_compmin_individual_4_sum(Precipitation,datetime,contadorinicialfuncao, limitetitf);
        }
if(v==41){
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_compmin_individual_4_avg(GTI,datetime,contadorinicialfuncao, limitetitf);
        }

if(v==42){
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_compmin_individual_4_max(GTI,datetime,contadorinicialfuncao, limitetitf);
        }

if(v==43){
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_compmin_individual_4_min(GTI,datetime,contadorinicialfuncao, limitetitf);
        }

if(v==44){
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_compmin_individual_4_stddev(GTI,datetime,contadorinicialfuncao, limitetitf);
        }
if(v==45){
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_compmin_individual_4_count(GTI,datetime,contadorinicialfuncao, limitetitf);
        }

        //acaba a parte de dam
        if(v==46){
        cout<<"A1 channel (V)"<<endl;
        imprimir_compmin_individual_4_avg(A1,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==47){
        cout<<"A1 channel (V)"<<endl;
        imprimir_compmin_individual_4_max(A1,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==48){
        cout<<"A1 channel (V)"<<endl;
        imprimir_compmin_individual_4_min(A1,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==49){
        cout<<"A1 channel (V)"<<endl;
        imprimir_compmin_individual_4_stddev(A1,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==50){
        cout<<"A2 channel (V)"<<endl;
        imprimir_compmin_individual_4_avg(A2,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==51){
        cout<<"A2 channel (V)"<<endl;
        imprimir_compmin_individual_4_max(A2,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==52){
        cout<<"A2 channel (V)"<<endl;
        imprimir_compmin_individual_4_min(A2,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==53){
        cout<<"A2 channel (V)"<<endl;
        imprimir_compmin_individual_4_stddev(A2,datetime,contadorinicialfuncao, limitetitf);
        }

        if(v==54){
        cout<<"A3 channel (V)"<<endl;
        imprimir_compmin_individual_4_avg(A3,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==55){
        cout<<"A3 channel (V)"<<endl;
        imprimir_compmin_individual_4_max(A3,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==56){
        cout<<"A3 channel (V)"<<endl;
        imprimir_compmin_individual_4_min(A3,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==57){
        cout<<"A3 channel (V)"<<endl;
        imprimir_compmin_individual_4_stddev(A3,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==58){
        cout<<"A4 channel (V)"<<endl;
        imprimir_compmin_individual_4_avg(A4,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==59){
        cout<<"A4 channel (V)"<<endl;
        imprimir_compmin_individual_4_max(A4,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==60){
        cout<<"A4 channel (V)"<<endl;
        imprimir_compmin_individual_4_min(A4,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==61){
        cout<<"A4 channel (V)"<<endl;
        imprimir_compmin_individual_4_stddev(A4,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==62){
        cout<<"A5 channel (V)"<<endl;
        imprimir_compmin_individual_4_avg(A5,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==63){
        cout<<"A5 channel (V)"<<endl;
        imprimir_compmin_individual_4_max(A5,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==64){
        cout<<"A5 channel (V)"<<endl;
        imprimir_compmin_individual_4_min(A5,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==65){
        cout<<"A5 channel (V)"<<endl;
        imprimir_compmin_individual_4_stddev(A5,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==66){
        cout<<"A6 channel (V)"<<endl;
        imprimir_compmin_individual_4_avg(A6,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==67){
        cout<<"A6 channel (V)"<<endl;
        imprimir_compmin_individual_4_max(A6,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==68){
        cout<<"A6 channel (V)"<<endl;
        imprimir_compmin_individual_4_min(A6,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==69){
        cout<<"A6 channel (V)"<<endl;
        imprimir_compmin_individual_4_stddev(A6,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==70){
        cout<<"A7 channel (V)"<<endl;
        imprimir_compmin_individual_4_avg(A7,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==71){
        cout<<"A7 channel (V)"<<endl;
        imprimir_compmin_individual_4_max(A7,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==72){
        cout<<"A7 channel (V)"<<endl;
        imprimir_compmin_individual_4_min(A7,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==73){
        cout<<"A7 channel (V)"<<endl;
        imprimir_compmin_individual_4_stddev(A7,datetime,contadorinicialfuncao, limitetitf);
        }//damiao começa
if(v==74){
        cout<<"C1 channel (V)"<<endl;
        imprimir_compmin_individual_4_avg(C1,datetime,contadorinicialfuncao, limitetitf);
        }

if(v==75){
        cout<<"C1 channel (V)"<<endl;
        imprimir_compmin_individual_4_max(C1,datetime,contadorinicialfuncao, limitetitf);
        }

if(v==76){
        cout<<"C1 channel (V)"<<endl;
        imprimir_compmin_individual_4_min(C1,datetime,contadorinicialfuncao, limitetitf);
        }
if(v==77){
        cout<<"C1 channel (V)"<<endl;
        imprimir_compmin_individual_4_stddev(C1,datetime,contadorinicialfuncao, limitetitf);
        }

if(v==78){
        cout<<"C2 channel (V)"<<endl;
        imprimir_compmin_individual_4_avg(C2,datetime,contadorinicialfuncao, limitetitf);
        }

if(v==79){
        cout<<"C2 channel (V)"<<endl;
        imprimir_compmin_individual_4_max(C2,datetime,contadorinicialfuncao, limitetitf);
        }

if(v==80){
        cout<<"C2 channel (V)"<<endl;
        imprimir_compmin_individual_4_min(C2,datetime,contadorinicialfuncao, limitetitf);
        }

if(v==81){
        cout<<"C2 channel (V)"<<endl;
        imprimir_compmin_individual_4_stddev(C2,datetime,contadorinicialfuncao, limitetitf);
        }

if(v==82){
        cout<<"D1 channel (V)"<<endl;
        imprimir_compmin_individual_4_avg(D1,datetime,contadorinicialfuncao, limitetitf);
        }

if(v==83){
        cout<<"D1 channel (V)"<<endl;
        imprimir_compmin_individual_4_max(D1,datetime,contadorinicialfuncao, limitetitf);
        }

if(v==84){
        cout<<"D1 channel (V)"<<endl;
        imprimir_compmin_individual_4_min(D1,datetime,contadorinicialfuncao, limitetitf);
        }
if(v==85){
        cout<<"D1 channel (V)"<<endl;
        imprimir_compmin_individual_4_stddev(D1,datetime,contadorinicialfuncao, limitetitf);
        }

if(v==86){
        cout<<"T channel (AC)"<<endl;
        imprimir_compmin_individual_4_avg(T,datetime,contadorinicialfuncao, limitetitf);
        }

if(v==86){
        cout<<"T channel (AC)"<<endl;
        imprimir_compmin_individual_4_avg(T,datetime,contadorinicialfuncao, limitetitf);
        }

if(v==87){
        cout<<"I channel (mA)"<<endl;
        imprimir_compmin_individual_4_avg(I,datetime,contadorinicialfuncao, limitetitf);
        }

if(v==88){
        cout<<"I channel (mA)"<<endl;
        imprimir_compmin_individual_4_max(I,datetime,contadorinicialfuncao, limitetitf);
        }

if(v==89){
        cout<<"I channel (mA)"<<endl;
        imprimir_compmin_individual_4_min(I,datetime,contadorinicialfuncao, limitetitf);
        }
        //damiao acaba
        if(v==90){
        cout<<"V channel (V)"<<endl;
        imprimir_compmin_individual_4_avg(V,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==91){
        cout<<"V channel (V)"<<endl;
        imprimir_compmin_individual_4_max(V,datetime,contadorinicialfuncao, limitetitf);
        }
        if(v==92){
        cout<<"V channel (V)"<<endl;
        imprimir_compmin_individual_4_min(V,datetime,contadorinicialfuncao , limitetitf);
        }
}//fim da condição vmin




}






// comando N + V + vmax + vmin
if(n!=0 && v!=0 && condicao1questao3==0 && t==0){
int titf=0;
while (titf<n){
        if(v==1){
        cout<<"Anemoneter wind speed average(m/s)"<<endl;
        imprimir_individual_1_avg(Anemoneter,datetime,titf);
        }
        if(v==2 && vmax){
        cout<<"Anemoneter wind speed max(m/s)"<<endl;
        imprimir_individual_1_max(Anemoneter,datetime,titf);
        }
        if(v==3){
        cout<<"Anemoneter wind speed min(m/s)"<<endl;
        imprimir_individual_1_min(Anemoneter,datetime,titf);
        }
        if(v==4){
        cout<<"Anemoneter wind speed min(m/s)"<<endl;
        imprimir_individual_1_stddev(Anemoneter,datetime,titf);
        }
        if(v==5){
        cout<<"Anemoneter wind speed min(m/s)"<<endl;
        imprimir_individual_1_count(Anemoneter,datetime,titf);
        }
        
        if(v==6){
        cout<<"Wind Vane TMR wind direction (A)"<<endl;
        imprimir_individual_1_avg(Wind_Vane,datetime,titf);
        }
        if(v==7){
        cout<<"Wind Vane TMR wind direction (A)"<<endl;
        imprimir_individual_1_stddev(Wind_Vane,datetime,titf);
        }
        if(v==8){
        cout<<"Wind Vane TMR wind direction (A)"<<endl;
        imprimir_individual_1_count(Wind_Vane,datetime,titf);
        }
        
        if(v==9){
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_individual_1_avg(Thermo_Hum,datetime,titf);
        }
        if(v==10){
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_individual_1_max(Thermo_Hum,datetime,titf);
        }
        if(v==11){
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_individual_1_min(Thermo_Hum,datetime,titf);
        }
        if(v==12){
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_individual_1_stddev(Thermo_Hum,datetime,titf);
        }
        if(v==13){
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_individual_1_count(Thermo_Hum,datetime,titf);
        }
        if(v==14){
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_individual_1_avg(Thermo_Temp,datetime,titf);
        }
        if(v==15){
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_individual_1_max(Thermo_Temp,datetime,titf);
        }
        if(v==16){
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_individual_1_min(Thermo_Temp,datetime,titf);
        }
        if(v==17){
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_individual_1_stddev(Thermo_Temp,datetime,titf);
        }
        if(v==18){
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_individual_1_count(Thermo_Temp,datetime,titf);
        }
        if(v==19){
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_individual_1_avg(Barometer,datetime,titf);
        }
        if(v==20){
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_individual_1_max(Barometer,datetime,titf);
        }
        if(v==21){
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_individual_1_min(Barometer,datetime,titf);
        }
        if(v==22){
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_individual_1_stddev(Barometer,datetime,titf);
        }
        if(v==23){
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_individual_1_count(Barometer,datetime,titf);
        }

        if(v==24){
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_individual_1_avg(DHI,datetime,titf);
        }
        if(v==25){
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_individual_1_max(DHI,datetime,titf);
        }if(v==26){
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_individual_1_min(DHI,datetime,titf);
        }
        if(v==27){
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_individual_1_stddev(DHI,datetime,titf);
        }if(v==28){
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_individual_1_count(DHI,datetime,titf);
        }
        //começa dam
     if(v==29){
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_individual_1_avg(GHI,datetime,titf);
        }

 if(v==30){
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_individual_1_max(GHI,datetime,titf);
        }

 if(v==31){
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_individual_1_min(GHI,datetime,titf);
        }

if(v==32){
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_individual_1_stddev(GHI,datetime,titf);
        }

if(v==33){
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_individual_1_count(GHI,datetime,titf);
        }

if(v==34){
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_individual_1_avg(DNI,datetime,titf);
        }
if(v==35){
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_individual_1_max(DNI,datetime,titf);
        }

if(v==36){
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_individual_1_min(DNI,datetime,titf);
        }

if(v==37){
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_individual_1_stddev(DNI,datetime,titf);
        }

if(v==38){
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_individual_1_count(DNI,datetime,titf);
        }

if(v==39){
        cout<<"Precipitation (mm)"<<endl;
        imprimir_individual_1_count(Precipitation,datetime,titf);
        }

if(v==40){
        cout<<"Precipitation (mm)"<<endl;
        imprimir_individual_1_sum(Precipitation,datetime,titf);
        }
if(v==41){
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_individual_1_avg(GTI,datetime,titf);
        }

if(v==42){
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_individual_1_max(GTI,datetime,titf);
        }

if(v==43){
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_individual_1_min(GTI,datetime,titf);
        }

if(v==44){
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_individual_1_stddev(GTI,datetime,titf);
        }
        if(v==45){
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_individual_1_count(GTI,datetime,titf);
        }
        if(v==46){
        cout<<"A1 channel (V)"<<endl;
        imprimir_individual_1_avg(A1,datetime,titf);
        }
        if(v==47){
        cout<<"A1 channel (V)"<<endl;
        imprimir_individual_1_max(A1,datetime,titf);
        }
        if(v==48){
        cout<<"A1 channel (V)"<<endl;
        imprimir_individual_1_min(A1,datetime,titf);
        }
        if(v==49){
        cout<<"A1 channel (V)"<<endl;
        imprimir_individual_1_stddev(A1,datetime,titf);
        }
        if(v==50){
        cout<<"A2 channel (V)"<<endl;
        imprimir_individual_1_avg(A2,datetime,titf);
        }
        if(v==51){
        cout<<"A2 channel (V)"<<endl;
        imprimir_individual_1_max(A2,datetime,titf);
        }
        if(v==52){
        cout<<"A2 channel (V)"<<endl;
        imprimir_individual_1_min(A2,datetime,titf);
        }
        if(v==53){
        cout<<"A2 channel (V)"<<endl;
        imprimir_individual_1_stddev(A2,datetime,titf);
        }

        if(v==54){
        cout<<"A3 channel (V)"<<endl;
        imprimir_individual_1_avg(A3,datetime,titf);
        }
        if(v==55){
        cout<<"A3 channel (V)"<<endl;
        imprimir_individual_1_max(A3,datetime,titf);
        }
        if(v==56){
        cout<<"A3 channel (V)"<<endl;
        imprimir_individual_1_min(A3,datetime,titf);
        }
        if(v==57){
        cout<<"A3 channel (V)"<<endl;
        imprimir_individual_1_stddev(A3,datetime,titf);
        }
        if(v==58){
        cout<<"A4 channel (V)"<<endl;
        imprimir_individual_1_avg(A4,datetime,titf);
        }
        if(v==59){
        cout<<"A4 channel (V)"<<endl;
        imprimir_individual_1_max(A4,datetime,titf);
        }
        if(v==60){
        cout<<"A4 channel (V)"<<endl;
        imprimir_individual_1_min(A4,datetime,titf);
        }
        if(v==61){
        cout<<"A4 channel (V)"<<endl;
        imprimir_individual_1_stddev(A4,datetime,titf);
        }
        if(v==62){
        cout<<"A5 channel (V)"<<endl;
        imprimir_individual_1_avg(A5,datetime,titf);
        }
        if(v==63){
        cout<<"A5 channel (V)"<<endl;
        imprimir_individual_1_max(A5,datetime,titf);
        }
        if(v==64){
        cout<<"A5 channel (V)"<<endl;
        imprimir_individual_1_min(A5,datetime,titf);
        }
        if(v==65){
        cout<<"A5 channel (V)"<<endl;
        imprimir_individual_1_stddev(A5,datetime,titf);
        }
        if(v==66){
        cout<<"A6 channel (V)"<<endl;
        imprimir_individual_1_avg(A6,datetime,titf);
        }
        if(v==67){
        cout<<"A6 channel (V)"<<endl;
        imprimir_individual_1_max(A6,datetime,titf);
        }
        if(v==68){
        cout<<"A6 channel (V)"<<endl;
        imprimir_individual_1_min(A6,datetime,titf);
        }
        if(v==69){
        cout<<"A6 channel (V)"<<endl;
        imprimir_individual_1_stddev(A6,datetime,titf);
        }
        if(v==70){
        cout<<"A7 channel (V)"<<endl;
        imprimir_individual_1_avg(A7,datetime,titf);
        }
        if(v==71){
        cout<<"A7 channel (V)"<<endl;
        imprimir_individual_1_max(A7,datetime,titf);
        }
        if(v==72){
        cout<<"A7 channel (V)"<<endl;
        imprimir_individual_1_min(A7,datetime,titf);
        }
        if(v==73){
        cout<<"A7 channel (V)"<<endl;
        imprimir_individual_1_stddev(A7,datetime,titf);
        }//damiao começa
if(v==74){
        cout<<"C1 channel (V)"<<endl;
        imprimir_individual_1_avg(C1,datetime,titf);
        }

if(v==75){
        cout<<"C1 channel (V)"<<endl;
        imprimir_individual_1_max(C1,datetime,titf);
        }

if(v==76){
        cout<<"C1 channel (V)"<<endl;
        imprimir_individual_1_min(C1,datetime,titf);
        }
if(v==77){
        cout<<"C1 channel (V)"<<endl;
        imprimir_individual_1_stddev(C1,datetime,titf);
        }

if(v==78){
        cout<<"C2 channel (V)"<<endl;
        imprimir_individual_1_avg(C2,datetime,titf);
        }

if(v==79){
        cout<<"C2 channel (V)"<<endl;
        imprimir_individual_1_max(C2,datetime,titf);
        }

if(v==80){
        cout<<"C2 channel (V)"<<endl;
        imprimir_individual_1_min(C2,datetime,titf);
        }

if(v==81){
        cout<<"C2 channel (V)"<<endl;
        imprimir_individual_1_stddev(C2,datetime,titf);
        }

if(v==82){
        cout<<"D1 channel (V)"<<endl;
        imprimir_individual_1_avg(D1,datetime,titf);
        }

if(v==83){
        cout<<"D1 channel (V)"<<endl;
        imprimir_individual_1_max(D1,datetime,titf);
        }

if(v==84){
        cout<<"D1 channel (V)"<<endl;
        imprimir_individual_1_min(D1,datetime,titf);
        }
if(v==85){
        cout<<"D1 channel (V)"<<endl;
        imprimir_individual_1_stddev(D1,datetime,titf);
        }

if(v==86){
        cout<<"T channel (AC)"<<endl;
        imprimir_individual_1_avg(T,datetime,titf);
        }

if(v==86){
        cout<<"T channel (AC)"<<endl;
        imprimir_individual_1_avg(T,datetime,titf);
        }

if(v==87){
        cout<<"I channel (mA)"<<endl;
        imprimir_individual_1_avg(I,datetime,titf);
        }

if(v==88){
        cout<<"I channel (mA)"<<endl;
        imprimir_individual_1_max(I,datetime,titf);
        }

if(v==89){
        cout<<"I channel (mA)"<<endl;
        imprimir_individual_1_min(I,datetime,titf);
        }

        if(v==90){
        cout<<"V channel (V)"<<endl;
        imprimir_individual_1_avg(V,datetime,titf);
        }
        if(v==91){
        cout<<"V channel (V)"<<endl;
        imprimir_individual_1_max(V,datetime,titf);
        }
        if(v==92){
        cout<<"V channel (V)"<<endl;
        imprimir_individual_1_min(V,datetime,titf);
        }
titf++;
} //fim do while
//condição de vmax
        if(vmax==1){
        if(v==1){
        cout<<"Anemoneter wind speed average(m/s)"<<endl;
        imprimir_compmax_individual_3_avg(Anemoneter,datetime,n);
        }
        if(v==2){
        cout<<"Anemoneter wind speed max(m/s)"<<endl;
        imprimir_compmax_individual_3_max(Anemoneter,datetime,n);
        }
        if(v==3){
        cout<<"Anemoneter wind speed min(m/s)"<<endl;
        imprimir_compmax_individual_3_min(Anemoneter,datetime,n);
        }
        if(v==4){
        cout<<"Anemoneter wind speed min(m/s)"<<endl;
        imprimir_compmax_individual_3_stddev(Anemoneter,datetime,n);
        }
        if(v==5){
        cout<<"Anemoneter wind speed min(m/s)"<<endl;
        imprimir_compmax_individual_3_count(Anemoneter,datetime,n);
        }
        
        if(v==6){
        cout<<"Wind Vane TMR wind direction (A)"<<endl;
        imprimir_compmax_individual_3_avg(Wind_Vane,datetime,n);
        }
        if(v==7){
        cout<<"Wind Vane TMR wind direction (A)"<<endl;
        imprimir_compmax_individual_3_stddev(Wind_Vane,datetime,n);
        }
        if(v==8){
        cout<<"Wind Vane TMR wind direction (A)"<<endl;
        imprimir_compmax_individual_3_count(Wind_Vane,datetime,n);
        }
        
        if(v==9){
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_compmax_individual_3_avg(Thermo_Hum,datetime,n);
        }
        if(v==10){
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_compmax_individual_3_max(Thermo_Hum,datetime,n);
        }
        if(v==11){
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_compmax_individual_3_min(Thermo_Hum,datetime,n);
        }
        if(v==12){
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_compmax_individual_3_stddev(Thermo_Hum,datetime,n);
        }
        if(v==13){
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_compmax_individual_3_count(Thermo_Hum,datetime,n);
        }
        if(v==14){
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_compmax_individual_3_avg(Thermo_Temp,datetime,n);
        }
        if(v==15){
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_compmax_individual_3_max(Thermo_Temp,datetime,n);
        }
        if(v==16){
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_compmax_individual_3_min(Thermo_Temp,datetime,n);
        }
        if(v==17){
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_compmax_individual_3_stddev(Thermo_Temp,datetime,n);
        }
        if(v==18){
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_compmax_individual_3_count(Thermo_Temp,datetime,n);
        }
        if(v==19){
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_compmax_individual_3_avg(Barometer,datetime,n);
        }
        if(v==20){
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_compmax_individual_3_max(Barometer,datetime,n);
        }
        if(v==21){
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_compmax_individual_3_min(Barometer,datetime,n);
        }
        if(v==22){
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_compmax_individual_3_stddev(Barometer,datetime,n);
        }
        if(v==23){
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_compmax_individual_3_count(Barometer,datetime,n);
        }

        if(v==24){
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmax_individual_3_avg(DHI,datetime,n);
        }
        if(v==25){
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmax_individual_3_max(DHI,datetime,n);
        }if(v==26){
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmax_individual_3_min(DHI,datetime,n);
        }
        if(v==27){
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmax_individual_3_stddev(DHI,datetime,n);
        }if(v==28){
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmax_individual_3_count(DHI,datetime,n);
        }
        //começa dam
     if(v==29){
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmax_individual_3_avg(GHI,datetime,n);
        }

 if(v==30){
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmax_individual_3_max(GHI,datetime,n);
        }

 if(v==31){
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmax_individual_3_min(GHI,datetime,n);
        }

if(v==32){
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmax_individual_3_stddev(GHI,datetime,n);
        }

if(v==33){
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmax_individual_3_count(GHI,datetime,n);
        }

if(v==34){
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_compmax_individual_3_avg(DNI,datetime,n);
        }
if(v==35){
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_compmax_individual_3_max(DNI,datetime,n);
        }

if(v==36){
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_compmax_individual_3_min(DNI,datetime,n);
        }

if(v==37){
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_compmax_individual_3_stddev(DNI,datetime,n);
        }

if(v==38){
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_compmax_individual_3_count(DNI,datetime,n);
        }

if(v==39){
        cout<<"Precipitation (mm)"<<endl;
        imprimir_compmax_individual_3_count(Precipitation,datetime,n);
        }

if(v==40){
        cout<<"Precipitation (mm)"<<endl;
        imprimir_compmax_individual_3_sum(Precipitation,datetime,n);
        }
if(v==41){
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_compmax_individual_3_avg(GTI,datetime,n);
        }

if(v==42){
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_compmax_individual_3_max(GTI,datetime,n);
        }

if(v==43){
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_compmax_individual_3_min(GTI,datetime,n);
        }

if(v==44){
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_compmax_individual_3_stddev(GTI,datetime,n);
        }
if(v==45){
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_compmax_individual_3_count(GTI,datetime,n);
        }

      
        if(v==46){
        cout<<"A1 channel (V)"<<endl;
        imprimir_compmax_individual_3_avg(A1,datetime,n);
        }
        if(v==47){
        cout<<"A1 channel (V)"<<endl;
        imprimir_compmax_individual_3_max(A1,datetime,n);
        }
        if(v==48){
        cout<<"A1 channel (V)"<<endl;
        imprimir_compmax_individual_3_min(A1,datetime,n);
        }
        if(v==49){
        cout<<"A1 channel (V)"<<endl;
        imprimir_compmax_individual_3_stddev(A1,datetime,n);
        }
        if(v==50){
        cout<<"A2 channel (V)"<<endl;
        imprimir_compmax_individual_3_avg(A2,datetime,n);
        }
        if(v==51){
        cout<<"A2 channel (V)"<<endl;
        imprimir_compmax_individual_3_max(A2,datetime,n);
        }
        if(v==52){
        cout<<"A2 channel (V)"<<endl;
        imprimir_compmax_individual_3_min(A2,datetime,n);
        }
        if(v==53){
        cout<<"A2 channel (V)"<<endl;
        imprimir_compmax_individual_3_stddev(A2,datetime,n);
        }

        if(v==54){
        cout<<"A3 channel (V)"<<endl;
        imprimir_compmax_individual_3_avg(A3,datetime,n);
        }
        if(v==55){
        cout<<"A3 channel (V)"<<endl;
        imprimir_compmax_individual_3_max(A3,datetime,n);
        }
        if(v==56){
        cout<<"A3 channel (V)"<<endl;
        imprimir_compmax_individual_3_min(A3,datetime,n);
        }
        if(v==57){
        cout<<"A3 channel (V)"<<endl;
        imprimir_compmax_individual_3_stddev(A3,datetime,n);
        }
        if(v==58){
        cout<<"A4 channel (V)"<<endl;
        imprimir_compmax_individual_3_avg(A4,datetime,n);
        }
        if(v==59){
        cout<<"A4 channel (V)"<<endl;
        imprimir_compmax_individual_3_max(A4,datetime,n);
        }
        if(v==60){
        cout<<"A4 channel (V)"<<endl;
        imprimir_compmax_individual_3_min(A4,datetime,n);
        }
        if(v==61){
        cout<<"A4 channel (V)"<<endl;
        imprimir_compmax_individual_3_stddev(A4,datetime,n);
        }
        if(v==62){
        cout<<"A5 channel (V)"<<endl;
        imprimir_compmax_individual_3_avg(A5,datetime,n);
        }
        if(v==63){
        cout<<"A5 channel (V)"<<endl;
        imprimir_compmax_individual_3_max(A5,datetime,n);
        }
        if(v==64){
        cout<<"A5 channel (V)"<<endl;
        imprimir_compmax_individual_3_min(A5,datetime,n);
        }
        if(v==65){
        cout<<"A5 channel (V)"<<endl;
        imprimir_compmax_individual_3_stddev(A5,datetime,n);
        }
        if(v==66){
        cout<<"A6 channel (V)"<<endl;
        imprimir_compmax_individual_3_avg(A6,datetime,n);
        }
        if(v==67){
        cout<<"A6 channel (V)"<<endl;
        imprimir_compmax_individual_3_max(A6,datetime,n);
        }
        if(v==68){
        cout<<"A6 channel (V)"<<endl;
        imprimir_compmax_individual_3_min(A6,datetime,n);
        }
        if(v==69){
        cout<<"A6 channel (V)"<<endl;
        imprimir_compmax_individual_3_stddev(A6,datetime,n);
        }
        if(v==70){
        cout<<"A7 channel (V)"<<endl;
        imprimir_compmax_individual_3_avg(A7,datetime,n);
        }
        if(v==71){
        cout<<"A7 channel (V)"<<endl;
        imprimir_compmax_individual_3_max(A7,datetime,n);
        }
        if(v==72){
        cout<<"A7 channel (V)"<<endl;
        imprimir_compmax_individual_3_min(A7,datetime,n);
        }
        if(v==73){
        cout<<"A7 channel (V)"<<endl;
        imprimir_compmax_individual_3_stddev(A7,datetime,n);
        }
if(v==74){
        cout<<"C1 channel (V)"<<endl;
        imprimir_compmax_individual_3_avg(C1,datetime,n);
        }

if(v==75){
        cout<<"C1 channel (V)"<<endl;
        imprimir_compmax_individual_3_max(C1,datetime,n);
        }

if(v==76){
        cout<<"C1 channel (V)"<<endl;
        imprimir_compmax_individual_3_min(C1,datetime,n);
        }
if(v==77){
        cout<<"C1 channel (V)"<<endl;
        imprimir_compmax_individual_3_stddev(C1,datetime,n);
        }

if(v==78){
        cout<<"C2 channel (V)"<<endl;
        imprimir_compmax_individual_3_avg(C2,datetime,n);
        }

if(v==79){
        cout<<"C2 channel (V)"<<endl;
        imprimir_compmax_individual_3_max(C2,datetime,n);
        }

if(v==80){
        cout<<"C2 channel (V)"<<endl;
        imprimir_compmax_individual_3_min(C2,datetime,n);
        }

if(v==81){
        cout<<"C2 channel (V)"<<endl;
        imprimir_compmax_individual_3_stddev(C2,datetime,n);
        }

if(v==82){
        cout<<"D1 channel (V)"<<endl;
        imprimir_compmax_individual_3_avg(D1,datetime,n);
        }

if(v==83){
        cout<<"D1 channel (V)"<<endl;
        imprimir_compmax_individual_3_max(D1,datetime,n);
        }

if(v==84){
        cout<<"D1 channel (V)"<<endl;
        imprimir_compmax_individual_3_min(D1,datetime,n);
        }
if(v==85){
        cout<<"D1 channel (V)"<<endl;
        imprimir_compmax_individual_3_stddev(D1,datetime,n);
        }

if(v==86){
        cout<<"T channel (AC)"<<endl;
        imprimir_compmax_individual_3_avg(T,datetime,n);
        }

if(v==86){
        cout<<"T channel (AC)"<<endl;
        imprimir_compmax_individual_3_avg(T,datetime,n);
        }

if(v==87){
        cout<<"I channel (mA)"<<endl;
        imprimir_compmax_individual_3_avg(I,datetime,n);
        }

if(v==88){
        cout<<"I channel (mA)"<<endl;
        imprimir_compmax_individual_3_max(I,datetime,n);
        }

if(v==89){
        cout<<"I channel (mA)"<<endl;
        imprimir_compmax_individual_3_min(I,datetime,n);
        }

        if(v==90){
        cout<<"V channel (V)"<<endl;
        imprimir_compmax_individual_3_avg(V,datetime,n);
        }
        if(v==91){
        cout<<"V channel (V)"<<endl;
        imprimir_compmax_individual_3_max(V,datetime,n);
        }
        if(v==92){
        cout<<"V channel (V)"<<endl;
        imprimir_compmax_individual_3_min(V,datetime,n);
        }
}
//fim do if vmax
//começo do if vmin
if(vmin==1){
        if(v==1){
        cout<<"Anemoneter wind speed average(m/s)"<<endl;
        imprimir_compmin_individual_3_avg(Anemoneter,datetime,n);
        }
        if(v==2){
        cout<<"Anemoneter wind speed max(m/s)"<<endl;
        imprimir_compmin_individual_3_max(Anemoneter,datetime,n);
        }
        if(v==3){
        cout<<"Anemoneter wind speed min(m/s)"<<endl;
        imprimir_compmin_individual_3_min(Anemoneter,datetime,n);
        }
        if(v==4){
        cout<<"Anemoneter wind speed min(m/s)"<<endl;
        imprimir_compmin_individual_3_stddev(Anemoneter,datetime,n);
        }
        if(v==5){
        cout<<"Anemoneter wind speed min(m/s)"<<endl;
        imprimir_compmin_individual_3_count(Anemoneter,datetime,n);
        }
        
        if(v==6){
        cout<<"Wind Vane TMR wind direction (A)"<<endl;
        imprimir_compmin_individual_3_avg(Wind_Vane,datetime,n);
        }
        if(v==7){
        cout<<"Wind Vane TMR wind direction (A)"<<endl;
        imprimir_compmin_individual_3_stddev(Wind_Vane,datetime,n);
        }
        if(v==8){
        cout<<"Wind Vane TMR wind direction (A)"<<endl;
        imprimir_compmin_individual_3_count(Wind_Vane,datetime,n);
        }
        
        if(v==9){
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_compmin_individual_3_avg(Thermo_Hum,datetime,n);
        }
        if(v==10){
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_compmin_individual_3_max(Thermo_Hum,datetime,n);
        }
        if(v==11){
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_compmin_individual_3_min(Thermo_Hum,datetime,n);
        }
        if(v==12){
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_compmin_individual_3_stddev(Thermo_Hum,datetime,n);
        }
        if(v==13){
        cout<<"Hydro/Thermo humidity (%)"<<endl;
        imprimir_compmin_individual_3_count(Thermo_Hum,datetime,n);
        }
        if(v==14){
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_compmin_individual_3_avg(Thermo_Temp,datetime,n);
        }
        if(v==15){
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_compmin_individual_3_max(Thermo_Temp,datetime,n);
        }
        if(v==16){
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_compmin_individual_3_min(Thermo_Temp,datetime,n);
        }
        if(v==17){
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_compmin_individual_3_stddev(Thermo_Temp,datetime,n);
        }
        if(v==18){
        cout<<"Hydro/Thermo temperature (AC)"<<endl;
        imprimir_compmin_individual_3_count(Thermo_Temp,datetime,n);
        }
        if(v==19){
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_compmin_individual_3_avg(Barometer,datetime,n);
        }
        if(v==20){
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_compmin_individual_3_max(Barometer,datetime,n);
        }
        if(v==21){
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_compmin_individual_3_min(Barometer,datetime,n);
        }
        if(v==22){
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_compmin_individual_3_stddev(Barometer,datetime,n);
        }
        if(v==23){
        cout<<"Barometer air pressure (hPa)"<<endl;
        imprimir_compmin_individual_3_count(Barometer,datetime,n);
        }

        if(v==24){
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmin_individual_3_avg(DHI,datetime,n);
        }
        if(v==25){
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmin_individual_3_max(DHI,datetime,n);
        }if(v==26){
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmin_individual_3_min(DHI,datetime,n);
        }
        if(v==27){
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmin_individual_3_stddev(DHI,datetime,n);
        }if(v==28){
        cout<<"DHI (Diffuse Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmin_individual_3_count(DHI,datetime,n);
        }
        //começa dam
     if(v==29){
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmin_individual_3_avg(GHI,datetime,n);
        }

 if(v==30){
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmin_individual_3_max(GHI,datetime,n);
        }

 if(v==31){
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmin_individual_3_min(GHI,datetime,n);
        }

if(v==32){
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmin_individual_3_stddev(GHI,datetime,n);
        }

if(v==33){
        cout<<"GHI (Global Horizontal Irradiance) (W/mA2)"<<endl;
        imprimir_compmin_individual_3_count(GHI,datetime,n);
        }

if(v==34){
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_compmin_individual_3_avg(DNI,datetime,n);
        }
if(v==35){
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_compmin_individual_3_max(DNI,datetime,n);
        }

if(v==36){
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_compmin_individual_3_min(DNI,datetime,n);
        }

if(v==37){
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_compmin_individual_3_stddev(DNI,datetime,n);
        }

if(v==38){
        cout<<"DNI (Direct Normal Irradiance) Pyrheliometer (W/mA2)"<<endl;
        imprimir_compmin_individual_3_count(DNI,datetime,n);
        }

if(v==39){
        cout<<"Precipitation (mm)"<<endl;
        imprimir_compmin_individual_3_count(Precipitation,datetime,n);
        }

if(v==40){
        cout<<"Precipitation (mm)"<<endl;
        imprimir_compmin_individual_3_sum(Precipitation,datetime,n);
        }
if(v==41){
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_compmin_individual_3_avg(GTI,datetime,n);
        }

if(v==42){
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_compmin_individual_3_max(GTI,datetime,n);
        }

if(v==43){
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_compmin_individual_3_min(GTI,datetime,n);
        }

if(v==44){
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_compmin_individual_3_stddev(GTI,datetime,n);
        }
if(v==45){
        cout<<"GTI (Global Tilt Irradiance) PV Cell voltage (W/m2)"<<endl;
        imprimir_compmin_individual_3_count(GTI,datetime,n);
        }

      
        if(v==46){
        cout<<"A1 channel (V)"<<endl;
        imprimir_compmin_individual_3_avg(A1,datetime,n);
        }
        if(v==47){
        cout<<"A1 channel (V)"<<endl;
        imprimir_compmin_individual_3_max(A1,datetime,n);
        }
        if(v==48){
        cout<<"A1 channel (V)"<<endl;
        imprimir_compmin_individual_3_min(A1,datetime,n);
        }
        if(v==49){
        cout<<"A1 channel (V)"<<endl;
        imprimir_compmin_individual_3_stddev(A1,datetime,n);
        }
        if(v==50){
        cout<<"A2 channel (V)"<<endl;
        imprimir_compmin_individual_3_avg(A2,datetime,n);
        }
        if(v==51){
        cout<<"A2 channel (V)"<<endl;
        imprimir_compmin_individual_3_max(A2,datetime,n);
        }
        if(v==52){
        cout<<"A2 channel (V)"<<endl;
        imprimir_compmin_individual_3_min(A2,datetime,n);
        }
        if(v==53){
        cout<<"A2 channel (V)"<<endl;
        imprimir_compmin_individual_3_stddev(A2,datetime,n);
        }

        if(v==54){
        cout<<"A3 channel (V)"<<endl;
        imprimir_compmin_individual_3_avg(A3,datetime,n);
        }
        if(v==55){
        cout<<"A3 channel (V)"<<endl;
        imprimir_compmin_individual_3_max(A3,datetime,n);
        }
        if(v==56){
        cout<<"A3 channel (V)"<<endl;
        imprimir_compmin_individual_3_min(A3,datetime,n);
        }
        if(v==57){
        cout<<"A3 channel (V)"<<endl;
        imprimir_compmin_individual_3_stddev(A3,datetime,n);
        }
        if(v==58){
        cout<<"A4 channel (V)"<<endl;
        imprimir_compmin_individual_3_avg(A4,datetime,n);
        }
        if(v==59){
        cout<<"A4 channel (V)"<<endl;
        imprimir_compmin_individual_3_max(A4,datetime,n);
        }
        if(v==60){
        cout<<"A4 channel (V)"<<endl;
        imprimir_compmin_individual_3_min(A4,datetime,n);
        }
        if(v==61){
        cout<<"A4 channel (V)"<<endl;
        imprimir_compmin_individual_3_stddev(A4,datetime,n);
        }
        if(v==62){
        cout<<"A5 channel (V)"<<endl;
        imprimir_compmin_individual_3_avg(A5,datetime,n);
        }
        if(v==63){
        cout<<"A5 channel (V)"<<endl;
        imprimir_compmin_individual_3_max(A5,datetime,n);
        }
        if(v==64){
        cout<<"A5 channel (V)"<<endl;
        imprimir_compmin_individual_3_min(A5,datetime,n);
        }
        if(v==65){
        cout<<"A5 channel (V)"<<endl;
        imprimir_compmin_individual_3_stddev(A5,datetime,n);
        }
        if(v==66){
        cout<<"A6 channel (V)"<<endl;
        imprimir_compmin_individual_3_avg(A6,datetime,n);
        }
        if(v==67){
        cout<<"A6 channel (V)"<<endl;
        imprimir_compmin_individual_3_max(A6,datetime,n);
        }
        if(v==68){
        cout<<"A6 channel (V)"<<endl;
        imprimir_compmin_individual_3_min(A6,datetime,n);
        }
        if(v==69){
        cout<<"A6 channel (V)"<<endl;
        imprimir_compmin_individual_3_stddev(A6,datetime,n);
        }
        if(v==70){
        cout<<"A7 channel (V)"<<endl;
        imprimir_compmin_individual_3_avg(A7,datetime,n);
        }
        if(v==71){
        cout<<"A7 channel (V)"<<endl;
        imprimir_compmin_individual_3_max(A7,datetime,n);
        }
        if(v==72){
        cout<<"A7 channel (V)"<<endl;
        imprimir_compmin_individual_3_min(A7,datetime,n);
        }
        if(v==73){
        cout<<"A7 channel (V)"<<endl;
        imprimir_compmin_individual_3_stddev(A7,datetime,n);
        }
if(v==74){
        cout<<"C1 channel (V)"<<endl;
        imprimir_compmin_individual_3_avg(C1,datetime,n);
        }

if(v==75){
        cout<<"C1 channel (V)"<<endl;
        imprimir_compmin_individual_3_max(C1,datetime,n);
        }

if(v==76){
        cout<<"C1 channel (V)"<<endl;
        imprimir_compmin_individual_3_min(C1,datetime,n);
        }
if(v==77){
        cout<<"C1 channel (V)"<<endl;
        imprimir_compmin_individual_3_stddev(C1,datetime,n);
        }

if(v==78){
        cout<<"C2 channel (V)"<<endl;
        imprimir_compmin_individual_3_avg(C2,datetime,n);
        }

if(v==79){
        cout<<"C2 channel (V)"<<endl;
        imprimir_compmin_individual_3_max(C2,datetime,n);
        }

if(v==80){
        cout<<"C2 channel (V)"<<endl;
        imprimir_compmin_individual_3_min(C2,datetime,n);
        }

if(v==81){
        cout<<"C2 channel (V)"<<endl;
        imprimir_compmin_individual_3_stddev(C2,datetime,n);
        }

if(v==82){
        cout<<"D1 channel (V)"<<endl;
        imprimir_compmin_individual_3_avg(D1,datetime,n);
        }

if(v==83){
        cout<<"D1 channel (V)"<<endl;
        imprimir_compmin_individual_3_max(D1,datetime,n);
        }

if(v==84){
        cout<<"D1 channel (V)"<<endl;
        imprimir_compmin_individual_3_min(D1,datetime,n);
        }
if(v==85){
        cout<<"D1 channel (V)"<<endl;
        imprimir_compmin_individual_3_stddev(D1,datetime,n);
        }

if(v==86){
        cout<<"T channel (AC)"<<endl;
        imprimir_compmin_individual_3_avg(T,datetime,n);
        }

if(v==86){
        cout<<"T channel (AC)"<<endl;
        imprimir_compmin_individual_3_avg(T,datetime,n);
        }

if(v==87){
        cout<<"I channel (mA)"<<endl;
        imprimir_compmin_individual_3_avg(I,datetime,n);
        }

if(v==88){
        cout<<"I channel (mA)"<<endl;
        imprimir_compmin_individual_3_max(I,datetime,n);
        }

if(v==89){
        cout<<"I channel (mA)"<<endl;
        imprimir_compmin_individual_3_min(I,datetime,n);
        }

        if(v==90){
        cout<<"V channel (V)"<<endl;
        imprimir_compmin_individual_3_avg(V,datetime,n);
        }
        if(v==91){
        cout<<"V channel (V)"<<endl;
        imprimir_compmin_individual_3_max(V,datetime,n);
        }
        if(v==92){
        cout<<"V channel (V)"<<endl;
        imprimir_compmin_individual_3_min(V,datetime,n);
        }
}
//fim do if vmin        





}
    entrada.close();
    return 0;
}

#include<iostream>
#include <cmath>
#include <cstdlib>
#include <stdlib.h>
#include <iomanip>
using namespace std;
#define PI 3.14

float Seno(float grau, int n){
    float fatorial;
    float soma = 0;


    for(int i = 0; i < n; i++){
        //definindo o fatorial para 1 toda vez que mudar o i
        fatorial = 1;
        
        if(i%2 != 0){
            for(int j = 1; j <= i; j++){
                //calculo do fatorial
                fatorial = j * fatorial;
            }
            //calculo do seno
            soma = soma - (pow(-1, (i+1)/2) * (pow(grau, i)/fatorial));
            
        }
       
    }
    return soma;
    
}

float Cos(float grau, int n){
    float fatorial;
    float soma = 1;

    for(int i = 0; i < n; i++){
        //definindo o fatorial para 1 toda vez que mudar o i
        fatorial = 1;
        if(i != 0){

            if(i%2 == 0){
                //calculo do fatorial
                for(int j = 1; j <= i; j++){
                    fatorial = fatorial * j;
                }
                //calculo coseno
                soma = soma + ((pow(-1, i/2) * pow(grau, i)/fatorial));
            }
        }
    }
    return soma;


}


int main(){
    float grau;
    float dif_seno = 0, dif_cos = 0, cosseno = 0, seno = 0;
    cout << fixed << setprecision(6);
    int n;
    //Passando o valor pelo usuario
    cout << " - Bem Vindo a calculadora de Seno e Cosseno atraves de potencias -" << endl;
    cout << "             - Digite o angulo que deseja calcular: ";
    cin >> grau;
    //Passar o valor para radiano (grau*PI/180)
    grau = (grau*PI)/180;
    //Passar o numero de potencias
    cout << " - Digite o valor de N (numero de potencias) que deseja elevar o angulo: ";
    cin >> n;
    //Recebendo o valor final das funcoes seno e cosseno 
    cosseno = Cos(grau, n);
    seno = Seno(grau, n); 

    //Print das DIFERENCAS entre as duas funcoes cosseno
    cout << "-------------------------------------------------------" << endl;
    cout << "                       -Cosseno-" << endl;
    cout << "Valor: " << cosseno << endl;
    cout << "Valor (pela funcao): " << cos(grau) << endl;
    dif_cos = cosseno - cos(grau);
    cout << "A diferenca do Resultado (absoluto) foi: " << dif_cos << endl;
    cout << "A diferenca do Resultado (porcentagem) foi: " << dif_cos/100 << "%" << endl;
    cout << "-------------------------------------------------------";
    cout << endl << endl;

    //Print das DIFERENCAS entre as duas funcoes seno
    cout << "-------------------------------------------------------" << endl;
    cout << "                       -Seno-" << endl;
    cout << "Valor: " << seno << endl;
    cout << "Valor (pela funcao): " << sin(grau) << endl;
    dif_seno = seno - sin(grau);
    cout << "A diferenca do Resultado (absoluto) foi: " << dif_seno << endl;
    cout << "A diferenca do Resultado (porcentagem) foi: " << dif_seno/100 << "%" << endl;
    cout << "-------------------------------------------------------";
}
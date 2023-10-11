#include "CarRental.hpp"

#include<iostream>
#include<string>
#include<ctime>
Date::Date(){
    this->dia = 0;
    this->mes = 0;
    this->ano = 0;
}

Date::Date(int dia, int mes, int ano){
    std::string d, m, a, str, strm;
    int id, im, ia;
    
    bool valido = 1;

    id = dia;
    im = mes;
    ia = ano;

    if(im < 1 || im > 12 || id < 1 || id > 31)
        valido = 0;

    if(valido && (im == 4 || im == 6 || im == 9 || im == 11) && id > 30)
        valido = 0;

    if(valido && im == 2)
    {
        if (((ia % 4 == 0 && ia % 100 != 0) || ia % 400 == 0)  && id > 29)
            valido = 0;
        else if (ia % 4 !=0 && id > 28)
            valido = 0;
    }

    if(!valido){
        cout << "Essa data e invalida. ";
    }

    this->dia = id;
    this->mes = im;
    this->ano = ia;
}

Date::Date(string str){
    std::string d, m, a, strm;
    int id, im, ia;
    
    for(bool valido = 0; valido == 0;)
    {
        valido = 1;

        d = str.substr(0, 2);
        m = str.substr(3, 2);
        a = str.substr(6, 4);

        id = stoi(d);
        im = stoi(m);
        ia = stoi(a);

        if(im < 1 || im > 12 || id < 1 || id > 31)
            valido = 0;

        if(valido && (im == 4 || im == 6 || im == 9 || im == 11) && id > 30)
            valido = 0;

        if(valido && im == 2)
        {
            if (((ia % 4 == 0 && ia % 100 != 0) || ia % 400 == 0)  && id > 29)
                valido = 0;
            else if (ia % 4 !=0 && id > 28)
                valido = 0;
        }

        if(!valido){
            cout << "Essa data e invalida. ";
        }
    }

    this->dia = id;
    this->mes = im;
    this->ano = ia;
}

int Date::diasEntre(Date data){
    int dias = 0;
    int ano = this->ano;
    int mes = this->mes;
    int dia = this->dia;
    
    /*
    while(ano != data.ano || mes != data.mes || dia != data.dia){
        dias++;
        dia++;
        if(dia > 31){
            dia = 1;
            mes++;
        }
        if(mes > 12){
            mes = 1;
            ano++;
        }
    }
    //*/
    
    time_t tempo1 = 0;
    time_t tempo2 = 0;
    
    tm tm1 = *gmtime(&tempo1);
    tm tm2 = *gmtime(&tempo2);
    
    tm1.tm_mday = dia;
    tm1.tm_mon = mes - 1;
    tm1.tm_year = ano - 1900;
    
    tm2.tm_mday = data.dia;
    tm2.tm_mon = data.mes - 1;
    tm2.tm_year = data.ano - 1900;
    
    time_t newt1 = mktime(&tm1);
    time_t newt2 = mktime(&tm2);

    dias = (difftime(newt2, newt1)) / (3600 * 24);
    return dias;
}

int Date::diasEntre(Date data1, Date data2){
    int dias = 0;
    int ano = data1.ano;
    int mes = data1.mes;
    int dia = data1.dia;
    
    /*
    while(ano != data2.ano || mes != data2.mes || dia != data2.dia){
        dias++;
        dia++;
        if(dia > 31){
            dia = 1;
            mes++;
        }
        if(mes > 12){
            mes = 1;
            ano++;
        }
    }
    //*/

    time_t tempo1 = 0;
    time_t tempo2 = 0;
    
    tm tm1 = *gmtime(&tempo1);
    tm tm2 = *gmtime(&tempo2);
    
    tm1.tm_mday = dia;
    tm1.tm_mon = mes - 1;
    tm1.tm_year = ano - 1900;
    
    tm2.tm_mday = data2.dia;
    tm2.tm_mon = data2.mes - 1;
    tm2.tm_year = data2.ano - 1900;
    
    time_t newt1 = mktime(&tm1);
    time_t newt2 = mktime(&tm2);

    dias = (difftime(newt2, newt1)) / (3600 * 24);
    return dias;
}

bool Date::dataNaoNula(){
    if(dia == 0)
        {return 0;}
    return 1;
}

bool Date::dataNaoNula(Date data){
    if(data.dia == 0)
        {return 0;}
    return 1;
}

Date Date::dataAtual(){
    int dia, mes, ano;

    time_t rawtime;
    struct tm timeinfo;
    time(&rawtime);
    timeinfo = *localtime(&rawtime);

    dia = timeinfo.tm_mday;
    mes = (timeinfo.tm_mon) + 1;
    ano = (timeinfo.tm_year) + 1900;

    Date dataAtual(dia, mes, ano);
    return dataAtual;
}

string Date::toString(){
    string str = "";
    if(dia < 10)
        str += "0";
    str += to_string(dia);
    str += "/";
    if(mes < 10)
        str += "0";
    str += to_string(mes);
    str += "/";
    str += to_string(ano);
    return str;
};
bool Date::operator<(const Date &other) {
        if (ano < other.ano) {
            return true;
        } else if (ano > other.ano) {
            return false;
        } else {
            if (mes < other.mes) {
                return true;
            } else if (mes > other.mes) {
                return false;
            } else {
                return dia < other.dia;
            }
        }
    };



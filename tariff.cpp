#include "tariff.h"
#include <iostream>



Tariff::Tariff(string name, int internet, int time, double price) {
    this->name = name;
    this->internet = internet;
    this->time = time;
    this->price = price;
}

void Tariff::Show() {
    cout << name << "   "<< "Price: " << price << " UAH" << endl;

}

double Tariff::getprice() {
    return price;
}

int Tariff::getinternet() {
    return internet;
}

int Tariff::gettime() {
    return time;
}

string Tariff::getname() {
    return name;
}

void printMenu() {
    cout << "Choose one of the items:" << endl;
    cout << "1. View all tariffs." << endl;
    cout << "2. View only contract tariffs." << endl;
    cout << "3. View only prepaid tariffs." << endl;
    cout << "4. Select the tariff according to the parameters." << endl;
    cout << "5. Exit" << endl;
    cout << endl;
}

bool compareTariffsByPrice(Tariff& a, Tariff& b) {
    return a.getprice() < b.getprice();
}

void sortTariffsByPrice(vector<Tariff>& tariffs) {
    sort(tariffs.begin(), tariffs.end(), compareTariffsByPrice);
}

    void printSortedTariffs(vector<Tariff>& tariffs) {
    cout << "Sorted tariffs:" << endl;

    for (Tariff& tariff : tariffs) {
            cout << tariff.getname() << " Price: " << tariff.getprice() << " UAH" << endl;
    }
}

void PriceTariffs(vector<Tariff>& tariffs, double maxprice) {
    cout << "Tariffs within the specified range:" << endl;
    for (Tariff& tariff : tariffs) {
        double price = tariff.getprice();
        if (price <= maxprice) {
            cout << tariff.getname() << "  Internet: " << tariff.getinternet() << "GB   Time: " << tariff.gettime() << "min   Price: " << tariff.getprice() << " UAH" << std::endl;
        }
    }
}

void Priceinternet(vector<Tariff>& tariffs, double maxinternet) {
    cout << "Tariffs within the specified range:" << endl;
    for (Tariff& tariff : tariffs) {
        double internet = tariff.getinternet();
        if (internet <= maxinternet) {
            cout << tariff.getname() << "  Internet: " << tariff.getinternet() << "GB   Time: " << tariff.gettime() << "min   Price: " << tariff.getprice() << " UAH" << std::endl;
        }
    }
}

void Pricetime(vector<Tariff>& tariffs, double maxtime) {
    cout << "Tariffs within the specified range:" << endl;
    for (Tariff& tariff : tariffs) {
        double time = tariff.gettime();
        if (time <= maxtime) {
            cout << tariff.getname() << "  Internet: " << tariff.getinternet() << "GB   Time: " << tariff.gettime() << "min   Price: " << tariff.getprice() << " UAH" << std::endl;
        }
    }
}

void searching(vector<Tariff>& tariffcontract, int g){

                sortTariffsByPrice(tariffcontract);
               // printSortedTariffs(tariffcontract);

                if(g==1){
                    double maxprice=0;
                    cout<<"Enter max price"<<endl;
                    cin>>maxprice;

                    PriceTariffs(tariffcontract, maxprice);
                }

               else if (g==2){

                  double maxinternet=0;
                    cout<<"Enter max internet"<<endl;
                    cin>>maxinternet;
                    Priceinternet(tariffcontract,maxinternet);

               }
                else {
                    double maxtime=0;
                    cout<<"Enter max time"<<endl;
                    cin>>maxtime;
                    Pricetime(tariffcontract,maxtime);
                    }
               }

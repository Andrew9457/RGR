#ifndef TARIFF_H
#define TARIFF_H

#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Tariff {
private:
    string name;
    int internet;
    int time;
    double price;

public:
    Tariff(string name, int internet, int time, double price);
    void Show();
    double getprice();
    int getinternet();
    int gettime();
    string getname();

};

void printMenu();
bool compareTariffsByPrice(Tariff& a, Tariff& b);
void sortTariffsByPrice(vector<Tariff>& tariffs);
void printSortedTariffs(vector<Tariff>& tariffs);
void PriceTariffs(vector<Tariff>& tariffs, double maxprice);
void Priceinternet(vector<Tariff>& tariffs, double maxinternet);
void Pricetime(vector<Tariff>& tariffs, double maxtime);
void searching(vector<Tariff>& tariffcontract, int g);

#endif

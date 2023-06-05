#include <iostream>
#include <vector>
#include <algorithm>
#include "tariff.h"
#include "Logger.h"
#include <fstream>
#include <sstream>

using namespace std;

void encryptTariffs(const string& inputFileName, const string& outputFileName);
vector<Tariff> readTariffsFromFile(const string& filename);

int main() {

    Logger logger("log.txt");
    logger.log("Program started");

        string inputFileName = "tariffs.txt";
        string outputFileName = "encrypted_tariffs.txt";

    encryptTariffs(inputFileName, outputFileName);

        vector<Tariff> tariffs = readTariffsFromFile("tariffs.txt");

        vector<Tariff> tariffcontract = readTariffsFromFile("tariffcontract.txt");

            vector<Tariff> tariffPrepayment = readTariffsFromFile("tariffPrepayment.txt");

    while (1) {

       printMenu();

        int X = 0;
                   do{cin >> X;
                    check(logger, X,5);
                    }while(X<1||X>5);
        logger.log("Go to the next point");
        switch (X) {
            case 1: {

                    vector<Tariff> tariffs = readTariffsFromFile("tariffs.txt");

                for (Tariff& tariff : tariffs) {
                    tariff.Show();
                }

                int B;
                cout << "Sort tariffs by price?" << endl;
                cout << "1. YES" << endl;
                cout << "2. NO" << endl;
                cout << endl;
                logger.log("Go to the next point");
               do{cin >> B;
                    check(logger, B,2);
                    }while(B<1||B>2);

                if (B == 1) {
                    sortTariffsByPrice(tariffs);
                    printSortedTariffs(tariffs);
                }
                break;
            }

            case 2: {
              printSortedTariffs(tariffcontract);

               logger.log("Go to the next point");
                break;
            }

            case 3: {
                printSortedTariffs(tariffPrepayment);
               logger.log("Go to the next point");
                break;
            }

            case 4: {

                int l = 0;
                int g = 0;
                    logger.log("Go to the next point");
                    cout << "1. Contract tariffs" << endl;
                    cout << "2. Subscription rates" << endl;
                   do{cin >> l;

                    check(logger, l,2);
                    }while(l<1||l>2);
                    logger.log("Go to the next point");
                    cout << "1. Selection by price." <<     endl;
                    cout << "2. Selection by the amount of available Internet." <<  endl;
                    cout << "3. Selection by the number of minutes of conversation." <<     endl;
                do{cin >> g;
                    check(logger, g,3);
                    }while(g<1||g>3);

                if (l==1){

                searching(tariffcontract, g);}
                else if(l==2){
                    searching(tariffPrepayment, g);}

                logger.log("Go to the next point");
                break;
            }

        case 5:{
        logger.log("Program finished");
        exit(true);
        }
        }
    }
}


void encryptTariffs(const string& inputFileName, const string& outputFileName) {
    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);

    string line;
    while (getline(inputFile, line)) {

        for (char& c : line) {
            if (c >= 'a' && c <= 'z') {
                c = 'z' - (c - 'a');
            } else if (c >= 'A' && c <= 'Z') {
                c = 'Z' - (c - 'A');
            }
        }

        outputFile << line << endl;
    }

    inputFile.close();
    outputFile.close();
}

vector<Tariff> readTariffsFromFile(const string& filename) {
    vector<Tariff> tariffs;

    ifstream file(filename);
    if (!file) {
        cout << "Failed to open the file: " << filename << endl;
        return tariffs;
    }

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string name;
        int internet, time;
        double price;

        if (iss >> name >> internet >> time >> price) {
            tariffs.emplace_back(name, internet, time, price);
        }
    }

    file.close();

    return tariffs;
}

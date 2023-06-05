#include <iostream>
#include <fstream>
using namespace std;

class Logger {
private:
    ofstream logfile_;

public:
    Logger(const string& filename) {
        logfile_.open(filename, ios::app); // Відкриття файлу для допису
    }

    Logger() : logfile_() {} // Конструктор за замовчуванням

    ~Logger() {
        if (logfile_.is_open()) {
            logfile_.close(); // Закриття файлу перед знищенням об'єкта
        }
    }

    void log(const string& message);
};
    void check(Logger& logger, int L, int K);

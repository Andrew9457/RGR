#include <iostream>
#include <fstream>
using namespace std;

class Logger {
private:
    ofstream logfile_;

public:
    Logger(const string& filename) {
        logfile_.open(filename, ios::app); // ³������� ����� ��� ������
    }

    Logger() : logfile_() {} // ����������� �� �������������

    ~Logger() {
        if (logfile_.is_open()) {
            logfile_.close(); // �������� ����� ����� ��������� ��'����
        }
    }

    void log(const string& message);
};
    void check(Logger& logger, int L, int K);

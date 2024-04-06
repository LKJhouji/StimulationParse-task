#include "CSVFileReader.h"

int main() {
    CSVFileReader csv;
    csv.Load("/home/houji/桌面/SP-task/files/TriangularWaveOutput.csv");
    csv.printFcnValue();
    SignalValue sv = csv.Get();
    std::cout << csv.GetFcnValue(46.867) << std::endl;
    return 0;
}
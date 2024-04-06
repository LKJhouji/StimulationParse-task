#include "MATFileReader.h"

int main() {
    MATFileReader mat;
    int res = mat.Load("/home/houji/桌面/SP-task/files/20240313_135350.mat", "V_1_1");
    if (res != 0) {
        return -1;
    }
    SignalValue sv = mat.Get();
    mat.printFcnValue();
    double fx = mat.GetFcnValue(68.9930);
    std::cout << fx << std::endl;
    return 0;
}
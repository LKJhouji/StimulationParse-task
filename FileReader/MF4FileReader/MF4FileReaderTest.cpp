#include "MF4FileReader.h"

int main() {
    MF4FileReader mf4;
    mf4.Load("/home/houji/桌面/SP-task/files/20240313_134900.mf4");
    mf4.printFcnValue();
    return 0;
}
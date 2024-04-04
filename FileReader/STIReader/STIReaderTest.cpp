#include "STIReader.h"
#include "SignalDescriptionSet.h"

int main() {
    STIReader sti;
    int resCode = sti.load("/home/houji/桌面/SP-task/files/Stimulus1.sti");
    if (resCode != 0) std::cerr << "resCode == 0" << std::endl;
    SignalDescriptionSet sds = sti.get();
    sds.printSignalDescriptionSet();
    return 0;
}
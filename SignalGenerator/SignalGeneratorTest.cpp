#include "SignalGenerator.h"
#include "ParseXml.h"

int main() {
    ParseXml px("/home/houji/桌面/SP-task/files/Stimulus1.sti");
    SignalDescriptionSet sds = px.parse();
    sds.printSignalDescriptionSet();
    SignalGenerator sg(sds);
    std::cout << sg.GetFcnValue(0.3) << std::endl;
    SignalValue sv = sg.Get();
    for (int i = 0; i < sv.fcnVector.size(); i++) {
        std::cout << sv.fcnVector[i] << " ";
    }
    return 0;
}
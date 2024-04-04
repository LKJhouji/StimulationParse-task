#include "ParseXml.h"
#include "SignalDescriptionSet.h"

int main() {
    ParseXml px("/home/houji/桌面/SP-task/files/Stimulus1.sti");
    SignalDescriptionSet sds = px.parse();
    sds.printSignalDescriptionSet();
    return 0;
}
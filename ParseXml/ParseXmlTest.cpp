#include "ParseXml.h"
#include "SignalDescriptionSet.h"

int main() {
    ParseXml px("/root/houji_project/keju.li-SPTask/files/Stimulus1.sti");
    SignalDescriptionSet sds = px.parse();
    sds.printSignalDescriptionSet();
    return 0;
}
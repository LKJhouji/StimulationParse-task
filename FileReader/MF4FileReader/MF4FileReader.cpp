#include "MF4FileReader.h"



int MF4FileReader::Load(const char* mf4File) {
    CMdf4FileImport *pImport = new CMdf4FileImport;
	if (pImport->ImportFile(this, mf4File)) return 0;
    else return -1;
}

SignalValue MF4FileReader::Get() {
    return sv_;
}

void MF4FileReader::Mf4ToSignalValue(int idx, const char* mf4File, CMdf4DataGroup* pGroup, M4DGBlock *dg,M4CGBlock *cg,M4CNBlock *cn) {
    int iScanSize = cg->cg_data_bytes + cg->cg_inval_bytes + dg->dg_rec_id_size;
  M_UINT8 *pScan = (M_UINT8*)calloc(1,iScanSize);
	int n = cg->cg_cycle_count;
	for (int i = 0; i < n; i++) {
		BOOL bResult = pGroup->GetRecord(cg, pScan, i, i);
		if (!bResult)
			printf("        read error\n");
		else {
			double value;
			BOOL bNoval = pGroup->GetRawValueFromRecord(cg, cn, pScan, &value);
			if (!bNoval) {
				if (idx == 0) {
                    sv_.xVector.push_back(value);
                    xToIdx.insert({value, i});
                }
                else sv_.fcnVector.push_back(value); 
			}
		}
	}
}

double MF4FileReader::GetFcnValue(double x) {
    return sv_.fcnVector[xToIdx[x]];
}

void MF4FileReader::printFcnValue() {
    for (int i = 0; i < sv_.xVector.size(); i++) {
        std::cout << sv_.xVector[i] << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < sv_.fcnVector.size(); i++) {
        std::cout << sv_.fcnVector[i] << " ";
    }
    std::cout << std::endl;
}  
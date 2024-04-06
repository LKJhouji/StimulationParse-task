#include "MATFileReader.h"

int MATFileReader::Load(const char* matFile, const char* varName) {
    mat_t *matFp = nullptr;
    matFp = Mat_Open(matFile, MAT_ACC_RDONLY);
    if (matFp == nullptr) {
        std::cout << "mat file open failed!" << std::endl;
        return -1;
    }
    matvar_t *matVar = nullptr;
    matVar = Mat_VarRead(matFp, varName);
    if (matVar == nullptr) {
        std::cout << "read matVar error!" << std::endl;
        return -1;
    }
    else if (matVar->data_type == MAT_T_STRUCT) {
        //std::cout << "it's struct!" << std::endl;
        size_t numFields = Mat_VarGetNumberOfFields(matVar);
        for (int i = 0; i < numFields; i++) {
            matvar_t* data1 = Mat_VarGetStructFieldByName(matVar, "time", i);
            if (data1) {
                const double* xDataStar = (const double*)(data1->data);
                const int iDataN = data1->nbytes / data1->data_size;			// data1数组的长度
				for (int j = 0; j < iDataN; j++) {
					sv_.xVector.push_back(xDataStar[j]);
                    xToIdx.insert({xDataStar[j], j});
				}
            }
        }
        for (int i = 0; i < numFields; i++) {
            matvar_t* data1 = Mat_VarGetStructFieldByName(matVar, varName, i);
            if (data1) {
                const double* xDataStar = (const double*)(data1->data);
                const int iDataN = data1->nbytes / data1->data_size;			// data1数组的长度
				for (int j = 0; j < iDataN; j++) {
                    sv_.fcnVector.push_back(xDataStar[j]);
				}
            }
        }
    }
    
    Mat_VarFree(matVar);
    Mat_Close(matFp);
    return 0;
}

SignalValue MATFileReader::Get() {
    return sv_;
}

double MATFileReader::GetFcnValue(double x) {
    return sv_.fcnVector[xToIdx[x]];
}

void MATFileReader::printFcnValue() {
    for (int i = 0; i < sv_.xVector.size(); i++) {
        std::cout << sv_.xVector[i] << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < sv_.fcnVector.size(); i++) {
        std::cout << sv_.fcnVector[i] << " ";
    }
    std::cout << std::endl;
}   

// void MATFileReader::test() {
//     mat_t* matFp;
//     matvar_t* matVar;
//     matFp = Mat_Open("/home/houji/桌面/SP-task/files/20240313_135350.mat", MAT_ACC_RDONLY);
//     if (NULL == matFp) {
//         printf("Error opening MAT file!\n");
//         return;
//     }
//     while ((matVar = Mat_VarReadNext(matFp)) != nullptr) {
//         if (strcmp(matVar->name, "V_1_1") == 0) {
//             size_t numFields = Mat_VarGetNumberOfFields(matVar);
//             char*const* cc = Mat_VarGetStructFieldnames(matVar);
//             for (int i = 0; i < numFields; i++) {
//                 printf("%s\n", cc[i]);
//             }
//             matvar_t* mvTime = Mat_VarGetStructFieldByIndex(matVar, 0, 0);
//             matvar_t* mvValue = Mat_VarGetStructFieldByIndex(matVar, 1, 0);

//         }
//         Mat_VarFree(matVar);
//         matVar = nullptr;
//     }
//     Mat_Close(matFp);
// }
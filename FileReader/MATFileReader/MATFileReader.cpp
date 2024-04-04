#include "MATFileReader.h"

int MATFileReader::Load(const char* matFile) {
    mat_t *matFp;
    matFp = Mat_Open(matFile, MAT_ACC_RDONLY);
    if (matFp == nullptr) {
        printf("open failed!\n");
        return -1;
    }
    matvar_t *matVar;
    matVar = Mat_VarReadNext(matFp);
    int rank;
    rank=(int)matVar->rank;
 
    size_t* dims;
    dims=(size_t*)matVar->dims;
 
    double* data=(double*)matVar->data;
 
    targetArray_ = (double**)calloc(dims[0], 8);
    for(int i = 0; i < dims[0]; i++) {
        targetArray_[i] = (double*)calloc(dims[1], 8);
        for (int j = 0; j < dims[1];j++) {
            targetArray_[i][j] = data[i * dims[0] + j];
            std::cout << targetArray_[i][j] << " ";
        }
        std::cout << std::endl;
    }
    Mat_VarFree(matVar);
    Mat_Close(matFp);
    printf("%f\n",targetArray_[0][0]);
    return 0;
}

SignalValue MATFileReader::Get() {
    return sv_;
}
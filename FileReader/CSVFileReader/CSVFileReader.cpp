#include "CSVFileReader.h"

int CSVFileReader::Load(const char* csvFile) {
    std::ifstream inFile(csvFile, std::ios::in|std::ios::binary);
    std::string lineStr;
    int i = 0;
    if (inFile.is_open()) {
        getline(inFile, lineStr);
        while (getline(inFile, lineStr)) {
            // 打印整行字符串
            std::cout << lineStr << std::endl;
            // 存成二维表结构
            std::stringstream ss(lineStr);
            std::string str;
            std::vector<double> v;
            //按照逗号分隔
            while (getline(ss, str, ',')) {
                v.push_back(stod(str));
            }
            sv_.xVector.push_back(v[0]);
            xToIdx.insert({v[0], i++});
            sv_.fcnVector.push_back(v[1]);
        }
        return 0;
    }
    else {
        return -1;
    }
	
}

SignalValue CSVFileReader::Get() {
    return sv_;
}

double CSVFileReader::GetFcnValue(double x) {
    return sv_.fcnVector[xToIdx[x]];
}

void CSVFileReader::printFcnValue() {
    for (int i = 0; i < sv_.xVector.size(); i++) {
        std::cout << sv_.xVector[i] << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < sv_.fcnVector.size(); i++) {
        std::cout << sv_.fcnVector[i] << " ";
    }
    std::cout << std::endl;
}   
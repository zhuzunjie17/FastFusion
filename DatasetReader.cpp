//
// Created by zhuzunjie on 18-4-9.
//
#include "DatasetReader.h"
#include <iostream>
namespace DataReader {
    void loadImageList(const char *imagePath, std::vector<ICell> &iListData) {
        ifstream inf;
        inf.open(imagePath, ifstream::in);
        const int cnt = 2;          // 你要输出的个数

        string line;

        size_t comma = 0;
        size_t comma2 = 0;
        ICell temp;
        getline(inf, line);
        while (!inf.eof()) {
            getline(inf, line);

            comma = line.find(',', 0);
            string temp1 = line.substr(0, comma);
            temp.timeStamp = (double) atof(temp1.c_str());

            comma2 = line.find(',', comma + 1);
            temp.imgName = line.substr(comma + 1, comma2 - comma - 1).c_str();
            if(temp.timeStamp < 1e-3) continue;
            iListData.push_back(temp);

        }

        inf.close();
    }

    void loadIMUFile(const char *imuPath, std::vector<IMUData> &vimuData) {
        ifstream inf;
        inf.open(imuPath, ifstream::in);
        if(!inf){
            cout<< "No IMU information" << endl;
            return;
        }
        const int cnt = 7;          // 你要输出的个数

        string line;
        //int i = 0;
        int j = 0;
        size_t comma = 0;
        size_t comma2 = 0;

        //     char imuTime[14] = {0};
        double acc[3] = {0.0};
        double grad[3] = {0.0};
        double imuTimeStamp = 0.0;
        getline(inf, line);
        while (!inf.eof()) {
            getline(inf, line);
            comma = line.find(',', 0);
            string temp = line.substr(0, comma);
            imuTimeStamp = (double) atof(temp.c_str());

            //cout<<line.substr(0,comma).c_str()<<' ';
            //memcpy(imuTimeStamp,line.substr(0,comma).c_str(),line.substr(0,comma).length);
            while (comma < line.size() && j != cnt - 1) {

                comma2 = line.find(',', comma + 1);
                switch (j) {
                    case 0:
                        grad[0] = atof(line.substr(comma + 1, comma2 - comma - 1).c_str());
                        break;
                    case 1:
                        grad[1] = atof(line.substr(comma + 1, comma2 - comma - 1).c_str());
                        break;
                    case 2:
                        grad[2] = atof(line.substr(comma + 1, comma2 - comma - 1).c_str());
                        break;
                    case 3:
                        acc[0] = atof(line.substr(comma + 1, comma2 - comma - 1).c_str());
                        break;
                    case 4:
                        acc[1] = atof(line.substr(comma + 1, comma2 - comma - 1).c_str());
                        break;
                    case 5:
                        acc[2] = atof(line.substr(comma + 1, comma2 - comma - 1).c_str());
                        break;
                }
                //cout<<line.substr(comma + 1,comma2-comma-1).c_str()<<' ';
                ++j;
                comma = comma2;
            }
            if(imuTimeStamp < 1e-3) continue;
            IMUData tempImu(grad[0], grad[1], grad[2], acc[0], acc[1], acc[2], imuTimeStamp);
            vimuData.push_back(tempImu);

            j = 0;
        }

        inf.close();

        //return 0;
    }

    void synInit(std::vector<ICell> &imageList, std::vector<IMUData> &imuList, int imgIdx, int imuIdx) {
        // Find Start Idx
        // 预处理数据
        int startImuIdx = 0;
        int startImageIdx = 0;
        // 剔除初始的冗余IMU数据
        while (1) {
            if (imuList[startImuIdx]._t >= imageList[0].timeStamp)
                break;

            startImuIdx++;
        }

        // 剔除初始的冗余Image数据
        while (1) {
            if (imuList[0]._t <= imageList[startImageIdx].timeStamp)
                break;

            startImageIdx++;
        }
        // 将IMU和图片时间戳对齐
        while (1) {
            if (imuList[startImuIdx]._t >= imageList[startImageIdx].timeStamp)
                break;

            startImuIdx++;
        }
        imgIdx = startImageIdx;
        imuIdx = startImuIdx;
    }
}

/*void loadGTFile(const char *imuPath, std::vector<GT> &vGTData) {
    ifstream inf;
    inf.open(imuPath, ifstream::in);
    const int cnt = 7;          // 你要输出的个数

    string line;
    //int i = 0;
    int j = 0;
    size_t comma = 0;
    size_t comma2 = 0;

    getline(inf, line);
    while (!inf.eof()) {
        GT tempGT;
        getline(inf, line);
        comma = line.find(',', 0);
        string temp = line.substr(0, comma);
        tempGT.timeStamp = (double) atof(temp.c_str());

        //cout<<line.substr(0,comma).c_str()<<' ';
        //memcpy(imuTimeStamp,line.substr(0,comma).c_str(),line.substr(0,comma).length);
        while (j < cnt) {

            comma2 = line.find(',', comma + 1);
            switch (j) {
                case 0:
                    tempGT.position[2] = atof(line.substr(comma + 1, comma2 - comma - 1).c_str());
                    break;
                case 1:
                    tempGT.position[0] = -(atof(line.substr(comma + 1, comma2 - comma - 1).c_str()));
                    break;
                case 2:
                    tempGT.position[1] = -(atof(line.substr(comma + 1, comma2 - comma - 1).c_str()));
                    break;
                    // 				case 3:
                    // 					tempGT.rotation_Q[0] = atof(line.substr(comma + 1,comma2-comma-1).c_str());
                    // 					break;
                    // 				case 4:
                    // 					tempGT.rotation_Q[1] = atof(line.substr(comma + 1,comma2-comma-1).c_str());
                    // 					break;
                    // 				case 5:
                    // 					tempGT.rotation_Q[2] = atof(line.substr(comma + 1,comma2-comma-1).c_str());
                    // 					break;
                    // 				case 6:
                    // 					tempGT.rotation_Q[3] = atof(line.substr(comma + 1,comma2-comma-1).c_str());
                    // 					break;
            }
            //cout<<line.substr(comma + 1,comma2-comma-1).c_str()<<' ';
            ++j;
            comma = comma2;
        }

        vGTData.push_back(tempGT);

        j = 0;
    }

    inf.close();

    //return 0;
}*/
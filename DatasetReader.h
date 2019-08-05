//
// Created by zhuzunjie on 18-4-9.
//

#ifndef DATASETREADER_H
#define DATASETREADER_H

#include <vector>
#include <string>
#include <fstream>

#include "IMUdata.h"

using namespace std;
namespace DataReader {
    typedef struct ImageList {
        double timeStamp;
        string imgName;
    } ICell;

//    typedef struct loadGroundtruth {
//        double timeStamp;
//        Eigen::Vector3d position;
//        Eigen::Quaterniond rotation_Q;
//    } GT;

    void loadImageList(const char *imagePath, std::vector<ICell> &iListData);

    void loadIMUFile(const char *imuPath, std::vector<IMUData> &vimuData);

/*
 * @brief synchronize init time of imu and image.
 */
    void synInit(std::vector<ICell> &imageList, std::vector<IMUData> &imuList, int imgIdx, int imuIdx);

/*
 * @brief read groundtruth information.
 */
//    void loadGTFile(const char *imuPath, std::vector<GT> &vGTData);

}



#endif //DATASETREADER_H

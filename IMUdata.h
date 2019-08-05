//
// Created by zhuzunjie on 18-4-9.
//
#ifndef IMUDATA_H
#define IMUDATA_H
#include <vector>
namespace DataReader
{
    class IMUData
    {
    public:
        IMUData(const double& gx, const double& gy, const double& gz,
                const double& ax, const double& ay, const double& az,
                const double& t): _g{gx,gy,gz}, _a{ax,ay,az}, _t(t) {};

        // Raw data of imu's
        double _g[3];    //gyr data
        double _a[3];    //acc data
        double _t;      //timestamp
    };
}
#endif //IMUDATA_H
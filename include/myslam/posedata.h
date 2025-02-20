#ifndef MYSLAM_POSEDATA_H
#define MYSLAM_POSEDATA_H

#include "myslam/common_include.h"

namespace myslam{

struct PoseData{
    public:
    // Timestamp (alta precisione)
    double timestamp;

    // Posizione (x, y, z)
    Eigen::Vector3d position;

    // Orientamento (quaternione: w, x, y, z)
    Eigen::Quaterniond orientation;

};

}
#endif
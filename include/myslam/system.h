/*
 * Header file to save trajectory data:
 * tx ty tx qx qy qz qw
 * pointcloud
 */
#ifndef MYSLAM_SYSTEM_H
#define MYSLAM_SYSTEM_H

#include "myslam/common_include.h"

namespace myslam{

class System{
    public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW;
    
    System();

    void GetDataTrajectory();
    void SaveTrajectory();
    void GetPointCloud();
    void SavePointCloud();
    private:

}


}


#endif

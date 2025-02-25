#pragma once
#ifndef MAP_H
#define MAP_H

#include "myslam/common_include.h"
#include "myslam/frame.h"
#include "myslam/mappoint.h"



namespace myslam{

class Map {
   public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW;
    typedef std::shared_ptr<Map> Ptr;
    typedef std::unordered_map<unsigned long, MapPoint::Ptr> LandmarksType;
    typedef std::unordered_map<unsigned long, Frame::Ptr> KeyframesType;

    Map() {}

    void InsertKeyFrame(Frame::Ptr frame);
    void InsertMapPoint(MapPoint::Ptr map_point);

    LandmarksType GetAllMapPoints(){
        std::unique_lock<std::mutex> lck(data_mutex_);
        return landmarks_;
    }

    KeyframesType GetAllKeyFrames(){
        std::unique_lock<std::mutex> lck(data_mutex_);
        return keyframes_;
    }
    
    LandmarksType GetActiveMapPoints() {
        std::unique_lock<std::mutex> lck(data_mutex_);
        return active_landmarks_;
    }
    
    KeyframesType GetActiveKeyFrames() {
        std::unique_lock<std::mutex> lck(data_mutex_);
        return active_keyframes_;
    }

    void CleanMap();

    private:
    void RemoveOldKeyframe();
    std::mutex data_mutex_; 
    LandmarksType landmarks_;         // all landmarks
    LandmarksType active_landmarks_; // active landmarks
    KeyframesType keyframes_; // all keyframes
    KeyframesType active_keyframes_; // all keyframes

    Frame::Ptr current_frame_ = nullptr;

    //settings
    int num_active_keyframes_ = 7;
};

}

#endif // MAP_H
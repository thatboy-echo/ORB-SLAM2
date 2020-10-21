#pragma once
#ifdef SLAM_EXPORTS
#define SLAM_API __declspec(dllexport)
#else
#define SLAM_API __declspec(dllimport)
#endif

#include <string>
#include <opencv2/opencv.hpp>

using std::string;
using cv::Mat;

class SLAM_API SLAM
{
public:
	enum eSensor {
		MONOCULAR = 0,
		STEREO = 1,
		RGBD = 2
	};

public:
	void init(const string &strVocFile, const string &strSettingsFile, const eSensor sensor, const bool bUseViewer = true);
	Mat track(const Mat & im1, const Mat & im2 = Mat());

	static SLAM * createSingleObject();

private:
	SLAM();
	SLAM(const SLAM & slam) = delete;

	~SLAM();
};

extern SLAM_API SLAM & slam;
#include "SLAM.h"
#include "System.h"
#include <iostream>

using namespace ORB_SLAM2;

System * slamobj = nullptr;

SLAM  & slam = *SLAM::createSingleObject();

SLAM::SLAM()
{
}

SLAM::~SLAM()
{
	slamobj->Shutdown();
	delete slamobj;
	slamobj = nullptr;
}

void SLAM::init(const string & strVocFile, const string & strSettingsFile, const eSensor sensor, const bool bUseViewer)
{
	if (slamobj != nullptr)
	{
		slamobj->Shutdown();
		delete slamobj;
	}

	slamobj = new System(strVocFile, strSettingsFile, ORB_SLAM2::System::eSensor(sensor), bUseViewer);
}

Mat SLAM::track(const Mat & im1, const Mat & im2)
{
	static double timestamp = 0;
	Mat r;
	if (im2.data == nullptr)
		slamobj->TrackMonocular(im1, timestamp);
	else slamobj->TrackStereo(im1, im2, timestamp);
	timestamp += 0.01;

	return r;
}

SLAM * SLAM::createSingleObject()
{
	static bool firstTime = true;
	if (firstTime)
	{
		firstTime = false;
		return new SLAM();
	}
	else return &slam;
}



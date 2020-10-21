#include "System.h"
using namespace ORB_SLAM2;

int main()
{
	// 路径需要修改！！
	System orbslam("Vocabulary/ORBvoc.txt", "Examples/Stereo/KITTI03.yaml", System::eSensor::STEREO);
	system("pause");
	return 0;
}
#include "System.h"
using namespace ORB_SLAM2;

int main()
{
	// 路径需要修改！！
	System orbslam("../Run/Vocabulary/ORBvoc.txt", "../Run/Setting/KITTI03.yaml", System::eSensor::STEREO);
	system("pause");
	return 0;
}
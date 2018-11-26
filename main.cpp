#include "CylinderStitch.h"
int main()
{
	Mat img = imread("001.jpg", 0);//左图像
	Mat img1 = imread("002.jpg", 0);//右图像
	imshow("源图像-左", img);
	imshow("源图像-右", img1);
	double t = (double)getTickCount();
	//柱形投影
	double t3 = (double)getTickCount();
	img = cylinder(img, 1500);
	img1 = cylinder(img1, 1500);
	t3 = ((double)getTickCount() - t3) / getTickFrequency();
	//匹配
	double t1 = (double)getTickCount();
	Point2i a = getOffset(img, img1);
	t1 = ((double)getTickCount() - t1) / getTickFrequency();
	//拼接
	double t2 = (double)getTickCount();
	Mat stitch = linearStitch(img, img1, a);
	t2 = ((double)getTickCount() - t2) / getTickFrequency();
	t = ((double)getTickCount() - t) / getTickFrequency();

	cout << "各阶段耗时：" << endl; 
	cout << "柱面投影：" << t3 << '\n' << "模板匹配：" << t1 << '\n' << "渐入渐出拼接：" << t2 << endl;
	cout << "总时间：" << t << endl;
	
	imwrite("rectify.jpg", img);
	imwrite("rectify1.jpg", img1);
	imwrite("stitch.jpg", stitch);
	waitKey(0);
	return 0;
}




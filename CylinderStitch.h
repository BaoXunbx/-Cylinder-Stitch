#include <opencv2/opencv.hpp>
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include<iostream>
#include<time.h>
using namespace std;
using namespace cv;
Mat cylinder(Mat imgIn, int f);
Point2i getOffset(Mat img, Mat img1);
Mat linearStitch(Mat img, Mat img1, Point2i a);

#include <iostream>
#include <cstring>
using namespace std;

#include <opencv2/opencv.hpp>
using namespace cv;

#include "share_lib.h"
#include "static_lib.h"

void call_opencv_lib(const string &text)
{
    Mat img = Mat::zeros(Size(300, 100), CV_8UC3);
    int font_face = FONT_HERSHEY_COMPLEX;
    double font_scale = 1.0;
    int thickness = 2;
    putText(img, text, Point(50, 50), font_face, font_scale, Scalar(255, 255, 0), thickness);
    imshow("text", img);
    waitKey(0);
}

int main(int argc, char *argv[])
{
    string text = "call libs";
    cout << text << endl;
    call_opencv_lib("opencv lib");
    // NOTE call share_lib
    int res1 = share_lib::multiply(2, 2);
    cout << "call share_lib 2x2 = " << res1 << endl;
    // NOTE call static_lib
    int res2 = static_lib::multiply(3, 3);
    cout << "call static_lib 2x2 " << res2 << endl;
    exit(0);
}
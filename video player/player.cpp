#include "opencv2/highgui/highgui.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int main()
{
    VideoCapture cap("videofile.mp4");
        if ( !cap.isOpened() ){
        cout << "Cannot open the video file. \n";
        return -1;
    }

    double fps = cap.get(CV_CAP_PROP_FPS);

    namedWindow("windows",CV_WINDOW_AUTOSIZE);

    while(1) {
        Mat frame;
        if (!cap.read(frame)){
            cout<<"\n Cannot read the video file. \n";
            break;
        }
        imshow("windows", frame);
        if(waitKey(30) == 27){ 
            break; 
        }
    }

    return 0;
}
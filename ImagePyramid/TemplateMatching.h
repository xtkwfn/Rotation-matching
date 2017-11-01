#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/objdetect/objdetect.hpp"

#include <iostream>
#include <stdlib.h>

using namespace std;
using namespace cv;
/*
* vector<Point> Template_Matching(Mat grayImg, Mat tempGray, int num_loc)
* Parameters
*           grayImg-object image.
*           tempGray-template image.
*           num_loc-num of find location.
*           match_score-matching score.
* the function Template_Matching return num_loc top left location.
*/
vector<Point> Template_Matching(const Mat &grayImg, const Mat &tempGray, int num_loc, float match_score);
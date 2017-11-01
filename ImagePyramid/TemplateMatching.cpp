#include "TemplateMatching.h"
/*
* vector<Point> Template_Matching(Mat grayImg, Mat tempGray, int num_loc)
* Parameters
*           grayImg-object image.
*           tempGray-template image.
*           num_loc-num of find location.
*           match_score-matching score.
* the function Template_Matching return num_loc top left location.
*/
vector<Point> Template_Matching(const Mat &grayImg, const Mat &tempGray, int num_loc, float match_score)
{
	Mat img_draw=grayImg;
	vector<Point>center;
	vector<Point> vec_top_left;
	vector<Rect>box;
	vector<double>minValVec;
	vector<double>maxValVec;
	//for (size_t k=0;k<tempGray.size();k++)
	//{
		//创建输出结果的矩阵
		int result_cols =  grayImg.cols - tempGray.cols + 1;
		int result_rows = grayImg.rows - tempGray.rows + 1;

		Mat result;
		result.create( result_cols, result_rows, CV_32FC1 );

		////采用最小化方差进行匹配和标准化
		//matchTemplate(grayImg,tempGray[k], result,CV_TM_SQDIFF);
		//normalize( result, result, 0, 1, NORM_MINMAX, -1, Mat());


		//cout << result << endl;

		//double minVal,maxVal; 
		//Point minLoc,maxLoc;
		//minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc, Mat());

		//Point matchLoc = minLoc;
		////中心点
		//Point objCenter;
		//objCenter.x= minLoc.x + temp[k].cols/2;
		//objCenter.y= minLoc.y + temp[k].rows/2;

		//center.push_back(objCenter);
		//box.push_back(Rect(matchLoc,Point(matchLoc.x+temp[k].cols,matchLoc.y+temp[k].rows)));
		//minValVec.push_back(minVal);

		//采用相关归一化方法进行匹配和标准化
		matchTemplate(grayImg,tempGray, result,CV_TM_CCORR_NORMED);
		//normalize( result, result, 0, 1, NORM_MINMAX, -1, Mat());

		//cout << result << endl;

		double minVal,maxVal; 
		Point minLoc,maxLoc;
		minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc, Mat());

		Point matchLoc = maxLoc;
		vec_top_left.push_back(matchLoc);
		//中心点
		Point objCenter;
		objCenter.x= maxLoc.x + tempGray.cols/2;
		objCenter.y= maxLoc.y + tempGray.rows/2;

		center.push_back(objCenter);
		box.push_back(Rect(matchLoc,Point(matchLoc.x+tempGray.cols,matchLoc.y+tempGray.rows)));
		maxValVec.push_back(maxVal);
	//}


	for (size_t k=0;k<box.size();k++)
	{
		cout << "检测到的目标左上角坐标：" << vec_top_left[k] << endl;
		cout << "检测到的目标中心点坐标：" << center[k] << endl;

		cout << "目标：" << box[k] << endl;

		//cout << "方差：" << minValVec[k] << endl << endl;
		cout << "相关度：" << maxValVec[k] << endl << endl;

		//画出中心点
		circle(img_draw,center[k],1,Scalar(0,0,255),2,8,0);   

		//画出匹配的矩形
		rectangle(img_draw,box[k],Scalar(0,0,255),2,8,0);

		//画出匹配的圆形
		//circle(img,center[k],box[k].height/2-1,Scalar(0,0,255),2,8,0);
	}
	namedWindow("匹配结果",WINDOW_AUTOSIZE);
	imshow("匹配结果",img_draw);
	imwrite("drawRectImg.bmp",img_draw);
	return vec_top_left;
}
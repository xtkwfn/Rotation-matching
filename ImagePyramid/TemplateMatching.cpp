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
		//�����������ľ���
		int result_cols =  grayImg.cols - tempGray.cols + 1;
		int result_rows = grayImg.rows - tempGray.rows + 1;

		Mat result;
		result.create( result_cols, result_rows, CV_32FC1 );

		////������С���������ƥ��ͱ�׼��
		//matchTemplate(grayImg,tempGray[k], result,CV_TM_SQDIFF);
		//normalize( result, result, 0, 1, NORM_MINMAX, -1, Mat());


		//cout << result << endl;

		//double minVal,maxVal; 
		//Point minLoc,maxLoc;
		//minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc, Mat());

		//Point matchLoc = minLoc;
		////���ĵ�
		//Point objCenter;
		//objCenter.x= minLoc.x + temp[k].cols/2;
		//objCenter.y= minLoc.y + temp[k].rows/2;

		//center.push_back(objCenter);
		//box.push_back(Rect(matchLoc,Point(matchLoc.x+temp[k].cols,matchLoc.y+temp[k].rows)));
		//minValVec.push_back(minVal);

		//������ع�һ����������ƥ��ͱ�׼��
		matchTemplate(grayImg,tempGray, result,CV_TM_CCORR_NORMED);
		//normalize( result, result, 0, 1, NORM_MINMAX, -1, Mat());

		//cout << result << endl;

		double minVal,maxVal; 
		Point minLoc,maxLoc;
		minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc, Mat());

		Point matchLoc = maxLoc;
		vec_top_left.push_back(matchLoc);
		//���ĵ�
		Point objCenter;
		objCenter.x= maxLoc.x + tempGray.cols/2;
		objCenter.y= maxLoc.y + tempGray.rows/2;

		center.push_back(objCenter);
		box.push_back(Rect(matchLoc,Point(matchLoc.x+tempGray.cols,matchLoc.y+tempGray.rows)));
		maxValVec.push_back(maxVal);
	//}


	for (size_t k=0;k<box.size();k++)
	{
		cout << "��⵽��Ŀ�����Ͻ����꣺" << vec_top_left[k] << endl;
		cout << "��⵽��Ŀ�����ĵ����꣺" << center[k] << endl;

		cout << "Ŀ�꣺" << box[k] << endl;

		//cout << "���" << minValVec[k] << endl << endl;
		cout << "��ضȣ�" << maxValVec[k] << endl << endl;

		//�������ĵ�
		circle(img_draw,center[k],1,Scalar(0,0,255),2,8,0);   

		//����ƥ��ľ���
		rectangle(img_draw,box[k],Scalar(0,0,255),2,8,0);

		//����ƥ���Բ��
		//circle(img,center[k],box[k].height/2-1,Scalar(0,0,255),2,8,0);
	}
	namedWindow("ƥ����",WINDOW_AUTOSIZE);
	imshow("ƥ����",img_draw);
	imwrite("drawRectImg.bmp",img_draw);
	return vec_top_left;
}
#include "CommonHead.h"
//#include "UserLib.h"
#include "ImagePyramid.h"
int main()
{
	/************************************************************************/
	/*                        create pyramid                               */
	/************************************************************************/

	/*
	* 创建模板金字塔
	*/

	/*读取模板图像*/

	Mat img_tpl;
	//img_tpl=imread("Template.jpg",0);
	img_tpl=imread("template_0.bmp",0);
	imshow("原模板图像",img_tpl);
	cout<<img_tpl.channels()<<endl;
	waitKey(20);


	vector<Mat> pyramid_template;
	/*创建金字塔最上层图像高不小于n(32)的图像*/
	int num_pyramid=0;
	int template_width;
	template_width=img_tpl.cols;
	while ((template_width/2) >= 16)
	{
		num_pyramid+=1;
		template_width=template_width/2;
	}
	buildPyramid(img_tpl,pyramid_template,num_pyramid);
	/*显示最上层金字塔*/
	Mat up_pyramid_tpl;
	up_pyramid_tpl=pyramid_template[pyramid_template.size()-1];
	imwrite("UpPyramidImg.bmp",up_pyramid_tpl);
	imshow("最顶层模板金字塔图像",up_pyramid_tpl);
	waitKey(20);

	/*
	* 创建和模板图像金字塔相同层数的目标搜索图像金字塔
	*/
	/*选取目标搜索图像*/
	Mat img_search;
	//img_search=imread("Search1.jpg",0);
	img_search=imread("pcb.bmp",0);
	imshow("原搜索图像",img_search);
	waitKey(20);
	/*创建搜索图像金字塔*/
	vector<Mat> pyramid_search;
	buildPyramid(img_search,pyramid_search,num_pyramid);
	/*显示最上层搜索图像金字塔*/
	Mat up_pyramid_search;
	up_pyramid_search=pyramid_search[pyramid_search.size()-1];
	imshow("最顶层搜索金字塔图像",up_pyramid_search);
	waitKey(20);
	
	/************************************************************************/
	/* image pyramid matching                                               */
	/************************************************************************/
	//vector<Mat> vec_tlp;
	//vec_tlp.push_back(up_pyramid_tpl);
	vector<Point> vec_top_letf;
	//vec_center=Image_Pyrimid_Matching_Top(up_pyramid_search,vec_tlp);
	vec_top_letf=Image_Pyramid_Matching_Top(up_pyramid_search,up_pyramid_tpl,1,0.856);



	waitKey();
	return 0;
}
#include "CommonHead.h"
//#include "UserLib.h"
#include "ImagePyramid.h"
int main()
{
	/************************************************************************/
	/*                        create pyramid                               */
	/************************************************************************/

	/*
	* ����ģ�������
	*/

	/*��ȡģ��ͼ��*/

	Mat img_tpl;
	//img_tpl=imread("Template.jpg",0);
	img_tpl=imread("template_0.bmp",0);
	imshow("ԭģ��ͼ��",img_tpl);
	cout<<img_tpl.channels()<<endl;
	waitKey(20);


	vector<Mat> pyramid_template;
	/*�������������ϲ�ͼ��߲�С��n(32)��ͼ��*/
	int num_pyramid=0;
	int template_width;
	template_width=img_tpl.cols;
	while ((template_width/2) >= 16)
	{
		num_pyramid+=1;
		template_width=template_width/2;
	}
	buildPyramid(img_tpl,pyramid_template,num_pyramid);
	/*��ʾ���ϲ������*/
	Mat up_pyramid_tpl;
	up_pyramid_tpl=pyramid_template[pyramid_template.size()-1];
	imwrite("UpPyramidImg.bmp",up_pyramid_tpl);
	imshow("���ģ�������ͼ��",up_pyramid_tpl);
	waitKey(20);

	/*
	* ������ģ��ͼ���������ͬ������Ŀ������ͼ�������
	*/
	/*ѡȡĿ������ͼ��*/
	Mat img_search;
	//img_search=imread("Search1.jpg",0);
	img_search=imread("pcb.bmp",0);
	imshow("ԭ����ͼ��",img_search);
	waitKey(20);
	/*��������ͼ�������*/
	vector<Mat> pyramid_search;
	buildPyramid(img_search,pyramid_search,num_pyramid);
	/*��ʾ���ϲ�����ͼ�������*/
	Mat up_pyramid_search;
	up_pyramid_search=pyramid_search[pyramid_search.size()-1];
	imshow("�������������ͼ��",up_pyramid_search);
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
#include "ImagePyramid.h"

/* 
* Image_Pyramid_Matching_Top
* template matching at top of pyramid 
* vector<Point> Image_Pyramid_Matching_Top(const Mat &img_gray, const Mat &img_template_gray, int num_loc, float match_score)
* Parameters
*           img_gray-object image.
*           img_template_gray-template image.
*           num_loc-num of find location.
*           match_score-matching score.
* the function Image_Pyramid_Matching_Top return num_loc top left location at top of pyramid .
*/
vector<Point> Image_Pyramid_Matching_Top(const Mat &img_gray, const Mat &img_template_gray, int num_loc, float match_score)
{
	vector<Point> vector_center;
	vector_center=Template_Matching(img_gray,img_template_gray, num_loc, match_score);
	return vector_center;
}


/* 
* Image_Pyramid_Matching_Bottom
* top matching mapping to next storey of image pyramid.
* vector<Point> Image_Pyramid_Matching_Bottom(const Mat &img_gray, const Mat &img_template_gray, vector<Point> pre_loc, float match_score)
* Parameters
*           img_gray - object image.
*           img_template_gray - template image.
*           pre_loc - locations found in pre storey of pyramid.
*           match_score - matching score.
* the function Image_Pyramid_Matching_Bottom return  top left locations corresponding to pre_loc at bottom pyramid .
*/
vector<Point> Image_Pyramid_Matching_Bottom(const Mat &img_gray, const Mat &img_template_gray, vector<Point> pre_loc, float match_score)
{
	vector<Point> vec_top_left;
	for (int i=0; i<pre_loc.size(); i++)
	{
		Point point_temp;
		point_temp=pre_loc[i];
		/* pre matching location mapping on current pyramid layer*/
		Point point_cur;
		point_cur=2 * point_temp;
		/*
		* searching start point location 
		*/
		Point point_start_search;
		/* x value */
		if (point_cur.x-2 >= 0)
		{
			point_start_search.x = point_cur.x - 2;
		}
		else if (point_cur.x - 1 >= 0)
		{
			point_start_search.x = point_cur.x - 1;
		}
		else 
		{
			point_start_search.x = point_cur.x;
		}
		/* y value */
		if (point_cur.y-2 >= 0)
		{
			point_start_search.y = point_cur.y - 2;
		}
		else if (point_cur.y - 1 >= 0)
		{
			point_start_search.y = point_cur.y - 1;
		}
		else 
		{
			point_start_search.y = point_cur.y;
		}
		/* 
		* searching end point location 
		*/
		Point point_end_search;
		/* x value */
		if (point_cur.x+2 <= img_gray.cols)
		{
			point_end_search.x = point_cur.x + 2;
		}
		else if (point_cur.x + 1 <= img_gray.cols)
		{
			point_end_search.x = point_cur.x + 1;
		}
		else 
		{
			point_end_search.x = point_cur.x;
		}
		/* y value */
		if (point_cur.y+2 <= img_gray.rows)
		{
			point_end_search.y = point_cur.y + 2;
		}
		else if (point_cur.y + 1 <= img_gray.rows)
		{
			point_end_search.y = point_cur.y + 1;
		}
		else 
		{
			point_end_search.y = point_cur.y;
		}
		
		/* corp matching sub img */
		Mat img_crop_search;
		img_crop_search = img_gray(Rect(point_start_search,point_end_search));
		/*
		* start template matching 
		*/
		vector<Point> vec_top_left_temp;
		vec_top_left_temp = Template_Matching(img_crop_search, img_template_gray, 1, match_score );
		vec_top_left.push_back(vec_top_left_temp[0]);

	}

	return vec_top_left;
}
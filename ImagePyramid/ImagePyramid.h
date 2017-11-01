#include "CommonHead.h"
#include "TemplateMatching.h"

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
vector<Point> Image_Pyramid_Matching_Top(const Mat &img_gray, const Mat &img_template_gray, int num_loc, float match_score);

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
vector<Point> Image_Pyramid_Matching_Bottom(const Mat &img_gray, const Mat &img_template_gray, vector<Point> pre_loc, float match_score);
#include "superpixel.h"

/*
 * Constructor.
 */
Superpixel::Superpixel()
{

}

Superpixel::Superpixel(int id, int num_points)
{
	this->id = id;
	this->num_points = num_points;
	init_structures(num_points);
	//this->pixels = cv::Mat(50, 50, CV_8UC3, cvScalar(0,0,0));
}


Superpixel::Superpixel(int id, int num_points, cv::Point center, cv::Mat histogram, point2Dvec points)
{
	this->id = id;
	this->num_points = num_points;
	this->center = center;
	this->histogram = histogram;
	this->points = points;
}


Superpixel::Superpixel(int id, cv::Point center)
{
	this->id = id;
	this->num_points = 0;
	this->center = center;
}

cv::Point Superpixel::get_center()
{
	return this->center;
}


cv::Mat Superpixel::get_histogram()
{
	return this->histogram;
}

point2Dvec Superpixel::get_points()
{
	return this->points;
}

void Superpixel::add_point(cv::Point point)
{
	this->points.push_back(point);
	this->num_points += 1;
}


void Superpixel::calculate_histogram()
{
	/// Separate the image in 3 places ( B, G and R )
	vector<cv::Mat> bgr_planes;
	split(this->pixels, bgr_planes);

	/// Establish the number of bins
	int histSize = 256;

	/// Set the ranges ( for B,G,R) )
	float range[] = { 0, 256 } ;
	const float* histRange = { range };

	bool uniform = true; 
	bool accumulate = false;

	cv::Mat b_hist, g_hist, r_hist;

	/// Compute the histograms:
	calcHist( &bgr_planes[0], 1, 0, this->pixels_mask, b_hist, 1, &histSize, &histRange, uniform, accumulate );
	calcHist( &bgr_planes[1], 1, 0, this->pixels_mask, g_hist, 1, &histSize, &histRange, uniform, accumulate );
	calcHist( &bgr_planes[2], 1, 0, this->pixels_mask, r_hist, 1, &histSize, &histRange, uniform, accumulate );

	// Draw the histograms for B, G and R
	int hist_w = this->pixels.cols;
	int hist_h = this->pixels.rows;
	int bin_w = cvRound( (double) hist_w/histSize );

	this->histogram = cv::Mat(hist_h, hist_w, CV_8UC3, cvScalar( 0,0,0));

	/// Normalize the result to [ 0, histImage.rows ]
	normalize(b_hist, b_hist, 0, this->histogram.rows, cv::NORM_MINMAX, -1, cv::Mat() );
	normalize(g_hist, g_hist, 0, this->histogram.rows, cv::NORM_MINMAX, -1, cv::Mat() );
	normalize(r_hist, r_hist, 0, this->histogram.rows, cv::NORM_MINMAX, -1, cv::Mat() );
}



void Superpixel::add_pixels_information(IplImage *img, vector<vector<int>> clusters)
{
	CvScalar colour;
	this->pixels = cv::Mat::zeros(this->bounding_rect.height, this->bounding_rect.width, CV_8UC3);
	this->pixels_mask = cv::Mat::zeros(this->bounding_rect.height, this->bounding_rect.width, CV_8UC1);

	int x_coord, y_coord;
	for (int j = bounding_rect.y; j < bounding_rect.y+bounding_rect.height ;j++)
	{
		y_coord = j - bounding_rect.y;
		for (int i = bounding_rect.x; i < bounding_rect.x+bounding_rect.width ;i++)	
		{
			if(this->id == clusters[i][j])
			{
				x_coord = i - bounding_rect.x;
				/*
				cout << i << "   "	<< j << "\n";
				cout << bounding_rect.x << "   "	<< bounding_rect.y << "\n\n\n";
				*/
				colour = cvGet2D(img, j, i);
				(this->pixels.at<cv::Vec3b>(y_coord, x_coord)).val[0] = colour.val[0];
				(this->pixels.at<cv::Vec3b>(y_coord, x_coord)).val[1] = colour.val[1];
				(this->pixels.at<cv::Vec3b>(y_coord, x_coord)).val[2] = colour.val[2];
				this->pixels_mask.at<uchar>(y_coord, x_coord) = 255;
			}
		}
	}
}


void Superpixel::init_structures(int num_points)
{
	int i;

    cv::Point invalidPoint(-1, -1);

    center = invalidPoint;

	for(i=0; i<num_points ;i++)
	{
		points.push_back(invalidPoint);
	}
}


void Superpixel::print_everything()
{
	int i;
	cout << "Superpixel #" << id << "\n";
	cout << "Number of points = " << num_points << "\n";
	cout << "Center = (" << center.x << ", " << center.y << ")" << "\n";
	cout << "Points:\n";
	for(int i=0; i<num_points ;i++)
	{
		cout << "(" << points[i].x << ", " << points[i].y << ")" << "\n";
	}

/*
	cout << "Histogram:\n";
	for(int i=0; i<256 ;i++)
	{
		cout << "Valor = " << i << ".	R = " << histogram[i][0] << ".	G = " << histogram[i][1] << ".	B = " << histogram[i][2] << ".\n";
	}
*/
}


void Superpixel::calculate_bounding_rect()
{
	this->bounding_rect = cv::boundingRect(this->points);
//	cout << "numero de pixels = " << this->pixels.size() << "	numero de puntos = " << this->points.size()  << "		rectangulo, ancho = " << bounding_rect.width << "   largo =" << bounding_rect.height << "\n";

	/*cv::Point pt1, pt2;
	pt1.x = rect.x;
	pt1.y = rect.y;
	pt2.x = rect.x + rect.width;
	pt2.y = rect.y + rect.height;
	rectangle(pixel_mask, pt1, pt2, CV_RGB(255,0,0), 1);
	cv::imshow("pixel_mask", pixel_mask);
	*/
}


void Superpixel::export_to_jpeg(IplImage *img)
{
	/*
	if(this->id == 1)
	{
		cv::imshow("superpixel", this->pixels);
	}
	*/
	//string path = "/home/mecatronica/Github_Yoshua/VisionPercepcion_USB2015/Codigos/Tesis_ws/src/Plane_Segmentation_3/superpixel_images/";
	string path = "/home/alfredoso/GitHub/VisionPercepcion_USB2015/Codigos/Tesis_ws/src/plane_segmentation_alpha/superpixel_images/";
	string pixels_file_name = to_string(this->id) + ".jpg";
	string pixels_mask_file_name = to_string(this->id) + "_mask.jpg";

	imwrite(path+pixels_file_name, this->pixels);
	imwrite(path+pixels_mask_file_name, this->pixels_mask);
}






 /*
 * Destructor. Clear any present data.
 */
Superpixel::~Superpixel() 
{
    clear_data();
}


/*
 * Clear the data as saved by the algorithm.
 *
 * Input : -
 * Output: -
 */
void Superpixel::clear_data() 
{
	//center.clear();
	points.clear();
}



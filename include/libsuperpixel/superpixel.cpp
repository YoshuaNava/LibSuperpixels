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


int Superpixel::get_id()
{
	return this->id;
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
	/// Establish the number of bins
	int histSize = 256;
	int hist_w = this->pixels.cols;
	int hist_h = this->pixels.rows;
	int bin_w = cvRound( (double) hist_w/histSize );

	this->histogram = cv::Mat(hist_h, hist_w, CV_32FC3, cvScalar(0.0,0.0,0.0));

	/// Set the ranges ( for B,G,R) )
	float range[] = { 0, 256 } ;
	const float* histRange = { range };
	int channels[] = {0,1,2};

	bool uniform = true; 
	bool accumulate = false;

	if(this->pixels.rows>0 && this->pixels.cols>0)
	{
		/// Compute the histograms:
		// cout << "EPALE\n";
		calcHist( &this->pixels, 1, channels, this->pixels_mask, this->histogram, 1, &histSize, &histRange, uniform, accumulate );
		// cout << "hola\n";
		// /// Normalize the result to [ 0, histImage.rows ]
		normalize(this->histogram, this->histogram, 0, this->histogram.rows, cv::NORM_MINMAX, -1, cv::Mat() );
	}
}



void Superpixel::add_pixels_information(IplImage *img, vector<vector<int>> clusters)
{
	int i, j;
	int min_x, max_x, min_y, max_y, sp_height, sp_width;
	min_x = img->width;
	min_y = img->height;
	max_x = 0;
	max_y = 0;
	for(i=0; i<points.size() ;i++)
	{
		if(points[i].x < min_x)
		{
			min_x = points[i].x;
		}
		if(points[i].y < min_y)
		{
			min_y = points[i].y;
		}
		if(points[i].x > max_x)
		{
			max_x = points[i].x;
		}
		if(points[i].y > max_y)
		{
			max_y = points[i].y;
		}
	}
//	cout << "min_x " << min_x << "  max_x " << max_x << "   min_y " << min_y << "  max_y " << max_y << "\n";
	sp_height = max_y - min_y;
	sp_width = max_x - min_x;
	CvScalar colour;
	this->pixels = cv::Mat::zeros(sp_height, sp_width, CV_8UC3);
	this->pixels_mask = cv::Mat::zeros(sp_height, sp_width, CV_8UC1);

	int x_coord, y_coord;
	for (int j = min_y; j < max_y ;j++)
	{
		y_coord = j - min_y;
		for (int i = min_x; i < max_x ;i++)	
		{
			if(this->id == clusters[i][j])
			{
				x_coord = i - min_x;

				colour = cvGet2D(img, j, i);
				(this->pixels.at<cv::Vec3b>(y_coord, x_coord)).val[0] = colour.val[0];
				(this->pixels.at<cv::Vec3b>(y_coord, x_coord)).val[1] = colour.val[1];
				(this->pixels.at<cv::Vec3b>(y_coord, x_coord)).val[2] = colour.val[2];
				this->pixels_mask.at<uchar>(y_coord, x_coord) = 255;
			}
		}
	}
}


void Superpixel::add_pixels_information(cv::Mat img, vector<vector<int>> clusters)
{
	int i, j;
	int min_x, max_x, min_y, max_y, sp_height, sp_width;
	min_x = img.cols;
	min_y = img.rows;
	max_x = 0;
	max_y = 0;
	for(i=0; i<points.size() ;i++)
	{
		if(points[i].x < min_x)
		{
			min_x = points[i].x;
		}
		if(points[i].y < min_y)
		{
			min_y = points[i].y;
		}
		if(points[i].x > max_x)
		{
			max_x = points[i].x;
		}
		if(points[i].y > max_y)
		{
			max_y = points[i].y;
		}
	}
//	cout << "min_x " << min_x << "  max_x " << max_x << "   min_y " << min_y << "  max_y " << max_y << "\n";
	sp_height = max_y - min_y;
	sp_width = max_x - min_x;
	CvScalar colour;
	this->pixels = cv::Mat::zeros(sp_height, sp_width, CV_8UC3);
	this->pixels_mask = cv::Mat::zeros(sp_height, sp_width, CV_8UC1);

	int x_coord, y_coord;
	for (int j = min_y; j < max_y ;j++)
	{
		y_coord = j - min_y;
		for (int i = min_x; i < max_x ;i++)	
		{
			if(this->id == clusters[i][j])
			{
				x_coord = i - min_x;

				(this->pixels.at<cv::Vec3b>(y_coord, x_coord)).val[0] = img.at<cv::Vec3b>(j,i).val[0];
				(this->pixels.at<cv::Vec3b>(y_coord, x_coord)).val[1] = img.at<cv::Vec3b>(j,i).val[1];
				(this->pixels.at<cv::Vec3b>(y_coord, x_coord)).val[2] = img.at<cv::Vec3b>(j,i).val[2];
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
}




void Superpixel::export_to_jpeg(IplImage *img)
{
	//string path = "/home/mecatronica/Github_Yoshua/VisionPercepcion_USB2015/Codigos/Tesis_ws/src/Plane_Segmentation_3/superpixel_images/";
	string path = "/home/alfredoso/GitHub/VisionPercepcion_USB2015/Codigos/Tesis_ws/src/usbgm_pfs/superpixel_images/";
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



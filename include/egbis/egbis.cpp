

#include "egbis.h"

using namespace std;
using namespace cv;


/*
 * Constructor. Nothing is done here.
 */
Egbis::Egbis() {

}

/*
 * Destructor. Clear any present data.
 */
Egbis::~Egbis() {
    clear_data();
}


/*
 * Clear the data as saved by the algorithm.
 *
 * Input : -
 * Output: -
 */
void Egbis::clear_data() {
	clusters.clear();
	superpixels_centers_count.clear();
	superpixels_centers.clear();
	superpixels_list.clear();
	superpixels_adjacency_matrix.clear();
	superpixels_similarity_matrix.clear();
}


cv::Mat Egbis::displayCenterGrid(cv::Mat image, CvScalar colour) 
{
    for (int i=0; i<num_superpixels ;i++) 
    {
        cv::circle(image, cvPoint(superpixels_centers[i].x, superpixels_centers[i].y), 2, colour, 2);
    }

    return image;
}

cv::Mat Egbis::displayNumberGrid(cv::Mat image, CvScalar colour)
{
    for (int i = 0; i < (int) superpixels_list.size(); i++) {
        char buffer[25];
        sprintf(buffer, "%i", i);
        cv::putText(image, buffer, cvPoint(superpixels_centers[i].x, superpixels_centers[i].y), CV_FONT_HERSHEY_SIMPLEX, 0.3, colour, 1, CV_AA);
    }

    return image;
}



vector<Superpixel> Egbis::storeSuperpixelsMemory()
{
    int i, x, y, k;
    int index = 0;
    cv::Point temp_point;
    superpixels_adjacency_matrix.resize(num_superpixels);
    const int dx[8] = {-1, -1, -1, 0, +1, +1, +1, 0};
    const int dy[8] = {-1, 0, +1, +1, +1, 0, -1, -1};

    for(i = 0 ; i < num_superpixels ;++i)
    {
        //Grow Columns by n
        superpixels_adjacency_matrix[i].resize(num_superpixels);
        std::fill(superpixels_adjacency_matrix[i].begin(), superpixels_adjacency_matrix[i].end(), 0);
    }
    for (i = 0; i < num_superpixels ;i++) 
    {
        temp_point = cvPoint(superpixels_centers[i].x, superpixels_centers[i].y);
        Superpixel sp(i, temp_point);
        superpixels_list.push_back(sp);
    }

    for (x = 0; x < frame.cols; x++)
    {
        for (y = 0; y < frame.rows; y++)
        {
    		// cout << "num SuperPixels  " << superpixels_list.size() << "\n";
      //       cout << "hola " << clusters[x][y] << "\n";
            if(clusters[x][y] != -1)
            {
                index = clusters[x][y];
            }
            //CvScalar colour = cvGet2D(image, y, x);
            temp_point = cv::Point(x, y);

            //cout << index << "\n";
            superpixels_list[index].add_point(temp_point);
            for(k=0; k<8 ;k++)
            {
                if(((x+dx[k]>=0) && (x+dx[k]<frame.cols)) && ((y+dy[k]>=0) && (y+dy[k]<frame.rows)))
                {
                    if(clusters[x+dx[k]][y+dy[k]] == index)
                    {
                         superpixels_adjacency_matrix[index][index] = -1;
                    }
                    else
                    {
                        //cout << "index = " << index << "    x+dx[k] = " << x+dx[k] << "     y+dy[k] = " << y+dy[k] << "\n";
                        if(clusters[x+dx[k]][y+dy[k]] != -1)
                        {
                            superpixels_adjacency_matrix[index][clusters[x+dx[k]][y+dy[k]]] = 1;
                            superpixels_adjacency_matrix[clusters[x+dx[k]][y+dy[k]]][index] = 1;
                        }
                    }
                }
            }
        }
    }
    // cout << "bye\n";


    // for(i=0; i<num_superpixels ;++i)
    // {
    //     for(k=0; k<num_superpixels ;k++)    //Grow Columns by n
    //     {
    //         cout << (int) superpixels_adjacency_matrix[i][k] << "   ";
    //     }
    //     cout << "\n";
    // }
    // cout << "**************************************************************************************\n";

    for (i = 0; i < (int) superpixels_list.size(); i++) 
    {
  //   	vector<cv::Point> points = superpixels_list[i].get_points();
		// cout << "superpixel  " << superpixels_list[i].get_id() << "	points count  " << points.size() << "\n";
        //superpixels_list[i].calculate_bounding_rect();
        superpixels_list[i].add_pixels_information(frame, clusters);
        superpixels_list[i].calculate_histogram();
    }

    return superpixels_list;
}



void Egbis::calculateSuperpixelCenters()
{
	int j, k, c_id;
    /* Compute the new cluster centers. */
    for (j=0; j<frame.cols ;j++) 
    {
        for (k = 0; k<frame.rows ;k++) 
        {
            c_id = clusters[j][k];
            
            if (c_id != -1) 
            {
            	superpixels_centers[c_id].x += j;
            	superpixels_centers[c_id].y += k;    
                superpixels_centers_count[c_id] += 1;
            }
        }
    }

    /* Normalize the clusters. */
    for (j=0; j<num_superpixels ;j++) {
    	//cout << "superpixel  " << j << "	centers count  " << superpixels_centers_count[j] << "\n";
        superpixels_centers[j].x /= superpixels_centers_count[j];
        superpixels_centers[j].y /= superpixels_centers_count[j];
    }

}



cv::Mat Egbis::outlineSuperpixelsContours(CvScalar colour) 
{
	contours_image = frame.clone();
    const int dx8[8] = {-1, -1,  0,  1, 1, 1, 0, -1};
	const int dy8[8] = { 0, -1, -1, -1, 0, 1, 1,  1};
	
	/* Initialize the contour vector and the matrix detailing whether a pixel
	 * is already taken to be a contour. */
	vector<CvPoint> contours;
	vector<vector<bool>> istaken;
	for (int i = 0; i < seg_image.cols; i++) { 
        vector<bool> nb;
        for (int j = 0; j < seg_image.rows; j++) {
            nb.push_back(false);
        }
        istaken.push_back(nb);
    }
    
    /* Go through all the pixels. */
    for (int i = 0; i < seg_image.cols; i++) {
        for (int j = 0; j < seg_image.rows; j++) {
            int nr_p = 0;
            
            /* Compare the pixel to its 8 neighbours. */
            for (int k = 0; k < 8; k++) {
                int x = i + dx8[k], y = j + dy8[k];
                
                if (x >= 0 && x < seg_image.cols && y >= 0 && y < seg_image.rows) {
                    if (istaken[x][y] == false && clusters[i][j] != clusters[x][y]) {
                        nr_p += 1;
                    }
                }
            }
            
            /* Add the pixel to the contour list if desired. */
            if (nr_p >= 2) {
                contours.push_back(cvPoint(i,j));
                istaken[i][j] = true;
            }
        }
    }
    
    /* Draw the contour pixels. */
    for (int i = 0; i < (int)contours.size(); i++) {
		contours_image.at<cv::Vec3b>(contours[i].y, contours[i].x).val[0] = colour.val[0];
		contours_image.at<cv::Vec3b>(contours[i].y, contours[i].x).val[1] = colour.val[1];
		contours_image.at<cv::Vec3b>(contours[i].y, contours[i].x).val[2] = colour.val[2];
    }

    return contours_image;
}



cv::Mat Egbis::generateSuperpixels(cv::Mat image, cv::Mat gray_image)
{
	this->frame = image.clone();
	this->gray = gray_image.clone();
	clusters.clear();
	superpixels_centers_count.clear();
	superpixels_centers.clear();
	superpixels_list.clear();
	superpixels_adjacency_matrix.clear();
	superpixels_similarity_matrix.clear();



	IplImage gray_temp = (IplImage)gray;
	IplImage* ipl_gray = &gray_temp; // Reference on deallocating memory: http://stackoverflow.com/questions/12635978/memory-deallocation-of-iplimage-initialised-from-cvmat
	IplImage* seg = cvCreateImage(cv::Size(frame.cols, frame.rows), 8, 1);;

    static int num_ccs;
    static float sigma;
    static float k;

            //printf("processing\n");
    floatsigma = (float)int_sigma*0.1;
    k = (float)int_k;
    SegmentImage(seg, ipl_gray, sigma, k, min_size, &num_ccs);

    seg_image = cv::cvarrToMat(seg, true, true, 0);
    cvReleaseImage(&seg);
	num_superpixels = -1;
	int i, j;
	for(i=0; i<seg_image.cols ;i++)
	{
		vector<int> seg_row;
		for(j=0; j<seg_image.rows ;j++)
		{
//			cout << "u = " << j << "  ;  v = " << i << "	;	Superpixel = " << seg_image.at<uchar>(i,j) << "\n";
			seg_row.push_back((int)seg_image.at<uchar>(j,i));
			if((int)seg_image.at<uchar>(j,i) > num_superpixels)
			{
				num_superpixels = seg_image.at<uchar>(j,i);
			}
		}
		clusters.push_back(seg_row);
	}
	num_superpixels = num_superpixels + 1;
    cout << " num of superpixels    " << num_superpixels << "\n";

	for(i=0; i<num_superpixels ;i++)
	{
		superpixels_centers.push_back(cv::Point(0.0, 0.0));
		superpixels_centers_count.push_back(1);
	}


	return seg_image;
}



vector<Superpixel> Egbis::get_superpixels()
{
    return this->superpixels_list;
}
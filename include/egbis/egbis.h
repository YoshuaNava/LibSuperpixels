#ifndef EGBIS_H
#define EGBIS_H


/* egbis.h.
 *
 * Written by: Yoshua Nava and Rafael Colmenares
 * Authors of the EGBIS algorithm: Felzenswalb and Huttenlocher
 *
 */


#include "convolve.h"
#include "disjoint-set.h"
#include "filter.h"
#include "image.h"
#include "imconv.h"
#include "imutil.h"
#include "misc.h"
#include "pnmfile.h"
#include "segment-graph.h"
#include "segment-image.h"
#include <libsuperpixel/superpixel.h>


 class Egbis {
 	private:
		int int_sigma = 5;
		int int_k = 100;
		int min_size = 100;
		float floatsigma;
		const char * GBS 		= "seg"; //"Graph Based Segmentation";
		vector<vector<int>> clusters;
		int num_superpixels = -1;
		vector<int> superpixels_centers_count;
		vector<cv::Point> superpixels_centers;
		vector<Superpixel> superpixels_list;
		vector<vector<int>> superpixels_adjacency_matrix;
		vector<vector<int>> superpixels_Gsimilarity_matrix;
		cv::Mat frame, seg_image, gray, contours_image;

	public:
		Egbis();
        ~Egbis();

        void clear_data();

		cv::Mat generateSuperpixels(cv::Mat image, cv::Mat gray_image);
		cv::Mat outlineSuperpixelsContours(CvScalar colour);
		void calculateSuperpixelCenters();
		vector<Superpixel> storeSuperpixelsMemory();
		cv::Mat displayCenterGrid(cv::Mat image, CvScalar colour);
		cv::Mat displayNumberGrid(cv::Mat image, CvScalar colour);
 };


 #endif

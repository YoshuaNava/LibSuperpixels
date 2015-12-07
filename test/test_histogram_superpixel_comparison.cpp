
#include "../include/global.h"

//#include "slic_superpixels/slic.h"



//macros for stopwatch
//REFERENCE: https://sites.google.com/site/mikesapi/downloads/ground-plane-segmentation-and-autonomous-guidance
#define CV_TIMER_START(X)       	double X = (double)cvGetTickCount();
#define CV_TIMER_STOP(Y, STRING) 	double Y = (double)cvGetTickCount() - X; \
                                            printf("Time @ [%s] = %gms\n", \
                                            STRING, Y/((double)cvGetTickFrequency()*1000.) );

#define Window_W 1.02*proc_W //appriximate wht window width and hight as a function of the frame size
#define Window_H 1.3*(proc_H)+20
#define DISPLAY_IMAGE_XY(R,img,X,Y)		if(R){cvNamedWindow(#img); cvMoveWindow(#img, int(round(X*Window_W)), int(round(Y*Window_H))) ;} cv::imshow(#img, img);
#define SUPERPIXEL_ALGORITHM 	"SLIC"
using namespace std;
using namespace cv;


cv::Mat frame, seg_image, gray, superpixels_contours_img; // Mat Declarations


double proc_W, proc_H;
VideoCapture cap;

Slic slic;
Egbis egbis;


void compareHistograms(int base_sp_id, int test1_sp_id, int test2_sp_id)
{
	printf("Superpixels histogram comparison. Methods: 1) Correlation, 2) Chi-Square, 3) Intersection, and 4) Bhattacharyya distance\n");

	vector<Superpixel> superpixels_list;
	if(SUPERPIXEL_ALGORITHM == "EGBIS")
	{
		superpixels_list = egbis.get_superpixels();
	}
	else
	{
		superpixels_list = slic.get_superpixels();	
	}

	for( int i = 0; i < 4; i++ )
    {
		if((superpixels_list.size() >= base_sp_id) && (superpixels_list.size() >= test1_sp_id) && (superpixels_list.size() >= test2_sp_id))
		{
			int compare_method = i;
			double base_base = compareHist( superpixels_list[base_sp_id].get_histogram(), superpixels_list[base_sp_id].get_histogram(), compare_method );
		    double base_test1 = compareHist( superpixels_list[base_sp_id].get_histogram(), superpixels_list[test1_sp_id].get_histogram(), compare_method );
		    double base_test2 = compareHist( superpixels_list[base_sp_id].get_histogram(), superpixels_list[test2_sp_id].get_histogram(), compare_method );
		    printf( " Method [%d]: Superpixel %i against itself, Superpixels %i and %i, Superpixels %i and %i : %f,   %f,   %f \n", i, base_sp_id, base_sp_id, test1_sp_id, base_sp_id, test2_sp_id, base_base, base_test1, base_test2 );
		}
	}

}


void showImages()
{
	DISPLAY_IMAGE_XY(true, frame, 0, 0);
	cv::resizeWindow("frame", proc_W, proc_H);
	DISPLAY_IMAGE_XY(true, superpixels_contours_img, 1, 0);
	cv::resizeWindow("superpixels_contours_img", proc_W, proc_H);
}


void slicSuperpixels()
{
	seg_image = frame.clone();
	IplImage frame2 = (IplImage)seg_image; // Reference on deallocating memory: http://stackoverflow.com/questions/12635978/memory-deallocation-of-iplimage-initialised-from-cvmat

	/* Yield the number of superpixels and weight-factors from the user. */
	IplImage *lab_image = cvCloneImage(&frame2);
	cvCvtColor(&frame2, lab_image, CV_BGR2Lab);
	int w = lab_image->width, h = lab_image->height;
	int nr_superpixels = 6*proc_W;
	int nc = 20;
	double step = sqrt((w * h) / (double) nr_superpixels)*3;

	/* Perform the SLIC superpixel algorithm. */
	slic.clear_data();
	slic.generate_superpixels(lab_image, step, nc);
	slic.create_connectivity(lab_image);
	slic.store_superpixels(&frame2);

	slic.display_contours(&frame2, CV_RGB(255,0,0));
	//slic.display_center_grid(&frame2, CV_RGB(0,255,0));
	slic.display_number_grid(&frame2, CV_RGB(0,255,0));
	superpixels_contours_img = cv::cvarrToMat(&frame2, true, true, 0);

	cvReleaseImage(&lab_image);
}



void egbisSuperpixels()
{
	seg_image = egbis.generateSuperpixels(frame, gray);
    superpixels_contours_img = egbis.outlineSuperpixelsContours(cv::Scalar(255,0,0));
    egbis.calculateSuperpixelCenters();
    egbis.storeSuperpixelsMemory();
    superpixels_contours_img = egbis.displayCenterGrid(superpixels_contours_img, cv::Scalar(0,255,0));
    //superpixels_contours_img = egbis.displayNumberGrid(superpixels_contours_img, cv::Scalar(0,255,0));
}

void cameraSetup()
{
  	//cap = VideoCapture(0);
	cap = VideoCapture("../eng_stat_obst.avi");
	
//	proc_W = 160;//160
//	proc_H = 120;//120
	proc_W = 320;//160
	proc_H = 240;//120
	cap.set(CV_CAP_PROP_FRAME_WIDTH, 640);
	cap.set(CV_CAP_PROP_FRAME_HEIGHT, 480);
	// Good reference: http://superuser.com/questions/897420/how-to-know-which-framerate-should-i-use-to-capture-webcam-with-ffmpeg
	cap.set(CV_CAP_PROP_FPS, 30);
}



/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%            MAIN           %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/
int main( int argc, char** argv ) 
{
	cameraSetup();
	cap.read(frame);
	printf("******************************************\n");
	printf("Probabilistic Ground Plane Segmentation\n");
	printf("Authors: Rafael Colmenares and Yoshua Nava\n");
	printf("******************************************\n");
	char key_stroke = 0;

	waitKey(0);
    
	while ((key_stroke!=27) && (key_stroke!=10))
	{
		CV_TIMER_START(X)
		//cap >> frame; // Image from Cam to Mat Variable
		if (!cap.read(frame)) 
		{
			std::cout << "Unable to retrieve frame from video stream." << std::endl;
			continue;
		}

		printf("#######################################\n");
		CV_TIMER_STOP(A, "Received image from camera")
		cv:resize(frame, frame, Size(proc_W, proc_H), 0, 0, INTER_AREA);
		cvtColor(frame, gray, CV_BGR2GRAY);
		waitKey(1); // Wait Time
		seg_image = frame.clone();

		if(SUPERPIXEL_ALGORITHM == "EGBIS")
		{
			egbisSuperpixels();
		}
		else if(SUPERPIXEL_ALGORITHM == "SLIC")
		{
			slicSuperpixels();
		}
		CV_TIMER_STOP(B, "Superpixels processed")


		compareHistograms(11, 23, 104);
		CV_TIMER_STOP(C, "Three superpixel histograms compared")
		showImages();


		CV_TIMER_STOP(Z, "Loop finished")
		printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	 	
	 	char key_stroke = waitKey(3);
	}


	cap.release(); //Destroy the Capture from webcam
	destroyAllWindows(); //Destroy the windows

	return 0;
}

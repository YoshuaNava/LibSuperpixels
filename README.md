# LibSuperpixels
C++ library designed to handle superpixels information, using OpenCV.


Authors:
	Yoshua Nava
	Rafael Colmenares

## Instructions to compile and run the code:

1. Open a terminal and to the the repository root directory ("slic_egbis_segmentation/").

2. Type the following commands to compile everything:

mkdir build
cd build
cmake ..
make

3. To run the EGBIS superpixel segmentation test, type:

./test_egbis_superpixel_segmentation


4. To run the EGBIS superpixel segmentation test, type:

./test_slic_superpixel_segmentation


5. To run the superpixel histogram comparison test, type:

./test_histogram_superpixel_comparison


If you want to change the algorithm that is used for generating and comparing superpixels, change the value of the constant SUPERPIXEL_ALGORITHM (line 18) for either "EGBIS" or "SLIC"



## Contributions:

A library for handling superpixels called "libsuperpixel", that can be found in the folder include/libsuperpixel.

A wrapper for the egbis algorithm, which can be found in include/egbis, and is mainly concentrated in the files egbis.cpp and egbis.h.

A modification of the default SLIC library files, so that they can be compliant with libsuperpixel.




## Acknowledgements

To Professor José Cappelletto and Rafael Colmenares, supervisors of this work.

To Michael Sapienza, author of the dataset that is provided by default with this package ("eng_stat_obst.avi").

To the authors of the SLIC algorithm and its OpenCV wrapper (Achanta, Shaji, et al. And GitHub user PSMM).

To the authors of the EGBIS algorithm and its OpenCV wrapper (Felzenswalb, Huttenlocher, and Michael Sapienza).

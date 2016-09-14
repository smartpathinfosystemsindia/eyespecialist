/*************************************************(((
*
*              Fukebane     : eyerecognition.cpp
*		Description :  window launcher for the red eye detection tool
*
* 		Copyright (C) Smartpath infosystems india, Bangalore
*		email to us for further information on team@smartpathindia.com
*
*
*
*
*
****************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "eyerecognition.h"



EyeRecognition::EyeRecognition(const char *trainingdir)
{
	//trainingdirectory = trainingdir;
}

int EyeRecognition::set_training_path(const char *trainingpath)
{
memset(trainingdata, 0, 512);
strcpy(trainingdata, trainingpath);
}




int EyeRecognition::faceCount(char *imgfile, char *reffile)
{
int ret = -1;
CvHaarClassifierCascade* cascade;
        IplImage *img, *gray;
        CvMemStorage *storage;
        CvSeq *faces;
       CvRect *rect = NULL;
	img = cvLoadImage(imgfile, 1);
	if(!img) {
		printf("failed to load image\n");
		return -1;
	}

	cascade = (CvHaarClassifierCascade*)cvLoad(reffile, 0, 0, 0);
	if(!cascade) {
		printf("failed to load xml\n");
		goto release1;
	}

	gray = cvCreateImage(cvSize(img->width, img->height), 8, 1);
	cvCvtColor(img, gray, CV_BGR2GRAY);
	if(!gray) {
		printf("failed to allocate memory");
		goto release2;
	}
	cvEqualizeHist(gray, gray);

	printf("came here");

	storage = cvCreateMemStorage(0);
	if(!storage) {
		printf("failed to allocate memory");
		goto release3;
	}



	printf("faces found");

	faces = cvHaarDetectObjects(gray, cascade, storage, 1.1, 2, CV_HAAR_DO_CANNY_PRUNING, cvSize(0, 0));
		ret = faces->total;
		if(faces && faces->total > 0) {
			int i;
			for(i = 0; i < faces->total; i++) {
			rect = (CvRect *)cvGetSeqElem(faces, i);
			}
		}
	cvReleaseMemStorage(&storage);
release3:
	cvReleaseImage(&gray);
release2:
	cvReleaseImage(&img);
release1:
	return ret;
}

int  EyeRecognition::detectface(char *imagename)
{
int ret=faceCount(imagename, trainingdata);
return ret;
}

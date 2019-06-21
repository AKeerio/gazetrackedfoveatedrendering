#include "PupilDetect.h"
#include <windows.h>
#include <time.h>



//The coordinates of pupil when buttons on calibration form were pressed
PupilPosition coordinates[9] = { 0 };

/**Constructor of pupil Object*/
PupilDetect::PupilDetect()
{
	counter = 0;
	bool isCalibrating = false;
	double toDelay = clock();
}

/**
*Reads the image from camera
*/
cv::Mat PupilDetect::getOriginalImage(cv::VideoCapture cap)
{

	cv::namedWindow("Panel");	cv::resizeWindow("Panel", 200, 20);

	if (!cap.isOpened())
		throw static_cast<std::string>("Image is NULL. Cannot get video");

	cv::Mat img;
	cap.read(img);
	cvWaitKey(10);
	currentFrame = img;
	flip(currentFrame, currentFrame, 1);

	return currentFrame;
}

/**
*Isolate the region where eye is detected
*/
void PupilDetect::findEye()
{
	cv::CascadeClassifier eyeCascade("haarClassifiers\\haarcascade_eye.xml");

	eyeCascade.detectMultiScale(currentFrame, eye, 1.1, 10, CV_HAAR_SCALE_IMAGE | CV_HAAR_DO_CANNY_PRUNING, cvSize(0, 0), cvSize(300, 300));
	for (int i = 0; i < eye.size(); i++)
	{
		cv::Point center(eye[i].x, eye[i].y);
		int radius = cvRound((eye[i].width + eye[i].height));
		cv::circle(currentFrame, center, radius, cv::Scalar(255, 0, 0), 2, 8, 0);
	}
}

/**
*Applies desired threshold to current frame
*/
void PupilDetect::applyThreshold(int threshHoldIntensity)
{
	cv::Mat  bwFrame;

	cvtColor(this->currentFrame, bwFrame, CV_BGR2GRAY);
	cv::GaussianBlur(bwFrame, thresholdFrame, cv::Size(5, 5), 10);
	cv::threshold(thresholdFrame, thresholdFrame, threshHoldIntensity, 255, cv::THRESH_BINARY);

	this->thresholdFrame = thresholdFrame;
}

/**
*Finds the contours in current frame and stores them in a vector object
*/
void PupilDetect::findContours(cv::Mat thresholdFrame)
{
	std::vector<std::vector<cv::Point>> contours;
	cv::findContours(thresholdFrame, contours, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, cv::Point(0, 0));
	this->contours = contours;
}
/**
*Draws the contours onto the frame for debugging purposes
*To find the center of each contour it finds their center of masses first
*Also draw the points acquired during calibration
*/
void PupilDetect::drawContours(std::vector<std::vector<cv::Point>> contours)
{
	std::vector<cv::Vec4i> heirarchy;

	std::vector<std::vector<cv::Point>> contours_poly(contours.size());
	std::vector<cv::Point2f> center(contours.size());
	std::vector<float> radius(contours.size());

	//find the center points of each contour
	for (int i = 0; i < contours.size(); i++)
	{
		cv::approxPolyDP(cv::Mat(contours[i]), contours_poly[i], 3, true);
		cv::minEnclosingCircle((cv::Mat)contours_poly[i], center[i], radius[i]);
	}

	//Draw contours on the frame
	for (int i = 0; i < contours.size(); i++)
	{
		approxPolyDP(cv::Mat(contours[i]), contours_poly[i], 3, true);
		//Put a reference point at the center of the frame
		cv::Point imageCenter(currentFrame.cols / 2, currentFrame.rows / 2);
		circle(currentFrame, imageCenter, 2, cv::Scalar(0, 255, 0), 3, 8, 0);

		approxPolyDP(cv::Mat(contours[0]), contours_poly[i], 0.01*cv::arcLength(contours[i], true), true);
		double area = cv::contourArea(contours[i]);
		if (contours_poly.size() < 100 && area > minArea && area < maxArea)
		{
			int testArg = i;
			//cv::drawContours(currentFrame, contours, i, cv::Scalar(0, 0, 255), 2, 8, heirarchy, 0, cv::Point());
			std::string coords = std::to_string((int)center[testArg].x - currentFrame.cols / 2) + ", " + std::to_string((int)(center[testArg].y - currentFrame.rows / 2)*-1);
			position.x = center[testArg].x;
			position.y = center[testArg].y;
			//Write coordinates on frame
			cv::putText(currentFrame, coords, cv::Point(center[testArg].x, center[testArg].y), cv::FONT_HERSHEY_COMPLEX_SMALL, 0.8, cvScalar(0, 255, 0), 1, CV_AA);
			cv::RotatedRect ellipse = cv::fitEllipse(contours[i]);
			cv::ellipse(currentFrame, ellipse, cv::Scalar(0, 0, 255), 2);
			//line(currentFrame, imageCenter, center[testArg], cv::Scalar(0, 255, 0), 1);
		}
	}
	if (GetAsyncKeyState(VK_RETURN) && isCalibrating && (clock() - toDelay > 300)) {
		if (counter > 9)
		{
			isCalibrating = false;
		}
		PupilPosition calibPoint;
		calibPoint.x = position.x;
		calibPoint.y = position.y;
		coordinates[counter] = calibPoint;
		counter++;
		toDelay = clock();
	}

	for (int i = 0; i < 9; i++)
	{
		cv::Point coord(coordinates[i].x, coordinates[i].y);
		circle(currentFrame, coord, 2, cv::Scalar(255, 0, 0), 10, 8, 0);
	}
	cv::Point point1(coordinates[0].x, coordinates[0].y);
	cv::Point point2(coordinates[1].x, coordinates[1].y);
	cv::Point point3(coordinates[2].x, coordinates[2].y);
	cv::Point point4(coordinates[3].x, coordinates[3].y);
	cv::Point point5(coordinates[4].x, coordinates[4].y);
	cv::Point point6(coordinates[5].x, coordinates[5].y);
	cv::Point point7(coordinates[6].x, coordinates[6].y);
	cv::Point point8(coordinates[7].x, coordinates[7].y);
	cv::Point point9(coordinates[8].x, coordinates[8].y);

	line(currentFrame, point1, point2, cv::Scalar(0, 255, 0), 1);
	line(currentFrame, point2, point3, cv::Scalar(0, 255, 0), 1);
	line(currentFrame, point3, point4, cv::Scalar(0, 255, 0), 1);
	line(currentFrame, point4, point5, cv::Scalar(0, 255, 0), 1);
	line(currentFrame, point5, point6, cv::Scalar(0, 255, 0), 1);
	line(currentFrame, point6, point7, cv::Scalar(0, 255, 0), 1);
	line(currentFrame, point7, point8, cv::Scalar(0, 255, 0), 1);
	line(currentFrame, point8, point9, cv::Scalar(0, 255, 0), 1);
}


/**
*Gets the pupil cordinates from calibration form and stores them
* id is the identifiers of a calibration point or a button
*/
void PupilDetect::setCoordinates(int id)
{
	if (counter > 8)counter = 0;
	PupilPosition calibPoint;
	calibPoint.x = position.x;
	calibPoint.y = position.y;
	coordinates[counter] = calibPoint;
	counter++;
}

/**
*Puts together all funcitons in order to detect pupil
*/
void PupilDetect::detectPupil(cv::VideoCapture capture)
{
	play = true;
	while (play)
	{
		getOriginalImage(capture);
		//findEye();
		applyThreshold(thresholdIntensity);
		findContours(thresholdFrame);
		drawContours(contours);
	}

}

/**
*Stops video capture when the main program has been stopped
*@param playIn A boolean to decide if video should play or not
*/
void PupilDetect::setVideoStatus(bool playIn)
{
	play = playIn;
	cvDestroyWindow("Panel");
}

/**
*Gets the array of coordinates acquired during calibration
*/
PupilPosition * PupilDetect::getCoordinates()
{
	return coordinates;
}

/**
*Determines if the program is in calibration phase
*/
void PupilDetect::initCalibration()
{
	counter = 0;
	for (int i = 0; i < 9; i++)
	{
		coordinates[i].x = 0;
		coordinates[i].y = 0;
	}
	isCalibrating = true;
}

/**
* Gets the width and height or the camera frame
*/
PupilPosition PupilDetect::getFrameDimensions()
{
	PupilPosition dimensions;
	dimensions.x = currentFrame.cols;
	dimensions.y = currentFrame.rows;
	return dimensions;
}

/**
*Returns a frame after a pupil has been found
*/
cv::Mat PupilDetect::getProcessedFrame()
{
	return currentFrame;
}

/**
*Returns current coordinates of the pupil
*/
PupilPosition PupilDetect::getPupilPosition()
{
	return position;
}

/**
*Gets new value from threshold slider in the main GUI
*/
void PupilDetect::setThreshold(int thresholdIn)
{
	thresholdIntensity = thresholdIn;
}

/**
*Gets new value from maximum area slider in the main GUI
*@param maxAreaIn The value that is to set as maximum
*/
void PupilDetect::setMaxArea(int maxAreaIn)
{
	maxArea = maxAreaIn;

}

/**
*Gets new value from minimum area slider in the main GUI
*@param minAreaIn The value that is to set as maximum
*/
void PupilDetect::setMinArea(int minAreaIn)
{
	minArea = minAreaIn;
}

/**PupilDetect Object destructor*/
PupilDetect::~PupilDetect()
{
}
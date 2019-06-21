#include "Tracker.h"
#include "PupilDetect.h"
#include <Windows.h>


PupilPosition coords[9];

/**Tracker object constructor
*/
Tracker::Tracker()
{
}

/**
*This function will get current cooridnates of the pupil to be used in cursor location calculation
@param xIn, yIn Current coordinates of the pupil centre
*/
void Tracker::setPupilPosition(int xIn, int yIn)
{
	rawX = xIn;
	rawY = yIn;

}
/**gets positions of pupil while in calibration and stores them in coords
@param xIn,yIn,id coordinates of the pupil calibrating for point numbered by id
*/
void Tracker::setCalibrationPoints(int xIn, int yIn, int id)
{
	//these will be determined during calibration process
	coords[id].x = xIn;
	coords[id].y = yIn;
}

/**
Get dimension of current camera frame
@param x,y width and height of the camera frame
*/
void Tracker::setDimensions(int x, int y)
{
	dimensionY = y;
	dimensionX = x;
}
/**
*This is actual mapping function which will calculate coordinates from pupil on to screen cursor
*using calibration data
*/
void Tracker::calculateNewCoords()
{

	//top left quadrant
	if ((rawX - (dimensionX / 2)) < 0 && (rawY - (dimensionY / 2))*-1 >= 0)
	{
		if (coords[0].x != 0 && coords[0].y != 0)
		{
			factorX = (GetSystemMetrics(SM_CXSCREEN) / coords[0].x);
			factorY = (GetSystemMetrics(SM_CYSCREEN) / coords[0].y);
		}
	}
	//else
	//bottom left quadrant
	if ((rawX - (dimensionX / 2)) < 0 && (rawY - (dimensionY / 2))*-1 < 0)
	{
		if (coords[6].x != 0 && coords[6].y != 0)
		{
			factorX = (GetSystemMetrics(SM_CXSCREEN) / coords[5].x);
			factorY = (GetSystemMetrics(SM_CYSCREEN) / coords[5].y);
		}
	}
	//top right quadrant
	//else 
	if ((rawX - (dimensionX / 2)) >= 0 && (rawY - (dimensionY / 2))*-1 >= 0)
	{
		if (coords[2].x != 0 && coords[2].y != 0)
		{
			factorX = (GetSystemMetrics(SM_CXSCREEN) / coords[1].x);
			factorY = (GetSystemMetrics(SM_CYSCREEN) / coords[1].y);
		}
	}
	//bottom right quadrant
	//else
	if ((rawX - (dimensionX / 2)) >= 0 && (rawY - (dimensionY / 2))*-1 < 0)
	{
		if (coords[9].x != 0 && coords[9].y != 0)
		{
			factorX = (GetSystemMetrics(SM_CXSCREEN) / coords[6].x);
			factorY = (GetSystemMetrics(SM_CYSCREEN) / coords[6].y);
		}
	}

	cursorX = (rawX - coords[0].x) * (factorX) * 4;
	cursorY = (rawY - coords[0].y)* (factorY) * 4;
}

/**
*This function moves the cursor to a newly calculated points
*/
void Tracker::moveCursor()
{
	calculateNewCoords();
	SetCursorPos(cursorX, cursorY);
}

/**Tracker object destructor
*/
Tracker::~Tracker()
{
}

#include "opencv2/opencv.hpp"

/**A Struct for position the pupil
@param x, y Coordinates of a point
*/
typedef  struct PupilPosition
{
	int x;
	int y;
};

class PupilDetect
{
public:
	PupilDetect();
	PupilPosition getPupilPosition();
	PupilPosition * getCoordinates();
	PupilPosition getFrameDimensions();
	cv::Mat getOriginalImage(cv::VideoCapture cap);
	cv::Mat getProcessedFrame();
	void initCalibration();
	void detectPupil(cv::VideoCapture capture);
	void setVideoStatus(bool play);
	void setCoordinates(int id);
	void findEye();
	void setThreshold(int thresholdIn);
	void setMaxArea(int maxAreaIn);
	void setMinArea(int minAreaIn);


	PupilPosition position;

	~PupilDetect();
private:
	void findContours(cv::Mat thresholdFrame);
	void applyThreshold(int threshHoldIntensity);
	void drawContours(std::vector<std::vector<cv::Point>> contours);

	/**Current frame that is being processed */
	cv::Mat currentFrame;
	/**Current frame after applying threshold*/
	cv::Mat thresholdFrame;
	/**1D vector which contains all the contours in a threshold frame*/
	std::vector<std::vector<cv::Point>> contours;
	/**1D vector of rectangles where eye can be potentially found */
	std::vector<cv::Rect> eye;

	/**This is used to play or pause the video from camera*/
	bool play;
	/**Variable intensity for a camera frame*/
	int thresholdIntensity;
	/**Variable maximum logical area for a contour to be a pupil*/
	int maxArea;
	/**Variable minimum logical area for a contour to be a pupil*/
	int minArea;
	/**Counts number of points that are aready calibrated*/
	int counter;
	/**Defines if the user is calibrating or not*/
	bool isCalibrating;
	/**Delay input from user to avoid quick presses of a button*/
	double toDelay;
};
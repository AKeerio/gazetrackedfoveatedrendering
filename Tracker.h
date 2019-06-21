class Tracker {
public:
	Tracker();
	void setPupilPosition(int xIn, int yIn);
	void setCalibrationPoints(int xIn, int yIn, int id);
	void calculateNewCoords();
	void moveCursor();
	void Tracker::setDimensions(int x, int y);
	~Tracker();
private:
	/**Current X coordinate of the cursor*/
	int cursorX;
	/**Current Y coordinate of the cursor*/
	int cursorY;
	/**Current X coordinate of the pupil*/
	int rawX;
	/**Current y coordinate of the pupil*/
	int rawY;
	/**Scale factor for X axis*/
	int factorX;
	/**Scale factor for y axis*/
	int factorY;
	/**Width of the camera frame*/
	int dimensionY;
	/**Height of the camera frame*/
	int dimensionX;
	//PupilPosition coords[9];
};
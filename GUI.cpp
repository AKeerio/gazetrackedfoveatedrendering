#include "GUI.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

[STAThreadAttribute]
int Main(array<System::String ^> ^args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	GazeTrackGUI::GUI mainForm;
	Application::Run(%mainForm);

	return 0;
}
/**
*Starts tracker object in a background worker thread so it can be run in a loop independant of the main program
*/
void GazeTrackGUI::GUI::doneTesting()
{
	this->isTesting = false;
}

void GazeTrackGUI::GUI::runCursor()
{
	points = pupil.getCoordinates();
	PupilPosition temp[9];
	for (int i = 0; i < 9; i++)
	{
		temp[i] = points[i];
	}
	for (int i = 0; i < 9; i++)
	{
		tracker.setCalibrationPoints(temp[i].x, temp[i].y, i);
	}
	PupilPosition dimension = pupil.getFrameDimensions();
	tracker.setDimensions(dimension.x, dimension.y);
	cursorWorker->RunWorkerAsync(1);
}

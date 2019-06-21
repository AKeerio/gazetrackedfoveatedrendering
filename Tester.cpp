#include "Tester.h"
#include <windows.h>
#include <math.h>  

/**Generates a random X coordinate where the circle would be placed*/
int GazeTrackGUI::Tester::generateRandomX()
{
	int num = rand() % GetSystemMetrics(SM_CXSCREEN);
	return num;
}

/**Generates a random Y coordinate where the circle would be placed*/
int GazeTrackGUI::Tester::generateRandomY()
{
	int num = rand() % GetSystemMetrics(SM_CYSCREEN);
	return num;
}

/**Updates the location of the circle*/
void GazeTrackGUI::Tester::moveImageBox()
{
	cursorPos.X = this->generateRandomX();
	cursorPos.Y = this->generateRandomY();
	imgBox->Location = cursorPos;
}

/**
*Calculates distance between the coordinates of the image/circle and coordinates of the cursor/mouse pointer
*Writes this distance to a file
*/
void GazeTrackGUI::Tester::calculateDistance()
{
	int distance=0;
	Point mousePos= System::Windows::Forms::Cursor::Position;
	Point imgPos = imgBox->Location;
	distance = sqrt(pow((imgPos.X-mousePos.X),2)+ pow((imgPos.Y - mousePos.Y), 2));

	//save to file
	String^ strToWrite = "Mouse "+mousePos.X+", \t" + mousePos.Y+".\t Target: "+ imgPos.X+",\t "+ imgPos.Y+".\t Distance :"+distance;
	String^ fileName = "data\\distances.txt";
	StreamWriter^ streamWriter = File::AppendText(fileName);

	if (streamWriter)
	{
		streamWriter->WriteLine(strToWrite);
	}

	streamWriter->Close();
}
	



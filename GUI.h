#include "PupilDetect.h"
#include "CalibrationForm.h"
#include "Feedback.h"
#include "Tester.h"
#include "Tracker.h"
#include "HelpForm.h"
#include <Windows.h>
#include <time.h>

namespace GazeTrackGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	PupilDetect pupil;
	Tracker tracker;
	PupilPosition * points;

	public ref class GUI : public System::Windows::Forms::Form
	{
	public:

		GUI(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			comboBox1->Items->Add("Camera 0");
			comboBox1->Items->Add("Camera 1");
			comboBox1->Items->Add("Camera 2");
			isTesting = false;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GUI()
		{
			if (components)
			{
				delete components;
			}
		}

	public:	void doneTesting();
	private: boolean isTesting;
	private: void runCursor();

	private: System::Windows::Forms::Button^  calibrateBtn;
	private: System::Windows::Forms::Button^  initialiseBtn;
	private: System::Windows::Forms::Button^  trackBtn;
	private: System::Windows::Forms::PictureBox^  videoBox;
	private: System::ComponentModel::BackgroundWorker^  videoWorker;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::LinkLabel^  linkLabel1;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::ComponentModel::BackgroundWorker^  cursorWorker;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  menuToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  feedbackToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::Button^  testerBtn;

	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TrackBar^  threshBar;
	private: System::Windows::Forms::TrackBar^  minAreaBar;
	private: System::Windows::Forms::TrackBar^  maxAreaBar;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  threshLbl;
	private: System::Windows::Forms::Label^  minAreaLbl;
	private: System::Windows::Forms::Label^  maxAreaLbl;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
	private: System::Windows::Forms::ToolStripMenuItem^  loadToolStripMenuItem;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->calibrateBtn = (gcnew System::Windows::Forms::Button());
			this->initialiseBtn = (gcnew System::Windows::Forms::Button());
			this->trackBtn = (gcnew System::Windows::Forms::Button());
			this->videoBox = (gcnew System::Windows::Forms::PictureBox());
			this->videoWorker = (gcnew System::ComponentModel::BackgroundWorker());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->cursorWorker = (gcnew System::ComponentModel::BackgroundWorker());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->menuToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->feedbackToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->testerBtn = (gcnew System::Windows::Forms::Button());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->threshBar = (gcnew System::Windows::Forms::TrackBar());
			this->minAreaBar = (gcnew System::Windows::Forms::TrackBar());
			this->maxAreaBar = (gcnew System::Windows::Forms::TrackBar());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->threshLbl = (gcnew System::Windows::Forms::Label());
			this->minAreaLbl = (gcnew System::Windows::Forms::Label());
			this->maxAreaLbl = (gcnew System::Windows::Forms::Label());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->videoBox))->BeginInit();
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->threshBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->minAreaBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->maxAreaBar))->BeginInit();
			this->SuspendLayout();
			// 
			// calibrateBtn
			// 
			this->calibrateBtn->Enabled = false;
			this->calibrateBtn->Location = System::Drawing::Point(197, 349);
			this->calibrateBtn->Name = L"calibrateBtn";
			this->calibrateBtn->Size = System::Drawing::Size(166, 34);
			this->calibrateBtn->TabIndex = 1;
			this->calibrateBtn->Text = L"Calibrate";
			this->calibrateBtn->UseVisualStyleBackColor = true;
			this->calibrateBtn->Click += gcnew System::EventHandler(this, &GUI::calibrateBtn_Click);
			// 
			// initialiseBtn
			// 
			this->initialiseBtn->Enabled = false;
			this->initialiseBtn->Location = System::Drawing::Point(20, 349);
			this->initialiseBtn->Name = L"initialiseBtn";
			this->initialiseBtn->Size = System::Drawing::Size(171, 34);
			this->initialiseBtn->TabIndex = 2;
			this->initialiseBtn->Text = L"Initialise";
			this->initialiseBtn->UseVisualStyleBackColor = true;
			this->initialiseBtn->Click += gcnew System::EventHandler(this, &GUI::viewBtn_Click);
			// 
			// trackBtn
			// 
			this->trackBtn->Enabled = false;
			this->trackBtn->Location = System::Drawing::Point(197, 389);
			this->trackBtn->Name = L"trackBtn";
			this->trackBtn->Size = System::Drawing::Size(165, 36);
			this->trackBtn->TabIndex = 4;
			this->trackBtn->Text = L"Start Tracking";
			this->trackBtn->UseVisualStyleBackColor = true;
			this->trackBtn->Click += gcnew System::EventHandler(this, &GUI::trackBtn_Click);
			// 
			// videoBox
			// 
			this->videoBox->Location = System::Drawing::Point(14, 66);
			this->videoBox->Name = L"videoBox";
			this->videoBox->Size = System::Drawing::Size(366, 264);
			this->videoBox->TabIndex = 5;
			this->videoBox->TabStop = false;
			// 
			// videoWorker
			// 
			this->videoWorker->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &GUI::videoWorker_DoWork);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(16, 440);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(153, 13);
			this->label1->TabIndex = 7;
			this->label1->Text = L"1. Start by selecting a camera. ";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(17, 456);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(81, 13);
			this->label2->TabIndex = 8;
			this->label2->Text = L"2. Click initialise";
			// 
			// linkLabel1
			// 
			this->linkLabel1->AutoSize = true;
			this->linkLabel1->Location = System::Drawing::Point(20, 513);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->Size = System::Drawing::Size(0, 13);
			this->linkLabel1->TabIndex = 11;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(17, 500);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(214, 13);
			this->label5->TabIndex = 12;
			this->label5->Text = L"5. Press \'ESC\' to stop moving mouse cursor.";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(17, 513);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(147, 13);
			this->label6->TabIndex = 13;
			this->label6->Text = L"6. Press \'X\' to exit application.";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(11, 23);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(84, 13);
			this->label7->TabIndex = 14;
			this->label7->Text = L"Select a camera";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(14, 39);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 15;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &GUI::comboBox1_SelectedIndexChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(17, 486);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(188, 13);
			this->label4->TabIndex = 10;
			this->label4->Text = L"4. Click Start Tracking to move cursor.";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(17, 473);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(227, 13);
			this->label3->TabIndex = 16;
			this->label3->Text = L"3. Before starting tracking we need to calibrate";
			this->label3->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// cursorWorker
			// 
			this->cursorWorker->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &GUI::cursorWorker_DoWork_1);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->menuToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(648, 24);
			this->menuStrip1->TabIndex = 17;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// menuToolStripMenuItem
			// 
			this->menuToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->helpToolStripMenuItem,
					this->loadToolStripMenuItem, this->feedbackToolStripMenuItem, this->exitToolStripMenuItem
			});
			this->menuToolStripMenuItem->Name = L"menuToolStripMenuItem";
			this->menuToolStripMenuItem->Size = System::Drawing::Size(50, 20);
			this->menuToolStripMenuItem->Text = L"Menu";
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(124, 22);
			this->helpToolStripMenuItem->Text = L"Help";
			this->helpToolStripMenuItem->Click += gcnew System::EventHandler(this, &GUI::helpToolStripMenuItem_Click);
			// 
			// loadToolStripMenuItem
			// 
			this->loadToolStripMenuItem->Name = L"loadToolStripMenuItem";
			this->loadToolStripMenuItem->Size = System::Drawing::Size(124, 22);
			this->loadToolStripMenuItem->Text = L"Load";
			// 
			// feedbackToolStripMenuItem
			// 
			this->feedbackToolStripMenuItem->Name = L"feedbackToolStripMenuItem";
			this->feedbackToolStripMenuItem->Size = System::Drawing::Size(124, 22);
			this->feedbackToolStripMenuItem->Text = L"Feedback";
			this->feedbackToolStripMenuItem->Click += gcnew System::EventHandler(this, &GUI::feedbackToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(124, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &GUI::exitToolStripMenuItem_Click);
			// 
			// testerBtn
			// 
			this->testerBtn->Enabled = false;
			this->testerBtn->Location = System::Drawing::Point(20, 389);
			this->testerBtn->Name = L"testerBtn";
			this->testerBtn->Size = System::Drawing::Size(168, 36);
			this->testerBtn->TabIndex = 18;
			this->testerBtn->Text = L"Test";
			this->testerBtn->UseVisualStyleBackColor = true;
			this->testerBtn->Click += gcnew System::EventHandler(this, &GUI::testerBtn_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(254, 451);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(147, 20);
			this->label8->TabIndex = 19;
			this->label8->Text = L"Please do not close";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(250, 479);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(136, 20);
			this->label9->TabIndex = 20;
			this->label9->Text = L" the Panel window";
			// 
			// threshBar
			// 
			this->threshBar->Location = System::Drawing::Point(428, 66);
			this->threshBar->Maximum = 100;
			this->threshBar->Name = L"threshBar";
			this->threshBar->Orientation = System::Windows::Forms::Orientation::Vertical;
			this->threshBar->Size = System::Drawing::Size(45, 433);
			this->threshBar->TabIndex = 21;
			this->threshBar->Value = 50;
			this->threshBar->Scroll += gcnew System::EventHandler(this, &GUI::threshBar_Scroll);
			// 
			// minAreaBar
			// 
			this->minAreaBar->Location = System::Drawing::Point(499, 66);
			this->minAreaBar->Maximum = 5000;
			this->minAreaBar->Name = L"minAreaBar";
			this->minAreaBar->Orientation = System::Windows::Forms::Orientation::Vertical;
			this->minAreaBar->Size = System::Drawing::Size(45, 433);
			this->minAreaBar->TabIndex = 22;
			this->minAreaBar->Value = 100;
			this->minAreaBar->Scroll += gcnew System::EventHandler(this, &GUI::minAreaBar_Scroll);
			// 
			// maxAreaBar
			// 
			this->maxAreaBar->Location = System::Drawing::Point(584, 66);
			this->maxAreaBar->Maximum = 5000;
			this->maxAreaBar->Name = L"maxAreaBar";
			this->maxAreaBar->Orientation = System::Windows::Forms::Orientation::Vertical;
			this->maxAreaBar->Size = System::Drawing::Size(45, 433);
			this->maxAreaBar->TabIndex = 23;
			this->maxAreaBar->Value = 2000;
			this->maxAreaBar->Scroll += gcnew System::EventHandler(this, &GUI::maxAreaBar_Scroll);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(412, 47);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(54, 13);
			this->label10->TabIndex = 24;
			this->label10->Text = L"Threshold";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(495, 47);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(49, 13);
			this->label11->TabIndex = 25;
			this->label11->Text = L"Min Area";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(577, 47);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(52, 13);
			this->label12->TabIndex = 26;
			this->label12->Text = L"Max Area";
			// 
			// threshLbl
			// 
			this->threshLbl->AutoSize = true;
			this->threshLbl->Location = System::Drawing::Point(412, 60);
			this->threshLbl->Name = L"threshLbl";
			this->threshLbl->Size = System::Drawing::Size(0, 13);
			this->threshLbl->TabIndex = 27;
			// 
			// minAreaLbl
			// 
			this->minAreaLbl->AutoSize = true;
			this->minAreaLbl->Location = System::Drawing::Point(496, 60);
			this->minAreaLbl->Name = L"minAreaLbl";
			this->minAreaLbl->Size = System::Drawing::Size(0, 13);
			this->minAreaLbl->TabIndex = 28;
			// 
			// maxAreaLbl
			// 
			this->maxAreaLbl->AutoSize = true;
			this->maxAreaLbl->Location = System::Drawing::Point(578, 60);
			this->maxAreaLbl->Name = L"maxAreaLbl";
			this->maxAreaLbl->Size = System::Drawing::Size(0, 13);
			this->maxAreaLbl->TabIndex = 29;
			// 
			// GUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(648, 532);
			this->Controls->Add(this->maxAreaLbl);
			this->Controls->Add(this->minAreaLbl);
			this->Controls->Add(this->threshLbl);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->maxAreaBar);
			this->Controls->Add(this->minAreaBar);
			this->Controls->Add(this->threshBar);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->testerBtn);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->linkLabel1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->videoBox);
			this->Controls->Add(this->trackBtn);
			this->Controls->Add(this->initialiseBtn);
			this->Controls->Add(this->calibrateBtn);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"GUI";
			this->Text = L"GazeTrack";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &GUI::GUI_FormClosing);
			this->Load += gcnew System::EventHandler(this, &GUI::GUI_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->videoBox))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->threshBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->minAreaBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->maxAreaBar))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion		
	private: System::Void GUI_Load(System::Object^  sender, System::EventArgs^  e) {

	}
	private: System::Void calibrateBtn_Click(System::Object^  sender, System::EventArgs^  e) {

		CalibrationForm ^ form;
		form = gcnew CalibrationForm();
		form->Show();
		pupil.initCalibration();
		//send all calibration point to calibrationi form so it can write to file
		form->setCoordinates(/*array of coordinates*/);
		trackBtn->Enabled = true;
		testerBtn->Enabled = true;
	}

	private: System::Void viewBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		initialiseBtn->Enabled = false;
		calibrateBtn->Enabled = true;
		pupil.setThreshold(threshBar->Value);
		pupil.setMinArea(minAreaBar->Value);
		pupil.setMaxArea(maxAreaBar->Value);
		threshLbl->Text = System::Convert::ToString(threshBar->Value);
		minAreaLbl->Text = System::Convert::ToString(minAreaBar->Value);
		maxAreaLbl->Text = System::Convert::ToString(maxAreaBar->Value);
		videoWorker->RunWorkerAsync(1);
		calibrateBtn->Enabled = true;
	}

	private: System::Void videoWorker_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {

		while (!videoWorker->CancellationPending)
		{
			try
			{
				cv::Mat img = pupil.getProcessedFrame();
				System::Drawing::Graphics^ graphics = videoBox->CreateGraphics();
				System::Drawing::Bitmap^ bitmap = gcnew System::Drawing::Bitmap(img.cols, img.rows, img.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, (IntPtr)img.ptr());
				System::Drawing::RectangleF rect(0, 0, videoBox->Width, videoBox->Height);
				if (graphics)
					graphics->DrawImage(bitmap, rect);
			}
			catch (...)
			{
				String^ msg = "No input recieved from camera.";
				String^ caption = "Error";
				MessageBox::Show(this, msg, caption);
			}
		}
	}

	private: System::Void trackBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		this->runCursor();
	}

	private: System::Void GUI_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		Application::Exit();
		pupil.setVideoStatus(false);
	}

			 /*
			 *Attempts to open the selected camera  and start main detecting function
			 */
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		int cameraId;
		switch (comboBox1->SelectedIndex)
		{
		case 0:
		{
			initialiseBtn->Enabled = true;
			cameraId = 0;
		}break;
		case 1:
		{
			initialiseBtn->Enabled = true;
			cameraId = 1;
		}break;
		case 2:
		{
			initialiseBtn->Enabled = true;
			cameraId = 2;
		}break;
		}

		try {
			cv::VideoCapture capture(cameraId);

			pupil.detectPupil(capture);
		}
		catch (...) {
			String^ msg = "Error reading from camera. Please select a different camera.";
			String^ caption = "Error";
			MessageBox::Show(this, msg, caption);
		}
	}
	private: System::Void cursorWorker_DoWork_1(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
		String^ fileName = "data\\timing.txt";
		StreamWriter^ streamWriter = gcnew StreamWriter(fileName);
		double avgTime = 0;
		int avgCounter = 0;
		while (!cursorWorker->CancellationPending && !GetAsyncKeyState(VK_ESCAPE))
		{
			clock_t begin = clock();
			tracker.setPupilPosition(pupil.getPupilPosition().x, pupil.getPupilPosition().y);
			tracker.moveCursor();
			clock_t end = clock();

			if (isTesting)
			{
				double elapsed = (double)(end - begin) * 1000.0 / CLOCKS_PER_SEC;
				avgCounter++;
				if (avgCounter < 100000)
				{
					avgTime += elapsed;
				}
				else
				{
					elapsed = (avgTime / 100000);

					String^ text = elapsed.ToString();
					if (streamWriter)
					{
						streamWriter->Write(text);
						streamWriter->WriteLine("ms");
					}
					avgCounter = 0;
				}
			}
		}

		streamWriter->Close();

	}
	private: System::Void helpToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		HelpForm^ helpform = gcnew HelpForm();
		helpform->ShowDialog();

	}
	private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		pupil.setVideoStatus(false);
		Application::Exit();
	}
	private: System::Void testerBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		MessageBox::Show(this, "On the next screen you will see a red circle changing location every 2 seconds. Follow the red circle using your gaze. \nRead more in help section.", "Running tests");
		Tester ^ testForm = gcnew Tester();
		this->runCursor();
		this->isTesting = true;
		testForm->Show();
	}
	private: System::Void threshBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
		if (threshBar->Value > 0)
		{
			pupil.setThreshold(threshBar->Value);
			threshLbl->Text = System::Convert::ToString(threshBar->Value);
		}
	}
	private: System::Void minAreaBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
		if (minAreaBar->Value) {
			pupil.setMinArea(minAreaBar->Value);
			minAreaLbl->Text = System::Convert::ToString(minAreaBar->Value);
		}
	}
	private: System::Void maxAreaBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
		if (maxAreaBar->Value > 0)
		{
			pupil.setMaxArea(maxAreaBar->Value);
			maxAreaLbl->Text = System::Convert::ToString(maxAreaBar->Value);
		}
	}

	private: System::Void feedbackToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		Feedback^ fb = gcnew Feedback();
		fb->ShowDialog();
	}
};
}

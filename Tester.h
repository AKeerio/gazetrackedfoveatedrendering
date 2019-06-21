#include <windows.h>
#pragma once;
namespace GazeTrackGUI {

	using namespace System;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// Summary for Tester
	/// </summary>

	public ref class Tester : public System::Windows::Forms::Form
	{
		int counter1 = 5;
	public:
		Tester()
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Tester()
		{
			if (components)
			{
				delete components;
			}
		}
	private: int generateRandomX();
	private: int generateRandomY();
	private: void moveImageBox();
	private: void calculateDistance();

	private: System::Windows::Forms::Button^  exitButton;
	private: System::Windows::Forms::PictureBox^  imgBox;

	private: System::Windows::Forms::Timer^  generatorTimer;
	private: System::Windows::Forms::Timer^  countdownTimer;
	private: System::Windows::Forms::Label^  countLbl;
	private: System::ComponentModel::IContainer^  components;

	protected:
	protected:
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Tester::typeid));
			this->imgBox = (gcnew System::Windows::Forms::PictureBox());
			this->exitButton = (gcnew System::Windows::Forms::Button());
			this->generatorTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->countdownTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->countLbl = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgBox))->BeginInit();
			this->SuspendLayout();
			// 
			// imgBox
			// 
			this->imgBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"imgBox.Image")));
			this->imgBox->Location = System::Drawing::Point(240, 105);
			this->imgBox->Name = L"imgBox";
			this->imgBox->Size = System::Drawing::Size(39, 36);
			this->imgBox->TabIndex = 0;
			this->imgBox->TabStop = false;
			// 
			// exitButton
			// 
			this->exitButton->Location = System::Drawing::Point(1817, 12);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(75, 23);
			this->exitButton->TabIndex = 5;
			this->exitButton->Text = L"Exit";
			this->exitButton->UseVisualStyleBackColor = true;
			this->exitButton->Click += gcnew System::EventHandler(this, &Tester::exitButton_Click);
			// 
			// generatorTimer
			// 
			this->generatorTimer->Interval = 2000;
			this->generatorTimer->Tick += gcnew System::EventHandler(this, &Tester::generatorTimer_Tick);
			// 
			// countdownTimer
			// 
			this->countdownTimer->Enabled = true;
			this->countdownTimer->Interval = 1000;
			this->countdownTimer->Tick += gcnew System::EventHandler(this, &Tester::countdownTimer_Tick);
			// 
			// countLbl
			// 
			this->countLbl->AutoSize = true;
			this->countLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->countLbl->Location = System::Drawing::Point(957, 450);
			this->countLbl->Name = L"countLbl";
			this->countLbl->Size = System::Drawing::Size(51, 55);
			this->countLbl->TabIndex = 6;
			this->countLbl->Text = L"5";
			// 
			// Tester
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1904, 1041);
			this->Controls->Add(this->countLbl);
			this->Controls->Add(this->exitButton);
			this->Controls->Add(this->imgBox);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Tester";
			this->Text = L"Tester";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Tester::Tester_FormClosed);
			this->Load += gcnew System::EventHandler(this, &Tester::Tester_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: Point cursorPos;
	private: System::Void Tester_Load(System::Object^  sender, System::EventArgs^  e) {
	}

	private: System::Void exitButton_Click(System::Object^  sender, System::EventArgs^  e) {
		
		generatorTimer->Stop();
		countdownTimer->Stop();

		String^ fileName = "data\\distances.txt";
		StreamWriter^ streamWriter = File::AppendText(fileName);

		if (streamWriter)
		{
			streamWriter->WriteLine("--------------------------------------------------------------------------------------");
		}

		streamWriter->Close();
		this->Close();
	}

	private: System::Void generatorTimer_Tick(System::Object^  sender, System::EventArgs^  e) {
		if (counter1 < 10)
		{
			this->calculateDistance();
			this->moveImageBox();
			counter1++;
		}
		else
		{
			generatorTimer->Stop();
			MessageBox::Show(this, "Test is now complete.Press \nESCAPE to release the cursor", "Test completed");
		}
	}
private: System::Void countdownTimer_Tick(System::Object^  sender, System::EventArgs^  e) {
		countLbl->Text = counter1.ToString();
		counter1--;
		if (counter1 < 0)
		{
			countLbl->Visible = false;
			countdownTimer->Stop();
			counter1 = 0;
			generatorTimer->Start();
		}
}
private: System::Void Tester_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
	//Set isTesting to false in GUI.h

}
};
}

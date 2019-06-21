#pragma once

namespace GazeTrackGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for Feedback
	/// </summary>
	public ref class Feedback : public System::Windows::Forms::Form
	{
	public:
		Feedback(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Feedback()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  exitBtn;
	private: System::Windows::Forms::Button^  submitBtn;
	private: System::Windows::Forms::Label^  q1Lbl;

	private: System::Windows::Forms::ComboBox^  q1List;
	private: System::Windows::Forms::ComboBox^  q2List;
	private: System::Windows::Forms::Label^  q2Lbl;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::ComboBox^  q3List;
	private: System::Windows::Forms::Label^  q3Lbl;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ComboBox^  q4List;
	private: System::Windows::Forms::Label^  q4Lbl;
	private: System::Windows::Forms::ComboBox^  q5List;
	private: System::Windows::Forms::Label^  q5Lbl;
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->exitBtn = (gcnew System::Windows::Forms::Button());
			this->submitBtn = (gcnew System::Windows::Forms::Button());
			this->q1Lbl = (gcnew System::Windows::Forms::Label());
			this->q1List = (gcnew System::Windows::Forms::ComboBox());
			this->q2List = (gcnew System::Windows::Forms::ComboBox());
			this->q2Lbl = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->q3List = (gcnew System::Windows::Forms::ComboBox());
			this->q3Lbl = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->q4List = (gcnew System::Windows::Forms::ComboBox());
			this->q4Lbl = (gcnew System::Windows::Forms::Label());
			this->q5List = (gcnew System::Windows::Forms::ComboBox());
			this->q5Lbl = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(27, 37);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(342, 25);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Please answer following questions";
			// 
			// exitBtn
			// 
			this->exitBtn->Location = System::Drawing::Point(294, 11);
			this->exitBtn->Name = L"exitBtn";
			this->exitBtn->Size = System::Drawing::Size(75, 23);
			this->exitBtn->TabIndex = 1;
			this->exitBtn->Text = L"Exit";
			this->exitBtn->UseVisualStyleBackColor = true;
			this->exitBtn->Click += gcnew System::EventHandler(this, &Feedback::exitBtn_Click);
			// 
			// submitBtn
			// 
			this->submitBtn->Location = System::Drawing::Point(144, 422);
			this->submitBtn->Name = L"submitBtn";
			this->submitBtn->Size = System::Drawing::Size(75, 23);
			this->submitBtn->TabIndex = 2;
			this->submitBtn->Text = L"Submit";
			this->submitBtn->UseVisualStyleBackColor = true;
			this->submitBtn->Click += gcnew System::EventHandler(this, &Feedback::submitBtn_Click);
			// 
			// q1Lbl
			// 
			this->q1Lbl->AutoSize = true;
			this->q1Lbl->Location = System::Drawing::Point(29, 132);
			this->q1Lbl->Name = L"q1Lbl";
			this->q1Lbl->Size = System::Drawing::Size(174, 13);
			this->q1Lbl->TabIndex = 3;
			this->q1Lbl->Text = L"1. The application was easy to use.";
			// 
			// q1List
			// 
			this->q1List->FormattingEnabled = true;
			this->q1List->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"1", L"2", L"3", L"4", L"5" });
			this->q1List->Location = System::Drawing::Point(46, 148);
			this->q1List->Name = L"q1List";
			this->q1List->Size = System::Drawing::Size(121, 21);
			this->q1List->TabIndex = 4;
			this->q1List->SelectedIndexChanged += gcnew System::EventHandler(this, &Feedback::q1List_SelectedIndexChanged);
			// 
			// q2List
			// 
			this->q2List->FormattingEnabled = true;
			this->q2List->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"1", L"2", L"3", L"4", L"5" });
			this->q2List->Location = System::Drawing::Point(46, 204);
			this->q2List->Name = L"q2List";
			this->q2List->Size = System::Drawing::Size(121, 21);
			this->q2List->TabIndex = 6;
			// 
			// q2Lbl
			// 
			this->q2Lbl->AutoSize = true;
			this->q2Lbl->Location = System::Drawing::Point(29, 188);
			this->q2Lbl->Name = L"q2Lbl";
			this->q2Lbl->Size = System::Drawing::Size(190, 13);
			this->q2Lbl->TabIndex = 5;
			this->q2Lbl->Text = L"2. The instructions were easy to follow.";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(27, 62);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(175, 25);
			this->label4->TabIndex = 7;
			this->label4->Text = L"and click Submit.";
			// 
			// q3List
			// 
			this->q3List->FormattingEnabled = true;
			this->q3List->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"1", L"2", L"3", L"4", L"5" });
			this->q3List->Location = System::Drawing::Point(46, 258);
			this->q3List->Name = L"q3List";
			this->q3List->Size = System::Drawing::Size(121, 21);
			this->q3List->TabIndex = 9;
			// 
			// q3Lbl
			// 
			this->q3Lbl->AutoSize = true;
			this->q3Lbl->Location = System::Drawing::Point(29, 242);
			this->q3Lbl->Name = L"q3Lbl";
			this->q3Lbl->Size = System::Drawing::Size(271, 13);
			this->q3Lbl->TabIndex = 8;
			this->q3Lbl->Text = L"3. System was able to detect the pupil most of the times.";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(29, 105);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(358, 13);
			this->label2->TabIndex = 10;
			this->label2->Text = L"For each question select a number (1 to 5) where 5 means definitley agree.";
			// 
			// q4List
			// 
			this->q4List->FormattingEnabled = true;
			this->q4List->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"1", L"2", L"3", L"4", L"5" });
			this->q4List->Location = System::Drawing::Point(46, 308);
			this->q4List->Name = L"q4List";
			this->q4List->Size = System::Drawing::Size(121, 21);
			this->q4List->TabIndex = 12;
			// 
			// q4Lbl
			// 
			this->q4Lbl->AutoSize = true;
			this->q4Lbl->Location = System::Drawing::Point(29, 292);
			this->q4Lbl->Name = L"q4Lbl";
			this->q4Lbl->Size = System::Drawing::Size(269, 13);
			this->q4Lbl->TabIndex = 11;
			this->q4Lbl->Text = L"4. System moved cursor to gaze point most of the times.";
			// 
			// q5List
			// 
			this->q5List->FormattingEnabled = true;
			this->q5List->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"1", L"2", L"3", L"4", L"5" });
			this->q5List->Location = System::Drawing::Point(46, 362);
			this->q5List->Name = L"q5List";
			this->q5List->Size = System::Drawing::Size(121, 21);
			this->q5List->TabIndex = 14;
			// 
			// q5Lbl
			// 
			this->q5Lbl->AutoSize = true;
			this->q5Lbl->Location = System::Drawing::Point(29, 346);
			this->q5Lbl->Name = L"q5Lbl";
			this->q5Lbl->Size = System::Drawing::Size(282, 13);
			this->q5Lbl->TabIndex = 13;
			this->q5Lbl->Text = L"5. System provided enough information for error messages.";
			// 
			// Feedback
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(393, 459);
			this->Controls->Add(this->q5List);
			this->Controls->Add(this->q5Lbl);
			this->Controls->Add(this->q4List);
			this->Controls->Add(this->q4Lbl);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->q3List);
			this->Controls->Add(this->q3Lbl);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->q2List);
			this->Controls->Add(this->q2Lbl);
			this->Controls->Add(this->q1List);
			this->Controls->Add(this->q1Lbl);
			this->Controls->Add(this->submitBtn);
			this->Controls->Add(this->exitBtn);
			this->Controls->Add(this->label1);
			this->Name = L"Feedback";
			this->Text = L"Feedback";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void exitBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}
private: System::Void submitBtn_Click(System::Object^  sender, System::EventArgs^  e) {

	String^ fileName = "data\\feedback.txt";
	StreamWriter^ streamWriter = File::AppendText(fileName);
	if (streamWriter)
	{
		streamWriter->WriteLine(q1Lbl->Text + "\t"+ q1List->Text);
		streamWriter->WriteLine(q2Lbl->Text + "\t"+ q2List->Text);
		streamWriter->WriteLine(q3Lbl->Text + "\t" + q3List->Text);
		streamWriter->WriteLine(q4Lbl->Text + "\t" + q4List->Text);
		streamWriter->WriteLine(q5Lbl->Text + "\t" + q5List->Text);
	
		streamWriter->WriteLine("--------------------------------------------------------------------------------");
	}

	streamWriter->Close();
	submitBtn->Enabled = false;
	MessageBox::Show(this, "Thank you for your feedback", "Feedback Submitted.");
	this->Close();
}

private: System::Void q1List_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
}
};
}

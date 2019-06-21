#pragma once

namespace GazeTrackGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for HelpForm
	/// </summary>
	public ref class HelpForm : public System::Windows::Forms::Form
	{
	public:
		HelpForm(void)
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
		~HelpForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label8;
	protected:
	private: System::Windows::Forms::Button^  exitBtn;
	private: System::Windows::Forms::RichTextBox^  richTextBox6;
	private: System::Windows::Forms::RichTextBox^  richTextBox5;
	private: System::Windows::Forms::RichTextBox^  richTextBox4;
	private: System::Windows::Forms::RichTextBox^  richTextBox3;
	private: System::Windows::Forms::RichTextBox^  richTextBox2;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(HelpForm::typeid));
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->exitBtn = (gcnew System::Windows::Forms::Button());
			this->richTextBox6 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox5 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox4 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox3 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(18, 310);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(172, 13);
			this->label8->TabIndex = 30;
			this->label8->Text = L"How to stop the eye tracker\?";
			// 
			// exitBtn
			// 
			this->exitBtn->Location = System::Drawing::Point(551, 23);
			this->exitBtn->Name = L"exitBtn";
			this->exitBtn->Size = System::Drawing::Size(75, 23);
			this->exitBtn->TabIndex = 29;
			this->exitBtn->Text = L"Exit";
			this->exitBtn->UseVisualStyleBackColor = true;
			this->exitBtn->Click += gcnew System::EventHandler(this, &HelpForm::exitBtn_Click);
			// 
			// richTextBox6
			// 
			this->richTextBox6->Location = System::Drawing::Point(22, 494);
			this->richTextBox6->Name = L"richTextBox6";
			this->richTextBox6->ReadOnly = true;
			this->richTextBox6->Size = System::Drawing::Size(605, 39);
			this->richTextBox6->TabIndex = 28;
			this->richTextBox6->Text = resources->GetString(L"richTextBox6.Text");
			// 
			// richTextBox5
			// 
			this->richTextBox5->Location = System::Drawing::Point(21, 255);
			this->richTextBox5->Name = L"richTextBox5";
			this->richTextBox5->ReadOnly = true;
			this->richTextBox5->Size = System::Drawing::Size(605, 34);
			this->richTextBox5->TabIndex = 27;
			this->richTextBox5->Text = L"After you have completed the caliration the Track button will be enabled. To star"
				L"t moving cursor with your gaze press the Track button.";
			// 
			// richTextBox4
			// 
			this->richTextBox4->Location = System::Drawing::Point(21, 326);
			this->richTextBox4->Name = L"richTextBox4";
			this->richTextBox4->ReadOnly = true;
			this->richTextBox4->Size = System::Drawing::Size(605, 39);
			this->richTextBox4->TabIndex = 26;
			this->richTextBox4->Text = L"The eye tracker will start moving the cursor if you have pressed Track button or "
				L"Test button. To stop moving cursor with via this program press Escape.";
			// 
			// richTextBox3
			// 
			this->richTextBox3->Location = System::Drawing::Point(23, 398);
			this->richTextBox3->Name = L"richTextBox3";
			this->richTextBox3->ReadOnly = true;
			this->richTextBox3->Size = System::Drawing::Size(605, 66);
			this->richTextBox3->TabIndex = 25;
			this->richTextBox3->Text = resources->GetString(L"richTextBox3.Text");
			// 
			// richTextBox2
			// 
			this->richTextBox2->Location = System::Drawing::Point(22, 165);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->ReadOnly = true;
			this->richTextBox2->Size = System::Drawing::Size(605, 66);
			this->richTextBox2->TabIndex = 24;
			this->richTextBox2->Text = resources->GetString(L"richTextBox2.Text");
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(22, 68);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(605, 66);
			this->richTextBox1->TabIndex = 23;
			this->richTextBox1->Text = resources->GetString(L"richTextBox1.Text");
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(22, 68);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(0, 13);
			this->label7->TabIndex = 22;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(19, 478);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(187, 13);
			this->label6->TabIndex = 21;
			this->label6->Text = L"How to see results of the tests\?";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(20, 382);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(262, 13);
			this->label5->TabIndex = 20;
			this->label5->Text = L"How to test the accuracy of the eye tracker\?";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(19, 239);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(173, 13);
			this->label3->TabIndex = 19;
			this->label3->Text = L"How to start the eye tracker\?";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(19, 149);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(197, 13);
			this->label2->TabIndex = 18;
			this->label2->Text = L"How to calibrate the eye tracker\?";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(19, 51);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(214, 13);
			this->label1->TabIndex = 17;
			this->label1->Text = L"How to open or change the camera\?";
			// 
			// HelpForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(646, 570);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->exitBtn);
			this->Controls->Add(this->richTextBox6);
			this->Controls->Add(this->richTextBox5);
			this->Controls->Add(this->richTextBox4);
			this->Controls->Add(this->richTextBox3);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"HelpForm";
			this->Text = L"HelpForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void exitBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}
};
}

#include "Player.h"
#include <fstream>
#define	WATER_STREAM_0		"Ruisseau_Escattes_01.wav"
#pragma once

namespace WinformCplusplus {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	/// <summary>
	/// Description résumée de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:

		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
			init();
		}


	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::TrackBar^ trackBar1;
	private: System::Windows::Forms::ListBox^ SoundList;
	private: System::Windows::Forms::Button^ button5;

	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->SoundList = (gcnew System::Windows::Forms::ListBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			this->SuspendLayout();
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(25, 26);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(331, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Proof Of Concept to play sound with OpenAl and Windows Form C++";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(28, 74);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Play";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button_Play);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(141, 74);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Stop";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button_Stop);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(247, 74);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Pause";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button_Pause);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(352, 74);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 4;
			this->button4->Text = L"Resume";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button_Resume);
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(448, 12);
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Orientation = System::Windows::Forms::Orientation::Vertical;
			this->trackBar1->Size = System::Drawing::Size(45, 104);
			this->trackBar1->TabIndex = 5;
			this->trackBar1->TickStyle = System::Windows::Forms::TickStyle::Both;
			this->trackBar1->Value = 10;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &MyForm::OnChangeVolume);
			// 
			// SoundList
			// 
			this->SoundList->AllowDrop = true;
			this->SoundList->FormattingEnabled = true;
			this->SoundList->Location = System::Drawing::Point(12, 155);
			this->SoundList->Name = L"SoundList";
			this->SoundList->Size = System::Drawing::Size(481, 147);
			this->SoundList->TabIndex = 6;
			this->SoundList->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &MyForm::SoundList_DragDrop_1);
			this->SoundList->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &MyForm::SoundList_DragEnter);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(202, 308);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 7;
			this->button5->Text = L"Save";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::SoundList_Save);
			// 
			// MyForm
			// 
			this->AllowDrop = true;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(505, 398);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->SoundList);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"Open AL";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		List<String^>^ listedSound = gcnew List<String^>;

	private: System::Void button_Play(System::Object^ sender, System::EventArgs^ e) {

		Play(WATER_STREAM_0);
	}
	private: System::Void button_Stop(System::Object^ sender, System::EventArgs^ e) {
		Stop(WATER_STREAM_0);
	}
	private: System::Void button_Pause(System::Object^ sender, System::EventArgs^ e) {
		Pause(WATER_STREAM_0);
	}
	private: System::Void button_Resume(System::Object^ sender, System::EventArgs^ e) {
		Resume(WATER_STREAM_0);
	}
	private: System::Void OnChangeVolume(System::Object^ sender, System::EventArgs^ e) {
		ChangeVolume(trackBar1->Value);
	}

	private: System::Void SoundList_DragDrop_1(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e) {
		array<String^>^ files = safe_cast<array<String^>^>(e->Data->GetData(DataFormats::FileDrop));

		SoundList->DataSource = nullptr;

		for each (String ^ sound in files)
		{
			listedSound->Add(sound);
		}

		SoundList->DataSource = listedSound;
	}

	private: System::Void SoundList_DragEnter(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e) {
		if (e->Data->GetDataPresent(DataFormats::FileDrop))
			e->Effect = DragDropEffects::Copy;
	}
	private: System::Void SoundList_Save(System::Object^ sender, System::EventArgs^ e) {

		// Create a new file named "playlist.txt"
		std::ofstream outputFile("playlist.txt");

		if (outputFile.is_open()) {  // Check if the file was successfully opened
			// Write some text into the file
			outputFile << "PLAYLIST";
			for each (String^ sound in listedSound)
			{
				outputFile << &sound;
			}

			// Close the file
			outputFile.close();  // Close the file after writing
		}
	}
	};

}

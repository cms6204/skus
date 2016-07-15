#pragma once

#include <string>
#include <regex>
#include <msclr\marshal_cppstd.h>
#include <iostream>
#include <fstream>
#include <conio.h>
#include <vector>

extern std::vector<std::string> catalogFiles;

namespace Skus {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for CatalogForm
	/// </summary>
	public ref class CatalogForm : public System::Windows::Forms::Form
	{
	public:
		CatalogForm(void)
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
		~CatalogForm()
		{
			if (components)
			{
				delete components;
			}
		}

    protected:
    private: System::Windows::Forms::Label^  label1;
    private: System::Windows::Forms::Button^  SaveButton;
    private: System::Windows::Forms::RichTextBox^  CatalogFilesBox;

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
            this->SaveButton = (gcnew System::Windows::Forms::Button());
            this->CatalogFilesBox = (gcnew System::Windows::Forms::RichTextBox());
            this->SuspendLayout();
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(65, 56);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(67, 13);
            this->label1->TabIndex = 1;
            this->label1->Text = L"Catalog Files";
            // 
            // SaveButton
            // 
            this->SaveButton->Location = System::Drawing::Point(240, 381);
            this->SaveButton->Name = L"SaveButton";
            this->SaveButton->Size = System::Drawing::Size(75, 23);
            this->SaveButton->TabIndex = 2;
            this->SaveButton->Text = L"Save";
            this->SaveButton->UseVisualStyleBackColor = true;
            this->SaveButton->Click += gcnew System::EventHandler(this, &CatalogForm::SaveButton_Click);
            // 
            // CatalogFilesBox
            // 
            this->CatalogFilesBox->Location = System::Drawing::Point(68, 81);
            this->CatalogFilesBox->Name = L"CatalogFilesBox";
            this->CatalogFilesBox->Size = System::Drawing::Size(416, 278);
            this->CatalogFilesBox->TabIndex = 3;
            this->CatalogFilesBox->Text = L"";
            // 
            // CatalogForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(555, 438);
            this->Controls->Add(this->CatalogFilesBox);
            this->Controls->Add(this->SaveButton);
            this->Controls->Add(this->label1);
            this->Name = L"CatalogForm";
            this->Text = L"Catalog Files";
            this->Load += gcnew System::EventHandler(this, &CatalogForm::CatalogForm_Load);
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
    private: System::Void SaveButton_Click(System::Object^  sender, System::EventArgs^  e) {

        catalogFiles.clear();
        for (int i = 0; i < this->CatalogFilesBox->Lines->Length; i++)
        {
            String^ s0 = this->CatalogFilesBox->Lines[i];
            std::string catalogFileName = msclr::interop::marshal_as<std::string>(s0);
            catalogFiles.push_back(catalogFileName);
        }

    }
    private: System::Void CatalogForm_Load(System::Object^  sender, System::EventArgs^  e) {
        for (int i = 0; i < catalogFiles.size(); i++)
        {
            String^ catalogFileName = gcnew String(catalogFiles[i].c_str());
            this->CatalogFilesBox->AppendText(catalogFileName);
            String^ newLine = gcnew String("\n");
            this->CatalogFilesBox->AppendText(newLine);
        }
    }
};
}

#pragma once

#include <string>
#include <regex>
#include <msclr\marshal_cppstd.h>
#include <iostream>
#include <fstream>
#include <conio.h>
#include <vector>

extern std::vector<std::string> vendorNames;
extern std::vector<std::string> vendorPatterns;
extern std::vector<std::string> vendorObsoleteFiles;

namespace Skus {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for VendorsForm
	/// </summary>
	public ref class VendorsForm : public System::Windows::Forms::Form
	{
	public:
		VendorsForm(void)
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
		~VendorsForm()
		{
			if (components)
			{
				delete components;
			}
		}
    private: System::Windows::Forms::TextBox^  VendorNameBox;
    protected:
    private: System::Windows::Forms::Label^  label1;
    private: System::Windows::Forms::TextBox^  VendorRegEx1Box;
    private: System::Windows::Forms::Label^  label2;
    private: System::Windows::Forms::Label^  label3;
    private: System::Windows::Forms::TextBox^  VendorObsoleteBox;



    private: System::Windows::Forms::ComboBox^  VendorSelectionBox;
    private: System::Windows::Forms::Button^  SaveVendorButton;

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
            this->VendorNameBox = (gcnew System::Windows::Forms::TextBox());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->VendorRegEx1Box = (gcnew System::Windows::Forms::TextBox());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->VendorObsoleteBox = (gcnew System::Windows::Forms::TextBox());
            this->VendorSelectionBox = (gcnew System::Windows::Forms::ComboBox());
            this->SaveVendorButton = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // VendorNameBox
            // 
            this->VendorNameBox->Location = System::Drawing::Point(146, 64);
            this->VendorNameBox->Name = L"VendorNameBox";
            this->VendorNameBox->Size = System::Drawing::Size(100, 20);
            this->VendorNameBox->TabIndex = 0;
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(39, 67);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(72, 13);
            this->label1->TabIndex = 1;
            this->label1->Text = L"Vendor Name";
            // 
            // VendorRegEx1Box
            // 
            this->VendorRegEx1Box->Location = System::Drawing::Point(146, 118);
            this->VendorRegEx1Box->Name = L"VendorRegEx1Box";
            this->VendorRegEx1Box->Size = System::Drawing::Size(100, 20);
            this->VendorRegEx1Box->TabIndex = 2;
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(39, 121);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(48, 13);
            this->label2->TabIndex = 3;
            this->label2->Text = L"RegEx 1";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(39, 156);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(68, 13);
            this->label3->TabIndex = 5;
            this->label3->Text = L"Obsolete File";
            // 
            // VendorObsoleteBox
            // 
            this->VendorObsoleteBox->Location = System::Drawing::Point(146, 153);
            this->VendorObsoleteBox->Name = L"VendorObsoleteBox";
            this->VendorObsoleteBox->Size = System::Drawing::Size(100, 20);
            this->VendorObsoleteBox->TabIndex = 4;
            // 
            // VendorSelectionBox
            // 
            this->VendorSelectionBox->FormattingEnabled = true;
            this->VendorSelectionBox->Location = System::Drawing::Point(82, 18);
            this->VendorSelectionBox->Name = L"VendorSelectionBox";
            this->VendorSelectionBox->Size = System::Drawing::Size(121, 21);
            this->VendorSelectionBox->TabIndex = 8;
            this->VendorSelectionBox->SelectedIndexChanged += gcnew System::EventHandler(this, &VendorsForm::VendorSelectionBox_SelectedIndexChanged);
            // 
            // SaveVendorButton
            // 
            this->SaveVendorButton->Location = System::Drawing::Point(105, 220);
            this->SaveVendorButton->Name = L"SaveVendorButton";
            this->SaveVendorButton->Size = System::Drawing::Size(75, 23);
            this->SaveVendorButton->TabIndex = 9;
            this->SaveVendorButton->Text = L"Save";
            this->SaveVendorButton->UseVisualStyleBackColor = true;
            this->SaveVendorButton->Click += gcnew System::EventHandler(this, &VendorsForm::SaveVendorButton_Click);
            // 
            // VendorsForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(284, 261);
            this->Controls->Add(this->SaveVendorButton);
            this->Controls->Add(this->VendorSelectionBox);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->VendorObsoleteBox);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->VendorRegEx1Box);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->VendorNameBox);
            this->Name = L"VendorsForm";
            this->Text = L"Vendors Properties";
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

        public:
            System::Windows::Forms::ComboBox^  getVendorSelectionBox() { return VendorSelectionBox; }
            System::Windows::Forms::TextBox^  getVendorRegEx1Box() { return VendorRegEx1Box; }
            System::Windows::Forms::TextBox^  getVendorObsoleteBox() { return VendorObsoleteBox; }
            System::Windows::Forms::TextBox^  getVendorNameBox() { return VendorNameBox; }
    private: System::Void VendorSelectionBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {

        String^ vendorName;
        if (VendorSelectionBox->SelectedIndex >= vendorNames.size())
            vendorName = gcnew String("");
        else
            vendorName = gcnew String(vendorNames[VendorSelectionBox->SelectedIndex].c_str());
        VendorNameBox->Text = vendorName;

        String^ regEx1;
        if (VendorSelectionBox->SelectedIndex >= vendorPatterns.size())
            regEx1 = gcnew String(""); 
        else
            regEx1 = gcnew String(vendorPatterns[VendorSelectionBox->SelectedIndex].c_str());
        VendorRegEx1Box->Text = regEx1;

        String^ obsoleteFile;
        if (VendorSelectionBox->SelectedIndex >= vendorObsoleteFiles.size())
            obsoleteFile = gcnew String("");
        else
            obsoleteFile = gcnew String(vendorObsoleteFiles[VendorSelectionBox->SelectedIndex].c_str());
        VendorObsoleteBox->Text = obsoleteFile;

    }
private: System::Void SaveVendorButton_Click(System::Object^  sender, System::EventArgs^  e) {


    std::string vendorName = msclr::interop::marshal_as<std::string>(VendorNameBox->Text);
    if (VendorSelectionBox->SelectedIndex >= vendorNames.size())
        vendorNames.push_back(vendorName);
    else
        vendorNames[VendorSelectionBox->SelectedIndex] = vendorName;

    std::string regEx1 = msclr::interop::marshal_as<std::string>(VendorRegEx1Box->Text);
    if (VendorSelectionBox->SelectedIndex >= vendorPatterns.size())
        vendorPatterns.push_back(regEx1);
    else
        vendorPatterns[VendorSelectionBox->SelectedIndex] = regEx1;

    std::string obsoleteFile = msclr::interop::marshal_as<std::string>(VendorObsoleteBox->Text);
    if (VendorSelectionBox->SelectedIndex >= vendorObsoleteFiles.size())
        vendorObsoleteFiles.push_back(obsoleteFile);
    else
        vendorObsoleteFiles[VendorSelectionBox->SelectedIndex] = obsoleteFile;
}
};
}

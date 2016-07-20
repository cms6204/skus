#pragma once

#include <string>
#include <regex>
#include <msclr\marshal_cppstd.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <conio.h>

#include "VendorsForm.h"
#include "CatalogForm.h"
#include "HelpForm.h"

std::vector<std::string> catalogFiles;
std::vector<std::string> vendorNames;
std::vector<std::string> vendorPatterns;
std::vector<std::string> fileOutput;
std::vector<std::string> columnNames;
std::vector<std::string> vendorObsoleteFiles;
std::vector<std::string> obsoleteParts;

namespace Skus {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			//AllocConsole();
            columnNames.push_back("Customer Specs / PO");
            columnNames.push_back("Vendor Quote");
            columnNames.push_back("BYD");
            columnNames.push_back("MSRP");
            columnNames.push_back("Catalog");
            columnNames.push_back("Sales Quote");

            String^ line;
            try
            {
                System::IO::StreamReader ^ sr1 = gcnew System::IO::StreamReader("SkuCatalogSettings.txt");
                catalogFiles.clear();
                while (line = sr1->ReadLine())
                {
                    std::string sline = msclr::interop::marshal_as<std::string>(line);
                    catalogFiles.push_back(sline);
                }
                sr1->Close();
            }
            catch (Exception^ e)
            {
            }

            try
            {
                System::IO::StreamReader ^ sr2 = gcnew System::IO::StreamReader("SkuVendorSettings.txt");        
                vendorNames.clear();
                vendorPatterns.clear();
                vendorObsoleteFiles.clear();
                int lcnt = 0;
                while (line = sr2->ReadLine())
                {
                    std::string sline = msclr::interop::marshal_as<std::string>(line);
                    if (lcnt % 3 == 0) vendorNames.push_back(sline);
                    else if (lcnt % 3 == 1) vendorPatterns.push_back(sline);
                    else if (lcnt % 3 == 2) vendorObsoleteFiles.push_back(sline);
                    lcnt++;
                }
                sr2->Close();
            }
            catch (Exception^ e)
            {
            }

			for (int i = 0; i < catalogFiles.size(); i++)
			{
				String^ catalogFileName = gcnew String(catalogFiles[i].c_str());
				this->comboBox1->Items->Add(catalogFileName);
			}

			for (int i = 0; i < vendorNames.size(); i++)
			{
				String^ vendorName = gcnew String(vendorNames[i].c_str());
				this->comboBox2->Items->Add(vendorName);
			}
			if (vendorNames.size() > 0) comboBox2->SelectedIndex = 0;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

    protected: 


	private: System::Windows::Forms::TextBox^  fileNameBox1;


	private: System::Windows::Forms::Button^  loadFileButton1;


	private: System::Windows::Forms::Button^  compareButton;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::RichTextBox^  richTextBox2;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::RichTextBox^  richTextBox10;
	private: System::Windows::Forms::RichTextBox^  richTextBox9;
	private: System::Windows::Forms::RichTextBox^  richTextBox8;
	private: System::Windows::Forms::RichTextBox^  richTextBox7;
	private: System::Windows::Forms::RichTextBox^  richTextBox6;
	private: System::Windows::Forms::RichTextBox^  richTextBox5;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  fileNameBox3;
	private: System::Windows::Forms::Button^  loadFileButton3;
	private: System::Windows::Forms::Button^  loadFileButton2;
	private: System::Windows::Forms::TextBox^  fileNameBox2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::RichTextBox^  richTextBox4;
	private: System::Windows::Forms::RichTextBox^  richTextBox3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::TextBox^  fileNameBox4;
	private: System::Windows::Forms::Button^  loadFileButton4;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Button^  clearButton1;
	private: System::Windows::Forms::Button^  clearButton2;
	private: System::Windows::Forms::Button^  clearButton3;
	private: System::Windows::Forms::Button^  clearButton4;
	private: System::Windows::Forms::Button^  approvalButton;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::CheckBox^  checkBox3;
	private: System::Windows::Forms::CheckBox^  checkBox4;
	private: System::Windows::Forms::CheckBox^  checkBox5;
	private: System::Windows::Forms::CheckBox^  checkBox6;
	private: System::Windows::Forms::CheckBox^  checkBox7;
	private: System::Windows::Forms::CheckBox^  checkBox8;
	private: System::Windows::Forms::CheckBox^  checkBox9;
	private: System::Windows::Forms::CheckBox^  checkBox10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::Label^  label16;
private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
private: System::Windows::Forms::MenuStrip^  menuStrip1;
private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  programToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  addEditVendorToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  catalogFilesToolStripMenuItem;
private: System::Windows::Forms::Label^  label17;
private: System::Windows::Forms::CheckBox^  checkBox11;
private: System::Windows::Forms::CheckBox^  checkBox12;
private: System::Windows::Forms::RichTextBox^  richTextBox11;
private: System::Windows::Forms::RichTextBox^  richTextBox12;
private: System::Windows::Forms::Label^  label18;
private: System::Windows::Forms::Label^  label19;
private: System::Windows::Forms::Button^  clearButton5;
private: System::Windows::Forms::Button^  loadFileButton5;
private: System::Windows::Forms::TextBox^  fileNameBox5;
private: System::Windows::Forms::ToolStripMenuItem^  quitToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;



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
			this->fileNameBox1 = (gcnew System::Windows::Forms::TextBox());
			this->loadFileButton1 = (gcnew System::Windows::Forms::Button());
			this->compareButton = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->richTextBox10 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox9 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox8 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox7 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox6 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox5 = (gcnew System::Windows::Forms::RichTextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->fileNameBox3 = (gcnew System::Windows::Forms::TextBox());
			this->loadFileButton3 = (gcnew System::Windows::Forms::Button());
			this->loadFileButton2 = (gcnew System::Windows::Forms::Button());
			this->fileNameBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->richTextBox4 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox3 = (gcnew System::Windows::Forms::RichTextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->fileNameBox4 = (gcnew System::Windows::Forms::TextBox());
			this->loadFileButton4 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->clearButton1 = (gcnew System::Windows::Forms::Button());
			this->clearButton2 = (gcnew System::Windows::Forms::Button());
			this->clearButton3 = (gcnew System::Windows::Forms::Button());
			this->clearButton4 = (gcnew System::Windows::Forms::Button());
			this->approvalButton = (gcnew System::Windows::Forms::Button());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox5 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox6 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox7 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox8 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox9 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox10 = (gcnew System::Windows::Forms::CheckBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->quitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->programToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addEditVendorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->catalogFilesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->checkBox11 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox12 = (gcnew System::Windows::Forms::CheckBox());
			this->richTextBox11 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox12 = (gcnew System::Windows::Forms::RichTextBox());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->clearButton5 = (gcnew System::Windows::Forms::Button());
			this->loadFileButton5 = (gcnew System::Windows::Forms::Button());
			this->fileNameBox5 = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// fileNameBox1
			// 
			this->fileNameBox1->Location = System::Drawing::Point(250, 424);
			this->fileNameBox1->Name = L"fileNameBox1";
			this->fileNameBox1->ReadOnly = true;
			this->fileNameBox1->Size = System::Drawing::Size(150, 20);
			this->fileNameBox1->TabIndex = 3;
			// 
			// loadFileButton1
			// 
			this->loadFileButton1->Location = System::Drawing::Point(290, 468);
			this->loadFileButton1->Name = L"loadFileButton1";
			this->loadFileButton1->Size = System::Drawing::Size(70, 23);
			this->loadFileButton1->TabIndex = 6;
			this->loadFileButton1->Text = L"Load";
			this->loadFileButton1->UseVisualStyleBackColor = true;
			this->loadFileButton1->Click += gcnew System::EventHandler(this, &MainForm::loadFileButton1_Click);
			// 
			// compareButton
			// 
			this->compareButton->Location = System::Drawing::Point(1185, 41);
			this->compareButton->Name = L"compareButton";
			this->compareButton->Size = System::Drawing::Size(75, 23);
			this->compareButton->TabIndex = 9;
			this->compareButton->Text = L"Compare";
			this->compareButton->UseVisualStyleBackColor = true;
			this->compareButton->Click += gcnew System::EventHandler(this, &MainForm::compareButton_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// richTextBox1
			// 
			this->richTextBox1->AllowDrop = true;
			this->richTextBox1->Location = System::Drawing::Point(230, 150);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
			this->richTextBox1->Size = System::Drawing::Size(90, 225);
			this->richTextBox1->TabIndex = 10;
			this->richTextBox1->Text = L"";
			this->richTextBox1->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &MainForm::richTextBox1_DragDrop);
			this->richTextBox1->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &MainForm::richTextBox1_DragEnter);
			this->richTextBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::richTextBox1_MouseClick);
			// 
			// richTextBox2
			// 
			this->richTextBox2->AllowDrop = true;
			this->richTextBox2->Location = System::Drawing::Point(330, 150);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->ReadOnly = true;
			this->richTextBox2->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
			this->richTextBox2->Size = System::Drawing::Size(90, 225);
			this->richTextBox2->TabIndex = 11;
			this->richTextBox2->Text = L"";
			this->richTextBox2->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &MainForm::richTextBox2_DragDrop);
			this->richTextBox2->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &MainForm::richTextBox2_DragEnter);
			this->richTextBox2->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::richTextBox2_MouseClick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(227, 392);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(66, 13);
			this->label1->TabIndex = 13;
			this->label1->Text = L"Mismatches:";
			// 
			// richTextBox10
			// 
			this->richTextBox10->AllowDrop = true;
			this->richTextBox10->Location = System::Drawing::Point(1170, 150);
			this->richTextBox10->Name = L"richTextBox10";
			this->richTextBox10->ReadOnly = true;
			this->richTextBox10->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
			this->richTextBox10->Size = System::Drawing::Size(90, 225);
			this->richTextBox10->TabIndex = 22;
			this->richTextBox10->Text = L"";
			// 
			// richTextBox9
			// 
			this->richTextBox9->AllowDrop = true;
			this->richTextBox9->Location = System::Drawing::Point(1070, 150);
			this->richTextBox9->Name = L"richTextBox9";
			this->richTextBox9->ReadOnly = true;
			this->richTextBox9->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
			this->richTextBox9->Size = System::Drawing::Size(90, 225);
			this->richTextBox9->TabIndex = 21;
			this->richTextBox9->Text = L"";
			// 
			// richTextBox8
			// 
			this->richTextBox8->AllowDrop = true;
			this->richTextBox8->Location = System::Drawing::Point(960, 150);
			this->richTextBox8->Name = L"richTextBox8";
			this->richTextBox8->ReadOnly = true;
			this->richTextBox8->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
			this->richTextBox8->Size = System::Drawing::Size(90, 225);
			this->richTextBox8->TabIndex = 20;
			this->richTextBox8->Text = L"";
			this->richTextBox8->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &MainForm::richTextBox8_DragDrop);
			this->richTextBox8->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &MainForm::richTextBox8_DragEnter);
			this->richTextBox8->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::richTextBox8_MouseClick);
			// 
			// richTextBox7
			// 
			this->richTextBox7->AllowDrop = true;
			this->richTextBox7->Location = System::Drawing::Point(860, 150);
			this->richTextBox7->Name = L"richTextBox7";
			this->richTextBox7->ReadOnly = true;
			this->richTextBox7->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
			this->richTextBox7->Size = System::Drawing::Size(90, 225);
			this->richTextBox7->TabIndex = 19;
			this->richTextBox7->Text = L"";
			this->richTextBox7->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &MainForm::richTextBox7_DragDrop);
			this->richTextBox7->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &MainForm::richTextBox7_DragEnter);
			this->richTextBox7->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::richTextBox7_MouseClick);
			// 
			// richTextBox6
			// 
			this->richTextBox6->AllowDrop = true;
			this->richTextBox6->Location = System::Drawing::Point(750, 150);
			this->richTextBox6->Name = L"richTextBox6";
			this->richTextBox6->ReadOnly = true;
			this->richTextBox6->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
			this->richTextBox6->Size = System::Drawing::Size(90, 225);
			this->richTextBox6->TabIndex = 18;
			this->richTextBox6->Text = L"";
			this->richTextBox6->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &MainForm::richTextBox6_DragDrop);
			this->richTextBox6->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &MainForm::richTextBox6_DragEnter);
			this->richTextBox6->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::richTextBox6_MouseClick);
			// 
			// richTextBox5
			// 
			this->richTextBox5->AllowDrop = true;
			this->richTextBox5->Location = System::Drawing::Point(650, 150);
			this->richTextBox5->Name = L"richTextBox5";
			this->richTextBox5->ReadOnly = true;
			this->richTextBox5->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
			this->richTextBox5->Size = System::Drawing::Size(90, 225);
			this->richTextBox5->TabIndex = 17;
			this->richTextBox5->Text = L"";
			this->richTextBox5->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &MainForm::richTextBox5_DragDrop);
			this->richTextBox5->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &MainForm::richTextBox5_DragEnter);
			this->richTextBox5->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::richTextBox5_MouseClick);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(437, 392);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(66, 13);
			this->label3->TabIndex = 15;
			this->label3->Text = L"Mismatches:";
			// 
			// fileNameBox3
			// 
			this->fileNameBox3->Location = System::Drawing::Point(670, 424);
			this->fileNameBox3->Name = L"fileNameBox3";
			this->fileNameBox3->ReadOnly = true;
			this->fileNameBox3->Size = System::Drawing::Size(150, 20);
			this->fileNameBox3->TabIndex = 5;
			// 
			// loadFileButton3
			// 
			this->loadFileButton3->Location = System::Drawing::Point(710, 468);
			this->loadFileButton3->Name = L"loadFileButton3";
			this->loadFileButton3->Size = System::Drawing::Size(70, 23);
			this->loadFileButton3->TabIndex = 8;
			this->loadFileButton3->Text = L"Load";
			this->loadFileButton3->UseVisualStyleBackColor = true;
			this->loadFileButton3->Click += gcnew System::EventHandler(this, &MainForm::loadFileButton3_Click);
			// 
			// loadFileButton2
			// 
			this->loadFileButton2->Location = System::Drawing::Point(500, 468);
			this->loadFileButton2->Name = L"loadFileButton2";
			this->loadFileButton2->Size = System::Drawing::Size(70, 23);
			this->loadFileButton2->TabIndex = 7;
			this->loadFileButton2->Text = L"Load";
			this->loadFileButton2->UseVisualStyleBackColor = true;
			this->loadFileButton2->Click += gcnew System::EventHandler(this, &MainForm::loadFileButton2_Click);
			// 
			// fileNameBox2
			// 
			this->fileNameBox2->Location = System::Drawing::Point(460, 424);
			this->fileNameBox2->Name = L"fileNameBox2";
			this->fileNameBox2->ReadOnly = true;
			this->fileNameBox2->Size = System::Drawing::Size(150, 20);
			this->fileNameBox2->TabIndex = 4;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(327, 392);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(66, 13);
			this->label2->TabIndex = 14;
			this->label2->Text = L"Mismatches:";
			// 
			// richTextBox4
			// 
			this->richTextBox4->AllowDrop = true;
			this->richTextBox4->Location = System::Drawing::Point(540, 150);
			this->richTextBox4->Name = L"richTextBox4";
			this->richTextBox4->ReadOnly = true;
			this->richTextBox4->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
			this->richTextBox4->Size = System::Drawing::Size(90, 225);
			this->richTextBox4->TabIndex = 16;
			this->richTextBox4->Text = L"";
			this->richTextBox4->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &MainForm::richTextBox4_DragDrop);
			this->richTextBox4->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &MainForm::richTextBox4_DragEnter);
			this->richTextBox4->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::richTextBox4_MouseClick);
			// 
			// richTextBox3
			// 
			this->richTextBox3->AllowDrop = true;
			this->richTextBox3->Location = System::Drawing::Point(440, 150);
			this->richTextBox3->Name = L"richTextBox3";
			this->richTextBox3->ReadOnly = true;
			this->richTextBox3->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
			this->richTextBox3->Size = System::Drawing::Size(90, 225);
			this->richTextBox3->TabIndex = 12;
			this->richTextBox3->Text = L"";
			this->richTextBox3->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &MainForm::richTextBox3_DragDrop);
			this->richTextBox3->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &MainForm::richTextBox3_DragEnter);
			this->richTextBox3->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::richTextBox3_MouseClick);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(537, 392);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(66, 13);
			this->label4->TabIndex = 23;
			this->label4->Text = L"Mismatches:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(647, 392);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(66, 13);
			this->label5->TabIndex = 24;
			this->label5->Text = L"Mismatches:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(747, 392);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(66, 13);
			this->label6->TabIndex = 25;
			this->label6->Text = L"Mismatches:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(857, 392);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(66, 13);
			this->label7->TabIndex = 26;
			this->label7->Text = L"Mismatches:";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(957, 392);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(66, 13);
			this->label8->TabIndex = 27;
			this->label8->Text = L"Mismatches:";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(1067, 392);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(66, 13);
			this->label9->TabIndex = 28;
			this->label9->Text = L"Mismatches:";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(1167, 392);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(66, 13);
			this->label10->TabIndex = 29;
			this->label10->Text = L"Mismatches:";
			// 
			// fileNameBox4
			// 
			this->fileNameBox4->Location = System::Drawing::Point(880, 424);
			this->fileNameBox4->Name = L"fileNameBox4";
			this->fileNameBox4->ReadOnly = true;
			this->fileNameBox4->Size = System::Drawing::Size(150, 20);
			this->fileNameBox4->TabIndex = 30;
			// 
			// loadFileButton4
			// 
			this->loadFileButton4->Location = System::Drawing::Point(920, 468);
			this->loadFileButton4->Name = L"loadFileButton4";
			this->loadFileButton4->Size = System::Drawing::Size(70, 23);
			this->loadFileButton4->TabIndex = 31;
			this->loadFileButton4->Text = L"Load";
			this->loadFileButton4->UseVisualStyleBackColor = true;
			this->loadFileButton4->Click += gcnew System::EventHandler(this, &MainForm::loadFileButton4_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(1090, 424);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(150, 21);
			this->comboBox1->TabIndex = 32;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::comboBox1_SelectedIndexChanged);
			// 
			// clearButton1
			// 
			this->clearButton1->Location = System::Drawing::Point(290, 514);
			this->clearButton1->Name = L"clearButton1";
			this->clearButton1->Size = System::Drawing::Size(70, 23);
			this->clearButton1->TabIndex = 33;
			this->clearButton1->Text = L"Clear";
			this->clearButton1->UseVisualStyleBackColor = true;
			this->clearButton1->Click += gcnew System::EventHandler(this, &MainForm::clearButton1_Click);
			// 
			// clearButton2
			// 
			this->clearButton2->Location = System::Drawing::Point(500, 514);
			this->clearButton2->Name = L"clearButton2";
			this->clearButton2->Size = System::Drawing::Size(70, 23);
			this->clearButton2->TabIndex = 34;
			this->clearButton2->Text = L"Clear";
			this->clearButton2->UseVisualStyleBackColor = true;
			this->clearButton2->Click += gcnew System::EventHandler(this, &MainForm::clearButton2_Click);
			// 
			// clearButton3
			// 
			this->clearButton3->Location = System::Drawing::Point(710, 514);
			this->clearButton3->Name = L"clearButton3";
			this->clearButton3->Size = System::Drawing::Size(70, 23);
			this->clearButton3->TabIndex = 35;
			this->clearButton3->Text = L"Clear";
			this->clearButton3->UseVisualStyleBackColor = true;
			this->clearButton3->Click += gcnew System::EventHandler(this, &MainForm::clearButton3_Click);
			// 
			// clearButton4
			// 
			this->clearButton4->Location = System::Drawing::Point(920, 514);
			this->clearButton4->Name = L"clearButton4";
			this->clearButton4->Size = System::Drawing::Size(70, 23);
			this->clearButton4->TabIndex = 36;
			this->clearButton4->Text = L"Clear";
			this->clearButton4->UseVisualStyleBackColor = true;
			this->clearButton4->Click += gcnew System::EventHandler(this, &MainForm::clearButton4_Click);
			// 
			// approvalButton
			// 
			this->approvalButton->Location = System::Drawing::Point(1006, 41);
			this->approvalButton->Name = L"approvalButton";
			this->approvalButton->Size = System::Drawing::Size(154, 23);
			this->approvalButton->TabIndex = 37;
			this->approvalButton->Text = L"Generate Approval Note";
			this->approvalButton->UseVisualStyleBackColor = true;
			this->approvalButton->Click += gcnew System::EventHandler(this, &MainForm::approvalButton_Click);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(230, 121);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(50, 17);
			this->checkBox1->TabIndex = 38;
			this->checkBox1->Text = L"Skus";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(330, 121);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(47, 17);
			this->checkBox2->TabIndex = 39;
			this->checkBox2->Text = L"Qtys";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(440, 121);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(50, 17);
			this->checkBox3->TabIndex = 40;
			this->checkBox3->Text = L"Skus";
			this->checkBox3->UseVisualStyleBackColor = true;
			// 
			// checkBox4
			// 
			this->checkBox4->AutoSize = true;
			this->checkBox4->Location = System::Drawing::Point(540, 121);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(47, 17);
			this->checkBox4->TabIndex = 41;
			this->checkBox4->Text = L"Qtys";
			this->checkBox4->UseVisualStyleBackColor = true;
			// 
			// checkBox5
			// 
			this->checkBox5->AutoSize = true;
			this->checkBox5->Location = System::Drawing::Point(650, 121);
			this->checkBox5->Name = L"checkBox5";
			this->checkBox5->Size = System::Drawing::Size(50, 17);
			this->checkBox5->TabIndex = 42;
			this->checkBox5->Text = L"Skus";
			this->checkBox5->UseVisualStyleBackColor = true;
			// 
			// checkBox6
			// 
			this->checkBox6->AutoSize = true;
			this->checkBox6->Location = System::Drawing::Point(750, 121);
			this->checkBox6->Name = L"checkBox6";
			this->checkBox6->Size = System::Drawing::Size(47, 17);
			this->checkBox6->TabIndex = 43;
			this->checkBox6->Text = L"Qtys";
			this->checkBox6->UseVisualStyleBackColor = true;
			// 
			// checkBox7
			// 
			this->checkBox7->AutoSize = true;
			this->checkBox7->Location = System::Drawing::Point(860, 121);
			this->checkBox7->Name = L"checkBox7";
			this->checkBox7->Size = System::Drawing::Size(50, 17);
			this->checkBox7->TabIndex = 44;
			this->checkBox7->Text = L"Skus";
			this->checkBox7->UseVisualStyleBackColor = true;
			// 
			// checkBox8
			// 
			this->checkBox8->AutoSize = true;
			this->checkBox8->Location = System::Drawing::Point(960, 121);
			this->checkBox8->Name = L"checkBox8";
			this->checkBox8->Size = System::Drawing::Size(47, 17);
			this->checkBox8->TabIndex = 45;
			this->checkBox8->Text = L"Qtys";
			this->checkBox8->UseVisualStyleBackColor = true;
			// 
			// checkBox9
			// 
			this->checkBox9->AutoSize = true;
			this->checkBox9->Location = System::Drawing::Point(1070, 121);
			this->checkBox9->Name = L"checkBox9";
			this->checkBox9->Size = System::Drawing::Size(50, 17);
			this->checkBox9->TabIndex = 46;
			this->checkBox9->Text = L"Skus";
			this->checkBox9->UseVisualStyleBackColor = true;
			// 
			// checkBox10
			// 
			this->checkBox10->AutoSize = true;
			this->checkBox10->Location = System::Drawing::Point(1170, 121);
			this->checkBox10->Name = L"checkBox10";
			this->checkBox10->Size = System::Drawing::Size(47, 17);
			this->checkBox10->TabIndex = 47;
			this->checkBox10->Text = L"Qtys";
			this->checkBox10->UseVisualStyleBackColor = true;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(267, 92);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(110, 13);
			this->label11->TabIndex = 48;
			this->label11->Text = L"Customer Specs / PO";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(496, 92);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(73, 13);
			this->label12->TabIndex = 49;
			this->label12->Text = L"Vendor Quote";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(726, 92);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(29, 13);
			this->label13->TabIndex = 50;
			this->label13->Text = L"BYD";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(933, 92);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(38, 13);
			this->label14->TabIndex = 51;
			this->label14->Text = L"MSRP";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(1137, 92);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(43, 13);
			this->label15->TabIndex = 52;
			this->label15->Text = L"Catalog";
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(79, 37);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(150, 21);
			this->comboBox2->TabIndex = 53;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::comboBox2_SelectedIndexChanged);
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(16, 41);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(41, 13);
			this->label16->TabIndex = 54;
			this->label16->Text = L"Vendor";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->fileToolStripMenuItem,
					this->programToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1280, 24);
			this->menuStrip1->TabIndex = 55;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->helpToolStripMenuItem,
					this->quitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(99, 22);
			this->helpToolStripMenuItem->Text = L"Help";
			this->helpToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::helpToolStripMenuItem_Click);
			// 
			// quitToolStripMenuItem
			// 
			this->quitToolStripMenuItem->Name = L"quitToolStripMenuItem";
			this->quitToolStripMenuItem->Size = System::Drawing::Size(99, 22);
			this->quitToolStripMenuItem->Text = L"Quit";
			this->quitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::quitToolStripMenuItem_Click);
			// 
			// programToolStripMenuItem
			// 
			this->programToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->addEditVendorToolStripMenuItem,
					this->catalogFilesToolStripMenuItem
			});
			this->programToolStripMenuItem->Name = L"programToolStripMenuItem";
			this->programToolStripMenuItem->Size = System::Drawing::Size(65, 20);
			this->programToolStripMenuItem->Text = L"Program";
			// 
			// addEditVendorToolStripMenuItem
			// 
			this->addEditVendorToolStripMenuItem->Name = L"addEditVendorToolStripMenuItem";
			this->addEditVendorToolStripMenuItem->Size = System::Drawing::Size(161, 22);
			this->addEditVendorToolStripMenuItem->Text = L"Add/Edit Vendor";
			this->addEditVendorToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::addEditVendorToolStripMenuItem_Click);
			// 
			// catalogFilesToolStripMenuItem
			// 
			this->catalogFilesToolStripMenuItem->Name = L"catalogFilesToolStripMenuItem";
			this->catalogFilesToolStripMenuItem->Size = System::Drawing::Size(161, 22);
			this->catalogFilesToolStripMenuItem->Text = L"Catalog Files";
			this->catalogFilesToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::catalogFilesToolStripMenuItem_Click);
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(76, 92);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(65, 13);
			this->label17->TabIndex = 60;
			this->label17->Text = L"Sales Quote";
			// 
			// checkBox11
			// 
			this->checkBox11->AutoSize = true;
			this->checkBox11->Location = System::Drawing::Point(20, 121);
			this->checkBox11->Name = L"checkBox11";
			this->checkBox11->Size = System::Drawing::Size(50, 17);
			this->checkBox11->TabIndex = 59;
			this->checkBox11->Text = L"Skus";
			this->checkBox11->UseVisualStyleBackColor = true;
			// 
			// checkBox12
			// 
			this->checkBox12->AutoSize = true;
			this->checkBox12->Location = System::Drawing::Point(120, 121);
			this->checkBox12->Name = L"checkBox12";
			this->checkBox12->Size = System::Drawing::Size(47, 17);
			this->checkBox12->TabIndex = 58;
			this->checkBox12->Text = L"Qtys";
			this->checkBox12->UseVisualStyleBackColor = true;
			// 
			// richTextBox11
			// 
			this->richTextBox11->AllowDrop = true;
			this->richTextBox11->Location = System::Drawing::Point(20, 150);
			this->richTextBox11->Name = L"richTextBox11";
			this->richTextBox11->ReadOnly = true;
			this->richTextBox11->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
			this->richTextBox11->Size = System::Drawing::Size(90, 225);
			this->richTextBox11->TabIndex = 57;
			this->richTextBox11->Text = L"";
			this->richTextBox11->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &MainForm::richTextBox11_DragDrop);
			this->richTextBox11->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &MainForm::richTextBox11_DragEnter);
			this->richTextBox11->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::richTextBox11_MouseClick);
			// 
			// richTextBox12
			// 
			this->richTextBox12->AllowDrop = true;
			this->richTextBox12->Location = System::Drawing::Point(120, 150);
			this->richTextBox12->Name = L"richTextBox12";
			this->richTextBox12->ReadOnly = true;
			this->richTextBox12->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
			this->richTextBox12->Size = System::Drawing::Size(90, 225);
			this->richTextBox12->TabIndex = 56;
			this->richTextBox12->Text = L"";
			this->richTextBox12->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &MainForm::richTextBox12_DragDrop);
			this->richTextBox12->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &MainForm::richTextBox12_DragEnter);
			this->richTextBox12->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::richTextBox12_MouseClick);
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(17, 392);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(66, 13);
			this->label18->TabIndex = 62;
			this->label18->Text = L"Mismatches:";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(117, 392);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(66, 13);
			this->label19->TabIndex = 61;
			this->label19->Text = L"Mismatches:";
			// 
			// clearButton5
			// 
			this->clearButton5->Location = System::Drawing::Point(80, 515);
			this->clearButton5->Name = L"clearButton5";
			this->clearButton5->Size = System::Drawing::Size(70, 23);
			this->clearButton5->TabIndex = 65;
			this->clearButton5->Text = L"Clear";
			this->clearButton5->UseVisualStyleBackColor = true;
			this->clearButton5->Click += gcnew System::EventHandler(this, &MainForm::clearButton5_Click);
			// 
			// loadFileButton5
			// 
			this->loadFileButton5->Location = System::Drawing::Point(80, 469);
			this->loadFileButton5->Name = L"loadFileButton5";
			this->loadFileButton5->Size = System::Drawing::Size(70, 23);
			this->loadFileButton5->TabIndex = 64;
			this->loadFileButton5->Text = L"Load";
			this->loadFileButton5->UseVisualStyleBackColor = true;
			this->loadFileButton5->Click += gcnew System::EventHandler(this, &MainForm::loadFileButton5_Click);
			// 
			// fileNameBox5
			// 
			this->fileNameBox5->Location = System::Drawing::Point(40, 424);
			this->fileNameBox5->Name = L"fileNameBox5";
			this->fileNameBox5->ReadOnly = true;
			this->fileNameBox5->Size = System::Drawing::Size(150, 20);
			this->fileNameBox5->TabIndex = 63;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1280, 560);
			this->Controls->Add(this->clearButton5);
			this->Controls->Add(this->loadFileButton5);
			this->Controls->Add(this->fileNameBox5);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->label19);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->checkBox11);
			this->Controls->Add(this->checkBox12);
			this->Controls->Add(this->richTextBox11);
			this->Controls->Add(this->richTextBox12);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->checkBox10);
			this->Controls->Add(this->checkBox9);
			this->Controls->Add(this->checkBox8);
			this->Controls->Add(this->checkBox7);
			this->Controls->Add(this->checkBox6);
			this->Controls->Add(this->checkBox5);
			this->Controls->Add(this->checkBox4);
			this->Controls->Add(this->checkBox3);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->approvalButton);
			this->Controls->Add(this->clearButton4);
			this->Controls->Add(this->clearButton3);
			this->Controls->Add(this->clearButton2);
			this->Controls->Add(this->clearButton1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->loadFileButton4);
			this->Controls->Add(this->fileNameBox4);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->richTextBox10);
			this->Controls->Add(this->richTextBox9);
			this->Controls->Add(this->richTextBox8);
			this->Controls->Add(this->richTextBox7);
			this->Controls->Add(this->richTextBox6);
			this->Controls->Add(this->richTextBox5);
			this->Controls->Add(this->richTextBox4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->richTextBox3);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->compareButton);
			this->Controls->Add(this->loadFileButton3);
			this->Controls->Add(this->loadFileButton2);
			this->Controls->Add(this->loadFileButton1);
			this->Controls->Add(this->fileNameBox3);
			this->Controls->Add(this->fileNameBox2);
			this->Controls->Add(this->fileNameBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MainForm";
			this->Text = L"Spec Check";
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::MainForm_MouseClick);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: void loadFile(String^ fileName, System::Windows::Forms::RichTextBox^ box, System::Windows::Forms::RichTextBox^ qbox, System::Windows::Forms::TextBox^ fileBox)
	{
		box->Clear();
		qbox->Clear();

		System::IO::StreamReader ^ sr = gcnew System::IO::StreamReader(fileName);
		String^ line;
		while (line = sr->ReadLine())
		{
			std::string s = msclr::interop::marshal_as<std::string>(line);
			std::regex word_regex(vendorPatterns[comboBox2->SelectedIndex]); 
			auto words_begin = std::sregex_iterator(s.begin(), s.end(), word_regex);
			auto words_end = std::sregex_iterator();

			for (std::sregex_iterator i = words_begin; i != words_end; ++i)
			{
				std::smatch match = *i;
				std::string match_str = match.str();
				String^ addLine = gcnew String(match_str.substr(0, 8).c_str());
				String^ newLine = gcnew String("\n");
				box->AppendText(addLine);
				box->AppendText(newLine);

				int qntStart = match_str.length() - 1;
				while ((qntStart >= 0) && (match_str[qntStart] >= '0') && (match_str[qntStart] <= '9')) qntStart--;

				if (qntStart < match_str.length() - 1)
				{
					String^ addQuantity = gcnew String(match_str.substr(qntStart+1, match_str.length() - qntStart).c_str());
					qbox->AppendText(addQuantity);
					qbox->AppendText(newLine);
				}
				else
				{
					qbox->AppendText("1");
					qbox->AppendText(newLine);
				}
			}
		}
		sr->Close();
		if (fileBox != nullptr) fileBox->Text = fileName;
	}

	private: void loadText(String^ text, System::Windows::Forms::RichTextBox^ box, System::Windows::Forms::RichTextBox^ qbox, System::Windows::Forms::TextBox^ fileBox)
	{
		box->Clear();
		qbox->Clear();
		fileBox->Clear();

		std::string stext = msclr::interop::marshal_as<std::string>(text);
		std::stringstream ss(stext.c_str());
		std::string s;

		if (stext.c_str() != NULL)
		{
			while (std::getline(ss, s, '\n'))
			{
				std::cout << "Line processed" << std::endl;
				std::regex word_regex(vendorPatterns[comboBox2->SelectedIndex]);
				auto words_begin = std::sregex_iterator(s.begin(), s.end(), word_regex);
				auto words_end = std::sregex_iterator();

				for (std::sregex_iterator i = words_begin; i != words_end; ++i)
				{
					std::smatch match = *i;
					std::string match_str = match.str();
					String^ addLine = gcnew String(match_str.substr(0, 8).c_str());
					String^ newLine = gcnew String("\n");
					box->AppendText(addLine);
					box->AppendText(newLine);

					int qntStart = match_str.length() - 1;
					while ((qntStart >= 0) && (match_str[qntStart] >= '0') && (match_str[qntStart] <= '9')) qntStart--;

					if (qntStart < match_str.length() - 1)
					{
						String^ addQuantity = gcnew String(match_str.substr(qntStart + 1, match_str.length() - qntStart).c_str());
						qbox->AppendText(addQuantity);
						qbox->AppendText(newLine);
					}
					else
					{
						qbox->AppendText("1");
						qbox->AppendText(newLine);
					}
				}
			}
		}
	
		if (fileBox != nullptr) fileBox->Clear();
	}

    private: void loadObsoleteParts(String^ fileName)
    {
        System::IO::StreamReader ^ sr = gcnew System::IO::StreamReader(fileName);
        String^ line;
        obsoleteParts.clear();
        while (line = sr->ReadLine())
        {
            std::string part = msclr::interop::marshal_as<std::string>(line);
            obsoleteParts.push_back(part);
        }
        sr->Close();
    }

	private: System::Void loadFileButton1_Click(System::Object^  sender, System::EventArgs^  e) {
        if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
        {
            loadFile(openFileDialog1->FileName, this->richTextBox1, this->richTextBox2, this->fileNameBox1);
            this->checkBox1->Checked = true;  this->checkBox2->Checked = true;
        }
	}
	private: System::Void loadFileButton2_Click(System::Object^  sender, System::EventArgs^  e) {
        if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
        {
            loadFile(openFileDialog1->FileName, this->richTextBox3, this->richTextBox4, this->fileNameBox2);
            this->checkBox3->Checked = true;  this->checkBox4->Checked = true;
        }
	}
	private: System::Void loadFileButton3_Click(System::Object^  sender, System::EventArgs^  e) {
        if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
        {
            loadFile(openFileDialog1->FileName, this->richTextBox5, this->richTextBox6, this->fileNameBox3);
            this->checkBox5->Checked = true;  this->checkBox6->Checked = true;
        }
	}
	private: System::Void loadFileButton4_Click(System::Object^  sender, System::EventArgs^  e) {
        if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
        {
            loadFile(openFileDialog1->FileName, this->richTextBox7, this->richTextBox8, this->fileNameBox4);
            this->checkBox7->Checked = true;  this->checkBox8->Checked = true;
        }
	}
    private: System::Void loadFileButton5_Click(System::Object^  sender, System::EventArgs^  e) {
        if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
        {
            loadFile(openFileDialog1->FileName, this->richTextBox11, this->richTextBox12, this->fileNameBox5);
            this->checkBox11->Checked = true;  this->checkBox12->Checked = true;
        }
    }


	private: void richTextBox1_DragEnter(System::Object ^  sender,
				 System::Windows::Forms::DragEventArgs ^  e)
	{
		if (e->Data->GetDataPresent(DataFormats::FileDrop)) e->Effect = DragDropEffects::All;
		else if (e->Data->GetDataPresent(DataFormats::Text)) e->Effect = DragDropEffects::Copy;
		else e->Effect = DragDropEffects::None;
	}

	private: System::Void richTextBox1_DragDrop(System::Object ^  sender,
			System::Windows::Forms::DragEventArgs ^  e)
	{
		if (e->Data->GetDataPresent(DataFormats::Text))
		{
			loadText(e->Data->GetData(DataFormats::Text)->ToString(), this->richTextBox1, this->richTextBox2, this->fileNameBox1);
			this->checkBox1->Checked = true;  this->checkBox2->Checked = true;
		}
		else if (e->Data->GetDataPresent(DataFormats::FileDrop))
		{
			System::Object^ object = e->Data->GetData(DataFormats::FileDrop, false);
			array<String^>^ s = dynamic_cast<array<String^>^>(object);
			if (s->Length > 0) {
				loadFile(s[0], this->richTextBox1, this->richTextBox2, this->fileNameBox1);
				this->checkBox1->Checked = true;  this->checkBox2->Checked = true;
			}
		}
	}

	private: void richTextBox2_DragEnter(System::Object ^  sender,
		System::Windows::Forms::DragEventArgs ^  e)
	{
		if (e->Data->GetDataPresent(DataFormats::FileDrop)) e->Effect = DragDropEffects::All;
		else if (e->Data->GetDataPresent(DataFormats::Text)) e->Effect = DragDropEffects::Copy;
		else e->Effect = DragDropEffects::None;
	}

	private: System::Void richTextBox2_DragDrop(System::Object ^  sender,
		System::Windows::Forms::DragEventArgs ^  e)
	{
		if (e->Data->GetDataPresent(DataFormats::Text))
		{
			loadText(e->Data->GetData(DataFormats::Text)->ToString(), this->richTextBox1, this->richTextBox2, this->fileNameBox1);
			this->checkBox1->Checked = true;  this->checkBox2->Checked = true;
		}
		else if (e->Data->GetDataPresent(DataFormats::FileDrop))
		{
			System::Object^ object = e->Data->GetData(DataFormats::FileDrop, false);
			array<String^>^ s = dynamic_cast<array<String^>^>(object);
			if (s->Length > 0)
			{
				loadFile(s[0], this->richTextBox1, this->richTextBox2, this->fileNameBox1);
				this->checkBox1->Checked = true;  this->checkBox2->Checked = true;
			}
		}
	}

	private: void richTextBox3_DragEnter(System::Object ^  sender,
		System::Windows::Forms::DragEventArgs ^  e)
	{
		if (e->Data->GetDataPresent(DataFormats::FileDrop)) e->Effect = DragDropEffects::All;
		else if (e->Data->GetDataPresent(DataFormats::Text)) e->Effect = DragDropEffects::Copy;
		else e->Effect = DragDropEffects::None;
	}

	private: System::Void richTextBox3_DragDrop(System::Object ^  sender,
		System::Windows::Forms::DragEventArgs ^  e)
	{
		if (e->Data->GetDataPresent(DataFormats::Text))
		{
			loadText(e->Data->GetData(DataFormats::Text)->ToString(), this->richTextBox3, this->richTextBox4, this->fileNameBox2);
			this->checkBox3->Checked = true;  this->checkBox4->Checked = true;
		}
		else if (e->Data->GetDataPresent(DataFormats::FileDrop))
		{
			System::Object^ object = e->Data->GetData(DataFormats::FileDrop, false);
			array<String^>^ s = dynamic_cast<array<String^>^>(object);
			if (s->Length > 0)
			{
				loadFile(s[0], this->richTextBox3, this->richTextBox4, this->fileNameBox2);
				this->checkBox3->Checked = true;  this->checkBox4->Checked = true;
			}
		}
	}

	private: void richTextBox4_DragEnter(System::Object ^  sender,
		System::Windows::Forms::DragEventArgs ^  e)
	{
		if (e->Data->GetDataPresent(DataFormats::FileDrop)) e->Effect = DragDropEffects::All;
		else if (e->Data->GetDataPresent(DataFormats::Text)) e->Effect = DragDropEffects::Copy;
		else e->Effect = DragDropEffects::None;
	}

	private: System::Void richTextBox4_DragDrop(System::Object ^  sender,
		System::Windows::Forms::DragEventArgs ^  e)
	{
		if (e->Data->GetDataPresent(DataFormats::Text))
		{
			loadText(e->Data->GetData(DataFormats::Text)->ToString(), this->richTextBox3, this->richTextBox4, this->fileNameBox2);
			this->checkBox3->Checked = true;  this->checkBox4->Checked = true;
		}
		else if (e->Data->GetDataPresent(DataFormats::FileDrop))
		{
			System::Object^ object = e->Data->GetData(DataFormats::FileDrop, false);
			array<String^>^ s = dynamic_cast<array<String^>^>(object);
			if (s->Length > 0)
			{
				loadFile(s[0], this->richTextBox3, this->richTextBox4, this->fileNameBox2);
				this->checkBox3->Checked = true;  this->checkBox4->Checked = true;
			}
		}
	}

	private: void richTextBox5_DragEnter(System::Object ^  sender,
		System::Windows::Forms::DragEventArgs ^  e)
	{
		if (e->Data->GetDataPresent(DataFormats::FileDrop)) e->Effect = DragDropEffects::All;
		else if (e->Data->GetDataPresent(DataFormats::Text)) e->Effect = DragDropEffects::Copy;
		else e->Effect = DragDropEffects::None;
	}

	private: System::Void richTextBox5_DragDrop(System::Object ^  sender,
		System::Windows::Forms::DragEventArgs ^  e)
	{
		if (e->Data->GetDataPresent(DataFormats::Text))
		{
			loadText(e->Data->GetData(DataFormats::Text)->ToString(), this->richTextBox5, this->richTextBox6, this->fileNameBox3);
			this->checkBox5->Checked = true;  this->checkBox6->Checked = true;
		}
		else if (e->Data->GetDataPresent(DataFormats::FileDrop))
		{
			System::Object^ object = e->Data->GetData(DataFormats::FileDrop, false);
			array<String^>^ s = dynamic_cast<array<String^>^>(object);
			if (s->Length > 0)
			{
				loadFile(s[0], this->richTextBox5, this->richTextBox6, this->fileNameBox3);
				this->checkBox5->Checked = true;  this->checkBox6->Checked = true;
			}
		}
	}

	private: void richTextBox6_DragEnter(System::Object ^  sender,
		System::Windows::Forms::DragEventArgs ^  e)
	{
		if (e->Data->GetDataPresent(DataFormats::FileDrop)) e->Effect = DragDropEffects::All;
		else if (e->Data->GetDataPresent(DataFormats::Text)) e->Effect = DragDropEffects::Copy;
		else e->Effect = DragDropEffects::None;
	}

	private: System::Void richTextBox6_DragDrop(System::Object ^  sender,
		System::Windows::Forms::DragEventArgs ^  e)
	{
		if (e->Data->GetDataPresent(DataFormats::Text))
		{
			loadText(e->Data->GetData(DataFormats::Text)->ToString(), this->richTextBox5, this->richTextBox6, this->fileNameBox3);
			this->checkBox5->Checked = true;  this->checkBox6->Checked = true;
		}
		else if (e->Data->GetDataPresent(DataFormats::FileDrop))
		{
			System::Object^ object = e->Data->GetData(DataFormats::FileDrop, false);
			array<String^>^ s = dynamic_cast<array<String^>^>(object);
			if (s->Length > 0)
			{
				loadFile(s[0], this->richTextBox5, this->richTextBox6, this->fileNameBox3);
				this->checkBox5->Checked = true;  this->checkBox6->Checked = true;
			}
		}
	}

	private: void richTextBox7_DragEnter(System::Object ^  sender,
		System::Windows::Forms::DragEventArgs ^  e)
	{
		if (e->Data->GetDataPresent(DataFormats::FileDrop)) e->Effect = DragDropEffects::All;
		else if (e->Data->GetDataPresent(DataFormats::Text)) e->Effect = DragDropEffects::Copy;
		else e->Effect = DragDropEffects::None;
	}

	private: System::Void richTextBox7_DragDrop(System::Object ^  sender,
		System::Windows::Forms::DragEventArgs ^  e)
	{
		if (e->Data->GetDataPresent(DataFormats::Text))
		{
			loadText(e->Data->GetData(DataFormats::Text)->ToString(), this->richTextBox7, this->richTextBox8, this->fileNameBox4);
			this->checkBox7->Checked = true;  this->checkBox8->Checked = true;
		}
		else if (e->Data->GetDataPresent(DataFormats::FileDrop))
		{
			System::Object^ object = e->Data->GetData(DataFormats::FileDrop, false);
			array<String^>^ s = dynamic_cast<array<String^>^>(object);
			if (s->Length > 0)
			{
				loadFile(s[0], this->richTextBox7, this->richTextBox8, this->fileNameBox4);
				this->checkBox7->Checked = true;  this->checkBox8->Checked = true;
			}
		}
	}

	private: void richTextBox8_DragEnter(System::Object ^  sender,
		System::Windows::Forms::DragEventArgs ^  e)
	{
		if (e->Data->GetDataPresent(DataFormats::FileDrop)) e->Effect = DragDropEffects::All;
		else if (e->Data->GetDataPresent(DataFormats::Text)) e->Effect = DragDropEffects::Copy;
		else e->Effect = DragDropEffects::None;
	}

	private: System::Void richTextBox8_DragDrop(System::Object ^  sender,
		System::Windows::Forms::DragEventArgs ^  e)
	{
		if (e->Data->GetDataPresent(DataFormats::Text))
		{
			loadText(e->Data->GetData(DataFormats::Text)->ToString(), this->richTextBox7, this->richTextBox8, this->fileNameBox4);
			this->checkBox7->Checked = true;  this->checkBox8->Checked = true;
		}
		else if (e->Data->GetDataPresent(DataFormats::FileDrop))
		{
			System::Object^ object = e->Data->GetData(DataFormats::FileDrop, false);
			array<String^>^ s = dynamic_cast<array<String^>^>(object);
			if (s->Length > 0)
			{
				loadFile(s[0], this->richTextBox7, this->richTextBox8, this->fileNameBox4);
				this->checkBox7->Checked = true;  this->checkBox8->Checked = true;
			}
		}
	}

    private: void richTextBox11_DragEnter(System::Object ^  sender,
        System::Windows::Forms::DragEventArgs ^  e)
    {
        if (e->Data->GetDataPresent(DataFormats::FileDrop)) e->Effect = DragDropEffects::All;
		else if (e->Data->GetDataPresent(DataFormats::Text)) e->Effect = DragDropEffects::Copy;
        else e->Effect = DragDropEffects::None;
    }

    private: System::Void richTextBox11_DragDrop(System::Object ^  sender,
        System::Windows::Forms::DragEventArgs ^  e)
    {
		if (e->Data->GetDataPresent(DataFormats::Text))
		{
			loadText(e->Data->GetData(DataFormats::Text)->ToString(), this->richTextBox11, this->richTextBox12, this->fileNameBox5);
			this->checkBox11->Checked = true;  this->checkBox12->Checked = true;
		}
		else if (e->Data->GetDataPresent(DataFormats::FileDrop))
		{
			System::Object^ object = e->Data->GetData(DataFormats::FileDrop, false);
			array<String^>^ s = dynamic_cast<array<String^>^>(object);
			if (s->Length > 0)
			{
				loadFile(s[0], this->richTextBox11, this->richTextBox12, this->fileNameBox5);
				this->checkBox11->Checked = true;  this->checkBox12->Checked = true;
			}
		}
    }

    private: void richTextBox12_DragEnter(System::Object ^  sender,
        System::Windows::Forms::DragEventArgs ^  e)
    {
        if (e->Data->GetDataPresent(DataFormats::FileDrop)) e->Effect = DragDropEffects::All;
		else if (e->Data->GetDataPresent(DataFormats::Text)) e->Effect = DragDropEffects::Copy;
        else e->Effect = DragDropEffects::None;
    }

    private: System::Void richTextBox12_DragDrop(System::Object ^  sender,
        System::Windows::Forms::DragEventArgs ^  e)
    {
		if (e->Data->GetDataPresent(DataFormats::Text))
		{
			loadText(e->Data->GetData(DataFormats::Text)->ToString(), this->richTextBox11, this->richTextBox12, this->fileNameBox5);
			this->checkBox11->Checked = true;  this->checkBox12->Checked = true;
		}
		else if (e->Data->GetDataPresent(DataFormats::FileDrop))
		{
			System::Object^ object = e->Data->GetData(DataFormats::FileDrop, false);
			array<String^>^ s = dynamic_cast<array<String^>^>(object);
			if (s->Length > 0)
			{
				loadFile(s[0], this->richTextBox11, this->richTextBox12, this->fileNameBox5);
				this->checkBox11->Checked = true;  this->checkBox12->Checked = true;
			}
		}
    }

	private: void compare(int index, System::Windows::Forms::RichTextBox^ box1, array<System::Windows::Forms::RichTextBox^>^ boxes, 
		                  System::Windows::Forms::RichTextBox^ qbox1, array<System::Windows::Forms::RichTextBox^>^ quantities,
						  System::Windows::Forms::Label^ slabel, System::Windows::Forms::Label^ qlabel)
	{
        String^ obsoletePartsFile = gcnew String(vendorObsoleteFiles[comboBox2->SelectedIndex].c_str());
        loadObsoleteParts(obsoletePartsFile); 

        fileOutput.push_back(columnNames[index]);

		int numMismatches = 0;
		std::vector<bool> mismatches;
		std::vector<bool> qmismatches(box1->Lines->Length, false);
		for (int i = 0; i < box1->Lines->Length; i++)
		{
			System::String^ s1 = box1->Lines[i]->ToString();

            for (int j = 0; j < obsoleteParts.size(); j++)
            {
                String^ part = gcnew String(obsoleteParts[j].c_str());
                if (s1 == part)
                {
                    std::string message = obsoleteParts[j] + " is obsolete";
                    fileOutput.push_back(message);
                    break;
                }
            }

			int found = 0;
			int valids = 0;
			for (int b = 0; b < boxes->Length; b++)
			{
				if ((boxes[b] != nullptr) && (boxes[b] != box1))
				{
					valids++;
                    bool curMatch = false;
					for (int j = 0; j < boxes[b]->Lines->Length; j++)
					{
						System::String^ s2 = boxes[b]->Lines[j]->ToString();
						if (s1 == s2) 
						{ 
							found++;
                            curMatch = true;
							if ((qbox1 != nullptr) && (quantities[b] != nullptr))
							{
								System::String^ q1 = qbox1->Lines[i]->ToString();
								System::String^ q2 = quantities[b]->Lines[j]->ToString();
								std::string qs1 = msclr::interop::marshal_as<std::string>(q1);
								std::string qs2 = msclr::interop::marshal_as<std::string>(q2);
                                if (atoi(qs1.c_str()) != atoi(qs2.c_str()))
                                {
                                    std::string message = msclr::interop::marshal_as<std::string>(s1) + " quantity does not match " + columnNames[b] +  " (" + qs1 + ", " + qs2 + ")";
                                    fileOutput.push_back(message);
                                    qmismatches[i] = true;
                                }
							}
							break; 
						}
					}
                    if (!curMatch)
                    {
                        std::string message = msclr::interop::marshal_as<std::string>(s1) + " not found in " + columnNames[b];
                        fileOutput.push_back(message);
                    }
				}
			}
			mismatches.push_back(found != valids);
			if (found != valids) numMismatches++;
		}
		
		std::vector<std::string> ids;
		for (int i = 0; i < box1->Lines->Length; i++)
			ids.push_back(msclr::interop::marshal_as<std::string>(box1->Lines[i]->ToString()));
		box1->Clear();

		for (int i = 0; i < ids.size(); i++)
		{
			String^ addLine = gcnew String(ids[i].c_str());
			String^ newLine = gcnew String("\n");
			if (!mismatches[i]) box1->SelectionFont = gcnew System::Drawing::Font("Microsoft Sans Sarif", 8.25, FontStyle::Regular);
			else box1->SelectionFont = gcnew System::Drawing::Font("Microsoft Sans Sarif", 8.25, FontStyle::Bold);
			box1->AppendText(addLine);
			if (i < ids.size() - 1) box1->AppendText(newLine);
		}

		std::string labelText = "Mismatches: " + std::to_string(numMismatches);
		slabel->Text = gcnew String(labelText.c_str());

        std::vector<std::string> qnts;
		for (int i = 0; i < qbox1->Lines->Length; i++)
			qnts.push_back(msclr::interop::marshal_as<std::string>(qbox1->Lines[i]->ToString()));
		qbox1->Clear();

		for (int i = 0; i < qnts.size(); i++)
		{
			String^ addLine = gcnew String(qnts[i].c_str());
			String^ newLine = gcnew String("\n");
			if (!qmismatches[i]) qbox1->SelectionFont = gcnew System::Drawing::Font("Microsoft Sans Sarif", 8.25, FontStyle::Regular);
			else qbox1->SelectionFont = gcnew System::Drawing::Font("Microsoft Sans Sarif", 8.25, FontStyle::Bold);
			qbox1->AppendText(addLine);
			if (i < qnts.size() - 1) qbox1->AppendText(newLine);
		}

        int numQMismatches = 0;
        for (int i = 0; i< qmismatches.size(); i++)
            if (qmismatches[i]) numQMismatches++;
		labelText = "Mismatches: " + std::to_string(numQMismatches);
		qlabel->Text = gcnew String(labelText.c_str());

        fileOutput.push_back("\n");
	}
	private: System::Void compareButton_Click(System::Object^  sender, System::EventArgs^  e) {
        fileOutput.clear();

		array<System::Windows::Forms::RichTextBox^>^ compareBoxes = gcnew array<System::Windows::Forms::RichTextBox^>(6);
		if ((this->checkBox1->Checked) && (this->richTextBox1->Lines->Length > 0)) compareBoxes[0] = this->richTextBox1; else compareBoxes[0] = nullptr;
		if ((this->checkBox3->Checked) && (this->richTextBox3->Lines->Length > 0)) compareBoxes[1] = this->richTextBox3; else compareBoxes[1] = nullptr;
		if ((this->checkBox5->Checked) && (this->richTextBox5->Lines->Length > 0)) compareBoxes[2] = this->richTextBox5; else compareBoxes[2] = nullptr;
		if ((this->checkBox7->Checked) && (this->richTextBox7->Lines->Length > 0)) compareBoxes[3] = this->richTextBox7; else compareBoxes[3] = nullptr;
		if ((this->checkBox9->Checked) && (this->richTextBox9->Lines->Length > 0)) compareBoxes[4] = this->richTextBox9; else compareBoxes[4] = nullptr;
        if ((this->checkBox11->Checked) && (this->richTextBox11->Lines->Length > 0)) compareBoxes[5] = this->richTextBox11; else compareBoxes[5] = nullptr;

		array<System::Windows::Forms::RichTextBox^>^ compareQuantities = gcnew array<System::Windows::Forms::RichTextBox^>(6);
		if ((this->checkBox2->Checked) && (this->richTextBox2->Lines->Length > 0)) compareQuantities[0] = this->richTextBox2; else compareQuantities[0] = nullptr;
		if ((this->checkBox4->Checked) && (this->richTextBox4->Lines->Length > 0)) compareQuantities[1] = this->richTextBox4; else compareQuantities[1] = nullptr;
		if ((this->checkBox6->Checked) && (this->richTextBox6->Lines->Length > 0)) compareQuantities[2] = this->richTextBox6; else compareQuantities[2] = nullptr;
		if ((this->checkBox8->Checked) && (this->richTextBox8->Lines->Length > 0)) compareQuantities[3] = this->richTextBox8; else compareQuantities[3] = nullptr;
		if ((this->checkBox10->Checked) && (this->richTextBox10->Lines->Length > 0)) compareQuantities[4] = this->richTextBox10; else compareQuantities[4] = nullptr;
        if ((this->checkBox12->Checked) && (this->richTextBox12->Lines->Length > 0)) compareQuantities[5] = this->richTextBox12; else compareQuantities[5] = nullptr;

		if ((this->checkBox1->Checked) && (this->richTextBox1->Lines->Length > 0)) compare(0, this->richTextBox1, compareBoxes, this->checkBox2->Checked ? this->richTextBox2 : nullptr, compareQuantities, this->label1, this->label2);
		if ((this->checkBox3->Checked) && (this->richTextBox3->Lines->Length > 0)) compare(1, this->richTextBox3, compareBoxes, this->checkBox4->Checked ? this->richTextBox4 : nullptr, compareQuantities, this->label3, this->label4);
		if ((this->checkBox5->Checked) && (this->richTextBox5->Lines->Length > 0)) compare(2, this->richTextBox5, compareBoxes, this->checkBox6->Checked ? this->richTextBox6 : nullptr, compareQuantities, this->label5, this->label6);
		if ((this->checkBox7->Checked) && (this->richTextBox7->Lines->Length > 0)) compare(3, this->richTextBox7, compareBoxes, this->checkBox8->Checked ? this->richTextBox8 : nullptr, compareQuantities, this->label7, this->label8);
		//if ((this->checkBox9->Checked) && (this->richTextBox9->Lines->Length > 0)) compare(4, this->richTextBox9, compareBoxes, this->checkBox10->Checked ? this->richTextBox10 : nullptr, compareQuantities, this->label9, this->label10);
        if ((this->checkBox11->Checked) && (this->richTextBox11->Lines->Length > 0)) compare(5, this->richTextBox11, compareBoxes, this->checkBox12->Checked ? this->richTextBox12 : nullptr, compareQuantities, this->label18, this->label19);
	}

	private: System::Void clearButton1_Click(System::Object^  sender, System::EventArgs^  e) {
		this->richTextBox1->Clear();
		this->richTextBox2->Clear();
		this->checkBox1->Checked = false;
		this->checkBox2->Checked = false;
		std::string labelText = "Mismatches: ";
		this->label1->Text = gcnew String(labelText.c_str());
		this->label2->Text = gcnew String(labelText.c_str());
	}
	private: System::Void clearButton2_Click(System::Object^  sender, System::EventArgs^  e) {
		this->richTextBox3->Clear();
		this->richTextBox4->Clear();
		this->checkBox3->Checked = false;
		this->checkBox4->Checked = false;
		std::string labelText = "Mismatches: ";
		this->label3->Text = gcnew String(labelText.c_str());
		this->label4->Text = gcnew String(labelText.c_str());
	}
	private: System::Void clearButton3_Click(System::Object^  sender, System::EventArgs^  e) {
		this->richTextBox5->Clear();
		this->richTextBox6->Clear();
		this->checkBox5->Checked = false;
		this->checkBox6->Checked = false;
		std::string labelText = "Mismatches: ";
		this->label5->Text = gcnew String(labelText.c_str());
		this->label6->Text = gcnew String(labelText.c_str());
	}
	private: System::Void clearButton4_Click(System::Object^  sender, System::EventArgs^  e) {
		this->richTextBox7->Clear();
		this->richTextBox8->Clear();
		this->checkBox7->Checked = false;
		this->checkBox8->Checked = false;
		std::string labelText = "Mismatches: ";
		this->label7->Text = gcnew String(labelText.c_str());
		this->label8->Text = gcnew String(labelText.c_str());
	}
    private: System::Void clearButton5_Click(System::Object^  sender, System::EventArgs^  e) {
        this->richTextBox11->Clear();
        this->richTextBox12->Clear();
		this->checkBox11->Checked = false;
		this->checkBox12->Checked = false;
        std::string labelText = "Mismatches: ";
        this->label18->Text = gcnew String(labelText.c_str());
        this->label19->Text = gcnew String(labelText.c_str());
    }
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
	{
		String^ catalogFileName = gcnew String(catalogFiles[this->comboBox1->SelectedIndex].c_str());
		loadFile(catalogFileName, this->richTextBox9, this->richTextBox10, nullptr);
        this->checkBox9->Checked = true;  this->checkBox10->Checked = true;
	}
	private: System::Void comboBox2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
	{
	}
	private: System::Void approvalButton_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			std::string fileName = msclr::interop::marshal_as<std::string>(saveFileDialog1->FileName);
			std::ofstream outfile(fileName.c_str());
			
			//for (int i = 0; i < this->richTextBox1->Lines->Length; i++)
            for (int i = 0; i < fileOutput.size(); i++)
			{
                std::string s = fileOutput[i]; // msclr::interop::marshal_as<std::string>(this->richTextBox1->Lines[i]->ToString());
				outfile << s << std::endl;
			}
			
			outfile.close();
		}
	}
private: System::Void addEditVendorToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
    VendorsForm^ form = gcnew VendorsForm();

    System::Windows::Forms::ComboBox^ VendorSelectionBox = form->getVendorSelectionBox();
    
    VendorSelectionBox->Items->Clear();
    for (unsigned int i=0; i<vendorNames.size(); i++)
    {
        String^ vendorName = gcnew String(vendorNames[i].c_str());
        VendorSelectionBox->Items->Add(vendorName);
    }
    VendorSelectionBox->Items->Add("New Vendor");

    if (vendorNames.size() > 0) VendorSelectionBox->SelectedIndex = 0;

    form->ShowDialog();

    this->comboBox2->Items->Clear();
    for (int i = 0; i < vendorNames.size(); i++)
    {
        String^ vendorName = gcnew String(vendorNames[i].c_str());
        this->comboBox2->Items->Add(vendorName);
    }
    if (this->comboBox2->Items->Count > 0) comboBox2->SelectedIndex = 0;

    std::ofstream outfile("SkuVendorSettings.txt");
    for (int i = 0; i < vendorNames.size(); i++)
    {
        outfile << vendorNames[i] << std::endl;
        outfile << vendorPatterns[i] << std::endl;
        outfile << vendorObsoleteFiles[i] << std::endl;
    }
    outfile.close();
}
private: System::Void catalogFilesToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
    CatalogForm^ form = gcnew CatalogForm();

    form->ShowDialog();

    this->comboBox1->Items->Clear();
    for (int i = 0; i < catalogFiles.size(); i++)
    {
        String^ catalogFileName = gcnew String(catalogFiles[i].c_str());
        this->comboBox1->Items->Add(catalogFileName);
    }
    if (this->comboBox1->Items->Count > 0) this->comboBox1->SelectedIndex = 0;

    std::ofstream outfile("SkuCatalogSettings.txt");
    for (int i = 0; i < catalogFiles.size(); i++)
        outfile << catalogFiles[i] << std::endl;
    outfile.close();
}

private: System::Void quitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
    Application::Exit();
}
private: System::Void richTextBox1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	if (e->Button == System::Windows::Forms::MouseButtons::Left)
	{
		if (Clipboard::GetData(DataFormats::Text))
		{
			loadText(Clipboard::GetData(DataFormats::Text)->ToString(), this->richTextBox1, this->richTextBox2, this->fileNameBox1);
			this->checkBox1->Checked = true;  this->checkBox2->Checked = true;
		}
	}
}
private: System::Void MainForm_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

}
private: System::Void richTextBox2_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	if (e->Button == System::Windows::Forms::MouseButtons::Left)
	{
		if (Clipboard::GetData(DataFormats::Text))
		{
			loadText(Clipboard::GetData(DataFormats::Text)->ToString(), this->richTextBox1, this->richTextBox2, this->fileNameBox1);
			this->checkBox1->Checked = true;  this->checkBox2->Checked = true;
		}
	}
}
private: System::Void richTextBox3_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	if (e->Button == System::Windows::Forms::MouseButtons::Left)
	{
		if (Clipboard::GetData(DataFormats::Text))
		{
			loadText(Clipboard::GetData(DataFormats::Text)->ToString(), this->richTextBox3, this->richTextBox4, this->fileNameBox2);
			this->checkBox3->Checked = true;  this->checkBox4->Checked = true;
		}
	}
}
private: System::Void richTextBox4_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	if (e->Button == System::Windows::Forms::MouseButtons::Left)
	{
		if (Clipboard::GetData(DataFormats::Text))
		{
			loadText(Clipboard::GetData(DataFormats::Text)->ToString(), this->richTextBox3, this->richTextBox4, this->fileNameBox2);
			this->checkBox3->Checked = true;  this->checkBox4->Checked = true;
		}
	}
}
private: System::Void richTextBox5_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	if (e->Button == System::Windows::Forms::MouseButtons::Left)
	{
		if (Clipboard::GetData(DataFormats::Text))
		{
			loadText(Clipboard::GetData(DataFormats::Text)->ToString(), this->richTextBox5, this->richTextBox6, this->fileNameBox3);
			this->checkBox5->Checked = true;  this->checkBox6->Checked = true;
		}
	}
}
private: System::Void richTextBox6_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	if (e->Button == System::Windows::Forms::MouseButtons::Left)
	{
		if (Clipboard::GetData(DataFormats::Text))
		{
			loadText(Clipboard::GetData(DataFormats::Text)->ToString(), this->richTextBox5, this->richTextBox6, this->fileNameBox3);
			this->checkBox5->Checked = true;  this->checkBox6->Checked = true;
		}
	}
}
private: System::Void richTextBox7_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	if (e->Button == System::Windows::Forms::MouseButtons::Left)
	{
		if (Clipboard::GetData(DataFormats::Text))
		{
			loadText(Clipboard::GetData(DataFormats::Text)->ToString(), this->richTextBox7, this->richTextBox8, this->fileNameBox4);
			this->checkBox7->Checked = true;  this->checkBox8->Checked = true;
		}
	}
}
private: System::Void richTextBox8_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	if (e->Button == System::Windows::Forms::MouseButtons::Left)
	{
		if (Clipboard::GetData(DataFormats::Text))
		{
			loadText(Clipboard::GetData(DataFormats::Text)->ToString(), this->richTextBox7, this->richTextBox8, this->fileNameBox4);
			this->checkBox7->Checked = true;  this->checkBox8->Checked = true;
		}
	}
}
private: System::Void richTextBox11_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	if (e->Button == System::Windows::Forms::MouseButtons::Left)
	{
		if (Clipboard::GetData(DataFormats::Text))
		{
			loadText(Clipboard::GetData(DataFormats::Text)->ToString(), this->richTextBox11, this->richTextBox12, this->fileNameBox5);
			this->checkBox11->Checked = true;  this->checkBox12->Checked = true;
		}
	}
}
private: System::Void richTextBox12_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	if (e->Button == System::Windows::Forms::MouseButtons::Left)
	{
		if (Clipboard::GetData(DataFormats::Text))
		{
			loadText(Clipboard::GetData(DataFormats::Text)->ToString(), this->richTextBox11, this->richTextBox12, this->fileNameBox5);
			this->checkBox11->Checked = true;  this->checkBox12->Checked = true;
		}
	}
}
private: System::Void helpToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	HelpForm^ form = gcnew HelpForm();

	form->ShowDialog();

}
};
}

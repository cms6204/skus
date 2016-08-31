#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <msclr\marshal_cppstd.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include <conio.h>
#include <stdlib.h>

namespace Skus {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for CostForm
	/// </summary>
	public ref class CostForm : public System::Windows::Forms::Form
	{
	public:
		CostForm(void)
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
		~CostForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  clearButton1;
	protected:
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::RichTextBox^  richTextBox2;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::Button^  compareButton1;

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
			this->clearButton1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->compareButton1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// clearButton1
			// 
			this->clearButton1->Location = System::Drawing::Point(144, 404);
			this->clearButton1->Name = L"clearButton1";
			this->clearButton1->Size = System::Drawing::Size(70, 23);
			this->clearButton1->TabIndex = 39;
			this->clearButton1->Text = L"Clear";
			this->clearButton1->UseVisualStyleBackColor = true;
			this->clearButton1->Click += gcnew System::EventHandler(this, &CostForm::clearButton1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(181, 282);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(66, 13);
			this->label2->TabIndex = 38;
			this->label2->Text = L"Mismatches:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(81, 282);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(66, 13);
			this->label1->TabIndex = 37;
			this->label1->Text = L"Mismatches:";
			// 
			// richTextBox2
			// 
			this->richTextBox2->AllowDrop = true;
			this->richTextBox2->Location = System::Drawing::Point(184, 40);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->ReadOnly = true;
			this->richTextBox2->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
			this->richTextBox2->Size = System::Drawing::Size(90, 225);
			this->richTextBox2->TabIndex = 36;
			this->richTextBox2->Text = L"";
			this->richTextBox2->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &CostForm::richTextBox2_DragDrop);
			this->richTextBox2->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &CostForm::richTextBox2_DragEnter);
			this->richTextBox2->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &CostForm::richTextBox2_MouseClick);
			// 
			// richTextBox1
			// 
			this->richTextBox1->AllowDrop = true;
			this->richTextBox1->Location = System::Drawing::Point(84, 40);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
			this->richTextBox1->Size = System::Drawing::Size(90, 225);
			this->richTextBox1->TabIndex = 35;
			this->richTextBox1->Text = L"";
			this->richTextBox1->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &CostForm::richTextBox1_DragDrop);
			this->richTextBox1->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &CostForm::richTextBox1_DragEnter);
			this->richTextBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &CostForm::richTextBox1_MouseClick);
			// 
			// compareButton1
			// 
			this->compareButton1->Location = System::Drawing::Point(144, 358);
			this->compareButton1->Name = L"compareButton1";
			this->compareButton1->Size = System::Drawing::Size(70, 23);
			this->compareButton1->TabIndex = 34;
			this->compareButton1->Text = L"Compare";
			this->compareButton1->UseVisualStyleBackColor = true;
			this->compareButton1->Click += gcnew System::EventHandler(this, &CostForm::compareButton1_Click);
			// 
			// CostForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(355, 466);
			this->Controls->Add(this->clearButton1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->compareButton1);
			this->Name = L"CostForm";
			this->Text = L"Compare Prices";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: void loadText(String^ text, System::Windows::Forms::RichTextBox^ box)
	{
			box->Clear();

			std::string stext = msclr::interop::marshal_as<std::string>(text);
			std::stringstream ss(stext.c_str());
			std::string s;

			if (stext.c_str() != NULL)
			{
				while (std::getline(ss, s, '\n'))
				{
					_cprintf("%s\n", s.c_str());
					int nump = 0;  for (unsigned int i = 0; i < s.length(); i++) if (s[i] == ',') nump++;
					std::string nocommas;  nocommas.resize(s.length() - nump);
					int cnt = 0;   for (unsigned int i = 0; i < s.length(); i++) if (s[i] != ',') nocommas[cnt++] = s[i];
					String^ addLine = gcnew String(nocommas.c_str());
					box->AppendText(addLine);
				}

				box->SelectionStart = 0;
				box->ScrollToCaret();
			}
	}

	private: void compare(System::Windows::Forms::RichTextBox^ box1, System::Windows::Forms::RichTextBox^ box2,
			System::Windows::Forms::Label^ slabel)
	{
		int numMismatches = 0;
		std::vector<bool> mismatches;

		std::vector<double> p1, p2;
		std::string vp = "(\\$?)(\\d*\\.?\\d*)(.*)(\\n?\\f?\\r?)";
		//_cprintf("Length: %d\n", box1->Lines->Length);
		for (int i = 0; i < box1->Lines->Length; i++)
		{
			System::String^ s1 = box1->Lines[i]->ToString();
			if (s1->Length == 0) continue;
			std::string ss1 = msclr::interop::marshal_as<std::string>(s1);
			std::regex re(vp);
			std::smatch m;
			std::regex_match(ss1, m, re);
			if (m.begin() != m.end())
			{
				std::string part = *(m.begin() + 2);
				//_cprintf("Part: %s %d %lf\n", part.c_str(), part.length(), atof(part.c_str()));
				p1.push_back(atof(part.c_str()));
				//_cprintf("%f\n", p1[p1.size() - 1]);
			}
		}
		for (int i = 0; i < box2->Lines->Length; i++)
		{
			System::String^ s2 = box2->Lines[i]->ToString();
			if (s2->Length == 0) continue;
			std::string ss2 = msclr::interop::marshal_as<std::string>(s2);
			std::regex re(vp);
			std::smatch m;
			std::regex_match(ss2, m, re);
			if (m.begin() != m.end())
			{
				std::string part = *(m.begin() + 2);
				p2.push_back(atof(part.c_str()));
			}
		}
		std::sort(p1.begin(), p1.end());
		std::sort(p2.begin(), p2.end());

		for (int i = 0; i < p1.size(); i++)
		{
			bool matching = false;
			for (int j = 0; j < p2.size(); j++)
			{
				if (p1[i] == p2[j]) matching = true;
			}
			mismatches.push_back(!matching);
			if (!matching) numMismatches++;
			/*if (p2.size() < i)
			{
				mismatches.push_back(true);
				numMismatches++;
			}
			else
			{
				bool matching = (p1[i] == p2[i]);
				//_cprintf("Matching: %d %f %f\n", matching, p1[i], p2[i]);
				mismatches.push_back(!matching);
				if (!matching) numMismatches++;
			}*/
		}
			
		std::vector<std::string> ids;
		for (int i = 0; i < p1.size(); i++)
			ids.push_back(std::to_string(p1[i]));	
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
	}

	private: void richTextBox1_DragEnter(System::Object ^  sender,
		System::Windows::Forms::DragEventArgs ^  e)
	{
		if (e->Data->GetDataPresent(DataFormats::Text)) e->Effect = DragDropEffects::Copy;
		else e->Effect = DragDropEffects::None;
	}

	private: System::Void richTextBox1_DragDrop(System::Object ^  sender, 
		System::Windows::Forms::DragEventArgs ^  e)
	{
		if (e->Data->GetDataPresent(DataFormats::Text))
		{
			loadText(e->Data->GetData(DataFormats::Text)->ToString(), this->richTextBox1);
		}	
	}

	private: void richTextBox2_DragEnter(System::Object ^  sender,
		System::Windows::Forms::DragEventArgs ^  e)
	{
		if (e->Data->GetDataPresent(DataFormats::Text)) e->Effect = DragDropEffects::Copy;
		else e->Effect = DragDropEffects::None;
	}

	private: System::Void richTextBox2_DragDrop(System::Object ^  sender,
		System::Windows::Forms::DragEventArgs ^  e)
	{
		if (e->Data->GetDataPresent(DataFormats::Text))
		{
			loadText(e->Data->GetData(DataFormats::Text)->ToString(), this->richTextBox2);
		}
	}

	private: System::Void richTextBox1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		if (e->Button == System::Windows::Forms::MouseButtons::Left)
		{
			if (Clipboard::GetData(DataFormats::Text))
			{
				loadText(Clipboard::GetData(DataFormats::Text)->ToString(), this->richTextBox1);
			}
		}
	}
private: System::Void richTextBox2_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	if (e->Button == System::Windows::Forms::MouseButtons::Left)
	{
		if (Clipboard::GetData(DataFormats::Text))
		{
			loadText(Clipboard::GetData(DataFormats::Text)->ToString(), this->richTextBox2);
		}
	}
}
private: System::Void compareButton1_Click(System::Object^  sender, System::EventArgs^  e) {
	compare(this->richTextBox1, this->richTextBox2, this->label1);
	compare(this->richTextBox2, this->richTextBox1, this->label2);
}
private: System::Void clearButton1_Click(System::Object^  sender, System::EventArgs^  e) {
	this->richTextBox1->Clear();
	this->richTextBox2->Clear();
	std::string labelText = "Mismatches: ";
	this->label1->Text = gcnew String(labelText.c_str());
	this->label2->Text = gcnew String(labelText.c_str());
}
};
}

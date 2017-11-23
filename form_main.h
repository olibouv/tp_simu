#pragma once
#include <msclr\marshal_cppstd.h>

#include <sstream>
#include "Header.h"

namespace ConsoleApplication1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace msclr::interop;

	/// <summary>
	/// Description résumée de form_main
	/// </summary>
	public ref class form_main : public System::Windows::Forms::Form
	{
	public:
		form_main(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~form_main()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected:
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart2;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  textBox5;











	protected:

	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea5 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend5 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series5 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea6 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend6 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series6 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->chart2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(215, 254);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(120, 52);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Simuler";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &form_main::button1_Click_1);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(210, 11);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(125, 20);
			this->textBox1->TabIndex = 2;
			this->textBox1->Text = L"1000";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &form_main::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(210, 52);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(125, 20);
			this->textBox2->TabIndex = 3;
			this->textBox2->Text = L"10";
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &form_main::textBox2_TextChanged);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(210, 99);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(125, 20);
			this->textBox3->TabIndex = 4;
			this->textBox3->Text = L"1";
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &form_main::textBox3_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(35, 18);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(111, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Durée de la simulation";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(35, 59);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(122, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Durée entre deux clients";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(35, 106);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(154, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Durée de traitement Machine A";
			// 
			// chart1
			// 
			chartArea5->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea5);
			legend5->Name = L"Legend1";
			this->chart1->Legends->Add(legend5);
			this->chart1->Location = System::Drawing::Point(12, 326);
			this->chart1->Name = L"chart1";
			series5->ChartArea = L"ChartArea1";
			series5->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
			series5->Legend = L"Legend1";
			series5->Name = L"Series1";
			this->chart1->Series->Add(series5);
			this->chart1->Size = System::Drawing::Size(377, 365);
			this->chart1->TabIndex = 8;
			this->chart1->Text = L"chart1";
			this->chart1->Click += gcnew System::EventHandler(this, &form_main::chart1_Click);
			// 
			// chart2
			// 
			chartArea6->Name = L"ChartArea1";
			this->chart2->ChartAreas->Add(chartArea6);
			legend6->Name = L"Legend1";
			this->chart2->Legends->Add(legend6);
			this->chart2->Location = System::Drawing::Point(421, 326);
			this->chart2->Name = L"chart2";
			series6->ChartArea = L"ChartArea1";
			series6->Legend = L"Legend1";
			series6->Name = L"Series1";
			this->chart2->Series->Add(series6);
			this->chart2->Size = System::Drawing::Size(419, 341);
			this->chart2->TabIndex = 9;
			this->chart2->Text = L"chart2";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(776, 694);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(76, 60);
			this->button2->TabIndex = 10;
			this->button2->Text = L"Quitter";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &form_main::button2_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(463, 11);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(377, 295);
			this->richTextBox1->TabIndex = 11;
			this->richTextBox1->Text = L"";
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &form_main::richTextBox1_TextChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(35, 152);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(154, 13);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Durée de traitement Machine B";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(210, 149);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(125, 20);
			this->textBox4->TabIndex = 13;
			this->textBox4->Text = L"0.8";
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &form_main::textBox4_TextChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(35, 198);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(154, 13);
			this->label5->TabIndex = 14;
			this->label5->Text = L"Durée de traitement Machine C";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(210, 198);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(125, 20);
			this->textBox5->TabIndex = 15;
			this->textBox5->Text = L"0.6";
			this->textBox5->TextChanged += gcnew System::EventHandler(this, &form_main::textBox5_TextChanged);
			// 
			// form_main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(864, 766);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->chart2);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"form_main";
			this->Text = L"form_main";
			this->Load += gcnew System::EventHandler(this, &form_main::form_main_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void form_main_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	



	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {


		System::String^ contenu = "essai";

		msclr::interop::marshal_context context;
		std::string standardString = context.marshal_as<std::string>(contenu);


		System::String^ contenu_zone1 = textBox1->Text;
		System::String^ contenu_zone2 = textBox1->Text;
		System::String^ contenu_zone3 = textBox1->Text;

		textBox1->Text = contenu_zone1;
		textBox2->Text = contenu_zone2;
		textBox3->Text = contenu_zone3;


	}

private: System::Void chart1_Click(System::Object^  sender, System::EventArgs^  e) {

}
private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {
	System::String^ contenu_zone1 = textBox1->Text;
	textBox1->Text = contenu_zone1;
	msclr::interop::marshal_context context;
	std::string contenu_zone1_std = context.marshal_as<std::string>(contenu_zone1);

	System::String^ contenu_zone2 = textBox2->Text;
	textBox2->Text = contenu_zone2;
	std::string contenu_zone2_std = context.marshal_as<std::string>(contenu_zone2);

	System::String^ contenu_zone3 = textBox3->Text;
	textBox3->Text = contenu_zone3;
	std::string contenu_zone3_std = context.marshal_as<std::string>(contenu_zone3);

	System::String^ contenu_zone4 = textBox4->Text;
	textBox4->Text = contenu_zone4;
	std::string contenu_zone4_std = context.marshal_as<std::string>(contenu_zone4);

	System::String^ contenu_zone5 = textBox5->Text;
	textBox5->Text = contenu_zone5;
	std::string contenu_zone5_std = context.marshal_as<std::string>(contenu_zone5);


	int Date_fin;
	int Duree_Int;
	int Duree_TraitementA;
	int Duree_TraitementB;
	int Duree_TraitementC;

	std::istringstream(contenu_zone1_std) >> Date_fin;
	std::istringstream(contenu_zone2_std) >> Duree_Int;
	std::istringstream(contenu_zone3_std) >> Duree_TraitementA;
	std::istringstream(contenu_zone4_std) >> Duree_TraitementB;
	std::istringstream(contenu_zone5_std) >> Duree_TraitementC;

	simuler(Date_fin, Duree_Int, Duree_TraitementA, Duree_TraitementB, Duree_TraitementC, richTextBox1);
	
	chart1->Series[0]->Points->AddXY(100, 100);
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	Application::Exit();
}
private: System::Void richTextBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox3_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox4_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox5_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
};
}

#pragma once
#include<string>
#include <sstream>
#include <fstream>
#include "List.h";
#include <stdlib.h>
#include <chrono>
#define NOMBRE_ARCHIVO "vacio.csv"

namespace LAB6CESARMEJIA1127922 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Media;
	using namespace std;
	using namespace std::chrono;
	LIST pokedex;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^ pokedex_no_ordenada;
	private: System::Windows::Forms::Button^ btn_ordenar;
	private: System::Windows::Forms::ListBox^ pokedex_ordenada;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ lbl_tiempo;
	protected:

	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pokedex_no_ordenada = (gcnew System::Windows::Forms::ListBox());
			this->btn_ordenar = (gcnew System::Windows::Forms::Button());
			this->pokedex_ordenada = (gcnew System::Windows::Forms::ListBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->lbl_tiempo = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// pokedex_no_ordenada
			// 
			this->pokedex_no_ordenada->FormattingEnabled = true;
			this->pokedex_no_ordenada->ItemHeight = 16;
			this->pokedex_no_ordenada->Location = System::Drawing::Point(42, 31);
			this->pokedex_no_ordenada->Name = L"pokedex_no_ordenada";
			this->pokedex_no_ordenada->Size = System::Drawing::Size(252, 612);
			this->pokedex_no_ordenada->TabIndex = 0;
			this->pokedex_no_ordenada->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listBox1_SelectedIndexChanged);
			// 
			// btn_ordenar
			// 
			this->btn_ordenar->Location = System::Drawing::Point(300, 31);
			this->btn_ordenar->Name = L"btn_ordenar";
			this->btn_ordenar->Size = System::Drawing::Size(137, 75);
			this->btn_ordenar->TabIndex = 1;
			this->btn_ordenar->Text = L"Ordenar por National Number";
			this->btn_ordenar->UseVisualStyleBackColor = true;
			this->btn_ordenar->Click += gcnew System::EventHandler(this, &MyForm::btn_ordenar_Click);
			// 
			// pokedex_ordenada
			// 
			this->pokedex_ordenada->FormattingEnabled = true;
			this->pokedex_ordenada->ItemHeight = 16;
			this->pokedex_ordenada->Location = System::Drawing::Point(443, 31);
			this->pokedex_ordenada->Name = L"pokedex_ordenada";
			this->pokedex_ordenada->Size = System::Drawing::Size(252, 612);
			this->pokedex_ordenada->TabIndex = 2;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(300, 112);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(137, 75);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Ordenar por Generacion";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// lbl_tiempo
			// 
			this->lbl_tiempo->AutoSize = true;
			this->lbl_tiempo->Location = System::Drawing::Point(300, 190);
			this->lbl_tiempo->Name = L"lbl_tiempo";
			this->lbl_tiempo->Size = System::Drawing::Size(0, 16);
			this->lbl_tiempo->TabIndex = 4;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(744, 686);
			this->Controls->Add(this->lbl_tiempo);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pokedex_ordenada);
			this->Controls->Add(this->btn_ordenar);
			this->Controls->Add(this->pokedex_no_ordenada);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Pokedex";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		ifstream archivo(NOMBRE_ARCHIVO);
		string linea;
		char delimitador = ',';
		getline(archivo, linea);
		while (getline(archivo,linea))
		{
			stringstream stream(linea);
			string nn,n,g;
			getline(stream, nn, delimitador);
			getline(stream, n, delimitador);
			getline(stream, g, delimitador);

			int nnn=std::stoi(nn);
			int gg = std::stoi(g);
			pokedex.Add(nnn, n, gg);
		}
		for (int i = 0; i < pokedex.Count(); i++)
		{
			pokedex_no_ordenada->Items->Add(gcnew String(pokedex.getPokemon(pokedex.Count()-i-1).c_str()));
		}
	}		 
	private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btn_ordenar_Click(System::Object^ sender, System::EventArgs^ e) {
		auto start = high_resolution_clock::now();
		pokedex_ordenada->Items->Clear();
		pokedex.Shell_sort_Nacional(pokedex.Count());
		for (int i = 0; i < pokedex.Count(); i++)
		{
			pokedex_ordenada->Items->Add(gcnew String(pokedex.getPokemon(pokedex.Count() - i - 1).c_str()));
		}
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);
		string str = to_string(duration.count() / 1000);
		lbl_tiempo->Text = "Ha demorado: \n" + gcnew String(str.c_str()) + "ms";
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	auto start = high_resolution_clock::now();
	pokedex_ordenada->Items->Clear();
	pokedex.Shell_sort_Generacion(pokedex.Count());
	for (int i = 0; i < pokedex.Count(); i++)
	{
		pokedex_ordenada->Items->Add(gcnew String(pokedex.getPokemon(pokedex.Count() - i - 1).c_str()));
	}
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	string str = to_string(duration.count()/1000);
	lbl_tiempo->Text = "Ha demorado: \n" + gcnew String(str.c_str())+"ms";
}
};
}

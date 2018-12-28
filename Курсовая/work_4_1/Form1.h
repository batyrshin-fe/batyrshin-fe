#pragma once


namespace work_4_1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	

	/// <summary>
	/// Сводка для Form1
	///
	/// Внимание! При изменении имени этого класса необходимо также изменить
	///          свойство имени файла ресурсов ("Resource File Name") для средства компиляции управляемого ресурса,
	///          связанного со всеми файлами с расширением .resx, от которых зависит данный класс. В противном случае,
	///          конструкторы не смогут правильно работать с локализованными
	///          ресурсами, сопоставленными данной форме.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::GroupBox^  groupBox3;

	private: System::Windows::Forms::Button^  butLoad;
	private: System::Windows::Forms::Button^  butClear;	

	private: System::Windows::Forms::Button^  butFDCT;
	private: System::Windows::Forms::Button^  butIDCT;

	private: System::Windows::Forms::PictureBox^  pictureBox1;	
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	
	private: System::Windows::Forms::Button^  butIDCT4;
	private: System::Windows::Forms::Button^  butIDCT3;
	private: System::Windows::Forms::Button^  butIDCT2;
	private: System::Windows::Forms::Button^  butIDCT1;






	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>


		//====     ОПИСАНИЕ ПЕРЕМЕННЫХ ФОРМЫ    =====


		
		int Wpic,Hpic; //ширина и высота рисунка
		int NN; //количество пикселей на рисунке и на гистограмме

		//Массивы для рисунков (по пикселям)
		int *R1,*G1,*B1; //указатели на массивы 
		int *Y1,*Y2,*Y9,*U,*V; //указатели на массивы 
		int *R2,*G2,*B2; //указатели на массивы 
	private: System::Windows::Forms::Button^  buttonSave;
	private: System::Windows::Forms::Button^  buttonAbout;
	



	//private: System::Windows::Forms::Label^  label2;

	

		

		
	

		










			 System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{	
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->buttonSave = (gcnew System::Windows::Forms::Button());
			this->buttonAbout = (gcnew System::Windows::Forms::Button());
			this->butIDCT4 = (gcnew System::Windows::Forms::Button());
			this->butIDCT3 = (gcnew System::Windows::Forms::Button());
			this->butIDCT2 = (gcnew System::Windows::Forms::Button());
			this->butIDCT1 = (gcnew System::Windows::Forms::Button());
			this->butIDCT = (gcnew System::Windows::Forms::Button());
			this->butFDCT = (gcnew System::Windows::Forms::Button());
			this->butClear = (gcnew System::Windows::Forms::Button());
			this->butLoad = (gcnew System::Windows::Forms::Button());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->groupBox1->SuspendLayout();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->buttonSave);
			this->groupBox1->Controls->Add(this->buttonAbout);
			this->groupBox1->Controls->Add(this->butIDCT4);
			this->groupBox1->Controls->Add(this->butIDCT3);
			this->groupBox1->Controls->Add(this->butIDCT2);
			this->groupBox1->Controls->Add(this->butIDCT1);
			this->groupBox1->Controls->Add(this->butIDCT);
			this->groupBox1->Controls->Add(this->butFDCT);
			this->groupBox1->Controls->Add(this->butClear);
			this->groupBox1->Controls->Add(this->butLoad);
			this->groupBox1->Location = System::Drawing::Point(370, 20);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(150, 377);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Управление";
			// 
			// buttonSave
			// 
			this->buttonSave->Location = System::Drawing::Point(12, 337);
			this->buttonSave->Name = L"buttonSave";
			this->buttonSave->Size = System::Drawing::Size(126, 24);
			this->buttonSave->TabIndex = 24;
			this->buttonSave->Text = L"Сохранить результат";
			this->buttonSave->UseVisualStyleBackColor = true;
			this->buttonSave->Click += gcnew System::EventHandler(this, &Form1::buttonSave_Click);
			// 
			// buttonAbout
			// 
			this->buttonAbout->Location = System::Drawing::Point(12, 25);
			this->buttonAbout->Name = L"buttonAbout";
			this->buttonAbout->Size = System::Drawing::Size(126, 24);
			this->buttonAbout->TabIndex = 23;
			this->buttonAbout->Text = L"О программе";
			this->buttonAbout->UseVisualStyleBackColor = true;
			this->buttonAbout->Click += gcnew System::EventHandler(this, &Form1::buttonAbout_Click);
			// 
			// butIDCT4
			// 
			this->butIDCT4->Location = System::Drawing::Point(48, 266);
			this->butIDCT4->Name = L"butIDCT4";
			this->butIDCT4->Size = System::Drawing::Size(60, 24);
			this->butIDCT4->TabIndex = 22;
			this->butIDCT4->Text = L"IDCT4";
			this->butIDCT4->UseVisualStyleBackColor = true;
			this->butIDCT4->Click += gcnew System::EventHandler(this, &Form1::butIDCT4_Click);
			// 
			// butIDCT3
			// 
			this->butIDCT3->Location = System::Drawing::Point(48, 236);
			this->butIDCT3->Name = L"butIDCT3";
			this->butIDCT3->Size = System::Drawing::Size(60, 24);
			this->butIDCT3->TabIndex = 21;
			this->butIDCT3->Text = L"IDCT3";
			this->butIDCT3->UseVisualStyleBackColor = true;
			this->butIDCT3->Click += gcnew System::EventHandler(this, &Form1::butIDCT3_Click);
			// 
			// butIDCT2
			// 
			this->butIDCT2->Location = System::Drawing::Point(48, 206);
			this->butIDCT2->Name = L"butIDCT2";
			this->butIDCT2->Size = System::Drawing::Size(60, 24);
			this->butIDCT2->TabIndex = 20;
			this->butIDCT2->Text = L"IDCT2";
			this->butIDCT2->UseVisualStyleBackColor = true;
			this->butIDCT2->Click += gcnew System::EventHandler(this, &Form1::butIDCT2_Click);
			// 
			// butIDCT1
			// 
			this->butIDCT1->Location = System::Drawing::Point(48, 176);
			this->butIDCT1->Name = L"butIDCT1";
			this->butIDCT1->Size = System::Drawing::Size(60, 24);
			this->butIDCT1->TabIndex = 19;
			this->butIDCT1->Text = L"IDCT1";
			this->butIDCT1->UseVisualStyleBackColor = true;
			this->butIDCT1->Click += gcnew System::EventHandler(this, &Form1::butIDCT1_Click);
			// 
			// butIDCT
			// 
			this->butIDCT->Location = System::Drawing::Point(48, 296);
			this->butIDCT->Name = L"butIDCT";
			this->butIDCT->Size = System::Drawing::Size(60, 24);
			this->butIDCT->TabIndex = 18;
			this->butIDCT->Text = L"IDCT";
			this->butIDCT->UseVisualStyleBackColor = true;
			this->butIDCT->Click += gcnew System::EventHandler(this, &Form1::butIDCT_Click);
			// 
			// butFDCT
			// 
			this->butFDCT->Location = System::Drawing::Point(48, 139);
			this->butFDCT->Name = L"butFDCT";
			this->butFDCT->Size = System::Drawing::Size(60, 24);
			this->butFDCT->TabIndex = 17;
			this->butFDCT->Text = L"FDCT";
			this->butFDCT->UseVisualStyleBackColor = true;
			this->butFDCT->Click += gcnew System::EventHandler(this, &Form1::butFDCT_Click);
			// 
			// butClear
			// 
			this->butClear->Location = System::Drawing::Point(12, 109);
			this->butClear->Name = L"butClear";
			this->butClear->Size = System::Drawing::Size(126, 24);
			this->butClear->TabIndex = 16;
			this->butClear->Text = L"Очистить";
			this->butClear->UseVisualStyleBackColor = true;
			this->butClear->Click += gcnew System::EventHandler(this, &Form1::butClear_Click);
			// 
			// butLoad
			// 
			this->butLoad->Location = System::Drawing::Point(12, 79);
			this->butLoad->Name = L"butLoad";
			this->butLoad->Size = System::Drawing::Size(126, 24);
			this->butLoad->TabIndex = 10;
			this->butLoad->Text = L"Загрузить";
			this->butLoad->UseVisualStyleBackColor = true;
			this->butLoad->Click += gcnew System::EventHandler(this, &Form1::butLoad_Click);
			// 
			// groupBox3
			// 
			this->groupBox3->BackColor = System::Drawing::SystemColors::Control;
			this->groupBox3->Controls->Add(this->pictureBox1);
			this->groupBox3->Location = System::Drawing::Point(12, 20);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(352, 377);
			this->groupBox3->TabIndex = 2;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Исходное изображение";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::Info;
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(6, 25);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(336, 336);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// groupBox2
			// 
			this->groupBox2->BackColor = System::Drawing::SystemColors::Control;
			this->groupBox2->Controls->Add(this->pictureBox2);
			this->groupBox2->Location = System::Drawing::Point(526, 20);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(352, 377);
			this->groupBox2->TabIndex = 3;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Результат";
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::SystemColors::Info;
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox2->Location = System::Drawing::Point(6, 25);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(340, 340);
			this->pictureBox2->TabIndex = 0;
			this->pictureBox2->TabStop = false;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->Title = L"Выберите файл изображения";
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->Filter = L"BMP files|*.bmp|Все файлы|*.*";
			this->saveFileDialog1->Title = L"Сохранение файла изображения";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(889, 427);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox1);
			this->Name = L"Form1";
			this->Text = L"     FDCT и  IDCT  преобразования  ";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->groupBox2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) ;
	private: System::Void butLoad_Click(System::Object^  sender, System::EventArgs^  e) ;
	private: System::Void butClear_Click(System::Object^  sender, System::EventArgs^  e) ;
	private: System::Void ShowResult(void) ;
	private: System::Void PrepareData(void) ;
	private: System::Void FirstYUV(void) ;
	
	private: System::Void butFDCT_Click(System::Object^  sender, System::EventArgs^  e) ;
	private: System::Void butIDCT_Click(System::Object^  sender, System::EventArgs^  e) ;

	private: System::Void butIDCT1_Click(System::Object^  sender, System::EventArgs^  e) ;
	private: System::Void butIDCT2_Click(System::Object^  sender, System::EventArgs^  e) ;
	private: System::Void butIDCT3_Click(System::Object^  sender, System::EventArgs^  e) ;
	private: System::Void butIDCT4_Click(System::Object^  sender, System::EventArgs^  e) ;
	private: System::Void buttonSave_Click(System::Object^  sender, System::EventArgs^  e) ;
	private: System::Void buttonAbout_Click(System::Object^  sender, System::EventArgs^  e) ;

};
}


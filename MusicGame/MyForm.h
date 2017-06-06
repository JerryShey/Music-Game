#pragma once
#include "TestForm.h"
#include "LeaderboardForm.h"

#define not_bad 100
#define good 150
#define perfect 250
#define excellent 300

namespace MusicGame {

	using namespace System;
	using namespace System::IO;
	using namespace System::Diagnostics;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	/// <summary>
	/// MyForm 的摘要
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		array<Int32>^ game_Rhythm0;
		array<Int32>^ game_Rhythm1;
		array<Int32>^ game_Rhythm2;
		array<Int32>^ game_Rhythm3;
		array<Int32>^ label_num;
		array<Int32>^ first_label;
		array<Int32>^ Rhythm_num;
		array<Int32, 2>^ build_time ;
		array<Int32, 2>^ label_len;
		array<Label ^, 2>^ build_label = gcnew array<System::Windows::Forms::Label ^, 2>(4, 600);
		String^ song_name;
		array<Label^>^ act_label = gcnew array<System::Windows::Forms::Label ^>(4);
		array<Label^>^ miss_label = gcnew array<System::Windows::Forms::Label ^>(4);
		array<Int32, 2>^ act_vector = gcnew array<Int32, 2>(4, 2);
		array<Int16>^ act_miss = gcnew array<Int16>(4);
		array<Button^>^ fourBtn = gcnew array<Button^>(4);
		System::Windows::Forms::Timer^ music_play = gcnew System::Windows::Forms::Timer();
		Stopwatch ^ timePerParse;
		array<Int32>^ bye = gcnew array<Int32>(4);
		array<char^>^ key;

		bool teacher = false;
		System::String^ en = "abcdefghijklmnopqrstuvwxyz";
		int end = 0;
		int comboNum = 0;
		unsigned int score = 0;
		int start_cnt = 5;

 	private: System::Windows::Forms::Button^  btn_left;
	private: System::Windows::Forms::Button^  btn_down;
	private: System::Windows::Forms::Button^  btn_up;
	private: System::Windows::Forms::Button^  btn_right;
	private: System::Windows::Forms::Label^  lbl_combo;
	private: System::Windows::Forms::Label^  lbl_perf;
	private: System::Windows::Forms::Label^  lbl_act1;
	private: System::Windows::Forms::Label^  lbl_act2;
	private: System::Windows::Forms::Label^  lbl_act3;
	private: System::Windows::Forms::Label^  lbl_act4;
	private: System::Windows::Forms::Label^  lbl_score;
	private: System::Windows::Forms::Label^  lbl_miss1;
	private: System::Windows::Forms::Label^  lbl_miss2;
	private: System::Windows::Forms::Label^  lbl_miss3;
	private: System::Windows::Forms::Label^  lbl_miss4;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Button^  btn_LB;
	private: System::Windows::Forms::Button^  button3;



			 System::Media::SoundPlayer^ player = gcnew System::Media::SoundPlayer();

			 
	public:
		MyForm(char^ left, char^ down, char^ up, char^ right)
		{

			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
			key = gcnew array<char^> {left, down, up, right};
			this->StartPosition = FormStartPosition::CenterScreen;
			song_name = gcnew String("");
			game_Rhythm0 = gcnew array<Int32>(600);
			game_Rhythm1 = gcnew array<Int32>(600);
			game_Rhythm2 = gcnew array<Int32>(600);
			game_Rhythm3 = gcnew array<Int32>(600);
			label_num = gcnew array<Int32>(4);
			first_label = gcnew array<Int32>{0, 0, 0, 0};
			Rhythm_num = gcnew array<Int32>{0, 0, 0, 0};
			build_time = gcnew array<Int32, 2>(4,500);
			//label_len = gcnew array<Int32, 2>{{1, 1, 1, 1, 1, 1, 1}, { 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1,1 }, { 1, 1, 1, 1 ,1,1}};
			act_vector = gcnew array<Int32, 2>{{ 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }};
			act_miss = gcnew array<Int16>  {0, 0, 0, 0};
			miss_label = gcnew array<System::Windows::Forms::Label ^>{lbl_miss1, lbl_miss2, lbl_miss3, lbl_miss4};
			act_label = gcnew array<System::Windows::Forms::Label ^>{lbl_act1, lbl_act2, lbl_act3, lbl_act4};
			fourBtn = gcnew array<System::Windows::Forms::Button^> {btn_left, btn_down, btn_up, btn_right };
			this->music_play->Enabled = false;
			this->music_play->Interval = 5000;
			this->music_play->Tick += gcnew System::EventHandler(this, &MyForm::music_play_Tick);
			this->KeyPreview = true;
			this->KeyPress +=
				gcnew KeyPressEventHandler(this, &MyForm::MyForm_KeyPress);
			for (int i = 0; i < 4; i++){
				int now = (*key[i]) - 'a';
				fourBtn[i]->Text = en->Substring(now, 1)->ToUpper();
			}
			this->Cursor = gcnew System::Windows::Forms::Cursor(".\\cursor.ico");
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Panel^  panel4;
	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::Timer^  Timer1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Timer^  start_timer;

	private: System::Windows::Forms::ProgressBar^  pBar1;
	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器
		/// 修改這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->btn_left = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->btn_down = (gcnew System::Windows::Forms::Button());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->btn_up = (gcnew System::Windows::Forms::Button());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->btn_right = (gcnew System::Windows::Forms::Button());
			this->Timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->start_timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->pBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->lbl_combo = (gcnew System::Windows::Forms::Label());
			this->lbl_perf = (gcnew System::Windows::Forms::Label());
			this->lbl_act1 = (gcnew System::Windows::Forms::Label());
			this->lbl_act2 = (gcnew System::Windows::Forms::Label());
			this->lbl_act3 = (gcnew System::Windows::Forms::Label());
			this->lbl_act4 = (gcnew System::Windows::Forms::Label());
			this->lbl_score = (gcnew System::Windows::Forms::Label());
			this->lbl_miss1 = (gcnew System::Windows::Forms::Label());
			this->lbl_miss2 = (gcnew System::Windows::Forms::Label());
			this->lbl_miss3 = (gcnew System::Windows::Forms::Label());
			this->lbl_miss4 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->btn_LB = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1->Controls->Add(this->btn_left);
			this->panel1->Location = System::Drawing::Point(22, 38);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(41, 380);
			this->panel1->TabIndex = 0;
			// 
			// btn_left
			// 
			this->btn_left->BackColor = System::Drawing::Color::Blue;
			this->btn_left->Enabled = false;
			this->btn_left->FlatAppearance->BorderSize = 0;
			this->btn_left->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_left->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->btn_left->Location = System::Drawing::Point(-2, 354);
			this->btn_left->Name = L"btn_left";
			this->btn_left->Size = System::Drawing::Size(41, 24);
			this->btn_left->TabIndex = 0;
			this->btn_left->TabStop = false;
			this->btn_left->Text = L"D";
			this->btn_left->UseVisualStyleBackColor = false;
			// 
			// panel2
			// 
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel2->Controls->Add(this->btn_down);
			this->panel2->Location = System::Drawing::Point(92, 38);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(41, 380);
			this->panel2->TabIndex = 0;
			// 
			// btn_down
			// 
			this->btn_down->BackColor = System::Drawing::Color::Blue;
			this->btn_down->Enabled = false;
			this->btn_down->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_down->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->btn_down->Location = System::Drawing::Point(-2, 354);
			this->btn_down->Name = L"btn_down";
			this->btn_down->Size = System::Drawing::Size(41, 24);
			this->btn_down->TabIndex = 0;
			this->btn_down->TabStop = false;
			this->btn_down->Text = L"F";
			this->btn_down->UseVisualStyleBackColor = false;
			// 
			// panel3
			// 
			this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel3->Controls->Add(this->btn_up);
			this->panel3->Location = System::Drawing::Point(162, 38);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(41, 380);
			this->panel3->TabIndex = 1;
			// 
			// btn_up
			// 
			this->btn_up->BackColor = System::Drawing::Color::Blue;
			this->btn_up->Enabled = false;
			this->btn_up->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_up->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->btn_up->Location = System::Drawing::Point(-2, 354);
			this->btn_up->Name = L"btn_up";
			this->btn_up->Size = System::Drawing::Size(41, 24);
			this->btn_up->TabIndex = 0;
			this->btn_up->TabStop = false;
			this->btn_up->Text = L"J";
			this->btn_up->UseVisualStyleBackColor = false;
			// 
			// panel4
			// 
			this->panel4->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel4->Controls->Add(this->btn_right);
			this->panel4->Location = System::Drawing::Point(231, 38);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(41, 380);
			this->panel4->TabIndex = 0;
			// 
			// btn_right
			// 
			this->btn_right->BackColor = System::Drawing::Color::Blue;
			this->btn_right->Enabled = false;
			this->btn_right->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_right->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->btn_right->Location = System::Drawing::Point(-2, 354);
			this->btn_right->Name = L"btn_right";
			this->btn_right->Size = System::Drawing::Size(41, 24);
			this->btn_right->TabIndex = 0;
			this->btn_right->TabStop = false;
			this->btn_right->Text = L"K";
			this->btn_right->UseVisualStyleBackColor = false;
			// 
			// Timer1
			// 
			this->Timer1->Interval = 10;
			this->Timer1->Tick += gcnew System::EventHandler(this, &MyForm::Timer1_Tick);
			// 
			// button1
			// 
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::Yellow;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button1->ForeColor = System::Drawing::Color::Yellow;
			this->button1->Location = System::Drawing::Point(40, 9);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Play";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
			this->button1->MouseEnter += gcnew System::EventHandler(this, &MyForm::btn_enter);
			this->button1->MouseLeave += gcnew System::EventHandler(this, &MyForm::btn_leave);
			// 
			// button2
			// 
			this->button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.BackgroundImage")));
			this->button2->FlatAppearance->BorderColor = System::Drawing::Color::Yellow;
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button2->ForeColor = System::Drawing::Color::Yellow;
			this->button2->Location = System::Drawing::Point(176, 9);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"choose music";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			this->button2->MouseEnter += gcnew System::EventHandler(this, &MyForm::btn_enter);
			this->button2->MouseLeave += gcnew System::EventHandler(this, &MyForm::btn_leave);
			// 
			// start_timer
			// 
			this->start_timer->Interval = 1000;
			this->start_timer->Tick += gcnew System::EventHandler(this, &MyForm::start_tick);
			// 
			// pBar1
			// 
			this->pBar1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->pBar1->Location = System::Drawing::Point(278, 38);
			this->pBar1->Name = L"pBar1";
			this->pBar1->Size = System::Drawing::Size(167, 23);
			this->pBar1->Style = System::Windows::Forms::ProgressBarStyle::Continuous;
			this->pBar1->TabIndex = 0;
			// 
			// lbl_combo
			// 
			this->lbl_combo->AutoSize = true;
			this->lbl_combo->Font = (gcnew System::Drawing::Font(L"Buxton Sketch", 16, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_combo->ForeColor = System::Drawing::Color::Silver;
			this->lbl_combo->Location = System::Drawing::Point(297, 391);
			this->lbl_combo->Name = L"lbl_combo";
			this->lbl_combo->Size = System::Drawing::Size(0, 27);
			this->lbl_combo->TabIndex = 7;
			// 
			// lbl_perf
			// 
			this->lbl_perf->AutoSize = true;
			this->lbl_perf->BackColor = System::Drawing::Color::Black;
			this->lbl_perf->Font = (gcnew System::Drawing::Font(L"Buxton Sketch", 16, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_perf->ForeColor = System::Drawing::Color::Yellow;
			this->lbl_perf->Location = System::Drawing::Point(297, 215);
			this->lbl_perf->Name = L"lbl_perf";
			this->lbl_perf->Size = System::Drawing::Size(0, 27);
			this->lbl_perf->TabIndex = 2;
			// 
			// lbl_act1
			// 
			this->lbl_act1->AutoSize = true;
			this->lbl_act1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->lbl_act1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 5.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->lbl_act1->Location = System::Drawing::Point(300, 202);
			this->lbl_act1->Name = L"lbl_act1";
			this->lbl_act1->Size = System::Drawing::Size(40, 7);
			this->lbl_act1->TabIndex = 0;
			this->lbl_act1->Text = L"                  ";
			this->lbl_act1->Visible = false;
			// 
			// lbl_act2
			// 
			this->lbl_act2->AutoSize = true;
			this->lbl_act2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->lbl_act2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 5.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->lbl_act2->Location = System::Drawing::Point(300, 209);
			this->lbl_act2->Name = L"lbl_act2";
			this->lbl_act2->Size = System::Drawing::Size(40, 7);
			this->lbl_act2->TabIndex = 0;
			this->lbl_act2->Text = L"                  ";
			this->lbl_act2->Visible = false;
			// 
			// lbl_act3
			// 
			this->lbl_act3->AutoSize = true;
			this->lbl_act3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->lbl_act3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 5.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->lbl_act3->Location = System::Drawing::Point(300, 215);
			this->lbl_act3->Name = L"lbl_act3";
			this->lbl_act3->Size = System::Drawing::Size(40, 7);
			this->lbl_act3->TabIndex = 10;
			this->lbl_act3->Text = L"                  ";
			this->lbl_act3->Visible = false;
			// 
			// lbl_act4
			// 
			this->lbl_act4->AutoSize = true;
			this->lbl_act4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->lbl_act4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 5.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->lbl_act4->Location = System::Drawing::Point(300, 222);
			this->lbl_act4->Name = L"lbl_act4";
			this->lbl_act4->Size = System::Drawing::Size(40, 7);
			this->lbl_act4->TabIndex = 0;
			this->lbl_act4->Text = L"                  ";
			this->lbl_act4->Visible = false;
			// 
			// lbl_score
			// 
			this->lbl_score->AutoSize = true;
			this->lbl_score->Font = (gcnew System::Drawing::Font(L"Buxton Sketch", 20.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_score->ForeColor = System::Drawing::Color::Yellow;
			this->lbl_score->Location = System::Drawing::Point(278, 73);
			this->lbl_score->Name = L"lbl_score";
			this->lbl_score->Size = System::Drawing::Size(29, 33);
			this->lbl_score->TabIndex = 0;
			this->lbl_score->Text = L"0";
			// 
			// lbl_miss1
			// 
			this->lbl_miss1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->lbl_miss1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 5.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->lbl_miss1->Location = System::Drawing::Point(364, 202);
			this->lbl_miss1->Name = L"lbl_miss1";
			this->lbl_miss1->Size = System::Drawing::Size(40, 7);
			this->lbl_miss1->TabIndex = 0;
			this->lbl_miss1->Text = L"                  ";
			this->lbl_miss1->Visible = false;
			// 
			// lbl_miss2
			// 
			this->lbl_miss2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->lbl_miss2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 5.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->lbl_miss2->Location = System::Drawing::Point(364, 209);
			this->lbl_miss2->Name = L"lbl_miss2";
			this->lbl_miss2->Size = System::Drawing::Size(40, 7);
			this->lbl_miss2->TabIndex = 14;
			this->lbl_miss2->Text = L"                  ";
			this->lbl_miss2->Visible = false;
			// 
			// lbl_miss3
			// 
			this->lbl_miss3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->lbl_miss3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 5.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->lbl_miss3->Location = System::Drawing::Point(364, 216);
			this->lbl_miss3->Name = L"lbl_miss3";
			this->lbl_miss3->Size = System::Drawing::Size(40, 7);
			this->lbl_miss3->TabIndex = 0;
			this->lbl_miss3->Text = L"                  ";
			this->lbl_miss3->Visible = false;
			// 
			// lbl_miss4
			// 
			this->lbl_miss4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->lbl_miss4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 5.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->lbl_miss4->Location = System::Drawing::Point(364, 223);
			this->lbl_miss4->Name = L"lbl_miss4";
			this->lbl_miss4->Size = System::Drawing::Size(40, 7);
			this->lbl_miss4->TabIndex = 0;
			this->lbl_miss4->Text = L"                  ";
			this->lbl_miss4->Visible = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox1->Location = System::Drawing::Point(321, 273);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(140, 110);
			this->pictureBox1->TabIndex = 17;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			// 
			// btn_LB
			// 
			this->btn_LB->BackColor = System::Drawing::Color::Transparent;
			this->btn_LB->Enabled = false;
			this->btn_LB->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_LB->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_LB->ForeColor = System::Drawing::Color::Silver;
			this->btn_LB->Location = System::Drawing::Point(278, 109);
			this->btn_LB->Name = L"btn_LB";
			this->btn_LB->Size = System::Drawing::Size(72, 29);
			this->btn_LB->TabIndex = 0;
			this->btn_LB->TabStop = false;
			this->btn_LB->Text = L"Board";
			this->btn_LB->UseVisualStyleBackColor = false;
			this->btn_LB->Visible = false;
			this->btn_LB->Click += gcnew System::EventHandler(this, &MyForm::btn_LB_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Black;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Consolas", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::Color::Silver;
			this->button3->Location = System::Drawing::Point(278, 144);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(105, 23);
			this->button3->TabIndex = 18;
			this->button3->Text = L"For teacher";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(463, 418);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->btn_LB);
			this->Controls->Add(this->lbl_miss4);
			this->Controls->Add(this->lbl_miss3);
			this->Controls->Add(this->lbl_miss2);
			this->Controls->Add(this->lbl_miss1);
			this->Controls->Add(this->lbl_score);
			this->Controls->Add(this->lbl_act4);
			this->Controls->Add(this->lbl_act3);
			this->Controls->Add(this->lbl_act2);
			this->Controls->Add(this->lbl_act1);
			this->Controls->Add(this->lbl_perf);
			this->Controls->Add(this->lbl_combo);
			this->Controls->Add(this->pBar1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->pictureBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->KeyPreview = true;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
			this->panel1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void Timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
			if (pBar1->Value == 0)
			{
				player->Stop();
				Timer1->Enabled = false;
				MessageBox::Show(
					"You are lose!",
					"", MessageBoxButtons::OK,
					MessageBoxIcon::Information);
				this->Close();
			}
			else if (pBar1->Value < 3333)
			{
				pBar1->ForeColor = System::Drawing::Color::Maroon;
			}
			else if (pBar1->Value < 6666)
			{
				pBar1->ForeColor = System::Drawing::Color::Yellow;
			}
			else
			{
				pBar1->ForeColor = System::Drawing::Color::FromArgb(128, 255, 128);
			}
			pBar1->PerformStep();
			int i = 0, j = 0;
			lbl_score->Text = score.ToString();
			for (i = 0; i < 4; i++)
			{
				//miss °Êµe
				if (act_miss[i] > 0){
					Int32 W = miss_label[i]->Size.Width + 4, H = miss_label[i]->Size.Height + 2;
					miss_label[i]->Size = System::Drawing::Size(W, H);
					miss_label[i]->Location = System::Drawing::Point(miss_label[i]->Location.X - 2, miss_label[i]->Location.Y - 1);
					if (miss_label[i]->Size.Height > 25)
						act_miss[i] = -1;
				}
				else if (act_miss[i] < 0){
					Int32 W = miss_label[i]->Size.Width - 2, H = miss_label[i]->Size.Height - 1;
					miss_label[i]->Size = System::Drawing::Size(W, H);
					miss_label[i]->Location = System::Drawing::Point(miss_label[i]->Location.X + 1, miss_label[i]->Location.Y + 1);
					if (miss_label[i]->Size.Height < 20){
						act_miss[i] = 0;
						miss_label[i]->Size = System::Drawing::Size(37, 11);
						miss_label[i]->Visible = false;
					}

				}

				//¦¨¥\ °Êµe
				act_label[i]->Location = System::Drawing::Point(act_label[i]->Location.X + act_vector[i, 0], act_label[i]->Location.Y + act_vector[i, 1]);
				if (act_label[i]->Location.X >= lbl_combo->Location.X){
					act_vector[i, 0] = 0; act_vector[i, 1] = 0;
					act_label[i]->Visible = false;
				}
				if (act_label[i]->Location.Y < lbl_combo->Location.Y - 60)
					act_vector[i, 1] = 1;
				if (act_label[i]->Location.Y > 450){
					act_label[i]->Visible = false;
					act_vector[i, 0] = 0; act_vector[i, 1] = 0;
				}

				for (j = first_label[i]; j < label_num[i]; j++)
				{
					if (j < 0)
						break;
					if (this->build_label[i, j]->Visible == false && build_time[i, j] > timePerParse->ElapsedMilliseconds)
					{
						break;
					}

					if (this->build_label[i, j]->Visible == false && build_time[i, j] < timePerParse->ElapsedMilliseconds)
					{
						this->build_label[i, j]->Visible = true;
					}

					if (this->build_label[i, j]->Visible == true && this->build_label[i, j]->Location.Y > 355 && teacher){
						lbl_perf->Text = "Excellent!!!!";
						setact(i);
						combo(excellent);
						if (first_label[i] < label_num[i] - 1)
							first_label[i] += 1;
						else
							first_label[i] = label_num[i];
						this->build_label[i, j]->Visible = false;
					}
					else if (this->build_label[i, j]->Visible == true && this->build_label[i, j]->Location.Y >380)
					{
						lbl_perf->Text = "miss";
						combo(0);
						if (first_label[i] < label_num[i] - 1)
							first_label[i] += 1;
						else
							first_label[i] = label_num[i];
						this->build_label[i, j]->Visible = false;
					}

					if (this->build_label[i, j]->Visible == true )
					{
						this->build_label[i, j]->Top = build_label[i, j]->Top + 1;
					}
				}
				end = 0;
				for (int i = 0; i < 4; i++){
					if (first_label[i] == label_num[i]){
						end++;
						continue;
					}
					else
						break;
				}
				if (end == 4){
					btn_LB->Visible = true;
					btn_LB->Enabled = true;
					pBar1->Step = 0;
				}
			}
		}
		private: System::Void build_time_Tick(System::Object^  sender, System::EventArgs^  e) {
			System::Windows::Forms::Timer^ timer = (System::Windows::Forms::Timer^)sender;
			String^ str_tag = System::Convert::ToString(timer->Tag);
			String^ delimStr = ",";
			array<Char>^ delimiter = delimStr->ToCharArray();
			array<String^>^ words;
			words = str_tag->Split(delimiter);
			this->build_label[System::Convert::ToInt32(words[0]), System::Convert::ToInt32(words[1])]->Visible = true;
		}
		void timeToBuild(array<int, 2>^ interval){
			int i = 0, j = 0;
			for (i = 0; i < 4; i++)
			{
				for (j = 0; j <= label_num[i]; j++)
				{
					this->build_label[i, j] = (gcnew System::Windows::Forms::Label());
					switch (i)
					{
					case 0:
						this->panel1->Controls->Add(this->build_label[i, j]);
						break;
					case 1:
						this->panel2->Controls->Add(this->build_label[i, j]);
						break;
					case 2:
						this->panel3->Controls->Add(this->build_label[i, j]);
						break;
					case 3:
						this->panel4->Controls->Add(this->build_label[i, j]);
						break;
					default:
						break;
					}
					this->build_label[i, j]->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
						static_cast<System::Int32>(static_cast<System::Byte>(128)));
					this->build_label[i, j]->Location = System::Drawing::Point(-1, 0);
					this->build_label[i, j]->Size = System::Drawing::Size(41, 10);
					this->build_label[i, j]->Visible = false;
					//this->build_label[i, j]->Size = System::Drawing::Size(41, 10*label_len[i,j]);
				}
			}
		}
		void MyForm_KeyPress(Object^ sender, KeyPressEventArgs^ e)
		{
			int btn = 0;
			System::Windows::Forms::Button^ goalbtn;
			char type = e->KeyChar;
			for (int i = 0; i < 4; i++){
				if (type == (*key[i])){
					fourBtn[i]->BackColor = System::Drawing::Color::Yellow;
					goalbtn = fourBtn[i];
					btn = i+1;
					break;
				}
			}
			if (btn&&start_cnt==0){
				int l = goalbtn->Location.Y - build_label[btn - 1, first_label[btn - 1]]->Location.Y - 3;
				if (l < 0)
					l *= -1;
				if (l > 25){
					return;
				}
				else if (l > 11){
					lbl_perf->Text = "miss";
					combo(0);
				}
				else if (l > 8){
					lbl_perf->Text = "not bad!";
					combo(not_bad);
				}
				else if (l > 5){
					lbl_perf->Text = "Good!!";
					combo(good);
				}
				else if (l > 2){
					lbl_perf->Text = "Perfect!!!";
					combo(perfect);
				}
				else if (l > 0){
					lbl_perf->Text = "Excellent!!!!";
					combo(excellent);
				}
				build_label[btn - 1, first_label[btn - 1]]->Visible = false;
				if (first_label[btn - 1] < label_num[btn - 1] - 1)
					first_label[btn - 1]++;
				else
					first_label[btn - 1] = label_num[btn - 1];
				setact(btn - 1);
				btn = 0;
			}
			else return;
		}
		void MyForm_KeyUp(Object^ /*sender*/, System::Windows::Forms::KeyEventArgs^ e)
		{
			int keycode;
			Keys allkey[26] = { Keys::A, Keys::B, Keys::C, Keys::D, Keys::E, Keys::F, Keys::G, Keys::H, Keys::I, Keys::J, Keys::K, Keys::L, Keys::M, Keys::N, Keys::O, Keys::P, Keys::Q, Keys::R, Keys::S,
				Keys::T, Keys::U, Keys::V, Keys::W, Keys::X, Keys::Y, Keys::Z };
			for (int i = 0; i < 4; i++){
				keycode = (*key[i]) - 'a';
				if (e->KeyCode == allkey[keycode]){
					fourBtn[i]->BackColor = System::Drawing::Color::Blue;
				}
			}
			return;
		}
		private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {
			if (song_name == "")
			{
				MessageBox::Show(
					"Error: Choose your song first!!",
					"Error", MessageBoxButtons::OK,
					MessageBoxIcon::Error);
				return;
			}
			//this->music_play->Enabled = true;
			Timer1->Enabled = true;
			start_timer->Enabled = true;
			timePerParse = Stopwatch::StartNew();
		}
		private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			OpenFileDialog^ openfiledialog1 = gcnew OpenFileDialog;
			openfiledialog1->InitialDirectory = Path::GetDirectoryName(Directory::GetCurrentDirectory())+ "\\MusicGame\\Song\\";
			openfiledialog1->Filter = "|*.wav";
			openfiledialog1->ShowDialog();
			song_name = openfiledialog1->FileName;
			if (song_name == "")
			{
				MessageBox::Show(
					"Error: Choose your song first!!",
					"Error", MessageBoxButtons::OK,
					MessageBoxIcon::Error);
				return;
			}
			// load song
			player->SoundLocation = song_name;
			player->Load();

			//load ¼ÖÃÐ
			song_name = Path::GetFileName(openfiledialog1->FileName);
			array<String^>^ words = gcnew array<String^>(500);
			StreamReader^ din;
			try
			{
				din = File::OpenText(".\\txt\\" + song_name + ".txt");
			}
			catch (Exception^ e)
			{
				MessageBox::Show(
					"Error: Erorr",
					"Error", MessageBoxButtons::OK,
					MessageBoxIcon::Error);
				return;
			}
			words = getLine(din, words);
			label_num[0] = Convert::ToInt32(words[0]);
			label_num[1] = Convert::ToInt32(words[1]);
			label_num[2] = Convert::ToInt32(words[2]);
			label_num[3] = Convert::ToInt32(words[3]);
			words = getLine(din, words);
			input_build_time(0, words);
			words = getLine(din, words);
			input_build_time(1, words);
			words = getLine(din, words);
			input_build_time(2, words);
			words = getLine(din, words);
			input_build_time(3, words);
			//build time_build
			timeToBuild(build_time);

			//set progress bar
			pBar1->Minimum = 0;
			pBar1->Maximum = 10000;
			pBar1->Value = 10000;
			pBar1->Step = -3;

		}
		void combo(unsigned int type){
			if (lbl_perf->Text != "miss"){
				if (pBar1->Value > 9800)
					pBar1->Value = 10000;
				else
					pBar1->Value+=200;
				comboNum++;
				score += type * ((type / 100) * comboNum);
				if (comboNum > 10){
					lbl_combo->ForeColor = System::Drawing::Color::LimeGreen;
				}
				if (comboNum > 20){
					lbl_combo->ForeColor = System::Drawing::Color::Gold;
				}
				lbl_combo->Text = "Combo X " + comboNum.ToString();
			}
			else{
				if (pBar1->Value < 300)
					pBar1->Value = 0;
				else
					pBar1->Value -= 300;
				score += type;
				comboNum = 0;
				lbl_combo->ForeColor = System::Drawing::Color::Silver;
				lbl_combo->Text = "Combo X " + comboNum.ToString();
			}

		}
		void setact(int num){
			if (lbl_perf->Text == "miss")
				for (int j = 0; j < 4; j++){
					if (!act_miss[j]){
						act_miss[j] = 1;
						miss_label[j]->Location = System::Drawing::Point(22 + 70 * num, 375);
						miss_label[j]->Visible = true;
						return;
					}
				}
			else{
				for (int i = 0; i < 4; i++){
					if (act_vector[i, 0] == 0 && act_vector[i, 1] == 0){
						act_vector[i, 0] = 4 - num;
						act_vector[i, 1] = -1;
						act_label[i]->Location = System::Drawing::Point(22 + 70 * num, 360);
						act_label[i]->Visible = true;
						return;
					}
				}
			}

		}
		private: System::Void music_play_Tick(System::Object^  sender, System::EventArgs^  e) {
			
			this->music_play->Enabled = false;
		}
		private: System::Void start_tick(System::Object^  sender, System::EventArgs^  e) {
			if (start_cnt - 1 > -1)
			{
				start_cnt -= 1;
			}
			else
			{
				//increase progress bar
				//pBar1->PerformStep();
				player->Play();
				start_timer->Enabled = false;
			}
		}


	array<String^>^ getLine(StreamReader^ din, array<String^>^ words)
	{
		

		String^ str;
		String^ strcat = "";
		while ((str = din->ReadLine()) != " ")
		{
			strcat += str;
		}
		String^ delimStr = ",";
		array<Char>^ delimiter = delimStr->ToCharArray();
		words = strcat->Split(delimiter);

		return words;
	}
	void input_build_time(int i , array<String^>^ words)
	{
		int j;
		for (j = 0; j < label_num[i]; j++)
		{
			build_time[i, j] = Convert::ToInt32(words[j]);
		}
	}
	private: System::Void btn_enter(System::Object^  sender, System::EventArgs^  e) {
		Button^ thisButton = safe_cast<Button^>(sender);
		thisButton->FlatAppearance->BorderSize = 1;
	}
	private: System::Void btn_leave(System::Object^  sender, System::EventArgs^  e) {
		Button^ thisButton = safe_cast<Button^>(sender);
		thisButton->FlatAppearance->BorderSize = 0;
	}
	private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
		player->SoundLocation = ".\\menuback.wav";
		player->Load();
		player->Play();
		Timer1->Enabled = false;
		this->Close();
	}

	private: System::Void btn_LB_Click(System::Object^  sender, System::EventArgs^  e) {
		LeaderboardForm^ dlg = gcnew LeaderboardForm(score, song_name);
		Timer1->Enabled = false;
		player->Stop();
		dlg->ShowDialog();
		for (int i = 0; i < 4; i++)
			first_label[i] = 0;
		
		this->Close();
	}

	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		teacher = !teacher;
		System::Drawing::Color temp = button3->BackColor;
		button3->BackColor = button3->ForeColor;
		button3->ForeColor = temp;
		if (teacher)
			button3->Text = "Cancel";
		else
			button3->Text = "For teacher";
	}
};
}

#pragma once

namespace MusicGame {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// LeaderboardForm 的摘要
	/// </summary>
	public ref class LeaderboardForm : public System::Windows::Forms::Form
	{
		array<Label^>^ ary_name = gcnew array<Label^>(10);
		array<Label^>^ ary_score = gcnew array<Label^>(10);
		array<String^>^ lines = gcnew array<String^>(10);
		int newrecord = 10;
		String^ path;
		int record = 0;


	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;


	private: System::Windows::Forms::TextBox^  txt_inputname;
	private: System::Windows::Forms::Label^  lbl_name1;
	private: System::Windows::Forms::Label^  lbl_name2;
	private: System::Windows::Forms::Label^  lbl_name3;
	private: System::Windows::Forms::Label^  lbl_name4;
	private: System::Windows::Forms::Label^  lbl_name5;
	private: System::Windows::Forms::Label^  lbl_name6;
	private: System::Windows::Forms::Label^  lbl_name7;
	private: System::Windows::Forms::Label^  lbl_name8;
	private: System::Windows::Forms::Label^  lbl_name9;
	private: System::Windows::Forms::Label^  lbl_name10;
	private: System::Windows::Forms::Label^  lbl_score1;

	private: System::Windows::Forms::Label^  lbl_score2;
	private: System::Windows::Forms::Label^  lbl_score3;
	private: System::Windows::Forms::Label^  lbl_score4;
	private: System::Windows::Forms::Label^  lbl_score5;
	private: System::Windows::Forms::Label^  lbl_score6;
	private: System::Windows::Forms::Label^  lbl_score7;
	private: System::Windows::Forms::Label^  lbl_score8;
	private: System::Windows::Forms::Label^  lbl_score9;
	private: System::Windows::Forms::Label^  lbl_score10;
	private: System::Windows::Forms::Label^  lbl_perf;

	private: System::Windows::Forms::Button^  btn_submit;
			 
	public:
		LeaderboardForm(int score, String^ songname)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
			ary_name = gcnew array<Label^> {lbl_name1, lbl_name2, lbl_name3, lbl_name4, lbl_name5
				, lbl_name6, lbl_name7, lbl_name8, lbl_name9, lbl_name10};
			ary_score = gcnew array<Label^> {lbl_score1, lbl_score2, lbl_score3, lbl_score4, lbl_score5
				, lbl_score6, lbl_score7, lbl_score8, lbl_score9, lbl_score10};
			record = score;
			path = ".//LeaderBoard//" + songname;
			path += ".txt";
			System::String^ delimStr = L",";
			array<System::Char>^ delimiter = delimStr->ToCharArray();
			lines = gcnew array<String^>(10);
			int^ temp_score = gcnew int(0);

			array<System::String^>^ split_line;
			if (System::IO::File::Exists(path)){
				System::IO::StreamReader^ din = gcnew System::IO::StreamReader(System::IO::File::OpenRead(path), System::Text::Encoding::ASCII);;
				String^ line;
				
				int cnt = 0;
				while ((line = din->ReadLine()) != nullptr && line->CompareTo("")){
					lines[cnt] = line;
					cnt++;
				}
				din->Close();
			}
			int i = 0;
			while (i<10){
				split_line = lines[i]->Split(delimiter);
				calc(split_line[1]->ToCharArray(), temp_score);
				if (score>(*temp_score) && newrecord == 10){
		
					ary_score[i]->Text = score.ToString();
					for (int j = 9; j > i; j--)
						lines[j] = lines[j-1];
					
					newrecord = i;
					i++;
					
				}
				else{
					ary_name[i]->Text = split_line[0];
					ary_score[i]->Text = split_line[1];
					i++;
				}
			}
			if (newrecord != 10)
				lbl_perf->Text = "Please enter your name";
			else{
				lbl_perf->Text = "Don't give up";
				txt_inputname->Visible = false;
			}
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~LeaderboardForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器
		/// 修改這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(LeaderboardForm::typeid));
			this->btn_submit = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->txt_inputname = (gcnew System::Windows::Forms::TextBox());
			this->lbl_name1 = (gcnew System::Windows::Forms::Label());
			this->lbl_name2 = (gcnew System::Windows::Forms::Label());
			this->lbl_name3 = (gcnew System::Windows::Forms::Label());
			this->lbl_name4 = (gcnew System::Windows::Forms::Label());
			this->lbl_name5 = (gcnew System::Windows::Forms::Label());
			this->lbl_name6 = (gcnew System::Windows::Forms::Label());
			this->lbl_name7 = (gcnew System::Windows::Forms::Label());
			this->lbl_name8 = (gcnew System::Windows::Forms::Label());
			this->lbl_name9 = (gcnew System::Windows::Forms::Label());
			this->lbl_name10 = (gcnew System::Windows::Forms::Label());
			this->lbl_score1 = (gcnew System::Windows::Forms::Label());
			this->lbl_score2 = (gcnew System::Windows::Forms::Label());
			this->lbl_score3 = (gcnew System::Windows::Forms::Label());
			this->lbl_score4 = (gcnew System::Windows::Forms::Label());
			this->lbl_score5 = (gcnew System::Windows::Forms::Label());
			this->lbl_score6 = (gcnew System::Windows::Forms::Label());
			this->lbl_score7 = (gcnew System::Windows::Forms::Label());
			this->lbl_score8 = (gcnew System::Windows::Forms::Label());
			this->lbl_score9 = (gcnew System::Windows::Forms::Label());
			this->lbl_score10 = (gcnew System::Windows::Forms::Label());
			this->lbl_perf = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btn_submit
			// 
			this->btn_submit->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->btn_submit->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->btn_submit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_submit->ForeColor = System::Drawing::SystemColors::ControlLight;
			this->btn_submit->Location = System::Drawing::Point(247, 346);
			this->btn_submit->Name = L"btn_submit";
			this->btn_submit->Size = System::Drawing::Size(64, 28);
			this->btn_submit->TabIndex = 2;
			this->btn_submit->Text = L"確認";
			this->btn_submit->UseVisualStyleBackColor = false;
			this->btn_submit->Click += gcnew System::EventHandler(this, &LeaderboardForm::btn_submit_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Buxton Sketch", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->label1->Location = System::Drawing::Point(8, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(18, 26);
			this->label1->TabIndex = 0;
			this->label1->Text = L"1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Buxton Sketch", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->label2->Location = System::Drawing::Point(8, 33);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(24, 26);
			this->label2->TabIndex = 0;
			this->label2->Text = L"2";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Buxton Sketch", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->label3->Location = System::Drawing::Point(8, 57);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(25, 26);
			this->label3->TabIndex = 0;
			this->label3->Text = L"3";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Buxton Sketch", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::White;
			this->label4->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->label4->Location = System::Drawing::Point(8, 81);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(24, 26);
			this->label4->TabIndex = 0;
			this->label4->Text = L"4";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Buxton Sketch", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::White;
			this->label5->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->label5->Location = System::Drawing::Point(8, 105);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(24, 26);
			this->label5->TabIndex = 0;
			this->label5->Text = L"5";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Buxton Sketch", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::White;
			this->label6->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->label6->Location = System::Drawing::Point(8, 129);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(23, 26);
			this->label6->TabIndex = 0;
			this->label6->Text = L"6";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Transparent;
			this->label7->Font = (gcnew System::Drawing::Font(L"Buxton Sketch", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::White;
			this->label7->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->label7->Location = System::Drawing::Point(8, 153);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(23, 26);
			this->label7->TabIndex = 0;
			this->label7->Text = L"7";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::Transparent;
			this->label8->Font = (gcnew System::Drawing::Font(L"Buxton Sketch", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::White;
			this->label8->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->label8->Location = System::Drawing::Point(8, 177);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(22, 26);
			this->label8->TabIndex = 0;
			this->label8->Text = L"8";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::Color::Transparent;
			this->label9->Font = (gcnew System::Drawing::Font(L"Buxton Sketch", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::Color::White;
			this->label9->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->label9->Location = System::Drawing::Point(8, 201);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(23, 26);
			this->label9->TabIndex = 0;
			this->label9->Text = L"9";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::Color::Transparent;
			this->label10->Font = (gcnew System::Drawing::Font(L"Buxton Sketch", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label10->ForeColor = System::Drawing::Color::White;
			this->label10->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->label10->Location = System::Drawing::Point(8, 225);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(30, 26);
			this->label10->TabIndex = 0;
			this->label10->Text = L"10";
			// 
			// txt_inputname
			// 
			this->txt_inputname->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->txt_inputname->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txt_inputname->Location = System::Drawing::Point(12, 346);
			this->txt_inputname->Name = L"txt_inputname";
			this->txt_inputname->Size = System::Drawing::Size(152, 27);
			this->txt_inputname->TabIndex = 3;
			this->txt_inputname->TextChanged += gcnew System::EventHandler(this, &LeaderboardForm::txt_inputname_TextChanged);
			// 
			// lbl_name1
			// 
			this->lbl_name1->BackColor = System::Drawing::Color::Transparent;
			this->lbl_name1->ForeColor = System::Drawing::Color::Silver;
			this->lbl_name1->Location = System::Drawing::Point(37, 12);
			this->lbl_name1->Name = L"lbl_name1";
			this->lbl_name1->Size = System::Drawing::Size(125, 23);
			this->lbl_name1->TabIndex = 4;
			// 
			// lbl_name2
			// 
			this->lbl_name2->BackColor = System::Drawing::Color::Transparent;
			this->lbl_name2->ForeColor = System::Drawing::Color::Silver;
			this->lbl_name2->Location = System::Drawing::Point(37, 36);
			this->lbl_name2->Name = L"lbl_name2";
			this->lbl_name2->Size = System::Drawing::Size(125, 23);
			this->lbl_name2->TabIndex = 5;
			// 
			// lbl_name3
			// 
			this->lbl_name3->BackColor = System::Drawing::Color::Transparent;
			this->lbl_name3->ForeColor = System::Drawing::Color::Silver;
			this->lbl_name3->Location = System::Drawing::Point(37, 60);
			this->lbl_name3->Name = L"lbl_name3";
			this->lbl_name3->Size = System::Drawing::Size(125, 23);
			this->lbl_name3->TabIndex = 6;
			// 
			// lbl_name4
			// 
			this->lbl_name4->BackColor = System::Drawing::Color::Transparent;
			this->lbl_name4->ForeColor = System::Drawing::Color::Silver;
			this->lbl_name4->Location = System::Drawing::Point(37, 84);
			this->lbl_name4->Name = L"lbl_name4";
			this->lbl_name4->Size = System::Drawing::Size(125, 23);
			this->lbl_name4->TabIndex = 7;
			// 
			// lbl_name5
			// 
			this->lbl_name5->BackColor = System::Drawing::Color::Transparent;
			this->lbl_name5->ForeColor = System::Drawing::Color::Silver;
			this->lbl_name5->Location = System::Drawing::Point(37, 108);
			this->lbl_name5->Name = L"lbl_name5";
			this->lbl_name5->Size = System::Drawing::Size(125, 23);
			this->lbl_name5->TabIndex = 8;
			// 
			// lbl_name6
			// 
			this->lbl_name6->BackColor = System::Drawing::Color::Transparent;
			this->lbl_name6->ForeColor = System::Drawing::Color::Silver;
			this->lbl_name6->Location = System::Drawing::Point(37, 132);
			this->lbl_name6->Name = L"lbl_name6";
			this->lbl_name6->Size = System::Drawing::Size(125, 23);
			this->lbl_name6->TabIndex = 9;
			// 
			// lbl_name7
			// 
			this->lbl_name7->BackColor = System::Drawing::Color::Transparent;
			this->lbl_name7->ForeColor = System::Drawing::Color::Silver;
			this->lbl_name7->Location = System::Drawing::Point(37, 156);
			this->lbl_name7->Name = L"lbl_name7";
			this->lbl_name7->Size = System::Drawing::Size(125, 23);
			this->lbl_name7->TabIndex = 10;
			// 
			// lbl_name8
			// 
			this->lbl_name8->BackColor = System::Drawing::Color::Transparent;
			this->lbl_name8->ForeColor = System::Drawing::Color::Silver;
			this->lbl_name8->Location = System::Drawing::Point(37, 180);
			this->lbl_name8->Name = L"lbl_name8";
			this->lbl_name8->Size = System::Drawing::Size(125, 23);
			this->lbl_name8->TabIndex = 11;
			// 
			// lbl_name9
			// 
			this->lbl_name9->BackColor = System::Drawing::Color::Transparent;
			this->lbl_name9->ForeColor = System::Drawing::Color::Silver;
			this->lbl_name9->Location = System::Drawing::Point(37, 204);
			this->lbl_name9->Name = L"lbl_name9";
			this->lbl_name9->Size = System::Drawing::Size(125, 23);
			this->lbl_name9->TabIndex = 12;
			// 
			// lbl_name10
			// 
			this->lbl_name10->BackColor = System::Drawing::Color::Transparent;
			this->lbl_name10->ForeColor = System::Drawing::Color::Silver;
			this->lbl_name10->Location = System::Drawing::Point(37, 228);
			this->lbl_name10->Name = L"lbl_name10";
			this->lbl_name10->Size = System::Drawing::Size(125, 23);
			this->lbl_name10->TabIndex = 13;
			// 
			// lbl_score1
			// 
			this->lbl_score1->BackColor = System::Drawing::Color::Transparent;
			this->lbl_score1->ForeColor = System::Drawing::Color::Silver;
			this->lbl_score1->Location = System::Drawing::Point(168, 12);
			this->lbl_score1->Name = L"lbl_score1";
			this->lbl_score1->Size = System::Drawing::Size(125, 23);
			this->lbl_score1->TabIndex = 14;
			// 
			// lbl_score2
			// 
			this->lbl_score2->BackColor = System::Drawing::Color::Transparent;
			this->lbl_score2->ForeColor = System::Drawing::Color::Silver;
			this->lbl_score2->Location = System::Drawing::Point(168, 36);
			this->lbl_score2->Name = L"lbl_score2";
			this->lbl_score2->Size = System::Drawing::Size(125, 23);
			this->lbl_score2->TabIndex = 15;
			// 
			// lbl_score3
			// 
			this->lbl_score3->BackColor = System::Drawing::Color::Transparent;
			this->lbl_score3->ForeColor = System::Drawing::Color::Silver;
			this->lbl_score3->Location = System::Drawing::Point(168, 60);
			this->lbl_score3->Name = L"lbl_score3";
			this->lbl_score3->Size = System::Drawing::Size(125, 23);
			this->lbl_score3->TabIndex = 16;
			// 
			// lbl_score4
			// 
			this->lbl_score4->BackColor = System::Drawing::Color::Transparent;
			this->lbl_score4->ForeColor = System::Drawing::Color::Silver;
			this->lbl_score4->Location = System::Drawing::Point(168, 84);
			this->lbl_score4->Name = L"lbl_score4";
			this->lbl_score4->Size = System::Drawing::Size(125, 23);
			this->lbl_score4->TabIndex = 17;
			// 
			// lbl_score5
			// 
			this->lbl_score5->BackColor = System::Drawing::Color::Transparent;
			this->lbl_score5->ForeColor = System::Drawing::Color::Silver;
			this->lbl_score5->Location = System::Drawing::Point(168, 108);
			this->lbl_score5->Name = L"lbl_score5";
			this->lbl_score5->Size = System::Drawing::Size(125, 23);
			this->lbl_score5->TabIndex = 18;
			// 
			// lbl_score6
			// 
			this->lbl_score6->BackColor = System::Drawing::Color::Transparent;
			this->lbl_score6->ForeColor = System::Drawing::Color::Silver;
			this->lbl_score6->Location = System::Drawing::Point(168, 132);
			this->lbl_score6->Name = L"lbl_score6";
			this->lbl_score6->Size = System::Drawing::Size(125, 23);
			this->lbl_score6->TabIndex = 19;
			// 
			// lbl_score7
			// 
			this->lbl_score7->BackColor = System::Drawing::Color::Transparent;
			this->lbl_score7->ForeColor = System::Drawing::Color::Silver;
			this->lbl_score7->Location = System::Drawing::Point(168, 156);
			this->lbl_score7->Name = L"lbl_score7";
			this->lbl_score7->Size = System::Drawing::Size(125, 23);
			this->lbl_score7->TabIndex = 20;
			// 
			// lbl_score8
			// 
			this->lbl_score8->BackColor = System::Drawing::Color::Transparent;
			this->lbl_score8->ForeColor = System::Drawing::Color::Silver;
			this->lbl_score8->Location = System::Drawing::Point(168, 180);
			this->lbl_score8->Name = L"lbl_score8";
			this->lbl_score8->Size = System::Drawing::Size(125, 23);
			this->lbl_score8->TabIndex = 21;
			// 
			// lbl_score9
			// 
			this->lbl_score9->BackColor = System::Drawing::Color::Transparent;
			this->lbl_score9->ForeColor = System::Drawing::Color::Silver;
			this->lbl_score9->Location = System::Drawing::Point(168, 204);
			this->lbl_score9->Name = L"lbl_score9";
			this->lbl_score9->Size = System::Drawing::Size(125, 23);
			this->lbl_score9->TabIndex = 22;
			// 
			// lbl_score10
			// 
			this->lbl_score10->BackColor = System::Drawing::Color::Transparent;
			this->lbl_score10->ForeColor = System::Drawing::Color::Silver;
			this->lbl_score10->Location = System::Drawing::Point(168, 228);
			this->lbl_score10->Name = L"lbl_score10";
			this->lbl_score10->Size = System::Drawing::Size(125, 23);
			this->lbl_score10->TabIndex = 23;
			// 
			// lbl_perf
			// 
			this->lbl_perf->AutoSize = true;
			this->lbl_perf->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->lbl_perf->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->lbl_perf->Location = System::Drawing::Point(12, 294);
			this->lbl_perf->Name = L"lbl_perf";
			this->lbl_perf->Size = System::Drawing::Size(0, 19);
			this->lbl_perf->TabIndex = 0;
			// 
			// LeaderboardForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 19);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(323, 377);
			this->Controls->Add(this->lbl_score10);
			this->Controls->Add(this->lbl_score9);
			this->Controls->Add(this->lbl_score8);
			this->Controls->Add(this->lbl_score7);
			this->Controls->Add(this->lbl_score6);
			this->Controls->Add(this->lbl_score5);
			this->Controls->Add(this->lbl_score4);
			this->Controls->Add(this->lbl_score3);
			this->Controls->Add(this->lbl_score2);
			this->Controls->Add(this->lbl_score1);
			this->Controls->Add(this->lbl_name10);
			this->Controls->Add(this->lbl_name9);
			this->Controls->Add(this->lbl_name8);
			this->Controls->Add(this->lbl_name7);
			this->Controls->Add(this->lbl_name6);
			this->Controls->Add(this->lbl_name5);
			this->Controls->Add(this->lbl_name4);
			this->Controls->Add(this->lbl_name3);
			this->Controls->Add(this->lbl_name2);
			this->Controls->Add(this->lbl_name1);
			this->Controls->Add(this->lbl_perf);
			this->Controls->Add(this->txt_inputname);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btn_submit);
			this->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"LeaderboardForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"LeaderboardForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void txt_inputname_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		if (newrecord != 10)
			ary_name[newrecord]->Text = txt_inputname->Text;
	}
	private: System::Void btn_submit_Click(System::Object^  sender, System::EventArgs^  e) {
		System::IO::StreamWriter^ sw = gcnew System::IO::StreamWriter(path);
		if (newrecord != 10){
			lines[newrecord] = txt_inputname->Text + "," + record.ToString();
			for (int i = 0; i < 10; i++){
				sw->WriteLine(lines[i]);
			}
		}
		sw->Close();
		this->Close();
	}
	void calc(array<System::Char>^ line, int^ num){
		int^ i = gcnew int(0);
		bool^ isDigit = gcnew bool(true);
		int^ result = gcnew int(0);

		for (*i; *i<(line->Length) && isDigit; (*i)++){
			if (!(line[(*i)] >= '0'&&line[(*i)] <= '9')){
				*isDigit = false;
				continue;
			}
			*result = (*result) * 10 + (line[*i] - '0');
		}
		*num = *result;
		delete i;
		delete isDigit; delete result;
	}



};
}

#pragma once

namespace MusicGame {

	using namespace System;
	using namespace System::IO;
	using namespace System::Diagnostics;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// TestForm 的摘要
	/// </summary>
	public ref class TestForm : public System::Windows::Forms::Form
	{
	public:
		String^ song_name;
		System::Media::SoundPlayer^ player = gcnew System::Media::SoundPlayer();
	

	public:
		Stopwatch ^ timePerParse;
		array<Int32>^ game_Rhythm0;
		array<Int32>^ game_Rhythm1;
		array<Int32>^ game_Rhythm2;
		array<Int32>^ game_Rhythm3;
		array<Int32>^ Rhythm_num;
		array<String^ >^  str;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	public:

	public:
		String^ num = gcnew String("");
		TestForm(void)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
			game_Rhythm0 = gcnew array<Int32>(600);
			game_Rhythm1 = gcnew array<Int32>(600);
			game_Rhythm2 = gcnew array<Int32>(600);
			game_Rhythm3 = gcnew array<Int32>(600);
			Rhythm_num = gcnew array<Int32>{0, 0, 0, 0};
			str = gcnew array<String^>{"", "","", ""};
			song_name = gcnew String("");
			this->KeyPreview = true;
			this->KeyPress +=
				gcnew KeyPressEventHandler(this, &TestForm::TestForm_KeyPress);

			this->Cursor = gcnew System::Windows::Forms::Cursor(".\\cursor.ico");

		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~TestForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::Timer^  start_timer;
	private: System::Windows::Forms::TextBox^  textBox3;



	protected:

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(TestForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->start_timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::Color::Yellow;
			this->label1->Location = System::Drawing::Point(21, 160);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(16, 12);
			this->label1->TabIndex = 0;
			this->label1->Text = L"str";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(38, 157);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
			this->textBox1->Size = System::Drawing::Size(234, 22);
			this->textBox1->TabIndex = 1;
			this->textBox1->WordWrap = false;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(38, 205);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
			this->textBox2->Size = System::Drawing::Size(234, 22);
			this->textBox2->TabIndex = 3;
			this->textBox2->WordWrap = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->ForeColor = System::Drawing::Color::Yellow;
			this->label2->Location = System::Drawing::Point(11, 208);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(26, 12);
			this->label2->TabIndex = 2;
			this->label2->Text = L"num";
			// 
			// button1
			// 
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::Yellow;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button1->ForeColor = System::Drawing::Color::Yellow;
			this->button1->Location = System::Drawing::Point(38, 24);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 4;
			this->button1->Text = L"選擇音樂";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &TestForm::button1_Click);
			this->button1->MouseEnter += gcnew System::EventHandler(this, &TestForm::btn_enter);
			this->button1->MouseLeave += gcnew System::EventHandler(this, &TestForm::btn_leave);
			// 
			// button2
			// 
			this->button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.BackgroundImage")));
			this->button2->FlatAppearance->BorderColor = System::Drawing::Color::Yellow;
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button2->ForeColor = System::Drawing::Color::Yellow;
			this->button2->Location = System::Drawing::Point(164, 24);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 5;
			this->button2->Text = L"開始撥放";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &TestForm::button2_Click);
			this->button2->MouseEnter += gcnew System::EventHandler(this, &TestForm::btn_enter);
			this->button2->MouseLeave += gcnew System::EventHandler(this, &TestForm::btn_leave);
			// 
			// button3
			// 
			this->button3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.BackgroundImage")));
			this->button3->FlatAppearance->BorderColor = System::Drawing::Color::Yellow;
			this->button3->FlatAppearance->BorderSize = 0;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button3->ForeColor = System::Drawing::Color::Yellow;
			this->button3->Location = System::Drawing::Point(101, 128);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 6;
			this->button3->Text = L"製作樂譜";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &TestForm::button3_Click);
			this->button3->MouseEnter += gcnew System::EventHandler(this, &TestForm::btn_enter);
			this->button3->MouseLeave += gcnew System::EventHandler(this, &TestForm::btn_leave);
			// 
			// start_timer
			// 
			this->start_timer->Interval = 1000;
			this->start_timer->Tick += gcnew System::EventHandler(this, &TestForm::start_timer_Tick);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(130, 26);
			this->textBox3->Name = L"textBox3";
			this->textBox3->ReadOnly = true;
			this->textBox3->Size = System::Drawing::Size(17, 22);
			this->textBox3->TabIndex = 7;
			this->textBox3->Text = L"5";
			this->textBox3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// button4
			// 
			this->button4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button4.BackgroundImage")));
			this->button4->FlatAppearance->BorderColor = System::Drawing::Color::Yellow;
			this->button4->FlatAppearance->BorderSize = 0;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button4->ForeColor = System::Drawing::Color::Yellow;
			this->button4->Location = System::Drawing::Point(101, 233);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 8;
			this->button4->Text = L"儲存樂譜";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &TestForm::button4_Click);
			this->button4->MouseEnter += gcnew System::EventHandler(this, &TestForm::btn_enter);
			this->button4->MouseLeave += gcnew System::EventHandler(this, &TestForm::btn_leave);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::Blue;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button5->Location = System::Drawing::Point(38, 75);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(57, 28);
			this->button5->TabIndex = 9;
			this->button5->Text = L"D";
			this->button5->UseVisualStyleBackColor = false;
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::Blue;
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button6->Location = System::Drawing::Point(91, 75);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(51, 28);
			this->button6->TabIndex = 10;
			this->button6->Text = L"F";
			this->button6->UseVisualStyleBackColor = false;
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::Color::Blue;
			this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button7->Location = System::Drawing::Point(138, 75);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(54, 28);
			this->button7->TabIndex = 11;
			this->button7->Text = L"J";
			this->button7->UseVisualStyleBackColor = false;
			// 
			// button8
			// 
			this->button8->BackColor = System::Drawing::Color::Blue;
			this->button8->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button8->Location = System::Drawing::Point(188, 75);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(51, 28);
			this->button8->TabIndex = 12;
			this->button8->Text = L"K";
			this->button8->UseVisualStyleBackColor = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox1->Location = System::Drawing::Point(178, 283);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(109, 105);
			this->pictureBox1->TabIndex = 13;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &TestForm::pictureBox1_Click);
			// 
			// TestForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ClientSize = System::Drawing::Size(284, 382);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"TestForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Edit";
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &TestForm::TestForm_KeyUp);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		void textSet(array<Int32>^ game_Rhythm, String^ %str, String^ %num)
		{
			int count = 0;
			for (int i = 0; i < 300; i++)
			{
				if (game_Rhythm[i] == 0)
				{
					break;
				}
				if (i != 0)
				{
					str += ",";
				}
				str += game_Rhythm[i];
				
				count++;
			}
			if (num != "")
			{
				num += ",";
			}
			num += count;
		}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		OpenFileDialog^ openfiledialog1 = gcnew OpenFileDialog;
		openfiledialog1->Filter = "|*.wav";
		openfiledialog1->ShowDialog();
		song_name = openfiledialog1->FileName;
		if (song_name == "")
		{
			MessageBox::Show(
				"Error: 請先選擇歌曲!",
				"Error", MessageBoxButtons::OK,
				MessageBoxIcon::Error);
			return;
		}
		// load song
		player->SoundLocation = song_name;
		player->Load();
		song_name = Path::GetFileName(openfiledialog1->FileName);
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		if (song_name == "")
		{
			MessageBox::Show(
				"Error: 請先選擇歌曲!",
				"Error", MessageBoxButtons::OK,
				MessageBoxIcon::Error);
			return;
		}
		start_timer->Enabled = true;
		timePerParse = Stopwatch::StartNew();
	}
	
	private: System::Void start_timer_Tick(System::Object^  sender, System::EventArgs^  e) {
		if (Convert::ToInt32(textBox3->Text) - 1 > -1)
		{
			textBox3->Text = Convert::ToString(Convert::ToInt32(textBox3->Text) - 1);
		}
		else
		{
			player->Play();
			start_timer->Enabled = false;
		}
	}
	void TestForm_KeyPress(Object^ sender, KeyPressEventArgs^ e)
	{
		if (e->KeyChar == 'd')
		{
			game_Rhythm0[Rhythm_num[0]] = timePerParse->ElapsedMilliseconds - 5500;
			Rhythm_num[0]++;
			button5->BackColor = System::Drawing::Color::Yellow;
		}
		else if (e->KeyChar == 'f')
		{
			game_Rhythm1[Rhythm_num[1]] = timePerParse->ElapsedMilliseconds - 5500;
			Rhythm_num[1]++;
			button6->BackColor = System::Drawing::Color::Yellow;
		}
		else if (e->KeyChar == 'j')
		{
			game_Rhythm2[Rhythm_num[2]] = timePerParse->ElapsedMilliseconds - 5500;
			Rhythm_num[2]++;
			button7->BackColor = System::Drawing::Color::Yellow;
		}
		else if (e->KeyChar == 'k')
		{
			game_Rhythm3[Rhythm_num[3]] = timePerParse->ElapsedMilliseconds - 5500;
			Rhythm_num[3]++;
			button8->BackColor = System::Drawing::Color::Yellow;
		}
		else
			return;
	}
	void TestForm_KeyUp(Object^ /*sender*/, System::Windows::Forms::KeyEventArgs^ e)
	{

		if (e->KeyCode == Keys::D)
		{
			button5->BackColor = System::Drawing::Color::Blue;
		}
		if (e->KeyCode == Keys::F)
		{
			button6->BackColor = System::Drawing::Color::Blue;
		}
		if (e->KeyCode == Keys::J)
		{
			button7->BackColor = System::Drawing::Color::Blue;
		}
		if (e->KeyCode == Keys::K)
		{
			button8->BackColor = System::Drawing::Color::Blue;
		}
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		textSet(game_Rhythm0, str[0], num);
		textSet(game_Rhythm1, str[1], num);
		textSet(game_Rhythm2, str[2], num);
		textSet(game_Rhythm3, str[3], num);
		textBox1->Text = "{" + str[0] + "}," + "{" + str[1] + "}," + "{" + str[2] + "}," + "{" + str[3] + "}";
		textBox2->Text = num;
	}
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
		if (song_name == "")
		{
			MessageBox::Show(
				"Error: 請先選擇歌曲!",
				"Error", MessageBoxButtons::OK,
				MessageBoxIcon::Error);
			return;
		}
		StreamWriter^ sw = gcnew StreamWriter(".\\txt\\"+song_name+".txt");
		sw->WriteLine(textBox2->Text);
		sw->WriteLine(" ");
		sw->WriteLine(str[0]);
		sw->WriteLine(" ");
		sw->WriteLine(str[1]);
		sw->WriteLine(" ");
		sw->WriteLine(str[2]);
		sw->WriteLine(" ");
		sw->WriteLine(str[3]);
		sw->Write(" ");
		sw->Close();
		sw = gcnew StreamWriter(".\\LeaderBoard\\" + song_name + ".txt");
		for (int i = 0; i < 10; i++){
			sw->WriteLine("Undefine,0");
		}
		sw->Close();
		delete str, num;
		MessageBox::Show(
			"Information: 儲存成功!",
			"Information", MessageBoxButtons::OK,
			MessageBoxIcon::Information);
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
		this->Close();
	}
};
}

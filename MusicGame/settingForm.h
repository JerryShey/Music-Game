#pragma once

namespace MusicGame {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Setting 的摘要
	/// </summary>
	public ref class settingForm : public System::Windows::Forms::Form
	{
	private: array<Button^>^ fourBtn;
	private: unsigned short int setButton;
	private: bool selectBtn = false;
	private: array<char^>^ key ;
	private: System::String^ en = "abcdefghijklmnopqrstuvwxyz";

	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Label^  lbl_msg;
	public:
		System::Media::SoundPlayer^ player = gcnew System::Media::SoundPlayer();

		settingForm( char^ left, char^ down, char^ up, char^ right)
		{
			key = gcnew array<char^> {left, down, up, right};
			InitializeComponent();
			
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &settingForm::settingForm_KeyPress);
			fourBtn = gcnew array<System::Windows::Forms::Button ^> {btn_left, btn_down, btn_up, btn_right};
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
		~settingForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btn_left;
	private: System::Windows::Forms::Button^  btn_down;
	protected:

	private: System::Windows::Forms::Button^  btn_right;
	private: System::Windows::Forms::Button^  btn_up;



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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(settingForm::typeid));
			this->btn_left = (gcnew System::Windows::Forms::Button());
			this->btn_down = (gcnew System::Windows::Forms::Button());
			this->btn_right = (gcnew System::Windows::Forms::Button());
			this->btn_up = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->lbl_msg = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// btn_left
			// 
			this->btn_left->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->btn_left->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_left->Font = (gcnew System::Drawing::Font(L"Georgia", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_left->ForeColor = System::Drawing::Color::Silver;
			this->btn_left->Location = System::Drawing::Point(44, 90);
			this->btn_left->Name = L"btn_left";
			this->btn_left->Size = System::Drawing::Size(78, 31);
			this->btn_left->TabIndex = 1;
			this->btn_left->Text = L"D";
			this->btn_left->UseVisualStyleBackColor = false;
			this->btn_left->Click += gcnew System::EventHandler(this, &settingForm::btn_click);
			this->btn_left->MouseEnter += gcnew System::EventHandler(this, &settingForm::btn_enter);
			this->btn_left->MouseLeave += gcnew System::EventHandler(this, &settingForm::btn_leave);
			// 
			// btn_down
			// 
			this->btn_down->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->btn_down->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_down->Font = (gcnew System::Drawing::Font(L"Georgia", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_down->ForeColor = System::Drawing::Color::Silver;
			this->btn_down->Location = System::Drawing::Point(168, 90);
			this->btn_down->Name = L"btn_down";
			this->btn_down->Size = System::Drawing::Size(78, 31);
			this->btn_down->TabIndex = 2;
			this->btn_down->Text = L"F";
			this->btn_down->UseVisualStyleBackColor = false;
			this->btn_down->Click += gcnew System::EventHandler(this, &settingForm::btn_click);
			this->btn_down->MouseEnter += gcnew System::EventHandler(this, &settingForm::btn_enter);
			this->btn_down->MouseLeave += gcnew System::EventHandler(this, &settingForm::btn_leave);
			// 
			// btn_right
			// 
			this->btn_right->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->btn_right->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_right->Font = (gcnew System::Drawing::Font(L"Georgia", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_right->ForeColor = System::Drawing::Color::Silver;
			this->btn_right->Location = System::Drawing::Point(416, 90);
			this->btn_right->Name = L"btn_right";
			this->btn_right->Size = System::Drawing::Size(78, 31);
			this->btn_right->TabIndex = 4;
			this->btn_right->Text = L"K";
			this->btn_right->UseVisualStyleBackColor = false;
			this->btn_right->Click += gcnew System::EventHandler(this, &settingForm::btn_click);
			this->btn_right->MouseEnter += gcnew System::EventHandler(this, &settingForm::btn_enter);
			this->btn_right->MouseLeave += gcnew System::EventHandler(this, &settingForm::btn_leave);
			// 
			// btn_up
			// 
			this->btn_up->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->btn_up->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_up->Font = (gcnew System::Drawing::Font(L"Georgia", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_up->ForeColor = System::Drawing::Color::Silver;
			this->btn_up->Location = System::Drawing::Point(292, 90);
			this->btn_up->Name = L"btn_up";
			this->btn_up->Size = System::Drawing::Size(78, 31);
			this->btn_up->TabIndex = 3;
			this->btn_up->Text = L"J";
			this->btn_up->UseVisualStyleBackColor = false;
			this->btn_up->Click += gcnew System::EventHandler(this, &settingForm::btn_click);
			this->btn_up->MouseEnter += gcnew System::EventHandler(this, &settingForm::btn_enter);
			this->btn_up->MouseLeave += gcnew System::EventHandler(this, &settingForm::btn_leave);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(412, 206);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(132, 100);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &settingForm::pictureBox1_Click);
			// 
			// lbl_msg
			// 
			this->lbl_msg->AutoSize = true;
			this->lbl_msg->BackColor = System::Drawing::Color::Transparent;
			this->lbl_msg->ForeColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->lbl_msg->Location = System::Drawing::Point(39, 261);
			this->lbl_msg->Name = L"lbl_msg";
			this->lbl_msg->Size = System::Drawing::Size(122, 21);
			this->lbl_msg->TabIndex = 0;
			this->lbl_msg->Text = L"請輸入小寫字母";
			// 
			// settingForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 21);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(544, 306);
			this->Controls->Add(this->lbl_msg);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->btn_up);
			this->Controls->Add(this->btn_right);
			this->Controls->Add(this->btn_down);
			this->Controls->Add(this->btn_left);
			this->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(136)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(5);
			this->Name = L"settingForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Setting";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: System::Void btn_click(System::Object^  sender, System::EventArgs^  e){
		Button^ clickButton = safe_cast<Button^>(sender);
		for (int i = 0; i < 4; i++){
			fourBtn[i]->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			fourBtn[i]->ForeColor = System::Drawing::Color::Silver;
			if (clickButton == fourBtn[i]){
				selectBtn = true;
				setButton = i;
				fourBtn[setButton]->BackColor = System::Drawing::SystemColors::HotTrack;
				this->KeyPreview = true;
			}
		}
		this->lbl_msg->ForeColor = System::Drawing::SystemColors::InactiveCaptionText;
		return;
	}
	private: System::Void btn_enter(System::Object^  sender, System::EventArgs^  e) {
		Button^ thisButton = safe_cast<Button^>(sender);
		if (!selectBtn){
			thisButton->BackColor = System::Drawing::Color::Gold;
			thisButton->ForeColor = System::Drawing::Color::Black;
		}
		player->SoundLocation = ".\\spinnerbonus.wav";
		player->Load();
		player->Play();
	}
	private: System::Void btn_leave(System::Object^  sender, System::EventArgs^  e) {
		Button^ thisButton = safe_cast<Button^>(sender);
		if (!selectBtn){
			thisButton->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			thisButton->ForeColor = System::Drawing::Color::Silver;
		}
	}

	private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
		player->SoundLocation = ".\\menuback.wav";
		player->Load();
		player->Play();
		this->Close();
	}
	void settingForm_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		char type = e->KeyChar;
		if (selectBtn){
			for (int i = 0; i < 4; i++){
				if ((*key[i]) == type){
					if (i == setButton){
						fourBtn[setButton]->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
						selectBtn = false;
						this->KeyPreview = false;
					}
					else{
						fourBtn[setButton]->BackColor = System::Drawing::Color::Red;
						fourBtn[i]->BackColor = System::Drawing::Color::Red;
					}
					return;
				}
				else{
					fourBtn[i]->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
					fourBtn[i]->ForeColor = System::Drawing::Color::Silver;
				}
			}
			(*key[setButton]) = type;
			int i = type - 'a';
			if (i < 26 && i >= 0){
				fourBtn[setButton]->Text = en->Substring(i, 1)->ToUpper();
				selectBtn = false;
				this->KeyPreview = false;
				return;
			}
			else{
				lbl_msg->ForeColor = System::Drawing::Color::Red;
			}
			
		}
		else
			return;
	}
};
}

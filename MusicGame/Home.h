#pragma once
#include "MyForm.h"
#include "TestForm.h"
#include "settingForm.h"
#include "AboutForm1.h"

namespace MusicGame {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Home 的摘要
	/// </summary>
	public ref class Home : public System::Windows::Forms::Form
	{
	public:
		System::Media::SoundPlayer^ player = gcnew System::Media::SoundPlayer();
		char ^left = gcnew char('d'), 
			^down = gcnew char('f'),
			^up = gcnew char('j'),
			^right = gcnew char('k');

		Home(void)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//

			this->StartPosition = FormStartPosition::CenterScreen;
			this->Cursor = gcnew System::Windows::Forms::Cursor(".\\cursor.ico");
			
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~Home()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  Start;
	private: System::Windows::Forms::Button^  Edit;
	private: System::Windows::Forms::Button^  Setting;
	private: System::Windows::Forms::Button^  Exit;
	private: System::Windows::Forms::Button^  About;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Home::typeid));
			this->Start = (gcnew System::Windows::Forms::Button());
			this->Edit = (gcnew System::Windows::Forms::Button());
			this->Setting = (gcnew System::Windows::Forms::Button());
			this->Exit = (gcnew System::Windows::Forms::Button());
			this->About = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Start
			// 
			this->Start->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Start.BackgroundImage")));
			this->Start->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Start->FlatAppearance->BorderColor = System::Drawing::Color::Yellow;
			this->Start->FlatAppearance->BorderSize = 0;
			this->Start->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Start->Font = (gcnew System::Drawing::Font(L"標楷體", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(136)));
			this->Start->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->Start->Location = System::Drawing::Point(202, 137);
			this->Start->Name = L"Start";
			this->Start->Size = System::Drawing::Size(109, 36);
			this->Start->TabIndex = 0;
			this->Start->Text = L"Start";
			this->Start->UseVisualStyleBackColor = true;
			this->Start->Click += gcnew System::EventHandler(this, &Home::Start_Click);
			this->Start->MouseEnter += gcnew System::EventHandler(this, &Home::btn_enter);
			this->Start->MouseLeave += gcnew System::EventHandler(this, &Home::btn_leave);
			// 
			// Edit
			// 
			this->Edit->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Edit.BackgroundImage")));
			this->Edit->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Edit->FlatAppearance->BorderColor = System::Drawing::Color::Yellow;
			this->Edit->FlatAppearance->BorderSize = 0;
			this->Edit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Edit->Font = (gcnew System::Drawing::Font(L"標楷體", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(136)));
			this->Edit->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->Edit->Location = System::Drawing::Point(202, 188);
			this->Edit->Name = L"Edit";
			this->Edit->Size = System::Drawing::Size(109, 36);
			this->Edit->TabIndex = 1;
			this->Edit->Text = L"Edit";
			this->Edit->UseVisualStyleBackColor = true;
			this->Edit->Click += gcnew System::EventHandler(this, &Home::Edit_Click);
			this->Edit->MouseEnter += gcnew System::EventHandler(this, &Home::btn_enter);
			this->Edit->MouseLeave += gcnew System::EventHandler(this, &Home::btn_leave);
			// 
			// Setting
			// 
			this->Setting->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Setting.BackgroundImage")));
			this->Setting->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Setting->FlatAppearance->BorderColor = System::Drawing::Color::Yellow;
			this->Setting->FlatAppearance->BorderSize = 0;
			this->Setting->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Setting->Font = (gcnew System::Drawing::Font(L"標楷體", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(136)));
			this->Setting->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->Setting->Location = System::Drawing::Point(202, 239);
			this->Setting->Name = L"Setting";
			this->Setting->Size = System::Drawing::Size(109, 36);
			this->Setting->TabIndex = 2;
			this->Setting->Text = L"Setting";
			this->Setting->UseVisualStyleBackColor = true;
			this->Setting->Click += gcnew System::EventHandler(this, &Home::Setting_Click);
			this->Setting->MouseEnter += gcnew System::EventHandler(this, &Home::btn_enter);
			this->Setting->MouseLeave += gcnew System::EventHandler(this, &Home::btn_leave);
			// 
			// Exit
			// 
			this->Exit->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Exit.BackgroundImage")));
			this->Exit->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Exit->FlatAppearance->BorderColor = System::Drawing::Color::Yellow;
			this->Exit->FlatAppearance->BorderSize = 0;
			this->Exit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Exit->Font = (gcnew System::Drawing::Font(L"標楷體", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(136)));
			this->Exit->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->Exit->Location = System::Drawing::Point(202, 345);
			this->Exit->Name = L"Exit";
			this->Exit->Size = System::Drawing::Size(109, 36);
			this->Exit->TabIndex = 3;
			this->Exit->Text = L"Exit";
			this->Exit->UseVisualStyleBackColor = true;
			this->Exit->Click += gcnew System::EventHandler(this, &Home::Exit_Click);
			this->Exit->MouseEnter += gcnew System::EventHandler(this, &Home::btn_enter);
			this->Exit->MouseLeave += gcnew System::EventHandler(this, &Home::btn_leave);
			// 
			// About
			// 
			this->About->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"About.BackgroundImage")));
			this->About->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->About->FlatAppearance->BorderColor = System::Drawing::Color::Yellow;
			this->About->FlatAppearance->BorderSize = 0;
			this->About->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->About->Font = (gcnew System::Drawing::Font(L"標楷體", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(136)));
			this->About->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->About->Location = System::Drawing::Point(202, 290);
			this->About->Name = L"About";
			this->About->Size = System::Drawing::Size(109, 40);
			this->About->TabIndex = 4;
			this->About->Text = L"About";
			this->About->UseVisualStyleBackColor = true;
			this->About->Click += gcnew System::EventHandler(this, &Home::About_Click);
			this->About->MouseEnter += gcnew System::EventHandler(this, &Home::btn_enter);
			this->About->MouseLeave += gcnew System::EventHandler(this, &Home::btn_leave);
			// 
			// Home
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(522, 394);
			this->Controls->Add(this->About);
			this->Controls->Add(this->Exit);
			this->Controls->Add(this->Setting);
			this->Controls->Add(this->Edit);
			this->Controls->Add(this->Start);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Home";
			this->Text = L"Home";
			this->Load += gcnew System::EventHandler(this, &Home::Home_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Start_Click(System::Object^  sender, System::EventArgs^  e) {
		player->SoundLocation = ".\\menuhit.wav";
		player->Load();
		player->Play();
		this->Visible = false;
		MyForm^ dlg = gcnew MyForm(left, down, up, right);
		dlg->ShowDialog();
		this->Visible = true;
	}
	private: System::Void btn_enter(System::Object^  sender, System::EventArgs^  e) {
		Button^ thisButton = safe_cast<Button^>(sender);
		thisButton->FlatAppearance->BorderSize = 2;
		player->SoundLocation = ".\\spinnerbonus.wav";
		player->Load();
		player->Play();
	}
	private: System::Void btn_leave(System::Object^  sender, System::EventArgs^  e) {
		Button^ thisButton = safe_cast<Button^>(sender);
		thisButton->FlatAppearance->BorderSize = 0;
	}
	private: System::Void Edit_Click(System::Object^  sender, System::EventArgs^  e) {
		player->SoundLocation = ".\\menuhit.wav";
		player->Load();
		player->Play();
		this->Visible = false;
		TestForm dlg;
		dlg.ShowDialog();
		this->Visible = true;

	}
	private: System::Void Exit_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}
	private: System::Void Setting_Click(System::Object^  sender, System::EventArgs^  e) {
		player->SoundLocation = ".\\menuhit.wav";
		player->Load();
		player->Play();
		this->Hide();
		settingForm^ dlg = gcnew settingForm(left, down, up, right);
		dlg->ShowDialog();
		this->Show();
	}
	private: System::Void About_Click(System::Object^  sender, System::EventArgs^  e) {
		player->SoundLocation = ".\\menuhit.wav";
		player->Load();
		player->Play();
		this->Hide();
		AboutForm1 dlg;
		dlg.ShowDialog();
		this->Show();
	}
private: System::Void Home_Load(System::Object^  sender, System::EventArgs^  e) {
}
};
}

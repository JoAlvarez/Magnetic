#include < cstdlib >
#include < iostream >
#include < string >
#include < windows.h >
#include < shellapi.h >
#include < Tchar.h>
using namespace std;

#pragma once


namespace MageneticEditorTools {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	// GLOBAL VARIABLES
	string currentType;
	bool editorLoadSuccess = false;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}

			if ( editorLoadSuccess )
				this->editorWindow->CloseMainWindow();
		}
	internal: System::Windows::Forms::ToolStripMenuItem^  ClearToolStripMenuItem;
	protected: 
	internal: System::Windows::Forms::Button^  btnCancel;
	internal: System::Windows::Forms::ToolStripMenuItem^  menuBar;
	internal: System::Windows::Forms::ToolStripMenuItem^  NewLevelToolStripMenuItem;

	internal: System::Windows::Forms::ToolStripMenuItem^  OpenLevelToolStripMenuItem;
	internal: System::Windows::Forms::ToolStripMenuItem^  SaveLevelToolStripMenuItem;
	internal: System::Windows::Forms::ToolStripMenuItem^  SaveLevelAsToolStripMenuItem;

	internal: System::Windows::Forms::ToolStripMenuItem^  ExitToolStripMenuItem;

	internal: System::Windows::Forms::ToolStripMenuItem^  EditorModeToolStripMenuItem;
	internal: System::Windows::Forms::ToolStripMenuItem^  basicMode;
	internal: System::Windows::Forms::ToolStripMenuItem^  advancedMode;
	internal: System::Windows::Forms::Label^  lblAdvanced;
	internal: System::Windows::Forms::NumericUpDown^  openSpeed;
	internal: System::Windows::Forms::Label^  lblOpenSpeed;
	internal: System::Windows::Forms::NumericUpDown^  mass;
	internal: System::Windows::Forms::Label^  lblMass;
	internal: System::Windows::Forms::ComboBox^  destructible;
	internal: System::Windows::Forms::Label^  lblDirection;
	internal: System::Windows::Forms::Button^  btnApply;
	internal: System::Windows::Forms::ToolStripMenuItem^  PlayToolStripMenuItem;
	internal: System::Windows::Forms::ComboBox^  direction;
	internal: System::Windows::Forms::NumericUpDown^  closeSpeed;
	internal: System::Windows::Forms::Label^  lblCloseSpeed;
	internal: System::Windows::Forms::ToolStripMenuItem^  AboutToolStripMenuItem;
	internal: System::Windows::Forms::Label^  lblDestructible;
	internal: System::Windows::Forms::NumericUpDown^  radius;
	internal: System::Windows::Forms::Label^  lblRadius;
	internal: System::Windows::Forms::NumericUpDown^  health;
	internal: System::Windows::Forms::ToolStripMenuItem^  HowToToolStripMenuItem;
	internal: System::Windows::Forms::Label^  lblHealth;
	internal: System::Windows::Forms::ToolStripMenuItem^  AboutToolStripMenuItem1;
	internal: System::Windows::Forms::ComboBox^  polarity;
	internal: System::Windows::Forms::ToolStripMenuItem^  CurrentLevelToolStripMenuItem;
	internal: System::Windows::Forms::Label^  lblPolarity;
	internal: System::Windows::Forms::NumericUpDown^  strength;
	internal: System::Windows::Forms::Label^  lblStrength;
	internal: System::Windows::Forms::TextBox^  txtName;
	internal: System::Windows::Forms::Label^  lblName;
	internal: System::Windows::Forms::Label^  Label2;
	internal: System::Windows::Forms::ToolTip^  ToolTip1;
	internal: System::Windows::Forms::Button^  btnButton;
	internal: System::Windows::Forms::Button^  btnDoor;
	internal: System::Windows::Forms::Button^  btnMagnet;
	internal: System::Windows::Forms::Button^  btnBall;
	internal: System::Windows::Forms::Button^  btnBumper;
	internal: System::Windows::Forms::Button^  btnWall;
	internal: System::Windows::Forms::Label^  Label1;
	internal: System::Windows::Forms::MenuStrip^  MenuStrip1;
	private: System::Windows::Forms::OpenFileDialog^  openFile;
	internal: 
	private: System::Windows::Forms::SaveFileDialog^  saveFile;
	private: System::Diagnostics::Process^  editorWindow;


	private: System::ComponentModel::IContainer^  components;
	internal: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

		
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->ClearToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->menuBar = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->NewLevelToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->OpenLevelToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->SaveLevelToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->SaveLevelAsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ExitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->EditorModeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->basicMode = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->advancedMode = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lblAdvanced = (gcnew System::Windows::Forms::Label());
			this->openSpeed = (gcnew System::Windows::Forms::NumericUpDown());
			this->lblOpenSpeed = (gcnew System::Windows::Forms::Label());
			this->mass = (gcnew System::Windows::Forms::NumericUpDown());
			this->lblMass = (gcnew System::Windows::Forms::Label());
			this->destructible = (gcnew System::Windows::Forms::ComboBox());
			this->lblDirection = (gcnew System::Windows::Forms::Label());
			this->btnApply = (gcnew System::Windows::Forms::Button());
			this->PlayToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->direction = (gcnew System::Windows::Forms::ComboBox());
			this->closeSpeed = (gcnew System::Windows::Forms::NumericUpDown());
			this->lblCloseSpeed = (gcnew System::Windows::Forms::Label());
			this->AboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lblDestructible = (gcnew System::Windows::Forms::Label());
			this->radius = (gcnew System::Windows::Forms::NumericUpDown());
			this->lblRadius = (gcnew System::Windows::Forms::Label());
			this->health = (gcnew System::Windows::Forms::NumericUpDown());
			this->HowToToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lblHealth = (gcnew System::Windows::Forms::Label());
			this->AboutToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->polarity = (gcnew System::Windows::Forms::ComboBox());
			this->CurrentLevelToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lblPolarity = (gcnew System::Windows::Forms::Label());
			this->strength = (gcnew System::Windows::Forms::NumericUpDown());
			this->lblStrength = (gcnew System::Windows::Forms::Label());
			this->txtName = (gcnew System::Windows::Forms::TextBox());
			this->lblName = (gcnew System::Windows::Forms::Label());
			this->Label2 = (gcnew System::Windows::Forms::Label());
			this->ToolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->btnButton = (gcnew System::Windows::Forms::Button());
			this->btnDoor = (gcnew System::Windows::Forms::Button());
			this->btnMagnet = (gcnew System::Windows::Forms::Button());
			this->btnBall = (gcnew System::Windows::Forms::Button());
			this->btnBumper = (gcnew System::Windows::Forms::Button());
			this->btnWall = (gcnew System::Windows::Forms::Button());
			this->Label1 = (gcnew System::Windows::Forms::Label());
			this->MenuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->openFile = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFile = (gcnew System::Windows::Forms::SaveFileDialog());
			this->editorWindow = (gcnew System::Diagnostics::Process());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->openSpeed))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mass))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->closeSpeed))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->radius))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->health))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->strength))->BeginInit();
			this->MenuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// ClearToolStripMenuItem
			// 
			this->ClearToolStripMenuItem->BackColor = System::Drawing::SystemColors::WindowText;
			this->ClearToolStripMenuItem->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->ClearToolStripMenuItem->Name = L"ClearToolStripMenuItem";
			this->ClearToolStripMenuItem->Size = System::Drawing::Size(139, 22);
			this->ClearToolStripMenuItem->Text = L"Clear Level";
			// 
			// btnCancel
			// 
			this->btnCancel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btnCancel.BackgroundImage")));
			this->btnCancel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnCancel->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnCancel->Location = System::Drawing::Point(94, 548);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(74, 28);
			this->btnCancel->TabIndex = 17;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &Form1::btnCancel_Click);
			// 
			// menuBar
			// 
			this->menuBar->BackColor = System::Drawing::SystemColors::WindowText;
			this->menuBar->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {this->NewLevelToolStripMenuItem, 
				this->OpenLevelToolStripMenuItem, this->SaveLevelToolStripMenuItem, this->SaveLevelAsToolStripMenuItem, this->ExitToolStripMenuItem});
			this->menuBar->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->menuBar->Name = L"menuBar";
			this->menuBar->Size = System::Drawing::Size(37, 20);
			this->menuBar->Text = L"File";
			// 
			// NewLevelToolStripMenuItem
			// 
			this->NewLevelToolStripMenuItem->BackColor = System::Drawing::SystemColors::WindowText;
			this->NewLevelToolStripMenuItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->NewLevelToolStripMenuItem->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->NewLevelToolStripMenuItem->Name = L"NewLevelToolStripMenuItem";
			this->NewLevelToolStripMenuItem->Size = System::Drawing::Size(144, 22);
			this->NewLevelToolStripMenuItem->Text = L"New Level";
			// 
			// OpenLevelToolStripMenuItem
			// 
			this->OpenLevelToolStripMenuItem->BackColor = System::Drawing::SystemColors::WindowText;
			this->OpenLevelToolStripMenuItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->OpenLevelToolStripMenuItem->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->OpenLevelToolStripMenuItem->Name = L"OpenLevelToolStripMenuItem";
			this->OpenLevelToolStripMenuItem->Size = System::Drawing::Size(144, 22);
			this->OpenLevelToolStripMenuItem->Text = L"Open Level";
			this->OpenLevelToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::OpenLevelToolStripMenuItem_Click);
			// 
			// SaveLevelToolStripMenuItem
			// 
			this->SaveLevelToolStripMenuItem->BackColor = System::Drawing::SystemColors::MenuText;
			this->SaveLevelToolStripMenuItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->SaveLevelToolStripMenuItem->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->SaveLevelToolStripMenuItem->Name = L"SaveLevelToolStripMenuItem";
			this->SaveLevelToolStripMenuItem->Size = System::Drawing::Size(144, 22);
			this->SaveLevelToolStripMenuItem->Text = L"Save Level";
			this->SaveLevelToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::SaveLevelToolStripMenuItem_Click);
			// 
			// SaveLevelAsToolStripMenuItem
			// 
			this->SaveLevelAsToolStripMenuItem->BackColor = System::Drawing::SystemColors::WindowText;
			this->SaveLevelAsToolStripMenuItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->SaveLevelAsToolStripMenuItem->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->SaveLevelAsToolStripMenuItem->Name = L"SaveLevelAsToolStripMenuItem";
			this->SaveLevelAsToolStripMenuItem->Size = System::Drawing::Size(144, 22);
			this->SaveLevelAsToolStripMenuItem->Text = L"Save Level As";
			// 
			// ExitToolStripMenuItem
			// 
			this->ExitToolStripMenuItem->BackColor = System::Drawing::SystemColors::WindowText;
			this->ExitToolStripMenuItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->ExitToolStripMenuItem->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->ExitToolStripMenuItem->Name = L"ExitToolStripMenuItem";
			this->ExitToolStripMenuItem->Size = System::Drawing::Size(144, 22);
			this->ExitToolStripMenuItem->Text = L"Exit";
			this->ExitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::ExitToolStripMenuItem_Click);
			// 
			// EditorModeToolStripMenuItem
			// 
			this->EditorModeToolStripMenuItem->BackColor = System::Drawing::SystemColors::WindowText;
			this->EditorModeToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->basicMode, 
				this->advancedMode});
			this->EditorModeToolStripMenuItem->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->EditorModeToolStripMenuItem->Name = L"EditorModeToolStripMenuItem";
			this->EditorModeToolStripMenuItem->Size = System::Drawing::Size(139, 22);
			this->EditorModeToolStripMenuItem->Text = L"Editor Mode";
			// 
			// basicMode
			// 
			this->basicMode->BackColor = System::Drawing::SystemColors::WindowText;
			this->basicMode->Checked = true;
			this->basicMode->CheckState = System::Windows::Forms::CheckState::Checked;
			this->basicMode->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->basicMode->Name = L"basicMode";
			this->basicMode->Size = System::Drawing::Size(127, 22);
			this->basicMode->Text = L"Basic";
			this->basicMode->Click += gcnew System::EventHandler(this, &Form1::basicMode_Click);
			// 
			// advancedMode
			// 
			this->advancedMode->BackColor = System::Drawing::SystemColors::WindowText;
			this->advancedMode->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->advancedMode->Name = L"advancedMode";
			this->advancedMode->Size = System::Drawing::Size(127, 22);
			this->advancedMode->Text = L"Advanced";
			this->advancedMode->Click += gcnew System::EventHandler(this, &Form1::advancedMode_Click);
			// 
			// lblAdvanced
			// 
			this->lblAdvanced->AutoSize = true;
			this->lblAdvanced->BackColor = System::Drawing::Color::Transparent;
			this->lblAdvanced->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblAdvanced->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->lblAdvanced->Location = System::Drawing::Point(9, 371);
			this->lblAdvanced->Name = L"lblAdvanced";
			this->lblAdvanced->Size = System::Drawing::Size(114, 25);
			this->lblAdvanced->TabIndex = 31;
			this->lblAdvanced->Text = L"Advanced ";
			this->lblAdvanced->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// openSpeed
			// 
			this->openSpeed->BackColor = System::Drawing::SystemColors::Window;
			this->openSpeed->Location = System::Drawing::Point(105, 491);
			this->openSpeed->Name = L"openSpeed";
			this->openSpeed->Size = System::Drawing::Size(63, 20);
			this->openSpeed->TabIndex = 14;
			// 
			// lblOpenSpeed
			// 
			this->lblOpenSpeed->AutoSize = true;
			this->lblOpenSpeed->BackColor = System::Drawing::Color::Transparent;
			this->lblOpenSpeed->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblOpenSpeed->Location = System::Drawing::Point(11, 491);
			this->lblOpenSpeed->Name = L"lblOpenSpeed";
			this->lblOpenSpeed->Size = System::Drawing::Size(84, 16);
			this->lblOpenSpeed->TabIndex = 31;
			this->lblOpenSpeed->Text = L"Open Speed:";
			// 
			// mass
			// 
			this->mass->BackColor = System::Drawing::SystemColors::Window;
			this->mass->Location = System::Drawing::Point(69, 459);
			this->mass->Name = L"mass";
			this->mass->Size = System::Drawing::Size(99, 20);
			this->mass->TabIndex = 13;
			// 
			// lblMass
			// 
			this->lblMass->AutoSize = true;
			this->lblMass->BackColor = System::Drawing::Color::Transparent;
			this->lblMass->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblMass->Location = System::Drawing::Point(11, 459);
			this->lblMass->Name = L"lblMass";
			this->lblMass->Size = System::Drawing::Size(44, 16);
			this->lblMass->TabIndex = 31;
			this->lblMass->Text = L"Mass:";
			// 
			// destructible
			// 
			this->destructible->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->destructible->FormattingEnabled = true;
			this->destructible->ItemHeight = 13;
			this->destructible->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"Yes", L"No"});
			this->destructible->Location = System::Drawing::Point(98, 429);
			this->destructible->Name = L"destructible";
			this->destructible->Size = System::Drawing::Size(70, 21);
			this->destructible->TabIndex = 12;
			// 
			// lblDirection
			// 
			this->lblDirection->AutoSize = true;
			this->lblDirection->BackColor = System::Drawing::Color::Transparent;
			this->lblDirection->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblDirection->Location = System::Drawing::Point(11, 313);
			this->lblDirection->Name = L"lblDirection";
			this->lblDirection->Size = System::Drawing::Size(63, 16);
			this->lblDirection->TabIndex = 31;
			this->lblDirection->Text = L"Direction:";
			// 
			// btnApply
			// 
			this->btnApply->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btnApply.BackgroundImage")));
			this->btnApply->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnApply->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnApply->Location = System::Drawing::Point(14, 548);
			this->btnApply->Name = L"btnApply";
			this->btnApply->Size = System::Drawing::Size(74, 28);
			this->btnApply->TabIndex = 16;
			this->btnApply->Text = L"Apply";
			this->btnApply->UseVisualStyleBackColor = true;
			this->btnApply->Click += gcnew System::EventHandler(this, &Form1::btnApply_Click);
			// 
			// PlayToolStripMenuItem
			// 
			this->PlayToolStripMenuItem->BackColor = System::Drawing::SystemColors::WindowText;
			this->PlayToolStripMenuItem->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->PlayToolStripMenuItem->Name = L"PlayToolStripMenuItem";
			this->PlayToolStripMenuItem->Size = System::Drawing::Size(139, 22);
			this->PlayToolStripMenuItem->Text = L"Play Level";
			// 
			// direction
			// 
			this->direction->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->direction->FormattingEnabled = true;
			this->direction->ItemHeight = 13;
			this->direction->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"Up", L"Down", L"Left", L"Right"});
			this->direction->Location = System::Drawing::Point(75, 312);
			this->direction->Name = L"direction";
			this->direction->Size = System::Drawing::Size(93, 21);
			this->direction->TabIndex = 9;
			// 
			// closeSpeed
			// 
			this->closeSpeed->BackColor = System::Drawing::SystemColors::Window;
			this->closeSpeed->Location = System::Drawing::Point(105, 518);
			this->closeSpeed->Name = L"closeSpeed";
			this->closeSpeed->Size = System::Drawing::Size(63, 20);
			this->closeSpeed->TabIndex = 15;
			// 
			// lblCloseSpeed
			// 
			this->lblCloseSpeed->AutoSize = true;
			this->lblCloseSpeed->BackColor = System::Drawing::Color::Transparent;
			this->lblCloseSpeed->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblCloseSpeed->Location = System::Drawing::Point(11, 518);
			this->lblCloseSpeed->Name = L"lblCloseSpeed";
			this->lblCloseSpeed->Size = System::Drawing::Size(86, 16);
			this->lblCloseSpeed->TabIndex = 31;
			this->lblCloseSpeed->Text = L"Close Speed:";
			// 
			// AboutToolStripMenuItem
			// 
			this->AboutToolStripMenuItem->BackColor = System::Drawing::SystemColors::WindowText;
			this->AboutToolStripMenuItem->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->AboutToolStripMenuItem->Name = L"AboutToolStripMenuItem";
			this->AboutToolStripMenuItem->Size = System::Drawing::Size(116, 22);
			this->AboutToolStripMenuItem->Text = L"About";
			// 
			// lblDestructible
			// 
			this->lblDestructible->AutoSize = true;
			this->lblDestructible->BackColor = System::Drawing::Color::Transparent;
			this->lblDestructible->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblDestructible->Location = System::Drawing::Point(11, 434);
			this->lblDestructible->Name = L"lblDestructible";
			this->lblDestructible->Size = System::Drawing::Size(81, 16);
			this->lblDestructible->TabIndex = 31;
			this->lblDestructible->Text = L"Destructible:";
			// 
			// radius
			// 
			this->radius->BackColor = System::Drawing::SystemColors::Window;
			this->radius->Location = System::Drawing::Point(69, 281);
			this->radius->Name = L"radius";
			this->radius->Size = System::Drawing::Size(99, 20);
			this->radius->TabIndex = 8;
			// 
			// lblRadius
			// 
			this->lblRadius->AutoSize = true;
			this->lblRadius->BackColor = System::Drawing::Color::Transparent;
			this->lblRadius->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblRadius->Location = System::Drawing::Point(11, 281);
			this->lblRadius->Name = L"lblRadius";
			this->lblRadius->Size = System::Drawing::Size(52, 16);
			this->lblRadius->TabIndex = 31;
			this->lblRadius->Text = L"Radius:";
			// 
			// health
			// 
			this->health->BackColor = System::Drawing::SystemColors::Window;
			this->health->Location = System::Drawing::Point(69, 402);
			this->health->Name = L"health";
			this->health->Size = System::Drawing::Size(99, 20);
			this->health->TabIndex = 11;
			// 
			// HowToToolStripMenuItem
			// 
			this->HowToToolStripMenuItem->BackColor = System::Drawing::SystemColors::WindowText;
			this->HowToToolStripMenuItem->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->HowToToolStripMenuItem->Name = L"HowToToolStripMenuItem";
			this->HowToToolStripMenuItem->Size = System::Drawing::Size(116, 22);
			this->HowToToolStripMenuItem->Text = L"How To";
			// 
			// lblHealth
			// 
			this->lblHealth->AutoSize = true;
			this->lblHealth->BackColor = System::Drawing::Color::Transparent;
			this->lblHealth->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblHealth->Location = System::Drawing::Point(11, 406);
			this->lblHealth->Name = L"lblHealth";
			this->lblHealth->Size = System::Drawing::Size(49, 16);
			this->lblHealth->TabIndex = 31;
			this->lblHealth->Text = L"Health:";
			// 
			// AboutToolStripMenuItem1
			// 
			this->AboutToolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->HowToToolStripMenuItem, 
				this->AboutToolStripMenuItem});
			this->AboutToolStripMenuItem1->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->AboutToolStripMenuItem1->Name = L"AboutToolStripMenuItem1";
			this->AboutToolStripMenuItem1->Size = System::Drawing::Size(44, 20);
			this->AboutToolStripMenuItem1->Text = L"Help";
			// 
			// polarity
			// 
			this->polarity->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->polarity->FormattingEnabled = true;
			this->polarity->ItemHeight = 13;
			this->polarity->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"Negative ( - )", L"Neutral", L"Positive ( + )"});
			this->polarity->Location = System::Drawing::Point(69, 251);
			this->polarity->Name = L"polarity";
			this->polarity->Size = System::Drawing::Size(99, 21);
			this->polarity->TabIndex = 7;
			// 
			// CurrentLevelToolStripMenuItem
			// 
			this->CurrentLevelToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->PlayToolStripMenuItem, 
				this->ClearToolStripMenuItem, this->EditorModeToolStripMenuItem});
			this->CurrentLevelToolStripMenuItem->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->CurrentLevelToolStripMenuItem->Name = L"CurrentLevelToolStripMenuItem";
			this->CurrentLevelToolStripMenuItem->Size = System::Drawing::Size(50, 20);
			this->CurrentLevelToolStripMenuItem->Text = L"Editor";
			// 
			// lblPolarity
			// 
			this->lblPolarity->AutoSize = true;
			this->lblPolarity->BackColor = System::Drawing::Color::Transparent;
			this->lblPolarity->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblPolarity->Location = System::Drawing::Point(11, 252);
			this->lblPolarity->Name = L"lblPolarity";
			this->lblPolarity->Size = System::Drawing::Size(56, 16);
			this->lblPolarity->TabIndex = 31;
			this->lblPolarity->Text = L"Polarity:";
			// 
			// strength
			// 
			this->strength->BackColor = System::Drawing::SystemColors::Window;
			this->strength->Location = System::Drawing::Point(77, 339);
			this->strength->Name = L"strength";
			this->strength->Size = System::Drawing::Size(91, 20);
			this->strength->TabIndex = 10;
			// 
			// lblStrength
			// 
			this->lblStrength->AutoSize = true;
			this->lblStrength->BackColor = System::Drawing::Color::Transparent;
			this->lblStrength->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblStrength->Location = System::Drawing::Point(11, 339);
			this->lblStrength->Name = L"lblStrength";
			this->lblStrength->Size = System::Drawing::Size(61, 16);
			this->lblStrength->TabIndex = 31;
			this->lblStrength->Text = L"Strength:";
			// 
			// txtName
			// 
			this->txtName->Location = System::Drawing::Point(57, 224);
			this->txtName->MaxLength = 20;
			this->txtName->Name = L"txtName";
			this->txtName->Size = System::Drawing::Size(111, 20);
			this->txtName->TabIndex = 6;
			this->txtName->TextChanged += gcnew System::EventHandler(this, &Form1::txtName_TextChanged);
			// 
			// lblName
			// 
			this->lblName->AutoSize = true;
			this->lblName->BackColor = System::Drawing::Color::Transparent;
			this->lblName->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblName->Location = System::Drawing::Point(11, 228);
			this->lblName->Name = L"lblName";
			this->lblName->Size = System::Drawing::Size(46, 16);
			this->lblName->TabIndex = 31;
			this->lblName->Text = L"Name:";
			// 
			// Label2
			// 
			this->Label2->AutoSize = true;
			this->Label2->BackColor = System::Drawing::Color::Transparent;
			this->Label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Label2->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->Label2->Location = System::Drawing::Point(9, 191);
			this->Label2->Name = L"Label2";
			this->Label2->Size = System::Drawing::Size(110, 25);
			this->Label2->TabIndex = 31;
			this->Label2->Text = L"Properties";
			this->Label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// ToolTip1
			// 
			this->ToolTip1->AutoPopDelay = 5000;
			this->ToolTip1->InitialDelay = 1000;
			this->ToolTip1->IsBalloon = true;
			this->ToolTip1->ReshowDelay = 100;
			// 
			// btnButton
			// 
			this->btnButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btnButton.BackgroundImage")));
			this->btnButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnButton->Location = System::Drawing::Point(14, 102);
			this->btnButton->Name = L"btnButton";
			this->btnButton->Size = System::Drawing::Size(74, 35);
			this->btnButton->TabIndex = 2;
			this->btnButton->Text = L"Button";
			this->ToolTip1->SetToolTip(this->btnButton, L"Create a new Button.");
			this->btnButton->UseVisualStyleBackColor = true;
			this->btnButton->Click += gcnew System::EventHandler(this, &Form1::btnButton_Click);
			// 
			// btnDoor
			// 
			this->btnDoor->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btnDoor.BackgroundImage")));
			this->btnDoor->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnDoor->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnDoor->Location = System::Drawing::Point(94, 102);
			this->btnDoor->Name = L"btnDoor";
			this->btnDoor->Size = System::Drawing::Size(74, 35);
			this->btnDoor->TabIndex = 3;
			this->btnDoor->Text = L"Door";
			this->ToolTip1->SetToolTip(this->btnDoor, L"Create a new Door.");
			this->btnDoor->UseVisualStyleBackColor = true;
			this->btnDoor->Click += gcnew System::EventHandler(this, &Form1::btnDoor_Click);
			// 
			// btnMagnet
			// 
			this->btnMagnet->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btnMagnet.BackgroundImage")));
			this->btnMagnet->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnMagnet->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnMagnet->Location = System::Drawing::Point(14, 143);
			this->btnMagnet->Name = L"btnMagnet";
			this->btnMagnet->Size = System::Drawing::Size(74, 35);
			this->btnMagnet->TabIndex = 4;
			this->btnMagnet->Text = L"Magnet";
			this->ToolTip1->SetToolTip(this->btnMagnet, L"Create a new Magnet.");
			this->btnMagnet->UseVisualStyleBackColor = true;
			this->btnMagnet->Click += gcnew System::EventHandler(this, &Form1::btnMagnet_Click);
			// 
			// btnBall
			// 
			this->btnBall->BackColor = System::Drawing::Color::Transparent;
			this->btnBall->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btnBall.BackgroundImage")));
			this->btnBall->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnBall->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
			this->btnBall->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnBall->Location = System::Drawing::Point(14, 61);
			this->btnBall->Name = L"btnBall";
			this->btnBall->Size = System::Drawing::Size(74, 35);
			this->btnBall->TabIndex = 0;
			this->btnBall->Text = L"Ball";
			this->ToolTip1->SetToolTip(this->btnBall, L"Create a new Ball.");
			this->btnBall->UseVisualStyleBackColor = false;
			this->btnBall->Click += gcnew System::EventHandler(this, &Form1::btnBall_Click);
			// 
			// btnBumper
			// 
			this->btnBumper->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btnBumper.BackgroundImage")));
			this->btnBumper->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnBumper->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnBumper->Location = System::Drawing::Point(94, 61);
			this->btnBumper->Name = L"btnBumper";
			this->btnBumper->Size = System::Drawing::Size(74, 35);
			this->btnBumper->TabIndex = 1;
			this->btnBumper->Text = L"Bumper";
			this->ToolTip1->SetToolTip(this->btnBumper, L"Create a new Bumber.");
			this->btnBumper->UseVisualStyleBackColor = true;
			this->btnBumper->Click += gcnew System::EventHandler(this, &Form1::btnBumper_Click);
			// 
			// btnWall
			// 
			this->btnWall->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btnWall.BackgroundImage")));
			this->btnWall->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnWall->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
			this->btnWall->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnWall->Location = System::Drawing::Point(94, 143);
			this->btnWall->Name = L"btnWall";
			this->btnWall->Size = System::Drawing::Size(74, 35);
			this->btnWall->TabIndex = 5;
			this->btnWall->Text = L"Wall";
			this->ToolTip1->SetToolTip(this->btnWall, L"Create a new wall.");
			this->btnWall->UseVisualStyleBackColor = true;
			this->btnWall->Click += gcnew System::EventHandler(this, &Form1::btnWall_Click);
			// 
			// Label1
			// 
			this->Label1->AutoSize = true;
			this->Label1->BackColor = System::Drawing::Color::Transparent;
			this->Label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Label1->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->Label1->Location = System::Drawing::Point(9, 24);
			this->Label1->Name = L"Label1";
			this->Label1->Size = System::Drawing::Size(120, 25);
			this->Label1->TabIndex = 31;
			this->Label1->Text = L"Entity Type";
			this->Label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// MenuStrip1
			// 
			this->MenuStrip1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->MenuStrip1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->MenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->menuBar, this->CurrentLevelToolStripMenuItem, 
				this->AboutToolStripMenuItem1});
			this->MenuStrip1->LayoutStyle = System::Windows::Forms::ToolStripLayoutStyle::HorizontalStackWithOverflow;
			this->MenuStrip1->Location = System::Drawing::Point(0, 0);
			this->MenuStrip1->Name = L"MenuStrip1";
			this->MenuStrip1->Size = System::Drawing::Size(179, 24);
			this->MenuStrip1->TabIndex = 18;
			this->MenuStrip1->Text = L"MenuStrip1";
			// 
			// openFile
			// 
			this->openFile->Filter = L"Magnetic Custom Level|*.mclvl";
			this->openFile->Title = L"Open A Custom Level File";
			// 
			// saveFile
			// 
			this->saveFile->FileName = L"customLevel";
			this->saveFile->Filter = L"Magnetic Custom Level|.mclvl";
			this->saveFile->Title = L"Save Custom Level";
			// 
			// editorWindow
			// 
			this->editorWindow->StartInfo->Domain = L"";
			this->editorWindow->StartInfo->FileName = L"MagEditor.exe";
			this->editorWindow->StartInfo->LoadUserProfile = false;
			this->editorWindow->StartInfo->Password = nullptr;
			this->editorWindow->StartInfo->StandardErrorEncoding = nullptr;
			this->editorWindow->StartInfo->StandardOutputEncoding = nullptr;
			this->editorWindow->StartInfo->UserName = L"";
			this->editorWindow->StartInfo->Verb = L"open";
			this->editorWindow->StartInfo->WorkingDirectory = L"//";
			this->editorWindow->SynchronizingObject = this;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(179, 587);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->lblAdvanced);
			this->Controls->Add(this->openSpeed);
			this->Controls->Add(this->lblOpenSpeed);
			this->Controls->Add(this->mass);
			this->Controls->Add(this->lblMass);
			this->Controls->Add(this->destructible);
			this->Controls->Add(this->lblDirection);
			this->Controls->Add(this->btnApply);
			this->Controls->Add(this->direction);
			this->Controls->Add(this->closeSpeed);
			this->Controls->Add(this->lblCloseSpeed);
			this->Controls->Add(this->lblDestructible);
			this->Controls->Add(this->radius);
			this->Controls->Add(this->lblRadius);
			this->Controls->Add(this->health);
			this->Controls->Add(this->lblHealth);
			this->Controls->Add(this->polarity);
			this->Controls->Add(this->lblPolarity);
			this->Controls->Add(this->strength);
			this->Controls->Add(this->lblStrength);
			this->Controls->Add(this->txtName);
			this->Controls->Add(this->lblName);
			this->Controls->Add(this->Label2);
			this->Controls->Add(this->btnButton);
			this->Controls->Add(this->btnDoor);
			this->Controls->Add(this->btnMagnet);
			this->Controls->Add(this->btnBall);
			this->Controls->Add(this->btnBumper);
			this->Controls->Add(this->btnWall);
			this->Controls->Add(this->Label1);
			this->Controls->Add(this->MenuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"Form1";
			this->Text = L"Tool Box";
			this->TopMost = true;
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->openSpeed))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mass))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->closeSpeed))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->radius))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->health))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->strength))->EndInit();
			this->MenuStrip1->ResumeLayout(false);
			this->MenuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

private: System::Void basicMode_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 this->basicMode->Checked = true;
			 this->advancedMode->Checked = false;

			 // Disable Advanced Options
			 this->lblAdvanced->Visible = false;
			 this->lblHealth->Visible = false;
			 this->health->Visible = false;
			 this->lblDestructible->Visible = false;
			 this->destructible->Visible = false;
			 this->lblMass->Visible = false;
			 this->mass->Visible = false;
			 this->lblOpenSpeed->Visible = false;
			 this->openSpeed->Visible = false;
			 this->lblCloseSpeed->Visible = false;
			 this->closeSpeed->Visible = false;

			 if ( currentType == "WALL" )
				 this->strength->Enabled = false;

			 // Move Buttons
			 this->btnApply->Location = Point( this->btnApply->Location.X, 368 );
			 this->btnCancel->Location = Point( this->btnCancel->Location.X, 368 );

			 this->Height = 432;
			 this->Refresh();
		 }
private: System::Void advancedMode_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 this->advancedMode->Checked = true;
			 this->basicMode->Checked = false;

			 // Enable Advanced Options
			 this->lblAdvanced->Visible = true;
			 this->lblHealth->Visible = true;
			 this->health->Visible = true;
			 this->lblDestructible->Visible = true;
			 this->destructible->Visible = true;
			 this->lblMass->Visible = true;
			 this->mass->Visible = true;
			 this->lblOpenSpeed->Visible = true;
			 this->openSpeed->Visible = true;
			 this->lblCloseSpeed->Visible = true;
			 this->closeSpeed->Visible = true;

			 if ( currentType == "WALL" )
				 this->strength->Enabled = true;

			 // Move Buttons
			 this->btnApply->Location = Point( this->btnApply->Location.X, 548 );
			 this->btnCancel->Location = Point( this->btnCancel->Location.X, 548 );

			 this->Height = 620;
			 this->Refresh();
		 }
private: System::Void btnBall_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 currentType = "BALL";

			//Enable properties of this object
			this->txtName->Enabled = true;
			this->strength->Enabled = false;
			this->polarity->Enabled = true;
		    this->health->Enabled = false;
			this->radius->Enabled = true;
			this->destructible->Enabled = false;
			this->mass->Enabled = true;
			this->openSpeed->Enabled = false;
			this->closeSpeed->Enabled = false;
			this->direction->Enabled = false;

			// Set Focus On Name Text Box
			this->txtName->Focus();
		 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e)
		 {
			 currentType = "NONE";

			//Disable all properties
			this->txtName->Enabled = false;
			this->strength->Enabled = false;
			this->polarity->Enabled = false;
			this->health->Enabled = false;
			this->radius->Enabled = false;
			this->destructible->Enabled = false;
			this->mass->Enabled = false;
			this->openSpeed->Enabled = false;
			this->closeSpeed->Enabled = false;
			this->direction->Enabled = false;

			this->basicMode_Click( sender, e );

			editorLoadSuccess = this->editorWindow->Start();

		 }
private: System::Void txtName_TextChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
		 }
private: System::Void btnBumper_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
		     currentType = "BUMPER";

			 //Enable properties of this object
			 this->txtName->Enabled = true;
			 this->strength->Enabled = true;
			 this->polarity->Enabled = false;
			 this->health->Enabled = false;
			 this->radius->Enabled = true;
			 this->destructible->Enabled = false;
			 this->mass->Enabled = false;
			 this->openSpeed->Enabled = false;
			 this->closeSpeed->Enabled = false;
			 this->direction->Enabled = false;

			 // Set Focus On Name Text Box
			this->txtName->Focus();
		 }
private: System::Void btnButton_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			currentType = "BUTTON";

			//Enable properties of this object
			this->txtName->Enabled = true;
			this->strength->Enabled = false;
			this->polarity->Enabled = false;
			this->health->Enabled = false;
			this->radius->Enabled = false;
			this->destructible->Enabled = false;
			this->mass->Enabled = false;
			this->openSpeed->Enabled = false;
			this->closeSpeed->Enabled = false;
			this->direction->Enabled = true;

			// Set Focus On Name Text Box
			this->txtName->Focus();
		 }
private: System::Void btnDoor_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 currentType = "DOOR";

			//Enable properties of this object
			this->txtName->Enabled = true;
			this->strength->Enabled = false;
			this->polarity->Enabled = false;
			this->health->Enabled = false;
			this->radius->Enabled = false;
			this->destructible->Enabled = false;
			this->mass->Enabled = false;
			this->openSpeed->Enabled = true;
			this->closeSpeed->Enabled = true;
			this->direction->Enabled = false;

			// Set Focus On Name Text Box
			this->txtName->Focus();
		 }
private: System::Void btnMagnet_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 currentType = "MAGNET";

			//Enable properties of this object
			this->txtName->Enabled = true;
			this->strength->Enabled = false;
			this->polarity->Enabled = true;
			this->health->Enabled = false;
			this->radius->Enabled = true;
			this->destructible->Enabled = false;
			this->mass->Enabled = true;
			this->openSpeed->Enabled = false;
			this->closeSpeed->Enabled = false;
			this->direction->Enabled = false;

			// Set Focus On Name Text Box
			this->txtName->Focus();
		 }
private: System::Void btnWall_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 currentType = "WALL";

			//Enable properties of this object
			this->txtName->Enabled = true;

			if ( this->advancedMode->Checked == true )
				this->strength->Enabled = true;

			this->polarity->Enabled = false;
			this->health->Enabled = true;
			this->radius->Enabled = false;
			this->destructible->Enabled = true;
			this->mass->Enabled = false;
			this->openSpeed->Enabled = false;
			this->closeSpeed->Enabled = false;
			this->direction->Enabled = false;

			// Set Focus On Name Text Box
			this->txtName->Focus();
		 }
private: System::Void btnApply_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			// Record data

			// Send to editor

			// Reset Type
			 currentType = "NONE";

			//Disable all properties
			this->txtName->Enabled = false;
			this->strength->Enabled = false;
			this->polarity->Enabled = false;
			this->health->Enabled = false;
			this->radius->Enabled = false;
			this->destructible->Enabled = false;
			this->mass->Enabled = false;
			this->openSpeed->Enabled = false;
			this->closeSpeed->Enabled = false;
			this->direction->Enabled = false;

			//Reset all properties values
			this->txtName->Clear();
			this->strength->Value = 0;
			this->polarity->SelectedIndex = -1;
			this->health->Value = 0;
			this->radius->Value = 0;
			this->destructible->SelectedIndex = -1;
			this->mass->Value = 0;
			this->openSpeed->Value = 0;
			this->closeSpeed->Value = 0;
			this->direction->SelectedIndex = -1;
		 }
private: System::Void ExitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if ( editorLoadSuccess )
				this->editorWindow->CloseMainWindow();

			 this->Close();
		 }
private: System::Void btnCancel_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 currentType = "NONE";

			 //Reset all properties values
			this->txtName->Clear();
			this->strength->Value = 0;
			this->polarity->SelectedIndex = -1;
			this->health->Value = 0;
			this->radius->Value = 0;
			this->destructible->SelectedIndex = -1;
			this->mass->Value = 0;
			this->openSpeed->Value = 0;
			this->closeSpeed->Value = 0;
			this->direction->SelectedIndex = -1;

			//Disable all properties
			this->txtName->Enabled = false;
			this->strength->Enabled = false;
			this->polarity->Enabled = false;
			this->health->Enabled = false;
			this->radius->Enabled = false;
			this->destructible->Enabled = false;
			this->mass->Enabled = false;
			this->openSpeed->Enabled = false;
			this->closeSpeed->Enabled = false;
			this->direction->Enabled = false;
		 }
private: System::Void OpenLevelToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {			 
			 this->openFile->ShowDialog();
		 }
private: System::Void SaveLevelToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 this->saveFile->ShowDialog();
		 }

};
}


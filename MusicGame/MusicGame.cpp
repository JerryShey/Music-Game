// MusicGame.cpp: �D�n�M���ɡC

#include "stdafx.h"
#include "Home.h"

using namespace System;
using namespace MusicGame;

//for opening windows choose file dialog successsfully
[STAThread]
int main(array<System::String ^> ^args)
{
    Console::WriteLine(L"Hello World");
	Application::Run(gcnew Home());
    return 0;
}

//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("Project1.res");
USEFORM("Unit1.cpp", Form1);
USEFORM("Unit2.cpp", Frame2); /* TFrame: File Type */
USEFORM("Unit3.cpp", Frame3); /* TFrame: File Type */
USEFORM("Unit4.cpp", Frame4); /* TFrame: File Type */
USEFORM("Unit5.cpp", Frame5); /* TFrame: File Type */
USEFORM("Unit6.cpp", Frame6); /* TFrame: File Type */
USE("Project1.todo", ToDo);
USEFORM("Unit7.cpp", about);
USEFORM("Unit8.cpp", Frame8); /* TFrame: File Type */
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->Title = "TimeAttacker 1.0";
                 Application->HelpFile = "F:\\devellopez\\syst\\FONCTION.HLP";
                 Application->CreateForm(__classid(TForm1), &Form1);
                 Application->CreateForm(__classid(Tabout), &about);
                 Application->Run();
        }
        catch (Exception &exception)
        {

                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------

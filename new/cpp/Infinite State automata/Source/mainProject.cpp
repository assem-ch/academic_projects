//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("mainProject.res");
USEFORM("main.cpp", Form1);
USEFORM("trans.cpp", addtrans);
USEFORM("etat.cpp", addetat);
USEFORM("verify.cpp", verify);
USEFORM("Unit4.cpp", Form4);
USEFORM("about.cpp", about);
USE("mainProject.todo", ToDo);
USEFORM("Unit2.cpp", Form2);
USEFORM("addalphabet.cpp", Form3);
USEFORM("Unit5.cpp", Form5);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->HelpFile = "";
                 Application->Title = "WordAttacker v1.0";
                 Application->CreateForm(__classid(TForm1), &Form1);
                 Application->CreateForm(__classid(Taddtrans), &addtrans);
                 Application->CreateForm(__classid(Taddetat), &addetat);
                 Application->CreateForm(__classid(Tverify), &verify);
                 Application->CreateForm(__classid(TForm4), &Form4);
                 Application->CreateForm(__classid(Tabout), &about);
                 Application->CreateForm(__classid(TForm2), &Form2);
                 Application->CreateForm(__classid(TForm3), &Form3);
                 Application->CreateForm(__classid(TForm5), &Form5);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------

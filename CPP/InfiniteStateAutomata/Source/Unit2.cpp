//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "main.h"
#include "Unit2.h"
#include "parser.h"
using namespace std;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
string s="";
Node* n;


//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}


//---------------------------------------------------------------------------

void __fastcall TForm2::Button1Click(TObject *Sender)
{
s=Edit1->Text.c_str();
clean(s);
Edit1->Text=s.c_str();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button2Click(TObject *Sender)
{
s=Edit1->Text.c_str();
clean(s);
Edit1->Text="";
Edit1->Text=s.c_str();
n=new Node(s);
Form2->Close();
}
//---------------------------------------------------------------------------







//---------------------------------------------------------------------------






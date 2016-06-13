//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "verify.h"
#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tverify *verify;

//---------------------------------------------------------------------------



void __fastcall Tverify::Button3Click(TObject *Sender)
{
  Close();      
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

void __fastcall Tverify::FormShow(TObject *Sender)
{
Edit1->SetFocus();        
}
//---------------------------------------------------------------------------




void __fastcall Tverify::Edit1KeyPress(TObject *Sender, char &Key)
{
if (Key==13) Button2Click(Sender);        
}
//---------------------------------------------------------------------------


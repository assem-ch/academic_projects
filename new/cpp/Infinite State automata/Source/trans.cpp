//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "trans.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Taddtrans *addtrans;
//---------------------------------------------------------------------------
__fastcall Taddtrans::Taddtrans(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Taddtrans::OKClick(TObject *Sender)
{
   addtrans->Close();
}
//---------------------------------------------------------------------------

void __fastcall Taddtrans::Edit1KeyPress(TObject *Sender, char &Key)
{
 if (Key==13) addtrans->Close();
}
//---------------------------------------------------------------------------

void __fastcall Taddtrans::FormShow(TObject *Sender)
{
  ComboBox1->SetFocus();
        
}
//---------------------------------------------------------------------------



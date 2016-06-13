//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "etat.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Taddetat *addetat;

//---------------------------------------------------------------------------
__fastcall Taddetat::Taddetat(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall Taddetat::BitBtn1Click(TObject *Sender)
{
 addetat->Close();

}
//---------------------------------------------------------------------------

void __fastcall Taddetat::FormKeyPress(TObject *Sender, char &Key)
{
if (Key==13) addetat->Close();
}
//---------------------------------------------------------------------------




void __fastcall Taddetat::FormShow(TObject *Sender)
{ Edit1->Text="S"+IntToStr(cpt);

if (cpt==0) Initial->Checked=true;
else  Initial->Checked=false;
Edit1->SetFocus();
}
//---------------------------------------------------------------------------


void __fastcall Taddetat::FormClose(TObject *Sender, TCloseAction &Action)
{
if (Edit1->Text=="S"+IntToStr(cpt)) cpt++;
if (cpt==0) cpt++;
}
//---------------------------------------------------------------------------

void __fastcall Taddetat::FormCreate(TObject *Sender)
{
cpt=0;        
}
//---------------------------------------------------------------------------

void __fastcall Taddetat::SpeedButton1Click(TObject *Sender)
{
Initial->Checked=false;

}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
#include "about.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tabout *about;
//---------------------------------------------------------------------------
__fastcall Tabout::Tabout(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tabout::FormClose(TObject *Sender, TCloseAction &Action)
{
Form1->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall Tabout::Label9Click(TObject *Sender)
{
ShellExecute(Handle,"Open",PChar("mailto:Adrianshephard@maktoob.com \
        ?subject= About TimeAttacker "),NULL,NULL,SW_SHOWNORMAL);

}
//---------------------------------------------------------------------------

void __fastcall Tabout::Label10Click(TObject *Sender)
{
ShellExecute(Handle,"Open",PChar("mailto:Sof_ini@yahoo.fr \
        ?subject= About TimeAttacker "),NULL,NULL,SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------


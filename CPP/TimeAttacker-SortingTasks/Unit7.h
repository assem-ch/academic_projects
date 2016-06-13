//---------------------------------------------------------------------------

#ifndef Unit7H
#define Unit7H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class Tabout : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TImage *Image1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        TLabel *Label9;
        TLabel *Label10;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Label9Click(TObject *Sender);
        void __fastcall Label10Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Tabout(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tabout *about;
//---------------------------------------------------------------------------
#endif

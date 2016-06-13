//---------------------------------------------------------------------------

#ifndef UrecmotH
#define UrecmotH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class Tverify : public TForm
{
__published:	// IDE-managed Components
        TEdit *Edit1;
        TLabel *Label1;
        TButton *Button1;
        TLabel *Label2;
        TLabel *Label3;
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall Edit1KeyPress(TObject *Sender, char &Key);
private:	// User declarations
public:		// User declarations
        __fastcall Tverify(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tverify *verify;
//---------------------------------------------------------------------------
#endif

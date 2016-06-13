//---------------------------------------------------------------------------

#ifndef FtraH
#define FtraH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class Taddtrans : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TButton *OK;
        TComboBox *ComboBox1;
        TComboBox *ComboBox2;
        TLabel *Label2;
        TLabel *Label3;
        TComboBox *Edit1;
        void __fastcall OKClick(TObject *Sender);
        void __fastcall Edit1KeyPress(TObject *Sender, char &Key);
        void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Taddtrans(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Taddtrans *addtrans;
//---------------------------------------------------------------------------
#endif

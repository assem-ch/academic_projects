//---------------------------------------------------------------------------

#ifndef UetatH
#define UetatH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class Taddetat : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TEdit *Edit1;
        TBitBtn *BitBtn1;
        TCheckBox *Initial;
        TCheckBox *Final;
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall FormKeyPress(TObject *Sender, char &Key);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall SpeedButton1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Taddetat(TComponent* Owner);
        int cpt;
};
//---------------------------------------------------------------------------
extern PACKAGE Taddetat *addetat;
//---------------------------------------------------------------------------
#endif

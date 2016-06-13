//---------------------------------------------------------------------------


#ifndef Unit4H
#define Unit4H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TFrame4 : public TFrame
{
__published:	// IDE-managed Components
        TEdit *Edit1;
        TEdit *Edit2;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TEdit *Edit3;
        TLabel *Label4;
private:	// User declarations
public:		// User declarations
        __fastcall TFrame4(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrame4 *Frame4;
//---------------------------------------------------------------------------
#endif

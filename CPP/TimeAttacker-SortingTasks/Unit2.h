//---------------------------------------------------------------------------


#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TFrame2 : public TFrame
{
__published:	// IDE-managed Components
        TEdit *Edit1;
        TEdit *Edit2;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
private:	// User declarations
public:		// User declarations
        __fastcall TFrame2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrame2 *Frame2;
//---------------------------------------------------------------------------
#endif

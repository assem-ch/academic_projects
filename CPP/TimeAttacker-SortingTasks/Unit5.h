//---------------------------------------------------------------------------


#ifndef Unit5H
#define Unit5H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFrame5 : public TFrame
{
__published:	// IDE-managed Components
        TStringGrid *StringGrid1;
        TPanel *Panel1;
        TLabel *Label1;
private:	// User declarations
public:		// User declarations
        __fastcall TFrame5(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrame5 *Frame5;
//---------------------------------------------------------------------------
#endif

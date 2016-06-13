//---------------------------------------------------------------------------


#ifndef Unit8H
#define Unit8H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TFrame8 : public TFrame
{
__published:	// IDE-managed Components
        TStringGrid *StringGrid1;
        TPanel *Panel1;
        TLabel *Label1;
        TSpeedButton *SpeedButton2;
private:	// User declarations
public:		// User declarations
        __fastcall TFrame8(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrame8 *Frame8;
//---------------------------------------------------------------------------
#endif
 
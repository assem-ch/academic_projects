//---------------------------------------------------------------------------


#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFrame3 : public TFrame
{
__published:	// IDE-managed Components
        TStringGrid *StringGrid1;
        TPanel *Panel1;
        TLabel *Label1;
        TLabel *Label2;
        TPanel *Panel2;
        TSpeedButton *SpeedButton2;
private:	// User declarations
public:		// User declarations
        __fastcall TFrame3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrame3 *Frame3;
//---------------------------------------------------------------------------
#endif

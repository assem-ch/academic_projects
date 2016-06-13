//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ActnList.hpp>
#include <ComCtrls.hpp>
#include <ImgList.hpp>
#include <Menus.hpp>
#include <StdActns.hpp>
#include <ToolWin.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
#include "Unit5.h"
#include "Unit6.h"
#include <Dialogs.hpp>
#include "Unit8.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TPopupMenu *PopupMenu1;
        TActionList *ActionList1;
        TImageList *ImageList1;
        TStatusBar *StatusBar1;
        TToolBar *ToolBar1;
        TAction *Action1;
        TEditCopy *EditCopy1;
        TEditCut *EditCut1;
        TEditDelete *EditDelete1;
        TEditPaste *EditPaste1;
        TEditUndo *EditUndo1;
        THelpContents *HelpContents1;
        TMenuItem *Copy1;
        TMenuItem *Cut1;
        TMenuItem *Paste1;
        TMenuItem *N1;
        TMenuItem *Undo1;
        TMenuItem *File1;
        TMenuItem *Exit1;
        TMenuItem *N4;
        TMenuItem *SaveAs1;
        TMenuItem *Save1;
        TMenuItem *Open1;
        TMenuItem *New1;
        TMenuItem *Edit1;
        TMenuItem *Paste2;
        TMenuItem *Copy2;
        TMenuItem *Cut2;
        TMenuItem *N6;
        TMenuItem *Undo2;
        TMenuItem *Help1;
        TMenuItem *About1;
        TMenuItem *Contents2;
        TToolButton *ToolButton1;
        TToolButton *ToolButton2;
        TToolButton *ToolButton3;
        TToolButton *ToolButton4;
        TToolButton *ToolButton10;
        TToolButton *ToolButton11;
        TToolButton *ToolButton5;
        TToolButton *ToolButton6;
        TToolButton *ToolButton7;
        TPanel *Panel1;
        TLabel *Label1;
        TSpeedButton *SpeedButton1;
        TSpeedButton *SpeedButton2;
        TSpeedButton *SpeedButton3;
        TSpeedButton *SpeedButton4;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TSpeedButton *SpeedButton5;
        TLabel *Label5;
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TTabSheet *TabSheet2;
        TTabSheet *TabSheet3;
        TTabSheet *TabSheet4;
        TTabSheet *TabSheet5;
        TTabSheet *TabSheet6;
        TFrame6 *Frame61;
        TFrame2 *Frame21;
        TFrame3 *Frame31;
        TFrame4 *Frame41;
        TFrame5 *Frame51;
        TImageList *ImageList2;
        TToolButton *ToolButton8;
        TToolButton *ToolButton9;
        TSpeedButton *SpeedButton6;
        TSaveDialog *SaveDialog1;
        TOpenDialog *OpenDialog1;
        TMenuItem *Export1;
        TMenuItem *N3;
        TPanel *Panel2;
        TRichEdit *RichEdit1;
        TPanel *Panel3;
        TSpeedButton *SpeedButton7;
        TSpeedButton *SpeedButton8;
        TSpeedButton *SpeedButton9;
        TMenuItem *Imprimer1;
        TSaveDialog *SaveDialog2;
        TToolButton *ToolButton12;
        TToolButton *ToolButton13;
        TFrame8 *Frame81;
        TLabel *Label6;
        TSpeedButton *SpeedButton10;
        TSpeedButton *SpeedButton11;
        void __fastcall Exit1Click(TObject *Sender);
        void __fastcall About1Click(TObject *Sender);
        void __fastcall Frame21Edit1Change(TObject *Sender);
        void __fastcall Frame21Edit2Change(TObject *Sender);
        void __fastcall Frame41Edit1Change(TObject *Sender);
        void __fastcall Frame41Edit2Change(TObject *Sender);
        void __fastcall Frame31StringGrid1ColumnMoved(TObject *Sender,
          int FromIndex, int ToIndex);
        void __fastcall SpeedButton1Click(TObject *Sender);
        void __fastcall SpeedButton2Click(TObject *Sender);
        void __fastcall SpeedButton3Click(TObject *Sender);
        void __fastcall SpeedButton4Click(TObject *Sender);
        void __fastcall SpeedButton5Click(TObject *Sender);
        void __fastcall ToolButton1Click(TObject *Sender);
        void __fastcall SpeedButton6Click(TObject *Sender);
        void __fastcall Frame31StringGrid1SetEditText(TObject *Sender,
          int ACol, int ARow, const AnsiString Value);
        void __fastcall Frame31StringGrid1SelectCell(TObject *Sender,
          int ACol, int ARow, bool &CanSelect);
        void __fastcall ToolButton4Click(TObject *Sender);
        void __fastcall ToolButton3Click(TObject *Sender);
        void __fastcall ToolButton2Click(TObject *Sender);
        void __fastcall Frame31SpeedButton1Click(TObject *Sender);
        void __fastcall SpeedButton7Click(TObject *Sender);
        void __fastcall ToolButton8Click(TObject *Sender);
        void __fastcall SpeedButton9Click(TObject *Sender);
        void __fastcall SpeedButton8Click(TObject *Sender);
        void __fastcall ToolButton12Click(TObject *Sender);
        void __fastcall ToolButton13Click(TObject *Sender);
        void __fastcall Frame81SpeedButton1Click(TObject *Sender);
        void __fastcall ToolButton10Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

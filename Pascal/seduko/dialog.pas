unit dialog;

interface

uses Windows, SysUtils, Classes, Graphics, Forms, Controls, StdCtrls, 
  Buttons, ExtCtrls;

type
  TOKBottomDlg = class(TForm)
    OKBtn: TButton;
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    Label4: TLabel;
    Label5: TLabel;
    Bevel1: TBevel;
    procedure OKBtnClick(Sender: TObject);
  private
    { déclarations privées }
  public
    { déclarations publiques }
  end;

var
  OKBottomDlg: TOKBottomDlg;

implementation

uses Unit1;

{$R *.dfm}

procedure TOKBottomDlg.OKBtnClick(Sender: TObject);
begin
okbottomdlg.Hide;
form1.enabled:=true;
end;

end.

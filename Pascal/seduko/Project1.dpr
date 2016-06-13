program Project1;

uses
  Forms,
  Unit1 in 'Unit1.pas' {Form1},
  dialog in 'dialog.pas' {OKBottomDlg};

{$R *.res}

begin
  Application.Initialize;
  Application.Title := 'seduko machine';
  Application.CreateForm(TForm1, Form1);
  Application.CreateForm(TOKBottomDlg, OKBottomDlg);
  Application.Run;
end.

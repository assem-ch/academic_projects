unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, Buttons, ExtCtrls,shellapi;

type
  TForm1 = class(TForm)
    Edit1: TEdit;
    Edit2: TEdit;
    Edit3: TEdit;
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    BitBtn2: TBitBtn;
    Image1: TImage;
    Label4: TLabel;
    Label5: TLabel;
    procedure BitBtn1Click(Sender: TObject);
    procedure BitBtn2Click(Sender: TObject);
    procedure Label4Click(Sender: TObject);
    procedure Label5Click(Sender: TObject);
  private
    { Déclarations privées }
  public
    { Déclarations publiques }
  end;

var
  Form1: TForm1;
  cc,cle,code,beta,i:integer;
  str0,str1:string;

implementation

{$R *.dfm}

procedure TForm1.BitBtn1Click(Sender: TObject);
var i:integer;
begin
str0:=edit1.Text;
val(str0,cc,beta);  
str(cc,str0);
edit1.Text:=str0;
if length(str0)<7 then  edit2.Text:='??'
                  else begin
                        cle:=0;
                        for i:=1 to 7 do begin
                                           cle:=cle+(cc mod 10)*(3+i);
                                           cc:=cc div 10;
                                         end;
                        cle:=cle mod 100;
                        str(cle:2,str0);
                        edit2.Text:=str0;
                        end;
end;

procedure TForm1.BitBtn2Click(Sender: TObject);
var i:integer;
begin
BitBtn1Click(sender);
str0:=edit1.Text;
str1:=edit2.Text;
if str1[1]='?' then  edit3.Text:='????'
                  else begin
                        val(str0,cc,beta);
                        val(str1,cle,beta);
                        code:=cle+cc mod 10000;
                        beta:=cc*100+cle;
                        for i:=1 to 9 do begin
                                           code:=code+(beta mod 10);
                                           beta:=beta div 10;
                                         end;
                        beta:=0;
                        for i:=1 to 4 do begin
                                         beta:=beta*10+code mod 10;
                                         code:=code div 10;
                                         end;

                        str(beta:4,str0);
                        edit3.Text:=str0;
                        end;
end;

procedure TForm1.Label4Click(Sender: TObject);
begin
ShellExecute(
    application.Handle,
    'open',
    'http://CCP.POSTE.DZ',
    nil,
    nil,
    0);

end;

procedure TForm1.Label5Click(Sender: TObject);
begin
shellExecute(
  Handle,
  'Open',
  PChar('mailto:ADRIANSHEPHARD@MAKTOOB.COM'+
    '?subject=about code ccp program'+
    '&Body='+
    '&CC='),
  nil,
  nil,
  SW_RESTORE);
end;

end.

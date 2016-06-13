unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls,clipbrd, ComCtrls, ExtCtrls,dialog;

type
   TForm1 = class(TForm)
    Edit01: TEdit;
    GroupBox1: TGroupBox;
    b_build: TButton;
    GroupBox2: TGroupBox;
    Label1: TLabel;
    b_hide: TButton;
    GroupBox3: TGroupBox;
    b_play: TButton;
    GroupBox4: TGroupBox;
    b_save: TButton;
    e_save: TEdit;
    b_open: TButton;
    GroupBox5: TGroupBox;
    b_about: TButton;
    t_level: TTrackBar;
    procedure step1;
    procedure FormCreate(Sender: TObject);
    procedure b_buildClick(Sender: TObject);
    procedure b_hideClick(Sender: TObject);
    procedure b_playClick(Sender: TObject);
    procedure FormMouseMove(Sender: TObject; Shift: TShiftState; X,
      Y: Integer);
    procedure FormClick(Sender: TObject);
    procedure b_saveClick(Sender: TObject);
    procedure b_openClick(Sender: TObject);
    procedure b_aboutClick(Sender: TObject);
    procedure e_saveChange(Sender: TObject);
    procedure t_levelChange(Sender: TObject);

   
      private
    { Déclarations privées }
  public
    { Déclarations publiques }
  end;
    gt=array[1..9,1..9] of integer;
     mt=array[1..9] of integer;

const niv:array[1..4] of integer=(36,31,27,24);
      {niv:number of cell showed}
      nivmax:array[1..4] of integer=(5,5,4,4);
      {nivmax:max number of cells hided which have the same digit}
var
  Form1: TForm1;
  i,j:integer;
  str0,str1,str2:string;
  e:array[1..9,1..9] of tedit;
  t,s:gt;//area
    a,b,k,x,l,per,per_,n,code,sj,si:integer;
    m:mt;//mask array
   tap, btn,ch:char;
   hided,playmod,builded:boolean;
   fix_si,fix_sj:integer;
  implementation

{$R *.dfm}

procedure TForm1.FormCreate(Sender: TObject);
var i,j:integer;
begin
fix_si:=0; //the cell which the player edits is (0,0)
fix_sj:=0;
builded:=false;
playmod:=false;
hided:=false;
{scan if the file in e-save  exists}
b_open.Enabled:=FileExists(concat(e_save.Text,'.txt'));

n:=1;//level=1

{copy the principal cell(edit01) to make all cells }
RegisterClasses([tedit]);
clipboard.Open;
for i:=1 to 9 do
for j:=1 to 9 do
begin
  Clipboard.SetComponent(edit01);//copy
  e[i,j]:=edit01; //rename
  Clipboard.GetComponent(Self,form1);//paste
  e[i,j].Left:=20+(j-1)*50+((j-1) div 3)*10;//choose it's place
  e[i,j].top:=20+(i-1)*50+((i-1) div 3)*10;

  end;
edit01.Hide;// hide the principal cell
end;

{donner le minumim de deux nombre}
function min(a,b:integer):integer;
begin
if a>b then min:=b else min:=a;
end;

{donner le maxumim de deux nombre}
function max(a,b:integer):integer;
begin
if a>b then max:=a else max:=b;
end;

{true if x exist in the line i}
function line(t:gt;x,i:integer):boolean;
         var j:integer;
         begin
         line:=false;
         for j:=1 to 9 do if t[i,j]=x then line:=true;
         end;

{true if x exist in the colomne j}
function col(t:gt;x,j:integer):boolean;
         var i:integer;
         begin
         col:=false;
         for i:=1 to 9 do if t[i,j]=x then col:=true;
         end;

{reset mask to 000000000}
procedure raz(var m:mt);
var k:integer;
begin
for k:=1 to 9 do m[k]:=0;
end;

{reset a part of an array to 0}
procedure razg(var t:gt;i0,j0,i1,j1:integer);
label STOP;
var i,j:integer;
begin
for i:=i0 to i1 do for j:=j0 to j1 do begin
                                      if t[i,j]<>0 then t[i,j]:=0 else goto STOP;

                                         end;
STOP:
end;

{number of 1 in mask}
function nb(m:mt):integer;
var k,n:integer;
begin
n:=0;
for k:=1 to 9 do if m[k]=1 then n:=n+1;
nb:=n;
end;

{true if x exist in a region}
function reg(t:gt;x,i,j:integer):boolean;
         var mini,minj:integer;
         begin
         reg:=false;
         mini:=0;minj:=0;
         case i of
         1..3:mini:=1;
         4..6:mini:=4;
         7..9:mini:=7;
         end;
         case j of
         1..3:minj:=1;
         4..6:minj:=4;
         7..9:minj:=7;
         end;
         for i:=mini to mini+2 do
         for j:=minj to minj+2 do
         if t[i,j]=x then reg:=true;
         end;

 
{building... }
procedure tform1.step1;
label a,b;
begin
//per:=0;{percent of advancement}
//per_:=0;{percent of            }
 i:=0;
while i<9 do
begin
i:=i+1;
k:=0;
l:=0;
j:=0;
while j<9 do
begin
j:=j+1;

b: raz(m);
{generate a random number x}
a: randomize;
x:=random(9)+1;

if nb(m)>8 then begin  //nb(m)=9 means no digit is valide
                k:=k+1;
                l:=l+1;
                j:=max(1,min(9-i+1,j-3));//return many cells
                if l=10 then begin l:=0;i:=i-2;j:=1;end;//l=10(10 times) >> return 2 lines
                if k=3 then begin k:=0;j:=1;end;//k=3(3 times) >> return to the beginning of line;
                razg(t,i,j,min(9,i+2),9);{reset}
                goto b;
                end;
if m[x]=1 then goto a;//if tested before
{test duplication}
if (line(t,x,i)) or (col(t,x,j)) or (reg(t,x,i,j))   then begin
                                                        m[X]:=1;//mask of x turned 1
                                                        goto a;
                                                        end;

{x stored and printed }
t[i,j]:=x;
str(x,str0);
e[i,j].text:=str0;

{calculate percents}
//per:=max(per,((9*i-9+j)*100) div 81);
//per_:=per-((9*i-9+j)*100) div 81;
//str(per,str0);
//form1.Caption:=concat('seduko maker-building..',str0,'%');

end;
end;
end;

{hide many cells respect the level n}
procedure step2(n:integer);
label a;
var i,j,k:integer;
begin
s:=t;
//per:=0;
raz(m);//reset mask m
for k:=1 to 81-niv[n] do begin
                         a:randomize;//generate random place
                         i:=random(9)+1;
                         j:=random(9)+1;
                         if (s[i,j]=0) or (m[s[i,j]]>=nivmax[n]) then goto a else begin
                                                                                  s[i,j]:=0;
                                                                                  inc(m[s[i,j]]);
                                                                                  end;
                         if s[i,j]=0 then e[i,j].Text:='';
                         {parcent}
                         //per:=(k*100) div (81-niv[n]);
                         //str(per,str0);
                         //form1.Caption:=concat('seduko-hiding..',str0,'%');
                         end;


end;

{make all cells like default state}
procedure disable_all;
var i,j:integer;
begin
for i:=1 to 9 do
for j:=1 to 9 do with e[i,j] do
                  begin
                  Enabled:=false;
                  Color:=clwhite;
                  ReadOnly:=true;
                  end;
end;
{preparing playing mod}
procedure step3;
var i,j:integer;
begin
 fix_si:=0; //the cell which the player edits is (0,0)
 fix_sj:=0;
for i:=1 to 9 do
for j:=1 to 9 do begin
                  if e[i,j].Text='' then e[i,j].ReadOnly:=false;
                  //the player can change val of empty cells
                  end;
end;

{start building..}
procedure TForm1.b_buildClick(Sender: TObject);
begin
disable_all;
form1.Caption:='seduko maker-by assem chelli';
razg(t,1,1,9,9);  //reset all cells
step1;     //building

{preparing the suivant step}
builded:=true;
b_hide.Enabled:=true;
t_level.Enabled:=true;
b_play.enabled:=false;
b_save.enabled:=false;
hided:=false;
playmod:=false;
{}
end;
{start to hide}
procedure TForm1.b_hideClick(Sender: TObject);
begin
if (builded) and (not(hided)) then step2(n);//hide

{preparing the suivant step}
hided:=true;
b_play.enabled:=true;
b_save.enabled:=true;
b_hide.Enabled:=false;
t_level.Enabled:=false;
end;



{start playmode}
procedure TForm1.b_playClick(Sender: TObject);
begin
if hided then begin
                playmod:=true;
                b_play.enabled:=false;
                form1.Caption:='seduko maker-mode playing...';
                step3;//prepare

              end;
end;

{determination of the current cell }
procedure TForm1.FormMouseMove(Sender: TObject; Shift: TShiftState; X,
  Y: Integer);
begin
//to compare
  //e[i,j].Left:=20+(j-1)*50+((j-1) div 3)*10;
 //e[i,j].top:=20+(i-1)*50+((i-1) div 3)*10;

sj:=0;//no colomn
case x of
21..69:sj:=1;//colomn 1
71..119:sj:=2;
121..169:sj:=3;
181..229:sj:=4;
231..279:sj:=5;
281..329:sj:=6;
341..389:sj:=7;
391..439:sj:=8;
441..489:sj:=9;//colomn 9
end;
si:=0;//no line
case y of
21..69:si:=1; //line 1
71..119:si:=2;
121..169:si:=3;
181..229:si:=4;
231..279:si:=5;
281..329:si:=6;
341..389:si:=7;
391..439:si:=8;
441..489:si:=9;//line 9
end;
end;

{change value of  the selected cell}
procedure TForm1.FormClick(Sender: TObject);
var ok:boolean;
    x:integer;
begin
if playmod then
begin
if fix_si*fix_si<>0 then begin
  if e[fix_si,fix_sj].Text<>'' then
      begin
      ok:=true; //no problem
      {scan validation of digit}
      str0:=e[fix_si,fix_sj].Text;
      val(str0,x,code);
      if x=0 then str0:='' else str(x,str0);
      e[fix_si,fix_sj].Text:=str0;
if ((col(s,x,fix_sj)) or (line(s,x,fix_si)) or (reg(s,x,fix_si,fix_sj))) then ok:=false;
                          if ok then e[Fix_si,fix_sj].Color:=clSkyBlue//blue:modified without problems
                          else e[Fix_si,fix_sj].Color:=clred;//red:modified with problems
                          if e[fix_si,fix_sj].Text='' then e[Fix_si,fix_sj].Color:=clwhite;//white:not modified
                          e[Fix_si,fix_sj].enabled:=false;
                          s[fix_si,fix_sj]:=x;
    end else e[Fix_si,fix_sj].Color:=clwhite;//white:not modified
    end;
if (si*sj<>0) then if not(e[si,sj].ReadOnly) then begin
                                      if fix_si*fix_si<>0 then e[Fix_si,fix_sj].enabled:=false;//close the previos cell

                                      {prepare the new cell }
                                      e[si,sj].Enabled:=true;
                                      e[si,sj].color:=clMoneyGreen;//green:selected cell
                                      fix_si:=si;// selected cell (si,sj)
                                      fix_sj:=sj;
                                      e[si,sj].SetFocus;
                                     end;
end;
end;

{start saving}
procedure TForm1.b_saveClick(Sender: TObject);
var fich:textfile;
    i,j:integer;
    ch:char;
begin

{prepare file}
if e_save.Text='' then e_save.Text:='seduko';
assignfile(fich,concat(e_save.Text,'.txt'));
rewrite(fich);

write(fich,'#created by seduko maker-Assem Chelli',chr(13),chr(10));//line 1
write(fich,'#Level:',chr(t_level.Position+30));      //line 2
if playmod then write(fich,'-modified',chr(13),chr(10))    //line 2
            else write(fich,'-raw',chr(13),chr(10));      //line 2
for i:=1 to 9 do
  begin
   write(fich,chr(13),chr(10));//jump to the next line
    for j:=1 to 9 do
      begin
        if s[i,j]=0 then ch:='-' else ch:=chr(s[i,j]+48);
        write(fich,chr(9),ch);//chr(9):many spaces

      end;
  end;
closefile(fich);
b_open.Enabled:=FileExists(concat(e_save.Text,'.txt'));
end;
{open a file exist}
procedure TForm1.b_openClick(Sender: TObject);
var fich:textfile;
    i,j:integer;
    ch:char;
begin
if FileExists(concat(e_save.Text,'.txt')) then
begin
form1.Caption:='seduko maker-by assem chelli';
disable_all;// as default

{prepare the new state }
builded:=true;
hided:=true;
playmod:=false;
b_hide.Enabled:=false;
b_play.Enabled:=true;
t_level.Enabled:=false;
b_save.enabled:=true;
{}
{prepare the file}
assignfile(fich,concat(e_save.Text,'.txt'));
reset(fich);
{read the first line}
read(fich,ch);
while ch<>chr(10) do read(fich,ch);
{read the second line}
read(fich,ch);
while ch<>chr(10) do read(fich,ch);
{}
for   i:=1 to 9 do
  begin
   read(fich,ch,ch);//advance 2 step
    for j:=1 to 9 do
      begin
        read(fich,ch,ch);//advance 1 step and read the second char
        val(ch,s[i,j],code);//transform the value from ch to s[i,j]
        if ch='-' then ch:=chr(0);
        e[i,j].Text:=ch;
      end;
  end;
closefile(fich);
end;
end;
{show the "about" dialog}
procedure TForm1.b_aboutClick(Sender: TObject);
begin
okbottomdlg.Show;
form1.Enabled:=false;
end;
{enable the b_open if the file exist,disable else} 
procedure TForm1.e_saveChange(Sender: TObject);
begin
b_open.Enabled:=FileExists(concat(e_save.Text,'.txt'));
end;

{change the level}
procedure TForm1.t_levelChange(Sender: TObject);
begin
n:=t_level.Position;
end;

end.

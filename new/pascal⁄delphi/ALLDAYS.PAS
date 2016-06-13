program alldays;
uses crt;
label 1;
var jj,mm,aa,j:integer;
    o:char;
begin
clrscr;
textcolor(green);
1:writeln;
writeln('add jour-moin-ann‚e!');
write('jour: ');
readln(jj);
write('moin: ');
readln(mm);
write('ann‚e: ');
readln(aa);
case mm of
1:j:=0;
2:j:=31;
3:j:=59;
4:j:=90;
5:j:=120;
6:j:=151;
7:j:=181;
8:j:=212;
9:j:=243;
10:j:=273;
11:j:=304;
12:j:=334;
end;
writeln;
if (mm<13) and (mm>0) and (jj<32) then begin
if (aa mod 4=0) and (mm>2) then j:=j+1;
j:=j+jj;
writeln('le jour ',j);
writeln('la semaine  ',(j div 7)+1);
end else writeln ('erreur');
writeln;
writeln('to repeat press "o"');
o:=readkey;
if o='o' then goto 1;
textcolor(white);
end.

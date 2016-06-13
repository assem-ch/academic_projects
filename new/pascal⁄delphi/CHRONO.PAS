program chrono;
uses crt;
label 1,2,3,4;
var h,m,s,c:shortint;
    ky:char;
begin
h:=0;
m:=0;
s:=0;
c:=0;
3:textcolor(yellow);
clrscr;
writeln;

writeln('s:start');
writeln('c:continue');
writeln('a:about...');
writeln;
writeln('q:quit');

gotoxy(32,13);
write(h:2,' : ',m:2,' : ',s:2,' : ',c:2);
ky:=readkey;
clrscr;
writeln('any key:stop');
case ky of
's':goto 1;
'c':goto 2;
'q':goto 4;
'a':begin
    clrscr;
    writeln('about...');
    writeln;
    writeln('name: assem.ch');
    writeln('group: 2');
    writeln('day: 11/03/2006');
    writeln('from: taher-jijel');
    readkey;
    end;
end;
goto 3;

1:textcolor(28);
h:=-1;

repeat h:=h+1;
gotoxy(32,13);
write(h:2,' : ');
m:=-1;
repeat m:=m+1;
gotoxy(37,13);
write(m:2,' : ');
s:=-1;
repeat s:=s+1;
gotoxy(42,13);
write(s:2,' : ');
c:=-1;
2:if ky='c' then begin
                 gotoxy(32,13);
                 textcolor(28);
                 ky:='0';
                 write(h:2,' : ',m:2,' : ',s:2,' : ',c:2);
                 end;
repeat c:=c+1;
gotoxy(47,13);
write(c:2);
delay(10);
until (c=99) or (keypressed);
until (s=59) or (keypressed);
until (m=59) or (keypressed);
until (h=23) or (keypressed);
readkey;
writeln;
 goto 3;
4:clrscr;
textcolor(27);
gotoxy(35,13);
writeln('arabe armory G:2');
delay(1000);
end.

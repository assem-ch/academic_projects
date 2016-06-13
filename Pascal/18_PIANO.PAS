program piano;
uses crt;
label 1,10;
var ky:char;
    i:byte;
    txt:file of char;

    begin
1:textcolor(yellow);
clrscr;
writeln('press k to play with keyboard');
writeln('press a to play automatic');
writeln('press r to play radomize');
writeln('press c to clear the file');
writeln('press s to see about..');
writeln;
writeln('press q to quit');
ky:=readkey;
clrscr;
textcolor(31);
assign(txt,'c:\piano.txt');
reset(txt);
case ky of
'k':begin
         i:=1;
         writeln('play with keys! to stop press F4');
         repeat
         textcolor(i);
         i:=i+1;
         ky:=readkey;
         write(ky,' ');
         write(txt,ky);
         sound((ord(ky)*20)-1700);
         delay(150);
         nosound;
         if i=16 then i:=1;
         until ky='>';
    end;
 'a':begin
         i:=1;
         writeln('automatic mode (read file c:\piano.txt)! to stop press any key!');
         repeat
         textcolor(i);
         i:=i+1;
         read(txt,ky);
         write(ky,' ');
         sound((ord(ky)*20)- 1800);
         delay(150);
         nosound;
         if i=16 then i:=1;
         until Eof(txt) or keypressed;readkey;
         end;
'r':begin
    i:=1;
         writeln('randomize mode! to stop press any key!');
         repeat
         randomize;
         textcolor(i);
         i:=i+1;
         ky:=chr(random(26)+97);
         write(ky,' ');
         write(txt,ky);
         sound((ord(ky)*20)-1800);
         delay(150);
         nosound;
         if i=16 then i:=1;
         until keypressed;
         readkey;
    end;
'c':begin
    clrscr;
    rewrite(txt);
    writeln('clear file success!');
    sound(300);
    delay(1000);
    nosound;
    end;
's':begin
    clrscr;
    writeln('about...');
    writeln;
    writeln('name: assem.ch');
    writeln('group: 2');
    writeln('day: 11/03/2006');
    writeln('from: taher-jijel');
    readkey;
    end;
'q':goto 10;
    end;
close(txt);
goto 1;
clrscr;
textcolor(yellow);
10:clrscr;
textcolor(31);
gotoxy(39,13);
write('arabe armory');
delay(1000);
textcolor(15);
end.


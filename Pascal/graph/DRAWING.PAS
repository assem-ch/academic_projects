program drawing;
uses crt,graph3,graph;
label init;
const dy=100;
var x,y,d,f,cl,ccl,fcl,i,j:integer;
    px,py,x0,y0,x1,y1:integer;
    xa,xb,ya,yb,r:integer;
    xp,yp:integer;
    cu2,cu4,cu6,cu8:integer;
    ch:char;
    str0,str1,name:string;
    s:byte;
    ph:file of char;
    save:file of byte;
{ init graph }
procedure ig(x:integer);
var a,b:integer;
    begin
    a:=x;
    initgraph(a,b,'..\bgi');
    if not(graphresult=0) then write('graph error!');
    end;
{ test if outside AND DIRECTION}
function Io:boolean;
  begin
  io:=false;
  if x<=x0 then io:=true;
  if x1<=x then io:=true;
  if y<=y0 then io:=true;
  if y1<=y then io:=true;
  end;

{ name of color }
function color(x:integer):string;
begin
case (x mod 16) of
0:color:='black';
1:color:='blue';
2:color:='green';
3:color:='cyan';
4:color:='red';
5:color:='magenta';
6:color:='brown';
7:color:='lightgray';
8:color:='darkgray';
9:color:='lightblue';
10:color:='lightgreen';
11:color:='lightcyan';
12:color:='lightred';
13:color:='lightmagenta';
14:color:='yellow';
15:color:='white';
end;
end;

{ add a string }

procedure add(title,first:string);
begin
bar(5,420,195,475);
outtextxy(5,420,first);
ch:=' ';
setcolor(15);
if length(name)=0 then
	repeat name:=concat(name,ch);
                outtextxy(5,435,concat(title,' : ',name));
		ch:=readkey;
	until ch=chr(13);
bar(5,420,195,475);
end;



{ move and take a point }
procedure move;
begin
bar(5,420,195,475);

{ take  point a }
xa:=x-x0;
ya:=y-y0;
str(xa,str0);
str(ya,str1);
bar(5,435,190,445);
outtextxy(5,435,concat('point 1: (',str0,',',str1,')'));
repeat
{ cursor }
cu2:=getpixel(x,y+1);
putpixel(x,y+1,ccl);
cu4:=getpixel(x-1,y);
putpixel(x-1,y,ccl);
cu8:=getpixel(x,y-1);
putpixel(x,y-1,ccl);
cu6:=getpixel(x+1,y);
putpixel(x+1,y,ccl);

ch:=readkey;

{ clean cursur}
putpixel(x,y+1,cu2);
putpixel(x-1,y,cu4);
putpixel(x,y-1,cu8);
putpixel(x+1,y,cu6);

setcolor(15);
write(ph,ch);
case ch of
'4':x:=x-1;
'6':x:=x+1;
'2':y:=y+1;
'8':y:=y-1;
'1':begin x:=x-1;y:=y+1; end;
'3':begin x:=x+1;y:=y+1; end;
'7':begin x:=x-1;y:=y-1; end;
'9':begin x:=x+1;y:=y-1; end;
'f':begin f:=-f;
          bar(205,465,280,475);
          outtextxy(205,465,'fill: ');
          if f=1 then outtextxy(250,465,'on')
          else outtextxy(250,465,'off');
    end;

'-':begin cl:=cl+1;
          bar(485,435,590,445);
          outtextxy(405,435,'pencolor:');
          if not(cl mod 16=0) then setcolor(cl);
          outtextxy(485,435,color(cl));
          setcolor(white);
    end;
'*':begin fcl:=fcl+1;
          bar(485,450,590,460);
          outtextxy(405,450,'fillcolor:');
          if not(fcl mod 16=0) then setcolor(fcl);
          outtextxy(485,450,color(fcl));
          setcolor(white);
    end;


'/':begin ccl:=ccl+1;
          bar(470,465,570,475);
          outtextxy(405,465,'cursor:');
          if not(ccl mod 16=0) then setcolor(ccl);
          outtextxy(470,465,color(ccl));
          setcolor(white);
    end;

end;
moveto(x,y);
setcolor(red);
{ take point b }
xb:=x-x0;
yb:=y-y0;
str(xb,str0);
str(yb,str1);
bar(5,450,190,460);
outtextxy(5,450,concat('point 2: (',str0,',',str1,')'));

{ rayon  }
r:=round(sqrt(sqr(xa-xb)+sqr(ya-yb)));
str(r,str0);
bar(5,465,190,475);
outtextxy(5,465,concat('rayon : ',str0));

until ch=chr(13);
bar(5,420,195,475);
setcolor(cl);
setfillstyle(1,fcl);
end;


{-------------------}
{ program principal }
{-------------------}
begin
clrscr;
textcolor(green);
writeln('welcom..');
writeln('add size of picture x*y (max=400*400)');
textcolor(red);
repeat write('x= ');readln(px); until px<401;
repeat write('y= ');read(py); until py<401;

{graph}
ig(0);

{ start a new picture }
{fichier}
assign(ph,concat('0','.txt'));
rewrite(ph);

{init variables}
d:=-1;
f:=-1;
cl:=15;
ccl:=13;
fcl:=0;
x0:=(640-px) div 2+100-1;
y0:=(480-py) div 2-25-1;
x1:=x0+px+1;
y1:=y0+py+1;
x:=(x0+x1) div 2;
y:=(y0+y1) div 2;

{ init draw }

{ center }
rectangle(x0,y0,x1,y1);
line(200,0,200,480);
line(200,430,640,430);
line(0,415,200,415);

{ left }
outtextxy(5,5,'keys : ');
outtextxy(5,30,'keypad : move cursor');
outtextxy(5,50,'enter : apply');
outtextxy(5,70,'5 : pen on\off ');
outtextxy(5,90,'f : fill on\off');
outtextxy(5,110,'- : change pen color');
outtextxy(5,130,'/ : change cursor color');
outtextxy(5,150,'* :change fill color');
outtextxy(5,170,'l : draw a line');
outtextxy(5,190,'c : draw a circle');
outtextxy(5,210,'r : draw a rectangle');
outtextxy(5,230,'esc : exit');


{ down }
outtextxy(205,450,'Pen : ');
outtextxy(250,450,'off');
outtextxy(405,435,'pencolor:');
setcolor(cl);
outtextxy(485,435,color(cl));
setcolor(white);
outtextxy(405,465,'cursor:');
setcolor(ccl);
outtextxy(470,465,color(ccl));
setcolor(white);
outtextxy(405,450,'fillcolor:');
outtextxy(485,450,'black');
outtextxy(205,465,'fill: ');
outtextxy(250,465,'off');

setfillstyle(1,0);
{ \init draw }
repeat

setfillstyle(1,0);
setcolor(15);
rectangle(x0,y0,x1,y1);

{ draw x y}
bar(265,435,400,445);
str(x-x0,str0);
str(y-y0,str1);
outtextxy(205,435,concat('(x,y) = (',str0,',',str1,')'));

{ cursor }
cu2:=getpixel(x,y+1);
putpixel(x,y+1,ccl);
cu4:=getpixel(x-1,y);
putpixel(x-1,y,ccl);
cu8:=getpixel(x,y-1);
putpixel(x,y-1,ccl);
cu6:=getpixel(x+1,y);
putpixel(x+1,y,ccl);

ch:=readkey;

{ clean cursur}
putpixel(x,y+1,cu2);
putpixel(x-1,y,cu4);
putpixel(x,y-1,cu8);
putpixel(x+1,y,cu6);


write(ph,ch);
{ func }
case ch of
'4':x:=x-1;
'6':x:=x+1;
'2':y:=y+1;
'8':y:=y-1;
'1':begin x:=x-1;y:=y+1; end;
'3':begin x:=x+1;y:=y+1; end;
'7':begin x:=x-1;y:=y-1; end;
'9':begin x:=x+1;y:=y-1; end;

'5':begin d:=-d;
          bar(205,450,280,460);
          outtextxy(205,450,'Pen : ');
          if d=1 then outtextxy(250,450,'on')
          else outtextxy(250,450,'off');
    end;
'f':begin f:=-f;
          bar(205,465,280,475);
          outtextxy(205,465,'fill: ');
          if f=1 then outtextxy(250,465,'on')
          else outtextxy(250,465,'off');
    end;

'-':begin cl:=cl+1;
          bar(485,435,590,445);
          outtextxy(405,435,'pencolor:');
          if not(cl mod 16=0) then setcolor(cl);
          outtextxy(485,435,color(cl));
          setcolor(white);
    end;
'/':begin ccl:=ccl+1;
          bar(470,465,570,475);
          outtextxy(405,465,'cursor:');
          if not(ccl mod 16=0) then setcolor(ccl);
          outtextxy(470,465,color(ccl));
          setcolor(white);
    end;
'*':begin fcl:=fcl+1;
          bar(485,450,590,460);
          outtextxy(405,450,'fillcolor:');
          if not(fcl mod 16=0) then setcolor(fcl);
          outtextxy(485,450,color(fcl));
          setcolor(white);
    end;

'l':begin outtextxy(5,420,'draw line ');
	  move;
          setviewport(x0,y0,x1,y1,true);
          line(xa,ya,xb,yb);
          SetViewPort(0, 0, GetMaxX,GetMaxY, True);
	  end;
'c':begin outtextxy(5,420,'draw circle');
	  move;
          setviewport(x0,y0,x1,y1,true);
          if f=1 then begin pieslice(xa,ya,0,360,r);
          		    bar(xa,ya,xa+r,ya);
                      end
                 else circle(xa,ya,r);
          SetViewPort(0, 0, GetMaxX,GetMaxY, True);
    end;
'r':begin outtextxy(5,420,'draw rectangle');
	  move;
          setviewport(x0,y0,x1,y1,true);
          if f=1 then  bar(xa,ya,xb,yb);
          rectangle(xa,ya,xb,yb);
          SetViewPort(0, 0, GetMaxX,GetMaxY, True);
          end;
{'p':begin xp:=x;yp:=y;
	repeat str(xp-x0,str0);
           str(yp-y0,str1);
	   outtextxy(5,435,concat('polygone : (',str0,',',str1,')'));
	   move;
           setviewport(x0,y0,x1,y1,true);
           line(xa,ya,xb,yb);
           SetViewPort(0, 0, GetMaxX,GetMaxY, True);
        until (xp=x) and (yp=y);
     end;          }
's':begin
        add('name','add name of file');
        {name:='default';}
        assign(save,name);
        rewrite(save);
        outtextxy(5,420,concat(name,' saving...'));
        setcolor(white);
        setfillstyle(1,blue);
        for j:=1 to py do
        begin
        s:=100;
        write(save,s);
        for i:=1 to px do
        begin
        s:=getpixel(i+x0,j+y0);
        write(save,s);
        rectangle(4,434,196,446);
        bar(5,435,round((((((j-1)*px+i)*100)/(px*py))*190)/100)+5,445);;
        end;
        end;
        setfillstyle(1,0);
        outtextxy(10,436,'saving complete.');
       close(save);
    end;
'o':begin
        bar(x0+1,y0+1,x1-1,y1-1);
        add('name','add name of file');
        name:='default';
        assign(save,name);
        reset(save);
        outtextxy(5,420,concat(name,'loading...'));
        setcolor(white);
        setfillstyle(1,blue);
        j:=0;
        repeat j:=j+1;
        i:=0;
        repeat i:=i+1;
        read(save,s);
        if not(s=100) then putpixel(i+x0,j+y0,s);
        rectangle(4,434,196,446);
        until (s=100) or eof(save);
        until eof(save);
        px:=i;
        py:=j;
        setfillstyle(1,0);
        outtextxy(10,436,'loading complete.');
        close(save);

    end;

end;
if (d=-1) or (io) then moveto(x,y) else putpixel(x,y,cl);
until ch='&';
close(ph);
end.





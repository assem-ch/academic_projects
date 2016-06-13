Program pict;
uses crt,graph;
var save:file of byte;
	name:string;
        i,j,x0,y0:integer;
        s:byte;
{ init graph }
procedure ig(x:integer);
var a,b:integer;
    begin
    a:=x;
    initgraph(a,b,'..\bgi');
    if not(graphresult=0) then write('graph error!');
    end;

procedure open(name:string;x0,y0:integer);
begin
        assign(save,name);
        reset(save);
        outtextxy(5,420,concat(name,' loading...'));
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
        setfillstyle(1,0);
        outtextxy(10,436,'loading complete.');
        close(save);

    end;
    begin
    writeln('add name');
    readln(name);
    writeln('add x');
    readln(x0);
    writeln('add y');
    readln(y0);

    ig(0);
    open(name,x0,y0);
    readkey;
    end.
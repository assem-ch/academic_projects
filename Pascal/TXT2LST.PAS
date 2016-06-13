(*next: enter symbols******)
program text2list;
uses crt;
type    text=file of char;
	cord=record
        	i,j:integer;
              end;

	ptr=^maillon;
     	maillon=record
     		mot:string;
		deb,fin:cord;
		addr:ptr;
     	     end;
label 1;
const max_j=80;
var 	fich:text;
	pathe,mot0:string;
	l,p,q:ptr;



(********************beauty********************)
procedure ecrire(str0:string;cl,ln:byte);
begin
textcolor(cl);
if ln=0 then write(str0) else writeln(str0);
textcolor(white);
end;

procedure debut;
begin
clrscr;
ecrire('le programme est intialis‚...........',14,1);
writeln;
end;

(********************fichier********************)
procedure prepare_fich(s:char);
begin
if s='1' then
begin
writeln;
ecrire('preparing file.........',2,1);
ecrire('ajouter pathe de fichier:',4,1);
readln(pathe);
end
else pathe:='text.txt';
assign(fich,pathe);
reset(fich);
ecrire('preparing file has finished.........',2,1);
end;

procedure imprime_fich;
var ch:char;
    x,y:integer;
begin
writeln;
ecrire('printing file.........',2,1);
if eof(fich) then ecrire('fichier vide!',14,1);
x:=0;y:=1;
while not(eof(fich)) do
begin
read(fich,ch);
write(ch);
x:=x+1;
if (ch=chr(13)) or (x=80) then begin y:=y+1;x:=0; end;
if y=25 then begin
			ecrire('press any key to continue........',2,0);
                        readkey;
                        textcolor(red);
                        clrscr;
                        y:=1;
                     end;
end;
textcolor(white);
writeln;
ecrire('printing file has finished.........',2,1);
writeln;
end;

(*****************small*******************)
function select0:char;
begin
writeln;
ecrire('choose one of these:',4,1);
writeln('1.write the path of the file');
writeln('*.use dephault file "text.txt"');
select0:=readkey;
writeln;
end;

procedure incr(var i,j:integer);
begin
j:=j+1;
if j=max_j+1 then begin
			j:=0;
                        i:=i+1;
                  end;
end;

procedure decr(var i,j:integer);
begin
j:=j-1;
if i=0 then begin
		j:=max_j;
                i:=i-1;
            end;
end;
(***********fonctions de maillon*******************)
procedure allouer(var p:ptr);
begin
new(p);
end;

procedure liberer(var p:ptr);
begin
dispose(p);
end;

function mot(p:ptr):string;
begin
mot:=p^.mot;
end;

function deb_i(p:ptr):integer;
begin
deb_i:=p^.deb.i;
end;

function deb_j(p:ptr):integer;
begin
deb_j:=p^.deb.j;
end;

function fin_i(p:ptr):integer;
begin
fin_i:=p^.fin.i;
end;

function fin_j(p:ptr):integer;
begin
fin_j:=p^.fin.j;
end;

procedure suivant(var p:ptr);
begin
p:=p^.addr;
end;

procedure aff_addr(p,q:ptr);
begin
p^.addr:=q;
end;
procedure aff_mot(p:ptr;mot:string);
begin
p^.mot:=mot;
end;
procedure aff_deb_i(p:ptr;i:integer);
begin
p^.deb.i:=i;
end;
procedure aff_deb_j(p:ptr;j:integer);
begin
p^.deb.j:=j;
end;
procedure aff_fin_i(p:ptr;i:integer);
begin
p^.fin.i:=i;
end;
procedure aff_fin_j(p:ptr;j:integer);
begin
p^.fin.j:=j;
end;
(*****************************************************)
(*****************************************************)

procedure creer_list;
var ch:char;
	mot0:string;
        i,j:integer;
        p,q:ptr;
begin
ecrire('creating list....',2,1);
reset(fich);
i:=1;j:=0;
l:=nil;q:=nil;
while not(eof(fich)) do
begin
read(fich,ch);
incr(i,j);
if (ch=' ') or (ch=chr(13)) then
begin
if mot0<>'' then begin
		aff_mot(p,mot0);
                decr(i,j);
                aff_fin_i(p,i);
                aff_fin_j(p,j);
                incr(i,j);
                mot0:='';
                q:=p;p:=nil;
                end;
if ch=chr(13) then begin
			i:=i+1;
                        j:=0;
			end;
end else begin
         if mot0='' then  begin
         			allouer(p);
                                aff_deb_i(p,i);
                                aff_deb_j(p,j);
				if l=nil then l:=p else aff_addr(q,p);
                                mot0:=ch;
                         end
         else 	mot0:=concat(mot0,ch);
        end;
end;
aff_addr(p,nil);
ecrire('creating list finished....',2,1);
end;

procedure imprime_list;
var p:ptr;
begin
ecrire('printing list.........',2,1);
p:=l;
while p<>nil do
begin
writeln(deb_j(p):4,'*',deb_i(p):4,':',fin_j(p):4,'*',fin_i(p):4,':',mot(p));
suivant(p);
end;
ecrire('printing list has finished.........',2,1);
end;

procedure cherch_mot;
var p:ptr;
	exist:boolean;
        mot0:string;
begin
ecrire('researching word in list....',2,1);
ecrire('ajouter un mot:',4,1);
readln(mot0);
p:=l;
exist:=false;
while p<>nil do
begin
if mot(p)=mot0 then
begin
writeln(deb_i(p):4,'*',deb_j(p):4,':',fin_i(p):4,'*',fin_j(p):4,':',mot(p));
exist:=true;
end;
suivant(p);
end;
if not(exist) then writeln('le mot "',mot0,'" n''exist pas...');
ecrire('researching word in list finished....',2,1);
end;

procedure mots_columne;
var p:ptr;
	j:integer;
	exist:boolean;
begin
writeln;
ecrire('ajouter le numero de la columne :',4,1);
readln(j);
ecrire('printing all words in a column ',2,0);
write(j);
ecrire(' ............',2,1);
p:=l;
exist:=false;
while p<>nil do
begin
if (j>=deb_j(p)) and (j<=fin_j(p)) then
begin
writeln(deb_j(p):4,'*',deb_i(p):4,':',fin_j(p):4,'*',fin_i(p):4,':',mot(p));
exist:=true;
end;
suivant(p);
end;
if not(exist) then begin
			ecrire('aucan mot existe a la columne:',14,0);
                        writeln(j);
                   end;
ecrire('printing all words in a columne ',2,0);
write(j);
ecrire(' has finished............',2,1);
end;

procedure mots_ligne;
var p:ptr;
	i:integer;
	exist:boolean;
begin
writeln;
ecrire('ajouter le numero de la ligne :',4,1);
readln(i);
ecrire('printing all words in a ligne ',2,0);
write(i);
ecrire(' ............',2,1);
p:=l;
exist:=false;
while p<>nil do
begin
if (i=deb_i(p)) or (i=fin_i(p)) then
begin
writeln(deb_j(p):4,'*',deb_i(p):4,':',fin_j(p):4,'*',fin_i(p):4,':',mot(p));
exist:=true;
end;
suivant(p);
end;
if not(exist) then begin
			ecrire('aucan mot existe a la ligne:',14,0);
                        writeln(i);
                   end;
ecrire('printing all words in a ligne ',2,0);
write(i);
ecrire(' has finished............',2,1);
end;
procedure inserer_mot;
var p,q:ptr;
	i,j:integer;
        mot0:string;
begin
writeln;
ecrire('inserer le mot : ',4,1);
readln(mot0);
ecrire('inserer la ligne :',4,1);
readln(i);
ecrire('inserer la columne :',4,1);
readln(j);
ecrire('inserting word...........',2,1);
p:=l;
q:=nil;
while p<>nil do
begin
if (i>=deb_i(p)) and (j>=deb_j(p)) then begin
					q:=p;
                                        allouer(p);
                                        aff_addr(p,addr(q));
					aff_addr(q,p);
                                        aff_mot(p,mot0);
                                        suivant(q);
                                        suivant(q);
                                        aff_deb_i(p,deb_i(q));
                                        aff_deb_j(p,deb_j(q));

                                        aff_fin_i(p,deb_i(p)+length(mot0));
                                        aff_fin_j(p,deb_j(p)+length(mot0));






procedure select;
var ch:char;
begin
writeln;
ecrire('select one of these:',4,1);
writeln('1.choose a file of text');
writeln('2.print the text of file on screen');
writeln('3.creer liste de mots d''un fichier');
writeln('4.print all words of the list');
writeln('5.recherche un mot dans le liste');
writeln('6.donner toute les mots de la columne *j*');
writeln('7.donner toute les mots de la ligne *i*');
writeln('8.inserer un mot dans la ligne i et la columne j');
writeln('9.souvgarde la liste dans fichier texte');
writeln('a.about....');
writeln('x.exit');
ch:=readkey;
case ch of
'1':prepare_fich(select0);
'2':imprime_fich;
'3':creer_list;
'4':imprime_list;
'5':cherch_mot;
'6':mots_columne;
'7':mots_ligne;
'8':;
'9':;
'a':;
end;
if ch<>'x' then select;
end;

procedure fin;
begin
writeln;
ecrire('le programme est fini......',14,1);
readkey;
end;


(**************programme principale******************)
begin
debut;
select;
1:fin;
end.

program finalproject;
                        {Declaration des types et des constantes
                         pour les frequences du repäre}
uses graph,crt;
 type strg=string[6];

 const x0=50;y0=430;q=400;p=500;{x0 et y0 pour les rÇfÇrences de l"origine}

           {Fonction qui calcule l"ÇchÇlle de l"Axe desY}
 function Ey(t:array of real;n:integer):integer;
 var i,k:integer;
     max:real;
 begin
  max:=t[0];
  for i:=1 to n-1 do if max<t[i] then max:=t[i];
  k:=q div (trunc(max)+8)+1;
  Ey:=k; { Ey = ÇchÇlle de Y}
 end;
     {Fonction qui calcule l"ÇchÇlle de l"Axe desX}
 function Ex(n:integer):integer;
  var k:integer;
   begin
    k:=p div (n+2)+1;
    if k>40 then k:=40;
    Ex:=k; {Ex = ÇchÇlle de l"Axe desY}
   end;
       {Procedure M qui calcule le Min,Max,Moy}
 procedure M(t:array of real;n:integer;var moy,min,max:real);
  var i:integer;
      som:real;
   begin
    som:=0;
    min:=t[0];
    max:=t[0];
    for i:=0 to n-1 do
         begin
          som:=som+t[i];
          if min>t[i] then min:=t[i];
          if max<t[i] then max:=t[i];
         end;
    moy:=som/n;
   end;
          {Procedure envire qui trace le repäre et ses caracteristiques}
 procedure envire(Ex,Ey:integer;nx,ny,ux,uy:string;nj:array of strg);
  var i,j,step,nc:integer;
      str0:string;
   begin
    cleardevice;
    setcolor(15);
    settextstyle(0,0,1);
    line(x0,y0,x0,y0-q); {Dessine les deux Axes}
    line(x0,y0,x0+p,y0);
    outtextxy(x0-3,y0-q-3,'^');
    outtextxy(x0+p,y0-3,'Ø');
    setcolor(14);        {Ecrire les noms des deux Axes et leurs UnitÇs}
    outtextxy(x0-45,y0-q-20,concat(ny,' (',uy,')'));
    outtextxy(x0+p-10,y0+30,concat(nx,' (',ux,')'));
    setcolor(15);
    settextstyle(2,0,4);
    for j:=0 to (p div Ex) do
           begin             {Dessine les petits tirÇs dans les deux Axes
                               et ecriver les numeros}
            step:=x0+Ex*j;
            if Ex>25 then outtextxy(step-11+Ex div 2,y0+10,nj[j]);
            line(step,y0,step,y0+2);
           end;

   settextstyle(0,0,1);
   nc:=q div Ey div 20+1;
   for i:=0 to q div (nc*Ey) do
           begin
            str(nc*i,str0);
            step:=y0-nc*Ey*i;
            if Ey>2 then outtextxy(x0-30,step,str0);
            line(x0-2,step,x0,step);
           end;

   {Dessine l"ÇchÇlle des Y dans une fenÇtre dans l"ecran}

   setfillstyle(1,blue);
   setcolor(yellow);
   bar3d(562,103,590,87-nc*Ey,0,true);
   line(570,95,570,95-nc*Ey);
   outtextxy(567,95-nc*Ey-3,'^');
   str(nc,str0);
   outtextxy(580,103-nc*Ey,str0);
   line(568,95,572,95);
   setcolor(green);
   settextstyle(3,0,1);
   if length(nx)<>0 then
      outtextxy(x0+40,y0+25,concat('Histogramme De Repartition Des ',nx))
   else outtextxy(x0+40,y0+25,'                 Histogramme ');
 end;
     {Procedure qui trace les bares gÇometriques de chaque valeur}
 procedure histo(t:array of real;n,Ex,Ey:integer);
  var i,py:integer;
      moy,min,max:real;
      str0:string;
   begin
    settextstyle(2,0,4);
    M(t,n,moy,min,max);
    for py:=1 to 100 do {py:est pour que chaque bare remonte de 1%}
     begin         {dans ce cas tous les bares remonte au mÇme temps}
      if n<20 then delay(20-n);
      for i:=0 to n-1 do
            begin
             str(t[i]:4:1,str0);
             setcolor(white);
             setfillstyle(2,i mod 15+1);
             bar3d(x0+Ex*i,y0-trunc(Ey*t[i]*py/100),x0+Ex*(i+1),y0,0,false);
             if (py>=100) and (Ex>20) then
                   outtextxy(x0+Ex*i+Ex div 2-11,y0-trunc(t[i]*Ey)-14,str0);
            end;                     { Pour ecrire la valeur de t[i] au}
     end;                                    { dessus de la bare }
    setcolor(yellow);
    str(moy:5:2,str0);
    line(x0,y0-trunc(Ey*moy),x0+p,y0-trunc(Ey*moy));
    outtextxy(x0+p+12,y0-trunc(Ey*moy)-5,concat('moy = ',str0));
    if min<>moy then
          begin
           setcolor(red);{Pour tracer les 3 lignes de Min,Max,Moy}
           str(max:5:2,str0);
           line(x0,y0-trunc(Ey*max),x0+p,y0-trunc(Ey*max));
           outtextxy(x0+p+12,y0-trunc(Ey*max)-5,concat('max = ',str0));
           setcolor(green);
           str(min:5:2,str0);
           line(x0,y0-trunc(Ey*min),x0+p,y0-trunc(Ey*min));
           outtextxy(x0+p+12,y0-trunc(Ey*min)-5,concat('min = ',str0));
          end;
   end;
        { Procedure lire qui lit le tableau,les noms des Axes,leurs unitÇs
            de mesures et les classes de l"Axe des X}
 procedure lire(var t:array of real;var n:integer;
                            var nx,ny,ux,uy:string;var nj:array of strg);
   var i,j:integer;
       str0:string;
    begin
     i:=0;
     for i:=0 to 100 do nj[i]:=chr(0);
     i:=0;             {tous les classes de X := un blanc}
     setbkcolor(0);
     setcolor(yellow);
     settextstyle(7,0,1);
     textcolor(green);
     repeat
       cleardevice;
       outtextxy(150,155,'Ajoutez Le Nom de l''Axe Des "X"' );
       outtextxy(150,185,'l''axe X: ');
       gotoxy(30,13);
       read(nx);     {Lire le nom de X}
       readln;
       sound(200);   {son }
       delay(20);
       nosound;
     until length(nx)<15;
     repeat
       cleardevice;
       outtextxy(150,155,concat('Ajoutez L''UnitÇ de Mesure De ',nx) );
       outtextxy(150,185,'L''UnitÇ: ');
       gotoxy(30,13);  {Lire l"unitÇ de mesure de X}
       read(ux);
       readln;
       sound(200);   {son }
       delay(20);
       nosound;
     until length(ux)<6;
      repeat
        cleardevice;
        outtextxy(150,155,'Ajoutez Le Nom De l''Axe Des "Y"' );
        outtextxy(150,185,'l''axe Y: ');
        gotoxy(30,13);   {Lire le nom de Y}
        read(ny);
        readln;
        sound(200);   {son }
        delay(20);
        nosound;

      until  (length(ny)<15);
      repeat
        cleardevice;
        outtextxy(150,155,concat('Ajoutez L''UnitÇ de Mesure De ',ny) );
        outtextxy(150,185,'L''UnitÇ: ');
        gotoxy(30,13); {Lire l"unitÇ de Y}
        read(uy);
        readln;
        sound(200);   {son }
        delay(20);
        nosound;

      until length(uy)<6;
      repeat
        cleardevice;
        outtextxy(150,155,'Ajouter le nombre de valeurs!');
        outtextxy(150,185,'N= ');  {Lire n}
        window(25,13,30,13);
        read(n);
        n:=abs(n);
        sound(200);   {son }
        delay(20);
        nosound;

      until (n<101) and (n<>0);
      cleardevice;
      outtextxy(150,150,'Ajouter les classes maintenent!');
      delay(1000);      {Lire les classes de X}
      cleardevice;
      settextstyle(0,0,1);
      j:=-1;
      for i:=0 to 99 do
             begin
              inc(j,1);
              case j of
               44:j:=46;{Reservation des fenÇtre oó on ecrit les classes}
               57:j:=59;
              end;
              if i<n then setfillstyle(1,j mod 13+1)
                     else setfillstyle(1,15);
              setcolor(15);
              bar3d((j div 13)*80+3,12+32*(j mod 13),
                                   (j div 13)*80+75,34+32*(j mod 13),3,true);
              str(i:2,str0);
              setcolor(0);
              if i<n then  outtextxy((j div 13)*80+15,19+32*(j mod 13),
                                                        concat('N¯: ',str0));
             end;
      setcolor(green);
      settextstyle(4,0,5);
      if length(nx)<>0 then         {Le nom des fenÇtres}
                 outtextxy(20,420,concat('Tableaux des Classes de ',nx))
                 else outtextxy(50,420,'Tableaux des Classes ');
      j:=-1;
      textcolor(14);
      textbackground(0);
      settextstyle(0,0,1);
      for i:=0 to n-1 do
             begin
              inc(j,1);
              case j of
               44:j:=46;  {Pour sauter deux fenÇtres au milieu de l"ecran}
               57:j:=59;
              end;        {Reservation des fenÇtres}
              readln;
              setfillstyle(1,0);
              setcolor(15);
              bar3d(243,172,395,226,3,true);
              window(43,13,47,13);
              outtextxy(260,195,'Ajouter:');
              repeat
              read(nj[i]);   {Lecture des classes}
              until length(nj[i])<7;
              sound(100);
              delay(100);
              nosound;
              setfillstyle(1,j mod 13+1);
              bar3d((j div 13)*80+3,12+32*(j mod 13),
                                    (j div 13)*80+75,34+32*(j mod 13),3,true);
              setcolor(0);   {Ecriture des classes dans les fenÇtre}
              outtextxy((j div 13)*80+20,19+32*(j mod 13),nj[i]);
             end;
      settextstyle(7,0,1);
      setcolor(yellow);
      cleardevice;
      outtextxy(150,150,'Ajouter les valuers maintenent!');
      delay(1000);
      cleardevice;   {Lecture des vleurs des classes}
      settextstyle(0,0,1);
      j:=-1;
      for i:=0 to 99 do
           begin
             inc(j,1);
             case j of
              44:j:=46; {Pour sauter deux fenÇtres au milieu}
              57:j:=59;
             end;
             if i<n then setfillstyle(1,j mod 13+1)
                    else setfillstyle(1,15);
             setcolor(15);  {Pour dessiner les fenÇtres }
             bar3d((j div 13)*80+3,12+32*(j mod 13),
                                   (j div 13)*80+75,34+32*(j mod 13),3,true);
             setcolor(0);
             if i<n then  outtextxy((j div 13)*80+20,19+32*(j mod 13),nj[i]);
           end;
      setcolor(green);
      settextstyle(4,0,5);         {le nom des fenÇtres des valeurs}
      if length(nx)<>0 then outtextxy(120,420,concat('Tableaux de ',nx))
                         else outtextxy(170,420,'Tableaux de donneÇs');
      j:=-1;
      textcolor(14);
      textbackground(0);
      settextstyle(0,0,1);
      for i:=0 to n-1 do
                begin
                 inc(j,1);
                 case j of
                  44:j:=46;
                  57:j:=59;
                 end;
                 setfillstyle(1,0);
                 setcolor(15);
                 bar3d(243,172,395,226,3,true);
                 outtextxy(260,195,'Ajouter:');

                 window(42,13,48,13);
                 repeat      { Lecture des valeurs du l"histogramme}
                 read(t[i])
                 until t[i]<101;
                 sound(100);
                 delay(100);
                 nosound;           {Reservation des fenÇtres}
                 t[i]:=abs(t[i]);
                 setfillstyle(1,j mod 13+1);
                 bar3d((j div 13)*80+3,12+32*(j mod 13),
                                    (j div 13)*80+75,34+32*(j mod 13),3,true);
                 str(t[i]:5:2,str0);
                 setcolor(0);        {Ecriture des valeurs dans les fenÇtres}
                 outtextxy((j div 13)*80+20,19+32*(j mod 13),str0);
                end;
     window(1,1,80,25);
     delay(1000);
    end;
  {procedure qui faire lÇsthetique de sortie}
 procedure FIN(str0,str1:string);
  var i,d:integer;
   begin
    randomize;
    d:=1;
    i:=1;
    repeat
     if (i=0) or (i=15) then d:=-d;
     inc(i,d);
     cleardevice;
     outtextxy(random(640),random(480),'*');
     outtextxy(random(640),random(480),'*');
     setcolor(i+1);
     settextstyle(i mod 5+4,0,i); {Elle change la dimention des deux noms}
     sound(random(12)*20);
     outtextxy(300-18*i,200-10*i,str0);
     outtextxy(300-18*i+random(50)-25,250-5*i,str1);
     setbkcolor(i-1);
     delay(110);
     nosound;
    until keypressed;
    readkey;
   end;
   {procedure qui ecrit une phrase avec un delay entre deux chiffres}
      {en choisissant la couleur et le point de depart}
 procedure txt(d,clr,x,y:integer;str0:string);
  var i:integer;
   begin
    moveto(x,y);
    SETCOLOR(clr);
    i:=0;
    while not(keypressed) and (i<>length(str0)) do
         begin
          inc(i,1);
          if (str0[i]<>' ') and (i mod 2=1) then sound(150);
          outtext(str0[i]);
          delay(5);
          nosound;
          delay(d);
         end;
   end;
   {procedure nvpage pour aller Ö novelle page}
   procedure nvpage(cl:integer);
    var i:integer;
    begin
    setcolor(cl);
    setfillstyle(1,1);
    moveto(0,0);
    i:=0;
    repeat
    i:=i+1 ;
    sound(i div 2+14);
    bar(0,i+1,640,i+20);
    line(0,i,640,i);
    delay(2);
    until (keypressed) or (i=480);
    nosound;
    end;
 {procedure pour afficher la barre de chargement}
 procedure chargement;
 var i:integer;

 begin
 cleardevice;
 setcolor(14);
 setfillstyle(1,1);
 settextstyle(8,0,2);
 rectangle(100,220,540,260);
 outtextxy(245,180,'chargement...');

 for i:=1 to 430 do begin
                    sound(i div 2+25);
                    bar(105,225,105+i,255);
                    delay(5);
                    end;
 nosound;
 end;

 {Procedure pour la presentation ou la page de garde
  utilise la procedure txt pour ecrire des textes}
 procedure Presentation;
  var i:integer;
   begin
   {Introduction}
    nvpage(4);
    settextstyle(8,0,2);
    txt(50,2,20,3,'MINISTERE DE L''ENSEIGNEMENT SUPERIEUR ET DE  ');
    txt(50,2,150,28,' LA RECHERCHE SCIENTIFIQUE ');
    settextstyle(8,0,1);
    txt(50,3,20,75,'*..INSTITUT NATIONAL DE FORMATION EN INFORMATIQUE..*');
    settextstyle(4,0,6);
    txt(120,10,240,95,'* INI *');
    settextstyle(8,0,1);
    txt(50,15,95,160,'*////////.......1"ere ANNEê  T.C ........\\\\\\**');
    txt(50,15,160,205,'**.. PROGET DE FIN DE L''ANNEê ..**');
    settextstyle(8,0,5);
    txt(50,15,10,325,'******* HISTOGRAMME ******');
    settextstyle(8,0,1);
    txt(50,14,560,440,'suite..');
    readkey;
    nvpage(14);
    settextstyle(8,0,3);
    txt(50,1,210,70,'Section : A');
    txt(50,1,210,95,'Groupe : 2');
    settextstyle(8,0,4);
    txt(100,20,140,180,'::***  BINôME n¯:12  ***::');
    settextstyle(7,0,2);
    txt(60,2,100,300,'RealisÇ par : - Assem Chelli');
    txt(60,2,105,325,'             - GuerGour Mohamed');
    settextstyle(8,0,1);
    txt(50,1,560,440,'suite..');
    readkey;
    nvpage(green);
    settextstyle(7,0,3);
    txt(50,4,50,20,'Soyez les bienvenus dans notre projet final');
    settextstyle(7,0,2);
    txt(50,14,70,80,'- Cet programme est realisÇ pour obtenir ');
    txt(50,14,50,110,'Un Histograme de donneÇs variantes ex : (Notes -');
    txt(50,14,50,140,'Etudiants - les Naissances . . . ).');
    txt(50,14,50,170,'et pour cela que chaque fois vous donnez ');
    txt(50,14,50,200,'des valeurs que l''Histogramme donne les ');
    txt(50,14,50,230,'resultat plus rapides et bien precis. . . . .');
    settextstyle(8,0,1);
    txt(50,1,560,440,'suite..');
    readkey;
    cleardevice;             {Esthetique}
    setbkcolor(0);
    settextstyle(4,0,4);
    for i:=1 to 16 do
        begin
         rectangle(5*i,5*i,640-5*i,480-5*i);
         setcolor(i mod 15+1);
        end;
    txt(50,15,100,160,'Pour executer notre programme');
    txt(50,15,90,210,'Appuez sur EntrÇe s''il vous plait!');
    readkey;
    delay(1000);
   end;
   {Procedure qui repÇte l"execution Ö chaque fois}
      { quand on tappe sur Entr  }
 procedure repeter(var btn:char);
  var i:longint;
   begin
    randomize;
    i:=0;
    cleardevice;
    repeat       {Esthetique}
      inc(i,1);
      sound(i div 25+100);
      setcolor(i div 25*3);
      circle(320,240,400-i);
    until i=400;
    nosound;
    setfillstyle(2,blue);
    bar3d(5,210,635,300,0,true);
    repeat
      setcolor(random(14)+2);
      settextstyle(4,0,5);
      sound(random(2)*100+100);
      outtextxy(20,220,'pour repeter appuyez sur "Entree"');
      delay(120);
    until keypressed;
    nosound;
    btn:=readkey;
    if btn<>chr(13) then     {Le teste de repetiton de l"execution}
           begin
             setcolor(red);
             bar3d(5,210,635,300,0,true);
             outtextxy(20,220,'Tank you for using our program.');
             readkey;
             FIN('Assem &','Mohamed');
             end;
    readln;
   end;
                   { Programme prnicipale}
         {Declaration des variables}
 var a,b,n:integer;
     t:array[0..100] of real;
     nj:array[0..100] of strg;
     nx,ny,ux,uy:string;
     btn:char;
  BEGIN
    a:=0;      {Initialisation et test de graph}
    initgraph(a,b,'..\bgi');
    if graphresult=0 then
    begin
         Presentation;
         repeat    {l"Appelles des fonctions et des procedures}
             chargement;
             lire(t,n,nx,ny,ux,uy,nj);
             envire(Ex(n),Ey(t,n),nx,ny,ux,uy,nj);
             histo(t,n,Ex(n),Ey(t,n));
             readkey;
             repeter(btn);
         until btn<>chr(13);
    end
    else
    begin
         clrscr;
         Writeln('il y''a une probläme dans le graph.......');
         readkey;
    end;
  END.         { ****La fin du programme****}

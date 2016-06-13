//---------------------------------------------------------------------------

#include <vcl.h>
#include <atlbase.h>
#pragma hdrstop

#include "main.h"
#include "trans.h"

#include "etat.h"
#include "Unit2.h"
#include "verify.h"
#include "addalphabet.h"
#include "Unit4.h"
#include "Unit5.h"
#include "about.h"
#include "parser.h"
#include "wgv/WinGraphviz.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#pragma resource "manifest.RES"
TForm1 *Form1;
//******************************************
#include <vector.h>
#include <math.h>
//******************************************


/////////////////////////////////////////////////////
////////////variables globales //////////////////////
/////////////////////////////////////////////////////
AnsiString Path,Lab="";
automate * a=new automate,*c;
int d=1,G=-1,fontsize=15;
int nbretat=0;
int ki=0,deb=0,cptM=0,cptU=0,cptI=0,cptF=0,cptS=0,cptC=0,cptP=0;
bool trouv=false,FREE=false,trouve=false,GGactivated=false;
etat *saveinit;
EtatStruct buffetat[50];
transStruct bufftran[100];


/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
int NB_F(etatsfin *f)
{   int nb=0;
for(etatsfin *f0=f;f0!=NULL;f0=f0->Suivant) nb++;
return nb;
}

void Zero(void)
{
  cptS=0;
  cptI=0;
  cptU=0;
  cptF=0;
  cptC=0;
  cptM=0;
  cptP=0;
  addetat->cpt=1;
  }



etatsfin *UnSeule(automate *a)
{   int nb=0;
    etatsfin *fin;

     if (NB_F(a->F)!=1)
 {
    etat *fs=new etat;
   fs->name="F"+IntToStr(cptF);
   fs->Suivant=a->S;
   a->S=fs;


    for(etatsfin *f=a->F;f!=NULL;f=f->Suivant)
        {
        nb++;
   //relier avec la nouvelle etat final
      transition *tr=new transition;
       tr->etatinitial=f->ref;
       tr->etatfinal=fs;
          Alphabet *m=new Alphabet;
          m->mot="";
          m->Suivant=NULL;
       tr->mot=m;
       tr->Suivant=a->I;
       a->I=tr;
        }

   fin=new etatsfin;
   fin->ref=fs;
   fin->Suivant=NULL;

 a->F=fin;
 cptF++;}
 else fin=a->F;

 return fin;
 }



void enable_all(void)
{
Form1->ToolButton3->Enabled=true;
Form1->ToolButton9->Enabled=true;
Form1->Repaint->Enabled=true;
Form1->ToolButton7->Enabled=true;
Form1->ToolButton8->Enabled=true;
Form1->ToolButton10->Enabled=true;
Form1->ToolButton11->Enabled=true;
Form1->ToolButton21->Enabled=true;
Form1->Panel5->Visible=true;
Form1->Panel1->Visible=true;
Form1->Outils1->Enabled=true;
Form1->Automate1->Enabled=true;
Form1->Edition1->Enabled=true;
Form1->Enregistrer1->Enabled=true;
Form1->i1->Enabled=true;
}


automate *NoDouble(automate *a)
{automate *aN=a;
transition *u0;
//eliminate Double transition
bool changed=true;
while (changed)
{  changed=false;
for(transition *t=aN->I;t!=NULL;t=t->Suivant)
{u0=t;
 for(transition *u=t->Suivant;u!=NULL;u=u->Suivant)
 {if (u->etatinitial==t->etatinitial && u->etatfinal==t->etatfinal)
  {for(Alphabet *m=u->mot;m!=NULL;m=m->Suivant)
   {bool found=false;
    for(Alphabet *n=t->mot;n!=NULL;n=n->Suivant)
         {if (n->mot==m->mot) found=true;}
    if (!found) {Alphabet *nouv=new Alphabet;
                 nouv->mot=m->mot;
                 nouv->Suivant=t->mot;
                 t->mot=nouv;
                 changed=true;
                 }
    }
     u0->Suivant=u->Suivant;
    }
   u0=u;
   }
  }
  }
 return aN;
 }

////////////////////////////////////////////////
automate*  automate::Iteration()
{ /*  nouv
 automate *ai=new automate;
 etatsfin *f;
 transition *tr;
 Alphabet *m;
 etat *s=new etat;

 ai->X=this->X;

 ai->I=this->I;
 ai->S=this->S;
 ai->S0=this->S0;
 ai->F=this->F;

 for(f=this->F;f!=NULL;f=f->Suivant)
 {//relier avec l'etat initial
 if (f->ref!=S0)
 {
 tr=new transition;
  tr->etatinitial=f->ref;
  tr->etatfinal=this->S0;
    m=new Alphabet;
    m->mot="";
    m->Suivant=NULL;
  tr->mot=m;
  tr->Suivant=ai->I;
  ai->I=tr;
  }
  if (f->ref!=S0)
 {
 tr=new transition;
  tr->etatfinal=f->ref;
  tr->etatinitial=this->S0;
    m=new Alphabet;
    m->mot="";
    m->Suivant=NULL;
  tr->mot=m;
  tr->Suivant=ai->I;
  ai->I=tr;
  }
  }



 return ai; */

 automate *ai=new automate;
 etatsfin *f;
 transition *tr;
 Alphabet *m;
 etat *s=new etat;

 ai->X=this->X;

 ai->I=this->I;
  //nouvelle etat initial
 s->name="Is"+IntToStr(cptI);
 s->Suivant=this->S;

 //relier la nouvelle etat initial avec l'ancienne
 tr=new transition;
  tr->etatinitial=s;
  tr->etatfinal=S0;
    m=new Alphabet;
    m->mot="";
    m->Suivant=NULL;
  tr->mot=m;
  tr->Suivant=ai->I;
  ai->I=tr;
 //ajouter s dans les liste

 ai->S=s;
 ai->S0=s;

   etat *fs=new etat;
   fs->name="If"+IntToStr(cptI);
   fs->Suivant=ai->S;
   ai->S=fs;

    etatsfin *fin=new etatsfin;
   fin->ref=fs;
   fin->Suivant=NULL;
   ai->F=fin;

  //relier la nouvelle etat initial avec la nouvelle etat final
  tr=new transition;
  tr->etatinitial=s;
  tr->etatfinal=fs;
    m=new Alphabet;
    m->mot="";
    m->Suivant=NULL;
  tr->mot=m;
  tr->Suivant=ai->I;
  ai->I=tr;

 for(f=this->F;f!=NULL;f=f->Suivant)
 {//relier avec l'etat initial
 if (f->ref!=S0)
 {
 tr=new transition;
  tr->etatinitial=f->ref;
  tr->etatfinal=this->S0;
    m=new Alphabet;
    m->mot="";
    m->Suivant=NULL;
  tr->mot=m;
  tr->Suivant=ai->I;
  ai->I=tr;
  }
   //relier avec la nouvelle etat final
  tr=new transition;
  tr->etatinitial=f->ref;
  tr->etatfinal=fs;
    m=new Alphabet;
    m->mot="";
    m->Suivant=NULL;
  tr->mot=m;
  tr->Suivant=ai->I;
  ai->I=tr;
  }

 cptI++;


 return ai;

}










///////////////////////////////////////////////////////
 typedef struct Lderive {Node *node;
                etat  *state;
                string word;
                Lderive *Suivant;
                } Lderive;


 etat *search(string S,Lderive *L)
   {   etat *e=NULL;bool found=false;
   Lderive *i;
      for (i=L;i!=NULL;i=i->Suivant)
      {if (i->word==S) {e=i->state;found=true;}
      };
     if (found) return e;
     else return NULL;
   }

////////////////////////////////////////////////////////////////
void __fastcall TForm2::Button8Click(TObject *Sender)
{   Form2->Close();
int cptE=1,steps=0;
char ch;
  string E=Form2->Edit1->Text.c_str(),E0;
  clean(E);
  Node *N=new Node(E);
  E=mot(N);
  etat *S=new etat,*Sf;
  etatsfin *F;
  transition *T,*Tf;
  Alphabet *m;
  a->F=NULL;


  Lderive *Ld=new Lderive,*Lf,*Lx;
  Ld->node=N;
  Ld->word=E;
  Ld->Suivant=NULL;
        S->name="E0";
        S->Suivant=NULL;
        a->S0=S;
        a->S=S;
        if (final(N))
         {
                        F=new etatsfin;
                        F->ref=S;
                        F->Suivant=NULL;
                        inserer(F,a->F);

                        };
        a->I=NULL;
  Ld->state=S;

  Lf=Ld;
  Sf=S;
  Tf=NULL;

  for (Lderive *i=Ld;i!=NULL;i=i->Suivant)
  {    steps++;if (steps>30) goto fin;
  for (Alphabet *c=a->X;c!=NULL;c=c->Suivant)
   {   ch=c->mot.c_str()[0] ;

   N=derivee(i->node,ch);
    if(N!=NULL) { E0=mot(N);
                //else E0="#";
                        S=search(E0,Ld);
                   if (S==NULL) {Lx=new Lderive;
                                Lx->node=new Node(E0);
                                Lx->word=E0;
                                Lx->Suivant=NULL;
                                                S=new etat;
                                           S->name=S->name="E"+IntToStr(cptE);cptE++;
                                           S->Suivant=NULL;

                                            Sf->Suivant=S;
                                            Sf=S;

                                              if (final(Lx->node))
                                               { F=new etatsfin;
                                                 F->ref=S;
                                                 F->Suivant=NULL;
                                                 inserer(F,a->F);

                                              };

                                  Lx->state=S;
                                  Lf->Suivant=Lx;
                                  if (i==Lf) i->Suivant=Lx;
                                  Lf=Lx;
                               }
                  T=new transition;
                  T->etatfinal=S;
                  T->etatinitial=i->state;

                   m=new Alphabet;
                  m->mot=c->mot;
                  m->Suivant=NULL;

                  T->mot=m;

                  T->Suivant=NULL;

                  if (Tf==NULL) a->I=T;
                  else Tf->Suivant=T;
                  Tf=T;
               };

    };
    delete i->node;
   };
      addetat->Initial->Enabled=false;
      addetat->Initial->Checked=false;
      addetat->cpt++;
      a=NoDouble(a);
      goto apres;
    fin:if (steps>30) {Alphabet *X=a->X;
                           a=new automate;
                           a->X=X;
                           addetat->Initial->Enabled=true;
                           addetat->Initial->Checked=true;
                           addetat->cpt--;
                           }

 apres:repaint(a);

}

AnsiString Scan(AnsiString S)
{    int t=S.Length();
for(int i=1;i<=t;i++)
{for(int j=i+1;j<=t;j++)
{if (S[i]==S[j]) {S.Delete(j,1);j--;t--;};

};
}
return S;
}



void __fastcall TForm1::TrackBar1Change(TObject *Sender)
{
fontsize=TrackBar1->Position;
repaint(a);
}
 //---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton9Click(TObject *Sender)
{
RichEdit1->Print(RichEdit1->Text);
MessageBox(NULL,"le texte est imprimee","success",MB_OK);
}
//---------------------------------------------------------------------------




void __fastcall TForm1::Button10Click(TObject *Sender)
{
 Panel1->Visible=true;
  G=0;
 SpeedButton7Click(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{
Panel1->Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject *Sender)
{
Form2->Show();

}
//---------------------------------------------------------------------------




void __fastcall TForm1::SpeedButton7Click(TObject *Sender)
{
 AnsiString str0="";
 RichEdit1->Clear();
 RichEdit1->Lines->Add("Informations:");
 RichEdit1->Lines->Add("-------");
  if (G==1)
  {
if(a->Test())
{
automate *b;
 Panel1->Visible=true;
 GGactivated=true;
 b=a->amiroir();
 GGactivated=false;
 RichEdit1->Lines->Add("La Grammaire Gauche Est:");
 RichEdit1->Lines->Add("    G< X , V , P , S >");
 RichEdit1->Lines->Add(" { ");
    str0="";
  for(Alphabet *m=b->X;m!=NULL;m=m->Suivant)
 {
  str0+=m->mot+",";
 }
 RichEdit1->Lines->Add("   X={"+str0+" }");
 // ensemble v

    str0="";
 for(etat *e=b->S;e!=NULL;e=e->Suivant)
 {
  str0+=e->name+",";
 }
  RichEdit1->Lines->Add("  V={"+str0+"}");
 // les axioms
 etat *e=b->S0;
 str0="";
 RichEdit1->Lines->Add("   P={ ");
 int i=0;
   bool trouv=false; etatsfin *l=b->F;
   while(!trouv && l!=NULL)
     if(e==l->ref) trouv=true; else l=l->Suivant;
     if(trouv) {str0="    "+e->name+"=> £ ";i=1;}
     else str0="    "+e->name+"=>";
   for(transition *tr1=b->I;tr1!=NULL;tr1=tr1->Suivant)
    if(e==tr1->etatinitial)
     {
      for(Alphabet *m=tr1->mot;m!=NULL;m=m->Suivant)
       {
        if(i!=0) str0+="/";
        i++;
        str0+=tr1->etatfinal->name+"."+m->mot;
       }
     }
    RichEdit1->Lines->Add(str0);
    str0="";
 for(etat *e=b->S;e!=NULL;e=e->Suivant)
  { i=0;
   if(e!=b->S0)
    {
     bool trouv=false; etatsfin *l=b->F;
      while(!trouv && l!=NULL)
     if(e==l->ref) trouv=true; else l=l->Suivant;
     if(trouv) {str0="    "+e->name+"=> £";i=1;}
     else str0="    "+e->name+"=>";
     for(transition *tr1=b->I;tr1!=NULL;tr1=tr1->Suivant)
      if(e==tr1->etatinitial)
       {for(Alphabet *m=tr1->mot;m!=NULL;m=m->Suivant)
        {
         if(i!=0) str0+="/";
         i++;
         str0+=tr1->etatfinal->name+"."+m->mot;
        }
       }
     RichEdit1->Lines->Add(str0);
    }
  }
 RichEdit1->Lines->Add("      }");
 RichEdit1->Lines->Add("     S={ "+b->S0->name+" }");

RichEdit1->Lines->Add(" }");
}
   };
   if (G==0)
   {

if(a->Test())
 {Panel1->Visible=true;

 RichEdit1->Lines->Add("La Grammaire Droite Est:");
 RichEdit1->Lines->Add("    G< X , V , P , S >");
 RichEdit1->Lines->Add(" { ");
    str0="";
  for(Alphabet *m=a->X;m!=NULL;m=m->Suivant)
 {
  str0+=m->mot+",";
 }
 RichEdit1->Lines->Add("   X={"+str0+" }");
 // ensemble v

     str0="";
 for(etat *e=a->S;e!=NULL;e=e->Suivant)
 {
  str0+=e->name+",";
 }
  RichEdit1->Lines->Add("  V={"+str0+"}");
 // les axioms
 etat *e=a->S0;
 str0="";
 RichEdit1->Lines->Add("   P={ ");
 int i=0;
   bool trouv=false; etatsfin *l=a->F;
   while(!trouv && l!=NULL)
     if(e==l->ref) trouv=true; else l=l->Suivant;
     if(trouv) {str0="    "+e->name+"=>£";i=1;}
      else str0="    "+e->name+"=>";
   for(transition *tr1=a->I;tr1!=NULL;tr1=tr1->Suivant)
    if(e==tr1->etatinitial)
     {
      for(Alphabet *m=tr1->mot;m!=NULL;m=m->Suivant)
      {if(i!=0) str0+="/";
       i++;
       str0+=m->mot+"."+tr1->etatfinal->name;
      }
     }
    RichEdit1->Lines->Add(str0);
     str0="";
 for(etat *e=a->S;e!=NULL;e=e->Suivant)
  { i=0;
   if(e->name!=a->S0->name)
    {
     bool trouv=false; etatsfin *l=a->F;
      while(!trouv && l!=NULL)
     if(e->name==l->ref->name) trouv=true; else l=l->Suivant;
     if(trouv) {str0="    "+e->name+"=>£";i=1;}
     else str0="    "+e->name+"=>";
     for(transition *tr1=a->I;tr1!=NULL;tr1=tr1->Suivant)
      if(e->name==tr1->etatinitial->name)
      {for(Alphabet *m=tr1->mot;m!=NULL;m=m->Suivant)
        {
         if(i!=0) str0+="/";
         i++;
         str0+=m->mot+"."+tr1->etatfinal->name;
        }
      }
     RichEdit1->Lines->Add(str0);
    }
  }
  RichEdit1->Lines->Add("      }");
 RichEdit1->Lines->Add("     S={ "+a->S0->name+" }");

RichEdit1->Lines->Add(" }");
  };
 };



  RichEdit1->Lines->Add("-------");

RichEdit1->Lines->Add("----------------------------------------");
RichEdit1->Lines->Add("WordAttacker V1.0 -3SiQ3-AsM&&SoF");
RichEdit1->Lines->Add("----------------------------------------");
}
//---------------------------------------------------------------------------






void __fastcall TForm1::aboutClick(TObject *Sender)
{
about->Show();
}
//---------------------------------------------------------------------------




 void designe_Dot(AnsiString *text)
 {
 const IID IID_IDOT = {0xA1080582,0xD33F,0x486E,{0xBD,0x5F,0x58,0x19,0x89,0xA3,0xC7,0xE9}};
const CLSID CLSID_DOT = {0x55811839,0x47B0,0x4854,{0x81,0xB5,0x0A,0x00,0x31,0xB8,0xAC,0xEC}};

USES_CONVERSION;
HRESULT hr;
IDOT * pIDOT;
IBinaryImage* result_image;
wchar_t *input_text;
short saving_result;

hr = CoInitialize(NULL);

if (FAILED(hr)) {
        MessageBox(NULL,"CoInitialize Failed... " , _T("DOT.ToJPEG"), MB_OK);
        return;
};

hr = CoCreateInstance(CLSID_DOT, NULL, CLSCTX_ALL,
  IID_IDOT, reinterpret_cast<void**>(&pIDOT));

if (FAILED(hr)) {
        MessageBox(NULL,"CoCreateInstance Failed... " , _T("DOT.ToJPEG"), MB_OK);
        return;
};

input_text=new wchar_t[30000];
StringToWideChar(*text,input_text,30000);

hr = pIDOT->ToJPEG(input_text,&result_image);

if (FAILED(hr)) {
        MessageBox(NULL,"ToJPEG Failed... " , _T("DOT.ToJPEG"), MB_OK);
        return;
};

result_image->Save(L"automate.jpg",&saving_result);

Form1->Image1->Picture->LoadFromFile("automate.jpg");
Form1->Image1->Height=Form1->Image1->Picture->Height;
Form1->Image1->Width=Form1->Image1->Picture->Width;

delete[] input_text;
CoUninitialize();
}
//--------------------------------------------------------
void Dot(automate *a,AnsiString *text)
{
transition *i,*jt,*jt0;
 etat *j,*init,*fin;
 etatsfin  *k;
 AnsiString ch="";
  Alphabet *l;





   *text="digraph assem{";
  if (!FREE) *text+="size=\""+FloatToStr(Form1->ScrollBox1->Width/96.2)+","+FloatToStr(Form1->ScrollBox1->Height/96.2)+"\";";
   *text+="rankdir=\"LR\"; ";


  // *text+="0[label=\""+Lab+"\" fontname=\"Arial\" fontsize=\"20\" ];";
   *text+="node[shape=\"circle\" ";
   *text+="fixedsize=\"false\" ";
   *text+="fontsize=\""+IntToStr(fontsize)+"\" ";
   *text+="width=\"0.1\" ";
   *text+="height=\"0.1\"];";
   *text+="edge[fontsize=\""+IntToStr(fontsize)+"\" ";
   *text+="fixedsize=\"false\" ];";

  //dessigner tout les transitions
 for( i=a->I;i!=NULL;i=i->Suivant)
 {
 ch=i->mot->mot;
  if (ch=="") ch="£";

  for(l=i->mot->Suivant;l!=NULL;l=l->Suivant)   {if (l->mot=="") ch=ch+"/£";
                                                  else ch=ch+"/"+l->mot;}


       init=i->etatinitial;
     fin=i->etatfinal;

          *text+=init->name;
          *text+="->";
          *text+=fin->name;
         *text+="[label=\""+ch+"\"color=\"dodgerblue\" arrowsize=\""+FloatToStr(fontsize/12.0)+"\" ];";

     };


//dessigner tout les etats

   for(j=a->S;j!=NULL;j=j->Suivant) *text+=j->name+";";
  //les etats finaux

 for(k=a->F;k!=NULL;k=k->Suivant) *text+=k->ref->name+"[color=\"green\"  peripheries=\"2\"];";
    // l'etat initiale
 if(a->S0!=NULL)
 {if(chercher(a->S0,a->F)) *text+=a->S0->name+"[style=filled color=\"red\" fillcolor=\"lightyellow\" peripheries=\"2\"];";
  else  *text+=a->S0->name+"[style=filled color=\"red\" fillcolor=\"lightyellow\"];";
   }

  *text+="}";
 }

////////////////////////////////////////////////
 etatsfin * automate::accessible()
 {
 transition * i;
  bool find;
  etatsfin * acc=NULL,*j,*k;

 if(S0!=NULL)
 {
 acc=new etatsfin;
  acc->ref=S0;
  acc->Suivant=NULL;
  for(j=acc;j!=NULL;j=j->Suivant)
  {
  for(i=I;i!=NULL;i=i->Suivant)
   {
   if(i->etatinitial==j->ref&&!chercher(i->etatfinal,acc))
      {k=new etatsfin;
       k->ref=i->etatfinal;      //si l'etat initiale de la transition est
       k->Suivant=NULL;           //accessible on ajoute l'etat finale à
       inserer(k,acc);        //l'ensemble des etats accessible
      }
   }
  }
 }
 return acc;
 }
////////////////////////////////////////////////
 etatsfin * automate::coaccessible()
 {
 transition * i;
  etatsfin * coacc=NULL,*j,*k;
  if(F!=NULL)
  {for(j=F;j!=NULL;j=j->Suivant)
   {k=new etatsfin;
    k->ref=j->ref;
    k->Suivant=NULL;
    inserer(k,coacc);
   }
  for(j=coacc;j!=NULL;j=j->Suivant)
  {for(i=I;i!=NULL;i=i->Suivant)
   {if(i->etatfinal==j->ref&&!chercher(i->etatinitial,coacc))
      {k=new etatsfin;
       k->ref=i->etatinitial;
       k->Suivant=NULL;
       inserer(k,coacc);
      }
   }
  }
 }
 return coacc;
 }
////////////////////////////////////////////////
 automate * automate::reduire()
 {etatsfin * acc,*coacc,*red,*i,* j;
  automate * areduite=new automate;
  etat * e,*init,*fin;
  transition*tr,*t;
  bool find,find2;
  areduite->X=this->X;
  acc=this->accessible();
  coacc=this->coaccessible();
  red=intersection(acc,coacc);
  if(red!=NULL)
  {for(i=red;i!=NULL;i=i->Suivant)
   {e=new etat;

    e->name=i->ref->name;
    e->Suivant=areduite->S;
    areduite->S=e;
    if(i->ref==S0)areduite->S0=e;
    find=chercher(i->ref,a->F);
    if(find)
     {j=new etatsfin;
      j->ref=e;
      j->Suivant=areduite->F;
      areduite->F=j;
     }
    }
  for(t=I;t!=NULL;t=t->Suivant)
   {init=areduite->S;
    fin=areduite->S;
    find=chercher(t->etatinitial,init);
    find2=chercher(t->etatfinal,fin);
    if(find&&find2)
     {tr=new transition;
      tr->etatinitial=init;
      tr->etatfinal=fin;
      tr->mot=t->mot;
      tr->Suivant=areduite->I;
      areduite->I=tr;
     }
   }
  }
 return areduite;
}

////////////////////////////////////////////////
automate *automate:: amiroir()
{
automate * am=new automate;
 etat * amS0,* i,* e,*init,*fin;
 etatsfin * l,*f;
 Alphabet *m,*m1;
 transition * tr,*t ;
 int nb=0;

          am->X=this->X;

 for(f=F;f!=NULL;f=f->Suivant) nb++;

 /*if (nb!=1)
        { // l'etat initiale     */
                amS0=new etat;
                amS0->name="M"+IntToStr(cptM);
                if (!GGactivated) cptM++;
                amS0->Suivant=NULL;
      /*          }
        else amS0=this->F->ref;  */

 am->S0=amS0;
 am->S=amS0;

 for(i=this->S;i!=NULL;i=i->Suivant)
 { e=new etat;
   e->name=i->name;
   e->Suivant=am->S;
   am->S=e;
   if(i==S0)
    {am->F=new etatsfin;
     am->F->ref=e;
     am->F->Suivant=NULL;
    }
  //  if (nb!=1)
    {
   if(chercher(i,F))
    {tr=new transition;
     tr->etatinitial=amS0;
     tr->etatfinal=e;
     m=new Alphabet;
     m->mot="";
     m->Suivant=NULL;
     tr->mot=m;
     tr->Suivant=am->I;
     am->I=tr;
    }
    }
 }

 for(t=I;t!=NULL;t=t->Suivant )
    {tr=new transition;
     e=am->S;
     chercher(t->etatfinal,e);
     tr->etatinitial=e;
     e=am->S;
     chercher(t->etatinitial,e);
     tr->etatfinal=e;
     tr->mot=NULL;
     for(m1=t->mot;m1!=NULL;m1=m1->Suivant)
      {m=new Alphabet;
       m->mot=mot_meroire(m1->mot);
       m->Suivant=tr->mot;
       tr->mot=m;
      }
     tr->Suivant=am->I;
     am->I=tr;
    }

 return am;
}
////////////////
automate * automate::Pgeneralise()
{
automate *apg=new automate;
 etat *i,* e,*fin,*ini;
 transition *tr,*t;
 etatsfin * l;
 Alphabet *m,*m1,*m2;
 int cpt=0;
 apg->X=this->X;
 for(i=a->S;i!=NULL;i=i->Suivant)
 {e=new etat;

  e->name=i->name;
  e->Suivant=apg->S;
  apg->S=e;
  if(i==S0) apg->S0=e;
  if(chercher(i,F))
   {l=new etatsfin;
    l->ref=e;
    l->Suivant=apg->F;
    apg->F=l;
   }
 }
for(t=a->I;t!=NULL;t=t->Suivant )
 {m1=NULL;
  ini=apg->S;
  chercher(t->etatinitial,ini);
  fin=apg->S;
  chercher(t->etatfinal,fin);
  for(m2=t->mot;m2!=NULL;m2=m2->Suivant)
   {if(m2->mot.Length()>1)
     {e=ini;
      for(int pos=1;pos<m2->mot.Length();pos++)
       {tr=new transition;
        tr->etatinitial=e;
        m=new Alphabet;
        m->mot=m2->mot[pos];
        m->Suivant=NULL;
        tr->mot=m;
        e=new etat;
        e->name="SI"+IntToStr(cpt);
        cpt++;
        e->Suivant=apg->S;
        apg->S=e;
        tr->etatfinal=e;
        tr->Suivant=apg->I;
        apg->I=tr;
       }
       tr=new transition;
       tr->etatinitial=e;
       m=new Alphabet;
       m->mot=m2->mot[m2->mot.Length()];
       m->Suivant=NULL;
       tr->mot=m;
       tr->etatfinal=fin;
       tr->Suivant=apg->I;
       apg->I=tr;
      }
    else{
         m=new Alphabet;
         m->mot=m2->mot;
         m->Suivant=m1;
         m1=m;
       }
  }
 if(m1!=NULL)
  {tr=new transition;
   tr->etatinitial=ini;
   tr->etatfinal=fin;
   tr->mot=m1;
   tr->Suivant=apg->I;
   apg->I=tr;
  }
 }

 return apg;
}

///////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\
automate *automate::simple()
{automate* asimple;
 etat *i,* e,*fin,*ini;
 transition *tr,*t,*tprec,*t1;
 etatsfin * l;
 Alphabet *m,*m1,*m2,*m3,*mprec;
 asimple=this->Pgeneralise();
 tprec=NULL;
 t=asimple->I;
 while(t!=NULL)
 {mprec=NULL;
  m=t->mot;
  while(m!=NULL)
   {if(m->mot=="")
     {if(t->etatinitial!=t->etatfinal)
      {if(chercher(t->etatfinal,asimple->F)&&!chercher(t->etatinitial,asimple->F))
         {l=new etatsfin;
          l->ref=t->etatinitial;
          l->Suivant=asimple->F;
          asimple->F=l;
         }
       for(t1=asimple->I;t1!=NULL;t1=t1->Suivant )
         {if(t1->etatinitial==t->etatfinal)
           {tr=new transition;
            tr->etatinitial=t->etatinitial;
            tr->etatfinal=t1->etatfinal;
            tr->Suivant=NULL;
            tr->mot=NULL;
            for(m2=t1->mot;m2!=NULL;m2=m2->Suivant)
             {m3=new Alphabet;
              m3->mot=m2->mot;
              m3->Suivant=tr->mot;
              tr->mot=m3;
             }
            inserer(tr,asimple->I);
           }
         }
       }
     if(mprec!=NULL) mprec->Suivant=m->Suivant;
      else{t->mot=t->mot->Suivant;
          }
      m1=m;
      m=m->Suivant;
      delete m1;
    }
    else
     {mprec=m;
      m=m->Suivant;
     }
   }
  if(t->mot==NULL)
    {if(tprec!=NULL)tprec->Suivant=t->Suivant;
     else asimple->I=asimple->I->Suivant;
     t1=t;
     t=t->Suivant;
     delete t1;
    }
   else
     {tprec=t;
      t=t->Suivant;
     }
 }
 return asimple;
}
//
/////////////////////////////////////////////
////////////////////////////////////////////
bool  verif_determ(automate *adet)
 { etat *e=adet->S,*einit;
 transition *tr;
 bool determinist=true;
   Alphabet *q;
   int t[20];
    int max,i;
    automate *b=adet;

  while(determinist && e!=NULL)
   {  max=0;
     for(int i=0;i<20;i++) t[i]=0;//init tab
     einit=e;
     if(b!=NULL)
     for(tr=b->I; tr!=NULL; tr=tr->Suivant)
      { if(tr->etatinitial->name==einit->name )//inserer
         {//rech pos  dans alphabet
           trouv=false;
           q=b->X;
           i=0;
           while(!trouv && q!=NULL)
             if(q->mot==tr->mot->mot) { trouv=true; t[i]++; }
                                        else {i++;q=q->Suivant;}
         }
      }
     //rech max
     for(int i=0;i<20;i++)
          if(max<t[i]) max=t[i];
      // test deterministe
     if(max>1) determinist=false;
     else {e=e->Suivant;}
   }
 return determinist;
 }

////////////////////////////////////////////////

AnsiString lab(etatsfin *ef)
{AnsiString s="";
 for(etatsfin *i=ef;i!=NULL;i=i->Suivant)
  s+=i->ref->name;
 return s;
 }
automate *automate:: deterministe()
{
automate *adet;

 EtatsDet *led,*li,*i;
 etat* e,*Ss, *q=NULL,*p=NULL;
 etatsfin *l,*Fs,*edc;
 transition * Is,*tr;
 Alphabet *m,*c;
 AnsiString s;

 bool stop;
 int cpt=0;

 adet=this->simple();
 if(!verif_determ(adet))
 {
 Fs=adet->F;
 adet->F=NULL;
 Is=adet->I;
 adet->I=NULL;

 l=new etatsfin;
 l->ref=adet->S0;
 l->Suivant=NULL;

 led=new EtatsDet;
 led->etatdet=l;
 led->Suivant=NULL;

 e=new etat;
 e->name=adet->S0->name;
 e->Suivant=NULL;

 if(chercher(adet->S0,Fs))
  {l=new etatsfin;
   l->ref=e;
   l->Suivant=NULL;
   adet->F=l;
  }

 adet->S0=e;
 adet->S=e;
 led->eref=e;
 i=led;

  while(i!=NULL)
  { c=adet->X;
    while(c!=NULL)
      { edc=etat_suivant(i->etatdet,c->mot,Is);

        if(edc!=NULL)
          { trier(edc);
            s=lab(edc);
            stop=false;
            for(e=adet->S;e!=NULL;e=e->Suivant)
              {if(e->name==s)
                 {
                 stop=true;
                  break;
                 }
              }
            if(!stop)
              {


              e=new etat;
               e->name=s;
               e->Suivant=adet->S;
               adet->S=e;
               li=new EtatsDet;
               li->etatdet=edc;
               li->eref=e;
               li->Suivant=NULL ;
               inserer(li,led);
               for(etatsfin *j=edc;j!=NULL;j=j->Suivant)
                 {if(chercher(j->ref,Fs))
                   {l=new etatsfin;
                    l->ref=e;
                    l->Suivant=adet->F;
                    adet->F=l;
                    break;
                   }
                 }
              }
            else liberer(edc);
            tr=new transition;
            tr->etatinitial=i->eref;
            tr->etatfinal=e;
            m=new Alphabet;
            m->mot=c->mot;
            m->Suivant=NULL;
            tr->mot=m;
            tr->Suivant=adet->I;
            adet->I=tr;
          }
       c=c->Suivant;
      }
    i=i->Suivant;
  }
 liberer(led);
 liberer(Is);
 liberer(Fs);

}
//renommer
bool found=false;
for(p=adet->S;p!=NULL;p=p->Suivant)
{   found=false;
for(q=this->S;q!=NULL;q=q->Suivant)
{if (p->name==q->name) {found=true;break;} ;
 }
 if (!found)  {
                p->name="D"+IntToStr(cpt);
                cpt++;
                };


 }

 return adet;
}



//******************complet
automate *automate::complet()
{
automate *acomplet;
 etat *puit;
 Alphabet *m,*mp,*m1;
 transition *tr,*lt=NULL;
 acomplet=this->deterministe();
 puit=new etat;
 puit->name="P"+IntToStr(cptP);cptP++;
 puit->Suivant=NULL;
 for(etat* e=acomplet->S;e!=NULL;e=e->Suivant)
  {m=NULL;
   mp=NULL;
   for(transition* t=acomplet->I;t!=NULL;t=t->Suivant)
    if(e==t->etatinitial) inserer(t->mot,m);
   for(Alphabet *c=X;c!=NULL;c=c->Suivant)
    {if(!chercher(c->mot,m))
      {m1=new Alphabet;
       m1->mot=c->mot;
       m1->Suivant=mp;
       mp=m1;
      }
    }
   if(mp!=NULL)
    {tr=new transition;
     tr->etatinitial=e;
     tr->mot=mp;
     tr->etatfinal=puit;
     tr->Suivant=lt;
     lt=tr;
    }
   liberer(m);
  }
 if(lt!=NULL)
  {mp=NULL;
   for(Alphabet*c=X;c!=NULL;c=c->Suivant)
    {m1=new Alphabet;
     m1->mot=c->mot;
     m1->Suivant=mp;
     mp=m1;
    }
   tr=new transition;
   tr->etatinitial=puit;
   tr->mot=mp;
   tr->etatfinal=puit;
   tr->Suivant=lt;
   lt=tr;
   inserer(lt,acomplet->I);
   puit->Suivant=acomplet->S;
   acomplet->S=puit;
  }
 else liberer(puit);

return acomplet;
}




////////////////////////////////////////////////
automate * automate::complement()
{automate *acomplement;
 etatsfin *l,*f=NULL;
 acomplement=this->complet();
 for(etat * e=acomplement->S;e!=NULL;e=e->Suivant)
  {if(!chercher(e,acomplement->F))
    {l=new etatsfin;
     l->ref=e;
     l->Suivant=f;
     f=l;
    }
  }
 l=acomplement->F;
 acomplement->F=f;
 liberer(l);
 return acomplement;
}
////////////////////////////////////////////////
int automate::reconaitre_mot(AnsiString mot)
{automate * adet;
 bool bloque=false;
 etat *e;
 int i=1,resultat;
 adet=this->deterministe();
 e=adet->S0;

 while(i<=mot.Length()&&!bloque)
  {bloque=true;
   for(transition *t=adet->I;t!=NULL;t=t->Suivant)
    {if(t->etatinitial==e&&chercher(mot[i],t->mot))
      {bloque=false;
       e=t->etatfinal;
       i++;
       break;
      }
    }
  }
 if(!bloque)
   {if(chercher(e,adet->F))resultat=0; //reconu
    else resultat=1;                  // accepté
   }
 else resultat=2;                     //non reconu
 return resultat;
}
////////////////////////////////////////////////
 automate *renommer(automate *b)
  {etat *e;
  bool trouv;
  etat *e1;
  transition *tr;
   for(e=b->S;e!=NULL;e=e->Suivant)
    {tr=b->I;

     AnsiString name="C"+IntToStr(cptC);cptC++;
     while(tr!=NULL)
     {
      if(tr->etatinitial->name==e->name)
       {e->name=name;tr->etatinitial->name=name;}
      if(tr->etatfinal->name==e->name)
       {e->name=name;tr->etatfinal->name=name;}
      tr=tr->Suivant;
     }

   }
   return b;
  }
////////////////////////////////////////////////
   automate *automate::Concatenation(automate *b)
   {
    c=new automate;
    AnsiString m;
    bool trouv;


    b=renommer(b);
    Alphabet *l,*l1=NULL,*l2,*lettre;
     for(l=this->X;l!=NULL;l=l->Suivant)
          {l2=new Alphabet;
          l2->mot=l->mot;
          l2->Suivant=l1;
          l1=l2; }
     for(l=b->X;l!=NULL;l=l->Suivant)
          {
            l2=new Alphabet;
            l2->mot=l->mot;
            l2->Suivant=l1;
            l1=l2;
          }
     c->X=l1;

     //scanning
     AnsiString s="";
  for(Alphabet *m=c->X;m!=NULL;m=m->Suivant)  s+=m->mot;
 s=Scan(s);
 Form1->textYard->Text=s;
     c->X=NULL;

  for(int i=1;i<=s.Length();i++)
   {lettre=new Alphabet;
    lettre->mot=s[i];
    lettre->Suivant=c->X;
    c->X=lettre;
    }
     //les etats
     etat *e,*e1=NULL,*e2;
     for(e=this->S;e!=NULL;e=e->Suivant)
          {
           e2=new etat;

           e2->name=e->name;
           e2->Suivant=e1;
           e1=e2;
           }
     for(e=b->S;e!=NULL;e=e->Suivant)
          {
           e2=new etat;

           e2->name=e->name;
           e2->Suivant=e1;e1=e2;
           }
     c->S=e1;

     //finaux
     etatsfin *le,*le1=NULL,*le2;
     for(le=b->F;le!=NULL;le=le->Suivant)
           {
              le2=new etatsfin;
              e=e1;m=le->ref->name;
              while(!trouv && e!=NULL) if(e->name==m) trouv=true;
                                       else e=e->Suivant;
            if(trouv)
              {  le2->ref=e;
                 le2->Suivant=le1;
                 le1=le2;
              }
           }
      c->F=le1;

     transition *tr,*tr1=NULL,*tr2;
     for(tr=this->I;tr!=NULL;tr=tr->Suivant)
       { tr2=new transition;
         e=e1; trouv=false;
         while(!trouv && e!=NULL )
            if(tr->etatinitial->name==e->name) trouv=true;
            else e=e->Suivant;
         tr2->etatinitial=e;

         e=e1; trouv=false;
         while(!trouv && e!=NULL )
            if(tr->etatfinal->name==e->name) trouv=true;
            else e=e->Suivant;
         if(trouv)
             {
               tr2->etatfinal=e;
               tr2->mot=tr->mot;
               tr2->Suivant=tr1;tr1=tr2;
             }
       }
     for(tr=b->I;tr!=NULL;tr=tr->Suivant)
       { tr2=new transition;
         e=e1; trouv=false;
         while(!trouv && e!=NULL )
            if(tr->etatinitial->name==e->name)trouv=true;
            else e=e->Suivant;

         if( trouv)  tr2->etatinitial=e;
          e=e1; trouv=false;
         while(!trouv && e!=NULL )
            if(tr->etatfinal->name==e->name) trouv=true;
            else e=e->Suivant;

         if(trouv)
         { tr2->etatfinal=e;
           tr2->mot=tr->mot;
           tr2->Suivant=tr1;tr1=tr2;
         }
        }

     Alphabet *mot=new Alphabet;mot->Suivant=NULL;mot->mot="";
     for(le=this->F;le!=NULL;le=le->Suivant)
      {  tr2=new transition;
         e=e1; trouv=false;
         while(!trouv && e!=NULL )
            if(le->ref->name==e->name) trouv=true;
            else e=e->Suivant;
         tr2->etatinitial=e;

         e=e1; trouv=false;
         while(!trouv && e!=NULL )
            if(b->S0->name==e->name) trouv=true;
            else e=e->Suivant;
         tr2->etatfinal=e;
         tr2->mot=mot;
         tr2->Suivant=tr1;tr1=tr2;
      }
      c->I=tr1;
     //etat init
     trouv=false;
      e=c->S;
      m=this->S0->name;
      while(!trouv && e!=NULL) if(e->name==m) trouv=true;
                               else e=e->Suivant;
      if(trouv) c->S0=e;


      // c=NoDouble(c);
      return c;
   }
 ////////////////////////////////////////////////
automate *automate:: Union(automate * b)
{etat *e;
 Alphabet *m,*x,*lettre;
 AnsiString s="";
 transition *tr;

for(e=b->S;e!=NULL;e=e->Suivant)
 {e->name="U"+IntToStr(cptU);
  cptU++;
 }
 automate *Union=this;
 for(m=b->X;m!=NULL;m=m->Suivant)
  {if(!chercher(m->mot,this->X))
    {x=new Alphabet;
     x->mot=m->mot;
     x->Suivant=this->X;
     this->X=x;
    }
  }
 for(m=this->X;m!=NULL;m=m->Suivant)  s+=m->mot;

 s=Scan(s);
 Form1->textYard->Text=s;
     this->X=NULL;
  for(int i=1;i<=s.Length();i++)
   {lettre=new Alphabet;
    lettre->mot=s[i];
    lettre->Suivant=this->X;
    this->X=lettre;
    }

 e=new etat;
 e->name="U0";
 e->Suivant=Union->S;
 Union->S=e;
 tr=new transition;
 tr->etatinitial=e;
 tr->etatfinal=Union->S0;
 m=new Alphabet;
 m->mot="";
 m->Suivant=NULL;
 tr->mot=m;
 tr->Suivant=Union->I;
 Union->I=tr;
 tr=new transition;
 tr->etatinitial=e;
 tr->etatfinal=b->S0;
 m=new Alphabet;
 m->mot="";
 m->Suivant=NULL;
 tr->mot=m;
 tr->Suivant=Union->I;
 Union->I=tr;
 Union->S0=e;
 inserer(b->F,Union->F);
 for(transition *t=b->I;t!=NULL;t=t->Suivant)
 {tr=new transition;
  tr->etatinitial=t->etatinitial;
  tr->etatfinal=t->etatfinal;

  tr->mot=t->mot;
  tr->Suivant=Union->I;
  Union->I=tr;
 }
 e=Union->S;
 while(e->Suivant!=NULL)e=e->Suivant;
 e->Suivant=b->S;

 return Union;
}
//****************métode Test
bool automate::Test()
{if(S0==NULL)
  {ShowMessage("L'automate doit avoir un état initial");
   return false;
  }
 else
 {if(F==NULL){ShowMessage("L'automate doit avoir au moins un état final");
              return false;
             }
  else return true;
 }
}
////////////////////////////////////////////////
etatsfin *etat_suivant(etatsfin* l,AnsiString c,transition *Is)
{transition *t;
 etatsfin * ed=NULL,*j,*k;
 Alphabet *m;
 bool existe;
 while(l!=NULL)
  { t=Is;
    while(t!=NULL)
     {if(t->etatinitial==l->ref)
       { existe=false;
         for(k=ed;k!=NULL;k=k->Suivant)
          {if(k->ref==t->etatfinal)
           {existe=true;
            break;
           }
          }
        if(!existe)
          { m=t->mot;
            while(m!=NULL)
             {if(m->mot==c)
               { j=new etatsfin;
                 j->ref=t->etatfinal;
                 j->Suivant=ed;
                 ed=j;
                 break;
                }
               m=m->Suivant;
             }
          }
       }
      t=t->Suivant;
     }
   l=l->Suivant;
  }
 return ed;
}
//***************Fonction chercher
bool chercher(etat *e,etatsfin *liste)
{bool cont=true;
 etatsfin *i=liste;
 while(i!=NULL&&cont)
 {if(i->ref==e) cont=false;
  else i=i->Suivant;
 }
 return !cont;
}
//***********
bool chercher(etat * e,etat * &liste) //chrche une état dans une liste d'états
{bool cont=true;
 while(liste!=NULL&&cont)
 {if(e->name==liste->name) cont=false;
  else liste=liste->Suivant;
 }
 return !cont;
}
//*************
bool chercher(AnsiString  name,etat *liste )
{bool cont=true;
 while(liste!=NULL&&cont)
 {if(name==liste->name) cont=false;
  else liste=liste->Suivant;
 }
 return !cont;
}
//*************
bool chercher(AnsiString mot,Alphabet*liste)
{bool cont=true;
 Alphabet*m=liste;
 while(m!=NULL&&cont)
 {if(m->mot==mot) cont=false;
  else m=m->Suivant;
 }
 return !cont;
}
//**************Fonction inserer
void inserer(etatsfin *element,etatsfin * &liste)
{etatsfin *i=liste;
 if(liste==NULL) liste=element;
 else
 {while(i->Suivant!=NULL) i=i->Suivant;
  i->Suivant=element;
 }
}
//**************
void inserer(transition *tr,transition * &listetran)
{transition *i=listetran;
 if(listetran==NULL) listetran=tr;
 else
 {while(i->Suivant!=NULL) i=i->Suivant;
  i->Suivant=tr;
 }
}
//******************
void inserer(EtatsDet *l,EtatsDet * &led)
{EtatsDet *i=led;
 if(led==NULL) led=l;
 else
 {while(i->Suivant!=NULL) i=i->Suivant;
  i->Suivant=l;
 }
}
//******************
void inserer(Alphabet*m,Alphabet * &lm)
{Alphabet *m1,*m2=NULL;
 for(Alphabet*c=m;c!=NULL;c=c->Suivant)
  {m1=new Alphabet;
   m1->mot=c->mot;
   m1->Suivant=m2;
   m2=m1;
  }
 if(lm==NULL) lm=m2;
 else
 {for(m1=lm;m1->Suivant!=NULL;m1=m1->Suivant);
  m1->Suivant=m2;
 }
}
//**************Fonction intersection
etatsfin *intersection(etatsfin * l1 ,etatsfin *l2)
{etatsfin *l=NULL,*i,*j,*k;
 for(i=l1;i!=NULL;i=i->Suivant)
 { if(chercher(i->ref,l2))
      {k=new etatsfin;
       k->ref=i->ref;
       k->Suivant=l;
       l=k;
      }
 }
 return l;
}
//*******************mot_méroire
AnsiString mot_meroire(AnsiString mot)
{char c;
 int i,j;
 i=1;
 j=mot.Length();
 while(i<j)
 {c=mot[i];
  mot[i]=mot[j];
  mot[j]=c;
  i++;
  j-- ;
 }
return mot;
}
//**************trier
void trier(etatsfin*liste)
{bool stop=false;
 etatsfin*prec,*l;
 etat *e;
 while(!stop)
  {stop=true;
   prec=liste;
   l=liste->Suivant;
   while(l!=NULL)
    {if(l->ref<prec->ref)
      {e=l->ref;
       l->ref=prec->ref;
       prec->ref=e;
       stop=false;
      }
     prec=l;
     l=l->Suivant;
    }
  }
}

//**************vérifier_mot
bool verifier_mot(AnsiString mot)
{bool appartient=true;
 for(int i=1;i<=mot.Length();i++)
  {if(!chercher(mot[i],a->X))
    {appartient=false;
     break;
    }
  }
 return appartient;
}
//**************liberer une alphabet
void liberer(Alphabet *l)
{Alphabet *l1;
 while(l!=NULL)
 {l1=l;
  l=l->Suivant;
  delete l1;
 }
 }
//**************liberer une listedes etats
void liberer(etat *l)
{etat *l1;
 while(l!=NULL)
 {l1=l;
  l=l->Suivant;
  delete l1;
 }
}
//**************liberer une liste des etats
void liberer(etatsfin *l)
{etatsfin *l1;
 while(l!=NULL)
 {l1=l;
  l=l->Suivant;
  delete l1;
 }
}
//**************liberer une listedes etats
void liberer(EtatsDet *l)
{EtatsDet *l1;
 while(l!=NULL)
 {l1=l;
  l=l->Suivant;
  liberer(l1->etatdet);
  delete l1;
 }
}
//**************liberer une liste des transirions
void liberer(transition *l)
{transition *l1;
 while(l!=NULL)
 {l1=l;
  l=l->Suivant;
  liberer(l1->mot);
  delete l1;
 }
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Etat1Click(TObject *Sender)
{ etat* s;
  etatsfin  *f;
  etat *i;
         // Fetat
         if (a!=NULL) if (a->S0==NULL) {
                                addetat->Initial->Enabled=True;
                                 addetat->Initial->Checked=True;
                                }
        addetat->ShowModal(); //dessigner etat
         if(!chercher(addetat->Edit1->Text,a->S)&&addetat->Edit1->Text!="")
        {
         s=new etat;  //insertion de l'etat
         s->name=addetat->Edit1->Text;
         s->Suivant=a->S;
         a->S=s;
         if(addetat->Final->Checked) //etat final
         {f=new etatsfin ;
          f->ref=s;
          f->Suivant=a->F;
          a->F=f;
          }
         if(addetat->Initial->Checked) //etat initail
         {a->S0=s;
          addetat->Initial->Enabled=false;
          addetat->Initial->Checked=false;
         }

         //dessiger l'etat
         repaint(a);
         }
         else Application->MessageBoxA("etat existe ou non valable","Erreur",0);

  Cursor=crDefault;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Transition1Click(TObject *Sender)
{
 etat *i,*init,*fin;
 transition *tr;
 Alphabet *mot,*x;
 AnsiString s;
 bool init_=false,fin_=false;
  bool cont;

   addtrans->ComboBox1->Items->Clear();
   addtrans->ComboBox2->Items->Clear();
  for(i=a->S;i!=NULL;i=i->Suivant)
  {addtrans->ComboBox1->Items->Add(i->name);
   addtrans->ComboBox2->Items->Add(i->name);
   }
   addtrans->Edit1->Items->Clear();
   addtrans->Edit1->Items->Add("£");
  for(x=a->X;x!=NULL;x=x->Suivant)
  {addtrans->Edit1->Items->Add(x->mot);
   }
 addtrans->ShowModal();
 if (addtrans->Edit1->Text=="£") s=="";
 else  s=addtrans->Edit1->Text;
         //recherche si les deux etats exist
         for(i=a->S;i!=NULL;i=i->Suivant)
         {if (i->name==addtrans->ComboBox1->Text)
                        {
                        init_=true;
                        init=i;

                        }
           if (i->name==addtrans->ComboBox2->Text)
                        {
                         fin_=true;
                        fin=i;
                        }
                        }

         if(init_ && fin_)
          {
                  if (verifier_mot(s))
         {
         mot=new Alphabet;
         mot->mot=s;
         mot->Suivant=NULL;
         //verifier si la trasition existe
         tr=a->I;cont=true;
         while(cont && tr!=NULL)
         {if(tr->etatinitial==init && tr->etatfinal==fin )
           cont=false;
          else tr=tr->Suivant;
         }
          if(cont)//tr n'existe pas-
          {tr=new transition;
           tr->etatinitial=init;
           tr->mot=mot;
           tr->etatfinal=fin;
           tr->Suivant=a->I;
           a->I=tr;
          }
          else   //tr existe
          { cont=true;
           transition *tr1=tr;
           while(cont && tr!=NULL)
            {if(tr->etatinitial==init && tr->etatfinal==fin && tr->mot->mot==s)
             cont=false;
            else tr=tr->Suivant;
             }
            if(!cont)
             Application->MessageBoxA("la transition existe déja!","NOTE!",0);
            else
            {
             mot->Suivant=tr1->mot;
             tr1->mot=mot;
            }
          }
           }
         else Application->MessageBoxA("Mot n'appartanant pas à X*","Erreur",0);
         }
         else if (!init_) Application->MessageBoxA("l'etat init n'existe pas","Erreur",0);
              else     Application->MessageBoxA("l'etat fin n'existe pas","Erreur",0);
      repaint(a);
 
 }
//---------------------------------------------------------------------------;


//---------------------------------------------------------------------------
void repaint(automate *a)
{
 AnsiString text;
  Dot(a,&text);
  designe_Dot(&text);
  
 }


//---------------------------------------------------------------------------

void __fastcall TForm1::Suprimer1Click(TObject *Sender)
{  etat *i;


   Form4->Edit1->Items->Clear();

  for(i=a->S;i!=NULL;i=i->Suivant)  Form4->Edit1->Items->Add(i->name);


Form4->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Rdure1Click(TObject *Sender)
{
 if(a->Test())
  {
    a=a->reduire();
    repaint(a);
  } 
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Mroire1Click(TObject *Sender)
{
 if(a->Test())
  {
   a=a->amiroir();
   repaint(a);
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Simple1Click(TObject *Sender)
{
 if(a->Test())
 {
  a=a->simple();
  repaint(a);
 }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Dterministe1Click(TObject *Sender)
{
 if(a->Test())
  {

     a=a->deterministe();
    repaint(a);
  }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Complet1Click(TObject *Sender)
{if(a->Test())
 {
   a=a->complet();
   repaint(a);
 } 
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Complment1Click(TObject *Sender)
{if(a->Test())
 {
  a=a->complement();
  repaint(a);
 }
}
//-----------------------------------------
void __fastcall Tverify::Button2Click(TObject *Sender)
{
  int i;
 verify->Label3->Visible=true;
  if(verify->Edit1->Text!="")
  {
 if(verify->Edit1->Text!="£")
 {
 if(!verifier_mot(verify->Edit1->Text))

   {
    verify->Label3->Caption="\""+Edit1->Text+"\"\n";
    verify->Label3->Caption=verify->Label3->Caption+"n'appartenant pas à X*";}
 else
  {i=a->reconaitre_mot(verify->Edit1->Text);
   switch(i)
    {case 0:{
             verify->Label3->Caption="\""+Edit1->Text+"\"\n";
             verify->Label3->Caption=verify->Label3->Caption+"reconu"; break;
            }

     case 1:{
             verify->Label3->Caption="\""+Edit1->Text+"\"\n";
             verify->Label3->Caption=verify->Label3->Caption+"Accepté";   break;
            }
     case 2:{
             verify->Label3->Caption="\""+Edit1->Text+"\"\n";
             verify->Label3->Caption=verify->Label3->Caption+"non reconu";break;
            }


    }
  }
 }
 else
  {automate *ad=a->deterministe();
  if(chercher(ad->S0,ad->F))
    {
       verify->Label3->Caption="\""+Edit1->Text+"\"\n";
       verify->Label3->Caption=verify->Label3->Caption+"reconu";
    }
   else {
         verify->Label3->Caption="\""+Edit1->Text+"\"\n";
         verify->Label3->Caption=verify->Label3->Caption+"non reconu";
        }

   }
 }
}
//---------------------------------------------------------------------------

void __fastcall Tverify::BitBtn1Click(TObject *Sender)
{
}
//---------------------------------------------------------------------------

__fastcall Tverify::Tverify(TComponent* Owner)
        : TForm(Owner)
{int i;
 if(verify->Edit1->Text!="" ||verify->Edit1->Text!="£")
 {
 if(!verifier_mot(verify->Edit1->Text))
   verify->Caption="Mot n'appartenant pas à X*";
 else
  {i=a->reconaitre_mot(verify->Edit1->Text);
   switch(i)
    {case 0:verify->Caption="Mot reconu";     break;
     case 1:verify->Caption="Mot accepté";   break;
     case 2:verify->Caption="Mot non reconu";break;
    }
  }
 }
}
//---------------------------------------------------------------------------
void enregistrer()
{int pos=0,nbetat,nbmot,lg=0;
 FILE * fichier;
 char initiale[20];
 char alphabet[20]="";
 strcpy(initiale,a->S0->name.c_str());


        //save(F,Path,X);

 if(Form1->SaveDialog->Execute())
 { Path=Form1->SaveDialog->FileName;
  Form1->Caption="WordAttackerV1.0 -Fichier : "+Path;
 for(Alphabet *m=a->X;m!=NULL;m=m->Suivant)
   {strcat(alphabet,m->mot.c_str());
    lg++;
   }
  for(etat *e=a->S;e!=NULL;e=e->Suivant)
   {strcpy(buffetat[pos].name,e->name.c_str());
    buffetat[pos].finale=chercher(e,a->F);
    pos++;
   }
  nbetat=pos;
  pos=0;
  for(transition *t=a->I;t!=NULL;t=t->Suivant)
   {strcpy(bufftran[pos].init,t->etatinitial->name.c_str());
    strcpy(bufftran[pos].fin,t->etatfinal->name.c_str());
    nbmot=0;
    for(Alphabet *m=t->mot;m!=NULL;m=m->Suivant)
     {strcpy(bufftran[pos].mot[nbmot],m->mot.c_str());
      nbmot++;
     }
    bufftran[pos].nbmot=nbmot;
    pos++ ;
   }
 fichier=fopen(Form1->SaveDialog->FileName.c_str(),"w");
 fwrite(&lg,sizeof(int),1,fichier);
 fwrite(alphabet,sizeof(alphabet),1,fichier);
 fwrite(initiale,sizeof(char),20,fichier);
 fwrite(&nbetat,sizeof(int),1,fichier);
 fwrite(buffetat,sizeof(EtatStruct),nbetat,fichier);
 fwrite(&pos,sizeof(int),1,fichier);
 fwrite(bufftran,sizeof(transStruct),pos,fichier);
 fclose(fichier);
 }
}
//---------------------------------------------------------------------------
automate * ouvrir()
{int nbtr,nbetat,lg;
 FILE * fichier;
 char initiale[20];
 char alphabet[20]="";
 Alphabet *m;
 etat *e;
 transition *tr;
 automate * ouv=NULL;
 etatsfin *l;
 AnsiString s="";



 if(Form1->OpenDialog->Execute())
 {Path=Form1->OpenDialog->FileName;
  Form1->Caption="WordAttackerV1.0 -Fichier : "+Path;
 ouv=new automate;
  fichier=fopen(Form1->OpenDialog->FileName.c_str(),"r");
  fread(&lg,sizeof(int),1,fichier);
  fread(alphabet,sizeof(alphabet),1,fichier);

  Form1->textYard->Text=alphabet;
  for(int i=0;i<lg;i++)
   {m=new Alphabet;
    m->mot=alphabet[i];
    m->Suivant=ouv->X;
    ouv->X=m;
   }
  fread(initiale,sizeof(char),20,fichier);
  fread(&nbetat,sizeof(int),1,fichier);
  fread(buffetat,sizeof(EtatStruct),nbetat,fichier);
  for(int i=0;i<nbetat;i++)
   {e=new etat;
    e->name=buffetat[i].name;
    e->Suivant=ouv->S;
    ouv->S=e;
    if(buffetat[i].finale)
     {l=new etatsfin;
      l->ref=e;
      l->Suivant=ouv->F;
      ouv->F=l;
     }
    if(e->name==initiale) ouv->S0=e;
   }
 fread(&nbtr,sizeof(int),1,fichier);
 fread(bufftran,sizeof(transStruct),nbtr,fichier);
  for(int i=0;i<nbtr;i++)
   {tr=new transition;
    for(e=ouv->S;e!=NULL;e=e->Suivant)
     {s=bufftran[i].init;
     if(s==e->name) break;
    }
     tr->etatinitial=e;
    for(e=ouv->S;e!=NULL;e=e->Suivant)
     {s=bufftran[i].fin;
      if(s==e->name)break;
     }
     tr->etatfinal=e;
    tr->mot=NULL;
    for(int j=0;j<bufftran[i].nbmot;j++)
     {m=new Alphabet;
       m->mot=bufftran[i].mot[j];
      m->Suivant=tr->mot;
      tr->mot=m;
     }
    tr->Suivant=ouv->I;
    ouv->I=tr;
   }
 fclose(fichier);

 }

 return ouv;
}
//----------------------------------------------------------------
void __fastcall TForm1::Ouvrire1Click(TObject *Sender)
{
automate *temp=a;
 a=ouvrir();
 Zero();
 if(a!=NULL)

  {
     addetat->cpt++;
   enable_all();
    addetat->Initial->Enabled=false;
    addetat->Initial->Checked=false;
    if(a->S0==NULL) {   addetat->Initial->Enabled=true;
                        addetat->Initial->Checked=true;
                        addetat->cpt--;

                        } ;



  }
 else a=temp;
   repaint(a);

 }
//---------------------------------------------------------------------------

void __fastcall TForm1::Reconaitreunmot1Click(TObject *Sender)
{verify->Caption="";
 if(a->Test())
 {
  verify->ShowModal();
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Quiter1Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Nouveau1Click(TObject *Sender)
{

deb=0;
 a=new automate;
 Form1->Caption="WordAttacker v1.0 -Fichier : Nouveau";
///////////////nouv alphabet

  Alphabet *lettre;
  a->X=NULL;
  Form3->ShowModal();

  AnsiString s=Form3->textYard->Text;
   s=Scan(s);
   textYard->Text=s;
   Form3->textYard->Text=s;

   //parser tefresh info
   string st=s.c_str();
   chars=st+"£.*U^()";
   operands=st+"£";
   priorityString = "U.^*"+st+"£";

if(s=="")ShowMessage("ensemble d'alphabet vide!");
else
 {
  for(int i=1;i<=s.Length();i++)
   {lettre=new Alphabet;
    lettre->mot=s[i];
    lettre->Suivant=a->X;
    a->X=lettre;
    }
   enable_all();
   addetat->Initial->Enabled=true;
    addetat->Initial->Checked=true;
   repaint(a);
   textYard->ReadOnly=false;
   Zero();
  addetat->cpt=0;

   }


 /////////////////////////



   }


//---------------------------------------------------------------------------


void __fastcall TForm1::Enregistrer1Click(TObject *Sender)
{
 enregistrer();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Union1Click(TObject *Sender)
{ automate * Union,*b ;
 if(a->Test())
  {
    b=ouvrir();
    Union=a->Union(b);
    repaint(Union);
 }

}
//---------------------------------------------------------------------------




void __fastcall TForm1::Image2Click(TObject *Sender)
{
 //automate *adet;
  if(a->Test())
  {
    a=a->amiroir();
    repaint(a);
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image6Click(TObject *Sender)
{
  if(a->Test())
  {

     a=a->deterministe();
    repaint(a);
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image9Click(TObject *Sender)
{if(a->Test())
  {
    a=a->reduire();
    repaint(a);
 }
}
//--------------------------------------------

void __fastcall TForm1::Image7Click(TObject *Sender)
{//if(a->Test())
 {

  a=a->complement();
  repaint(a);
 }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Image3Click(TObject *Sender)
{
 if(a->Test())
 {
   a=a->complet();
   repaint(a);
 }

}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton2Click(TObject *Sender)
{

TrackBar1->Position++;

 }
//---------------------------------------------------------------------------

void __fastcall TForm1::Image1Click(TObject *Sender)
{
if(a->Test())
 {
  a=a->simple();
  repaint(a);
  }
}
//---------------------------------------------------------------------------





void __fastcall TForm1::Image10Click(TObject *Sender)
{
 automate *b=NULL,*ac;
  if(a->Test())
  {   b=ouvrir();
    if(b!=NULL)
       {
        a=a->Concatenation(b);
        }

   repaint(a);

    Form1->textYard->Text="";
   for(Alphabet *c=a->X;c!=NULL;c=c->Suivant)
   {Form1->textYard->Text=Form1->textYard->Text+c->mot;  }
  }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image13Click(TObject *Sender)
{verify->Caption="";
 if(a->Test())
 {
  verify->Show();
 }

}


//---------------------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject *Sender)
{ Panel1->Visible=true;
  G=1;
 SpeedButton7Click(Sender);

   }


//------------------------------------
automate *copy(automate *a)
{ automate *b=new automate;
 //x
 b->X=a->X;
 //etats
 etat *eb;
 for(etat *e=a->S;e!=NULL;e=e->Suivant)
  {eb=new etat;
  eb->name=e->name;
  eb->Suivant=b->S;
  b->S=eb;
  }
 //finaux
 etat *e=b->S; etatsfin *efb;
 for( etatsfin *ef=a->F;ef!=NULL;ef=ef->Suivant)
  {efb=new etatsfin;
   trouv=false;e=b->S;
   while(!trouv && e!=NULL) if(e->name==ef->ref->name) trouv=true; else e=e->Suivant;
   if(trouv)
    {efb->ref=e;efb->Suivant=b->F;b->F=efb;}
  }
  //init
  e=b->S;trouv=false;
  while(!trouv && e!=NULL) if(e->name==a->S0->name) trouv=true; else e=e->Suivant;
  if(trouv) b->S0=e;
  //transition
  transition *tr1;
  for(transition *tr=a->I;tr!=NULL;tr=tr->Suivant)
  {tr1=new transition; e=b->S;trouv=false;
   while(!trouv && e!=NULL) if(tr->etatinitial->name==e->name) trouv=true; else e=e->Suivant;
   tr1->etatinitial=e;e=b->S;
   trouv=false;
   while(!trouv && e!=NULL) if(tr->etatfinal->name==e->name) trouv=true; else e=e->Suivant;
   tr1->etatfinal=e;
   tr1->mot=tr->mot;
   tr1->Suivant=b->I;b->I=tr1;
  }
 return b;
  }
//---------------------------------------------------------------------------




void __fastcall TForm1::Image29Click(TObject *Sender)
{
//automate * ared;
 if(a->Test())
  {
     a=a->reduire();
    repaint(a);
  }
}
//---------------------------------------------------------------------------

 void __fastcall TForm4::Button1Click(TObject *Sender)
{
etat *e,*e1,*e2;etatsfin *ef,*ef1;
 bool trouv=false;



 //supprime etat-
 //supprime de etas finaux

 if(a->S0->name==Form4->Edit1->Text){
                                        a->S0=NULL;
                                        addetat->Initial->Enabled=True;
                                        addetat->Initial->Checked=True;
                                        }
 ef=a->F;ef1=NULL;trouv=false;
 while(ef!=NULL && !trouv)
  {if(ef->ref->name==Form4->Edit1->Text) trouv=true;
   else ef1=ef;ef=ef->Suivant;
  }
  if(trouv)
    {if(ef1==NULL) a->F=a->F->Suivant;
    else ef1->Suivant=ef->Suivant;
   }
 //etats transition
  transition  *tr=a->I,*tr1=NULL;
 while(tr!=NULL)
   {if(tr->etatinitial->name==Form4->Edit1->Text||tr->etatfinal->name==Form4->Edit1->Text)
     if(tr1==NULL) {a->I=tr->Suivant;tr=a->I;}
     else {tr1->Suivant=tr->Suivant;tr=tr->Suivant;}
   else {tr1=tr; tr=tr->Suivant;}
   }

 trouv=false;e1=NULL;e=a->S;
  while(!trouv && e!=NULL)
   if(e->name==Form4->Edit1->Text)trouv=true;
   else {e1=e;e=e->Suivant;}
 if(trouv)
    if(e1==NULL) a->S=e->Suivant;
    else e1->Suivant=e->Suivant;
 else Application->MessageBoxA("L'état n'existe Plus!","ERREUR",0);

 Form4->Close();
if(a!=NULL)
 {
   repaint(a);
 }
}
//-----------------------------
void __fastcall TForm4::Button2Click(TObject *Sender)
{

 Form4->Close();


}

void __fastcall TForm5::Button1Click(TObject *Sender)
{
etat *e,*e1,*e2;etatsfin *ef,*ef1;
 bool trouv=false;



   transition *tr=a->I,*tr1=NULL;
   trouv=false;
   while(!trouv && tr!=NULL)
   {if(tr->etatinitial->name==Form5->Edit2->Text &&
      tr->etatfinal->name==Form5->Edit3->Text)
      trouv=true;

    else {tr1=tr;tr=tr->Suivant;}
    if(trouv)
     {if(tr1==NULL) a->I=tr->Suivant;
      else {tr1->Suivant=tr->Suivant;}
     };
     }
    if (!trouv) Application->MessageBoxA("le transition n'existe Pas","ERREUR",0);

 Form5->Close();
if(a!=NULL)
 {
   repaint(a);
 }
}
//-----------------------------
void __fastcall TForm5::Button2Click(TObject *Sender)
{

 Form5->Close();


}
//-------------------------------------



void __fastcall TForm1::Image14Click(TObject *Sender)
{
 Application->HelpContext(10);
}
//---------------------------------------------------------------------------






void __fastcall TForm1::ToolButton9Click(TObject *Sender)
{
 if(Form1->SavePictureDialog1->Execute())
 Form1->Image1->Picture->SaveToFile(Form1->SavePictureDialog1->FileName);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::SpeedButton8Click(TObject *Sender)
{
 if (SaveDialog2->Execute())
                {RichEdit1->Lines->SaveToFile(SaveDialog2->FileName);}
}



//---------------------------------------------------------------------------


void __fastcall TForm1::ajouterunexpressionreguliere1Click(TObject *Sender)
{
Form2->Show();
}
//---------------------------------------------------------------------------




void __fastcall TForm1::FormCreate(TObject *Sender)
{
deb=0;
 a=new automate;
 Form1->Caption="WordAttacker v1.0 -Fichier : Nouveau";

///////////////nouv alphabet

  Alphabet *lettre;
  a->X=NULL;
  textYard->Text="ab";
  for(int i=1;i<=textYard->Text.Length();i++)
   {lettre=new Alphabet;
    lettre->mot=textYard->Text[i];
    lettre->Suivant=a->X;
    a->X=lettre;
    }

    Image1->Height=Image1->Picture->Height;
    Image1->Width=Image1->Picture->Width;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ToolButton11Click(TObject *Sender)
{
  etat *i;
  

   Form5->Edit2->Items->Clear();
   Form5->Edit3->Items->Clear();

  for(i=a->S;i!=NULL;i=i->Suivant)
  {Form5->Edit2->Items->Add(i->name);
 Form5->Edit3->Items->Add(i->name);
   }

Form5->Show();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::CheckBox1Click(TObject *Sender)
{
TrackBar1->Enabled=CheckBox1->Checked;
SpeedButton2->Enabled=CheckBox1->Checked;
SpeedButton3->Enabled=CheckBox1->Checked;
FREE=!FREE;
if (FREE) fontsize=TrackBar1->Position;
else fontsize=15;
repaint(a);
}
//---------------------------------------------------------------------------




void __fastcall TForm1::Button12Click(TObject *Sender)
{
  if(a->Test())
 {
  a=a->Pgeneralise();
  repaint(a);
  }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::RepaintClick(TObject *Sender)
{
a=NoDouble(a);
repaint(a);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
 automate * Union,*b=NULL;
 if(a->Test())
  {
    b=ouvrir();
    if(b!=NULL)
    {
    Union=a->Union(b);
    repaint(Union);

 }}
}
//---------------------------------------------------------------------------




void __fastcall TForm1::ApplicationEvents1ActionExecute(
      TBasicAction *Action, bool &Handled)
{

StatusBar->SimpleText="Erreur!";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button13Click(TObject *Sender)
{
if(a->Test())
 {
  a=a->Iteration();
  a=NoDouble(a);
  repaint(a);
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton3Click(TObject *Sender)
{

TrackBar1->Position--;
}
//---------------------------------------------------------------------------
 //





 automate *AUTO (Node *N)
 {etat *i,*j=NULL;
 transition *tr=NULL;
 automate *A=new automate;
 if (N!=NULL)
 {

 if (getType(N->text)==OPERAND) { A->X=a->X;

                                  i=new etat;
                                  i->name="S"+IntToStr(cptS);
                                  cptS++;
                                   j=new etat;
                                  j->name="S"+IntToStr(cptS);
                                  cptS++;
                                  j->Suivant=NULL;
                                  i->Suivant=j;

                                  tr=new transition;
                                  tr->etatinitial=i;
                                  tr->etatfinal=j;//->Suivant;
                                        tr->mot=new Alphabet;
                                      if (N->text!='£') tr->mot->mot=N->text;
                                      else tr->mot->mot="";
                                        tr->mot->Suivant=NULL;
                                  tr->Suivant=NULL;

                                  A->F=new etatsfin;
                                  A->F->ref=j;
                                  A->F->Suivant=NULL;

                                  A->S0=i;
                                  A->S=i;
                                  A->I=tr;




                                  }
    else {

        switch (N->text)
                {
                 case '.':A=(AUTO(N->left))->Concatenation(AUTO(N->right));
                        // UnSeule(A);

                                break;
                 case 'U':A=(AUTO(N->left))->Union(AUTO(N->right));
                          //   UnSeule(A);

                                break;
                  case '*':A=(AUTO(N->left))->Iteration();
                            //  UnSeule(A);

                                break;
                 default :A=NULL;
                 };
          }
/*  A=A->simple();
  A=A->reduire() ;
  A=A->deterministe();
  A=NoDouble(A); */
  }
  else A=NULL;
  return (A);
 };
void __fastcall TForm2::BitBtn1Click(TObject *Sender)
{     Form2->Close();
string E=Form2->Edit1->Text.c_str();
clean(E);
Node *N=new Node(E);
Zero();
a=AUTO(N);
a=a->simple();
a=a->reduire() ;
a=a->deterministe();
a=NoDouble(a);
repaint(a);
}


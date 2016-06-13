//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
#include "Unit5.h"
#include "Unit6.h"
#include "Unit7.h"

#include <stdio.h>


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Unit2"
#pragma link "Unit3"
#pragma link "Unit4"
#pragma link "Unit5"
#pragma link "Unit6"
#pragma link "Unit8"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
//-------------------Types--------------

struct info {
                int _n;          //nombre de produits;machines
                int _m;

                int t[128][128];    //tableaux de temp et de sortie
                int s[128][128];
                int o[128];    //ordre et "Best" ordre
                int b[128];


                } X;
typedef info info;
/////////////////////////////////////////

//-----------vars global---------------
int _i=1,_j=1,code;
char st[10];
info buff;
AnsiString Path;
FILE *F;
int exe1=0;

//----------------base---------------

void init(info *x)
{
  int m=(*x)._m,n=(*x)._n;
 for (int k=1;k<=n;k++)
         {
        (*x).b[k]=0; //init best ordre

        for (int l=1;l<=m;l++)
                {(*x).t[k][l]=0;  
                (*x).s[k][l]=0;
                };
        } ;

        //init ordre
      for (int k=1;k<128;k++)  (*x).o[k]=k;
 }

int sortie(int i,int j)
{
int s=0;
if (i==1 || j==1) {
            if (i==1) {
            for (int k=1;k<j+1;k++) { s+=X.t[1][k];}
                        }
            else {
            for (int l=1;l<i+1;l++) { s+=X.t[l][1];}
                        }
                   }
else  {
        s=max(sortie(i-1,j),sortie(i,j-1))+X.t[i][j];
        }
 return(s);
}

void sortie_tous(info *x)
{    int m=(*x)._m,n=(*x)._n;

(*x).s[1][1]=(*x).t[1][1];
for (int l=2;l<m+1;l++) {(*x).s[1][l]=(*x).s[1][l-1]+(*x).t[1][l]; }
for (int k=2;k<n+1;k++) {(*x).s[k][1]=(*x).s[k-1][1]+(*x).t[k][1]; }

for (int l=2;l<m+1;l++)
for (int k=2;k<n+1;k++) {
(*x).s[k][l]=max((*x).s[k-1][l],(*x).s[k][l-1])+(*x).t[k][l];
                        }


 }
 


 void best(info *x,int app)
        {       //declaration vars
                int m=(*x)._m,n=(*x)._n;
                  int s1=0,s2=0,v[128],temp;
                  bool continu=1;

        ///if (n=1) {(*x).b[1]=1;} /*pas de calcul*/
        //else  {
          //remplir tab v
                 for (int k=1;k<n+1;k++)
                {s1=s2=0;
                for (int l=1;l<m+1;l++)
                { if (l!=n) s1+=(*x).t[k][l];
                  if (l!=1) s2+=(*x).t[k][l];
                  };
                  if (s2!=0) {v[k]=s1/s2;}
                        else {v[k]=9999999;};
                  };

         //b=o......
          for (int k=1;k<n+1;k++) {(*x).b[k]=(*x).o[k];};
          while (continu)
          {
          continu=0;
          for (int k=1;k<n;k++)
                { if (v[k+1]<v[k]) { temp=v[k];
                                     v[k]=v[k+1];
                                    v[k+1]=temp;


                                    if (app) {    //le meilleur ordre appliKation
                                    temp=(*x).o[k];
                                    (*x).o[k]=(*x).o[k+1];
                                    (*x).o[k+1]=temp;
                                    for (int l=1;l<=X._m;l++)
                                        {temp=X.t[k][l];
                                        X.t[k][l]=X.t[k+1][l];
                                        X.t[k+1][l]=temp;
                                        };
                                             };

                                    temp=(*x).b[k];
                                    (*x).b[k]=(*x).b[k+1];
                                    (*x).b[k+1]=temp;

                                    continu=1;
                                    };
                };
                };
          //      };
        };










 bool save(FILE *f,AnsiString path,info x)
{
 if ((f = fopen(path.c_str(),"wb"))==0)
        {
        Application->MessageBoxA("error in creating of the File",NULL,MB_OK);
         return(0);
         }
     else {   int test=123456;
        fwrite(&test,sizeof(test),1,f);
        fwrite(&x,sizeof(info)+2,1,f);
         MessageBox(NULL,"the File saved with succes","Succes",MB_OK);
         return(1);
        };
  }

  bool open(FILE *f,AnsiString path,info *x)
  {   if ((f = fopen(path.c_str(),"rb"))==0)
        {
        Application->MessageBoxA("error in openning of the File",NULL,MB_OK);
        return(0);
        }
        else {  int test;

                    fread(&test,sizeof(test),1,f);
               if (test!=123456)
                        {
                        Application->MessageBoxA("le fichier est non valid",NULL,MB_OK);

                         return(0);
                        }
                else {

                        MessageBox(NULL,"the File opened with succes","Succes",MB_OK);
                         fread(x,sizeof(info)+2,1,f);
                        return(1);
                        };


        };

  }




//--------------relations------------------


void __fastcall TForm1::Exit1Click(TObject *Sender)
{
Form1->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::About1Click(TObject *Sender)
{
Form1->Enabled=false;
about->Show();

}
//---------------------------------------------------------------------------





void __fastcall TForm1::Frame21Edit1Change(TObject *Sender)
{
int n;
n=StrToIntDef(Frame21->Edit1->Text,1);
if (n<1)  {n=1;};
if (n>100) {n=100;};
Frame21->Edit1->Text=IntToStr(n);
X._n=n;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Frame21Edit2Change(TObject *Sender)
{
 int m;
m=StrToIntDef(Frame21->Edit2->Text,1);
if (m<1)  {m=1;};
if (m>100) {m=100;};
Frame21->Edit2->Text=IntToStr(m);
X._m=m;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Frame41Edit1Change(TObject *Sender)
{
_i=StrToIntDef(Frame41->Edit1->Text,1);
if (_i<1)  {_i=1;};
if (_i>X._n) {_i=X._n;};
Frame41->Edit1->Text=IntToStr(_i);

if (X.s[_i][_j]==0) {X.s[_i][_j]=sortie(_i,_j);} ;
Frame41->Edit3->Text=IntToStr(X.s[_i][_j] );
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Frame41Edit2Change(TObject *Sender)
{
_j=StrToIntDef(Frame41->Edit2->Text,1);
if (_j<1)  {_j=1;};
if (_j>X._m) {_j=X._m;};
Frame41->Edit2->Text=IntToStr(_j);

if (X.s[_i][_j]==0) {X.s[_i][_j]=sortie(_i,_j);} ;
Frame41->Edit3->Text=IntToStr(X.s[_i][_j] );
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Frame31StringGrid1ColumnMoved(TObject *Sender,
      int FromIndex, int ToIndex)
{ int min,max;
     if (FromIndex>ToIndex) {
                            min=ToIndex;
                            max=FromIndex;
                            }
                        else {
                            min=FromIndex;
                            max=ToIndex;
                            };
      int m=X._m,t;
      Char *st0,*st1;
     for (int k=min;k<=max;k++)
     { st0=Frame31->StringGrid1->Cells[k][0].c_str();
        st1=(st0+7);
       X.o[k]=StrToIntDef(st1,0);
     for (int l=1;l<=m;l++)

     {
     X.t[k][l]=StrToIntDef(Frame31->StringGrid1->Cells[k][l],0);
      }
      }
}
//---------------------------------------------------------------------------




void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{
  PageControl1->Pages[1]->Show();
  Frame21->Edit1->Text=IntToStr(X._n);
  Frame21->Edit2->Text=IntToStr(X._m);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton2Click(TObject *Sender)
{
PageControl1->Pages[2]->Show();

int n=X._n,m=X._m;

Frame31->StringGrid1->ColCount=n+1;
Frame31->StringGrid1->RowCount=m+1;


//

for (int k=1;k<=n;k++)
        {
        Frame31->StringGrid1->Cells[k][0]="Produit "+IntToStr(X.o[k]);
        }
for (int l=1;l<=m;l++)
        {
        Frame31->StringGrid1->Cells[0][l]="Machine "+IntToStr(l);
        }

for (int l=1;l<=m;l++)
 for (int k=1;k<=n;k++)
 {
 Frame31->StringGrid1->Cells[k][l]=IntToStr(X.t[k][l]);
  }

  }
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton3Click(TObject *Sender)
{
 PageControl1->Pages[3]->Show();
Frame41->Edit1->Text=IntToStr(_i);
Frame41->Edit2->Text=IntToStr(_j);

Frame41->Edit3->Text=IntToStr(sortie(_i,_j));

}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton4Click(TObject *Sender)
{
 PageControl1->Pages[4]->Show();
 int n=X._n,m=X._m;

Frame51->StringGrid1->ColCount=n+1;
Frame51->StringGrid1->RowCount=m+1;
//
for (int k=1;k<=n;k++)
        {
        Frame51->StringGrid1->Cells[k][0]="Produit "+IntToStr(X.o[k]);
        }
for (int l=1;l<=m;l++)
        {
        Frame51->StringGrid1->Cells[0][l]="Machine "+IntToStr(l);
        }


 sortie_tous(&X);
 for (int l=1;l<=m;l++)
 for (int k=1;k<=n;k++)
 {
 Frame51->StringGrid1->Cells[k][l]=IntToStr(X.s[k][l]);
  }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton5Click(TObject *Sender)
{
PageControl1->Pages[5]->Show();
best(&X,0);
 int n=X._n;

 Frame81->StringGrid1->ColCount=n+1;

Frame81->StringGrid1->Cells[0][0]="ordre :";
Frame81->StringGrid1->Cells[0][1]="produit :";

for (int k=1;k<=n;k++)
        {
        Frame81->StringGrid1->Cells[k][0]="   "+IntToStr(k);
        Frame81->StringGrid1->Cells[k][1]="Produit "+IntToStr(X.b[k]);
        };
}
//---------------------------------------------------------------------------
//initialisation de tous variables
void __fastcall TForm1::ToolButton1Click(TObject *Sender)
{

for (int k=0;k<PageControl1->PageCount;k++)
                PageControl1->Pages[k]->TabVisible=false;

//PageControl1->Pages[0]->Show();


_i=1;
_j=1;

X._m=1;
X._n=1;
init(&X);

Path="";
Form1->Caption="TimeAttackerV1.0 -Fichier : (nouveau)";
if (exe1 /*&& PageControl1->ActivePageIndex!=1*/) {SpeedButton1Click(Sender);}
else {PageControl1->Pages[0]->Show();}
exe1=1;
SpeedButton7Click(Sender);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton6Click(TObject *Sender)
{
PageControl1->Pages[0]->Show();

}
//---------------------------------------------------------------------------


void __fastcall TForm1::Frame31StringGrid1SetEditText(TObject *Sender,
      int ACol, int ARow, const AnsiString Value)
{
int v;
v=StrToIntDef(Value,0);
//Frame31->StringGrid1->Cells[ACol][ARow]=IntToStr(v);
X.t[ACol][ARow]=v;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Frame31StringGrid1SelectCell(TObject *Sender,
      int ACol, int ARow, bool &CanSelect)
{
Frame31->StringGrid1->SetFocus();
}
//---------------------------------------------------------------------------





void __fastcall TForm1::ToolButton4Click(TObject *Sender)
{
if (SaveDialog1->Execute())
        {
        Path=SaveDialog1->FileName;
        save(F,Path,X);
        Form1->Caption="TimeAttackerV1.0 -Fichier : "+Path;
        }


}
//---------------------------------------------------------------------------

void __fastcall TForm1::ToolButton3Click(TObject *Sender)
{
if (Path!="")   {save(F,Path,X);
                Form1->Caption="TimeAttackerV1.0 -Fichier : "+Path;
                        }
else {Form1->ToolButton4Click(Sender);}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ToolButton2Click(TObject *Sender)
{
 if (OpenDialog1->Execute())
 {
        Path=OpenDialog1->FileName;
        Form1->Caption="TimeAttackerV1.0 -Fichier : "+Path;

        if (open(F,Path,&X))
                {     SpeedButton7Click(Sender);
                switch (PageControl1->ActivePageIndex)
                        {
                        case 0:
                        case 1:Form1->SpeedButton1Click(Sender);break;
                        case 2:Form1->SpeedButton2Click(Sender);break;
                        case 3:Form1->SpeedButton3Click(Sender);break;
                        case 4:Form1->SpeedButton4Click(Sender);break;
                        case 5:Form1->SpeedButton5Click(Sender);break;

                                 };
                };
 };
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Frame31SpeedButton1Click(TObject *Sender)
{
init(&X);
Form1->SpeedButton2Click(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton7Click(TObject *Sender)
{
RichEdit1->Clear();
RichEdit1->Lines->Add("Informations:");
RichEdit1->Lines->Add("-------");
//RichEdit1->Font->Color=clBlue;
RichEdit1->Lines->Add("nombre de produits:"+IntToStr(X._n));
RichEdit1->Lines->Add("nombre de machines:"+IntToStr(X._m));
 RichEdit1->Lines->Add("-------");

  RichEdit1->Lines->Add("Tab de durees du produits");
  AnsiString st;
for (int l=1;l<=X._m;l++)
 { RichEdit1->Lines->Add("**machine="+IntToStr(l));
        st="";
 for (int k=1;k<=X._n;k++)
 {
   st+="->"+IntToStr(X.t[k][l]);
  }
  RichEdit1->Lines->Add(st);
  }
  RichEdit1->Lines->Add("-------");




  RichEdit1->Lines->Add("Tab d'instants du sortie");
 for (int l=1;l<=X._m;l++)
 { RichEdit1->Lines->Add("**machine="+IntToStr(l));
        st="";
 for (int k=1;k<=X._n;k++)
 {
   st+="->"+IntToStr(X.s[k][l]);
  }
  RichEdit1->Lines->Add(st);
  }
  RichEdit1->Lines->Add("-------");


  RichEdit1->Lines->Add("l\'ordre :");
  st="";
  for (int k=1;k<=X._n;k++)
 {
   st+="->"+IntToStr(X.o[k]);
  }
  RichEdit1->Lines->Add(st);
  RichEdit1->Lines->Add("-------");

  RichEdit1->Lines->Add("le mieuer ordre :");
  st="";
  for (int k=1;k<=X._n;k++)
 {
   st+="->"+IntToStr(X.b[k]);
  }
  RichEdit1->Lines->Add(st);
  RichEdit1->Lines->Add("-------");

RichEdit1->Lines->Add("----------------------------------------");
RichEdit1->Lines->Add("TimeAttackerV1.0 -3SiQ3-AsM&SoF");
RichEdit1->Lines->Add("----------------------------------------");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ToolButton8Click(TObject *Sender)
{
Panel2->Visible=!Panel2->Visible;

if (Panel2->Visible) {
                        SpeedButton7Click(Sender);
                        ToolButton8->ImageIndex=18;
                        }
else {
          ToolButton8->ImageIndex=19;
          }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton9Click(TObject *Sender)
{
RichEdit1->Print(RichEdit1->Text);
MessageBox(NULL,"le texte est imprimee","succes",MB_OK);
}
//---------------------------------------------------------------------------







void __fastcall TForm1::SpeedButton8Click(TObject *Sender)
{
if (SaveDialog2->Execute())
                {RichEdit1->Lines->SaveToFile(SaveDialog2->FileName);}

}
//---------------------------------------------------------------------------



void __fastcall TForm1::ToolButton12Click(TObject *Sender)
{
SpeedButton7Click(Sender);
SpeedButton8Click(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ToolButton13Click(TObject *Sender)
{
SpeedButton7Click(Sender);
SpeedButton9Click(Sender);

}
//---------------------------------------------------------------------------





void __fastcall TForm1::Frame81SpeedButton1Click(TObject *Sender)
{

      best(&X,1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ToolButton10Click(TObject *Sender)
{
Application->HelpJump("");
}
//---------------------------------------------------------------------------



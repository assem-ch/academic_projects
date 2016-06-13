//---------------------------------------------------------------------------

#ifndef mainunitH
#define mainunitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <Buttons.hpp>
#include <Dialogs.hpp>
#include <ImgList.hpp>
#include <Graphics.hpp>
#include <jpeg.hpp>
#include <ExtDlgs.hpp>
#include <AppEvnts.hpp>
//---------------------------------------------------------------------------
   typedef struct Alphabet{AnsiString mot;
                    Alphabet *Suivant;
                    } Alphabet;

typedef struct etat{
                    AnsiString name;
                    etat *Suivant ;
                    } etat;


typedef struct transition{etat * etatinitial;
                           Alphabet *mot;
                           etat * etatfinal;
                           transition *Suivant  ;
                          } transition;
typedef struct etatsfin {etat * ref;
                           etatsfin  *Suivant  ;
                          } etatsfin ;



class automate
     {
      public :
         Alphabet *X;
         etat *S;
         etat *S0;
          etatsfin  *F;
      transition *I;


      automate()
                {X=NULL;
                S=NULL;
                S0=NULL;
                F=NULL;
                 I=NULL;
                 }


     automate * simple();
     etatsfin * accessible();
    etatsfin * coaccessible();
    automate * deterministe();
    automate * reduire();
    automate * complet();
    automate * amiroir();
    automate * Pgeneralise();
    automate * complement();
    automate * Union(automate *) ;
    automate* Concatenation(automate *);
    automate* Iteration();

   bool Test();
   int reconaitre_mot(AnsiString mot);
   };

typedef struct {char init[10];
                char fin[10];
                int nbmot;
                char mot[5][5];
               } transStruct;

typedef struct {char name[10];
                int x;
                int y;
                bool finale;
               } EtatStruct;

typedef struct EtatsDet{etatsfin* etatdet;
                              etat* eref;
                              EtatsDet *Suivant ;
                                 }EtatsDet;

 void designe_Dot(AnsiString *text);

void Dot(automate *a,AnsiString *text);
void repaint(automate *a);
void enable_all(void);


bool chercher(etat *,etatsfin *);
bool chercher(etat *,etat * &);
bool chercher(AnsiString  name,etat *liste );
bool chercher(AnsiString mot,Alphabet*liste) ;

void inserer(etatsfin *k,etatsfin * &acc);
void inserer(transition *tr,transition * &listetran);
void inserer(Alphabet*m,Alphabet * &lm);

etatsfin *etat_suivant(etatsfin* l,AnsiString c,transition *Is);
etatsfin *intersection(etatsfin * l1,etatsfin *l2);
AnsiString mot_meroire(AnsiString);

AnsiString Scan(AnsiString S);
bool verifier_mot(AnsiString mot);


void liberer(Alphabet *l);
void liberer(transition *l);
void liberer(etat *l);
void liberer(etatsfin *l);
void liberer(EtatsDet *l);
void inserer(EtatsDet *l,EtatsDet * &led);
void trier(etatsfin*liste);
automate *NoDouble(automate *a);


void enregistrer();
automate* ouvrir();
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TMenuItem *Edition1;
        TMenuItem *Etat1;
        TMenuItem *Transition1;
        TMenuItem *Fichier1;
        TMenuItem *Automate1;
        TMenuItem *Rdure1;
        TMenuItem *Mroire1;
        TMenuItem *Simple1;
        TStatusBar *StatusBar;
        TToolBar *ToolBar1;
        TMenuItem *Dterministe1;
        TMenuItem *Complet1;
        TMenuItem *Complment1;
        TMenuItem *Outils1;
        TMenuItem *Reconaitreunmot1;
        TOpenDialog *OpenDialog;
        TSaveDialog *SaveDialog;
        TMenuItem *Nouveau1;
        TMenuItem *Ouvrire1;
        TMenuItem *Enregistrer1;
        TMenuItem *N1;
        TMenuItem *Quiter1;
        TToolButton *ToolButton1;
        TToolButton *ToolButton2;
        TToolButton *ToolButton3;
        TImageList *ImageList1;
        TMenuItem *Suprimeretat1;
        TMenuItem *Union1;
        TToolButton *ToolButton4;
        TMenuItem *N3;
        TToolButton *ToolButton8;
        TToolButton *ToolButton7;
        TToolButton *ToolButton10;
        TToolButton *ToolButton19;
        TToolButton *ToolButton20;
        TToolButton *ToolButton22;
        TToolButton *ToolButton21;
        TMenuItem *Help1;
        TMenuItem *Sommair1;
        TMenuItem *Aproposde1;
        TPanel *Panel5;
        TLabel *Label11;
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TButton *Button4;
        TButton *Button5;
        TButton *Button6;
        TButton *Button7;
        TButton *Button8;
        TButton *Button10;
        TToolButton *ToolButton9;
        TMenuItem *i1;
        TMenuItem *N4;
        TMenuItem *ajouterunexpressionreguliere1;
        TMenuItem *ajouterungrammaire1;
        TMenuItem *N5;
        TMenuItem *affichergrammaire1;
        TSavePictureDialog *SavePictureDialog1;
        TPanel *Panel1;
        TRichEdit *RichEdit1;
        TPanel *Panel3;
        TSpeedButton *SpeedButton7;
        TSpeedButton *SpeedButton8;
        TSpeedButton *SpeedButton9;
        TSaveDialog *SaveDialog2;
        TButton *Button9;
        TSpeedButton *SpeedButton1;
        TLabel *Label1;
        TLabel *Label2;
        TButton *Button11;
        TMenuItem *Concate1;
        TMenuItem *afficherlagrammairedroite1;
        TToolButton *ToolButton5;
        TTrackBar *TrackBar1;
        TLabel *Label12;
        TToolButton *ToolButton6;
        TMemo *textYard;
        TToolButton *ToolButton11;
        TCheckBox *CheckBox1;
        TMenuItem *Transition2;
        TButton *Button12;
        TMenuItem *Partielmentgeneralise1;
        TMenuItem *N2;
        TToolButton *Repaint;
        TToolButton *ToolButton13;
        TApplicationEvents *ApplicationEvents1;
        TScrollBox *ScrollBox1;
        TImage *Image1;
        TButton *Button13;
        TSpeedButton *SpeedButton2;
        TSpeedButton *SpeedButton3;
        TMenuItem *Iteration1;
        void __fastcall Etat1Click(TObject *Sender);
        void __fastcall Transition1Click(TObject *Sender);
        void __fastcall Suprimer1Click(TObject *Sender);
        void __fastcall Rdure1Click(TObject *Sender);
        void __fastcall Mroire1Click(TObject *Sender);
        void __fastcall Simple1Click(TObject *Sender);
        void __fastcall Dterministe1Click(TObject *Sender);
        void __fastcall Complet1Click(TObject *Sender);
        void __fastcall Complment1Click(TObject *Sender);
        void __fastcall Ouvrire1Click(TObject *Sender);
        void __fastcall Reconaitreunmot1Click(TObject *Sender);
        void __fastcall Quiter1Click(TObject *Sender);
        void __fastcall Nouveau1Click(TObject *Sender);
        void __fastcall Enregistrer1Click(TObject *Sender);
        void __fastcall Union1Click(TObject *Sender);
        void __fastcall Image2Click(TObject *Sender);
        void __fastcall Image6Click(TObject *Sender);
        void __fastcall Image7Click(TObject *Sender);
        void __fastcall Image3Click(TObject *Sender);
        void __fastcall Image9Click(TObject *Sender);
        void __fastcall SpeedButton2Click(TObject *Sender);
        void __fastcall Image1Click(TObject *Sender);
        void __fastcall Image10Click(TObject *Sender);
        void __fastcall Image13Click(TObject *Sender);
        void __fastcall Button9Click(TObject *Sender);
        void __fastcall Image29Click(TObject *Sender);
        void __fastcall Image14Click(TObject *Sender);
        void __fastcall SpeedButton7Click(TObject *Sender);
        void __fastcall aboutClick(TObject *Sender);
        void __fastcall ToolButton9Click(TObject *Sender);
        void __fastcall SpeedButton8Click(TObject *Sender);
        void __fastcall SpeedButton9Click(TObject *Sender);
        void __fastcall Button10Click(TObject *Sender);
        void __fastcall SpeedButton1Click(TObject *Sender);
        void __fastcall Button11Click(TObject *Sender);
        void __fastcall TrackBar1Change(TObject *Sender);
        void __fastcall ajouterunexpressionreguliere1Click(
          TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall ToolButton11Click(TObject *Sender);
        void __fastcall CheckBox1Click(TObject *Sender);
        void __fastcall Button12Click(TObject *Sender);
        void __fastcall RepaintClick(TObject *Sender);
        void __fastcall Button7Click(TObject *Sender);
        void __fastcall ApplicationEvents1ActionExecute(
          TBasicAction *Action, bool &Handled);
        void __fastcall Button13Click(TObject *Sender);
        void __fastcall SpeedButton3Click(TObject *Sender);

private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};




////////////////////////////////////////////////

//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

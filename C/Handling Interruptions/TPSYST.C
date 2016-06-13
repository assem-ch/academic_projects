/*


copyright assem chelli 3siq3

*/

#include <stdio.h>
#include <dos.h>
#include <bios.h>

typedef  unsigned char BYTE;
typedef  unsigned int WORD;
typedef  unsigned long int DOUBLE;

 WORD inv(WORD w)
{
 BYTE *b=&w,x;
 x=*b;
 *b=*(b+1);
 *(b+1)=x;
 return w;
}

DOUBLE invd(DOUBLE d)
{BYTE *b=&d,x,y;
 x=*b;
 *b=*(b+3);
 *(b+3)=x;
 y=*(b+1);
 *(b+1)=*(b+2);
 *(b+2)=y;
 return d;
}


void about(void)
		{
		printf(" \n\n About program:");
		printf("	\n	this program gathers informations about your computer  \
		\n	with using the hardware and Dos interruptions \
		\n	*No Copyright");


		printf("\n\n about programmer 1:");
			printf ("\n 		Name:Assem Chelli");
			printf ("\n 		instute :INI");
			printf ("\n 		group:3SIQ3");
			printf ("\n\n");

			printf("about programmer 2:");
			printf ("\n 		Name:Soufiane Beltas");
			printf ("\n 		instute :INI");
			printf ("\n 		group:3SIQ3");
			printf ("\n\n");

		getch();
		}


void config(void)
{    unsigned int cfg,X;

	 printf("\n\n");
     asm {
	  int 11h;
	  mov cfg,ax;
	  }

 printf("CONFIGURATION:");
 //bit 0 ,7 et 6
 printf("\n\n1:");
 X=cfg/64;
 if (cfg%2==1) {printf("le systeme dispose %d lecteur(s) de disquette",(X%4));}
 else {printf("il n'y a pas des lecteurs de disquettes");}

  //bit 2 et 3
 printf("\n\n2:");
 X=cfg/4;
 printf("la Memoire RAM sur la carte mere est :%d(pc)Ko",(X%4)*16+16,(X%4)*64+64);

//bit 5 et 4  =mode video
printf("\n\n3:");
 X=cfg/16;
 printf("le Mode video lors du lancement du systeme est:");
 switch (X%4)
 {
	case 0:printf("EGA, VGA, or PGA");break;
	case 1:printf("40*25 cara.sur carte couleur");break;
	case 2:printf("80*25 cara.sur carte couleur");break;
	case 3:printf("80*25 cara.sur carte monochrome");break;
}

//bit 8
 printf("\n\n4:");
 X=cfg/256;
 if (X%2==0) {printf("DMA support installed ");}
 else {printf("DMA support not installed ");}

//bits 9,10 et 11 => nb de cartes RS232
 printf("\n\n5:");
 X=cfg/512;
 printf("number of serial ports(RS232) installed is %d",X%8);

 //bit 12
 printf("\n\n6:");
 X=cfg/4096;
 if (X%2==0) {printf("game port installed");}
		else {printf("game port not installed");}

 //bits 13
 printf("\n\n7:");
 X=cfg/8192;
 if (X%2==0) {printf("serial printer attached ");}
else {printf("serial printer not attached ");};

 //bits 14 et 15
 printf("\n\n8:");
 X=cfg/16384;
 printf("number of parallel ports installed= %d",X%4);

 printf("\n*****************************\n");
  getch();
}

void mem()
{
 unsigned int mem,et,big_dx,big_ax,ax64,bx64,cx64,dx64,Telement,Tcache;
 long int a,b,c,d;
 printf("\nla memoire:\n");

     /*asm { mov ah,88h;
	 int 15h;//la memoire etendu
      mov et,ax;}
	  asm{
	  mov ah,8Ah;
		int 15h;//la memoire
		mov big_dx,dx;
		mov big_ax,ax;
		}*/

asm{
      mov ax,0xE801;
      int 15h;//
      mov dx64,dx;
	  mov ax64,ax;
	  mov bx64,bx;
	  mov cx64,cx;

	 }

	  asm {
		int 12h;//la memoire
		mov mem,ax;

	  }
	  asm{
		mov ax,0x4A10;
		mov bx,0x0004
		int 0x2F;
	  mov Tcache,ax;
	  mov Telement,cx;


	 }



 printf("La taille de la memoire de base est : %uko\n",mem);
// printf("La taille de la memoire etendu est : %uko\n",et);
// printf("La taille de la grande memoire etendu est : %umo\n",(big_ax+big_dx*255)/1024);

 a=ax64;
 b=bx64;
 c=cx64;
 d=dx64;


 if (a*b!=0) printf("La taille de la memoire etendu est : %u mo\n",(a+b*64)/1024);
 if (c*d!=0) printf("La taille de la memoire configure est :%u mo\n",(c+d*64)/1024);
 printf("La taille de la memoire Cache est :%g mo(element=%u octets)\n",Telement/1024.*Tcache/1024.,Telement);
 getch();
}


//global vars
unsigned char disks,tetes,sects,_cl,_ch,erreur;
 unsigned int cyls,volume;

void carhard(int n)
{    unsigned char hexa=128+n;
     erreur=0;


     asm {
      mov ah,08h
      mov dl,hexa;
      int 13h
      jc err
      mov disks,dl
      mov tetes,dh
      mov _cl,cl
      mov _ch,ch
      jmp noerr


      }
err:
    erreur=1;
noerr:
}

void errhard(unsigned int _err)
{ switch (_err)
	 {
    case 1:printf("   Numero de fonction non autorise ou lecteur appele absent\n");break;
	case 2 :printf("	Marque d'adresse non trouvée\n");break;
	case 4 :printf("	Secteur non trouve\n");break;
	case 5 :printf("	Erreur lors de réinitialisation contrôleur\n");break;
	case 7 :printf("	Erreur lors d'initialisation du contrôleur\n");break;
	case 9 :printf("	Erreur de transmission DMA : transfert de données par-delà la limite de segment\n");break;
	case 10 :printf("	Secteur défectueux\n");break;
	case 16 :printf("	Erreur de lecture\n");break;
	case 17 :printf("	Erreur de lecture corrigee par ECC\n");break;
	case 32 :printf("	Controleur défectueux\n");break;
	case 64 :printf("	Operation de recherche infructueuse\n");break;
    case 128 :printf("	Lecteur ne répond pas (Time Out)\n");break;
	case 170 :printf("	Lecteur n'est pas pret\n");break;
	case 204 :printf("	Erreur en écriture\n");break;
    default :printf("\n");break;
    }
}

void hard(void)
{
     double size=0;
     float  t,c,s;
     int aff=0;
     printf("\nDisque dur:\n");
     carhard(0);

     if (erreur==1) {printf("Erreur a Disque dur 1:\n");
		    errhard(disks);//en cas de erreur ah:erreur
		     goto second;}
    printf("Le nombre de disques durs est %u\n",disks);
    aff=1;
    if(disks>=1)
      {
       printf("Les caractéristiques du disque dur 1:\n");
       printf("->Le nombre de tetes : %d\n",tetes+1);
       t=tetes+1;
       cyls=_ch+(_cl/64)*256;c=cyls;
       sects=_cl%64;s=sects;
       printf("->Le nombre de cylinders : %d\n",cyls);
       printf("->Le nombre de secteurs : %d\n",sects);
       size=(c/64.0)*(s/8.0)*(t/4.0);

       printf("->Le capacite : %g MO=%g GO\n",size,size/1024);
       if (disks==2){second:
			     carhard(1);
				if (erreur==1) {printf("Erreur a Disque dur 1:\n");
						errhard(disks);//en cas de erreur ah:erreur
						 goto fin;}
    if (aff==0) printf("Le nombre de disques durs est %u\n",disks);
	   printf("Les caractéristiques du disque dur 1:\n");

	      printf("Les caractéristiques du disque dur 1:\n");
       printf("->Le nombre de tetes : %d\n",tetes+1);
       t=tetes+1;
       cyls=_ch+(_cl/64)*256;c=cyls;
       sects=_cl%64;s=sects;
       printf("->Le nombre de cylinders : %d\n",cyls);
       printf("->Le nombre de secteurs : %d\n",sects);
       size=(c/64.0)*(s/8.0)*(t/4.0);

       printf("->Le capacite : %g MO=%g GO\n",size,size/1024);

		  }

       }
 fin:
     printf("***************************");
     getch();

}
void aff_err(unsigned char err)
{printf("\n error (%u):",err);
switch (err)
{
 case 0:printf(" successful completion");break;
 case 1:printf(" invalid function in AH or invalid parameter");break;
 case 2:printf(" address mark not found");break;
 case 3:printf(" disk write-protected");break;
 case 4:printf(" sector not found/read error");break;
 case 5:printf(" reset failed (hard disk)");break;
 case 6:printf(" disk changed (floppy)");break;
 case 7:printf(" drive parameter activity failed (hard disk)");break;
 case 8:printf(" DMA overrun");break;
 case 9:printf(" data boundary error (attempted DMA across 64K boundary or >80h sectors)");break;
 case 10:printf(" bad sector detected (hard disk)");break;
 case 11:printf(" bad track detected (hard disk)");break;
 case 12:printf(" unsupported track or invalid media");break;
 case 13:printf(" invalid number of sectors on format (PS/2 hard disk)");break;
 case 14:printf(" control data address mark detected (hard disk)");break;
 case 15:printf(" DMA arbitration level out of range (hard disk)");break;
 case 16:printf(" uncorrectable CRC or ECC error on read");break;
 case 17:printf(" data ECC corrected (hard disk)");break;
 case 32:printf(" controller failure");break;
 case 49:printf(" no media in drive )");break;
 case 50:printf(" incorrect drive type stored in CMOS (Compaq)");break;
 case 64:printf(" seek failed");break;
 case 128:printf(" timeout (not ready)");break;
 case 170:printf(" drive not ready (hard disk)");break;
 case 176:printf(" volume not locked in drive ");break;
 case 177:printf(" volume locked in drive ");break;
 case 178:printf(" volume not removable ");break;
 case 179:printf(" volume in use ");break;
 case 180:printf(" lock count exceeded ");break;
 case 181:printf(" valid eject request failed ");break;
 case 182:printf(" volume present but read protected ");break;
 case 187:printf(" undefined error (hard disk)");break;
 case 204:printf(" write fault (hard disk)");break;
 case 224:printf(" status register error (hard disk)");break;
 case 255:printf(" sense operation failed (hard disk)");break;
 default :printf(" unknown error ");break;
}
printf("\n");

}
void aff_flags(unsigned int f)
{
int i;
printf("\n\nFlags:");

for(i=0;i<7;i++)
	{
	printf("\n%d.",i);
switch (i) {

 case 0:printf("DMA boundary errors handled transparently=%d",f%2);break;
 case 1:printf("cylinder/head/sectors-per-track information is valid=%d",f%2);break;
 case 2:printf("removable drive=%d",f%2);break;
 case 3:printf("write with verify supported=%d",f%2);break;
 case 4:printf("drive has change-line support =%d",f%2);break;
 case 5:printf("drive can be locked =%d",f%2);break;
 case 6:printf("CHS information set to maximum supported values, not current media=%d",f%2);break;
}
f=f/2;
}
printf("\n\n");

}
void presence(void)
{	char ver;
	printf("\n\n INT 13 Extensions - INSTALLATION CHECK:");

	asm   	{
		mov ah,0x41
		mov bx,0x55AA
		mov dl,0x80
		int 0x13
		jc err
		mov ver,ah
		};
		printf("\nBios extension  supported\nversion:");
		switch (ver)
		{
		case 0x01 :printf(" 1.x\n");break;
		case 0x20 :printf(" 2.0 / EDD-1.0\n");break;
		case 0x21 :printf(" 2.1 / EDD-1.1\n");break;
		case 0x30 :printf(" EDD-3.0\n");break;
		default :printf("!!!!!");
		};

		goto fin;
	err:
	printf("\nBios extension not supported");
	fin:

	printf("\n");
	getch();

	}
unsigned int cylinders(void)
{unsigned int cyls0=0;
	asm {
			mov ah,0xFE
			mov dl,0x80//0x81
			int 0x13
			mov cyls0,dx
		};
		return (cyls0);
		}

void hard48(void)
{ //FP_OFF(tab);
	//FP_SEG(tab);
	//mk_fp(tab);
	//_seg


	int i;
	double totalsect,size1,size2;
	//new
	unsigned long int /*far*/ tab[7];

	union REGS inregs, outregs;
	struct SREGS segregs;
	inregs.h.ah=0x48;
	inregs.h.dl=0x80;
	inregs.x.si =FP_OFF(&tab);
	segregs.ds = FP_SEG(&tab);
	int86x(0x13,&inregs,&outregs,&segregs);
	if(outregs.h.ah!=0)
		aff_err(outregs.h.ah);
		else
	/*old
	unsigned char err;
	unsigned long int _ds *tab;
	for(i=0;i<10;i++){tab[i]=0;};

	 asm {

	 //mov ax,seg tab;
	 //mov ds,ax
	 mov si,offset tab
	 mov ah,0x48
	 mov dl,0x80//ff
	 int 0x13
	 mov err,ah;
	  }

	 aff_err(err);
	 //if (err==0)   < -  -  -  - - - - - - - - - - - - -- - -  - - - - -obligte if*/
	 {
	 printf("\n size buffer=%u\n",tab[0] % 65536);
	 aff_flags(tab[0] / 65536);
	 printf("\n physical cylinders=%u",tab[1]);
	 printf("\n physical heads=%u",tab[2]);
	 printf("\n sectors per track=%u",tab[3]);
	 totalsect=(tab[4])+(tab[5]*256*256*256*256);
	 printf("\n total number of sectors on drive=%u+%u*4294967296",tab[4],tab[5],totalsect/1000000.);
	 printf("\n bytes per sector =%u",tab[6] % 65536);
	 size1=(totalsect*(tab[6] % 65536))/1024/1024/1024;
	 size2=(tab[1]/1024.0)*(tab[2]/1024.)*(tab[3]/1024.)*(tab[6] % 65536);
	 printf("\n\n size drive is:\n  1.total nb of sectors*size sector=%g gigaOctet ",size1);
	 printf("\n  2.sectors*cylinders*heads*size sector=%g go (limite) \n"	,size2);
	 }
	getch();
}

void lectcd()
{ int nbdrive,firstdrive;

asm  {
	mov ax,0x1500
	mov bx,0x0000
	int 0x2f
	mov nbdrive,bx
	mov firstdrive,cx
	};

	printf("\n\nCD drives:");
	printf("\n number of CD-ROM drive letters used=%d",nbdrive);
	printf("\n first letter of CD-ROM drives is =<%c:>",'A'+firstdrive);
	printf("\n\n");
	getch();

	}



	struct address {
				BYTE head;
				WORD cyl_sect;
					};
struct partition {
			BYTE state;
			struct address begin;
			BYTE type;
			struct address end;
			DOUBLE add_sectors;
			DOUBLE nb_sectors;
			};
struct _mbr {
			BYTE boots_computer[446];
			struct partition part[4];
			WORD signature;
			} mbr;

struct _fbr {
				BYTE Jumpcode[2];
				BYTE NOP;
				BYTE OEMname[8];
				WORD BytesPerSector;
				BYTE SectorsPerCluster;
				WORD ReservedSectors;
				BYTE nbFat;
				WORD MaxRootDir;
				WORD nbsectors32mb;
				BYTE MediaDescriptor;
				WORD SectorsPerFATold;
				WORD SectorsPerTrack;
				WORD nbHead;
				DOUBLE nbHiddenSectors;
				DOUBLE nbsectors;
				DOUBLE SectorsPerFATnew;
				WORD Flags;
				BYTE Version[2];
				DOUBLE nbCluster;
				WORD FSIS;
				WORD BBS;
				BYTE reserved[12];
				BYTE nbLogicalDrive;
				BYTE Unused;
				BYTE ExtendedSignature;
				DOUBLE SerialNumber;
				BYTE VolumeName[11];
				BYTE FATname[8];
				BYTE boots_computer[420];
				WORD Signature;
	} fbr;


int partition_type(BYTE type)
{ int a=1;
switch (type)
{
case 0x00 :printf("	Unknown or Nothing");break;
case 0x01 :printf("12-bit FAT");break;
case 0x04 :printf("16-bit FAT (Partition Smallerthan 32MB)");break;
case 0x05 :printf("Extended MS-DOS Partition");break;
case 0x06 :printf("16-bit FAT (Partition Largerthan 32MB)");break;
case 0x0B :printf("32-bit FAT (Partition Up to2048GB)");break;
case 0x0C :printf("32-bit FAT (Partition Up to2048GB) uses LBA1 13h Extensions");break;
case 0x0E :printf("16-bit FAT (Partition Largerthan 32MB) uses LBA1 13h Extensions");break;
case 0x0F :printf("Extended MS-DOS Partition");break;
default :printf("erreur");a=0;break;
}
printf("\n");
return a;
}


int getcyl(WORD x)
{
return(x/256+(x%256)/64);
}
int getsect(WORD x)
{
return(x%64);
}

void FBR(BYTE head,WORD cyl_sect)
{	int i;
union REGS inregs, outregs;
	struct SREGS segregs;
	inregs.h.ah=0x2;
	inregs.h.dl=0x80;
	inregs.h.dh=head;
	inregs.x.cx=cyl_sect;
	inregs.h.al=0x1;
	inregs.x.bx =FP_OFF(&fbr);
	segregs.es = FP_SEG(&fbr);
	int86x(0x13,&inregs,&outregs,&segregs);
	if(outregs.h.ah!=0)
		aff_err(outregs.h.ah);

	else {
    if (fbr.Signature==0xAA55)
	{
	printf("\nFAT32 Boot Record:\n");
	printf("1.jump code=%X%X=jmp %X\n",fbr.Jumpcode[0],fbr.Jumpcode[1],fbr.Jumpcode[1]);
	printf("2.no operation code=%X\n",fbr.NOP);
	//oemname
	printf("X.OEMname:\'");
	for(i=0;i<8;i++) printf("%c",fbr.OEMname[i]);
	printf("\'\n");
	//////////
	printf("3.nombre des bytes par secteur=%u\n",fbr.BytesPerSector);
	printf("4.nombre des secteurs par cluster=%u\n",fbr.SectorsPerCluster);
	printf("5.nombre des secteurs reservee par secteur=%u\n",fbr.ReservedSectors);
	printf("6.nombre des Copies de FAT =%u\n",fbr.nbFat);
	printf("7.Maximum nombre d'entries de repertoire RACINE=%u\n",fbr.MaxRootDir);
	printf("8.nombre de secteur (si volume<32mo)=%u\n",fbr.nbsectors32mb);
	printf("9.Media Descriptor=%X(disque dur =F8)\n",fbr.MediaDescriptor);
	printf("10.Secteurs par FAT(enciene FAT)=%u\n",fbr.SectorsPerFATold);
	printf("11.nombre de Secteurs par piste=%u\n",fbr.SectorsPerTrack);
	printf("12.nombre de tete=%u\n",fbr.nbHead);
	printf("13.nombre de secteurs cache=%u\n",fbr.nbHiddenSectors);
	printf("14.nombre de secteurs dans la partition=%u\n",fbr.nbsectors);
	printf("15.Secteurs par FAT(FAT32)=%u\n",fbr.SectorsPerFATnew);
	printf("..........");
	getch();
	system("cls");
	printf("16.Drapaux=%x\n",fbr.Flags);
	printf("17.la version de FAT32=%u.%u\n",fbr.Version[1],fbr.Version[0]);
	printf("18.nombre de clusters=%u\n",fbr.nbCluster);
	printf("19.FileSystemInformationSector=%u\n",fbr.FSIS);
	printf("20.BackupBootSector(reference au debut)=%u\n",fbr.BBS);
	//printf("=%u\n",fbr.reserved[12]);
	printf("21.number of logical drive=%u\n",fbr.nbLogicalDrive);
	//printf("=%u\n",fbr.Unused);
	printf("22.signature etendu(29h)=%X\n",fbr.ExtendedSignature);
	printf("23.numero de serie=%X\n",invd(fbr.SerialNumber));
	//volume name
	printf("24.nom de volume:\'");
	for(i=0;i<11;i++) printf("%c",fbr.VolumeName[i]);
	printf("\'\n");
	////////////////
	//FAT name
	printf("25.nom de FAT(FAT32):\'");
	for(i=0;i<8;i++) printf("%c",fbr.FATname[i]);
	printf("\'\n");
	////////////////
	//fbr.boots_computer[420];
	printf("26.signature=%X\n",inv(fbr.Signature));
	} else printf("\nFAT32 Boot Record:Erreur\n");
	}
getch() ;
}
void MBR()
{
int i;char ch ;
union REGS inregs, outregs;
	struct SREGS segregs;
	inregs.h.ah=0x2;
	inregs.h.dl=0x80;
	inregs.h.dh=0x0;
	inregs.h.cl=0x1;
	inregs.h.ch=0x0;
	inregs.h.al=0x1;
	inregs.x.bx =FP_OFF(&mbr);
	segregs.es = FP_SEG(&mbr);
	int86x(0x13,&inregs,&outregs,&segregs);
	if(outregs.h.ah!=0)
		aff_err(outregs.h.ah);

	else {printf("\n\nMBR:\n");

 _to:
 system("cls");
 printf("\ Choisez une choix\n");
 printf("   1.afficher code hexa de programme d'amorcage\n");
 printf("   2.afficher la table de partitions\n");
 printf("   3.afficher la signature\n");
 printf("   4.Fat32 Boot Record de la 1ere partition\n");
 printf("   5.Fat32 Boot Record de la 2eme partition\n");
 printf("   6.Fat32 Boot Record de la 3eme partition\n");
 printf("   7.Fat32 Boot Record de la 4eme partition\n");

 printf("   x.return to main menu \n");
 ch=getch();
 system("cls");
 switch (ch)
 {
	case '1':printf("\nle programme d\'ammorcage:\n");
			for(i=0;i!=446;i++)  printf("%X",mbr.boots_computer[i]);

			printf("\n\n");getch();break;
	case '2':for(i=0;i<4;i++) {
							printf("\nPartition %d:\n",i+1);
							//type
							printf("Type:");
							if (partition_type(mbr.part[i].type)|| i==0)
							{
							//state
								switch (mbr.part[i].state)
								{
								case 0x0:printf("etat=non bootable\n");break;
								case 0x80:printf("etat=bootable\n");break;
								default :printf("etat=-----\n");
								}


							//@ debut par secteurs
								printf("address de debut par secteurs:%u\n",mbr.part[i].add_sectors);
							//nb sectors
								printf("nombre de secteurs:%u\n",mbr.part[i].nb_sectors);
							//@debut
							   printf("address debut:(cyl,tete,sect):(%u,%u,%u)\n",getcyl(mbr.part[i].begin.cyl_sect),mbr.part[i].begin.head,getsect(mbr.part[i].begin.cyl_sect));
							//@fin
							   printf("address fin:(cyl,tete,sect):(%u,%u,%u)\
										\n",getcyl(mbr.part[i].end.cyl_sect),mbr.part[i].end.head,getsect(mbr.part[i].end.cyl_sect));
							}
							getch();

							}
		;
		break;
	case '3':printf("signature =%X\n\n",inv(mbr.signature));getch();break;
	case '4':printf("Partition 1:\n");FBR(mbr.part[0].begin.head,mbr.part[0].begin.cyl_sect);break;
	case '5':printf("Partition 2:\n");FBR(mbr.part[1].begin.head,mbr.part[1].begin.cyl_sect);break;
	case '6':printf("Partition 3:\n");FBR(mbr.part[2].begin.head,mbr.part[2].begin.cyl_sect);break;
	case '7':printf("Partition 4:\n");FBR(mbr.part[3].begin.head,mbr.part[3].begin.cyl_sect);break;
	case 'x':goto _ex;
	default :printf("!!");break;
	}

       goto _to;
  _ex:

	}

	};




 void main()
 { char ch ;
  system("0E");

 _toto:

  system("cls");

 printf("\  Choisez une choix\n");
 printf("   1.la configuration\n");
 printf("   2.la taille de la memoire\n");
 printf("   3.les caractéristiques du disque dur(sieze limit‚)\n");
 printf("   4.test de presence d'int 13h ext 48h\n");
 printf("   5.les caractéristiques du disque dur(bios phoinix)(non limit‚)\n");
 printf("   6.le nombre de lectures cd\n");
// printf("   7.le nombre de cylinders\n");
 printf("   8.tables des Partitions\n");
 printf("   a.about\n");
 printf("   x.exit\n");
 ch=getch();
 system("cls");
 switch (ch)
 {
	case '1':config();break;
	case '2':mem();break;
	case '3':hard();break;
	case '4':presence();break;
	case '5':hard48();break;
	case '6':lectcd();break;
     //	case '7':printf("\n\ncylinders=%u\n\n",cylinders());getch();break;
	case '8':MBR();break;
	case 'a':about();break;
	case 'x':goto _exit;
	default :printf("!!");break;
	}
       goto _toto;
  _exit:
	printf("\n ..........");
  getch();
  }

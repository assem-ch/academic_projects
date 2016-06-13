
                  T=search_T(i->state,S,a->I);
                  if (T==NULL) {
                                T=new transition;
                                T->etatfinal=S;
                                T->etatinitial=i->state;
                                T->Suivant=NULL;
                                if (Tf==NULL) a->I=T;
                                  else Tf->Suivant=T;
                                Tf=T;
                                }
                  m=new Alphabet;
                  m->mot=c->mot;
                  m->Suivant=NULL;
                   Alphabet *z,*m1;
                  if (T->mot==NULL) T->mot=m;
                  else {
                        z=T->mot;
                        while (z!=NULL) {
                                                m1=z;
                                                z=z->Suivant;
                                                }
                        z->Suivant=m;
                        }



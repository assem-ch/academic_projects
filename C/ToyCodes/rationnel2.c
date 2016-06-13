/*



*/

#include <stdio.h>
#include <stdlib.h>

typedef struct rationnel {
       int num;
       int den;
       }rationnel;
 int pgcd ( int a , int b ){
     int z;
      if( a == 0 ) z=b;
      else z=pgcd ( (b % a)  , a );
      return z;
      } 
  int ppcm ( int x , int y){
      int z ,m;
      m=pgcd(x,y);
      z=(x*y)/m;
      return z;
      }
      
          
  rationnel reduct ( rationnel x ){
            rationnel z ;
            int t;
            t=pgcd(x.num,x.den);
            printf("%d",t);
            z.num=x.num/t;
            z.den=x.den/t;
            return z;
            }              
 rationnel add( rationnel x , rationnel y ){
               rationnel z ;
               int p = ppcm(x.den, y.den);
               z.num=(x.num*p/x.den)+(y.num*p/y.den);
               z.den=p;
               return z ;
                }
 rationnel sous ( rationnel x , rationnel y){
           rationnel y_neg,z;
           y_neg.num = - y.num;
           y_neg.den = y.den;
           z = add(x,y_neg);
           return z;
           }

 rationnel mult (rationnel x ,rationnel y){
           rationnel z;
           z.num=x.num*y.num;
           z.den=x.den*y.den;
           return z;
           }
 rationnel divi (rationnel x ,rationnel y){
           rationnel z;
           z.num=x.num*y.den;
           z.den=x.den*y.num;
           return z;
           }                                                                                                                       
 main()
{
  rationnel s_red,so_red,p_red,d_red,a,b,s,so,p,d;
  
  printf("\ndonner le numerateur de a :");
  scanf("%d",&a.num);
  printf("donner le denominateur de a :");
  scanf("%d",&a.den);
  printf("donner le numerateur de b :");
  scanf("%d",&b.num);
  printf("donner le denominateur de b :");
  scanf("%d",&b.den);
  s=add(a,b);s_red=reduct(s);
  so=sous(a,b); so_red=reduct(so);
  p=mult(a,b);p_red=reduct(p);
  d=divi(a,b);d_red=reduct(d);
  printf("\nla somme des nombres rationnels est %d/%d ou  %d/%d ",s.num,s.den,s_red.num,s_red.den);
  printf("\nla soustraction des nombres rationnels est %d/%d ou  %d/%d ",so.num,so.den, so_red.num,so_red.den);
  printf("\nla multitlication des nombres rationnels est %d/%d ou  %d/%d ",p.num,p.den, p_red.num,p_red.den);
  printf("\nla la division des nombres rationnels est %d/%d ou  %d/%d ",d.num,d.den,d_red.num,d_red.den);
  system("PAUSE>null");	
  return 0;
}

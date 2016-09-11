#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <time.h>

int myrand(int a)
{
    int g;
    g=rand();
    if(g<0)
        g=g*(-1);
        g=g%a;
        return g;
}

struct player
{
    char name[20];
    float Sposo,pontar;
    int pontoi;
} ;

struct fullo
{
    char arith;
    char symb[15];
    int a3ia;
};

void epanad(struct player a[],int atoma,int s)
{
    char i;
    struct player b[atoma];
    for(i=s;i<atoma;i++)
    {b[i-s]=a[i]; }
    for(i=0;i<s;i++)
    {b[i+atoma-s]=a[i];}
    for(i=0;i<atoma;i++)
    {a[i]=b[i];  }
}
struct fullo moirasm()
{
    struct fullo a;
    char noum[]={'7','8','9','1','J','Q','K','A'},*symb[]={"karo","trifulli","mpastouni","koupa"};
    a.arith=noum[myrand(8)];
    strcpy(a.symb,symb[myrand(4)]);
        if(a.arith=='7')
            a.a3ia=7;
        else
            if(a.arith=='8')
                a.a3ia=8;
            else
                if(a.arith=='9')
                        a.a3ia=9;
                else
                    if(a.arith=='1')
                        a.a3ia=10;
                         else
                            if(a.arith=='J')
                                a.a3ia=2;
                            else
                                if(a.arith=='Q')
                                    a.a3ia=3;
                                else
                                    if(a.arith=='K')
                                            a.a3ia=4;
                                    else
                                        if(a.arith=='A')
                                            a.a3ia=11;
            return a;
}
float pcpontar(int a3ia,float kaba)
{
    if(a3ia>9)
        return kaba/4;
    else
        if (a3ia<5)
            return kaba/8;
            else
                return kaba/6;
}
void niki(int i,struct player a[],float *g)
{
    a[0].Sposo=a[0].Sposo-a[i].pontar;
    printf("%s (mana)exases:%.1f eurw kai to sunoliko poso sou einai:%.1f eurw\n ",a[0].name,a[i].pontar,a[0].Sposo);
    a[i].Sposo=a[i].Sposo+a[i].pontar;
    *g=*g-a[i].pontar;
    printf("%s kerdises!:%.1f eurw kai to sunoliko poso sou einai:%.1f eurw\n ",a[i].name,a[i].pontar,a[i].Sposo);
    printf("twra i kaba einai: %.1f\n",*g);
    a[i].pontar=0;
    a[0].pontoi=0;
    a[i].pontoi=0;
}
void itta(int i,struct player a[],float *g)
{
    a[0].Sposo=a[0].Sposo+a[i].pontar;
    printf("%s (mana)kerdises: %.1f eurw kai to sunoliko poso sou einai:%.1f eurw\n ",a[0].name,a[i].pontar,a[0].Sposo);
    a[i].Sposo=a[i].Sposo-a[i].pontar;
    *g=*g+a[i].pontar;
    printf("%s exases:%.1f eurw kai to sunoliko poso sou einai:%.1f eurw\n ",a[i].name,a[i].pontar,a[i].Sposo);
    printf("twra i kaba einai: %.1f\n",*g);
    a[i].pontar=0;
    a[0].pontoi=0;
    a[i].pontoi=0;
}
void showcard(struct fullo s)
{
     if(s.arith!='1')
     printf("%c ",s.arith);
     else
     printf("10 ");
     puts(s.symb);
}
int main()
{
    char test=1,test2=1,apantisi,apantisi2,test3,test4=1,test5;
    int i,atoma,thmanas,metritis,w,metritis2;
    float posO,kaba,arxkaba;
    struct player *a;
    struct fullo s;
    printf("dwse arithmo atomwn: ");
    srand(time(NULL));
    do{
    scanf("%d",&atoma);}
    while(atoma<=1);
    fflush(stdin);
    printf("dwse arxiko poso: ");
    scanf("%f",&posO);
    a=(struct player *) calloc(atoma,sizeof(struct player));
    for(i=0;i<atoma;i++)
     {
        if (i==0)
        {
            a[0].Sposo=posO;
            strcpy(a[0].name,"pc");
            printf("stin 8esi 1 ka8ete to pc\n");
        }
        else
        {
            fflush(stdin);
            printf("dwse onoma paixti stin 8esi %d: ",i+1);
            gets(a[i].name);
            a[i].Sposo=posO;
        }
     }
     thmanas=myrand(atoma)-1;// afairrw ena giati molis mpw ston parakatw vrogxo pros8etw ena
     while(test)
     {
        thmanas=thmanas++;
        epanad(a,atoma,thmanas);
        thmanas=0;
        metritis2=0;
        test5=0;
        printf("mana einai o paixtis: %s\n",a[0].name);
        if(strcmp(a[0].name,"pc")==0)
            kaba=(a[0].Sposo)/6;
            else
                {

                    do{printf("mana pes poso 8es na einai i kaba: ");
                    scanf("%f",&kaba);
                    }while(kaba>a[0].Sposo);
                    arxkaba=kaba;
                }
        printf("i kaba einai %.1f\n",kaba);
                test2=1;
        while (test2)
        {
            puts("ksekinaei to moirasma tis  guras ");
            for(i=1;i<atoma;i++)
            {if(a[i].Sposo!=0){
                s=moirasm();
                    printf("to prwto fullo tou paixti %s einai : ",a[i].name);
                    showcard(s);
                    a[i].pontoi=s.a3ia;
                    printf("exeis %d pontous! \n",a[i].pontoi);
                    do
                    {
                        printf("gia na sunexisoume ston epomeno paixti pata (y/n): ");
                        fflush(stdin);
                        scanf("%c",&apantisi2);
                    }while(apantisi2!='y');
                    }
                else
                { printf("o paiktis %s exei xasei ola ta lefta tou! sunaxizoume me ton epomeno paixti\n",a[i].name);}
            }
            s=moirasm();
            printf("to prwto fullo tou %s pou einai kai i mana einai: ",a[0].name);
            showcard(s);
            a[0].pontoi=s.a3ia;
            printf("exeis %d pontous! \n",a[0].pontoi);
           for(i=1;((i<atoma)&&test2);i++)
            {test3=1;
            if (a[i].Sposo!=0)
            {
              if(arxkaba==(kaba/3))
                    {
                        puts("i mana 3plasiase tin kaba tis! 8a paixtei mia teleutaia gura!!");
                        test5=1;
                    }
                    if(test5)
                        metritis2++;
                   metritis=0;
                if(strcmp(a[i].name,"pc")!=0)
                    {
                         do
                         {
                            printf("%s dwse pontarisma: ",a[i].name);
                            scanf("%f",&a[i].pontar);
                         }while((kaba<a[i].pontar)&&(kaba<a[i].Sposo));
                        printf("%s theleis allo fullo ??? (y/n): ",a[i].name);
                        metritis++;
                        fflush(stdin);
                        scanf("%c",&apantisi);
                        while(apantisi=='y')
                            {
                                s=moirasm();
                                metritis=metritis++;
                                printf("to epomeno fullo sou einai: ");
                               showcard(s);
                                a[i].pontoi=s.a3ia+a[i].pontoi;
                                if(((metritis!=2)||(a[i].pontoi!=22)))
                                printf("exeis %d pontous\n",a[i].pontoi);
                            if((metritis==2)&&(a[i].pontoi==22))
                                {
                                    puts("exeis 21 pontous! ");
                                    niki(i,a,&kaba);
                                    apantisi='n';
                                }
                                else
                                    if(a[i].pontoi>21)
                                        {
                                            itta(i,a,&kaba);
                                            apantisi='n';
                                        }   else
                                        {
                                            if(a[i].pontoi<21)
                                            {

                                            printf("%s theleis allo fullo ??? (y/n): ",a[i].name);
                                            fflush(stdin);
                                            scanf("%c",&apantisi);
                                            }
                                            else{apantisi='n';}
                                        }
                            }

                    }
                    else
                    {
                        a[i].pontar=pcpontar(a[i].pontoi,kaba);
                        printf("to pontarisma tou pc einai: %.1f eurw\n",a[i].pontar);
                        while (test3){
                        printf("to pc thelei kialo fullo.gia na sunexisoume pata (y): ");
                        fflush(stdin);
                        do{
                        scanf("%c",&apantisi);
                        }while(apantisi!='y');
                        s=moirasm();
                        printf("to epomeno fullo tou pc einai: ");
                       showcard(s);
                        a[i].pontoi=s.a3ia+a[i].pontoi;
                        printf("kai exei %d pontous\n",a[i].pontoi);
                        if(a[i].pontoi==21)
                            test3=0;
                            else
                            if(a[i].pontoi==17)
                                test3=myrand(2);
                            else
                                if((a[i].pontoi>17)&&(a[i].pontoi<21))
                                test3=0;
                                else
                                    if(a[i].pontoi>21){
                                    itta(i,a,&kaba);
                                    test3=0;
                            }
                        }
                    }
                if(a[i].pontar!=0)
                    {test3=1;
                    puts("twra einai i seira tis manas:");
                    if((metritis>5)&&(a[i].pontoi<21))
                    {   if(strcmp(a[i].name,"pc")==0)
                        {   puts("epeidi o paixtis exeis travi3ei panw apo 5 fulla prepei na travi3eis eite mexri na pas 21 eite na kaeis.");
                            printf("gia na sunexisoume pata (y): ");
                            fflush(stdin);
                            do{
                            scanf("%c",&apantisi);
                            }while(apantisi!='y');
                             s=moirasm();
                            a[0].pontoi=a[0].pontoi+s.a3ia;
                            printf("to epomeno fullo tou pc einai: ");
                            showcard(s);
                            printf("kai exei %d pontous\n",a[0].pontoi);
                            while(a[0].pontoi<21)
                            {
                            s=moirasm();
                            a[0].pontoi=a[0].pontoi+s.a3ia;
                            printf("to epomeno fullo tou pc einai: ");
                            showcard(s);
                            printf("kai exei %d pontous\n",a[0].pontoi);
                            }
                        }else
                        {
                            printf("epeidi o paixtis exeis travi3ei panw apo 5 fulla prepei na travi3eis eite mexri na pas 21 eite na kaeis");
                        while(a[0].pontoi<21)
                            {printf("to pc thelei kialo fullo.gia na sunexisoume pata (y): ");
                            fflush(stdin);
                            do{
                            scanf("%c",&apantisi);
                            }while(apantisi!='y');
                             s=moirasm();
                            a[0].pontoi=a[0].pontoi+s.a3ia;
                            printf("to fullo tou paixti %s einai: ",a[i].name);
                            showcard(s);
                            printf("exeis %f pontous",a[i].pontoi);
                            }
                        }
                        if(a[0].pontoi==21){
                            printf("i mana sumplirwse 21 pontous\n");
                            itta(i,a,&kaba);}
                            else{
                            printf("i mana kaike\n");
                            niki(i,a,&kaba);}

                    }else{
                         if(strcmp(a[0].name,"pc")!=0)
                         {
                             while(test3)
                             {
                                 s=moirasm();
                                 a[0].pontoi=a[0].pontoi+s.a3ia;
                                 if(a[0].pontoi<22)
                                 {
                                printf("to epomeno fullo tis manas einai: ");
                                showcard(s);
                                printf("mana exeis %d pontous\n",a[0].pontoi);
                                printf("mana 8eleis allo fullo??? (y/n): ");
                                 fflush(stdin);
                                 scanf("%c",&apantisi);
                                 if(apantisi=='n')
                                    test3=0;
                                 }else{
                                 test3=0;
                                 puts("to epomeno fullo tis manas einai: ");
                                 showcard(s);
                                 printf("mana exeis %d pontous\n",a[0].pontoi);
                                 printf("i mana kaike!\n");
                                 niki(i,a,&kaba);
                                 }
                             }
                         }else
                         {
                              while(test3)
                             {
                                 s=moirasm();
                                 a[0].pontoi=a[0].pontoi+s.a3ia;
                                 printf("to epomeno fullo tis manas pou einai to pc einai: ");
                                 showcard(s);
                                 printf("kai exei %d pontous\n",a[0].pontoi);
                                 if(a[0].pontoi<22)
                                 {
                                     if(a[0].pontoi>=17)
                                        test3=0;
                                 }else
                                 {
                                  test3=0;
                                 printf("i mana kaike!\n");
                                 niki(i,a,&kaba);}
                                 if(test3==1){
                                 printf("to pc thelei kialo fullo.gia na sunexisoume pata (y): ");
                                 fflush(stdin);
                                 do{
                                 scanf("%c",&apantisi);
                                 }while(apantisi!='y');}
                             }
                         }
                    }
                        if((a[0].pontoi!=0)&&(a[i].pontoi!=0)){
                         if(a[0].pontoi<a[i].pontoi)
                            niki(i,a,&kaba);
                         else
                            itta(i,a,&kaba);}

                    }

            }
            else
               {
                printf("o paiktis %s exei xasei ola ta lefta tou! sunaxizoume me ton epomeno paixti\n",a[i].name);
               }
                if(metritis2==(atoma-1)||(kaba==0))
                    test2=0;

        }
    }

                if((kaba==0))
                    {printf("i mana exase oli tin kaba !\n");}
                    else
                        printf("i mana kaerdizei ta lefta pou apomenoun stin kaba diladi: %f ",kaba);
            for(i=0;i<atoma;i++)
                {
                    if(a[i].Sposo==(atoma*posO))
                        {
                        test=0;
                        w=i;
                        }
                }
    }
    printf("to paixnidi teleiwse! nikitis tou paixnidiou einai o paixtis %s kai to teliko poso tou einai %f eurw MPRAVO!!!!!!!!!",a[w].name,atoma*posO);
}

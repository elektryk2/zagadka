#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>


/*
Norweg, Anglik, Dunczyk, Niemiec, Szwed
czerwony, biały, żółty, niebieski, zielony
herbata, mlekom, woda, piwo, kawa
jabka, slwki, pomarancze, gruszki, banany
ptaki, psy, konie, koty, rypki

*/
uint8_t tab1[120][5]={{0}};
//uint8_t tab2[3125][120]={{0}};

uint8_t tab3[5][5]={{0}};

uint8_t tabGoond[5][5]={{0, 2, 1, 3, 4}, //6
                        {2, 3, 0, 4, 1}, //61
                        {2, 0, 1, 4, 3}, //49 //pije
                        {1, 0, 4, 2, 3}, //28
                        {3, 2, 0, 4, 1}  //85
                       };

uint8_t k=0;//, l=0;
uint64_t cnt=0;


uint8_t checc(uint8_t tab[5][5])
{
    //"pewne" zależności
    if(tab[0][0]!=0) return 14; //1. Norweg zamieszkuje pierwszy dom (licząc od lewej).
    if(tab[1][1]!=3) return 15; //12. Norweg mieszka obok niebieskiego domu.
    if(tab[2][2]!=1) return 16; //8. Mieszkaniec środkowego domu pija mleko.

    if(!((tab[0][1]==1 && tab[1][1]==0)
         ||(tab[0][2]==1 && tab[1][2]==0)
         ||(tab[0][3]==1 && tab[1][3]==0)
         ||(tab[0][4]==1 && tab[1][4]==0))) return 2; //2. Anglik mieszka w czerwonym domu.


    if(!((tab[0][1]==2 && tab[2][1]==0)
         ||(tab[0][2]==2 && tab[2][2]==0)
         ||(tab[0][3]==2 && tab[2][3]==0)
         ||(tab[0][4]==2 && tab[2][4]==0))) return 3; //4. Duńczyk pija herbatę.

    if(!((tab[0][1]==3 && tab[3][1]==2)
         ||(tab[0][2]==3 && tab[3][2]==2)
         ||(tab[0][3]==3 && tab[3][3]==2)
         ||(tab[0][4]==3 && tab[3][4]==2))) return 4; //7. Niemiec zjada pomarańcze.

    if(!((tab[0][1]==4 && tab[4][1]==1)
         ||(tab[0][2]==4 && tab[4][2]==1)
         ||(tab[0][3]==4 && tab[4][3]==1)
         ||(tab[0][4]==4 && tab[4][4]==1))) return 5; //11. Szwed hoduje psy.
    //////////////////////////////////////////////
    if(!((tab[1][0]==2 && tab[3][0]==1)
         ||(tab[1][2]==2 && tab[3][2]==1)
         ||(tab[1][3]==2 && tab[3][3]==1)
         ||(tab[1][4]==2 && tab[3][4]==1))) return 6;  //6. Mieszkaniec żółtego domu zjada śliwki.


    if(!((tab[1][0]==4 && tab[2][0]==4)
         ||(tab[1][2]==4 && tab[2][2]==4)
         ||(tab[1][3]==4 && tab[2][3]==4)
         ||(tab[1][4]==4 && tab[2][4]==4))) return 7;   //15. W zielonym domu pija się kawę.

    ///////////////////////////
    if(!((tab[3][0]==4 && tab[4][0]==0)
         ||(tab[3][1]==4 && tab[4][1]==0)
         ||(tab[3][2]==4 && tab[4][2]==0)
         ||(tab[3][3]==4 && tab[4][3]==0)
         ||(tab[3][4]==4 && tab[4][4]==0))) return 8; //10. Zjadacz bananów hoduje ptaki.

    if(!((tab[3][0]==3 && tab[2][0]==3)
         ||(tab[3][1]==3 && tab[2][1]==3)
         ||(tab[3][3]==3 && tab[2][3]==3)
         ||(tab[3][4]==3 && tab[2][4]==3))) return 9;//14. Zjadacz gruszek pija piwo.

    ///////////////////////////

    if(!(/*(tab[1][0]==4 && tab[1][1]==1) //
         ||(tab[1][1]==4 && tab[1][2]==1)
         ||*/(tab[1][2]==4 && tab[1][3]==1)
         ||(tab[1][3]==4 && tab[1][4]==1))) return 10; //3. Zielony dom znajduje się po lewej stronie domu białego.
    /////////////////////////////



    if(!((tab[1][0]==2 && tab[4][1]==2)
         ||(tab[1][2]==2 && tab[4][3]==2)
         ||(tab[1][3]==2 && tab[4][4]==2)

         ||(tab[1][2]==2 && tab[4][1]==2)
         ||(tab[1][3]==2 && tab[4][2]==2)
         ||(tab[1][4]==2 && tab[4][3]==2))) return 11;//13. Hodowca koni mieszka obok żółtego domu.

    if(!((tab[3][0]==0 && tab[4][1]==3)
         ||(tab[3][1]==0 && tab[4][2]==3)
         ||(tab[3][2]==0 && tab[4][3]==3)
         ||(tab[3][3]==0 && tab[4][4]==3)

         ||(tab[3][1]==0 && tab[4][0]==3)
         ||(tab[3][2]==0 && tab[4][1]==3)
         ||(tab[3][3]==0 && tab[4][2]==3)
         ||(tab[3][4]==0 && tab[4][3]==3))) return 12;//5. Zjadacz jabłek mieszka obok hodowcy kotów.

     if(!((tab[3][0]==0 && tab[2][1]==2)
          //||(tab[3][1]==0 && tab[2][2]==3)
          ||(tab[3][2]==0 && tab[2][3]==2)
          ||(tab[3][3]==0 && tab[2][4]==2)

          ||(tab[3][1]==0 && tab[2][0]==2)
          ||(tab[3][2]==0 && tab[2][1]==2)
          //||(tab[3][3]==0 && tab[2][2]==3)
          ||(tab[3][4]==0 && tab[2][3]==2))) return 13;//9. Zjadacz jabłek ma sąsiada, który pija wodę.

    return 1;
}


void comb(void)
{

    uint8_t num[5]={0};


    uint8_t overflow;


    while(1)
    {
        cnt++;

        if((cnt%1000000000ull)==0)
        {
            printf("c:%llu\n", cnt/1000000000ull);
            fflush(stdout);
        }



        memcpy(tab3[0], tab1[num[0]], 5);
        memcpy(tab3[1], tab1[num[1]], 5);
        memcpy(tab3[2], tab1[num[2]], 5);
        memcpy(tab3[3], tab1[num[3]], 5);
        memcpy(tab3[4], tab1[num[4]], 5);
       if(checc(tab3)==1)
     // if(memcmp(tab3, tabGoond, 5*5)==0)
        {
            printf("yea wygrywa kombinacja numer %llu\n", cnt);
            printf("%u %u %u %u %u\n", tab3[0][0], tab3[0][1], tab3[0][2],tab3[0][3],tab3[0][4]);
            printf("%u %u %u %u %u\n", tab3[1][0], tab3[1][1], tab3[1][2],tab3[1][3],tab3[1][4]);
            printf("%u %u %u %u %u\n", tab3[2][0], tab3[2][1], tab3[2][2],tab3[2][3],tab3[2][4]);
            printf("%u %u %u %u %u\n", tab3[3][0], tab3[3][1], tab3[3][2],tab3[3][3],tab3[3][4]);
            printf("%u %u %u %u %u\n", tab3[4][0], tab3[4][1], tab3[4][2],tab3[4][3],tab3[4][4]);
            printf("\n");
           return;
        }

        overflow=1;

        for(int j=0; j<5; j++)
        {
            //memcpy(tab2[l++], num, 5);
           // printf("%d, ", num[j]);
           // memcpy(tab3[0], tab1[num[0]], 5*5);

            if(overflow) num[j]++;
            if(num[4]==120) return;
            if(num[j]>=120)
            {
                overflow=1;
                num[j]=0;
            }
            else overflow=0;

         }
        //printf("\n");
        //fflush(stdout);

    }

}


void print(const uint8_t *v, const int size)
{
  if (v != 0) {
    for (int i = 0; i < size; i++) {
      //printf("%4d", v[i] );
      printf("%d, ", v[i] );
    }
    printf("\n");
  }
} // print


void swap(uint8_t *v, const int i, const int j)
{
  int t;
  t = v[i];
  v[i] = v[j];
  v[j] = t;
}


void rotateLeft(uint8_t *v, const int start, const int n)
{
  int tmp = v[start];
  for (int i = start; i < n-1; i++) {
    v[i] = v[i+1];
  }
  v[n-1] = tmp;
} // rotateLeft


void permute(uint8_t *v, const int start, const int n)
{
  //print(v, n);
  memcpy(tab1[k++], v, 5*sizeof(uint8_t));
  if (start < n) {
    int i, j;
    for (i = n-2; i >= start; i--) {
      for (j = i + 1; j < n; j++) {
    swap(v, i, j);
    permute(v, i+1, n);
      } // for j
      rotateLeft(v, i, n);
    } // for i
  }
} // permute


void init(uint8_t *v, int N)
{
  for (int i = 0; i < N; i++) {
   // v[i] = i+1;
    v[i] = i;
  }
} // init


int main()
{
    uint8_t v[5]={0};
    init(v, 10);
    permute(v, 0, 5);

    comb();

    printf("end\n");
}

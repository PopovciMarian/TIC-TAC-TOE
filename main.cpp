#include <iostream>
#include <graphics.h>
#include <winbgim.h>
#include <stdio.h>

 int width = 1000;
 int height = 800;
 int marimeTabla =  std :: min(width, height) - 100;
 int x1 = (width - marimeTabla)/2;
 int y1 = (height - marimeTabla)/2;
 int x2 = x1 + marimeTabla;
 int y2 = y1 + marimeTabla;
 int resp = marimeTabla/100;
 int tabla[10] = {0};
 short casuteOcupate;
 bool finis = false;
 int linie = 0;
 short scorX;
 short scorO;
 short turaOX = 2;
 int incepe = 0;

void init(){
  for(int i = 1; i <= 9; ++ i)
    tabla[i] = 0;
  casuteOcupate = 0;
  finis = false;
  linie = 0;
}

void scor(){
  char sir[12];
  settextstyle(8, HORIZ_DIR, resp + 2);

  setcolor(BLUE);
  sprintf(sir, "%d",scorX);
  outtextxy(x1 - textwidth("X") * 2, y1 + textheight("X")/2, "X");
  outtextxy(x1 - textwidth(sir) * 2, y1 + textheight(sir) + resp*4  , sir);

  setcolor(RED);
  sprintf(sir, "%d",scorO);
  outtextxy(x2 + textwidth("O"), y1 + textheight("O")/2, "O");
  outtextxy(x2 + textwidth(sir), y1 + textheight(sir) + resp*4  , sir);
}

void deseneazaPunct(){
  if(turaOX == 1){
    setcolor(7);
    setfillstyle(SOLID_FILL, BLUE);
    fillellipse(x1 - textwidth("X") - resp* 4, y1 + textheight("X")/2 - resp * 2, resp, resp);
    setfillstyle(SOLID_FILL, 7);
    bar(x2 + textwidth("O") + resp* 3, y1 + textheight("O")/2 - resp * 3,x2 + textwidth("O") + resp* 5, y1 + textheight("O")/2 - resp );
    }
  else if(turaOX == 2){
    setcolor(7);
    setfillstyle(SOLID_FILL, RED);
    fillellipse(x2 + textwidth("O") + resp* 4, y1 + textheight("O")/2 - resp * 2, resp, resp);
    setfillstyle(SOLID_FILL, 7);
    bar(x1 - textwidth("X") - resp* 5, y1 + textheight("X")/2 - resp * 3,x1 - textwidth("X") - resp* 4 + resp, y1 + textheight("X")/2 - resp * 2+ resp);
     }
}

void deseneazaX_O(int poz, short tura){
  int pozX, pozY;

  switch(poz){
    case 1:
        pozX = 0;
        pozY = 0;
        break;
    case 2:
        pozX = marimeTabla / 3;
        pozY = 0;
        break;
    case 3:
        pozX = marimeTabla / 3 * 2;
        pozY = 0;
        break;
    case 4:
        pozX =  0;
        pozY = marimeTabla / 3;
        break;
    case 5:
        pozX = marimeTabla / 3;
        pozY = marimeTabla / 3;
        break;
    case 6:
        pozX = marimeTabla / 3 * 2 ;
        pozY = marimeTabla / 3;
        break;
    case 7:
        pozX = 0;
        pozY = marimeTabla / 3 * 2;
        break;
    case 8:
        pozX = marimeTabla / 3;
        pozY = marimeTabla / 3 * 2;
        break;
    case 9:
        pozX = marimeTabla / 3 * 2;
        pozY = marimeTabla / 3 * 2;
        break;
  }

  setcolor(BLUE);
  if(tura == 1)
      for(int i = -1 * resp; i <= resp ; ++ i){
        line(x1 + i + resp * 4 + pozX, y1 + resp * 4 + pozY, x1 + marimeTabla/3 + i - resp * 4 + pozX, y1 + marimeTabla/3 - resp * 4 + pozY);
        line(x1 + marimeTabla/3 + i - resp * 4 + pozX, y1 + resp * 4 + pozY, x1 + i + resp * 4 + pozX, y1 + marimeTabla/3 - resp * 4 + pozY);
        }

  else if(tura == 2){
    setcolor(RED);
    for(int i = 0; i <= resp*2 ; ++ i)
        circle(x1 + marimeTabla/6 + pozX, y1 + marimeTabla/6 + pozY, marimeTabla/6 - i - resp * 3);
    }
}

void desenareTabla(){
  setfillstyle(SOLID_FILL, 11);
  bar(x1, y1, x2, y2);
  setfillstyle(SOLID_FILL, 10);
  bar(x1 + marimeTabla/3 - resp, y1, x1 + marimeTabla/3 + resp, y2);
  bar(x1 + marimeTabla/3 * 2 - resp, y1, x1 + marimeTabla/3 * 2 + resp, y2);
  bar(x1, y1 + marimeTabla/3 - resp, x2, y1 + marimeTabla/3 + resp);
  bar(x1, y1 + marimeTabla/3 * 2 - resp, x2, y1 + marimeTabla/3 * 2 + resp);
  for(int i = 1; i <= 9; ++ i)
    if(tabla[i]){
       deseneazaX_O(i, tabla[i]);
  }
}

short test(){
  if(tabla[1] == tabla[2] && tabla[1] == tabla [3] && tabla[1]){
    linie = 1;
    finis = true;
    return 1;
  }
  else if(tabla[4] == tabla[5] && tabla[4] == tabla[6] && tabla[4]){
    linie = 2;
    finis = true;
    return 2;
  }
  else if(tabla[7] == tabla[8] && tabla[7] == tabla[9] && tabla[7]){
    linie = 3;
    finis = true;
    return 3;
  }
  else if(tabla[1] == tabla[4] && tabla[1] == tabla[7] && tabla[1]){
    linie = 4;
    finis = true;
    return 4;
  }
  else if(tabla[2] == tabla[5] && tabla[2] == tabla[8] && tabla[2]){
    linie = 5;
    finis = true;
    return 5;
  }
  else if(tabla[3] == tabla[6] && tabla[3] == tabla[9] && tabla[3]){
    linie = 6;
    finis = true;
    return 6;
  }
  else if(tabla[1] == tabla[5] && tabla[1] == tabla[9] && tabla[1]){
    linie = 7;
    finis = true;
    return 7;
  }
  else if(tabla[3] == tabla[5] && tabla[3] == tabla[7] && tabla[3]){
    linie = 8;
    finis = true;
    return 8;
  }
  else if(casuteOcupate == 9){
    linie = 9;
    return 9;
  }
  return 0;
}

void deseneazaLinie(short segment, short nivel){
    setfillstyle(SOLID_FILL, YELLOW);
    if(segment == 1){        ///linie
        if(nivel == 1){                   // prima
          bar(x1 + resp * 5, y1 + marimeTabla/6 - resp, x2 - resp * 5, y1 + marimeTabla/6 + resp);
        }
        else if(nivel == 2){              // a doua
          bar(x1 + resp * 5, y1 + marimeTabla/2 - resp, x2 - resp * 5, y1 + marimeTabla/2 + resp);
        }
        else{                             // a treia
          bar(x1 + resp * 5, y1 + marimeTabla/6 * 5  - resp, x2 - resp * 5, y1 + marimeTabla/6 * 5  + resp);
        }
    }

    else if(segment == 2){   /// coloana
        if(nivel == 1){                   // prima
            bar(x1 + marimeTabla/6 - resp, y1 + 5, x1 + marimeTabla/6 + resp, y2 - 5);
        }
        else if(nivel == 2){              // a doua
            bar(x1 + marimeTabla/2 - resp, y1 + 5, x1 + marimeTabla/2 + resp, y2 - 5);
        }
        else{                             // a treia
            bar(x1 + marimeTabla/6 * 5 - resp, y1 + 5, x1 + marimeTabla/6 * 5 + resp, y2 - 5);
        }
    }

    else{                    /// diagonala
        setcolor(YELLOW);
        if(nivel == 1){                   //principala
            for(int i = -1*resp -5; i <= resp; i++){
                line(x1 + i + resp* 2 , y1 + resp* 2, x2+ i - resp* 2, y2 - resp* 2);
                }
        }
        else{                             //secundara
             for(int i = -1*resp -5; i <= resp; i++){
                line(x2 + i - resp* 2, y1 + resp* 2, x1+ i + resp* 2, y2 - resp * 2);
            }
        }
    }
}

void sfarsit(short castigator){
  setbkcolor(11);
  settextstyle(4, HORIZ_DIR, resp);
  setcolor(GREEN);
  switch(linie){
    case 1:
        deseneazaLinie(1, 1);
        break;
    case 2:
        deseneazaLinie(1, 2);
        break;
    case 3:
        deseneazaLinie(1, 3);
        break;
    case 4:
        deseneazaLinie(2, 1);
        break;
    case 5:
        deseneazaLinie(2, 2);
        break;
    case 6:
        deseneazaLinie(2, 3);
        break;
    case 7:
       deseneazaLinie(3, 1);
        break;
    case 8:
        deseneazaLinie(3, 2);
        break;
    case 9:
        outtextxy((width - textwidth("Remiza"))/2, (height - textheight("Remiza"))/2, "Remiza");
        finis = true;
        return;
  }
  setcolor(GREEN);
  if(castigator == 2){
    outtextxy((width - textwidth("O a castigat !!!"))/2, (height - textheight("O a castigat !!!"))/2, "O a castigat !!!");
    scorO++;
    }
  else if(castigator == 1){
    outtextxy((width - textwidth("X a castigat !!!"))/2, (height - textheight("X a castigat !!!"))/2, "X a castigat !!!");
    scorX++;
  }
}

void joc(){
    while(!finis){
        if(ismouseclick(WM_LBUTTONDOWN)){
           clearmouseclick(WM_LBUTTONDOWN);
           int x=mousex();
           int y=mousey();
           if(x >= x1 && x <= x2 && y >= y1 && y <= y2){
              if(x <= x1 + marimeTabla/3){
                 if(y <= y1 + marimeTabla/3){
                    if(!tabla[1]){
                        tabla[1] = turaOX;
                        ++ casuteOcupate;
                        }
                     }
                 else if(y < y1 + marimeTabla/3 * 2){
                    if(!tabla[4]){
                        tabla[4] = turaOX;
                        ++ casuteOcupate;
                        }
                     }
                else if(y < y2){
                    if(!tabla[7]){
                        tabla[7] = turaOX;
                        ++ casuteOcupate;
                        }
                    }
                }
            else if(x <= x1 + marimeTabla/3 * 2){
                if(y <= y1 + marimeTabla/3){
                    if(!tabla[2]){
                        tabla[2] = turaOX;
                        ++ casuteOcupate;
                        }
                    }
                else if(y < y1 + marimeTabla/3 * 2){
                    if(!tabla[5]){
                        tabla[5] = turaOX;
                        ++ casuteOcupate;
                        }
                    }
                else if(y < y2){
                    if(!tabla[8]){
                        tabla[8] = turaOX;
                        ++ casuteOcupate;
                        }
                    }
                }
            else{
                if(y <= y1 + marimeTabla/3){
                    if(!tabla[3]){
                        tabla[3] = turaOX;
                        ++ casuteOcupate;
                        }
                    }
                else if(y < y1 + marimeTabla/3 * 2){
                    if(!tabla[6]){
                        tabla[6] = turaOX;
                        ++ casuteOcupate;
                        }
                    }
                else if(y < y2){
                    if(!tabla[9]){
                        tabla[9] = turaOX;
                        ++ casuteOcupate;
                        }
                    }
                }
            desenareTabla();
            if(casuteOcupate > 4)
                if(test())
                    sfarsit(turaOX);
            if(incepe % 2)
                if(casuteOcupate % 2)
                    turaOX = 2 ;
                else
                    turaOX = 1;
            else if(!(incepe % 2))
                if(casuteOcupate % 2)
                    turaOX = 1 ;
                else
                    turaOX = 2;
            deseneazaPunct();
            }
        }
    }
  delay(1500);
}

int main(){
  initwindow(width, height, "X si O", 0, 0);
  do{
    init();
    if(incepe % 2 == 0)
        turaOX = 1;
    else
        turaOX = 2;
    incepe++;
    setbkcolor(7);
    cleardevice();
    desenareTabla();
    scor();
    deseneazaPunct();
    joc();
  }while(1);
  getch();

  closegraph();
  return 0;
}

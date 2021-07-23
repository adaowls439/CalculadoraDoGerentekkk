#include <stdio.h>
#include <time.h>
#include <locale.h>

void ErrorLojaMsg(void){
  printf("\n* Esta loja não existe!!\n\n");
}

void clear_key(){
  int c = 0;
  while ((c = getchar()) != '\n' && c != EOF) {}
  return;
}

void PressEnter(){
  printf("\n\n* Pressione ENTER para continuar...\n");
  clear_key();
  getchar();
}

int BuscarLoja(int lojas[]){
  int num = 0;

  do{
    printf("\nDigite o número da loja: ");
    scanf("%d",&num);

    if(num <= 20){
      int i = 0;
      while(i<=num){
        if(lojas[i] == num){
          i = num+1;
          return num;
        }
        i++;
      }

    } else {
      ErrorLojaMsg();
      num = 0;
    }
    num = 0;
    ErrorLojaMsg();
  }while(num==0);

  return 0;
}

int ParteGerente(int loja, int vTotal, int vVerdade){
  int vGerente;
  if((loja==2)||(loja == 9)||(loja==10)||(loja==18)){
    if(vTotal >= 10000000){
      vGerente = vVerdade * 0.5;
    } else if(vTotal >= 7000000){
      vGerente = vVerdade * 0.35;
    } else if(vTotal >= 5000000){
      vGerente = vVerdade * 0.3;
    } else if(vTotal >=3000000){
      vGerente = vVerdade * 0.25;
    } else{
      vGerente = 0;
    }
  }

  if((loja==11)||(loja == 8)){
    if(vTotal >= 10500000){
      vGerente = vVerdade * 0.5;
    } else if(vTotal >= 7500000){
      vGerente = vVerdade * 0.35;
    } else if(vTotal >= 5500000){
      vGerente = vVerdade * 0.3;
    } else if(vTotal >=3500000){
      vGerente = vVerdade * 0.25;
    } else{
      vGerente = 0;
    }
  }

  return vGerente;
}

void Calcular(int loja){
  int vTotal, vVerdade, vGerente, vDono;

  struct tm *p;
  time_t seconds;
  time(&seconds);
  p = localtime(&seconds);

  printf("Valor total em caixa: ");
  scanf("%d",&vTotal);

  printf("1 - Saque todo o dinheiro da loja;\n2 - Deposite 1.000.000 no caixa da loja;\n3 - Agora deposite o restante do dinheiro na sua conta bancaria para transferir para os donos. \n");
  PressEnter();

  printf("\nCalculando...\n");

  vVerdade = vTotal - 1000000;
  vGerente = ParteGerente(loja, vTotal, vVerdade);
  vDono = (vVerdade - vGerente) /2;

  printf("Envie %d para o \"Caveirinha - 159\" e envie o comprovante para ele no privado do discord.", vDono);
  PressEnter();

  printf("Envie %d para o \"Pedro Woruby - 18\" e envie o comprovante para ele no privado do discord.", vDono);

  PressEnter();

  printf("Copie e cole esta mensagem no discord(#fechamento-de-caixa): \n");

  printf("```\n**Loja %d:** %d", loja, vTotal);
  printf("\n**Parte do Gerente:** %d",vGerente);
  printf("\n**Parte do Caveirinha: ** %d",vDono);
  printf("\n**Parte do Pedro: ** %d",vDono);
  printf("\nPrint da transferência no PV.");
  printf("\n@PROPRIETÁRIO %s```", ctime(&seconds));

  system("pause");
}

int main(void) {
  setlocale(LC_ALL, "Portuguese");

  int lojas[10]={2,8,9,10,11,18};

  printf("* Atenção!!\n1 - Antes de fechar o caixa da loja, tente pagar o bônus de todos os funcionários, revisar as coletas e entregas;\n2 - Tente vender todas as coletas abandonadas na loja.");

  int loja = BuscarLoja(lojas);

  Calcular(loja);

  return 0;
}

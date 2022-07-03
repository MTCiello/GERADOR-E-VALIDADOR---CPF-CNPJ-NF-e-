#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define LIMPA system("cls");

int CPF[11], CNPJ[14], NF[44];

    char C_CPF[20]; //{"17409488239"};
    char C_CNPJ[20]; //{"43123341000167"};
    char C_NFe[50]; //{"41220779063764000186550010005492961769577034"};
    char AUX[2]; 

// VALIDAÇÕES

void VALIDAR_CPF();
void VALIDAR_CNPJ();
void GERAR_CPF();
void GERAR_CNPJ();
void VALIDAR_NFe();

// TELAS

void TELA_INICIAL();
void TELA_CPF();
void TELA_CNPJ();
void TELA_NFe();




int main() {


    int ESCOLHA, E1;

    

    do{

    
    TELA_INICIAL();

    scanf("%d", &ESCOLHA);

    switch (ESCOLHA)
    {
    case 1: // ESCOLHA MAIN

    E1=0;

    LIMPA
    TELA_CPF();

    do{
        scanf("%d", &E1);
        LIMPA

    switch (E1)
    {
    case 1:  

    TELA_CPF();

    GERAR_CPF();

    getch();
    LIMPA
    TELA_CPF();

    break;

    case 2: 

    TELA_CPF();

    printf("Digite o CPF:\n");

    scanf("%s", &C_CPF);

    for(int i =0; i<strlen(C_CPF);i++){

        AUX[0] = C_CPF[i];
        CPF[i] = atoi(AUX);
    }

    VALIDAR_CPF();

    getch();
    LIMPA
    TELA_CPF();
    

    break;

    case 3: 

    E1=4;

    break;

    default: 

    TELA_CPF();
    
    printf("SELECAO INVALIDA TENTE OUTRA!\n"); 

    getch();
    LIMPA
    TELA_CPF();
    
    break;
    }
    } while(E1<3);
  
    break;


    case 2: // ESCOLHA MAIN

    E1=0;

    LIMPA
    TELA_CNPJ();

    do{

    scanf("%d", &E1);
    LIMPA

    switch (E1)
    {
    case 1: 

    TELA_CNPJ();

    GERAR_CNPJ();

    getch();
    LIMPA
    TELA_CNPJ();

    break;

    case 2:

    TELA_CNPJ();

    printf("Digite o CNPJ:\n");
    
    scanf("%s", &C_CNPJ);

    for(int i =0; i<strlen(C_CNPJ);i++){

        AUX[0] = C_CNPJ[i];
        CNPJ[i] = atoi(AUX);
    }
    
    VALIDAR_CNPJ(); 

    getch();
    LIMPA
    TELA_CNPJ();


    break;

    case 3:

    E1=4;

    break;
    
    default:

    printf("SELECAO INVALIDA TENTE OUTRA!\n"); 

    TELA_CNPJ();

    getch();
    LIMPA
    TELA_CNPJ();

    break;
    }


    } while(E1<3);


    break;


    case 3:

    E1=0;
    LIMPA
    TELA_NFe();

    do{

        scanf("%d", &E1);
        LIMPA

    switch (E1)
    {
    case 1:

    TELA_NFe();

    printf("Digite a chave da NFe:\n");
    
    scanf("%s", &C_NFe);

    for(int i =0; i<strlen(C_NFe);i++){

        AUX[0] = C_NFe[i];
        NF[i] = atoi(AUX);
    }
    
    VALIDAR_NFe(); 

    getch();
    LIMPA
    TELA_NFe();
    
    break;

    case 2:

    E1=3;

    break;
    
    default:

    printf("SELECAO INVALIDA TENTE OUTRA!\n"); 

    TELA_NFe();

    getch();
    LIMPA
    TELA_NFe();

    break;

    }

    } while (E1<2);
     
    break;

    case 0:
    
    break;

    default: printf("SELECAO INVALIDA TENTE OUTRA!\n"); break;

    }

    } while(ESCOLHA>0);

    printf("\n\nEncerando O LEND%cRIO GERADOR !!", 181);
    getch();

}


// VALIDAÇÕES

void VALIDAR_CPF() {

    int DV[2], CAL1=0, CAL2=0;

    for(int i=1;i<=9;i++){ // PRIMEIRO DIGITO VERIFICADOR
        CAL1 = CAL1+(CPF[i-1]*i); 
    }

    for(int i=0;i<=8;i++){ // SEGUNDO DIGITO VERIFICADOR
        CAL2 = CAL2+(CPF[i]*i);
    }
    
    if((DV[0] = CAL1%11) >= 10){
        DV[0] = 0;
    } else {
        DV[0] = CAL1%11;
    }
    DV[1] = (CAL2+( DV[0] *9))%11;

    if(DV[1] >=10){
        DV[1] = 0;
    }

    if (DV[0] == CPF[9] && DV[1] == CPF[10]){
        printf("\n\nCPF VALIDO e com origem de:\n");

        switch (CPF[8]){ // VALIDAÇÃO DE ESTADO
            case 1: 
                    printf("- Distrito Federal;\n- Goias;\n- Mato Grosso do Sul;\n- Tocantins;\n");
                    break;
            case 2: 
                    printf("- Para;\n- Amazonas;\n- Acre;\n- Amapa;\n- Rondonia;\n- Roraima;\n");
                    break;
            case 3: 
                    printf("- Ceara;\n- Maranhao;\n- Piaui\n");
                    break;
            case 4: 
                    printf("- Pernambuco;\n- Rio Grande do Norte;\n- Paraiba;\n- Alagoas;\n");
                    break;
            case 5: 
                    printf("- Bahia;\n- Sergipe;\n");
                    break;
            case 6: 
                    printf("- Minas Gerais;\n");
                    break;
            case 7: 
                    printf("- Rio de Janeiro;\n- Espirito Santo;\n");
                    break;
            case 8: 
                    printf("- Sao Paulo;\n");
                    break;
            case 9: 
                    printf("- Parana;\n- Santa Catarina;\n");
                    break;
            case 0: 
                    printf("- Rio Grande do Sul;\n");
                    break;
            default: break;
        }
        
    } else {
        printf("\n\nCPF INVALIDO\n");
    }

}

void VALIDAR_CNPJ(){

    int DV[2], CAL1=0, CAL2=0; 

    for(int i=0;i<=3;i++){ // PRIMEIRO DIGITO VERIFICADOR
        CAL1 = CAL1+(CNPJ[i]*(5-i));
    }
    for(int i=0;i<=7;i++){
        CAL1 = CAL1+(CNPJ[i+4]*(9-i));
    }
    


    DV[0] = CAL1%11;

    if(DV[0] >= 2){
        DV[0]=11-DV[0];
    } else {
        DV[0] = 0;
    }




    for(int i=0;i<=4;i++){ // SEGUNDO DIGITO VERIFICADOR
        CAL2 = CAL2+(CNPJ[i]*(6-i));
    }
    for(int i=0;i<=6;i++){
        CAL2 = CAL2+(CNPJ[i+5]*(9-i));
    }
    

    CAL2+=DV[0]*2;


    DV[1] = CAL2%11;

    if(DV[1] >= 2){
        DV[1]=11-DV[1];
    } else {
        DV[1] = 0;
    }

    if (CNPJ[12] == DV[0] && CNPJ[13] == DV[1]){
        printf("\n\nCNPJ VALIDO\n");
    } else {
        printf("\n\nCNPJ INVALIDO\n");
    }

}

void GERAR_CPF(){


int TESTE[11],CAL1=0, CAL2=0, DV[2], AUX=0;
    
    for(AUX = 0; AUX <9; AUX++) { // GERAR NÚMEROS ALEATÓRIOS
        TESTE[AUX] = rand() % 10;
    }

    for(int i=1;i<=9;i++){ // PRIMEIRO DIGITO VERIFICADOR
        CAL1 = CAL1+(TESTE[i-1]*i); 
    }

    for(int i=0;i<=8;i++){ // SEGUNDO DIGITO VERIFICADOR
        CAL2 = CAL2+(TESTE[i]*i);
    }
    
    if((DV[0] = CAL1%11) >= 10){
        DV[0] = 0;
    } else {
        DV[0] = CAL1%11;
    }
    DV[1] = (CAL2+( DV[0] *9))%11;

    if(DV[1] >=10){
        DV[1] = 0;
    }

    TESTE[9] = DV[0];
    TESTE[10] = DV[1];

    // XXX.XXX.XXX-XX

    printf("\nCPF GERADO COM SUCESSO !\n[ ");

    for(int i=0;i<3;i++){
    printf("%d",TESTE[i]);
    }

    printf(".");

    for(int i=3;i<6;i++){
    printf("%d",TESTE[i]);
    }

    printf(".");

    for(int i=6;i<9;i++){
    printf("%d",TESTE[i]);
    }

    printf("-");

    for(int i=9;i<11;i++){
    printf("%d",TESTE[i]);
    }

    printf(" ]\n");

  

}

void GERAR_CNPJ(){

    int TESTE[14], CAL1=0, CAL2=0, DV[2], AUX=0;


    for(AUX = 0; AUX <13; AUX++) { // GERAR NÚMEROS ALEATÓRIOS
        TESTE[AUX] = rand() % 10;
    }

    TESTE[8] = 0;
    TESTE[9] = 0;
    TESTE[10] = 0;
    TESTE[11] = 1;


    for(int i=0;i<=3;i++){ // PRIMEIRO DIGITO VERIFICADOR
        CAL1 = CAL1+(TESTE[i]*(5-i));
    }
    for(int i=0;i<=7;i++){
        CAL1 = CAL1+(TESTE[i+4]*(9-i));
    }
    

    DV[0] = CAL1%11;

    if(DV[0] >= 2){
        DV[0]=11-DV[0];
    } else {
        DV[0] = 0;
    }




    for(int i=0;i<=4;i++){ // SEGUNDO DIGITO VERIFICADOR
        CAL2 = CAL2+(TESTE[i]*(6-i));
    }
    for(int i=0;i<=6;i++){
        CAL2 = CAL2+(TESTE[i+5]*(9-i));
    }
    

    CAL2+=DV[0]*2;


    DV[1] = CAL2%11;

    if(DV[1] >= 2){
        DV[1]=11-DV[1];
    } else {
        DV[1] = 0;
    }
    


    TESTE[12] = DV[0];
    TESTE[13] = DV[1];

    //XX.XXX.XXX/XXXX-XX

    printf("\nCNPJ GERADO COM SUCESSO ! \n[ ");

    for(int i=0;i<2;i++){
        printf("%d", TESTE[i]);
    }
    printf(".");
    for(int i=2;i<5;i++){
        printf("%d", TESTE[i]);
    }
    printf(".");
    for(int i=5;i<8;i++){
        printf("%d", TESTE[i]);
    }
    printf("/");
    for(int i=8;i<12;i++){
        printf("%d", TESTE[i]);
    }
    printf("-");
    for(int i=12;i<14;i++){
        printf("%d", TESTE[i]);
    }



    printf(" ] \n");





}

void VALIDAR_NFe(){


    int DV[2], CAL1=0, AUX=0, TAM=0;

    // 4 3 2 - 9 8 7 6 5 4 3 2 - 9 8 7 6 5 4 3 2 - 9 8 7 6 5 4 3 2 - 9 8 7 6 5 4 3 2 - 9 8 7 6 5 4 3 2

    for(int i=0; i<3;i++){
        CAL1=CAL1+(NF[i]*(4-i));
    }

    do{

    AUX++;

    for(int i = 0; i<8;i++){
        CAL1=CAL1+(NF[3+i+TAM]*(9-i));  
    }

    TAM=TAM+8;
    

    }while(AUX<5);

    DV[0] = 11-(CAL1%11);

    if(DV[0] == NF[43]){
        printf("\n\nNFe VALIDA !\n\n");

       int C1 = (NF[0]*10 + NF[1]);

        printf("Informacoes do documento:\n\n");

        switch (C1) // CÓDIGO DO ESTADO
        {
        case 11: printf("[RO] Rondonia;\n"); break;
        case 12: printf("[AC] Acre;\n"); break;
        case 13: printf("[AM] Amazonas;\n"); break;
        case 14: printf("[RR] Roraima;\n"); break;
        case 15: printf("[PA] Para;\n"); break;
        case 16: printf("[AP] Amapa;\n"); break;
        case 17: printf("[TO] Tocantins;\n"); break;
        case 21: printf("[MA] Maranhao;\n"); break;
        case 22: printf("[PI] Piaui;\n"); break;
        case 23: printf("[CE] Ceara;\n"); break;
        case 24: printf("[RN] Rio Grande do Norte;\n"); break;
        case 25: printf("[PB] Paraiba;\n"); break;
        case 26: printf("[PE] Pernambuco;\n"); break;
        case 27: printf("[AL] Alagoas;\n"); break;
        case 28: printf("[SE] Segipe;\n"); break;
        case 29: printf("[BA] Bahia;\n"); break;
        case 31: printf("[MG] Minas Gerais;\n"); break;
        case 32: printf("[ES] Espirito Santo;\n"); break;
        case 33: printf("[RJ] Rio de Janeiro;\n"); break;
        case 35: printf("[SP] Sao Paulo;\n"); break;
        case 41: printf("[PR] Parana;\n"); break;
        case 42: printf("[SC] Santa Catarina;\n"); break;
        case 43: printf("[RS] Rio Grande do Sul;\n"); break;
        case 50: printf("[MS] Mato Grosso do Sul;\n"); break;
        case 51: printf("[MT] Mato Grosso;\n"); break;
        case 52: printf("[GO] Goias;\n"); break;
        case 53: printf("[DF] Distrito Federal;\n"); break;
        
        default:
            break;
        }

        printf("Emissao: %d%d/20%d%d\n", NF[4], NF[5], NF[2], NF[3]);

        printf("CNPJ PROVEDOR: "); // XX.XXX.XXX/XXXX-XX

        for(int i=6;i<8;i++){
            printf("%d", NF[i]);
        }
        printf(".");
        for(int i=8;i<11;i++){
            printf("%d", NF[i]);
        }
        printf(".");
        for(int i=11;i<14;i++){
            printf("%d", NF[i]);
        }
        printf("/");
        for(int i=14;i<18;i++){
            printf("%d", NF[i]);
        }
        printf("-");
        for(int i=18;i<20;i++){
            printf("%d", NF[i]);
        }
    printf("\n");

        printf("IDENTIFICACAO: %d%d\n", NF[20],NF[21]);
        printf("SERIE: %d%d%d\n", NF[22],NF[23], NF[24]);
        printf("NUMERO: ");
        for(int i=25; i<=33;i++){
            printf("%d", NF[i]);
        }
        printf("\nTIPO DE EMISSAO: %d\n", NF[34]);
        printf("CODIGO NUMERICO DA CHAVE: ");
        for(int i=35;i<=42;i++){
            printf("%d",NF[i]);
        }
        printf("\nCODIGO VERIFICADOR: %d\n", NF[43]);

    } else {
        printf("NFe INVALIDA !\n");
    }  

}


// TELAS

void TELA_INICIAL(){

    LIMPA

    printf("%c", 201);
    for(int i=0;i<40;i++) printf("%c",205);
    printf("%c\n", 187);

    printf("%c           O LEND%cRIO GERADOR           %c\n", 186, 181, 186);

    
    printf("%c", 204);
    for(int i=0;i<40;i++) printf("%c",205);
    printf("%c\n%c\t   SELECIONE UMA OPC%cO           %c\n%c                                        %c\n", 186,186, 199, 186,186,186);

    printf("%c\t", 186);
    printf("[ 1 ] CPF                        %c\n",186);
    printf("%c\t", 186);
    printf("[ 2 ] CNPJ                       %c\n",186);
    printf("%c\t", 186);
    printf("[ 3 ] NF-e                       %c\n",186);
    printf("%c\t", 186);
    printf("[ 0 ] SAIR                       %c\n",186);
    printf("%c\t", 186);

    printf("                                 %c\n",186);
    printf("%c\t", 186);
    printf("                                 %c\n",186);
    printf("%c", 200);

    for(int i=0;i<40;i++) printf("%c",205);
    printf("%c\n ESCOLHA: ", 188);



}

void TELA_CPF(){

    printf("%c", 201);
    for(int i=0;i<40;i++) printf("%c",205);
    printf("%c\n", 187);

    printf("%c           O LEND%cRIO GERADOR           %c\n", 186, 181, 186);

    
    printf("%c", 204);
    for(int i=0;i<40;i++) printf("%c",205);
    printf("%c\n%c\t   SELECIONE UMA OPC%cO           %c\n%c                                        %c\n", 186,186, 199, 186,186,186);

    printf("%c\t", 186);
    printf("[ 1 ] GERAR                      %c\n",186);
    printf("%c\t", 186);
    printf("[ 2 ] VALIDAR                    %c\n",186);
    printf("%c\t", 186);
    printf("[ 3 ] VOLTAR                     %c\n",186);
    printf("%c\t", 186);
    printf("                                 %c\n",186);
    printf("%c\t", 186);

    printf("                                 %c\n",186);
    printf("%c\t", 186);
    printf("                                 %c\n",186);
    printf("%c", 200);

    for(int i=0;i<40;i++) printf("%c",205);
    printf("%c\n ESCOLHA: ", 188);

}

void TELA_CNPJ(){

    printf("%c", 201);
    for(int i=0;i<40;i++) printf("%c",205);
    printf("%c\n", 187);

    printf("%c           O LEND%cRIO GERADOR           %c\n", 186, 181, 186);

    
    printf("%c", 204);
    for(int i=0;i<40;i++) printf("%c",205);
    printf("%c\n%c\t   SELECIONE UMA OPC%cO           %c\n%c                                        %c\n", 186,186, 199, 186,186,186);

    printf("%c\t", 186);
    printf("[ 1 ] GERAR                      %c\n",186);
    printf("%c\t", 186);
    printf("[ 2 ] VALIDAR                    %c\n",186);
    printf("%c\t", 186);
    printf("[ 3 ] VOLTAR                     %c\n",186);
    printf("%c\t", 186);
    printf("                                 %c\n",186);
    printf("%c\t", 186);

    printf("                                 %c\n",186);
    printf("%c\t", 186);
    printf("                                 %c\n",186);
    printf("%c", 200);

    for(int i=0;i<40;i++) printf("%c",205);
    printf("%c\n ESCOLHA: ", 188);

}

void TELA_NFe(){

    printf("%c", 201);
    for(int i=0;i<40;i++) printf("%c",205);
    printf("%c\n", 187);

    printf("%c           O LEND%cRIO GERADOR           %c\n", 186, 181, 186);

    
    printf("%c", 204);
    for(int i=0;i<40;i++) printf("%c",205);
    printf("%c\n%c\t   SELECIONE UMA OPC%cO           %c\n%c                                        %c\n", 186,186, 199, 186,186,186);

    printf("%c\t", 186);
    printf("[ 1 ] VALIDAR                    %c\n",186);
    printf("%c\t", 186);
    printf("[ 2 ] VOLTAR                     %c\n",186);
    printf("%c\t", 186);
    printf("                                 %c\n",186);
    printf("%c\t", 186);
    printf("                                 %c\n",186);
    printf("%c\t", 186);

    printf("                                 %c\n",186);
    printf("%c\t", 186);
    printf("                                 %c\n",186);
    printf("%c", 200);

    for(int i=0;i<40;i++) printf("%c",205);
    printf("%c\n ESCOLHA: ", 188);

}

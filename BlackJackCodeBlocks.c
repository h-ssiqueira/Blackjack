// Alcides Gomes Beato Neto   RA 19060987
// Henrique Sartori Siqueira  RA 19240472
// Thiago Hideki Honda        RA 19310515

//#include <allegro.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct players{ // estrutura para as informações do jogador
    char name[30],v[19]; // respectivo nome e vetor para o valor das cartas
    float money, startbet, bet; // respectivos valores monetários de controle para apostas e contador para o vetor de cartas
    int wins, loses, ties, total, sum, A, bust, bj, cc; // respectivas estatísticas de jogo
}player;

typedef struct table{ // estrutura para os dados do banqueiro
    int bust, sum, A, bj;
    float bank;
}dealer;

//############################################################

void getplayerinfo(player p[],int pla){ // função para coleta dos dados dos jogadores
    for(int i=0; i < pla; i++){

        fflush(stdin);
        printf("\n\tInsert your name player %d: ",i+1);
        gets(p[i].name); // nomeia cada jogador
        fflush(stdin);

        do{
            printf("\n\tInsert your money for bets, %s: ",p[i].name);
            scanf("%f",&p[i].money); // dinheiro inicial
            fflush(stdin);
            system("cls");

            if(p[i].money < 50)
                printf("\n\tERROR! Value out of range! Try again.");

        }while(p[i].money < 50); // verificação se maior que $50

        p[i].loses = 0;
        p[i].wins = 0;
        p[i].ties = 0;
        p[i].total = 0;
        p[i].sum = 0; // Soma das cartas
        p[i].A = 0; // Utilizado como variável booleana para Às
        p[i].bust = 0; // Utilizado como variável booleana caso o jogador tenha estourado a soma das cartas
        p[i].bj = 0; // Utilizado como variável booleana caso o jogador consiga um blackjack (soma=21)
        p[i].startbet = p[i].money;
        p[i].startbet *= 0.3; // verificação para 30%
        p[i].cc = 0; // zera o contador para o vetor de valor de cartas
    }
}


void placebet(player p[],int pla){ // função para coleta do valor da aposta
    for(int i=0; i < pla; i++){
        do{
            printf("\n\tYou have $%.2f.\n\tInsert your bet value, %s: ",p[i].money,p[i].name);
            scanf("%f",&p[i].bet); // valor a ser apostado
            fflush(stdin);

            system("cls");
            if(p[i].bet < 2 || p[i].bet > p[i].startbet)
                printf("\n\tERROR! Value out of range! Try again.");
        }while(p[i].bet < 2 || p[i].bet > p[i].startbet);

        p[i].money -= p[i].bet; // subtrai do montante
    }
}


int givecard(int cardcheck[],int de){ // função carta aleatória
    int n;

    do{
        n = (rand()%13); // número aleatório para cartas (0-12)
    }while(cardcheck[n] == de * 4);
    cardcheck[n]++;
    //printf("%d ",n);
    //srand(time(NULL)); // função para coleta de nº aleatório atraves do horário

return n;
}


void sumcardp(char deck[], int n, player p[], int j,dealer *d){ // função soma das cartas
    switch(deck[n]){
        case 'A': // caso ÀS
            if((p[j].sum + 11) > 21){ // verificação se estoura se soma 11 ou se já existe às valendo 11
                p[j].sum++;
                if(p[j].sum>21 && p[j].A == 1){ // verificação bust
                    p[j].sum -= 10;// subtrai 10 se houver às valendo 11
                    p[j].A--;
                }
                else{ // bust
                        p[j].bust++;
                        d->bank += p[j].bet;
                        p[j].loses++;
                        p[j].total++;
                }
            }
            else{
                p[j].sum+=11;
                p[j].A++;
            }
            break;
        case '2':
            p[j].sum+=2;
            if(p[j].sum>21){
                if(p[j].A == 1){
                    p[j].sum -= 10;
                    p[j].A--;
                }
                else{
                    p[j].bust++;
                    d->bank += p[j].bet;
                    p[j].loses++;
                    p[j].total++;
                }
            }
            break;
        case '3':
            p[j].sum+=3;
            if(p[j].sum>21){
                if(p[j].A == 1){
                    p[j].sum -= 10;
                    p[j].A--;
                }
                else{
                    p[j].bust++;
                    d->bank += p[j].bet;
                    p[j].loses++;
                    p[j].total++;

                }
            }
            break;
        case '4':
            p[j].sum+=4;
            if(p[j].sum>21){
                if(p[j].A == 1){
                    p[j].sum -= 10;
                    p[j].A--;
                }
                else{
                    p[j].bust++;
                    d->bank += p[j].bet;
                    p[j].loses++;
                    p[j].total++;
                }
            }
            break;
        case '5':
            p[j].sum+=5;
            if(p[j].sum>21){
                if(p[j].A == 1){
                    p[j].sum -= 10;
                    p[j].A--;
                }
                else{
                    p[j].bust++;
                    d->bank += p[j].bet;
                    p[j].loses++;
                    p[j].total++;
                }
            }
            break;
        case '6':
            p[j].sum+=6;
            if(p[j].sum>21){
                if(p[j].A == 1){
                    p[j].sum -= 10;
                    p[j].A--;
                }
                else{
                    p[j].bust++;
                    d->bank += p[j].bet;
                    p[j].loses++;
                    p[j].total++;
                }
            }
            break;
        case '7':
            p[j].sum+=7;
            if(p[j].sum>21){
                if(p[j].A == 1){
                    p[j].sum -= 10;
                    p[j].A--;
                }
                else{
                    p[j].bust++;
                    d->bank += p[j].bet;
                    p[j].loses++;
                    p[j].total++;
                }
            }
            break;
        case '8':
            p[j].sum+=8;
            if(p[j].sum>21){
                if(p[j].A == 1){
                    p[j].sum -= 10;
                    p[j].A--;
                }
                else{
                    p[j].bust++;
                    d->bank += p[j].bet;
                    p[j].loses++;
                    p[j].total++;
                }
            }
            break;
        case '9':
            p[j].sum+=9;
            if(p[j].sum>21){
                if(p[j].A == 1){
                    p[j].sum -= 10;
                    p[j].A--;
                }
                else{
                    p[j].bust++;
                    d->bank += p[j].bet;
                    p[j].loses++;
                    p[j].total++;
                }
            }
            break;
        default: // Caso 10,J,Q,K todas valem 10
            p[j].sum+=10;
            if(p[j].sum>21){
                if(p[j].A == 1){
                    p[j].sum -= 10;
                    p[j].A--;
                }
                else{
                    p[j].bust++;
                    d->bank += p[j].bet;
                    p[j].loses++;
                    p[j].total++;
                }
            }
            break;

    }//switch
    if(p[j].sum == 21)
        p[j].bj++;
}


void sumcardd(dealer *d,int n,char deck[]){ // somatória das cartas da mesa
    switch(deck[n]){
        case 'A': // caso ÀS
            if((d->sum+11)>21){ // verificação se estoura se soma 11 ou se já existe às valendo 11
                d->sum++;
                if(d->sum>21 && d->A == 1){ // verificação bust
                        d->sum -= 10;// subtrai 10 se houver às valendo 11
                        d->A--;
                    }
                    else{ // bust
                        d->bust++;
                    }
                }
            else{
                d->sum+=11;
                d->A++;
            }
            break;
        case '2':
            d->sum+=2;
            if(d->sum>21){
                if(d->A == 1){
                    d->sum -= 10;
                    d->A--;
                }
                else{
                    d->bust++;
                }
            }
            break;
        case '3':
            d->sum+=3;
            if(d->sum>21){
                if(d->A == 1){
                    d->sum -= 10;
                    d->A--;
                }
                else{
                    d->bust++;
                }
            }
            break;
        case '4':
            d->sum+=4;
            if(d->sum>21){
                if(d->A == 1){
                    d->sum -= 10;
                    d->A--;
                }
                else{
                    d->bust++;
                }
            }
            break;
        case '5':
            d->sum+=5;
            if(d->sum>21){
                if(d->A == 1){
                    d->sum -= 10;
                    d->A--;
                }
                else{
                    d->bust++;
                }
            }
            break;
        case '6':
            d->sum+=6;
            if(d->sum>21){
                if(d->A == 1){
                    d->sum -= 10;
                    d->A--;
                }
                else{
                    d->bust++;
                }
            }
            break;
        case '7':
            d->sum+=7;
            if(d->sum>21){
                if(d->A == 1){
                    d->sum -= 10;
                    d->A--;
                }
                else{
                    d->bust++;
                }
            }
            break;
        case '8':
            d->sum+=8;
            if(d->sum>21){
                if(d->A == 1){
                    d->sum -= 10;
                    d->A--;
                }
                else{
                    d->bust++;
                }
            }
            break;
        case '9':
            d->sum+=9;
            if(d->sum>21){
                if(d->A == 1){
                    d->sum -= 10;
                    d->A--;
                }
                else{
                    d->bust++;
                }
            }
            break;
        default: // Caso 10,J,Q,K todas valem 10
            d->sum+=10;
            if(d->sum>21){
                if(d->A == 1){
                    d->sum -= 10;
                    d->A--;
                }
                else{
                    d->bust++;
                }
            }
            break;

    }//switch
    if(d->sum == 21)
        d->bj++;

}


int blackjack(player p[], int pla){ // conferência para instantaneo blackjack
    int aux = 0;

    for(int i=0; i < pla; i++){
        if(p[i].bj == 1){
            aux++;
            break;
        }
    }

return aux;
}


int bigger(player p[],int pla){ // maior valor na mão de um jogador
    int aux = 0;

    for(int i=0; i < pla; i++){
        if(aux < p[i].sum && p[i].bust == 0)
            aux = p[i].sum;
    }

return aux;
}

void cards (player p[],int j){
    int i;
    for(i=0; i<p[j].cc; i++){
        switch(p[j].v[i]){
            case 'A': printf(" ___\t"); break;

            case '2': printf(" ___\t"); break;

            case '3': printf(" ___\t"); break;

            case '4': printf(" ___\t"); break;

            case '5': printf(" ___\t"); break;

            case '6': printf(" ___\t"); break;

            case '7': printf(" ___\t"); break;

            case '8': printf(" ___\t"); break;

            case '9': printf(" ___\t"); break;

            case '1': printf(" ____\t"); break;

            case 'J': printf(" ____\t"); break;

            case 'Q': printf(" ____\t"); break;

            case 'K': printf(" ____\t"); break;

        }
    }
    printf("\n");

    for(i=0; i<p[j].cc; i++){
        switch(p[j].v[i]){
            case 'A': printf("| A |\t"); break;

            case '2': printf("| 2 |\t"); break;

            case '3': printf("| 3 |\t"); break;

            case '4': printf("| 4 |\t"); break;

            case '5': printf("| 5 |\t"); break;

            case '6': printf("| 6 |\t"); break;

            case '7': printf("| 7 |\t"); break;

            case '8': printf("| 8 |\t"); break;

            case '9': printf("| 9 |\t"); break;

            case '1': printf("| 10 |\t"); break;

            case 'J': printf("| J |\t"); break;

            case 'Q': printf("| Q |\t"); break;

            case 'K': printf("| K |\t"); break;

        }
    }
    printf("\n");

    for(i=0; i<p[j].cc; i++){
        switch(p[j].v[i]){
            case 'A': printf("|___|\t"); break;

            case '2': printf("|___|\t"); break;

            case '3': printf("|___|\t"); break;

            case '4': printf("|___|\t"); break;

            case '5': printf("|___|\t"); break;

            case '6': printf("|___|\t"); break;

            case '7': printf("|___|\t"); break;

            case '8': printf("|___|\t"); break;

            case '9': printf("|___|\t"); break;

            case '1': printf("|____|\t"); break;

            case 'J': printf("|___|\t"); break;

            case 'Q': printf("|___|\t"); break;

            case 'K': printf("|___|\t"); break;

        }
    }
    printf("\n");
}


void management(player p[],int pla,int *winplayer,dealer *d,int aux,int totalrounds){ // função de controle estatístico dos jogadores
    int i,k;

    for(i=0,k=0; i < pla; i++){
        if(p[i].sum < aux && p[i].bust == 0){ // os jogadores com valor menor perdem
            printf("\n\t%s loses this round!",p[i].name);
            p[i].loses++;
            p[i].total++;
            p[i].bust++;
            d->bank += p[i].bet;
        }
        else if(p[i].sum > d->sum && p[i].bust == 0){ // se jogadores tem maior valor que a mesa
            (*winplayer)++; // confere se há mais de um vencedor
            k=i; // utiliza-se caso haja 1 vencedor
        }
        else if(p[i].sum == d->sum && p[i].bust == 0){ // empate
            printf("\n\t%s ties this round!",p[i].name);
            p[i].money += p[i].bet;
            p[i].ties++;
            p[i].total++;
        }
        else if(p[i].bust == 0){ // mesa tem valor maior
            printf("\n\t%s loses this round!",p[i].name);
            p[i].loses++;
            p[i].total++;
            p[i].bust++;
            d->bank += p[i].bet;
        }
}//for
    if((*winplayer) == 1){ // se houver um vencedor
        printf("\n\t%s wins this round, congratulations!",p[k].name);
        p[k].money += (2 * p[k].bet);
        d->bank -= p[k].bet;
        p[k].wins++;
        p[k].total++;
    }
    else if((*winplayer) > 1){ // se houver empate
        for(i=0; i < pla; i++){
            if(totalrounds == p[i].total){ // contador de rounds == total refere-se que não foi incrementado o total do jogador
                printf("\n\t%s ties this round!",p[i].name);
                p[i].money += p[i].bet;
                p[i].ties++;
                p[i].total++;
            }
        }
    }//elif
}//void


void setzero(player p[],int pla,int cardcheck[],dealer *d,int *win){ // para zerar as varíaveis para uma próxima rodada
    int i;

    for (i=0; i < pla; i++){ // zerar soma e valores 'booleanos' dos jogadores
        p[i].sum = 0;
        p[i].A = 0;
        p[i].bust = 0;
        p[i].bj = 0;
        p[i].cc = 0;
    }

    for(i=0; i < 13; i++) // zerar contagem das cartas
        cardcheck[i] = 0;

    d->A = 0; // zerar soma e valores 'booleanos' do banqueiro
    d->sum = 0;
    d->bust = 0;
    d->bj = 0;

    *win = 0; // zerar contador de possível empate
}



//######################################################

int main()
{
    FILE *arq;
    int i, j, k, x, y, pla, de, n, cardcheck[13]={'\0'}, endg, aux, winplayer = 0, totalrounds = 0;
    char deck[]={"A234567891JQK\0"},line1[50],line2[20];
    player *p;
    dealer d;

    srand(time(NULL)); //srand(time(NULL)); // função para coleta de nº aleatório atraves do horário
    fflush(stdin);

    printf("\n\n\t ________   ___        ________   ________   ___  __           ___   ________   ________   ___  __       \n");
    printf("\t|\\   __  \\ |\\  \\      |\\   __  \\ |\\   ____\\ |\\  \\|\\  \\        |\\  \\ |\\   __  \\ |\\   ____\\ |\\  \\|\\  \\     \n");
    printf("\t\\ \\  \\|\\ /_\\ \\  \\     \\ \\  \\|\\  \\\\ \\  \\___| \\ \\  \\/  /|_      \\ \\  \\\\ \\  \\|\\  \\\\ \\  \\___| \\ \\  \\/  /|_   \n");
    printf("\t \\ \\   __  \\\\ \\  \\     \\ \\   __  \\\\ \\  \\     \\ \\   ___  \\   __ \\ \\  \\\\ \\   __  \\\\ \\  \\     \\ \\   ___  \\  \n");
    printf("\t  \\ \\  \\|\\  \\\\ \\  \\____ \\ \\  \\ \\  \\\\ \\  \\____ \\ \\  \\\\ \\  \\ |\\  \\\\_\\  \\\\ \\  \\ \\  \\\\ \\  \\____ \\ \\  \\\\ \\  \\ \n");
    printf("\t   \\ \\_______\\\\ \\_______\\\\ \\__\\ \\__\\\\ \\_______\\\\ \\__\\\\ \\__\\\\ \\________\\\\ \\__\\ \\__\\\\ \\_______\\\\ \\__\\\\ \\__\\\n");
    printf("\t    \\|_______| \\|_______| \\|__|\\|__| \\|_______| \\|__| \\|__| \\|________| \\|__|\\|__| \\|_______| \\|__| \\|__|\n");
    printf("\t\t   ___    ___    ___    ___    ___    ___    ___    ___    ___    ____    ___    ___    ___");
    printf("\n\t\t  | A |  | 2 |  | 3 |  | 4 |  | 5 |  | 6 |  | 7 |  | 8 |  | 9 |  | 10 |  | J |  | Q |  | K |");
    printf("\n\t\t  |___|  |___|  |___|  |___|  |___|  |___|  |___|  |___|  |___|  |____|  |___|  |___|  |___| ");
    printf("\n\n\n\t\t\t\tPress any key to continue...");
    getch();
    fflush(stdin);

    system("cls");


    do{
        printf("\n\tInsert number of players: "); // número de jogadores
        scanf("%d",&pla);

        system("cls");

        if(pla < 1 || pla > 4)
            printf("\n\tERROR! Value out of range! Try again.");

    }while(pla < 1 || pla > 4);

    p = (player *) malloc(pla * sizeof(player));// aloca

        do{
            printf("\n\tInsert number of decks: "); // número de baralhos
            scanf("%d",&de);

            system("cls");

            if(de < 2 || de > 4)
                printf("\n\tERROR! Value out of range! Try again.");

        }while(de < 2 || de > 4);

    system("cls");

    getplayerinfo(p,pla); // coleta os dados dos jogadores

    d.A = 0; // zera as variáveis da mesa
    d.bust = 0;
    d.bank = 0;
    d.sum = 0;
    d.bj = 0;

    do{
        placebet(p,pla); // definir apostas

        for(i=0; i < pla; i++){ // cartas iniciais para cada jogador
            for(k=0; k < 2; k++){ // cada um recebe duas
                n = givecard(cardcheck,de); // valor da carta
                sumcardp(deck,n,p,i,&d); // função para somar/ verificar se estoura
                p[i].v[p[i].cc] = deck[n];
                p[i].cc++;
            }//k (2x)
        }//for - cartas iniciais
        j = 0;
        while(j!=2){ // cartas do banqueiro
            n = givecard(cardcheck,de); // valor da carta
            sumcardd(&d,n,deck); // função para somar/verificar se estoura
            j++;
        }

        if(d.bj == 0){ // caso não haja blackjack instantâneo para a mesa
            endg = blackjack(p,pla); // conferência de blackjack instantâneo dos jogadores

            if(endg != 1){ // caso não haja BJ instantâneo de jogador
                for(i=0; i < pla; i++){ // loop para hits e stands

                aux = bigger(p,pla);

                do{
                    do{
                        printf("\n\tHigher value of opponent's hand: %02d.\tDealer's hand: %02d\n\tOne more card, %s? Your sum = %02d",aux,d.sum,p[i].name,p[i].sum);
                        if(p[i].A == 1)
                            printf(" with an Ace worthing 11 on your hand!\n");
                        else
                            printf(" without an Ace worthing 11 on your hand.\n");
                        cards(p,i);
                        printf("\n\t0 = Stand.\n\t1 = Hit.\n\t-> ");
                        scanf("%d",&y);
                        system("cls");
                        if(y!=0 && y!=1)
                            printf("\n\tERROR! Value out of range! Try again.");
                    }while(y!=0 && y!=1);
                    if(y==1){
                        n = givecard(cardcheck,de); // valor da carta
                        sumcardp(deck,n,p,i,&d); // função para somar/ verificar se estoura
                        p[i].v[p[i].cc] = deck[n];
                        p[i].cc++;
                        if(p[i].bust == 1){
                            y = 0;
                            printf("\n\tSum resulting more than 21, you burst! Good luck next time.\n");
                            printf("\n\n\tPress any key to continue...");
                            getch();
                            fflush(stdin);
                            system("cls");
                        }
                }
                }while(y!=0);
            } // for - hit/stand

                system("cls");

                aux = bigger(p,pla); // maior valor de carta de um jogador

                if(d.sum <= 17){
                    if(((d.sum - 11) <= 6 && d.A == 1) || d.sum < 17){

                        do{
                            n = givecard(cardcheck,de); // valor da carta
                            sumcardd(&d,n,deck); // função para somar/verificar se estoura
                        }while(((d.sum - 11) >= 6 && d.A == 1) || d.sum < 17);


                        if(d.bust == 1){ // se a mesa faz bust
                            for(i=0,k=0; i < pla; i++){ // jogadores vencedores pelo bust da mesa
                                if(p[i].sum < aux && p[i].bust == 0){ // os jogadores com valor menor perdem
                                    printf("\n\t%s loses this round!",p[i].name);
                                    p[i].loses++;
                                    p[i].total++;
                                    p[i].bust++;
                                    d.bank += p[i].bet;
                                }
                                if(p[i].bust == 0){
                                    winplayer++;
                                    k = i;
                                }
                            } // for

                            if(winplayer == 1){ // se houver um vencedor
                                printf("\n\t%s wins this round, congratulations!",p[k].name);
                                p[k].money += (2 * p[k].bet);
                                d.bank -= p[i].bet;
                                p[k].wins++;
                                p[k].total++;
                            }
                            else if(winplayer > 1){ // se houver empate
                                for(i=0; i < pla; i++){
                                    if(totalrounds == p[i].total){ // contador de rounds == total refere-se que não foi incrementado o total do jogador
                                        printf("\n\t%s ties this round!",p[i].name);
                                        p[i].money += p[i].bet;
                                        p[i].ties++;
                                        p[i].total++;
                                    }
                                }
                            }
                        }// if - mesa bust
                        else if(d.bj == 1){ // caso haja BJ para a mesa
                            for(i=0; i < pla; i++){
                                if(p[i].bj == 0 && p[i].bust == 0){ // os jogadores sem BJ perdem
                                    printf("\n\t%s loses this round!",p[i].name);
                                    p[i].loses++;
                                    p[i].bust++;
                                    d.bank += p[i].bet;
                                    p[i].total++;
                                } // if
                                else if(p[i].bj == 1){ // os jogadores com BJ empatam
                                    printf("\n\t%s ties this round",p[i].name);
                                    p[i].ties++;
                                    p[i].total++;
                                    p[i].money += (1.5 * p[i].bet);
                                    d.bank -= (0.5 * p[i].bet);
                                } //else
                            } // for
                        }//elif - BJ mesa
                        else if(d.bust == 0 && d.bj == 0){ // se não houver bust nem BJ para a mesa
                            management(p,pla,&winplayer,&d,aux,totalrounds);
                        }//elif sem bust e BJ da mesa
                    }// if - requesitos para mesa pegar +1 carta
                    if(d.sum == 17){
                        management(p,pla,&winplayer,&d,aux,totalrounds);
                    }
                } // mesa == 17 sem às || às + cartas > 17
                else{ // mesa > 17
                    management(p,pla,&winplayer,&d,aux,totalrounds);
                } //else - mesa >17
            } // sem insta BJ de jogador
            else if(endg == 1){ // com blackjack instantâneo de jogador (se houver mais de um os dois ganham vitória)
                for(i=0; i < pla; i++){
                    if(p[i].bust == 0 && p[i].bj == 0){
                        printf("\n\t%s loses this round!",p[i].name);
                        p[i].loses++;
                        p[i].bust++;
                        d.bank += p[i].bet;
                        p[i].total++;
                    }
                    else if(p[i].bj == 1){
                        printf("\n\t%s wins this round, congratulations!",p[i].name);
                        p[i].wins++;
                        p[i].total++;
                        p[i].money += (1.5 * p[i].bet);
                        d.bank -= (0.5 * p[i].bet);
                    }
                } // for

            }// com insta BJ de jogador
        }// if - sem blackjack instantâneo da mesa
        else if(d.bj == 1){// caso haja BJ instantâneo para a mesa
            for(i=0; i < pla; i++){
                if(p[i].bj == 0 && p[i].bust == 0){ // os jogadores sem BJ perdem
                    printf("\n\t%s loses this round!",p[i].name);
                    p[i].loses++;
                    d.bank += p[i].bet;
                    p[i].total++;
                    p[i].bust++;
                } // if
                else if(p[i].bust == 0){ // os jogadores com BJ empatam
                    printf("\n\t%s ties this round!",p[i].name);
                    p[i].ties++;
                    p[i].total++;
                    p[i].money += (1.5 * p[i].bet);
                    d.bank -= (0.5 * p[i].bet);
                } //else
            } // for
        } // else

        printf("\n\n\tPress any key to continue...");
        getch();
        fflush(stdin);

        //#################################################################

        printf("\n\t\tCards\tMoney");

        for(i=0; i < pla; i++)
            printf("\n\t%s:\t%02d\t$%5.2f",p[i].name,p[i].sum,p[i].money);

        printf("\n\n\tDealer: %02d\t$%5.2f\n\n\n",d.sum,d.bank);


        do{
            printf("\n\tDo you want to play another round?\n\t0 = No.\n\t1 = Yes.\n\t-> ");
            scanf("%d",&x);
            system("cls");
            if(x != 0 && x != 1)
                printf("\n\tERROR! Value out of range! Try again.");
        }while(x != 0 && x != 1);

        x==1 ? setzero(p,pla,cardcheck,&d,&winplayer),totalrounds++:totalrounds++; // operador ternário


    }while(x!=0);//para cada rodada

    // impressão de relatório usando arquivo

    arq = fopen("Data.txt", "w"); // escrita no arquivo

        fprintf(arq,"Dealer's amount: $%5.2f\n\n",d.bank);

        fprintf(arq,"Name\tWins\tTies\tLoses\tTotal\tMoney\n");
        for(i=0; i < pla; i++)
            fprintf(arq,"%s\t%2d\t%2d\t%2d\t%d\t$%5.2f\n",p[i].name,p[i].wins,p[i].ties,p[i].loses,p[i].total,p[i].money);

    arq != NULL ? fclose(arq) : printf("ERROR! File couldn't be created.");

    arq = fopen("Data.txt", "r"); // abre o arquivo para exibir no console

        fscanf(arq,"%[^\n]s",line2);
        fflush(stdin);
        printf("%s\n\n",line2);

        fscanf(arq, "\n\n%[^\n]s", line1);
        fflush(stdin);
        printf("%s\n",line1);

        for(i=0; i < pla; i++){
            fscanf(arq,"%[^\n]s\t%d\t%d\t%d\t%d\t$%f\n",p[i].name,&p[i].wins,&p[i].ties,&p[i].loses,&p[i].total,&p[i].money);
            fflush(stdin);
            printf("%s\t%d\t%d\t%d\t%d\t$%5.2f\n",p[i].name,p[i].wins,p[i].ties,p[i].loses,p[i].total,p[i].money);
        }

    arq != NULL ? fclose(arq): printf("ERROR! File not found.");

free(p); // desalocamento

    return 0;
}


#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include <time.h>

/* Cores Personalizadas */

//Regular text
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define YEL "\e[0;33m"

//Regular bold text
#define BRED "\e[1;31m"
#define BGRN "\e[1;32m"
#define BBLU "\e[1;34m"
#define BMAG "\e[1;35m"
#define BCYN "\e[1;36m"

//Regular underline text
#define URED "\e[4;31m"
#define UGRN "\e[4;32m"
#define UBLU "\e[4;34m"
#define UMAG "\e[4;35m"
#define UCYN "\e[4;36m"

//Regular background
#define REDB "\e[41m"
#define GRNB "\e[42m"
#define BLUB "\e[44m"
#define MAGB "\e[45m"
#define CYNB "\e[46m"

//Reset
#define reset "\e[0m"

/* Introdução do Jogo */

void criarIntro() { // 
  printf(BGRN "\n***********************************************\n");
  printf("*                                             *\n");
  printf("*                BEM VINDO!                   *\n");
  printf("*     "
    CYNB "OCP - ODISSEIA DO CODIGO PERDIDO"
    reset BGRN "        *\n");
  printf("*                                             *\n");
  printf("***********************************************\n\n"
    reset);
}

/* Funções Úteis */

void criarTitulo(char * text) {
  printf(GRN "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
  printf(BLU "\n%s\n", text);
  printf(GRN "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    reset);
}

void criarLinha() {
  printf(GRN "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n"
    reset);
}

void criarSubtitulo(char * text) {
  printf(CYN "\n%s\n", text);
  printf("---> "
    reset);
}

void criarErro(char * text) {
  printf(URED "\n%s\n"
    reset, text);
}

void criarTituloSub(char * titulo, char * subtitulo) {
  printf(GRN "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
  printf(BLU "\n%s\n", titulo);
  printf(CYN "%s\n", subtitulo);
  printf(GRN "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    reset);
}

void sendGameOver() {
  printf(RED "\n-_-_-_-_GAME OVER_-_-_-_-\n"
    reset);

  printf("\nVocê deseja "
    GRN "reiniciar"
    reset " o jogo?\n");
  printf("\n"
    GRN "1"
    reset " - Sim");
  printf("\n"
    GRN "2"
    reset " - Não\n");
  criarSubtitulo("Digite a opção desejada:");
}

/* Main */

int main() {
  int gameOver = 1;
  while (gameOver != 2) {
    srand(time(NULL));
    int opcao = 0;
    int personagemCriado = 0;
    int cp_tamanho_nome, cp_tamanho_historia;
    char cp_nome[100];
    char cp_historia[1000];
    int cp_raca, cp_alinhamento, cp_profissao, cp_meta, cp_meio, cp_porte;
    int vida = 100;
    int jokenpo, maquina_jokenpo;
    int pont_usuario = 0, pont_maquina = 0;
    int charada1, charada2, charada3, flag = 0;

    /* Personagem TESTE */
    /*
    int personagemTeste = -1;
  
    printf("MODO SANDBOX DE TESTE!\n");
    printf("Escolha um personagem:\n");
    printf("0 - Criar Personagem \n");
    printf("1 - Humano, Bom, Mago, Medio \n");
    printf("2 - Anao, Mal, Ladino, Pequeno\n");
    printf("3 - Elfo, Neutro, Guerreiro, Grande\n");
    printf("Digite a opção: ");
    scanf("%d", &personagemTeste);
    
    if (personagemTeste == 1) { // Mago, Bom, Humano, Médio
      strcpy(cp_nome, "Harry Potter");
      strcpy(cp_historia, "Bruxo dos Bruxo");
      cp_raca = 1;
      cp_porte = 2;
      cp_alinhamento = 3;
      cp_profissao = 2;
      cp_meta = 3;
      cp_meio = 1;
    } else if (personagemTeste == 2) { // Anão, Mal, Ladino, Pequeno
      strcpy(cp_nome, "Little Hair");
      strcpy(cp_historia, "Anãozin");
      cp_raca = 2;
      cp_porte = 3;
      cp_alinhamento = 1;
      cp_profissao = 3;
      cp_meta = 2;
      cp_meio = 1;
    } else if (personagemTeste == 3) { // Elfo, Guerreiro, Bom, Grande
      strcpy(cp_nome, "Yashin Rajdeir");
      strcpy(cp_historia, "Elfo mágico");
      cp_raca = 3;
      cp_porte = 1;
      cp_alinhamento = 2;
      cp_profissao = 1;
      cp_meta = 3;
      cp_meio = 3;
    }
    
    if (personagemTeste != 0) { personagemCriado = 1; }
    */

    criarIntro();

    while (opcao != 3) {
      /* Menu de entrada */
      printf(BGRN "Escolha uma opção:\n");
      printf(personagemCriado == 0 ? GRN "1. "
        reset "Criar Personagem\n" : GRN "1. "
        reset "Editar Personagem\n");
      printf(GRN "2. "
        reset "Iniciar Jogo\n");
      printf(GRN "3. "
        reset "Sair\n");
      printf(GRN "---> "
        reset);
      scanf("%d", & opcao);

      switch (opcao) {
      case 1: {
        /* Criação de Personagem */
        criarTitulo(personagemCriado == 0 ? "CRIAÇÃO DE PERSONAGEM" : "RECRIAÇÃO DE PERSONAGEM");

        // Nome [ cp_nome ]
        do {
          criarSubtitulo("Digite o nome do seu personagem (até 20 caracteres):");
          scanf(" %[^\n]", cp_nome);
          cp_tamanho_nome = strlen(cp_nome);
          if (cp_tamanho_nome > 20) {
            criarErro("Nome inserido excedeu o número máximo de caracteres!");
            printf(RED "Porfavor insira um nome de até 20 caracteres.\n");
          }
        } while (cp_tamanho_nome > 20);
        do { // Raça [ cp_porte ]
          criarSubtitulo("Escolha a raça do seu personagem (1 - Humano, 2 - Anão, 3 - Elfo): ");
          scanf(" %d", & cp_raca);
          if (cp_raca < 1 || cp_raca > 3) {
            criarErro("Opção inválida!");
            printf(RED "Porfavor insira uma das opções apresentadas.\n");
          }
        } while (cp_raca < 1 || cp_raca > 3);

        do { // Porte [ cp_raca ]
          criarSubtitulo("Escolha o porte do seu personagem (1 - Grande, 2 - Médio, 3 - Pequeno): ");
          scanf("%d", & cp_porte);
          if (cp_raca == 2 && cp_porte == 1) {
            criarErro("Você não pode selecionar o porte grande sendo um anão!");
            cp_porte = 0;
            continue;
          }
          if (cp_porte < 1 || cp_porte > 3) {
            criarErro("Opção inválida!");
            printf(RED "Porfavor insira uma das opções apresentadas.\n");
          }
        } while (cp_porte < 1 || cp_porte > 3);

        do { // Alinhamento [ cp_raca ]
          criarSubtitulo("Escolha o alinhamento do seu personagem (1 - Mal, 2 - Neutro, 3 - Bom): ");
          scanf("%d", & cp_alinhamento);
          if (cp_alinhamento < 1 || cp_alinhamento > 3) {
            criarErro("Opção inválida!");
            printf(RED "Porfavor insira uma das opções apresentadas.\n");
          }
        } while (cp_alinhamento < 1 || cp_alinhamento > 3);

        do { // Profissão [ cp_profissao ]
          criarSubtitulo("Escolha a classe do seu personagem (1 - Guerreiro, 2 - Mago, 3 - Ladino): ");
          scanf("%d", & cp_profissao);
          if (cp_alinhamento == 3 && cp_profissao == 3) {
            criarErro("Você não pode escolher a classe Ladino tendo um alinhamento Bom!");
            cp_profissao = 0;
            continue;
          }
          if (cp_profissao < 1 || cp_profissao > 3) {
            criarErro("Opção inválida!");
            printf(RED "Porfavor insira uma das opções apresentadas.\n");
          }
        } while (cp_profissao < 1 || cp_profissao > 3);

        do { // Meta [ cp_raca ]
          criarSubtitulo("Escolha a meta do seu personagem (1 - Governar o reino, 2 - Ficar rico, 3 - Destruir o mal): ");
          scanf("%d", & cp_meta);
          if (cp_meta == 3 && cp_alinhamento == 1) {
            criarErro("Você não pode escolher a meta \"Destruir o mal\" tendo o alinhamento Mal!");
            cp_meta = 0;
            continue;
          }
          if (cp_meta < 1 || cp_meta > 3) {
            criarErro("Opção inválida!");
            printf(RED "Porfavor insira uma das opções apresentadas.\n");
          }
        } while (cp_meta < 1 || cp_meta > 3);

        do { // Meio [ cp_meio ]
          criarSubtitulo("Escolha o meio em que seu personagem vive (1 - Urbano, 2 - Rural, 3 - Tribal): ");
          scanf("%d", & cp_meio);
          if (cp_profissao == 3 && cp_meio == 3) {
            criarErro("Você não pode escolher o meio Tribal tendo a classe Ladino!");
            cp_meio = 0;
            continue;
          }
          if (cp_meio < 1 || cp_meio > 3) {
            criarErro("Opção inválida!");
            printf(RED "Porfavor insira uma das opções apresentadas.\n");
          }

        } while (cp_meio < 1 || cp_meio > 3);

        // Historia [ cp_historia ]
        do {
          criarSubtitulo("Escreva a história do seu personagem (até 400 caracteres):");
          scanf(" %[^\n]", cp_historia);
          cp_tamanho_historia = strlen(cp_historia);
          if (cp_tamanho_historia > 400) {
            criarErro("História inserida excedeu o número máximo de caracteres!");
            printf(RED "Porfavor insira uma história de até 400 caracteres.\n");
          }
        } while (cp_tamanho_historia > 400);

        criarTitulo("SEU PERSONAGEM:");
        printf("\n"
          GRN "Nome: "
          reset "%s"
          "\n", cp_nome);
        printf(GRN "Vida: "
          reset "%d"
          "\n", vida);
        printf(GRN "Raça: "
          reset "%s"
          "\n", (cp_raca == 1 ? "Humano" : (cp_raca == 2 ? "Anão" : "Elfo")));
        printf(GRN "Porte: "
          reset "%s"
          "\n", (cp_porte == 1 ? "Grande" : (cp_porte == 2 ? "Médio" : "Pequeno")));
        printf(GRN "Alinhamento: "
          reset "%s"
          "\n", (cp_alinhamento == 1 ? "Mal" : (cp_alinhamento == 2 ? "Neutro" : "Bom")));
        printf(GRN "Profissao: "
          reset "%s"
          "\n", (cp_profissao == 1 ? "Guerreiro" : (cp_profissao == 2 ? "Mago" : "Ladino")));
        printf(GRN "Meta: "
          reset "%s"
          "\n", (cp_meta == 1 ? "Governar o reino" : (cp_meta == 2 ? " Ficar rico" : "Destruir o mal")));
        printf(GRN "Meio: "
          reset "%s"
          "\n", (cp_meio == 1 ? "Urbano" : (cp_meio == 2 ? "Rural" : "Tribal")));
        printf(GRN "História: "
          reset "%s"
          "\n", cp_historia);

        personagemCriado = 1;
        opcao = 0;
        break;
      }
      case 2:
        if (personagemCriado) {
          int evento1, evento2, evento3, evento4, evento5;

          printf("Iniciando jogo...\n");
          printf(BGRN "\n***********************************************\n");
          printf("*     "
            BLU "OCP - ODISSEIA DO CODIGO PERDIDO"
            reset BGRN "        *\n");
          printf("***********************************************\n"
            reset);

          printf("\n"
            CYNB "=-=-= INTRODUÇÃO =-=-="
            reset "\n");
          printf("\nVocê acorda em um mundo \e[0;32mfantástico\e[0m, cercado por florestas místicas, montanhas imponentes e criaturas de lendas antigas. Este é o reino de Codexia, um lugar onde a magia e a tecnologia se fundem. Você se encontra em uma vila tranquila chamada Byteville, ouvindo rumores de um artefato perdido, conhecido como \e[0;32m\"O Código Perdido\"\e[0m, que dizem ser capaz de \e[0;32mdesvendar os segredos mais profundos de Codexia.\e[0m\n");
          // \e[0;32m \e[0m

          printf("\n"
            CYNB "=-=-= CAPÍTULO 01 =-=-="
            reset "\n");
          printf("\nEnquanto vocë caminha pelo reino de Codéxia, você se depara com \e[0;32mtrês caminhos:\e[0m\n");
          printf("\n\e[0;32m1\e[0m - Seguir a trilha que leva à Floresta de Algoritmos.\n\e[0;32m2\e[0m - Escalar as Montanhas de Metadados.\n\e[0;32m3\e[0m - Explorar as Ruínas Binárias.\n");

          do { // Evento  01

            criarSubtitulo(GRN "Qual será o caminho que você irá trilhar? (Digite 1, 2 ou 3)");
            scanf("%d", & evento1);

            switch (evento1) {
            case 1:
              printf("\nVocê segue pela trilha da Floresta de Algoritmos. À medida que se aprofunda na floresta, o som dos pássaros digitais dá lugar ao zumbido dos bugs voadores. "
                GRN "Um clima de mistério e beleza natural envolve você.\n"
                reset);
              if (cp_meio == 1) {
                printf("\nVocê é acostumado com o meio urbano e não está acostumado com os desafios e mistérios da floresta, e acaba se machucando no caminho ao tentar passar por caminhos que não são recomendados. "
                  RED "[Menos 10 pontos de vida]");
                vida = vida - 10;
                printf(MAG "\n[VIDA ATUAL]: %s %d\n", (vida > 70 ? GRN : ((vida > 40) ? YEL : RED)), vida);
              }
              break;
            case 2:
              printf("\nVocê escolhe escalar as Montanhas de Metadados. "
                GRN "A subida é íngreme, e cada passo é um esforço."
                reset " No entanto, à medida que sobe, a vista panorâmica da paisagem digital abaixo compensa a fadiga.\n");
              if (cp_porte == 3) {
                printf("\nNo meio do caminho, você acabou enfrentando muitos desafios por ser muito pequeno. "
                  RED "[Menos 10 pontos de vida]");
                vida = vida - 10;
                printf(MAG "\n[VIDA ATUAL]: %s %d\n", (vida > 70 ? GRN : ((vida > 40) ? YEL : RED)), vida);
              }
              break;
            case 3:
              printf("\nVocê decide explorar as Ruínas Binárias. À medida que se aventura pelas ruínas, "
                GRN "cada pedra antiga parece contar uma história"
                reset ", um eco dos dias antigos de glória.\n");

              if (cp_meta == 2) {
                printf("\nEntre as ruinas, você avista algo tão brilhante quanto uma estrela e vai verificar o que é. É um baú coberto de pratas e diamantes brilhosos e muito valiosos. Se por fora é assim, imagine o que tem dentro? Você é destemido e louco por riquezas e não perde seu tempo, vai correndo abrir o báu e desfrutar de todas as suas riquezas que tem dentro. Porém, ele estava envolto de um campo de força muito forte, que te jogou para tão longe que você ficou desacordado por 5 minutos. Após o impacto, você estava tão zonzo que desistiu de abrir o báu. "
                  RED "[Menos 10 pontos de vida]");
                vida = vida - 10;
                printf(MAG "\n[VIDA ATUAL]: %s %d\n", (vida > 70 ? GRN : ((vida > 40) ? YEL : RED)), vida);
              }
              break;
            default:
              criarErro("Opção inválida!\nPor favor insira uma das opções apresentadas.");
              break;
            }
          } while (evento1 < 1 || evento1 > 3);

          printf(GRN "\n~> " reset "Você continua sua jornada, cada passo revelando mais sobre este mundo incrível.\n");
          printf(GRN "~> " reset "A jornada é desafiadora. Eventos subsequentes dependerão do " GRN "alinhamento do jogador.\n"reset);
          printf("\n" CYNB "=-=-= CAPÍTULO 02 =-=-=" reset "\n");
          printf("\nNo caminho de sua incrível jornada, você se depara com três estradas que levam para três caminhos  diferentes. Qual você escolhe?\n");

          voltaevento2:

           printf(""GRN "1"reset " - Um caminho formado pela circulaçao humana, floresta á dentro.\n"GRN "2"reset " - Um caminho livre sem nada a frente.\n");

          if (cp_alinhamento == 1) {
            // comerciamente pra roubar
            printf(GRN "3"reset " - Uma estrada com um comerciante ingênuo que tem muitos recursos valiosos.\n");
          } else if (cp_alinhamento == 2) {
            // viajante ferido
            printf(GRN "3"reset " - Uma estrada com um acampamento abandonado logo à frente.\n");
          } else {
            printf(GRN "3"reset " - Uma estrada com um viajante aparentemente ferido.\n");
          }

          do{
            criarSubtitulo(GRN "Escolha a opção desejada:");
            scanf("%d", &evento2);
  
            switch (evento2) {
  
              case 1:
                printf("Você acaba entrando em uma floresta"GRN" muito densa"reset". Após alguns minutos o caminho que estava seguindo se desfaz, então fica um pouco "GRN"confuso"reset" sem saber para onde seguir, nesse momento é atacado por um enxame de"GRN" abelhas"reset", acaba levando algumas picadas, e enquanto fugia das abelhas encontra a saida da floresta acidentalmente. "
                RED "[Menos 10 pontos de vida]");
                vida = vida - 10;
                printf(MAG "\n[VIDA ATUAL]: %s %d\n", (vida > 70 ? GRN : ((vida > 40) ? YEL : RED)), vida);
                if (vida <= 0) {
                sendGameOver();
                scanf("%d", & gameOver);
                opcao = 3;
              }
                
                break;
  
              case 2: 
                printf("O caminho que aparentemente nao tinha nada a frente, era um engano, e na verdade ele acabou te levando para um "GRN"corrego"reset" onde você conseguiu saciar sua sede e descansar um pouco.\n ");

                break;
                
              case 3:
                if (cp_alinhamento == 1) {
                  // comerciamente pra roubar
                  printf("\nVocê encontra um comerciante na estrada, ele parece ingênuo e está com recursos muito valiosos. Você decide enganar o comerciante. Com um truque astuto, você consegue levar alguns de seus itens preciosos sem que ele perceba. Entretanto, você rouba um feijão mágico que tem um feitiço de proteção muito poderoso, e ao tocá-lo, ele explode na sua mão e você tem queimaduras graves. "
                    RED "[Menos 20 pontos de vida]\n");
                  printf(MAG "\n[NOVOS ITENS]:"
                    reset " Mapa do Tesouro, Capa de Invisibilidade, Machado Nórdico, Mapa do Templo Antigo");
                  vida = vida - 20;
                  printf(MAG "\n[VIDA ATUAL]: %s %d\n", (vida > 70 ? GRN : ((vida > 40) ? YEL : RED)), vida);
                  if (vida <= 0) {
                sendGameOver();
                scanf("%d", & gameOver);
                opcao = 3;
              }
                
                } else if (cp_alinhamento == 2) {
                  //acampamento abanadonado
                  printf("\nNo caminho de sua incrível jornada, você encontra um acampamento abandonado, que parece ter alguns recursos valiosos. Você decide pegar os recursos do acampamento abandonado. Isso provavelmente pertencia a algum aventureiro menos sortudo, mas agora, seus pertences vão te ajudar na jornada.\n");
                  printf(MAG "\n[NOVOS ITENS]:"reset " Bolsa de Moedas, Escudo de Madeira, Mapa do Templo Antigo\n");
                } else if(cp_alinhamento == 3){
                  // viajante ferido
                  printf("\nDurante o caminho, você encontra um viajante ferido na estrada. Você decide ajudar o viajante ferido. Ao curar seus ferimentos, você aprende sobre o perigo que o deixou nesse estado. Sua bondade é recompensada com gratidão e informações valiosas.\n");
                  printf(MAG "\n[NOVO CONHECIMENTO]:"reset " Stealth");
                  printf(MAG "\n[NOVOS ITENS]:"reset " Mapa do Templo Antigo\n");
                }
                break;
    
              default:
                criarErro("Opção inválida!\nPor favor insira uma das opções apresentadas.");
                break;
              }
            }while(evento2 < 1 || evento2 > 3);

          
          printf("\n"
            CYNB "=-=-= CAPÍTULO 03 =-=-="
            reset "\n");
          printf("\nNo meio de sua jornada, você encontra um "
            GRN "Mapa antigo"
            reset ", que parece levar a um templo místico que parece "
            GRN "conter os segredos"
            reset " que você procura.\n");
          printf("Ao chegar perto de onde parece estar o templo sagrado, você se depara com uma "
            GRN "horda de goblins"
            reset " bloqueando o caminho. Eles parecem "
            GRN "furiosos"
            reset " e não querem deixar você passar de maneira alguma.\n");

          printf("\nVocê pensa em três alternativas:\n");
          printf(""
            GRN "1"
            reset " - Fugir e se esconder ate eles sairem do caminho.\n"
            GRN "2"
            reset " - Distrair-los e então atacar de surpresa.\n");
          if (cp_profissao == 1) {
            printf(GRN "3"
              reset " - Correr em direção aos goblins confiando na sua habilidade com a espada.\n");
          } else if (cp_profissao == 2) {
            printf(GRN "3"
              reset " - Usar sua magia para assustar os goblins.\n");
          } else if (cp_profissao == 3) {
            printf(GRN "3"
              reset " - Se esconder e mata-los um a um sorrateiramente.\n");
          }
          do {
            criarSubtitulo(GRN "Escolha a opção mais sensata para o seu personagem:");
            scanf("%d", &evento3);

            switch (evento3) {
            case 1:
              if (cp_profissao == 3) {
                printf("\nVocê dá uma "
                  GRN "cambalhota habilidosa"
                  reset " e escapa dos goblins. Eles são pegos de surpresa e antes que possam reagir, você já "
                  GRN "desapareceu na escuridão.\nContudo, você acaba se perdendo da sua rota original e acaba voltando para o passo anterior."
                  reset);
              } else {
                printf("\nVocê não tem habilidades acrobáticas suficientes, se atrapalha na hora de fugir e os goblins conseguem "
                  RED "te proferir alguns golpes"
                  reset ". Apesar disso, você consegue correr e sair vivo, mas acaba se perdendo da sua rota original e acaba voltando para o passo anterior. "
                  RED "[Menos 30 pontos de vida]"
                  reset);
                vida = vida - 30;
                printf(MAG "\n[VIDA ATUAL]: %s %d\n", (vida > 70 ? GRN : ((vida > 50) ? YEL : RED)), vida);
              }
              if (vida <= 0) {
                sendGameOver();
                scanf("%d", & gameOver);
                opcao = 3;
              }

               printf("\n"CYNB "=-=-= CAPÍTULO 02 =-=-="reset "\n");

              printf(reset "\nQual caminho irá seguir? (lembre-se de que ja passou por aqui antes)\n");

              evento2 = 0;
              goto voltaevento2;
            
            case 2:
              printf("\nVocê tenta dialogar com os goblins, mas aparentemente eles não entendem"
                GRN " nada doque você fala"
                reset ", e então começam a conversar entre si. Nesse momento você decide ataca-los com "
                GRN "toda"
                reset " sua força.\nOs goblins foram facilmente derrotados, e você "
                GRN "triunfou"
                reset " sem nenhum arranhão.");
              break;

            case 3:

              if (cp_profissao == 1) {
                printf("\nAo começar a lutar, você percebe que eles são mais fortes do que aparentam ser, e então acaba saindo bem ferido desse confronto, contufdo vitorioso."
                  RED "[Menos 40 pontos de vida]"
                  reset);
                vida -= 40;
                printf(MAG "\n[VIDA ATUAL]: %s %d\n", (vida > 70 ? GRN : ((vida > 50) ? YEL : RED)), vida);
              }
              if (vida <= 0) {
                sendGameOver();
                scanf("%d", & gameOver);
                opcao = 3;
              } else if (cp_profissao == 2) {
                printf("\nAo proferir uma "
                  GRN "bola de fogo "
                  reset "em direção aos goblins, você consegue atingir "
                  GRN "fatalmente"
                  reset " metade da horda, com isso, os sobreviventes do ataque tentam correr na sua direçao tentando te atacar, porêm após matar 2 dos sobreviventes, o restante decide "
                  GRN "fugir"
                  reset " pois nao tinham chances contra você.\n");
              } else if (cp_profissao == 3) {
                printf("\nVocê sobe em cima de uma arvore ao lado do local, e então"
                  GRN " atira uma adaga "
                  reset "em direção aos goblins que os acerta em cheio, nesse momento eles ficam "
                  GRN "perdidos"
                  reset " sem saber de onde foram atingidos, e dessa forma você consegue eliminar com êxito a horda inteira.");

              }
              break;

            default:
              criarErro("Opção inválida!\nPor favor insira uma das opções apresentadas.");
              break;

            }
          } while (evento3 < 1 || evento3 > 3);

          printf("\n\n"
            CYNB "=-=-= CAPÍTULO 04 =-=-="
            reset "\n");

          printf("\nAo se aproximar do templo-fonte, você se depara com uma "
            GRN "construção majestosa"
            reset ", envolta em mistério. Após entrar, encontra uma estátua imponente no centro da sala, cujos olhos brilham intensamente. A estátua fala, com uma voz grave e enigmática:\n\n");

          printf("Se quer passar além deste templo,terás de enfrentar-me em um desafio. Jogo "
            GRN "jokenpo"
            reset " com todos que buscam desvendar os misterios deste mundo. Caso perca você não é "
            GRN "digno"
            reset " de estar aqui e farei de tudo para te"
            GRN " matar!\n"
            reset);

          printf("\nAquele que atingir"
            GRN " 2 pontos primeiro"
            reset " vence a partida.\n"
            GRN);

          do {
            printf(GRN "\nEscolha:\n"
              reset "\e[0;32m1\e[0m - Pedra\n\e[0;32m2\e[0m - Papel\n\e[0;32m3\e[0m - Tesoura\n");

            do {
              criarSubtitulo(reset "Qual sua escolha? "
                GRN "(Digite 1, 2 ou 3)"
                reset);
              scanf("%d", & jokenpo);
              if (jokenpo < 1 || jokenpo > 3) {
                criarErro("Opção inválida!");
                printf(RED "Porfavor insira uma das opções apresentadas.\n");
              }
            } while (jokenpo < 1 || jokenpo > 3);
            maquina_jokenpo = rand() % 4;
            while (maquina_jokenpo == 0) {
              maquina_jokenpo = rand() % 4;
            }
            if (jokenpo == maquina_jokenpo) {
              printf(UCYN "\nEmpate!!.\n"
                reset);
              criarLinha();
              printf("----Placar----\n%s: %d\nGuardião: %d"
                reset, cp_nome, pont_usuario, pont_maquina);
              criarLinha();
            } else if (jokenpo == 1 && maquina_jokenpo == 2) {
              printf(UGRN "\n%s"
                reset " escolheu: Pedra \n"
                URED "Guardião"
                reset " escolheu: Papel\n", cp_nome);
              printf(URED "\nGuardião Ganhou!!\n"
                reset);

              pont_maquina += 1;

              criarLinha();
              printf("----Placar----\n%s: %d\nGuardião: %d"
                reset, cp_nome, pont_usuario, pont_maquina);
              criarLinha();
            } else if (jokenpo == 1 && maquina_jokenpo == 3) {
              printf(UGRN "\n%s"
                reset " escolheu: Pedra \n"
                URED "Guardião"
                reset " escolheu: Tesoura\n", cp_nome);
              printf(UGRN "\n%s Ganhou!!\n"
                reset, cp_nome);

              pont_usuario += 1;

              criarLinha();
              printf("----Placar----\n%s: %d\nGuardião: %d"
                reset, cp_nome, pont_usuario, pont_maquina);
              criarLinha();

            } else if (jokenpo == 2 && maquina_jokenpo == 3) {
              printf(UGRN "\n%s"
                reset " escolheu: Papel \n"
                URED "Guardião"
                reset " escolheu: Tesoura\n", cp_nome);
              printf(URED "\nGuardião Ganhou!!\n"
                reset);

              pont_maquina += 1;

              criarLinha();
              printf("----Placar----\n%s: %d\nGuardião: %d"
                reset, cp_nome, pont_usuario, pont_maquina);
              criarLinha();

            } else if (jokenpo == 2 && maquina_jokenpo == 1) {
              printf(UGRN "\n%s" reset " escolheu: Papel \n" URED "Guardião" reset " escolheu: Pedra\n", cp_nome);
              printf(UGRN "\n%s Ganhou!!\n" reset, cp_nome);
              pont_usuario += 1;
              criarLinha();
              printf("----Placar----\n%s: %d\nGuardião: %d"
                reset, cp_nome, pont_usuario, pont_maquina);
              criarLinha();
            } else if (jokenpo == 3 && maquina_jokenpo == 1) {
              printf(UGRN "\n%s"
                reset " escolheu: Tesoura \n"
                URED "Guardião"
                reset " escolheu: Pedra\n", cp_nome);
              printf(URED "\nGuardião Ganhou!!\n"
                reset);

              pont_maquina += 1;

              criarLinha();
              printf("----Placar----\n%s: %d\nGuardião: %d"
                reset, cp_nome, pont_usuario, pont_maquina);
              criarLinha();
            } else if (jokenpo == 3 && maquina_jokenpo == 2) {
              printf(UGRN "\n%s"
                reset " escolheu: Tesoura \n"
                URED "Guardião"
                reset " escolheu: Papel\n", cp_nome);
              printf(UGRN "\n%s Ganhou!!\n"
                reset, cp_nome);

              pont_usuario += 1;

              criarLinha();
              printf("----Placar----\n%s: %d\nGuardião: %d"
                reset, cp_nome, pont_usuario, pont_maquina);
              criarLinha();
            }
          } while ((pont_usuario < 2) && (pont_maquina < 2));

          if (pont_usuario < pont_maquina) {
            printf(RED "[Menos 70 pontos de vida]"
              reset);
            vida -= 70;
            if (vida < 0) {
              printf(MAG "\n[VIDA ATUAL]:"
                RED " 0"
                reset "\n");
            } else {
              printf(MAG "\n[VIDA ATUAL]: %s %d\n", (vida > 70 ? GRN : ((vida > 50) ? YEL : RED)), vida);
            }

            if (vida <= 0) {
              sendGameOver();
              scanf("%d", & gameOver);
              opcao = 3;
              break;
            } else {
              printf(GRN "\nQue sorte!!"
                reset "\n\nApós a derrota o guardião te acertou em cheio com um "
                RED "golpe fatal"
                reset ", mas por sorte após o golpe você conseguiu se "
                GRN "esconder"
                reset " no corredor ao lado e avançar em busca do código\n");
            }
          }

          printf("\n"
            CYNB "=-=-= CAPÍTULO 05 =-=-="
            reset "\n");

          printf("\nApós vencer o primeiro guardião você segue para o "
            GRN "templo-fonte"
            reset ", tudo parece estar muito fácil ate se deparar com uma sala a qual se assemelha a um santuário, la encontra o imponente e último -"
            GRN " Guardião do Código"
            reset ". Então ele te desafia a resolver uma série de enigmas. Caso responda corretamente, terá livre acesso ao "
            RED "Código Perdido"
            reset "\n");

          printf("\nPorque o programador saiu com uma lâmpada?\n");
          printf(GRN "1"
            reset " - Porque estava com medo do escuro\n");
          printf(GRN "2"
            reset " - Porque queria ter uma ideia brilhante\n");
          printf(GRN "3"
            reset " - Para enxergar o teclado a noite\n");

          do {
            criarSubtitulo(GRN "Qual a resposta da charada? (Digite 1, 2 ou 3)");
            scanf("%d", & charada1);

            switch (charada1) {

            case 1:
              printf(RED "\nResposta errada!\n"
                reset);
              sendGameOver();
              scanf("%d", & gameOver);
              opcao = 3;
              flag = 1;
              break;

            case 2:
              printf(GRN "\nReposta Correta!\n"
                reset);
              printf("\nProxima charada...");
              criarLinha();
              break;

            case 3:
              printf(RED "\nResposta errada!\n"
                reset);
              sendGameOver();
              scanf("%d", & gameOver);

              opcao = 3;
              flag = 1;
              break;
            default:
              criarErro("Opção inválida!\nPor favor insira uma das opções apresentadas.");
            }

          } while (charada1 < 1 || charada1 > 3);

          if (flag == 1) {
            break;
          }

          printf("Porque o robô estava sempre triste?\n");
          printf(GRN "1"
            reset " - Porque o coração dele é um disco rígido\n");
          printf(GRN "2"
            reset " - Porque foi programado para ser assim\n");
          printf(GRN "3"
            reset " - Porque tomou um fora da 'Sophia'\n");

          do {
            criarSubtitulo(GRN "Qual a resposta da charada? (Digite 1, 2 ou 3)");
            scanf("%d", & charada2);

            switch (charada2) {
            case 1:
              printf(GRN "\nReposta Correta!\n"
                reset);
              printf("\nProxima charada...");
              criarLinha();
              break;
            case 2:
              printf(RED "\nResposta errada!\n"
                reset);
              sendGameOver();
              scanf("%d", & gameOver);
              opcao = 3;
              flag = 1;
              break;
            case 3:
              printf(RED "\nResposta errada!\n"
                reset);
              sendGameOver();
              scanf("%d", & gameOver);
              opcao = 3;
              flag = 1;
              break;
            default:
              criarErro("Opção inválida!\nPor favor insira uma das opções apresentadas.");
            }

          } while (charada2 < 1 || charada2 > 3);

          if (flag == 1) {
            break;
          }

          printf("Qual o animal favorito de um programador?\n");
          printf(GRN "1"
            reset " - Leão\n");
          printf(GRN "2"
            reset " - Águia\n");
          printf(GRN "3"
            reset " - Rato\n");

          do {
            criarSubtitulo(GRN "Qual a resposta da charada? (Digite 1, 2 ou 3)");
            scanf("%d", & charada3);

            switch (charada3) {
            case 1:
              printf(RED "\nResposta errada!\n"
                reset);
              sendGameOver();
              scanf("%d", & gameOver);
              opcao = 3;
              flag = 1;
              break;
            case 2:
              printf(RED "\nResposta errada!\n"
                reset);
              sendGameOver();
              scanf("%d", & gameOver);
              opcao = 3;
              flag = 1;
              break;
            case 3:
              printf(GRN "\nReposta Correta!\n"
                reset);
              criarLinha();
              printf("\nParabéns!! Você impressionou todos nese mundo com sua "
                GRN "habilidade"
                reset ".\nA senha para a sala do "
                RED "C0D1G0 P3RD1D0"
                reset " é :\n"
                UMAG "74-101-114-101-109-105-97-115-32-109-101-32-100-97-32-49-48"
                reset "\n\n");
              printf("Você Finalmente revela todos os segredos de CODEXIA. Contudo, acaba saindo mais confuso do que estava no inicio, pois o maior dos segredos é: 'AS MAQUINAS ESTÃO PRESTES A DOMINAR O MUNDO'.\nQual será a proxima "
                GRN "aventura"
                reset " de %s?\n\nDescubra em:\n", cp_nome);
              printf(BGRN "\n***********************************************\n");
              printf("*                                             *\n");
              printf("*                 EM BREVE!                   *\n");
              printf("*  "
                CYNB "OCP2 - ODISSEIA DO CODIGO PERDIDO PARTE 2"
                reset BGRN "  *\n");
              printf("*                                             *\n");
              printf("***********************************************\n\n"
                reset);
              printf(MAG "FIM DO JOGO!\n"
                reset);
              printf("\nVocê deseja "
                GRN "reiniciar"
                reset " o jogo?\n");
              printf("\n"
                GRN "1"
                reset " - Sim");
              printf("\n"
                GRN "2"
                reset " - Não\n");
              criarSubtitulo("Digite a opção desejada:");
              scanf("%d", & gameOver);
              opcao = 3;
              break;
            default:
              criarErro("Opção inválida!\nPor favor insira uma das opções apresentadas.");
            }
          } while (charada3 < 1 || charada3 > 3);

          if (flag == 1) {
            break;
          }

    

        } else {
          criarErro("Personagem não criado. Por favor, crie um personagem antes de iniciar o jogo.\n");
        }
        break;
      case 3:
        printf("Saindo do jogo...\n");
        gameOver = 2;
        break; 
      default:
        criarErro("Opção inválida. Por favor, tente novamente.\n");
        break;
      }
    
      
      criarLinha();

    }
  }

  return 0;
}

/*
raca = (var == 1 ? "Humano" : (var == 2 ? "Anão" : "Elfo"))
porte = (var == 1 ? "Grande" : (var == 2 ? "Médio" : "Pequeno"))
alinhamento = (var == 1 ? "Mal" : (var == 2 ? "Neutro" : "Bom"))
profissao = (var == 1 ? "Guerreiro" : (var == 2 ? "Mago" : "Ladino"))
meta = (var == 1 ? "Governar o reino" : (var == 2 ? " Ficar rico" : "Destruir o mal"))
meio = (var == 1 ? "Urbano" : (var == 2 ? "Rural" : "Tribal"))
*/
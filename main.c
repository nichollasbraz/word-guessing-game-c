#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char palavra[20];
    char dica1[100];
    char dica2[100];
    char dica3[100];

} pergunta;

pergunta perguntas[48] = {
    {"hungria", "País da Europa Central", "Famoso por seus banhos termais", "Capital é Budapeste"},
    {"yuan", "Moeda oficial da China", "Símbolo é ¥", "Também é chamada de renminbi"},
    {"antartida", "Continete gelado", "Lar de pinguins", "Não tem população permanente"},
    {"napoleao", "Líder militar francês", "Exilado em Elba", "Derrotado em Waterloo"},
    {"copacabana", "Famosa praia do Rio de Janeiro", "Local de grandes eventos", "Tem um calçadão icônico"},
    {"beethoven", "Compositor alemão", "Famoso por suas sinfonias", "Perdeu a audição"},
    {"beatles", "Banda britânica", "Formada por John, Paul, George e Ringo", "Famosa por 'Hey Jude'"},
    {"titanic", "Navio de luxo", "Afundou em 1912", "Inspirou um filme de sucesso"},
    {"egito", "País do norte da África", "Famoso por suas pirâmides", "Rio Nilo é importante"},
    {"python", "Linguagem de programação", "Criada por Guido van Rossum", "Famosa por sua simplicidade"},
    {"google", "Empresa de tecnologia", "Criada por Larry Page e Sergey Brin", "Famosa por seu motor de busca"},
    {"mario", "Personagem de videogame", "Criado por Shigeru Miyamoto", "Famoso por salvar a princesa Peach"},
    {"pewdiepie", "Youtuber sueco", "Famoso por seus vídeos de jogos (gameplays)", "Já foi o canal mais inscrito do YouTube"},
    {"capcom", "Empresa de videogames", "Criadora de Street Fighter", "Famosa por Resident Evil"},
    {"bgs", "Evento de games no Brasil", "Realizado em São Paulo", "Reúne fãs e empresas do setor"},
    {"linux", "Sistema operacional", "Criado por Linus Torvalds", "Famoso por ser de código aberto"},
    {"playstation", "Console de videogame", "Criado pela Sony", "Famoso por seus exclusivos como 'God of War'"},
    {"malware", "Software malicioso", "Pode causar danos a computadores", "Exemplos incluem vírus e ransomware"},
    {"twitter", "Plataforma de mídia social", "Famosa por seu limite de 280 caracteres por postagem", "Atualmente é conhecida como X"},
    {"vacuo", "Espaço sem matéria", "Usado em física e engenharia", "Pode ser criado artificialmente"},
    {"inercia", "Propriedade de um objeto de resistir a mudanças em seu estado de movimento", "Formulado por Isaac Newton", "Depende da massa do objeto"},
    {"fotossintese", "Processo pelo qual as plantas produzem energia", "Requer luz solar, água e dióxido de carbono", "É feito pelas clorofilas nas folhas das plantas"},
    {"gravidade", "Força que atrai objetos uns aos outros", "Formulada por Isaac Newton", "Mantém os planetas em órbita ao redor do sol"},
    {"evolucao", "Processo de mudança nas características hereditárias de uma população ao longo do tempo", "Proposto por Charles Darwin", "Explica a diversidade da vida na Terra"},
    {"quantica", "Ramo da física que estuda o comportamento das partículas subatômicas", "Desenvolvida no início do século 20", "Inclui conceitos como superposição e entrelaçamento"},
    {"relatividade", "Teoria formulada por Albert Einstein", "Inclui a relatividade especial e geral", "Explica a gravidade como a curvatura do espaço-tempo"},
    {"cafeina", "Substância estimulante encontrada no café, chá e outras bebidas", "Pode melhorar o foco e a energia", "Excesso pode causar insônia e ansiedade"},
    {"biologia", "Ciência que estuda os seres vivos", "Inclui áreas como zoologia, botânica e microbiologia", "Foca em processos como evolução, genética e ecologia"},
    {"quimica", "Ciência que estuda a composição, estrutura e propriedades da matéria", "Inclui áreas como química orgânica e inorgânica", "Foca em reações químicas e interações moleculares"},
    {"drake", "Rapper canadense", "Famoso por hits como 'Hotline Bling'", "Ex de Rihanna"},
    {"avengers", "Equipe de super-heróis da Marvel", "Inclui personagens como Homem de Ferro, Capitão América e Thor", "Famosa por seus filmes de sucesso"},
    {"skins", "Série de televisão britânica", "Famosa por seu elenco jovem e temas controversos", "Criada por Bryan Elsley e Jamie Brittain"},
    {"coringa", "Vilão do universo Batman", "Famoso por seu sorriso macabro", "Interpretado por atores como Heath Ledger e Joaquin Phoenix"},
    {"shrek", "Personagem de filme de animação", "Famoso por ser um ogro verde", "Tem uma série de filmes de sucesso"},
    {"goku", "Personagem de anime", "Famoso por sua força e habilidades de luta", "Protagonista de 'Dragon Ball'"},
    {"skrillex", "DJ e produtor musical americano", "Ganhou vários prêmios Grammy", "Famoso por popularizar o dubstep"},
    {"lego", "Brinquedo de blocos de construção", "Famoso por suas peças coloridas e versáteis", "Tem uma série de filmes e jogos baseados em suas franquias"},
    {"matheus", "Nome próprio", "Pode ser um nome masculino", "Seu username é 'MathViana97'"},
    {"mpb", "Gênero musical brasileiro", "Inclui artistas como Tom Jobim e Caetano Veloso", "Famoso por suas letras poéticas e melodias suaves"},
    {"rock", "Gênero musical", "Famoso por suas guitarras elétricas e baterias", "Inclui subgêneros como rock clássico, punk e metal"},
    {"socrates", "Filósofo grego", "Famoso por seu método de questionamento", "Foi condenado à morte por suas ideias"},
    {"shakespeare", "Dramaturgo inglês", "Famoso por obras como 'Romeu e Julieta'", "Considerado um dos maiores escritores da língua inglesa"},
    {"maradona", "Jogador de futebol argentino", "Famoso por sua habilidade e controvérsias", "Ganhou a Copa do Mundo de 1986"},
    {"iluminismo", "Movimento intelectual do século 18", "Enfatizava a razão e a ciência", "Influenciou a Revolução Francesa"},
    {"absolutismo", "Sistema de governo onde o monarca tem poder absoluto", "Comum na Europa entre os séculos 16 e 18", "Exemplos incluem Luís XIV da França"},
    {"realismo", "Movimento artístico e literário do século 19", "Enfatizava a representação fiel da realidade", "Famoso por autores como Gustave Flaubert e Charles Dickens"},
    {"ditadura", "Sistema de governo onde o poder é concentrado em um líder ou grupo", "Geralmente caracterizado por repressão e falta de liberdades civis", "Exemplos incluem regimes como o de Adolf Hitler"},
    {"sustentabilidade", "Prática de usar recursos de maneira responsável para preservar o meio ambiente", "Envolve reduzir, reutilizar e reciclar", "Importante para combater as mudanças climáticas"},
};    

int pergunta_aleatoria(pergunta perguntas[], int total, int usadas[]) {
    int i;

    do {
        i = rand() % total;
    } while (usadas[i] == 1);

    usadas[i] = 1;

    return i;
}

int calcular_pontos(int dicas_usadas) {
    if (dicas_usadas == 0) {
        return 5;
    }
    
    else if (dicas_usadas == 1) {
        return 4;
    }
    
    else if (dicas_usadas == 2) {
        return 3;
    }
    
    else {
        return 3;
    }

} 

time_t iniciar_cronometro() {
    return time(NULL);
}

int tempo_restante(int tempo_inicio, int tempo_limite) {
    int tempo_agora = time(NULL);
    int tempo_passado = (int) difftime(tempo_agora, tempo_inicio);
    return tempo_limite - tempo_passado;    
}

void minusculas(char *str) {
    for(int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

void remover_acentos(char *str) {
    char temp[100];
    int j = 0;

    for (int i = 0; str[i]; i++) {
        // á à â ã
        if ((unsigned char)str[i] == 0xC3) {
            i++;
            switch ((unsigned char)str[i]) {
                case 0xA1: case 0xA0: case 0xA2: case 0xA3: temp[j++] = 'a'; break;
                case 0xA9: case 0xAA: temp[j++] = 'e'; break;
                case 0xAD: temp[j++] = 'i'; break;
                case 0xB3: case 0xB4: case 0xB5: temp[j++] = 'o'; break;
                case 0xBA: temp[j++] = 'u'; break;
                case 0xA7: temp[j++] = 'c'; break;
                default: temp[j++] = str[i]; break;
            }
        } else {
            temp[j++] = str[i];
        }
    }

    temp[j] = '\0';
    strcpy(str, temp);
}

typedef struct {
    char nome[30];
    int pontos;
} Jogador;

void salvar_pontuacao(char *nome, int pontos) {
    Jogador jogadores[100];
    int total = 0;
    
    FILE *arquivo = fopen("ranking.txt", "r"); 

    if (arquivo != NULL) {
        while (fscanf(arquivo, "%29[^-] - %d pontos\n", jogadores[total].nome, &jogadores [total].pontos) == 2) {
            jogadores[total].nome[strcspn(jogadores[total].nome, "\n")] = '\0';
            total++;
        }
        
        fclose(arquivo);
    }
    strcpy(jogadores[total].nome, nome);
    jogadores[total].pontos = pontos;
    total++;

    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - i - 1; j++) {
            if (jogadores[j].pontos < jogadores[j + 1].pontos) {
                Jogador temp = jogadores[j];
                jogadores[j] = jogadores[j + 1];
                jogadores[j + 1] = temp;
            }
        }
    }

    arquivo = fopen("ranking.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    int limite = total < 10 ? total : 10;

    for (int i = 0; i < limite; i++) {
        fprintf(arquivo, "%s - %d pontos\n", jogadores[i].nome, jogadores[i].pontos);
    }

    fclose(arquivo);
}

void mostrar_ranking() {
    FILE *arquivo = fopen("ranking.txt", "r");

    if (arquivo == NULL) {
        printf("\nNenhum ranking ainda.\n");
        return;
    }

    char linha[100];

    printf("\nRanking atual:\n");

    int pos = 1;
    while (fgets(linha, sizeof(linha), arquivo)) {
        printf("%dº - %s", pos++, linha);
    }

    fclose(arquivo);
}

int main() {
    char entrada[100]; 
    char nome[30]; 
    char resposta;
    int pontos = 0;
    
    srand(time(NULL));

    int total = sizeof(perguntas) / sizeof(perguntas[0]);
    int usadas[48] = {0};
    int usadas_count = 0;
    
    printf("Digite seu nome: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';
    printf("Jogo iniciado para %s!\n", nome);
    
    do {
        
        if(usadas_count == total) {
            printf("\nTodas as perguntas foram usadas! Reiniciando o jogo...\n");
            for(int j = 0; j < total; j++) {
                usadas[j] = 0;
            }
        
            usadas_count = 0;
        }

        int i = pergunta_aleatoria(perguntas, total, usadas);
        usadas_count++;

        int dicas_usadas = 0;

        time_t tempo_inicio = iniciar_cronometro();
        int tempo_limite = 30;

        printf("\nQual é a palavra? (30 segundos)\n");
        printf("Dica: %s\n", perguntas[i].dica1);            
    
            while (1) {    
                int restante = tempo_restante(tempo_inicio, tempo_limite);
                
                if (restante <= 0) {
                    printf("\nAcabou o tempo! A palavra correta era: %s\n", perguntas[i].palavra);
                    break;
                }
                
                printf("Resposta (ou digite 'dica'): ");

                fgets(entrada, sizeof(entrada), stdin);
                entrada[strcspn(entrada, "\n")] = '\0';
                
                char resposta_correta[100];
                strcpy(resposta_correta, perguntas[i].palavra);

                minusculas(entrada);
                remover_acentos(entrada);

                minusculas(resposta_correta);
                remover_acentos(resposta_correta);
                
                if (strcmp(entrada, "dica") == 0) {         
                    if (dicas_usadas == 0) {
                        printf("Dica: %s\n", perguntas[i].dica2);
                    }
                    
                    else if (dicas_usadas == 1) {
                        printf("Dica: %s\n", perguntas[i].dica3);
                    }
                    
                    else {
                        printf("Você já usou todas as dicas disponíveis!\n");
                    }
                    
                    if (dicas_usadas < 2) {
                        dicas_usadas++;
                    }

                }
             
                
                else if (strcmp(entrada, resposta_correta) == 0) {
                    printf("\nParabéns, %s! Você acertou!\n", nome);
                        
                    int pontos_rodada = calcular_pontos(dicas_usadas);
                    pontos += pontos_rodada;
                        
                    printf("Você ganhou %d pontos!\nTotal: %d pontos\n", pontos_rodada, pontos);

                    break;
                } 
                
                else {
                    printf("Errado! Tempo restante: %ds\n", restante);                    
                }
            }

        printf("\nDeseja jogar novamente? (s/n): ");
        scanf(" %c", &resposta);
        while (getchar() != '\n');

    } while (resposta == 's' || resposta == 'S');

    printf("\nFim de jogo!\n");
    printf("Até a próxima!\n");

    salvar_pontuacao(nome, pontos);
    mostrar_ranking();

    return 0;
}
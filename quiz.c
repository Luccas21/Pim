#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
// Estrutura para armazenar respostas do questionário
struct Resposta {
    char pergunta[100];
    char resposta;
    char correta;
};
 
int main() {
    // Variável para armazenar o nome do arquivo CSV para as respostas do questionário
    char arquivoCSV[50];
    
    // Nome do arquivo CSV para as respostas
    strcpy(arquivoCSV, "respostas.csv");
    
    // Variável para armazenar o número de perguntas no questionário
    int numPerguntas = 7;  // 6 perguntas + questão extra
    
    // Crie um array para armazenar as respostas do questionário
    struct Resposta respostas[numPerguntas];
    
    printf("Bem-vindo ao Quiz - Semana da Arte Moderna!\n");
    
    // Solicite informações pessoais
    char nome[50], sobrenome[50];
    int idade;
    
    printf("Por favor, digite seu nome: ");
    scanf("%s", nome);
    
    printf("Por favor, digite seu sobrenome: ");
    scanf("%s", sobrenome);
    
    printf("Por favor, digite sua idade: ");
    scanf("%d", &idade);
    
    // Solicite que o visitante responda ao questionário
    printf("Por favor, responda ao questionario:\n");
    
    for (int i = 0; i < numPerguntas; i++) {
        printf("Questao %d:\n", i + 1);
        switch (i) {
            case 0:
                printf("Em que ano ocorreu a Semana da Arte Moderna?\n");
                printf("A) 1920, B) 1924, C) 1917, D) 1922, E) 1919\n\n");
                respostas[i].correta = 'D';
                break;
            case 1:
                printf("Dessas manifestacoes artisticas, qual nao foi abordada na Semana da Arte Moderna?\n");
                printf("A) Danca, B) Escultura, C) Pintura, D) Musica, E) Literatura\n\n");
                respostas[i].correta = 'B';
                break;
            case 2:
                printf("Qual cidade brasileira foi palco da Semana da Arte Moderna?\n");
                printf("A) Sao Paulo, B) Brasilia, C) Rio de Janeiro, D) Amazonas, E) Morrinhos\n\n");
                respostas[i].correta = 'A';
                break;
            case 3:
                printf("Quem foi a primeira artista a apresentar seus quadros na semana da Arte Moderna?\n");
                printf("A) Di Cavalcanti, B) Gilda de Mello e Souza, C) Portinari, D) Tarsila do Amaral, E) Anita Malfati\n\n");
                respostas[i].correta = 'E';
                break;
            case 4:
                printf("A Semana da Arte Moderna eh comumente relacionada a um movimento cultural que tenha promovido:\n");
                printf("A) A promocao da arte religiosa, B) A manutencao das tradicoes classicas, C) A valorizacao da cultura estrangeira, D) O conservadorismo artistico, E) A inovacao e a ruptura com convencoes\n\n");
                respostas[i].correta = 'E';
                break;
            case 5:
                printf("Qual corrente artistica europeia mais influenciou os modernistas brasileiros?\n");
                printf("A) Renascimento, B) Impressionismo, C) Cubismo, D) Realismo, E) Romantismo\n\n");
                respostas[i].correta = 'C';
                break;
            case 6:
                printf("O que voce achou da exposicao?\n");
                printf("A) Excelente, B) Muito bom, C) Bom, D) Neutro, E) Ruim\n\n");
                respostas[i].correta = ' ';  // Questão extra não tem resposta correta
                break;
        }
        
        printf("Escolha a opcao (A/B/C/D/E): ");
        scanf(" %c", &respostas[i].resposta);
        
        if (respostas[i].resposta == respostas[i].correta) {
            printf("Voce acertou!\n");
        } else {
            printf("Voce errou. A resposta correta eh: %c\n", respostas[i].correta);
        }
    }
    
    // Calcular o número de questões corretas
    int corretas = 0;
    for (int i = 0; i < 6; i++) {
        if (respostas[i].resposta == respostas[i].correta) {
            corretas++;
        }
    }
    
    // Abra o arquivo CSV para escrita
    FILE *csvFile = fopen(arquivoCSV, "a");  // Modo "a" para anexar ao arquivo existente
    
    if (csvFile == NULL) {
        printf("Erro ao abrir o arquivo CSV.\n");
        return 1;
    }
    
    // Escreva as informações no arquivo CSV
    fprintf(csvFile, "Nome,Sobrenome,Idade,QuestoesCorretas,QuestaoExtra\n");
    fprintf(csvFile, "%s,%s,%d,%d,%c\n", nome, sobrenome, idade, corretas, respostas[6].resposta);
    
    // Feche o arquivo CSV
    fclose(csvFile);
    
    printf("Suas respostas foram salvas com sucesso no arquivo %s.\n", arquivoCSV);
    
    return 0;
}

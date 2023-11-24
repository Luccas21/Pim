#include <stdio.h>
 
// Função para calcular o preço do ingresso com base no tipo e idade
float calcularPreco(int idade, int estudante, int deficiencia) {
    float preco = 10.0; // Preço da entrada inteira
 
    if (estudante || idade >= 60 || deficiencia) {
        preco = 5.0; // Preço da meia entrada
    }
 
    return preco;
}
 
int main() {
    int idade, estudante, deficiencia;
    int totalIngressos = 0;
    float totalVenda = 0.0;
 
    printf("Bem-vindo ao Museu Ocarina!\n");
 
    while (1) {
        int escolha;
        printf("\nEscolha uma opcao:\n");
        printf("1 - Comprar ingresso\n");
        printf("2 - Sair\n");
        scanf("%d", &escolha);
 
        if (escolha == 1) {
            printf("Informe a idade do visitante: ");
            scanf("%d", &idade);
            
            printf("O visitante eh estudante? (1 - Sim, 0 - Nao): ");
            scanf("%d", &estudante);
            
            printf("O visitante tem alguma deficiencia? (1 - Sim, 0 - Nao): ");
            scanf("%d", &deficiencia);
 
            float preco = calcularPreco(idade, estudante, deficiencia);
 
            totalIngressos++;
            totalVenda += preco;
 
            printf("Ingresso comprado com sucesso! Preco: R$%.2f\n", preco);
        } else if (escolha == 2) {
            printf("Total de ingressos vendidos: %d\n", totalIngressos);
            printf("Total arrecadado: R$%.2f\n", totalVenda);
            printf("Obrigado por visitar o Museu Ocarina!\n");
            break;
        } else {
            printf("Opção invalida. Por favor, escolha novamente.\n");
        }
    }
 
    return 0;
}

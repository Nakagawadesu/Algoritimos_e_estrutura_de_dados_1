# Ponteiros em structs - medidas de estrutura esfera

- Implemente uma função que receba um ponteiro do tipo esfera e uma variável estática do tipo float que represente um valor de raio. A partir da varável do tipo float, os campos das estrutura devem ser atualizados.

- Em seguida, imprima os campos da "esfera".

### Input Format

- Na primeira linha da entrada deve ser lido um único float.

### Constraints

- .

### Output Format

- Em cada linha deve ser impresso, considerando uma casa decimal, um campo da esfera na seguinte sequência: raio, área, volume e diâmetro.

### Sample Input 0

- 5.0
### Sample Output 0

- raio: 5.0
- area: 314.0
- volume: 294.4
- diametro: 10.0

# Alocação dinâmica - vetor progressão aritmética

- Implemente uma função que receba dois números inteiros, sendo uma para o tamanho do vetor (n) e a outra para razão (r). A função deverá retornar um vetor de tamanho n ordenado de forma crescente representado uma sequência de elementos de uma progressão aritmética iniciada por 0.


### Input Format

- Na primeira linha devem ser lidos dois números inteiros, sendo o primeiro referente ao tamanho do vetor e o segundo, à razão da progressão aritmética.

### Constraints

.

### Output Format

- Vetor que represente uma sequência de elementos de uma progressão aritmética.

### Sample Input 0

- 5 2
### Sample Output 0

- 0 2 4 6 8

# TAD - Tipo Vetor
### Input Format

- Deve ser lido um valor inteiro n que representa a quantidade de elementos de um v. Em seguida, devem ser lidos os n elementos do vetor. Repetir o processo para o segundo vetor. Por fim, na última linha devem ser lidas as posições ini e fim para a geração de um subvetor a partir do primeiro vetor que foi lido.

### Constraints

.

### Output Format

- Vetores na seguinte ordem: resultantes da intercalação, resultantes da concatenação e subvetor.

### Sample Input 0

- 4
- 1 2 3 4
- 5
- 5 6 7 8 9
- 1 2
### Sample Output 0

- 1 5 2 6 3 7 4 8 9
- 1 2 3 4 5 6 7 8 9
- 2 3
 
# Pilhas estáticas - pares na base e ímpares no topo
- Implemente uma função que receba duas pilhas de números inteiros positivos. A função deverá retornar uma terceira pilha resultante da concatenação das duas pilhas, mas os números ímpares deverão estar próximos à base e os pares próximos do topo (utilizar apenas operações de empilhar e desempilhar).

### Input Format

- Na primeira linha, enquanto "-1" não for lido, ler números inteiros e colocá-los na primeira pilha.

- Na segunda linha, enquanto "-1" não for lido, ler números inteiros e colocá-los na segunda pilha pilha.

### Constraints

- Os elementos da pilha devem ser acessados através da função desempilhar.

### Output Format

- Imprimir o resultado da concatenação das duas pilhas.

### Sample Input 0

- 1 2 3 4 5 -1
- 6 7 8 9 10 -1
### Sample Output 0

- 4 2 10 8 6 5 3 1 9 7 

# Pilhas estáticas - balanço de parênteses
- Dada uma expressão qualquer com parênteses, indique se a quantidade de parênteses está correta ou não, sem levar em conta o restante da expressão. Por exemplo:

- a+(b*c)-2-a está correto (a+b*(2-c)-2+a)*2 está correto

- enquanto

- (a*b-(2+c) está incorreto 2*(3-a)) está incorreto )3+b*(2-c)( está incorreto

- Ou seja, todo parênteses que fecha deve ter um outro parênteses que abre correspondente e não pode haver parênteses que fecha sem um previo parenteses que abre e a quantidade total de parenteses que abre e fecha deve ser igual.

- Para a solução desse exercício, utilize uma pilha estática de caracteres.

Input Format

- Deve ser lido um valor inteiro N que representa a quantidade de casos de teste. Cada linha a seguir é uma expressões (1 <= N <= 10000), cada uma delas com até 1000 caracteres.

### Constraints

- As pilhas devem ser manipuladas apenas por funções. Por exemplo, o acesso a elementos deve ser feito apenas através da função desempilhar.

### Output Format

- O arquivo de saída deverá ter a quantidade de linhas correspondente ao arquivo de entrada, cada uma delas contendo as palavras correct ou incorrect de acordo com as regras acima fornecidas.

### Sample Input 0

- 5
- a+(b*c)-2-a 
- (a+b*(2-c)-2+a)*2 
- (a*b-(2+c) 
- 2*(3-a))  
- )3+b*(2-c)(
### Sample Output 0

- correct
- correct
- incorrect
- incorrect
- incorrect
# Filas estáticas - intercalação de filas estáticas
- Implemente uma função que receba duas filas compostas por números naturais. A função deverá intercalar as duas filas. Em cada intercalação, o maior elemento deve ser enfileirado primeiro.

- Exemplo:

 - Antes

- f1 = {1, 5, 3}

- f2 = {4, 2, 3, 4}

- f3 = {}

- Depois

- f1 = {}

- f2 = {}

- f3 = {4, 1, 5, 2, 3, 3, 4}

### Input Format

- Na primeira linha, enquanto "-1" não for lido, ler números inteiros. Na segunda linha, a mesma restrição da primeira linha deve ser aplicada.

###Constraints

- O acesso aos elementos da fila deve ser através da função desenfileirar.

### Output Format

- Imprimir a fila intercalada.

### Sample Input 0

- 1 5 3 -1
- 4 2 3 4 -1
### Sample Output 0

- 4 1 5 2 3 3 4
### Sample Input 1

- 1 2 3 4 5 -1
- 5 4 3 2 1 -1
### Sample Output 1

- 5 1 4 2 3 3 4 2 5 1
# Listas encadeadas - inverter lista encadeada
- Implemente uma função que receba uma lista encadeada. A função deverá inverter a lista recebida como entrada.

- Input Format

- Enquanto -1 não for lido, ler números inteiros.

### Constraints

- .

### Output Format

- Imprimir a lista invertida.

### Sample Input 0

- 1 2 3 4 5 6 -1
### Sample Output 0

- 6 5 4 3 2 1
# Pilhas encadeadas - binário para decimal

- Implemente uma função que receba uma pilha encadeada que contenha apenas 0's e 1's, ou seja, representa um número binário. A função deverá desempilhar todos os elementos da pilha converter o número binário para decimal.

### Input Format

- Na primeira linha, enquanto -1 não for lido, ler 0's e 1's.

### Constraints

- Os elementos da pilha devem ser acessados através da função desempilhar.

### Output Format

- Imprimir o resultado da conversão (número na base decimal).

### Sample Input 0

- 1 1 1 1 1 1 0 0 1 0 1 -1 

### Sample Output 0

- 2021

# 
# Filas encadeadas - gerenciamento de estacionamento
- O Sr. Pupunha, um grande investidor, comprou um terreno e decidiu fazê-lo um estacionamento, o qual tem capacidade para 10 carros. Ao estacionar o automóvel, o cliente recebe um ticket representando por um número inteiro. No entanto, o terreno é muito estreito e, consequentemente, os carros devem ser colocados em fila. Nesse terreno, a entrada é pelos fundos e a saída é pela frente. Caso um cliente precisar sair com o seu carro, os outros automóveis deverão ser retirados e estacionados novamente. Por exemplo, considere a seguinte fila de carros: {1, 2, 3, 4, 5, 6, 7, 8}, onde o primeiro elemento é o veículo que está mais próximo à saída e o último é mais próximo da entrada. Caso o carro 4 for retirado, os veículos 1, 2 e 3 devem estacionados novamente pela entrada do estacionamento. Desse modo, após a remoção do veículo 4, o estacionamento ficaria na seguinte forma: {5, 6, 7, 8, 1, 2, 3}.

- Implemente uma função que receba uma fila encadeada (representação do estacionamento) e um número inteiro (ticket ou id do carro) como parâmetros e faça o gerenciamento de veículos no estacionamento do Pupunha. Enquanto o ticket não for encontrado, o primeiro elemento da fila deverá ser removido e recolocado no final da da fila. Também, deve ser tratado o caso em que o elemento não é encontrado na fila. A função deverá retornar um número inteiro representado a quantidade de veículos que precisaram ser estacionados novamente para que o cliente pudesse retirar o seu carro.

### Input Format

- Na primeira linha, enquanto -1 não for lido, ler números inteiros. Na segunda linha deve ser lido um número inteiro que será o ticket a ser procurado na fila.

### Constraints

- O acesso aos elementos da fila deve ser através da função desenfileirar.

### Output Format

- Na primeira linha, o conteúdo da fila, após a operação de busca, deve ser impresso. Na segunda linha impresso a quantidade de movimentações que foram necessárias para procurar o ticket. Na terceira linha deve ser impressa a string "sucesso" caso o ticket for encontrado, ou "falha", caso contrário.

### Sample Input 0

- 1 2 3 4 5 6 7 8 -1
- 4
### Sample Output 0

- 5 6 7 8 1 2 3
- 3
- sucesso
# Pilhas encadeadas - checar se strings são equivalentes inversos
- Implemente uma função que receba duas strings: str1 e str2. A função deverá utilizar um pilha encadeada de caracteres para verificar de str2 é equivalente ao inverso de str1. Exemplos:

- "abcd" e "dcba": sim
- "efg" e "gie": nao
- "teste" e "etset": sim
- "gato" e "cabra": nao
- Input Format

- Na primeira e na segunda linha deve ser lida uma string (str1 e str2).

### Constraints

- Para acessar um elemento na pilha, deve ser utilizada a função desempilhar ou implementar uma função que retorne o elemento que está no topo da pilha. Para inserir um elemento na pilha, dese ser utilizada a função empilhar.

### Output Format

- Imprimir "sim" caso str2 seja equivalente ao inverso de str1.

- Imprimir "nao", caso contrário.

### Sample Input 0

- abcd
- dcba
### Sample Output 0

- sim
### Sample Input 1

- gato
- cao
### Sample Output 1

- nao
# Recursão - máximo divisor comum

- Implemente uma função recursiva que calcule o máximo divisor comum entre dois números inteiros: -> mdc(x, y) = y, se x >= y e x mod y = 0 -> mdc(x, y) = mdc(y, x), se x < y -> mdc(x, y) = mdc(x, x mod y), caso contrário

### Input Format

- Na primeira linha devem ser lidos dois números inteiros.

## Constraints

- .

### Output Format

- Imprimir o máximo divisor comum entre os dois números.

### Sample Input 0

-12 20
-Sample Output 0
-4
# Ordenação de strings - select sort
- Implemente o algoritmo selection sort para ordenar vetor de strings.

### Input Format

- Na primeira linha deve ser lido o tamanho do vetor. A partir da segunda linha, ler as strings do vetor.

### Constraints

 - .

### Output Format

- Imprimir o vetor após a ordenação.

### Sample Input 0

- 8
- joao_paulo
- tereza
- joao_luiz
- vegeta
- ana
- vampeta
- yusuke
- aioria
### Sample Output 0

- aioria
- ana
- joao_luiz
- joao_paulo
- tereza
- vampeta
- vegeta
- yusuke

# Algoritmos de ordenação - ordenação simples em listas encadedadas

- Implemente um dos algoritmos de ordenação simples apresentados em sala de aula (bublesort, selection sort ou insertion sort) para ordenar elementos de uma lista encadeada de números inteiros positivos.

### Input Format

- Enquanto -1 não for lido, ler número inteiro positivo.

### Constraints

- .

### Output Format

- Imprimir o conteúdo da lista encadeada ordenada.

### Sample Input 0

- 3 8 5 9 1 2 4 6 -1
### Sample Output 0

- 1 2 3 4 5 6 8 9 

# Matrizes esparsas - elementos não nulos

- Implemente uma função que retorne a quantidade de elementos não nulos de uma matriz esparsa.

### Input Format

 - A primeira linha contém os números de linhas e de colunas. Em seguida, uma matriz deve ser lida. Por último, a matriz bidimensional deve ser convertida para uma matriz esparsa.

### Constraints

- .

### Output Format

- Impressão da quantidade de elementos não nulos.

### Sample Input 0

- 5 5
- 0 2 0 1 0
- 1 0 0 3 1
- 2 3 0 0 0
- 1 3 2 0 1
- 0 0 4 0 1
### Sample Output 0

 - 13
# Matrizes esparsas - matriz diagonal
- Implemente uma função que verifica se a matriz esparsa é diagonal.

- -"Matriz diagonal é uma matriz quadrada onde os elementos que não pertencem à diagonal principal são obrigatoriamente iguais a zero." Fonte:

### Input Format

 - Na primeira linha deve ser lido um número inteiro, que representará os números de linhas e de colunas (matriz quadrada). Em seguida, uma matriz deve ser lida. Por último, a matriz bidimensional deve ser convertida para uma matriz esparsa.

### Constraints

- .

### Output Format

- Deve ser impresso "diagonal" se a matriz for diagonal ou "nao diagonal", caso contrário.

### Sample Input 0

- 5
- 0 2 0 1 0
- 1 0 0 3 1
- 2 3 0 0 0
- 1 3 2 0 1
- 0 0 4 0 1
### Sample Output 0

- nao diagonal
### Sample Input 1

- 4
- 1 0 0 0
- 0 2 0 0
- 0 0 1 0
- 0 0 0 1
### Sample Output 1

- diagonal
# Matrizes esparsas - matriz bidimensional para esparsa
 - Implemente uma função que converta uma matriz de números em uma matriz esparsa.

### Input Format

- A primeira linha contém os números de linhas e de colunas. Em seguida, uma matriz deve ser lida.

### Constraints

- .

### Output Format

- Matriz esparsa impressa no seguinte formato: "linha_i: -> coluna_j,item -> coluna_k,item"

- Caso a i-ésima linha da matriz esparsa seja nula, basta imprimir "linha_i -> ".

- Exemplo de matriz 3x3 e sua respectiva representação esparsa: 1 0 2 0 0 0 3 3 3

- 0: -> 0,1 -> 2,2 1: -> 2: -> 0,3 -> 1,3 -> 2,3

### Sample Input 0

- 5 5
- 0 2 0 1 0
- 1 0 0 3 1
- 2 3 0 0 0
- 1 3 2 0 1
- 0 0 4 0 1
### Sample Output 0

- 0: -> 1,2 -> 3,1
- 1: -> 0,1 -> 3,3 -> 4,1
- 2: -> 0,2 -> 1,3
- 3: -> 0,1 -> 1,3 -> 2,2 -> 4,1
- 4: -> 2,4 -> 4,1

# Hashing - tabela hash com listas encadeadas
- Implemente um TAD para hashing estático aberto, onde as colisões devem ser resolvidas por meio de listas encadeadas ordenadas. A função hash deve ser resto de divisão, ou seja, h(k) = k % B, onde k é uma chave e B é o tamanho da tabela hash.

### Input Format

- Na primeira linha deve ser lido o tamanho da tabela hash. Na segunda linha deve ser lida a quantidade de chaves que serão alocadas. Por fim, devem ser lidas as chaves que serão alocadas na tabela hash.

###Constraints

- .

### Output Format

- Imprimir as posições onde as chaves foram colocadas na tabela. Em seguida, imprimir a tabela hash inteira. Para isso, deve ser considerado o seguinte formato: "linha_i: -> item_0 -> item_1 -> ... -> item_n"

- Caso a i-ésima linha da matriz esparsa seja nula, basta imprimir "linha_i -> ".

### Sample Input 0

- 10
- 10
- 1
- 2
- 5
- 10
- 13
- 20
- 11
- 18
- 12
- 22
### Sample Output 0

- 1
- 2
- 5
- 0
- 3
- 0
- 1
- 8
- 2
- 2

- 0: -> 10 -> 20
- 1: -> 1 -> 11
- 2: -> 2 -> 12 -> 22
- 3: -> 13
- 4: -> 
- 5: -> 5
- 6: -> 
- 7: -> 
- 8: -> 18
- 9: -> 

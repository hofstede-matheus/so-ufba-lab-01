# RELATÓRIO DA ATIVIDADE PŔATICA 1
CHAMADAS DE SISTEMA E CHECAGEM DE ERROS
UNIVERSIDADE FEDERAL DA BAHIA
INSTITUTO DE MATEMÁTICA E ESTATÍSTICA
MATA58 - Sistemas Operacionais
  
- Laila Pereira Mota
- Matheus Hofstede
- Rafael Correa Nagy
  
# Considerações gerais

Todos os alunos já são familiarizados com lógica de programação, com a linguagem C e com a utilização do git, então não foi necessário revisar nenhum conteúdo e utilizamos o git para trabalharmos em conjunto.
Foi necessário um estudo sobre as chamadas de sistema e os erros provenientes de tais chamadas:
-   Para entender as chamadas, utilizamos a documentação dos manuais do linux (sugeridos pela atividade) que foi suficiente para utilizar os métodos com seus parâmetros e structs corretamente, mas, quando necessário, usamos o stackoverflow para resolver erros.
-   Para lidar com os erros, utilizamos o header do sistema errno.h
<img src="https://lh3.googleusercontent.com/lCzK-XCdBoiYIsp4XZHgN2UD9BuCHbEhSdmZ12z2bYZIk0ETOkiyrOAF_vdQdmOLWGQda4haVKmTM4NCoSuQ6lcj6xnZIicXdmYuedlWCirNGuYgDzmccAQEs8CPXPiUxOhW_LyT" width="80%">

  

O repositório está disponivel em [https://github.com/hofstede-matheus/so-ufba-lab-01](https://github.com/hofstede-matheus/so-ufba-lab-01) onde é possível encontrar as orientações e comandos de execução, descritas no "README.md", a partir do makefile, com as seguintes informações:
______________________________________________________________________
Clone o projeto, e no diretório raiz, execute em uma linha de comando
make filecopy
make treecopy
Os arquivos gerados estão na pasta build/
________________________________________________________________
# Exercício 1: Cópia de Arquivo Simples

Para esse exercício, adicionamos uma verificação inicial dos parâmetros fornecidos e implementamos a cópia do arquivo seguindo a lógica do pseudocódigo fornecido no exercício.

Os erros encontrados foram:
-   Número inválido de argumentos
-   Arquivo não existe
-   Erro ao ler arquivo
-   Erro ao escrever arquivo

Para que as mensagens de erros fossem retornadas de maneira amigável, criamos uma biblioteca auxiliar que chamamos de “errors”. Ela contém funções que irão sobrescrever as funções de erros padrão do C, essas funções consistem apenas em uma impressão de mensagens referentes ao erro, e depois, retorna a falha para o sistema. Além disso, também existe um header para essa biblioteca.

  
  

# Exercício 2: Cópia de Arquivo e Diretório

Para esse exercício, reaproveitamos o código do exercício anterior, para a verificação dos argumentos, as mensagens de erro e a cópia de arquivos.

Esse algoritmo precisa ser recursivo, entretanto sua complexidade não sofreu grande impacto. De forma simplificada, o algoritmo funciona da seguinte maneira, quando encontramos um arquivo copiamos ele para o destino, caso o arquivo em questão seja uma pasta pasta criamos uma pasta com mesmo nome no destino e chamamos a função recursivamente para seus filhos (os arquivos e diretórios contidos nela).

Para fazer esse algoritmo, precisamos utilizar uma função auxiliar de concatenação de string e uma função que verifica se o ponteiro que estamos lidando é um arquivo ou um diretório.

Os erros que encontramos foram os mesmos do exercício anterior, com a inclusão dos erros referentes a diretórios e não somente a arquivos.

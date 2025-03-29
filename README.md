# Estrutura_Ex1
Estrutura de Dados I + Estrutura De Dados Exercício EX1 - media dos alunos

Então, bora programar.


Trabalhe em grupos. A programação é na linguagem C. Pode usar a plataforma https://www.jdoodle.com/. Sugiro até que usem o recurso "Project Share" para que todos do grupo possam editar o mesmo código. Neste caso inclua meu email no projeto.


A entrega pode ser feita através de um link para o projeto ou mesmo para o github.


CONSIDERE O CADASTRO DE ALUNOS


Considere o cadastro de alunos. Para não envolver manipulação de strings, cada aluno possui apenas matricula, nota g1, g2 e media. Um exemplo de uma struct para os alunos pode ser:


struct ALUNOS {

  int matricula;

  double g1, g2, media;

};


Faça um programa em C que pergunte quantos alunos serão cadastrados. Crie um vetor para alunos. Leia cada dado de cada aluno (matricula, g1 e g2) e depois de lido, e somente depois de ler todos, faça:


    Calcule a media de todos (media = (g1+g2)/2)
    Imprima o aluno com maior media
    Ordene o vetor pela media
    Imprima os dados de todos os alunos que precisam realizar a substituição 


Entregue (preferencialmente) um link do teu projeto armazenado no jdoodle ou github. De permissão ao professor (elgio.schlemer@unilasalle.edu.br) para editar o projeto.


Ou, se preferir, entregue aqui mesmo em formato textual (C ou TXT).


JAMAIS EM PDF


Veja como pode ser o diálogo do teu programa com o usuário:


$ ./RespEX1 

# Quantos você quer cadastrar? 

3 

# Digite Matricula aluno 0: 

30 

# Digite Nota G1 aluno 0: 

5.6 

# Digite Nota G2 aluno 0: 

8.6 

# Digite Matricula aluno 1: 

31 

# Digite Nota G1 aluno 1: 

2 

# Digite Nota G2 aluno 1: 

3 

# Digite Matricula aluno 2: 

322 

# Digite Nota G1 aluno 2: 

8 

# Digite Nota G2 aluno 2: 

9.6 

Aluno 322 tem maior media ( 8.80)

===== 3 ALUNOS Depuracao ===== 

  31 2.50 

  30 7.10 

 322 8.80


$


É imprescindível que a leitura seja feita nesta ordem, para possibilitar testes automatizados. Exemplo:


$ echo "2 21 3.5 4.9 65 7.2 8.5 891 8.0 9.7"|./RespEX1 

# Quantos você quer cadastrar? 

# Digite Matricula aluno 0: 

# Digite Nota G1 aluno 0: 

# Digite Nota G2 aluno 0: 

# Digite Matricula aluno 1: 

# Digite Nota G1 aluno 1: 

# Digite Nota G2 aluno 1: 

Aluno 65 tem maior media ( 7.85) 


===== 2 ALUNOS Depuracao ===== 

  21 4.20 

  65 7.85

$


Neste teste acima não foi realmente digitado cada valor, mas foi passado como se fosse digitado. A ordem dos números importam:

Total

mat1

g1

g2

mat2

g1

g2

...

Assim pode-se testar com milhares de alunos sem ficar várias horas realmente digitando os dados.
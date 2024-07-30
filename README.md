# Greed - Resolução de Problemas

**Número da Lista**: 13 <br>
**Conteúdo da Disciplina**: Greed<br>

## Alunos
|Matrícula | Aluno |
| -- | -- |
| 19/0010495  |  Arthur Alves de Matos |
| 17/0085023  |  Carla Rocha Cangussú |

## Sobre
O objetivo do projeto é responder questões disponíveis em juízes online sobre algoritmos ambiciosos, as questões serão de média e alta complexidade.

## Screenshots
### Resultados dos Problemas em terminal
A partir dos arquivos de testes `teste.txt` presentes em cada diretório, os seguintes resultados são apresentados

### Bee 1021 - Notas e Moedas
![1021](/screenshots/1021.png)

### Bee 1086 - O Salão do Clube
![1086](/screenshots/1086.png)

## Instalação 
**Linguagem**: C<br>
Linguagem: C
Para a utilização do projeto, deve-se ter acesso ao compilador de linguagem C gcc.

## Uso 
Cada questão foi separada em uma pasta diferente e para executar os códigos de cada uma das questões é necessário a execução dos 3 seguintes comandos adaptados ao nome do arquivo de cada questão. Ex:

```sh
    cd Questoes/n_questao/
    gcc -o n_questao n_questao.c
    ./n_questao < teste.txt
```

### Uso para 1021
Para a questão 1021 é necessário rodar com o comando -lm para linkar a biblioteca math.h

```sh
    cd Questoes/1021/
    gcc -o 1021 1021.c -lm
    ./2490 < teste.txt
```

## Outros 
Para acessar os enunciados é necessário criar um login na plataforma Beecrowd, os links de cada enunciado estão presentes em:

- [Bee 1021 - Notas e Moedas](https://judge.beecrowd.com/pt/problems/view/1021)
- [Bee 1086 - O Salão do Clube](https://judge.beecrowd.com/pt/problems/view/1086)
- [Bee 1084 - Apagando e Ganhando](https://judge.beecrowd.com/pt/problems/view/1084)
- [Bee 1288 -  Canhão de Destruição](https://judge.beecrowd.com/pt/problems/view/1288)

## Apresentações de resoluções
Exemplificações em vídeo de aplicações entre os exercicios resolvidos.

- [Bee 1021 - Notas e Moedas](https://drive.google.com/file/d/1h8xpK7BcfBP8Mx6G4UgJe5YbX36VP7DY/view)
- [Bee 1086 - O Salão do Clube](https://drive.google.com/file/d/1a48_syhk07IYdQYq6pJSj51GTIwAVft8/view)
- [Bee 1084 e 1288 - Apagando e Ganhando / Canhão de Destruição](https://unbbr.sharepoint.com/sites/Contaprivada/Documentos%20Compartilhados/General/Recordings/Reuni%C3%A3o%20em%20_General_-20240729_232246-Grava%C3%A7%C3%A3o%20de%20Reuni%C3%A3o.mp4?web=1&referrer=Teams.TEAMS-ELECTRON&referrerScenario=MeetingChicletGetLink.view)

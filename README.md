<picture>
 <img alt="Shows an illustrated sun in light color mode and a moon with stars in dark color mode." src="https://pbs.twimg.com/profile_images/1283835103173648390/MYhdUSFu_400x400.jpg">
</picture>

# Trabalho Final Estrutura de Dados
## Sistema Biblioteca

### Dados Equipe:
**Otaviano Rodrigues da Silva – 411631**
**José Igor Oliveira de Lima – 500063**
**Jovito Maia Pinheiro Moura – 482257**
**Leonam Venâncio Wirtzbiki – 504415**
**Guilherme Rafael de Pontes Silva – 511427**

Neste trabalho, você deverá simular um sistema para biblioteca do campus da UFC-Russas
conseguir encomendar livros de outros campus. O sistema possui as seguintes fases:

Fase 1: inicialmente o aluno procura a biblioteca do seu campus para criar um processo de
encomenda de livro, onde é atendido por um estagiário. O estagiário fica encarregado de criar a
documentação inicial para encomendar um livro. Para tal, ele deve cadastrar o nome do aluno,
matrícula e descrição do livro. Portanto, estes dados devem ser adicionados (“cadastrados”) em
uma estrutura de dados que gerencie as encomendas de livro.

Detalhes importantes desta fase:

1- O documento de encomenda possui um padrão que consta de: um código identificador único,
nome do aluno, matrícula do aluno e um campo com detalhes sobre o livro (ex: nome, autor, dentre
outros).

**2 -** O estagiário é responsável por preencher apenas o nome do aluno, matrícula e o campo com
detalhes sobre o livro. O código identificador único deverá ser gerado pelo sistema antes do
estagiário “cadastrar” o documento (adicionar na estrutura de dados que gerencia as encomendas).

**3 -** Para cadastrar o documento no sistema o estagiário não precisa estar logado no sistema, ou
seja, não é necessária a verificação da pessoa que está cadastrando o documento no sistema.

**4 –** A estrutura de dados que gerencia os processos deverá ser definida e implementada pelos
alunos do grupo. O grupo deverá decidir qual a ordem de inserção desta estrutura.

**Fase 2:** qualquer um dos secretários da biblioteca pode remover uma encomenda da estrutura de
dados de encomendas . Para tal, ele deve a priori visualizar todas as encomendas para que possa
escolher qual encomenda ele deve deseja remover.

A remoção de uma encomenda deve ser feita através do código identificador. Assim que o
secretário remover uma encomenda, ele se tornará o responsável por ela. Portanto, o secretário deve
visualizar os dados da encomenda que já estão preenchidos e preencher os demais dados
importantes para efetuar um pedido de livro: nome do campus onde está o livro, o nome do campus
onde está o aluno, nome do responsável pela encomenda (seu nome) e prioridade do pedido (valor
de 0 a 100, onde quanto maior valor, maior a prioridade). Após inserir os dados, o sistema deve
 cadastrar o documento completo na fila de pedidos de livros.

**Detalhes importantes desta fase:**

**1 -** Assim que o secretário pedir para remover uma encomenda, o sistema deve pedir para que ele
se identifique, requisitando seu cpf e senha. Esta verificação deverá ser processada através de uma
uma estrutura de dados, definida pelos alunos.

**2 -** Os dados dos secretários da biblioteca devem estar pré-cadastrados no sistema. O aluno
deve criar pelo menos 3 secretários fictícios. Os dados que devem ser criados e armazenados para
cada secretário são: nome, cpf, senha e um campo que deverá ser utilizado para garantir que esta
pessoa e de fato é um secretário no sistema (outros tipos de usuários também serão cadastrados no
sistema).

**3 –** Quando o secretário pedir para remover uma encomenda, automaticamente o sistema deverá
adicionar seu nome no campo “nome do responsável pela encomenda”.

**Fase 3:** qualquer um dos transportadores pode remover um documento da fila de pedidos de
livros.

**Detalhes importantes desta fase:**

**1 -** Assim que o transportador pedir para remover um documento da fila de pedidos de livros, o
sistema deve pedir para que ele se identifique, requisitando seu cpf e senha. Esta verificação deverá
ser processada através da mesma estrutura de dados definida na fase 2.

**2 -** Os dados dos trasportadores do sistema devem estar pré-cadastrados no sistema. O aluno
deve criar pelo menos 5 transportadores fictícios. Os dados que devem ser criados e armazenados
para cada transportador são: nome, cpf, senha e um campo que deverá ser utilizado para garantir
que esta pessoa é de fato um transportador no sistema (outros tipos de usuários serão também
cadastrados no sistema).

**3 -** Note que quando o transportador pedir para remover um documento da fila de pedidos, este
deve ser sempre o de maior prioridade. Após a remoção nada mais é feito pelo sistema.

**DETALHES DA ENTREGA**

→ Os trabalhos deverão ser apresentados em equipes de até 6 alunos, em sala de aula, no dia
29/06/2022, no horário da aula.

→ Os alunos podem e devem pedir ajuda e tirar dúvidas com as demais equipes, mas cada equipe
deve apresentar seu trabalho de forma individual e obviamente ter conhecimento do código
apresentado. Será feita uma pergunta para cada integrante da equipe individualmente.

→ É proibido o uso de comentários no código de apresentação do trabalho.



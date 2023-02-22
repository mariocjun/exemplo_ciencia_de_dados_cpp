# Tutorial de uso do programa de interpolação de dados com C++, Gnuplot, GSL e CPM
## Referências: https://opensource.com/article/20/2/c-data-science
## Referências: https://medium.com/swlh/cpm-an-awesome-dependency-manager-for-c-with-cmake-3c53f4376766
### Plataforma: Windows 11 (64 bits)
##### O sistema operacional utilizado é o Windows 11 na versão de 64 bits.

### IDE CLion 2023.1
##### A IDE (Integrated Development Environment) utilizada é o CLion na versão 2023.1.

### Compilador MinGW w64 9.0
#####  Compilador é o MinGW w64 9.0, incluso na IDE CLion.

### CMake 3.25.2
##### O gerenciador de ‘build’ (compilação) utilizado é o CMake na versão 3.25.2, incluso na IDE CLion.

### C++ 11
##### O programa foi escrito em C++ utilizando a versão 11 da linguagem.

### Gnuplot
##### O Gnuplot é um programa que gera gráficos a partir de dados numéricos. Ele pode ser baixado no seguinte link: https://sourceforge.net/projects/gnuplot/

### CMake Package Manager (CPM)
##### O CPM é usado para automatizar o download e a configuração de bibliotecas externas. Ele é baixado automaticamente pelo CMake quando o projeto é compilado pela primeira vez.

### Biblioteca GSL
##### O programa utiliza a biblioteca GSL (GNU Scientific Library) para fazer a interpolação dos dados que estão no arquivo CSV. A GSL é baixada automaticamente pelo CPM quando o projeto é compilado pela primeira vez.

### Caminho do executável do gnuplot
##### O caminho para o executável do gnuplot utilizado no script plot.ps1 é o seguinte: C:\Program Files\gnuplot\bin\gnuplot.exe, se nao for esse o caminho do seu gnuplot, altere o script plot.ps1 para o caminho correto.

### CMake options
##### As opções de configuração do CMake foram editadas na IDE, para que a pasta ".cache" do CPM fosse criada no diretório temporário do CMake. A opção utilizada é a seguinte: -DCPM_SOURCE_CACHE:PATH=$CMakeProjectDir$/cmake-build-debug/.cache

## Funcionamento do programa

* Lê os dados do arquivo CSV anscombe.csv.
* Interpola os dados com uma linha reta (ou seja, f(x)=m ⋅ x + q), criando um arquivo CSV com os dados interpolados chamado fit_Cpp11.csv.
* Plota o resultado num arquivo de imagem chamado fit_Cpp11.png utilizando o script plot.ps1, que chama o gnuplot para gerar o gráfico a partir do arquivo plotting_Cpp11.gnuplot. Este último é um script do gnuplot que contém os comandos para gerar o gráfico a partir dos dados do arquivo fit_Cpp11.csv. O script deve ser executado no terminal do Windows, no diretório onde se encontra o arquivo plottin_Cpp11.gnuplot. O comando para executar o script é o seguinte: .\plot.ps1


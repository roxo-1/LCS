# LCS
## Descrição do Problema: Maior Subsequência Comum (LCS)
O problema abordado neste projeto é a busca pela Maior Subsequência Comum (LCS) entre duas sequências. Este problema tem uma aplicação direta em bioinformática, especificamente na comparação de filamentos de DNA.

## Contexto Biológico
No campo da biologia, é comum comparar o DNA de diferentes organismos para avaliar o quão geneticamente próximos eles estão. Um filamento de DNA é representado como uma sequência de bases, que são as letras A, C, G e T (adenina, citosina, guanina e timina).

Para medir a similaridade entre dois filamentos de DNA, procuramos uma terceira sequência que seja uma subsequência de ambos. Quanto maior for o tamanho dessa subsequência, mais similares são os dois filamentos. O objetivo é encontrar a subsequência comum de maior tamanho possível.

## Definições Formais
Subsequência: Uma sequência Z é uma subsequência de X se os elementos de Z aparecem na mesma ordem em X, mas não necessariamente de forma consecutiva.

Exemplo: Z=<B,C,B,D,B> é uma subsequência de X=<A,B,C,B,D,A,B>.

Subsequência Comum (CS): Uma sequência Z é uma subsequência comum de duas sequências X e Y se Z é uma subsequência de ambas.

Maior Subsequência Comum (LCS): A LCS de duas sequências é a subsequência comum de maior tamanho. Pode haver mais de uma LCS para um par de sequências, mas todas terão o mesmo comprimento.

Exemplo: Para X=<A,B,C,B,D,A,B> e Y=<B,D,C,A,B,A>, as subsequências <B,C,B,A> e <B,D,A,B> são exemplos de LCS, ambas com tamanho 4. Não existe uma subsequência comum de tamanho 5 ou maior.

## Objetivo do Projeto
O objetivo deste projeto é, dadas duas sequências de entrada, encontrar e retornar a maior subsequência comum (LCS) entre elas.

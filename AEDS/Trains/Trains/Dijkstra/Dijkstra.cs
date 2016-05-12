using System.Collections.Generic;
using System.Linq;

namespace Trains
{
    public class Dijkstra
    {
        List<ItemDijkstra> tabela;

        private const int INFINITO = int.MaxValue;

        public Dijkstra()
        {
            this.tabela = new List<ItemDijkstra>();
        }

        /// <summary>
        /// Recupera Menor Caminho - Implementação do algoritmo de Dijkstra
        /// Referencia: http://www.inf.ufsc.br/grafos/temas/custo-minimo/dijkstra.html
        /// </summary>
        /// <param name="grafo"></param>
        /// <param name="origem"></param>
        /// <param name="destino"></param>
        /// <returns>inteiro com o peso do menor caminho entre origem e destino no grafo</returns>
        public int RecuperaMenorCaminho(Grafo grafo, string origem, string destino)
        {
            int estimativa = 0;
            Inicializa(grafo, origem);
            IVertice verticeDestino = grafo.ProcuraVertice(destino);

            while (RetornaVerticeNaoMarcado() != null)
            {
                ItemDijkstra verticeAtual = RetornaVerticeDeMenorEstimativaNãoMarcado();
                verticeAtual.Set.EstaMarcado();
                // caso o destino já foi marcado, tem-se o resultado
                if (verticeAtual.Vertice.Nome == destino)
                {
                    estimativa = verticeAtual.Estimativa;
                    break;
                }
                // recalcula as estimativas para os vertices adjacentes ao atual
                foreach (var aresta in verticeAtual.Vertice.RetornaArestasAdjacentes())
                {
                    int soma = verticeAtual.Estimativa + aresta.Peso;
                    ItemDijkstra j = tabela.Find(i => i.Vertice.Nome == aresta.Destino.Nome);
                    if (j.Estimativa > soma)
                    {
                        j.Estimativa = soma;
                        j.Precedente = verticeAtual.Vertice;
                    }
                }
            }

            return estimativa;
        }

        // Inicializa a tabela de dijkstra, com a origem de estimativa ZERO e precedente em si mesmo.
        // Os restantes com distancia infinita e sem precedente.
        private void Inicializa(Grafo grafo, string origem)
        {
            List<IVertice> vertices = grafo.RecuperaListaDeVertices();

            foreach (var vertice in vertices)
            {
                ItemDijkstra item = new ItemDijkstra();
                if (vertice.Nome != origem)
                {
                    item.Set.Vertice(vertice).Estimativa(INFINITO).Precedente(null).NaoEstaMarcado();
                    tabela.Add(item);
                }
                else
                {
                    item.Set.Vertice(vertice).Estimativa(0).Precedente(vertice).NaoEstaMarcado();
                    tabela.Add(item);
                }
            }
        }

        private ItemDijkstra RetornaVerticeNaoMarcado()
        {
            ItemDijkstra resultado = tabela.Find(i => i.EstaMarcado == false);
            return resultado;
        }

        private ItemDijkstra RetornaVerticeDeMenorEstimativaNãoMarcado()
        {
            List<ItemDijkstra> lista = tabela.FindAll(i => i.EstaMarcado == false);
            ItemDijkstra resultado = lista.Find(i => i.Estimativa == lista.Min(j => j.Estimativa));
            return resultado;
        }
    }
    
}

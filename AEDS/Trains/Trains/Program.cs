using System;
using System.Collections.Generic;
namespace Trains
{
    class Program
    {

        private const int INFINITO = -1;

        static void Main(string[] args)
        {
            try
            {
                string input = "AB5, BC4, CD8, DC8, DE6, AD5, CE2, EB3, AE7";

                Grafo grafo = new Grafo();
                GeraGrafo(input, grafo);

                Dijkstra di = new Dijkstra();
                int menorCaminho = di.RecuperaMenorCaminho(grafo, "B", "B");

            }
            catch (Exception)
            {
                throw;
            }
            
        }
        
        private static void GeraGrafo(string input, Grafo grafo)
        {

            string[] tokens = input.Replace(" ", "").Split(',');

            IVertice origem, destino;
            string nomeOrigem, nomeDestino;
            int peso;

            foreach (var item in tokens)
            {
                nomeOrigem = item[0].ToString();
                nomeDestino = item[1].ToString();
                peso = int.Parse(item[2].ToString());

                origem = grafo.ProcuraVertice(nomeOrigem);
                destino = grafo.ProcuraVertice(nomeDestino);
                if (origem == null)
                {
                    origem = new Vertice(nomeOrigem);
                    grafo.InsereVertice(origem);
                } if (destino == null)
                {
                    destino = new Vertice(nomeDestino);
                    grafo.InsereVertice(destino);
                }
                origem.InsereAresta(destino, peso);
            }
        }
    }
}

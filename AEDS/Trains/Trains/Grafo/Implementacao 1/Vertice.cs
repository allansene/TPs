using System.Collections.Generic;

namespace Trains
{
    public class Vertice : IVertice
    {

        List<IAresta> _arestas;
        public string Nome { get; set; }

        public Vertice(string nome)
        {
            this.Nome = nome;
            this._arestas = new List<IAresta>();
        }

        public void InsereAresta(IVertice destino, int peso)
        {
            IAresta novaAresta = new Aresta(peso,destino);
            _arestas.Add(novaAresta);
        }

        public List<IAresta> RetornaArestasAdjacentes()
        {
            return this._arestas;
        }
    }
}

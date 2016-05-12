using System;
using System.Collections.Generic;
using System.Linq;

namespace Trains
{
    public class Grafo : IGrafo
    {

        List<IVertice> _vertices;

        public Grafo()
        {
            this._vertices = new List<IVertice>();
        }

        public void InsereVertice(IVertice v1)
        {
            this._vertices.Add(v1);
        }

        public IVertice ProcuraVertice(string nome)
        {
            return this._vertices.Find(v => v.Nome == nome);
        }

        public List<IVertice> RecuperaListaDeVertices()
        {
            return _vertices;
        }
    }
}

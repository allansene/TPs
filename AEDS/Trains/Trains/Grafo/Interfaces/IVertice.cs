using System.Collections.Generic;

namespace Trains
{
    public interface IVertice
    {
        void InsereAresta(IVertice destino, int peso);

        List<IAresta> RetornaArestasAdjacentes();

        string Nome { get; set; }
    }
}

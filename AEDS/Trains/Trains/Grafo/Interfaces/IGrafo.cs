using System;
using System.Collections.Generic;

namespace Trains
{
    public interface IGrafo
    {
        void InsereVertice(IVertice v1);
        IVertice ProcuraVertice(string nome);
        List<IVertice> RecuperaListaDeVertices();
    }
}

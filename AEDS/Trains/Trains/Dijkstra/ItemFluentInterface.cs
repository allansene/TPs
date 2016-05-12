
namespace Trains
{
    public class ItemDijkstraFluentInterface
    {

        private readonly ItemDijkstra _ItemDijkstra;

        public ItemDijkstraFluentInterface(ItemDijkstra ItemDijkstra)
        {
            _ItemDijkstra = ItemDijkstra;
        }

        public ItemDijkstraFluentInterface Precedente(IVertice precedente)
        {
            _ItemDijkstra.Precedente = precedente;
            return this;
        }

        public ItemDijkstraFluentInterface Estimativa(int estimativa)
        {
            _ItemDijkstra.Estimativa = estimativa;
            return this;
        }

        public ItemDijkstraFluentInterface Vertice(IVertice vertice)
        {
            _ItemDijkstra.Vertice = vertice;
            return this;
        }

        public ItemDijkstraFluentInterface EstaMarcado()
        {
            _ItemDijkstra.EstaMarcado = true;
            return this;
        }

        public ItemDijkstraFluentInterface NaoEstaMarcado()
        {
            _ItemDijkstra.EstaMarcado = false;
            return this;
        }
    }
}

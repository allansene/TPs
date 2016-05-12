
namespace Trains
{
    public class ItemDijkstra
    {

        public ItemDijkstra()
        {
            _set = new ItemDijkstraFluentInterface(this);
        }

        private int _estimativa;

        private IVertice _vertice;

        private IVertice _precedente;

        private bool _estaMarcado;

        private readonly ItemDijkstraFluentInterface _set;

        public ItemDijkstraFluentInterface Set
        {
            get { return _set; }
        }

        public bool EstaMarcado
        {
            get { return _estaMarcado; }
            set { _estaMarcado = value; }
        }
        

        public IVertice Precedente
        {
            get { return _precedente; }
            set { _precedente = value; }
        }
        

        public IVertice Vertice
        {
            get { return _vertice; }
            set { _vertice = value; }
        }
        

        public int Estimativa
        {
            get { return _estimativa; }
            set { _estimativa = value; }
        }
        
    }
}

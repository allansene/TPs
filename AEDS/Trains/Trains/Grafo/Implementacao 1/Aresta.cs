namespace Trains
{
    public class Aresta : IAresta
    {

        public int Peso { get; set; }

        public IVertice Destino { get; set; }

        public Aresta(int peso, IVertice destino)
        {
            this.Peso = peso;
            this.Destino = destino;
        }

    }
}

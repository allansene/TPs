
namespace Trains
{
    public interface IAresta
    {
        int Peso { get; set; }

        IVertice Destino { get; set; }

    }
}

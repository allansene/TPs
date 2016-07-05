using System;

namespace distr_binomial_geo
{
    class Program
    {
        static void Main(string[] args)
        {

            string entrada;
            double probabilidade;
            bool sucesso = false;
            double random;
            int tentativas = 1;

            Console.WriteLine("Entre com a probabilidade da moeda dar cara: ");
            entrada = Console.ReadLine();

            if (double.TryParse(entrada, out probabilidade) == false)
            {
                Console.WriteLine("Erro: Entrada não decimal!");
                throw new FormatException();
            }
            probabilidade = probabilidade * 10;

            random = LancaMoeda();
            Console.WriteLine("Lançando a moeda pela primeira vez!");
            while (! sucesso)
            {
                tentativas++;
                if (random > probabilidade) // se o numero random for menor que a probabilidade informada, lança novamente
                {
                    random = LancaMoeda();
                    Console.WriteLine("Tentativa: " + tentativas + " sem sucesso. Lançando moeda novamente");
                }
                else
                {
                    Console.WriteLine("Sucesso! Moeda deu cara! Tentativa: " + tentativas);
                    sucesso = true;
                }
            }

            Console.ReadKey();
        }


        // LANCA MOEDA - cria numero randomico entre ZERO e DEZ
        private static double LancaMoeda()
        {

            Random randomizador = new Random();
            return randomizador.Next(0, 10);
        }
    }
}

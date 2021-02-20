using System;

namespace HW_01_1
{
    class Program
    {
        static void Main(string[] args)
        {
            if (Test.SortTest())
            {
                Console.WriteLine("All tests passed!");
            }
            else
            {
                Console.WriteLine("Tests failed!");
                return;
            }
            
            var str = Console.ReadLine().Split(' ');
            var array = new int[str.Length];
            
            for (int i = 0; i < array.Length; i++)
                array[i] = int.Parse(str[i]);

            Sort.SelectionSort(array);

            foreach (int x in array)
                Console.Write($"{x} ");
            Console.WriteLine();
        }
    }
}

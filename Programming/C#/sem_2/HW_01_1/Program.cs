﻿using System;

namespace HW_01_1
{
    class Program
    {
        static void Main(string[] args)
        {
            // string[] str = Console.ReadLine().Split(' ');
            // int[] array = new int[str.Length];
            
            // for (int i = 0; i < array.Length; i++)
            //     array[i] = int.Parse(str[i]);

            // SelectionSort(array);
            if (Test.SortTest() == true)
                Console.WriteLine("All tests passed!");

        }
    }
}
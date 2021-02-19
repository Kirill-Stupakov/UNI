using System;

namespace HW_01_1
{
    public static class Test
    {
        public static bool SortTest()
        {
            int[] arrayShuffled1 = new int[] {1, 2, 3, 4, 5};
            int[] arraySorted1 = new int[] {1, 2, 3, 4, 5};
            if (SingleTest(arrayShuffled1, arraySorted1) == false)
                return false;

            int[] arrayShuffled2 = new int[] {10, 8, 3, -10, -20};
            int[] arraySorted2 = new int[] {-20, -10, 3, 8, 10};
            if (SingleTest(arrayShuffled2, arraySorted2) == false)
                return false;

            int[] arrayShuffled3 = new int[] {8, 2, 10, -16, -5};
            int[] arraySorted3 = new int[] {-16, -5, 2, 8, 10};
            if (SingleTest(arrayShuffled3, arraySorted3) == false)
                return false;

            int[] arrayShuffled4 = new int[] {11, 14, 17, 5, 16, 11, 1, 10, 8, 19, 2, 11};
            int[] arraySorted4 = new int[] {1, 2, 5, 8, 10, 11, 11, 11, 14, 16, 17, 19};
            if (SingleTest(arrayShuffled4, arraySorted4) == false)
                return false;

            int[] arrayShuffled5 = new int[] {1, 2, 3, 4, 5};
            int[] arraySorted5 = new int[] {1, 2, 3, 4, 5};
            if (SingleTest(arrayShuffled5, arraySorted5) == false)
                return false;

            return true;
        }
        public static bool SingleTest(int[] arrayShuffled, int[] arraySorted)
        {

            int[] arrayToCheck = new int[arrayShuffled.Length];
            arrayShuffled.CopyTo(arrayToCheck, 0);

            Sort.SelectionSort(arrayToCheck);

            for (int i = 0; i < arrayToCheck.Length; i++)
            {
                if (arraySorted[i] != arrayToCheck[i])
                {
                    Console.WriteLine($"==Result mismatch==");

                    Console.Write("Unsorted:        ");
                    foreach (int x in arrayShuffled)
                        Console.Write($"{x} ");
                    Console.WriteLine();

                    Console.Write("Result:          ");
                    foreach (int x in arrayToCheck)
                        Console.Write($"{x} ");
                    Console.WriteLine();

                    Console.Write("Expected result: ");
                    foreach (int x in arraySorted)
                        Console.Write($"{x} ");
                    Console.WriteLine("");

                    Console.WriteLine("");

                    return false;
                }
            }

            return true;
        }
    }
}

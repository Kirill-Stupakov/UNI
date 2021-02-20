namespace HW_01_1
{
    public static class Sort
    {
        public static void SelectionSort(int[] array)
        {
            for (int sortedLength = 0; sortedLength < array.Length; sortedLength++)
            {
                int minimalUnsorted = sortedLength;

                for (int j = sortedLength + 1; j < array.Length; j++)
                    if (array[j] < array[minimalUnsorted])
                        minimalUnsorted = j;

                int t = array[minimalUnsorted];
                array[minimalUnsorted] = array[sortedLength];
                array[sortedLength] = t;
            }
        }
    }
}

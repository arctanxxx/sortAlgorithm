using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace sortTestFun
{
    class Program
    {
        public static void bucketSort(int[] arr)
        {
            if (arr == null || arr.Length < 2)
            {
                return;
            }
            int max = int.MinValue;
            for (int i = 0; i < arr.Length; i++)
            {
                max = Math.Max(max, arr[i]);
            }
            int[] bucket = new int[max + 1];
            for (int i = 0; i < arr.Length; i++)
            {
                bucket[arr[i]]++;
            }
            int index = 0;
            for (int j = 0; j < bucket.Length; j++)
            {
                while (bucket[j]-- >0)
                {
                    arr[index++] = j;
                }
            }

        }

        static void Main(string[] args)
        {
            int[] arr = { 10,9,8,7,6,5,4};
            bucketSort(arr);
            for (int i = 0; i < arr.Length; i++)
            {
                Console.Write(arr[i] + " ");
            }

            Console.WriteLine();
            Console.Read();
        }
    }
}

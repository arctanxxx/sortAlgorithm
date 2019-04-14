using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MaxGap
{
    class Program
    {
        public static int maxGapFun(int[] nums)
        {
            if (nums == null || nums.Length < 2)
                return 0;
            int len = nums.Length;
            int min = int.MaxValue;
            int max = int.MinValue;
            for (int i = 0; i < len; i++)
            {
                min = Math.Min(min, nums[i]);
                max = Math.Max(max, nums[i]);
            }
            if (max == min)
                return 0;

            Boolean[] hasNum = new Boolean[len + 1];    // len = 8
            int[] maxs = new int[len + 1];
            int[] mins = new int[len + 1];
            int bid = 0;
            for (int i = 0; i < len; i++)
            {
                bid = bucket(nums[i],len,min,max);
                mins[bid] = hasNum[bid] ? Math.Min(mins[bid], nums[i]) : nums[i];
                maxs[bid] = hasNum[bid] ? Math.Max(maxs[bid], nums[i]) : nums[i];
                hasNum[bid] = true;
            }
            int res = 0;
            int lastMax = maxs[0];
            int j = 1;
            for (; j <= len; j++)
            {
                if (hasNum[j])
                {
                    res = Math.Max(res, mins[j] - lastMax);
                    lastMax = maxs[j];
                }
            }
            return res;
        }

        public static int bucket(long num,long len,long min,long max)
        {
            return (int)((num - min) * len / (max - min));
        }

        static void Main(string[] args)
        {
            int[] arr = { 1, 2, 3,12, 10, 11, 14, 16, 100 };
            int res = maxGapFun(arr);
            Console.WriteLine( res);
            Console.ReadKey();
        }
    }
}

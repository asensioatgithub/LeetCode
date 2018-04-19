void FindMinMax (int *Array, int left, int right, int *min, int *max)
{
      if ((right - left)==1)
      {
            *max = Array[left];  
            *min = Array[right];
            if (Array[left] < Array[right])
            {
                  *max = Array[right];
                  *min = Array[left];
            }
      }
      else if ((right - left) == 0)
      {
            *max = *min = Array[left];
      }
      else {
            int min1, min2, max1, max2;
            FindMinMax (Array, left, (right - left)/2 + left, &min1, &max1);
            FindMinMax (Array, (right - left)/2+1 + left, right, &min2, &max2);
            (min1 > min2) ? *min = min2 : *min = min1;
            (max1 > max2) ? *max = max1 : *max = max2;
            }
}

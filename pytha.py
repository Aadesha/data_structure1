def isTriplet(ar, n): 

    for i in range(n): 
        ar[i] = ar[i] * ar[i] 
  
 
    ar.sort() 
  

    for i in range(n-1, 1, -1): 

        j = 0
        k = i - 1
        while (j < k): 
 
            if (ar[j] + ar[k] == ar[i]): 
                return True
            else: 
                if (ar[j] + ar[k] < ar[i]): 
                    j = j + 1
                else: 
                    k = k - 1

    return False
 
ar = [3, 1, 4, 6, 5] 
ar_size = len(ar) 
if(isTriplet(ar, ar_size)): 
    print("Yes") 
else: 
    print("No") 
  
